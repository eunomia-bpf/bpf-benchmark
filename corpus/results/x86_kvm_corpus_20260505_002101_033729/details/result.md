# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T00:27:22.392136+00:00",
  "kop_modules": {
    "captured_at": "2026-05-05T00:21:01.051799+00:00",
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
      "invoked_at": "2026-05-05T00:21:01.051742+00:00",
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
        "captured_at": "2026-05-05T00:21:01.051735+00:00",
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
      "captured_at": "2026-05-05T00:21:01.041321+00:00",
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
      "baseline_avg_ns_per_run": 331.62352349268934,
      "baseline_run_cnt_delta": 973920,
      "baseline_run_time_ns_delta": 322974782,
      "post_rejit_avg_ns_per_run": 353.1444146797315,
      "post_rejit_run_cnt_delta": 1066886,
      "post_rejit_run_time_ns_delta": 376764832,
      "program": "cap_capable",
      "program_id": 6,
      "ratio": 1.064895550714805,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 855.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 1710,
      "post_rejit_avg_ns_per_run": 721.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 1442,
      "program": "syscall__execve",
      "program_id": 9,
      "ratio": 0.8432748538011696,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 192.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 384,
      "post_rejit_avg_ns_per_run": 227.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 455,
      "program": "do_ret_sys_execve",
      "program_id": 10,
      "ratio": 1.1848958333333333,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 2018.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 4037,
      "post_rejit_avg_ns_per_run": 2978.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 5957,
      "program": "bindsnoop_entry",
      "program_id": 13,
      "ratio": 1.4756006935843449,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 5969.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 11939,
      "post_rejit_avg_ns_per_run": 11535.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 23071,
      "program": "bindsnoop_v4_return",
      "program_id": 14,
      "ratio": 1.9324063991959126,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 220.54652855791872,
      "baseline_run_cnt_delta": 1575570,
      "baseline_run_time_ns_delta": 347486494,
      "post_rejit_avg_ns_per_run": 220.55853091018147,
      "post_rejit_run_cnt_delta": 1573818,
      "post_rejit_run_time_ns_delta": 347118986,
      "program": "trace_pid_start_tp",
      "program_id": 18,
      "ratio": 1.00005442095299,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 210.31022353672932,
      "baseline_run_cnt_delta": 1575580,
      "baseline_run_time_ns_delta": 331360582,
      "post_rejit_avg_ns_per_run": 211.91843708461153,
      "post_rejit_run_cnt_delta": 1573828,
      "post_rejit_run_time_ns_delta": 333523170,
      "program": "trace_req_start",
      "program_id": 19,
      "ratio": 1.0076468633851332,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 95.74571222752184,
      "baseline_run_cnt_delta": 1575585,
      "baseline_run_time_ns_delta": 150855508,
      "post_rejit_avg_ns_per_run": 96.00224356713832,
      "post_rejit_run_cnt_delta": 1573833,
      "post_rejit_run_time_ns_delta": 151091499,
      "program": "trace_req_completion_tp",
      "program_id": 20,
      "ratio": 1.0026792984630672,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 61.46586206643097,
      "baseline_run_cnt_delta": 136051,
      "baseline_run_time_ns_delta": 8362492,
      "post_rejit_avg_ns_per_run": 62.419758160462045,
      "post_rejit_run_cnt_delta": 138687,
      "post_rejit_run_time_ns_delta": 8656809,
      "program": "vfs_create",
      "program_id": 23,
      "ratio": 1.0155191200767693,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 69.8341384863124,
      "baseline_run_cnt_delta": 621,
      "baseline_run_time_ns_delta": 43367,
      "post_rejit_avg_ns_per_run": 69.28180574555404,
      "post_rejit_run_cnt_delta": 731,
      "post_rejit_run_time_ns_delta": 50645,
      "program": "kfunc__vmlinux__vfs_fsync_range",
      "program_id": 24,
      "ratio": 0.9920907917999645,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 44.678067914744396,
      "baseline_run_cnt_delta": 1286672,
      "baseline_run_time_ns_delta": 57486019,
      "post_rejit_avg_ns_per_run": 44.56019095621204,
      "post_rejit_run_cnt_delta": 1257880,
      "post_rejit_run_time_ns_delta": 56051373,
      "program": "vfs_open",
      "program_id": 25,
      "ratio": 0.997361637061896,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 40.84433157990205,
      "baseline_run_cnt_delta": 55130,
      "baseline_run_time_ns_delta": 2251748,
      "post_rejit_avg_ns_per_run": 45.26644129230126,
      "post_rejit_run_cnt_delta": 57386,
      "post_rejit_run_time_ns_delta": 2597660,
      "program": "vfs_read",
      "program_id": 26,
      "ratio": 1.1082674031217385,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 65.39742063243385,
      "baseline_run_cnt_delta": 79787,
      "baseline_run_time_ns_delta": 5217864,
      "post_rejit_avg_ns_per_run": 53.5876677020686,
      "post_rejit_run_cnt_delta": 75655,
      "post_rejit_run_time_ns_delta": 4054175,
      "program": "vfs_write",
      "program_id": 27,
      "ratio": 0.8194156158429863,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 445.8979297365119,
      "baseline_run_cnt_delta": 15940,
      "baseline_run_time_ns_delta": 7107613,
      "post_rejit_avg_ns_per_run": 380.4719008264463,
      "post_rejit_run_cnt_delta": 15730,
      "post_rejit_run_time_ns_delta": 5984823,
      "program": "__x64_sys_open",
      "program_id": 30,
      "ratio": 0.8532712880081617,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 391.27048964050624,
      "baseline_run_cnt_delta": 572277,
      "baseline_run_time_ns_delta": 223915102,
      "post_rejit_avg_ns_per_run": 390.48859453051944,
      "post_rejit_run_cnt_delta": 575338,
      "post_rejit_run_time_ns_delta": 224662927,
      "program": "kretfunc__vmlinux____x64_sys_openat",
      "program_id": 31,
      "ratio": 0.998001650697692,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 459.27933151432467,
      "baseline_run_cnt_delta": 2932,
      "baseline_run_time_ns_delta": 1346607,
      "post_rejit_avg_ns_per_run": 417.79843110504777,
      "post_rejit_run_cnt_delta": 2932,
      "post_rejit_run_time_ns_delta": 1224985,
      "program": "kretfunc__vmlinux____x64_sys_openat2",
      "program_id": 32,
      "ratio": 0.9096826319780011,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 59.576983652163506,
      "baseline_run_cnt_delta": 9360260,
      "baseline_run_time_ns_delta": 557656057,
      "post_rejit_avg_ns_per_run": 59.69163978543608,
      "post_rejit_run_cnt_delta": 9274439,
      "post_rejit_run_time_ns_delta": 553606472,
      "program": "tracepoint__raw_syscalls__sys_enter",
      "program_id": 35,
      "ratio": 1.0019245038309088,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 56.68692208475811,
      "baseline_run_cnt_delta": 9360261,
      "baseline_run_time_ns_delta": 530604386,
      "post_rejit_avg_ns_per_run": 57.79010193607377,
      "post_rejit_run_cnt_delta": 9274440,
      "post_rejit_run_time_ns_delta": 535970833,
      "program": "tracepoint__raw_syscalls__sys_exit",
      "program_id": 36,
      "ratio": 1.0194609234501424,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 883.3757763975156,
      "baseline_run_cnt_delta": 322,
      "baseline_run_time_ns_delta": 284447,
      "post_rejit_avg_ns_per_run": 929.6721854304636,
      "post_rejit_run_cnt_delta": 302,
      "post_rejit_run_time_ns_delta": 280761,
      "program": "trace_connect_entry",
      "program_id": 39,
      "ratio": 1.052408510930364,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 4600.490683229814,
      "baseline_run_cnt_delta": 161,
      "baseline_run_time_ns_delta": 740679,
      "post_rejit_avg_ns_per_run": 4266.543046357616,
      "post_rejit_run_cnt_delta": 151,
      "post_rejit_run_time_ns_delta": 644248,
      "program": "trace_connect_v4_return",
      "program_id": 40,
      "ratio": 0.9274104307852337,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 4720.378881987577,
      "baseline_run_cnt_delta": 161,
      "baseline_run_time_ns_delta": 759981,
      "post_rejit_avg_ns_per_run": 4390.086092715232,
      "post_rejit_run_cnt_delta": 151,
      "post_rejit_run_time_ns_delta": 662903,
      "program": "trace_connect_v6_return",
      "program_id": 41,
      "ratio": 0.9300283308755777,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcplife",
      "baseline_avg_ns_per_run": 866.8392272429601,
      "baseline_run_cnt_delta": 3054,
      "baseline_run_time_ns_delta": 2647327,
      "post_rejit_avg_ns_per_run": 861.1329365079365,
      "post_rejit_run_cnt_delta": 3024,
      "post_rejit_run_time_ns_delta": 2604066,
      "program": "tracepoint__sock__inet_sock_set_state",
      "program_id": 44,
      "ratio": 0.9934171290872786,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 190.65665219891483,
      "baseline_run_cnt_delta": 13172975,
      "baseline_run_time_ns_delta": 2511515313,
      "post_rejit_avg_ns_per_run": 177.0333347418801,
      "post_rejit_run_cnt_delta": 7194176,
      "post_rejit_run_time_ns_delta": 1273608968,
      "program": "sched_switch",
      "program_id": 47,
      "ratio": 0.9285452812691722,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 84.18314159809015,
      "baseline_run_cnt_delta": 573447,
      "baseline_run_time_ns_delta": 48274570,
      "post_rejit_avg_ns_per_run": 68.47520040859641,
      "post_rejit_run_cnt_delta": 931971,
      "post_rejit_run_time_ns_delta": 63816901,
      "program": "sched_wakeup",
      "program_id": 48,
      "ratio": 0.8134075197087904,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 195.22561738557786,
      "baseline_run_cnt_delta": 30370,
      "baseline_run_time_ns_delta": 5929002,
      "post_rejit_avg_ns_per_run": 219.05064343430985,
      "post_rejit_run_cnt_delta": 30073,
      "post_rejit_run_time_ns_delta": 6587510,
      "program": "raw_tracepoint__sched_wakeup_new",
      "program_id": 49,
      "ratio": 1.1220384208168577,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 3242.0,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 9726,
      "post_rejit_avg_ns_per_run": 3563.6666666666665,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 10691,
      "program": "tracepoint__sched_process_free",
      "program_id": 192,
      "ratio": 1.099218589348139,
      "runner": "otelcol-ebpf-profiler",
      "type": "tracepoint",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 958.703125,
      "baseline_run_cnt_delta": 1600,
      "baseline_run_time_ns_delta": 1533925,
      "post_rejit_avg_ns_per_run": 932.7617574257425,
      "post_rejit_run_cnt_delta": 1616,
      "post_rejit_run_time_ns_delta": 1507343,
      "program": "native_tracer_entry",
      "program_id": 193,
      "ratio": 0.9729411880510377,
      "runner": "otelcol-ebpf-profiler",
      "type": "perf_event",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "cilium/agent",
      "baseline_avg_ns_per_run": 590.3258426966293,
      "baseline_run_cnt_delta": 267,
      "baseline_run_time_ns_delta": 157617,
      "post_rejit_avg_ns_per_run": 606.7516129032258,
      "post_rejit_run_cnt_delta": 310,
      "post_rejit_run_time_ns_delta": 188093,
      "program": "cil_from_netdev",
      "program_id": 321,
      "ratio": 1.0278249214561963,
      "runner": "cilium",
      "type": "sched_cls",
      "workload": "network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1536.3502824858756,
      "baseline_run_cnt_delta": 1062,
      "baseline_run_time_ns_delta": 1631604,
      "post_rejit_avg_ns_per_run": 1615.9856596558318,
      "post_rejit_run_cnt_delta": 1046,
      "post_rejit_run_time_ns_delta": 1690321,
      "program": "event_exit_acct_process",
      "program_id": 336,
      "ratio": 1.051834127983563,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1969.1992882562276,
      "baseline_run_cnt_delta": 1124,
      "baseline_run_time_ns_delta": 2213380,
      "post_rejit_avg_ns_per_run": 1929.2117117117118,
      "post_rejit_run_cnt_delta": 1110,
      "post_rejit_run_time_ns_delta": 2141425,
      "program": "event_wake_up_new_task",
      "program_id": 338,
      "ratio": 0.9796934841572456,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 6089.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 12179,
      "post_rejit_avg_ns_per_run": 6932.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 13865,
      "program": "event_execve",
      "program_id": 341,
      "ratio": 1.138435011084654,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 727.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 1455,
      "post_rejit_avg_ns_per_run": 678.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 1356,
      "program": "tg_kp_bprm_committing_creds",
      "program_id": 342,
      "ratio": 0.931958762886598,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 386.2067711901979,
      "baseline_run_cnt_delta": 124055,
      "baseline_run_time_ns_delta": 47910881,
      "post_rejit_avg_ns_per_run": 450.88617138653916,
      "post_rejit_run_cnt_delta": 97884,
      "post_rejit_run_time_ns_delta": 44134542,
      "program": "generic_kprobe_event",
      "program_id": 373,
      "ratio": 1.167473501298319,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 51.32180081415501,
      "baseline_run_cnt_delta": 124055,
      "baseline_run_time_ns_delta": 6366726,
      "post_rejit_avg_ns_per_run": 86.74178619590536,
      "post_rejit_run_cnt_delta": 97884,
      "post_rejit_run_time_ns_delta": 8490633,
      "program": "generic_retkprobe_event",
      "program_id": 375,
      "ratio": 1.6901547650288453,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1148.9719667421068,
      "baseline_run_cnt_delta": 124602,
      "baseline_run_time_ns_delta": 143164205,
      "post_rejit_avg_ns_per_run": 1325.128497262792,
      "post_rejit_run_cnt_delta": 99006,
      "post_rejit_run_time_ns_delta": 131195672,
      "program": "generic_kprobe_event",
      "program_id": 380,
      "ratio": 1.1533166479423989,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 391.0023940993914,
      "baseline_run_cnt_delta": 124055,
      "baseline_run_time_ns_delta": 48505802,
      "post_rejit_avg_ns_per_run": 468.51327081034697,
      "post_rejit_run_cnt_delta": 97884,
      "post_rejit_run_time_ns_delta": 45859953,
      "program": "generic_kprobe_event",
      "program_id": 393,
      "ratio": 1.1982363225409116,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 54.779106041675064,
      "baseline_run_cnt_delta": 124055,
      "baseline_run_time_ns_delta": 6795622,
      "post_rejit_avg_ns_per_run": 111.66390829961996,
      "post_rejit_run_cnt_delta": 97884,
      "post_rejit_run_time_ns_delta": 10930110,
      "program": "generic_retkprobe_event",
      "program_id": 399,
      "ratio": 2.038439769620699,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1187.8544244875684,
      "baseline_run_cnt_delta": 124602,
      "baseline_run_time_ns_delta": 148009037,
      "post_rejit_avg_ns_per_run": 1375.9241359109549,
      "post_rejit_run_cnt_delta": 99006,
      "post_rejit_run_time_ns_delta": 136224745,
      "program": "generic_kprobe_event",
      "program_id": 409,
      "ratio": 1.158327239050794,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 454.02069279499864,
      "baseline_run_cnt_delta": 180111,
      "baseline_run_time_ns_delta": 81774121,
      "post_rejit_avg_ns_per_run": 514.6700205969593,
      "post_rejit_run_cnt_delta": 198573,
      "post_rejit_run_time_ns_delta": 102199570,
      "program": "generic_kprobe_event",
      "program_id": 413,
      "ratio": 1.133582739210843,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 953.5363705762176,
      "baseline_run_cnt_delta": 364168,
      "baseline_run_time_ns_delta": 347247433,
      "post_rejit_avg_ns_per_run": 868.2120842087811,
      "post_rejit_run_cnt_delta": 313649,
      "post_rejit_run_time_ns_delta": 272313852,
      "program": "generic_kprobe_event",
      "program_id": 423,
      "ratio": 0.9105180578315273,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 189.42340819916865,
      "baseline_run_cnt_delta": 360378,
      "baseline_run_time_ns_delta": 68264029,
      "post_rejit_avg_ns_per_run": 185.28975399054139,
      "post_rejit_run_cnt_delta": 326898,
      "post_rejit_run_time_ns_delta": 60570850,
      "program": "generic_kprobe_event",
      "program_id": 439,
      "ratio": 0.9781777012253895,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 536.3678487971222,
      "baseline_run_cnt_delta": 641046,
      "baseline_run_time_ns_delta": 343836464,
      "post_rejit_avg_ns_per_run": 546.152374124804,
      "post_rejit_run_cnt_delta": 591439,
      "post_rejit_run_time_ns_delta": 323015814,
      "program": "generic_kprobe_event",
      "program_id": 448,
      "ratio": 1.0182421920881817,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 37.25303020376073,
      "baseline_run_cnt_delta": 641046,
      "baseline_run_time_ns_delta": 23880906,
      "post_rejit_avg_ns_per_run": 37.58816378358546,
      "post_rejit_run_cnt_delta": 591439,
      "post_rejit_run_time_ns_delta": 22231106,
      "program": "generic_retkprobe_event",
      "program_id": 455,
      "ratio": 1.0089961428101732,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 5088.116947852761,
      "baseline_run_cnt_delta": 2608,
      "baseline_run_time_ns_delta": 13269809,
      "post_rejit_avg_ns_per_run": 7148.2987361164305,
      "post_rejit_run_cnt_delta": 2611,
      "post_rejit_run_time_ns_delta": 18664208,
      "program": "generic_kprobe_event",
      "program_id": 462,
      "ratio": 1.404900636007018,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 61.956288343558285,
      "baseline_run_cnt_delta": 2608,
      "baseline_run_time_ns_delta": 161582,
      "post_rejit_avg_ns_per_run": 81.38184603600153,
      "post_rejit_run_cnt_delta": 2611,
      "post_rejit_run_time_ns_delta": 212488,
      "program": "generic_retkprobe_event",
      "program_id": 464,
      "ratio": 1.3135364982602764,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 7348.0,
      "baseline_run_cnt_delta": 6,
      "baseline_run_time_ns_delta": 44088,
      "post_rejit_avg_ns_per_run": 7418.5,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 29674,
      "program": "generic_kprobe_event",
      "program_id": 468,
      "ratio": 1.0095944474686989,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 558.8333333333334,
      "baseline_run_cnt_delta": 6,
      "baseline_run_time_ns_delta": 3353,
      "post_rejit_avg_ns_per_run": 514.25,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 2057,
      "program": "generic_retkprobe_event",
      "program_id": 475,
      "ratio": 0.9202206978824933,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 5264.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 10528,
      "post_rejit_avg_ns_per_run": 5984.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 11969,
      "program": "generic_kprobe_event",
      "program_id": 516,
      "ratio": 1.1368731003039514,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1018.9743718386031,
      "baseline_run_cnt_delta": 5828120,
      "baseline_run_time_ns_delta": 5938704916,
      "post_rejit_avg_ns_per_run": 1018.7801254060806,
      "post_rejit_run_cnt_delta": 6097312,
      "post_rejit_run_time_ns_delta": 6211820284,
      "program": "generic_tracepoint_event",
      "program_id": 526,
      "ratio": 0.9998093706398405,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3802.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 7605,
      "post_rejit_avg_ns_per_run": 4108.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 8217,
      "program": "generic_rawtp_event",
      "program_id": 530,
      "ratio": 1.0804733727810651,
      "runner": "tetragon",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 506.71224379719524,
      "baseline_run_cnt_delta": 25956,
      "baseline_run_time_ns_delta": 13152223,
      "post_rejit_avg_ns_per_run": 635.5634141317037,
      "post_rejit_run_cnt_delta": 14563,
      "post_rejit_run_time_ns_delta": 9255710,
      "program": "generic_kprobe_event",
      "program_id": 538,
      "ratio": 1.2542886458967812,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3146.6898263027297,
      "baseline_run_cnt_delta": 806,
      "baseline_run_time_ns_delta": 2536232,
      "post_rejit_avg_ns_per_run": 4433.316313823163,
      "post_rejit_run_cnt_delta": 803,
      "post_rejit_run_time_ns_delta": 3559953,
      "program": "generic_kprobe_event",
      "program_id": 542,
      "ratio": 1.4088825268908638,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 402.1560920559429,
      "baseline_run_cnt_delta": 124055,
      "baseline_run_time_ns_delta": 49889474,
      "post_rejit_avg_ns_per_run": 467.00940909648153,
      "post_rejit_run_cnt_delta": 97884,
      "post_rejit_run_time_ns_delta": 45712749,
      "program": "generic_kprobe_event",
      "program_id": 557,
      "ratio": 1.1612640423000655,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 59.5934303333199,
      "baseline_run_cnt_delta": 124055,
      "baseline_run_time_ns_delta": 7392863,
      "post_rejit_avg_ns_per_run": 101.16413305545339,
      "post_rejit_run_cnt_delta": 97884,
      "post_rejit_run_time_ns_delta": 9902350,
      "program": "generic_retkprobe_event",
      "program_id": 563,
      "ratio": 1.6975719049838025,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1188.5312113770244,
      "baseline_run_cnt_delta": 124602,
      "baseline_run_time_ns_delta": 148093366,
      "post_rejit_avg_ns_per_run": 1398.316788881482,
      "post_rejit_run_cnt_delta": 99006,
      "post_rejit_run_time_ns_delta": 138441752,
      "program": "generic_kprobe_event",
      "program_id": 568,
      "ratio": 1.1765082612019935,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1332.5294117647059,
      "baseline_run_cnt_delta": 17,
      "baseline_run_time_ns_delta": 22653,
      "post_rejit_avg_ns_per_run": 1325.5882352941176,
      "post_rejit_run_cnt_delta": 17,
      "post_rejit_run_time_ns_delta": 22535,
      "program": "generic_kprobe_event",
      "program_id": 578,
      "ratio": 0.9947909769125501,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1465.6,
      "baseline_run_cnt_delta": 5,
      "baseline_run_time_ns_delta": 7328,
      "post_rejit_avg_ns_per_run": 1679.8,
      "post_rejit_run_cnt_delta": 5,
      "post_rejit_run_time_ns_delta": 8399,
      "program": "generic_kprobe_event",
      "program_id": 584,
      "ratio": 1.146151746724891,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4233.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 8467,
      "post_rejit_avg_ns_per_run": 7727.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 15455,
      "program": "generic_kprobe_event",
      "program_id": 592,
      "ratio": 1.8253218377229243,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2579.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 5158,
      "post_rejit_avg_ns_per_run": 3004.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 6009,
      "program": "generic_retkprobe_event",
      "program_id": 597,
      "ratio": 1.1649864288483909,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 6057.0,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 18171,
      "post_rejit_avg_ns_per_run": 5633.666666666667,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 16901,
      "program": "generic_kprobe_event",
      "program_id": 600,
      "ratio": 0.9301084145066315,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1901.8,
      "baseline_run_cnt_delta": 5,
      "baseline_run_time_ns_delta": 9509,
      "post_rejit_avg_ns_per_run": 1910.0,
      "post_rejit_run_cnt_delta": 5,
      "post_rejit_run_time_ns_delta": 9550,
      "program": "generic_kprobe_event",
      "program_id": 610,
      "ratio": 1.0043117047008099,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1195.0549799155424,
      "baseline_run_cnt_delta": 145635,
      "baseline_run_time_ns_delta": 174041832,
      "post_rejit_avg_ns_per_run": 1275.6332195459295,
      "post_rejit_run_cnt_delta": 135926,
      "post_rejit_run_time_ns_delta": 173391721,
      "program": "generic_kprobe_event",
      "program_id": 614,
      "ratio": 1.0674263870571727,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "katran",
      "baseline_avg_ns_per_run": 324.36304295656345,
      "baseline_run_cnt_delta": 41670,
      "baseline_run_time_ns_delta": 13516208,
      "post_rejit_avg_ns_per_run": 336.333457822926,
      "post_rejit_run_cnt_delta": 40164,
      "post_rejit_run_time_ns_delta": 13508497,
      "program": "xdp_root",
      "program_id": 632,
      "ratio": 1.03690437343679,
      "runner": "katran",
      "type": "xdp",
      "workload": "network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 148.3740077991518,
      "baseline_run_cnt_delta": 30652564,
      "baseline_run_time_ns_delta": 4548043770,
      "post_rejit_avg_ns_per_run": 148.96527275331255,
      "post_rejit_run_cnt_delta": 29618962,
      "post_rejit_run_time_ns_delta": 4412196753,
      "program": "tracepoint__raw_syscalls__sys_enter",
      "program_id": 655,
      "ratio": 1.0039849631544706,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 300.7704679173873,
      "baseline_run_cnt_delta": 30652569,
      "baseline_run_time_ns_delta": 9219387521,
      "post_rejit_avg_ns_per_run": 300.9426852057332,
      "post_rejit_run_cnt_delta": 29618967,
      "post_rejit_run_time_ns_delta": 8913611462,
      "program": "tracepoint__raw_syscalls__sys_exit",
      "program_id": 658,
      "ratio": 1.0005725870945321,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 259.6021894285907,
      "baseline_run_cnt_delta": 30652564,
      "baseline_run_time_ns_delta": 7957472726,
      "post_rejit_avg_ns_per_run": 259.30723311640696,
      "post_rejit_run_cnt_delta": 29618962,
      "post_rejit_run_time_ns_delta": 7680411084,
      "program": "trace_sys_enter",
      "program_id": 661,
      "ratio": 0.9988638142350303,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 253.82586930968168,
      "baseline_run_cnt_delta": 30652569,
      "baseline_run_time_ns_delta": 7780414973,
      "post_rejit_avg_ns_per_run": 254.64237125487867,
      "post_rejit_run_cnt_delta": 29618967,
      "post_rejit_run_time_ns_delta": 7542243991,
      "program": "trace_sys_exit",
      "program_id": 662,
      "ratio": 1.0032167798633669,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 67.8134771724855,
      "baseline_run_cnt_delta": 1045427,
      "baseline_run_time_ns_delta": 70894040,
      "post_rejit_avg_ns_per_run": 68.23974661935904,
      "post_rejit_run_cnt_delta": 1022809,
      "post_rejit_run_time_ns_delta": 69796227,
      "program": "trace_arch_prctl",
      "program_id": 667,
      "ratio": 1.006285910480439,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 277.02744907104943,
      "baseline_run_cnt_delta": 1045427,
      "baseline_run_time_ns_delta": 289611975,
      "post_rejit_avg_ns_per_run": 278.8277703852821,
      "post_rejit_run_cnt_delta": 1022809,
      "post_rejit_run_time_ns_delta": 285187553,
      "program": "trace_ret_arch_prctl",
      "program_id": 668,
      "ratio": 1.0064987109409904,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 239.90019255455712,
      "baseline_run_cnt_delta": 3116,
      "baseline_run_time_ns_delta": 747529,
      "post_rejit_avg_ns_per_run": 218.953006993007,
      "post_rejit_run_cnt_delta": 3575,
      "post_rejit_run_time_ns_delta": 782757,
      "program": "trace_dup",
      "program_id": 669,
      "ratio": 0.9126837484434849,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1000.900513478819,
      "baseline_run_cnt_delta": 3116,
      "baseline_run_time_ns_delta": 3118806,
      "post_rejit_avg_ns_per_run": 858.0772027972027,
      "post_rejit_run_cnt_delta": 3575,
      "post_rejit_run_time_ns_delta": 3067626,
      "program": "trace_ret_dup",
      "program_id": 670,
      "ratio": 0.8573051879200193,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 585.75,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 2343,
      "post_rejit_avg_ns_per_run": 601.75,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 2407,
      "program": "trace_dup2",
      "program_id": 671,
      "ratio": 1.0273154075970978,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1404.25,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 5617,
      "post_rejit_avg_ns_per_run": 1838.25,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 7353,
      "program": "trace_ret_dup2",
      "program_id": 672,
      "ratio": 1.3090617767491544,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1944.6413470993116,
      "baseline_run_cnt_delta": 4068,
      "baseline_run_time_ns_delta": 7910801,
      "post_rejit_avg_ns_per_run": 2385.4974054855447,
      "post_rejit_run_cnt_delta": 4047,
      "post_rejit_run_time_ns_delta": 9654108,
      "program": "tracepoint__sched__sched_process_fork",
      "program_id": 680,
      "ratio": 1.226703015979696,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4312.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 8624,
      "post_rejit_avg_ns_per_run": 5668.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 11337,
      "program": "tracepoint__sched__sched_process_exec",
      "program_id": 688,
      "ratio": 1.31458719851577,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1405.7574857708487,
      "baseline_run_cnt_delta": 4041,
      "baseline_run_time_ns_delta": 5680666,
      "post_rejit_avg_ns_per_run": 1428.8897597977243,
      "post_rejit_run_cnt_delta": 3955,
      "post_rejit_run_time_ns_delta": 5651259,
      "program": "tracepoint__sched__sched_process_exit",
      "program_id": 690,
      "ratio": 1.0164553802921354,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 945.9834240475012,
      "baseline_run_cnt_delta": 4042,
      "baseline_run_time_ns_delta": 3823665,
      "post_rejit_avg_ns_per_run": 963.1116738414788,
      "post_rejit_run_cnt_delta": 3949,
      "post_rejit_run_time_ns_delta": 3803328,
      "program": "tracepoint__sched__sched_process_free",
      "program_id": 691,
      "ratio": 1.0181062895591684,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 372.2682224305487,
      "baseline_run_cnt_delta": 1825127,
      "baseline_run_time_ns_delta": 679436784,
      "post_rejit_avg_ns_per_run": 391.82437951344394,
      "post_rejit_run_cnt_delta": 1492901,
      "post_rejit_run_time_ns_delta": 584955008,
      "program": "tracepoint__sched__sched_switch",
      "program_id": 693,
      "ratio": 1.0525324373786529,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 16.74392578774055,
      "baseline_run_cnt_delta": 529616,
      "baseline_run_time_ns_delta": 8867851,
      "post_rejit_avg_ns_per_run": 16.768480049132354,
      "post_rejit_run_cnt_delta": 491733,
      "post_rejit_run_time_ns_delta": 8245615,
      "program": "trace_filldir64",
      "program_id": 694,
      "ratio": 1.0014664578488386,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 895.1841128433556,
      "baseline_run_cnt_delta": 4041,
      "baseline_run_time_ns_delta": 3617439,
      "post_rejit_avg_ns_per_run": 865.5418457648547,
      "post_rejit_run_cnt_delta": 3955,
      "post_rejit_run_time_ns_delta": 3423218,
      "program": "trace_do_exit",
      "program_id": 696,
      "ratio": 0.9668869602875896,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 92.61685238443657,
      "baseline_run_cnt_delta": 4432263,
      "baseline_run_time_ns_delta": 410502248,
      "post_rejit_avg_ns_per_run": 93.93860933186974,
      "post_rejit_run_cnt_delta": 4129569,
      "post_rejit_run_time_ns_delta": 387925969,
      "program": "trace_security_file_ioctl",
      "program_id": 700,
      "ratio": 1.014271235886389,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3853.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 7707,
      "post_rejit_avg_ns_per_run": 4335.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 8670,
      "program": "trace_security_bprm_check",
      "program_id": 705,
      "ratio": 1.1249513429349942,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 564.2128137652934,
      "baseline_run_cnt_delta": 728092,
      "baseline_run_time_ns_delta": 410798836,
      "post_rejit_avg_ns_per_run": 557.6961294479845,
      "post_rejit_run_cnt_delta": 698350,
      "post_rejit_run_time_ns_delta": 389467092,
      "program": "trace_security_file_open",
      "program_id": 706,
      "ratio": 0.9884499533539134,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2095.706896551724,
      "baseline_run_cnt_delta": 116,
      "baseline_run_time_ns_delta": 243102,
      "post_rejit_avg_ns_per_run": 2146.310344827586,
      "post_rejit_run_cnt_delta": 116,
      "post_rejit_run_time_ns_delta": 248972,
      "program": "trace_security_inode_unlink",
      "program_id": 708,
      "ratio": 1.024146243140739,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 250.6558194336462,
      "baseline_run_cnt_delta": 374289,
      "baseline_run_time_ns_delta": 93817716,
      "post_rejit_avg_ns_per_run": 240.467199743544,
      "post_rejit_run_cnt_delta": 386811,
      "post_rejit_run_time_ns_delta": 93015358,
      "program": "trace_commit_creds",
      "program_id": 709,
      "ratio": 0.9593521518346422,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 523.8126701311556,
      "baseline_run_cnt_delta": 4041,
      "baseline_run_time_ns_delta": 2116727,
      "post_rejit_avg_ns_per_run": 500.9714285714286,
      "post_rejit_run_cnt_delta": 3955,
      "post_rejit_run_time_ns_delta": 1981342,
      "program": "trace_switch_task_namespaces",
      "program_id": 710,
      "ratio": 0.9563942553088532,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 134.27410416398206,
      "baseline_run_cnt_delta": 2491053,
      "baseline_run_time_ns_delta": 334483910,
      "post_rejit_avg_ns_per_run": 133.5297820075574,
      "post_rejit_run_cnt_delta": 2526005,
      "post_rejit_run_time_ns_delta": 337296897,
      "program": "trace_cap_capable",
      "program_id": 711,
      "ratio": 0.9944566961659588,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 304.37530535474133,
      "baseline_run_cnt_delta": 887083,
      "baseline_run_time_ns_delta": 270006159,
      "post_rejit_avg_ns_per_run": 296.5141066790104,
      "post_rejit_run_cnt_delta": 784203,
      "post_rejit_run_time_ns_delta": 232527252,
      "program": "trace_security_socket_create",
      "program_id": 712,
      "ratio": 0.9741726791318734,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2348.25,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 9393,
      "post_rejit_avg_ns_per_run": 1346.5,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 5386,
      "program": "trace_security_socket_listen",
      "program_id": 717,
      "ratio": 0.5734057276695411,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 380.20584178898633,
      "baseline_run_cnt_delta": 203020,
      "baseline_run_time_ns_delta": 77189390,
      "post_rejit_avg_ns_per_run": 348.2518950437318,
      "post_rejit_run_cnt_delta": 123480,
      "post_rejit_run_time_ns_delta": 43002144,
      "program": "trace_security_socket_connect",
      "program_id": 718,
      "ratio": 0.9159561920592768,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 454.2815885165638,
      "baseline_run_cnt_delta": 209554,
      "baseline_run_time_ns_delta": 95196524,
      "post_rejit_avg_ns_per_run": 443.1538081844037,
      "post_rejit_run_cnt_delta": 127633,
      "post_rejit_run_time_ns_delta": 56561050,
      "program": "trace_security_socket_accept",
      "program_id": 719,
      "ratio": 0.9755046635975336,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1379.25,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 5517,
      "post_rejit_avg_ns_per_run": 1417.5,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 5670,
      "program": "trace_security_socket_bind",
      "program_id": 720,
      "ratio": 1.0277324632952691,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 349.63695557589307,
      "baseline_run_cnt_delta": 66653,
      "baseline_run_time_ns_delta": 23304352,
      "post_rejit_avg_ns_per_run": 351.0636151490107,
      "post_rejit_run_cnt_delta": 123414,
      "post_rejit_run_time_ns_delta": 43326165,
      "program": "trace_security_socket_setsockopt",
      "program_id": 721,
      "ratio": 1.0040804026873182,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 65.81727679367884,
      "baseline_run_cnt_delta": 930462,
      "baseline_run_time_ns_delta": 61240475,
      "post_rejit_avg_ns_per_run": 61.92908918238438,
      "post_rejit_run_cnt_delta": 905560,
      "post_rejit_run_time_ns_delta": 56080506,
      "program": "trace_vfs_write",
      "program_id": 724,
      "ratio": 0.9409245140378113,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 81.24998549107863,
      "baseline_run_cnt_delta": 930462,
      "baseline_run_time_ns_delta": 75600024,
      "post_rejit_avg_ns_per_run": 82.27086443747515,
      "post_rejit_run_cnt_delta": 905560,
      "post_rejit_run_time_ns_delta": 74501204,
      "program": "vfs_write_magic_enter",
      "program_id": 725,
      "ratio": 1.0125646661993388,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 668.0130623281767,
      "baseline_run_cnt_delta": 930462,
      "baseline_run_time_ns_delta": 621560770,
      "post_rejit_avg_ns_per_run": 625.5313198462829,
      "post_rejit_run_cnt_delta": 905560,
      "post_rejit_run_time_ns_delta": 566456142,
      "program": "trace_ret_vfs_write",
      "program_id": 726,
      "ratio": 0.9364058206678845,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 41.71275452409663,
      "baseline_run_cnt_delta": 930462,
      "baseline_run_time_ns_delta": 38812133,
      "post_rejit_avg_ns_per_run": 41.7001899377181,
      "post_rejit_run_cnt_delta": 905560,
      "post_rejit_run_time_ns_delta": 37762024,
      "program": "vfs_write_magic_return",
      "program_id": 727,
      "ratio": 0.9996987831055062,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 694.2156862745098,
      "baseline_run_cnt_delta": 51,
      "baseline_run_time_ns_delta": 35405,
      "post_rejit_avg_ns_per_run": 657.3921568627451,
      "post_rejit_run_cnt_delta": 51,
      "post_rejit_run_time_ns_delta": 33527,
      "program": "trace_vfs_writev",
      "program_id": 729,
      "ratio": 0.9469566445417313,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 518.0196078431372,
      "baseline_run_cnt_delta": 51,
      "baseline_run_time_ns_delta": 26419,
      "post_rejit_avg_ns_per_run": 484.0980392156863,
      "post_rejit_run_cnt_delta": 51,
      "post_rejit_run_time_ns_delta": 24689,
      "program": "vfs_writev_magic_enter",
      "program_id": 730,
      "ratio": 0.9345168250123018,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5162.274509803921,
      "baseline_run_cnt_delta": 51,
      "baseline_run_time_ns_delta": 263276,
      "post_rejit_avg_ns_per_run": 4890.450980392156,
      "post_rejit_run_cnt_delta": 51,
      "post_rejit_run_time_ns_delta": 249413,
      "program": "trace_ret_vfs_writev",
      "program_id": 731,
      "ratio": 0.9473442319087193,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3604.529411764706,
      "baseline_run_cnt_delta": 51,
      "baseline_run_time_ns_delta": 183831,
      "post_rejit_avg_ns_per_run": 3573.0196078431372,
      "post_rejit_run_cnt_delta": 51,
      "post_rejit_run_time_ns_delta": 182224,
      "program": "vfs_writev_magic_return",
      "program_id": 732,
      "ratio": 0.9912582752636933,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 63.842785203689566,
      "baseline_run_cnt_delta": 1188107,
      "baseline_run_time_ns_delta": 75852060,
      "post_rejit_avg_ns_per_run": 62.55351038261155,
      "post_rejit_run_cnt_delta": 1138779,
      "post_rejit_run_time_ns_delta": 71234624,
      "program": "trace_vfs_read",
      "program_id": 739,
      "ratio": 0.9798054734459877,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 620.3211444760447,
      "baseline_run_cnt_delta": 1188107,
      "baseline_run_time_ns_delta": 737007894,
      "post_rejit_avg_ns_per_run": 606.8005381202147,
      "post_rejit_run_cnt_delta": 1138779,
      "post_rejit_run_time_ns_delta": 691011710,
      "program": "trace_ret_vfs_read",
      "program_id": 740,
      "ratio": 0.9782038602484683,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 470.7843137254902,
      "baseline_run_cnt_delta": 51,
      "baseline_run_time_ns_delta": 24010,
      "post_rejit_avg_ns_per_run": 494.7450980392157,
      "post_rejit_run_cnt_delta": 51,
      "post_rejit_run_time_ns_delta": 25232,
      "program": "trace_vfs_readv",
      "program_id": 742,
      "ratio": 1.0508954602249063,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2841.627450980392,
      "baseline_run_cnt_delta": 51,
      "baseline_run_time_ns_delta": 144923,
      "post_rejit_avg_ns_per_run": 2696.627450980392,
      "post_rejit_run_cnt_delta": 51,
      "post_rejit_run_time_ns_delta": 137528,
      "program": "trace_ret_vfs_readv",
      "program_id": 743,
      "ratio": 0.9489729028518593,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 134.417912291538,
      "baseline_run_cnt_delta": 8095,
      "baseline_run_time_ns_delta": 1088113,
      "post_rejit_avg_ns_per_run": 147.07634342186535,
      "post_rejit_run_cnt_delta": 8095,
      "post_rejit_run_time_ns_delta": 1190583,
      "program": "trace_mmap_alert",
      "program_id": 745,
      "ratio": 1.0941722045412563,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 74.35696168735817,
      "baseline_run_cnt_delta": 7491,
      "baseline_run_time_ns_delta": 557008,
      "post_rejit_avg_ns_per_run": 90.768522226672,
      "post_rejit_run_cnt_delta": 7491,
      "post_rejit_run_time_ns_delta": 679947,
      "program": "trace_do_mmap",
      "program_id": 746,
      "ratio": 1.2207131674949012,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 379.2025096782806,
      "baseline_run_cnt_delta": 7491,
      "baseline_run_time_ns_delta": 2840606,
      "post_rejit_avg_ns_per_run": 415.8063008944066,
      "post_rejit_run_cnt_delta": 7491,
      "post_rejit_run_time_ns_delta": 3114805,
      "program": "trace_ret_do_mmap",
      "program_id": 747,
      "ratio": 1.0965283464162225,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 133.5283044058745,
      "baseline_run_cnt_delta": 7490,
      "baseline_run_time_ns_delta": 1000127,
      "post_rejit_avg_ns_per_run": 147.01535380507343,
      "post_rejit_run_cnt_delta": 7490,
      "post_rejit_run_time_ns_delta": 1101145,
      "program": "trace_security_mmap_file",
      "program_id": 748,
      "ratio": 1.1010051723431125,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1105.076923076923,
      "baseline_run_cnt_delta": 39,
      "baseline_run_time_ns_delta": 43098,
      "post_rejit_avg_ns_per_run": 1198.7435897435898,
      "post_rejit_run_cnt_delta": 39,
      "post_rejit_run_time_ns_delta": 46751,
      "program": "trace_security_file_mprotect",
      "program_id": 749,
      "ratio": 1.0847603137036521,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 259.8723360655738,
      "baseline_run_cnt_delta": 9760,
      "baseline_run_time_ns_delta": 2536354,
      "post_rejit_avg_ns_per_run": 253.6762295081967,
      "post_rejit_run_cnt_delta": 9760,
      "post_rejit_run_time_ns_delta": 2475880,
      "program": "trace_security_bpf",
      "program_id": 751,
      "ratio": 0.976157113715199,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 244.28469871360866,
      "baseline_run_cnt_delta": 2954,
      "baseline_run_time_ns_delta": 721617,
      "post_rejit_avg_ns_per_run": 245.99627623561273,
      "post_rejit_run_cnt_delta": 2954,
      "post_rejit_run_time_ns_delta": 726673,
      "program": "trace_security_bpf_map",
      "program_id": 754,
      "ratio": 1.007006486820571,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 646.0574162679426,
      "baseline_run_cnt_delta": 209,
      "baseline_run_time_ns_delta": 135026,
      "post_rejit_avg_ns_per_run": 744.3253588516747,
      "post_rejit_run_cnt_delta": 209,
      "post_rejit_run_time_ns_delta": 155564,
      "program": "trace_security_bpf_prog",
      "program_id": 755,
      "ratio": 1.1521040392220758,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1366.25,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 5465,
      "post_rejit_avg_ns_per_run": 1466.0,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 5864,
      "program": "trace_security_inode_mknod",
      "program_id": 761,
      "ratio": 1.0730100640439157,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1302.25,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 5209,
      "post_rejit_avg_ns_per_run": 1658.5,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 6634,
      "program": "trace_load_elf_phdrs",
      "program_id": 769,
      "ratio": 1.2735649836820886,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 52.25277842707418,
      "baseline_run_cnt_delta": 3165820,
      "baseline_run_time_ns_delta": 165422891,
      "post_rejit_avg_ns_per_run": 52.17014291638271,
      "post_rejit_run_cnt_delta": 3043318,
      "post_rejit_run_time_ns_delta": 158770335,
      "program": "trace_security_file_permission",
      "program_id": 770,
      "ratio": 0.998418543220495,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 943.2111515151515,
      "baseline_run_cnt_delta": 4125,
      "baseline_run_time_ns_delta": 3890746,
      "post_rejit_avg_ns_per_run": 967.9584055459272,
      "post_rejit_run_cnt_delta": 4039,
      "post_rejit_run_time_ns_delta": 3909584,
      "program": "tracepoint__task__task_rename",
      "program_id": 771,
      "ratio": 1.0262372364777732,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1000.4880136986301,
      "baseline_run_cnt_delta": 8176,
      "baseline_run_time_ns_delta": 8179990,
      "post_rejit_avg_ns_per_run": 985.3325837081459,
      "post_rejit_run_cnt_delta": 8004,
      "post_rejit_run_time_ns_delta": 7886602,
      "program": "trace_do_sigaction",
      "program_id": 775,
      "ratio": 0.984851962459343,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2915.6679536679535,
      "baseline_run_cnt_delta": 259,
      "baseline_run_time_ns_delta": 755158,
      "post_rejit_avg_ns_per_run": 2929.59778597786,
      "post_rejit_run_cnt_delta": 271,
      "post_rejit_run_time_ns_delta": 793921,
      "program": "trace_do_truncate",
      "program_id": 778,
      "ratio": 1.0047775784249995,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 150.23047905419259,
      "baseline_run_cnt_delta": 2121785,
      "baseline_run_time_ns_delta": 318756777,
      "post_rejit_avg_ns_per_run": 148.38408014281765,
      "post_rejit_run_cnt_delta": 1920771,
      "post_rejit_run_time_ns_delta": 285011838,
      "program": "trace_fd_install",
      "program_id": 779,
      "ratio": 0.987709558519687,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 292.3658411721686,
      "baseline_run_cnt_delta": 396530,
      "baseline_run_time_ns_delta": 115931827,
      "post_rejit_avg_ns_per_run": 295.8449559471925,
      "post_rejit_run_cnt_delta": 393959,
      "post_rejit_run_time_ns_delta": 116550783,
      "program": "trace_filp_close",
      "program_id": 780,
      "ratio": 1.0118998675121391,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 187.20189451263943,
      "baseline_run_cnt_delta": 35682,
      "baseline_run_time_ns_delta": 6679738,
      "post_rejit_avg_ns_per_run": 185.5912970182278,
      "post_rejit_run_cnt_delta": 37964,
      "post_rejit_run_time_ns_delta": 7045788,
      "program": "trace_file_update_time",
      "program_id": 781,
      "ratio": 0.9913964679759003,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 644.0865702595146,
      "baseline_run_cnt_delta": 35682,
      "baseline_run_time_ns_delta": 22982297,
      "post_rejit_avg_ns_per_run": 643.2255557896955,
      "post_rejit_run_cnt_delta": 37964,
      "post_rejit_run_time_ns_delta": 24419415,
      "program": "trace_ret_file_update_time",
      "program_id": 782,
      "ratio": 0.9986632007100036,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 125.67433373280831,
      "baseline_run_cnt_delta": 350460,
      "baseline_run_time_ns_delta": 44043827,
      "post_rejit_avg_ns_per_run": 119.2491544008865,
      "post_rejit_run_cnt_delta": 344726,
      "post_rejit_run_time_ns_delta": 41108284,
      "program": "trace_file_modified",
      "program_id": 783,
      "ratio": 0.9488743712333327,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 503.68370427438225,
      "baseline_run_cnt_delta": 350460,
      "baseline_run_time_ns_delta": 176520991,
      "post_rejit_avg_ns_per_run": 507.0901730649849,
      "post_rejit_run_cnt_delta": 344726,
      "post_rejit_run_time_ns_delta": 174807167,
      "program": "trace_ret_file_modified",
      "program_id": 784,
      "ratio": 1.0067631109795583,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 99.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 199,
      "post_rejit_avg_ns_per_run": 101.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 202,
      "program": "trace_exec_binprm",
      "program_id": 788,
      "ratio": 1.015075376884422,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3092.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 6184,
      "post_rejit_avg_ns_per_run": 3633.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 7267,
      "program": "trace_security_bprm_creds_for_exec",
      "program_id": 789,
      "ratio": 1.1751293661060802,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5159.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 10319,
      "post_rejit_avg_ns_per_run": 5828.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 11657,
      "program": "trace_execute_finished",
      "program_id": 790,
      "ratio": 1.1296637271053396,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2342.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 4685,
      "post_rejit_avg_ns_per_run": 2804.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 5609,
      "program": "trace_set_fs_pwd",
      "program_id": 792,
      "ratio": 1.1972251867662753,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 288.15217937121577,
      "baseline_run_cnt_delta": 621326,
      "baseline_run_time_ns_delta": 179036441,
      "post_rejit_avg_ns_per_run": 271.94217846883464,
      "post_rejit_run_cnt_delta": 634262,
      "post_rejit_run_time_ns_delta": 172482590,
      "program": "trace_security_task_setrlimit",
      "program_id": 793,
      "ratio": 0.9437449998200487,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 345.39225349032984,
      "baseline_run_cnt_delta": 365868,
      "baseline_run_time_ns_delta": 126367973,
      "post_rejit_avg_ns_per_run": 350.0520706455542,
      "post_rejit_run_cnt_delta": 357956,
      "post_rejit_run_time_ns_delta": 125303239,
      "program": "trace_security_task_prctl",
      "program_id": 796,
      "ratio": 1.0134913771462302,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 30.60747559579988,
      "baseline_run_cnt_delta": 1096635,
      "baseline_run_time_ns_delta": 33565229,
      "post_rejit_avg_ns_per_run": 28.63943656411145,
      "post_rejit_run_cnt_delta": 911834,
      "post_rejit_run_time_ns_delta": 26114412,
      "program": "trace_sock_alloc_file",
      "program_id": 799,
      "ratio": 0.9357007073148333,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 106.82087385502012,
      "baseline_run_cnt_delta": 1096635,
      "baseline_run_time_ns_delta": 117143509,
      "post_rejit_avg_ns_per_run": 102.63809969797134,
      "post_rejit_run_cnt_delta": 911834,
      "post_rejit_run_time_ns_delta": 93588909,
      "program": "trace_ret_sock_alloc_file",
      "program_id": 800,
      "ratio": 0.9608431011084431,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 107.4121385446457,
      "baseline_run_cnt_delta": 3147,
      "baseline_run_time_ns_delta": 338026,
      "post_rejit_avg_ns_per_run": 124.87775311592965,
      "post_rejit_run_cnt_delta": 5857,
      "post_rejit_run_time_ns_delta": 731409,
      "program": "trace_security_sk_clone",
      "program_id": 801,
      "ratio": 1.162603731830778,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 159.58407783653948,
      "baseline_run_cnt_delta": 1691956,
      "baseline_run_time_ns_delta": 270009238,
      "post_rejit_avg_ns_per_run": 213.24856575619654,
      "post_rejit_run_cnt_delta": 1835462,
      "post_rejit_run_time_ns_delta": 391409639,
      "program": "trace_security_socket_recvmsg",
      "program_id": 802,
      "ratio": 1.336277206643542,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 160.57588139121447,
      "baseline_run_cnt_delta": 3850305,
      "baseline_run_time_ns_delta": 618266119,
      "post_rejit_avg_ns_per_run": 195.34304209092323,
      "post_rejit_run_cnt_delta": 4265599,
      "post_rejit_run_time_ns_delta": 833255085,
      "program": "trace_security_socket_sendmsg",
      "program_id": 803,
      "ratio": 1.2165154592239464,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 173.51362156575482,
      "baseline_run_cnt_delta": 2885241,
      "baseline_run_time_ns_delta": 500628615,
      "post_rejit_avg_ns_per_run": 198.1991179416509,
      "post_rejit_run_cnt_delta": 2629758,
      "post_rejit_run_time_ns_delta": 521215716,
      "program": "cgroup_bpf_run_filter_skb",
      "program_id": 804,
      "ratio": 1.1422683484624363,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 251.89080374173892,
      "baseline_run_cnt_delta": 557281,
      "baseline_run_time_ns_delta": 140373959,
      "post_rejit_avg_ns_per_run": 308.0630264145792,
      "post_rejit_run_cnt_delta": 439530,
      "post_rejit_run_time_ns_delta": 135402942,
      "program": "cgroup_skb_ingress",
      "program_id": 806,
      "ratio": 1.2230022765358004,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 193.87091988204406,
      "baseline_run_cnt_delta": 2009225,
      "baseline_run_time_ns_delta": 389530299,
      "post_rejit_avg_ns_per_run": 197.7344298992601,
      "post_rejit_run_cnt_delta": 1919994,
      "post_rejit_run_time_ns_delta": 379648919,
      "program": "cgroup_skb_egress",
      "program_id": 807,
      "ratio": 1.0199282595840917,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 67.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 135,
      "post_rejit_avg_ns_per_run": 78.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 157,
      "program": "empty_kprobe",
      "program_id": 810,
      "ratio": 1.162962962962963,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 894.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 1788,
      "post_rejit_avg_ns_per_run": 1024.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 2049,
      "program": "tracepoint__exec_test",
      "program_id": 811,
      "ratio": 1.145973154362416,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 271.7925825307791,
      "baseline_run_cnt_delta": 728092,
      "baseline_run_time_ns_delta": 197890005,
      "post_rejit_avg_ns_per_run": 265.2369556812487,
      "post_rejit_run_cnt_delta": 698350,
      "post_rejit_run_time_ns_delta": 185228228,
      "program": "lsm_file_open_test",
      "program_id": 812,
      "ratio": 0.9758800376798803,
      "runner": "tracee",
      "type": "lsm",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "bpftrace/capable",
      "baseline_avg_ns_per_run": 169.2051392662339,
      "baseline_run_cnt_delta": 1205425,
      "baseline_run_time_ns_delta": 203964105,
      "post_rejit_avg_ns_per_run": 162.8636923566074,
      "post_rejit_run_cnt_delta": 1226615,
      "post_rejit_run_time_ns_delta": 199771048,
      "program": "cap_capable",
      "program_id": 819,
      "ratio": 0.9625221377014522,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 447.9566590198555,
      "baseline_run_cnt_delta": 1350454,
      "baseline_run_time_ns_delta": 604944862,
      "post_rejit_avg_ns_per_run": 437.153357065407,
      "post_rejit_run_cnt_delta": 1381534,
      "post_rejit_run_time_ns_delta": 603942226,
      "program": "block_io_start",
      "program_id": 826,
      "ratio": 0.9758831535664935,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 820.2217703627407,
      "baseline_run_cnt_delta": 1350469,
      "baseline_run_time_ns_delta": 1107684074,
      "post_rejit_avg_ns_per_run": 789.6577211521271,
      "post_rejit_run_cnt_delta": 1381549,
      "post_rejit_run_time_ns_delta": 1090950835,
      "program": "block_io_done",
      "program_id": 827,
      "ratio": 0.9627368471369679,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 1371.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1371,
      "post_rejit_avg_ns_per_run": 1992.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1992,
      "program": "1",
      "program_id": 834,
      "ratio": 1.4529540481400438,
      "runner": "bpftrace",
      "type": "perf_event",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 31.64129024083062,
      "baseline_run_cnt_delta": 1562592,
      "baseline_run_time_ns_delta": 49442427,
      "post_rejit_avg_ns_per_run": 31.46389237347477,
      "post_rejit_run_cnt_delta": 1678025,
      "post_rejit_run_time_ns_delta": 52797198,
      "program": "vfs_create",
      "program_id": 835,
      "ratio": 0.994393469229427,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 65.58925928159314,
      "baseline_run_cnt_delta": 878917,
      "baseline_run_time_ns_delta": 57647515,
      "post_rejit_avg_ns_per_run": 92.9753368256532,
      "post_rejit_run_cnt_delta": 593111,
      "post_rejit_run_time_ns_delta": 55144695,
      "program": "sched_wakeup",
      "program_id": 842,
      "ratio": 1.4175390581327336,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 151.2433289986996,
      "baseline_run_cnt_delta": 19225,
      "baseline_run_time_ns_delta": 2907653,
      "post_rejit_avg_ns_per_run": 135.75827778384877,
      "post_rejit_run_cnt_delta": 27453,
      "post_rejit_run_time_ns_delta": 3726972,
      "program": "tracepoint_sched_sched_wakeup_new",
      "program_id": 843,
      "ratio": 0.8976149803276019,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 130.2495294137748,
      "baseline_run_cnt_delta": 12407928,
      "baseline_run_time_ns_delta": 1616126783,
      "post_rejit_avg_ns_per_run": 139.0055919736062,
      "post_rejit_run_cnt_delta": 11897946,
      "post_rejit_run_time_ns_delta": 1653881027,
      "program": "sched_switch",
      "program_id": 844,
      "ratio": 1.0672252913253548,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline_avg_ns_per_run": 820.3932664756447,
      "baseline_run_cnt_delta": 2792,
      "baseline_run_time_ns_delta": 2290538,
      "post_rejit_avg_ns_per_run": 915.8705374656728,
      "post_rejit_run_cnt_delta": 2549,
      "post_rejit_run_time_ns_delta": 2334554,
      "program": "tcp_set_state",
      "program_id": 852,
      "ratio": 1.1163798813222738,
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
            "avg_ns_per_run": 331.62352349268934,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 973920,
            "run_time_ns_delta": 322974782,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.014147421000004,
            "ops_per_sec": 1422499.3034814356,
            "ops_total": 1442624.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5966] setting to a 1 secs run per stressor\nstress-ng: info:  [5966] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [5966] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5966] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5966]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5966] cap             1243649      1.00      0.25      0.75   1243643.66     1244598.63\nstress-ng: metrc: [5966] eventfd          136306      1.00      0.06      0.68    136261.52      182747.17\nstress-ng: metrc: [5966] get                 984      1.00      0.02      0.12       983.31        6942.78\nstress-ng: metrc: [5966] prctl              4098      1.00      0.63      0.37      4097.21        4111.63\nstress-ng: metrc: [5966] set               57587      1.00      0.15      0.81     57586.15       59637.39\nstress-ng: info:  [5966] skipped: 0\nstress-ng: info:  [5966] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [5966] failed: 0\nstress-ng: info:  [5966] metrics untrustworthy: 0\nstress-ng: info:  [5966] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 353.1444146797315,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 1066886,
            "run_time_ns_delta": 376764832,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0155548640000092,
            "ops_per_sec": 1427609.7248843338,
            "ops_total": 1449816.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [13988] setting to a 1 secs run per stressor\nstress-ng: info:  [13988] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [13988] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13988] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13988]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13988] cap             1231902      1.00      0.31      0.69   1231897.89     1232732.86\nstress-ng: metrc: [13988] eventfd          145036      1.00      0.07      0.66    145013.87      197786.16\nstress-ng: metrc: [13988] get                 974      1.00      0.01      0.14       973.48        6394.77\nstress-ng: metrc: [13988] prctl              3834      1.00      0.64      0.36      3833.38        3841.36\nstress-ng: metrc: [13988] set               68070      1.00      0.14      0.82     68069.11       70513.07\nstress-ng: info:  [13988] skipped: 0\nstress-ng: info:  [13988] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [13988] failed: 0\nstress-ng: info:  [13988] metrics untrustworthy: 0\nstress-ng: info:  [13988] successful run completed in 1.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 6: prog 6 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 6 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 6
          }
        ],
        "exit_code": 1,
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
            "avg_ns_per_run": 855.0,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1710,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 192.0,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 384,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0178330450000033,
            "ops_per_sec": 21902885.85098937,
            "ops_total": 22293481.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [17790] setting to a 1 secs run per stressor\nstress-ng: info:  [17790] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [17790] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [17790] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [17790]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [17790] clone               748      1.01      0.16      0.68       743.26         890.47\nstress-ng: metrc: [17790] fork               2620      1.00      0.24      0.27      2618.46        5131.79\nstress-ng: metrc: [17790] futex            323802      2.00      0.11      1.13    161882.92      260344.78\nstress-ng: metrc: [17790] sem             1128210      1.00      0.21      0.63   1128159.70     1348525.32\nstress-ng: metrc: [17790] sem-sysv        4177642      1.00      0.18      0.77   4175160.38     4413084.47\nstress-ng: metrc: [17790] switch           492533      1.00      0.17      0.60    492445.30      639541.95\nstress-ng: metrc: [17790] vfork             18254      1.00      0.15      0.15     18253.70       59758.86\nstress-ng: metrc: [17790] yield          16149672      1.00      4.00      6.34  16095265.20     1561916.25\nstress-ng: info:  [17790] skipped: 0\nstress-ng: info:  [17790] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [17790] failed: 0\nstress-ng: info:  [17790] metrics untrustworthy: 0\nstress-ng: info:  [17790] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 721.0,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1442,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 227.5,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 455,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0165356269999961,
            "ops_per_sec": 24768503.26860221,
            "ops_total": 25178066.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [16358] setting to a 1 secs run per stressor\nstress-ng: info:  [16358] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [16358] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16358] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16358]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16358] clone               544      1.00      0.13      0.52       541.63         834.05\nstress-ng: metrc: [16358] fork               3975      1.00      0.32      0.48      3973.83        4964.31\nstress-ng: metrc: [16358] futex            347624      2.00      0.12      1.18    173795.20      267046.26\nstress-ng: metrc: [16358] sem             1478298      1.00      0.23      0.43   1478237.03     2248385.91\nstress-ng: metrc: [16358] sem-sysv        2613157      1.00      0.27      0.72   2611996.82     2636918.27\nstress-ng: metrc: [16358] switch           367508      1.00      0.07      0.46    367452.37      686774.23\nstress-ng: metrc: [16358] vfork             32790      1.00      0.26      0.34     32789.94       54625.87\nstress-ng: metrc: [16358] yield          20334170      1.01      4.06      6.32  20231567.60     1958834.38\nstress-ng: info:  [16358] skipped: 0\nstress-ng: info:  [16358] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [16358] failed: 0\nstress-ng: info:  [16358] metrics untrustworthy: 0\nstress-ng: info:  [16358] successful run completed in 1.01 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 9: prog 9 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 10: prog 10 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 9 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 9
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 10 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 10
          }
        ],
        "exit_code": 1,
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
            "avg_ns_per_run": 2018.5,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 4037,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 5969.5,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 11939,
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
            "duration_s": 1.0600503910000043,
            "ops_per_sec": 31690368.010061763,
            "ops_total": 33593387.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [21582] setting to a 1 secs run per stressor\nstress-ng: info:  [21582] dispatching hogs: 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 udp-flood\nstress-ng: info:  [21582] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21582] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21582]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21582] epoll            203685      1.01      0.21      1.56    202413.61      115062.88\nstress-ng: metrc: [21582] netdev          2137567      1.00      0.22      0.78   2137558.34     2136699.50\nstress-ng: metrc: [21582] sctp               2065      1.00      0.01      0.19      2064.42       10516.08\nstress-ng: metrc: [21582] sock               5166      1.00      0.07      1.88      5164.05        2645.89\nstress-ng: metrc: [21582] sockdiag       29486865      1.00      0.06      0.94  29476723.89    29526193.89\nstress-ng: metrc: [21582] sockfd           580177      1.00      0.18      1.44    580064.43      359511.86\nstress-ng: metrc: [21582] sockpair         318189      1.04      0.14      1.31    305200.72      219742.72\nstress-ng: metrc: [21582] udp-flood        859673      1.00      0.07      0.91    859640.41      881045.40\nstress-ng: info:  [21582] skipped: 0\nstress-ng: info:  [21582] passed: 8: epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) udp-flood (1)\nstress-ng: info:  [21582] failed: 0\nstress-ng: info:  [21582] metrics untrustworthy: 0\nstress-ng: info:  [21582] successful run completed in 1.05 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 2978.5,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 5957,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 11535.5,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 23071,
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
            "duration_s": 1.0510614410000017,
            "ops_per_sec": 35102296.174900725,
            "ops_total": 36894670.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [21631] setting to a 1 secs run per stressor\nstress-ng: info:  [21631] dispatching hogs: 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 udp-flood\nstress-ng: info:  [21631] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21631] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21631]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21631] epoll            202100      1.01      0.13      1.62    200570.58      115743.46\nstress-ng: metrc: [21631] netdev          2147486      1.00      0.32      0.68   2147451.18     2147140.31\nstress-ng: metrc: [21631] sctp              16808      1.00      0.10      1.01     16801.75       15075.85\nstress-ng: metrc: [21631] sock               5228      1.00      0.05      1.91      5226.61        2670.37\nstress-ng: metrc: [21631] sockdiag       32580851      1.00      0.08      0.92  32577650.95    32654617.78\nstress-ng: metrc: [21631] sockfd           564526      1.00      0.21      1.47    564347.59      336088.60\nstress-ng: metrc: [21631] sockpair         328089      1.04      0.17      1.28    316088.09      226196.67\nstress-ng: metrc: [21631] udp-flood       1049582      1.00      0.15      0.81   1049588.51     1084131.09\nstress-ng: info:  [21631] skipped: 0\nstress-ng: info:  [21631] passed: 8: epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) udp-flood (1)\nstress-ng: info:  [21631] failed: 0\nstress-ng: info:  [21631] metrics untrustworthy: 0\nstress-ng: info:  [21631] successful run completed in 1.04 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 13: prog 13 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 14: prog 14 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 15: prog 15 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 13 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 13
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 14 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 14
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 15 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 15
          }
        ],
        "exit_code": 1,
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
            "avg_ns_per_run": 220.54652855791872,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1575570,
            "run_time_ns_delta": 347486494,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 210.31022353672932,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 1575580,
            "run_time_ns_delta": 331360582,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 95.74571222752184,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1575585,
            "run_time_ns_delta": 150855508,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.349023216999996,
            "ops_per_sec": 393074.9437238799,
            "ops_total": 2102567.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.172757,\n        \"1000\" : 16.487092\n      },\n      \"latency_us\" : {\n        \"2\" : 31.227775,\n        \"4\" : 1.491648,\n        \"10\" : 9.520294,\n        \"20\" : 37.348290,\n        \"50\" : 2.922223,\n        \"100\" : 0.587527,\n        \"250\" : 0.234402,\n        \"500\" : 0.010000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 220.55853091018147,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1573818,
            "run_time_ns_delta": 347118986,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 211.91843708461153,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 1573828,
            "run_time_ns_delta": 333523170,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 96.00224356713832,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1573833,
            "run_time_ns_delta": 151091499,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.359133625999988,
            "ops_per_sec": 391696.3349851737,
            "ops_total": 2099153.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.033188,\n        \"1000\" : 12.337280\n      },\n      \"latency_us\" : {\n        \"2\" : 35.379152,\n        \"4\" : 1.642033,\n        \"10\" : 9.901219,\n        \"20\" : 36.212280,\n        \"50\" : 3.262323,\n        \"100\" : 1.037977,\n        \"250\" : 0.185775,\n        \"500\" : 0.010000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 18: prog 18 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 19: prog 19 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 20: prog 20 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 18 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 18
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 19 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 19
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 20 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 20
          }
        ],
        "exit_code": 1,
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
            "avg_ns_per_run": 61.46586206643097,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 136051,
            "run_time_ns_delta": 8362492,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": 69.8341384863124,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 621,
            "run_time_ns_delta": 43367,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 44.678067914744396,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 1286672,
            "run_time_ns_delta": 57486019,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 40.84433157990205,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 55130,
            "run_time_ns_delta": 2251748,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 65.39742063243385,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 79787,
            "run_time_ns_delta": 5217864,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1339775120000013,
            "ops_per_sec": 2173790.90318327,
            "ops_total": 2465030.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [6272] setting to a 1 secs run per stressor\nstress-ng: info:  [6272] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [6272] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [6291] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [6277] dentry: 107398 dentries allocated\nstress-ng: metrc: [6272] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6272]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6272] access            11080      1.00      0.27      1.64     11058.53        5817.33\nstress-ng: metrc: [6272] chdir                48      1.08      0.11      0.78        44.64          54.00\nstress-ng: metrc: [6272] chmod               130      1.00      0.00      0.03       129.70        4989.45\nstress-ng: metrc: [6272] chown               152      1.00      0.01      0.00       151.94       27681.66\nstress-ng: metrc: [6272] dentry            13132      1.02      0.03      0.42     12874.52       29305.63\nstress-ng: metrc: [6272] dir                8193      1.11      0.07      0.91      7381.65        8400.41\nstress-ng: metrc: [6272] dirmany            9857      1.00      0.00      0.23      9845.67       42694.10\nstress-ng: metrc: [6272] fallocate             1      1.00      0.00      0.00         1.00         228.36\nstress-ng: metrc: [6272] file-ioctl        75384      1.00      0.06      0.76     75300.20       92230.90\nstress-ng: metrc: [6272] filename           3702      1.01      0.02      0.70      3665.56        5089.04\nstress-ng: metrc: [6272] flock           1971736      1.00      0.41      0.54   1969879.45     2070470.53\nstress-ng: metrc: [6272] fpunch             1616      1.01      0.00      0.29      1596.21        5634.31\nstress-ng: metrc: [6272] fstat              2049      1.00      0.11      0.52      2048.76        3216.33\nstress-ng: metrc: [6272] getdent          210250      1.00      0.14      0.84    210245.84      215012.97\nstress-ng: metrc: [6272] hdd               23782      1.01      0.44      0.28     23549.43       33072.54\nstress-ng: metrc: [6272] inotify               2      1.05      0.00      0.00         1.90         814.33\nstress-ng: metrc: [6272] open              15360      1.01      0.02      0.21     15214.62       67447.70\nstress-ng: metrc: [6272] rename              444      1.01      0.00      0.02       439.81       25492.34\nstress-ng: metrc: [6272] touch             68948      1.01      0.03      1.96     68307.19       34648.77\nstress-ng: metrc: [6272] utime             49164      1.00      0.06      0.79     49161.97       58343.19\nstress-ng: info:  [6272] skipped: 0\nstress-ng: info:  [6272] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [6272] failed: 0\nstress-ng: info:  [6272] metrics untrustworthy: 0\nstress-ng: info:  [6272] successful run completed in 1.12 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "23": {
            "avg_ns_per_run": 62.419758160462045,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 138687,
            "run_time_ns_delta": 8656809,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": 69.28180574555404,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 731,
            "run_time_ns_delta": 50645,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 44.56019095621204,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 1257880,
            "run_time_ns_delta": 56051373,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 45.26644129230126,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 57386,
            "run_time_ns_delta": 2597660,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 53.5876677020686,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 75655,
            "run_time_ns_delta": 4054175,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.118739435000009,
            "ops_per_sec": 2475382.4826063965,
            "ops_total": 2769308.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [23201] setting to a 1 secs run per stressor\nstress-ng: info:  [23201] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [23201] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [23218] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [23206] dentry: 111451 dentries allocated\nstress-ng: metrc: [23201] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23201]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23201] access             9741      1.00      0.22      1.54      9732.46        5537.61\nstress-ng: metrc: [23201] chdir                53      1.08      0.10      0.85        49.01          55.73\nstress-ng: metrc: [23201] chmod               157      1.00      0.00      0.03       156.97        5210.75\nstress-ng: metrc: [23201] chown               181      1.00      0.01      0.00       180.99       33327.20\nstress-ng: metrc: [23201] dentry            14305      1.03      0.04      0.42     13869.85       30683.07\nstress-ng: metrc: [23201] dir                8192      1.10      0.05      0.85      7441.96        9162.98\nstress-ng: metrc: [23201] dirmany           11263      1.01      0.00      0.28     11103.92       40888.12\nstress-ng: metrc: [23201] fallocate             2      1.01      0.00      0.00         1.97         408.41\nstress-ng: metrc: [23201] file-ioctl        67254      1.00      0.07      0.73     67249.96       84842.43\nstress-ng: metrc: [23201] filename           3598      1.01      0.04      0.69      3554.74        4885.27\nstress-ng: metrc: [23201] flock           2285693      1.01      0.32      0.81   2258106.69     2034613.55\nstress-ng: metrc: [23201] fpunch             1400      1.01      0.01      0.23      1382.65        5789.05\nstress-ng: metrc: [23201] fstat              1785      1.00      0.02      0.49      1779.65        3481.35\nstress-ng: metrc: [23201] getdent          207775      1.00      0.09      0.90    207687.01      209939.69\nstress-ng: metrc: [23201] hdd               26644      1.01      0.43      0.31     26329.77       36261.14\nstress-ng: metrc: [23201] inotify               2      1.01      0.00      0.00         1.97         554.79\nstress-ng: metrc: [23201] open              18432      1.02      0.04      0.22     18135.77       70318.13\nstress-ng: metrc: [23201] rename              510      1.01      0.02      0.00       504.11       28823.33\nstress-ng: metrc: [23201] touch             68559      1.01      0.07      1.75     67753.22       37536.42\nstress-ng: metrc: [23201] utime             43762      1.01      0.08      0.70     43272.79       55783.73\nstress-ng: info:  [23201] skipped: 0\nstress-ng: info:  [23201] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [23201] failed: 0\nstress-ng: info:  [23201] metrics untrustworthy: 0\nstress-ng: info:  [23201] successful run completed in 1.11 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 23: prog 23 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 24: prog 24 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 25: prog 25 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 26: prog 26 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 27: prog 27 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 23 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 23
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 24 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 24
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 25 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 25
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 26 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 26
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 27 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 27
          }
        ],
        "exit_code": 1,
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
            "avg_ns_per_run": 445.8979297365119,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 15940,
            "run_time_ns_delta": 7107613,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 391.27048964050624,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 572277,
            "run_time_ns_delta": 223915102,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 459.27933151432467,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 2932,
            "run_time_ns_delta": 1346607,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1254744340000116,
            "ops_per_sec": 2559342.8984100497,
            "ops_total": 2880475.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [3160] setting to a 1 secs run per stressor\nstress-ng: info:  [3160] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [3160] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [3177] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [3165] dentry: 103578 dentries allocated\nstress-ng: metrc: [3160] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [3160]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [3160] access             9931      1.01      0.10      1.57      9796.04        5946.54\nstress-ng: metrc: [3160] chdir                35      1.09      0.03      0.69        32.23          48.46\nstress-ng: metrc: [3160] chmod               148      1.00      0.00      0.03       147.38        5213.65\nstress-ng: metrc: [3160] chown               203      1.00      0.01      0.00       202.13       35372.02\nstress-ng: metrc: [3160] dentry            10448      1.03      0.04      0.37     10123.99       25796.19\nstress-ng: metrc: [3160] dir                8192      1.10      0.06      0.91      7447.91        8412.27\nstress-ng: metrc: [3160] dirmany           10495      1.02      0.02      0.22     10272.56       43584.25\nstress-ng: metrc: [3160] fallocate             2      1.02      0.01      0.00         1.97         395.80\nstress-ng: metrc: [3160] file-ioctl        67901      1.00      0.11      0.67     67655.56       87489.34\nstress-ng: metrc: [3160] filename           3183      1.01      0.02      0.62      3142.58        4939.78\nstress-ng: metrc: [3160] flock           2417763      1.00      0.34      0.62   2408985.26     2531129.77\nstress-ng: metrc: [3160] fpunch             1429      1.02      0.00      0.31      1404.41        4666.98\nstress-ng: metrc: [3160] fstat              1877      1.00      0.13      0.39      1870.89        3559.51\nstress-ng: metrc: [3160] getdent          196421      1.00      0.08      0.89    196419.27      202800.50\nstress-ng: metrc: [3160] hdd               24953      1.01      0.42      0.31     24625.61       34149.59\nstress-ng: metrc: [3160] inotify               2      1.04      0.00      0.00         1.93         682.13\nstress-ng: metrc: [3160] open              17408      1.02      0.01      0.24     17111.87       70943.89\nstress-ng: metrc: [3160] rename              570      1.01      0.00      0.02       561.84       24585.92\nstress-ng: metrc: [3160] touch             61782      1.02      0.04      1.34     60855.71       44702.64\nstress-ng: metrc: [3160] utime             47732      1.01      0.04      0.74     47161.40       61135.85\nstress-ng: info:  [3160] skipped: 0\nstress-ng: info:  [3160] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [3160] failed: 0\nstress-ng: info:  [3160] metrics untrustworthy: 0\nstress-ng: info:  [3160] successful run completed in 1.11 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "30": {
            "avg_ns_per_run": 380.4719008264463,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 15730,
            "run_time_ns_delta": 5984823,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 390.48859453051944,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 575338,
            "run_time_ns_delta": 224662927,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 417.79843110504777,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 2932,
            "run_time_ns_delta": 1224985,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1154618740000046,
            "ops_per_sec": 2481586.385443765,
            "ops_total": 2768115.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [17777] setting to a 1 secs run per stressor\nstress-ng: info:  [17777] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [17777] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [17794] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [17782] dentry: 100892 dentries allocated\nstress-ng: metrc: [17777] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [17777]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [17777] access             9782      1.00      0.16      1.26      9771.10        6886.50\nstress-ng: metrc: [17777] chdir                38      1.07      0.12      0.68        35.40          47.75\nstress-ng: metrc: [17777] chmod               130      1.00      0.00      0.02       129.64        5180.93\nstress-ng: metrc: [17777] chown               149      1.01      0.00      0.01       147.37       21469.74\nstress-ng: metrc: [17777] dentry            12288      1.02      0.02      0.41     12041.88       28414.19\nstress-ng: metrc: [17777] dir                8192      1.10      0.06      0.86      7476.62        8847.34\nstress-ng: metrc: [17777] dirmany            9215      1.00      0.00      0.22      9186.13       42594.20\nstress-ng: metrc: [17777] fallocate             1      1.00      0.00      0.00         1.00         246.18\nstress-ng: metrc: [17777] file-ioctl        69178      1.00      0.06      0.67     69175.76       93612.31\nstress-ng: metrc: [17777] filename           3229      1.01      0.04      0.62      3194.66        4881.68\nstress-ng: metrc: [17777] flock           2306167      1.00      0.41      0.58   2301366.52     2330798.88\nstress-ng: metrc: [17777] fpunch              955      1.03      0.00      0.27       931.35        3599.73\nstress-ng: metrc: [17777] fstat              1879      1.00      0.09      0.50      1875.92        3191.98\nstress-ng: metrc: [17777] getdent          196679      1.00      0.08      0.91    196678.25      198776.29\nstress-ng: metrc: [17777] hdd               28672      1.02      0.33      0.28     27988.35       46748.16\nstress-ng: metrc: [17777] inotify               2      1.05      0.00      0.00         1.90         612.00\nstress-ng: metrc: [17777] open              17209      1.03      0.02      0.24     16737.72       66146.99\nstress-ng: metrc: [17777] rename              435      1.01      0.02      0.00       430.71       25582.22\nstress-ng: metrc: [17777] touch             57282      1.03      0.04      1.36     55822.33       41153.43\nstress-ng: metrc: [17777] utime             46633      1.00      0.03      0.74     46579.01       60184.12\nstress-ng: info:  [17777] skipped: 0\nstress-ng: info:  [17777] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [17777] failed: 0\nstress-ng: info:  [17777] metrics untrustworthy: 0\nstress-ng: info:  [17777] successful run completed in 1.10 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 30: prog 30 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 31: prog 31 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 32: prog 32 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 30 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 30
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 31 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 31
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 32 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 32
          }
        ],
        "exit_code": 1,
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
            "avg_ns_per_run": 59.576983652163506,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 9360260,
            "run_time_ns_delta": 557656057,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 56.68692208475811,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 9360261,
            "run_time_ns_delta": 530604386,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0143961439999885,
            "ops_per_sec": 617074.5065450555,
            "ops_total": 625958.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [28039] setting to a 1 secs run per stressor\nstress-ng: info:  [28039] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [28039] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [28039] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [28039]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [28039] cap              458364      1.00      0.06      0.94    458363.89      458388.75\nstress-ng: metrc: [28039] eventfd          125878      1.00      0.07      0.77    125812.70      150624.02\nstress-ng: metrc: [28039] get                 895      1.00      0.03      0.15       894.69        4953.81\nstress-ng: metrc: [28039] prctl              2716      1.00      0.68      0.30      2715.22        2781.20\nstress-ng: metrc: [28039] set               38105      1.00      0.07      0.91     38104.52       38733.41\nstress-ng: info:  [28039] skipped: 0\nstress-ng: info:  [28039] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [28039] failed: 0\nstress-ng: info:  [28039] metrics untrustworthy: 0\nstress-ng: info:  [28039] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 59.69163978543608,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 9274439,
            "run_time_ns_delta": 553606472,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 57.79010193607377,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 9274440,
            "run_time_ns_delta": 535970833,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0146117830000208,
            "ops_per_sec": 616011.9668154763,
            "ops_total": 625013.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [841] setting to a 1 secs run per stressor\nstress-ng: info:  [841] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [841] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [841] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [841]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [841] cap              459029      1.00      0.08      0.92    459024.84      458930.33\nstress-ng: metrc: [841] eventfd          124906      1.00      0.05      0.79    124879.59      149640.71\nstress-ng: metrc: [841] get                 887      1.00      0.03      0.15       886.09        5077.39\nstress-ng: metrc: [841] prctl              2628      1.00      0.67      0.30      2627.04        2717.89\nstress-ng: metrc: [841] set               37563      1.00      0.06      0.92     37562.73       38323.22\nstress-ng: info:  [841] skipped: 0\nstress-ng: info:  [841] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [841] failed: 0\nstress-ng: info:  [841] metrics untrustworthy: 0\nstress-ng: info:  [841] successful run completed in 1.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 35: prog 35 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 36: prog 36 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 35 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 35
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 36 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 36
          }
        ],
        "exit_code": 1,
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
            "avg_ns_per_run": 883.3757763975156,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 322,
            "run_time_ns_delta": 284447,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4600.490683229814,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 161,
            "run_time_ns_delta": 740679,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 4720.378881987577,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 161,
            "run_time_ns_delta": 759981,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0005328729999974,
            "ops_per_sec": 321.8285062783748,
            "ops_total": 322.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 929.6721854304636,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 302,
            "run_time_ns_delta": 280761,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4266.543046357616,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 151,
            "run_time_ns_delta": 644248,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 4390.086092715232,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 151,
            "run_time_ns_delta": 662903,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0024930149999989,
            "ops_per_sec": 301.24898176971374,
            "ops_total": 302.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 39: prog 39 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 40: prog 40 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 41: prog 41 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 39 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 39
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 40 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 40
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 41 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 41
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 0,
          "not_applied": 3,
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
            "avg_ns_per_run": 866.8392272429601,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 3054,
            "run_time_ns_delta": 2647327,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0021491560000015,
            "ops_per_sec": 304.3459131546677,
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
            "avg_ns_per_run": 861.1329365079365,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 3024,
            "run_time_ns_delta": 2604066,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0000856020000128,
            "ops_per_sec": 301.97415040877286,
            "ops_total": 302.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 44: prog 44 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 44 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 44
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 0,
          "not_applied": 1,
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
            "avg_ns_per_run": 190.65665219891483,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 13172975,
            "run_time_ns_delta": 2511515313,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 84.18314159809015,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 573447,
            "run_time_ns_delta": 48274570,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 195.22561738557786,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 30370,
            "run_time_ns_delta": 5929002,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0190718350000054,
            "ops_per_sec": 19152677.298749894,
            "ops_total": 19517954.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [23216] setting to a 1 secs run per stressor\nstress-ng: info:  [23216] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [23216] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [23216] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23216]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23216] clone               548      1.00      0.16      0.63       545.95         698.77\nstress-ng: metrc: [23216] fork               3420      1.00      0.31      0.38      3408.68        4972.04\nstress-ng: metrc: [23216] futex            351264      2.00      0.04      1.10    175618.79      308482.15\nstress-ng: metrc: [23216] sem             3831297      1.00      0.24      0.70   3831146.29     4045284.46\nstress-ng: metrc: [23216] sem-sysv        2630883      1.00      0.24      0.75   2630031.47     2657946.21\nstress-ng: metrc: [23216] switch           314275      1.00      0.08      0.79    314201.74      363111.29\nstress-ng: metrc: [23216] vfork             26317      1.00      0.23      0.29     26316.66       50568.48\nstress-ng: metrc: [23216] yield          12359950      1.01      2.88      7.17  12281019.28     1230496.16\nstress-ng: info:  [23216] skipped: 0\nstress-ng: info:  [23216] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [23216] failed: 0\nstress-ng: info:  [23216] metrics untrustworthy: 0\nstress-ng: info:  [23216] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 177.0333347418801,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 7194176,
            "run_time_ns_delta": 1273608968,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 68.47520040859641,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 931971,
            "run_time_ns_delta": 63816901,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 219.05064343430985,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 30073,
            "run_time_ns_delta": 6587510,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.01818981400001,
            "ops_per_sec": 33442593.445547536,
            "ops_total": 34050908.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [10904] setting to a 1 secs run per stressor\nstress-ng: info:  [10904] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [10904] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10904] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10904]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10904] clone               564      1.01      0.16      0.63       561.02         718.80\nstress-ng: metrc: [10904] fork               3250      1.00      0.29      0.40      3249.72        4757.30\nstress-ng: metrc: [10904] futex            414134      2.00      0.07      1.26    207049.75      310785.42\nstress-ng: metrc: [10904] sem             5935739      1.00      0.49      0.92   5935405.03     4184597.80\nstress-ng: metrc: [10904] sem-sysv        2683954      1.00      0.21      0.78   2683055.24     2694697.76\nstress-ng: metrc: [10904] switch           501638      1.00      0.11      0.88    501531.70      504717.79\nstress-ng: metrc: [10904] vfork             26168      1.00      0.20      0.34     26167.70       48098.79\nstress-ng: metrc: [10904] yield          24485461      1.01      3.21      5.80  24345822.23     2715526.03\nstress-ng: info:  [10904] skipped: 0\nstress-ng: info:  [10904] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [10904] failed: 0\nstress-ng: info:  [10904] metrics untrustworthy: 0\nstress-ng: info:  [10904] successful run completed in 1.01 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 47: prog 47 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 48: prog 48 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 49: prog 49 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 47 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 47
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 48 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 48
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 49 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 49
          }
        ],
        "exit_code": 1,
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
      "baseline": null,
      "error": "network wrk load failed via /usr/bin/wrk -t2 -c10 -d1s http://198.18.0.2:18080/: unable to connect to 198.18.0.2:18080 Connection timed out\n--- felix stderr tail ---\n_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: failed to pin map: File exists\n--- felix stdout tail ---\n2026-05-05 00:23:03.575 [WARNING][8889] felix/winutils.go 154: error creating inClusterConfig, falling back to default config: unable to load in-cluster configuration, KUBERNETES_SERVICE_HOST and KUBERNETES_SERVICE_PORT must be defined\n2026-05-05 00:23:03.577 [WARNING][8889] felix/daemon.go 378: BPF conntrack mode Auto,BPFProgram is not supported and will be deprecated soon. Falling back to userspace cleaner.\n2026-05-05 00:23:03.579 [WARNING][8889] felix/int_dataplane.go 1456: Failed to auto-detect host MTU - no interfaces matched the MTU interface pattern. To use auto-MTU, set mtuIfacePattern to match your host's interfaces\n2026-05-05 00:23:03.636 [WARNING][8889] felix/feature_detect_linux.go 383: Iptables backend specified does not match the detected backend, using specified backend detectedBackend=\"legacy\" specifiedBackend=\"nft\"\n2026-05-05 00:23:04.830 [WARNING][8889] felix/int_dataplane.go 1034: Failed to detach connect-time load balancer. Ignoring. error=error querying cgroup 11 : no such file or directory\nerror querying cgroup 15 : no such file or directory\nerror querying cgroup 20 : no such file or directory\nerror querying cgroup 10 : no such file or directory\nerror querying cgroup 14 : no such file or directory\nerror querying cgroup 19 : no such file or directory\n2026-05-05 00:23:05.098 [WARNING][8889] felix/int_dataplane.go 1456: Failed to auto-detect host MTU - no interfaces matched the MTU interface pattern. To use auto-MTU, set mtuIfacePattern to match your host's interfaces",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "calico",
      "selected_workload": "network",
      "status": "error"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline": {
        "bpf": {
          "181": {
            "avg_ns_per_run": null,
            "bytes_jited": 3721,
            "bytes_xlated": 6232,
            "id": 181,
            "name": "perf_unwind_stop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "182": {
            "avg_ns_per_run": null,
            "bytes_jited": 22575,
            "bytes_xlated": 37232,
            "id": 182,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "183": {
            "avg_ns_per_run": null,
            "bytes_jited": 18290,
            "bytes_xlated": 28048,
            "id": 183,
            "name": "perf_unwind_hotspot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "184": {
            "avg_ns_per_run": null,
            "bytes_jited": 17737,
            "bytes_xlated": 29144,
            "id": 184,
            "name": "perf_unwind_perl",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "185": {
            "avg_ns_per_run": null,
            "bytes_jited": 15178,
            "bytes_xlated": 25032,
            "id": 185,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 19909,
            "bytes_xlated": 33264,
            "id": 186,
            "name": "perf_unwind_python",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "187": {
            "avg_ns_per_run": null,
            "bytes_jited": 16540,
            "bytes_xlated": 28000,
            "id": 187,
            "name": "perf_unwind_ruby",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "188": {
            "avg_ns_per_run": null,
            "bytes_jited": 20050,
            "bytes_xlated": 33712,
            "id": 188,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 22565,
            "bytes_xlated": 34248,
            "id": 189,
            "name": "perf_unwind_dotnet",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "190": {
            "avg_ns_per_run": null,
            "bytes_jited": 1580,
            "bytes_xlated": 2496,
            "id": 190,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "191": {
            "avg_ns_per_run": null,
            "bytes_jited": 696,
            "bytes_xlated": 1088,
            "id": 191,
            "name": "perf_unwind_beam",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "192": {
            "avg_ns_per_run": 3242.0,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 192,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 9726,
            "type": "tracepoint"
          },
          "193": {
            "avg_ns_per_run": 958.703125,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 193,
            "name": "native_tracer_entry",
            "run_cnt_delta": 1600,
            "run_time_ns_delta": 1533925,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.018262729000014,
            "ops_per_sec": 2983.3033478865427,
            "ops_total": 14971.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [9388] setting to a 5 secs run per stressor\nstress-ng: info:  [9388] dispatching hogs: 1 cpu\nstress-ng: info:  [9388] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9388] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9388]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9388] cpu               14971      5.00      5.00      0.00      2994.04        2994.28\nstress-ng: info:  [9388] skipped: 0\nstress-ng: info:  [9388] passed: 1: cpu (1)\nstress-ng: info:  [9388] failed: 0\nstress-ng: info:  [9388] metrics untrustworthy: 0\nstress-ng: info:  [9388] successful run completed in 5.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "181": {
            "avg_ns_per_run": null,
            "bytes_jited": 3721,
            "bytes_xlated": 6232,
            "id": 181,
            "name": "perf_unwind_stop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "182": {
            "avg_ns_per_run": null,
            "bytes_jited": 22575,
            "bytes_xlated": 37232,
            "id": 182,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "183": {
            "avg_ns_per_run": null,
            "bytes_jited": 18290,
            "bytes_xlated": 28048,
            "id": 183,
            "name": "perf_unwind_hotspot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "184": {
            "avg_ns_per_run": null,
            "bytes_jited": 17737,
            "bytes_xlated": 29144,
            "id": 184,
            "name": "perf_unwind_perl",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "185": {
            "avg_ns_per_run": null,
            "bytes_jited": 15178,
            "bytes_xlated": 25032,
            "id": 185,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 19909,
            "bytes_xlated": 33264,
            "id": 186,
            "name": "perf_unwind_python",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "187": {
            "avg_ns_per_run": null,
            "bytes_jited": 16540,
            "bytes_xlated": 28000,
            "id": 187,
            "name": "perf_unwind_ruby",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "188": {
            "avg_ns_per_run": null,
            "bytes_jited": 20050,
            "bytes_xlated": 33712,
            "id": 188,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 22565,
            "bytes_xlated": 34248,
            "id": 189,
            "name": "perf_unwind_dotnet",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "190": {
            "avg_ns_per_run": null,
            "bytes_jited": 1580,
            "bytes_xlated": 2496,
            "id": 190,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "191": {
            "avg_ns_per_run": null,
            "bytes_jited": 696,
            "bytes_xlated": 1088,
            "id": 191,
            "name": "perf_unwind_beam",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "192": {
            "avg_ns_per_run": 3563.6666666666665,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 192,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 10691,
            "type": "tracepoint"
          },
          "193": {
            "avg_ns_per_run": 932.7617574257425,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 193,
            "name": "native_tracer_entry",
            "run_cnt_delta": 1616,
            "run_time_ns_delta": 1507343,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.017832381999995,
            "ops_per_sec": 2930.5482687604085,
            "ops_total": 14705.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [9413] setting to a 5 secs run per stressor\nstress-ng: info:  [9413] dispatching hogs: 1 cpu\nstress-ng: info:  [9413] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9413] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9413]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9413] cpu               14705      5.00      5.00      0.00      2940.54        2940.65\nstress-ng: info:  [9413] skipped: 0\nstress-ng: info:  [9413] passed: 1: cpu (1)\nstress-ng: info:  [9413] failed: 0\nstress-ng: info:  [9413] metrics untrustworthy: 0\nstress-ng: info:  [9413] successful run completed in 5.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 181: prog 181 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 182: prog 182 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 183: prog 183 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 184: prog 184 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 185: prog 185 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 186: prog 186 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 187: prog 187 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 188: prog 188 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 189: prog 189 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 190: prog 190 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 191: prog 191 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 192: prog 192 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 193: prog 193 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 181 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 181
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 182 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 182
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 183 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 183
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 184 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 184
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 185 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 185
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 186 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 186
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 187 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 187
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 188 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 188
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 189 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 189
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 190 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 190
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 191 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 191
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 192 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 192
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 193 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 193
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
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 201,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "202": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 202,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 298,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 299,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 300,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 301,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 303,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 305,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 306,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 307,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "308": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 308,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "309": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 309,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "310": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 310,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "311": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 311,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "312": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 312,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 313,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "314": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 314,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "315": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 315,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "316": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 316,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 317,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "319": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 319,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "320": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 320,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "321": {
            "avg_ns_per_run": 590.3258426966293,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 321,
            "name": "cil_from_netdev",
            "run_cnt_delta": 267,
            "run_time_ns_delta": 157617,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0030627859999868,
            "ops_per_sec": 119.63358792178497,
            "ops_total": 120.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    49.20ms   11.88ms  60.13ms   95.00%\n    Req/Sec    60.20     41.50   110.00     90.00%\n  120 requests in 1.00s, 18.97KB read\nRequests/sec:    119.93\nTransfer/sec:     18.96KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 201,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "202": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 202,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 298,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 299,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 300,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 301,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 303,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 305,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 306,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 307,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "308": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 308,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "309": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 309,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "310": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 310,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "311": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 311,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "312": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 312,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 313,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "314": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 314,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "315": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 315,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "316": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 316,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 317,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "319": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 319,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "320": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 320,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "321": {
            "avg_ns_per_run": 606.7516129032258,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 321,
            "name": "cil_from_netdev",
            "run_cnt_delta": 310,
            "run_time_ns_delta": 188093,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0050294619999818,
            "ops_per_sec": 139.2993989662788,
            "ops_total": 140.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    48.52ms   11.09ms  60.49ms   86.43%\n    Req/Sec    70.10     30.88   101.00     90.00%\n  140 requests in 1.00s, 22.13KB read\nRequests/sec:    139.73\nTransfer/sec:     22.09KB"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 201: prog 201 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 202: prog 202 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 298: prog 298 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 299: prog 299 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 300: prog 300 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 301: prog 301 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 303: prog 303 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 305: prog 305 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 306: prog 306 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 307: prog 307 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 308: prog 308 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 309: prog 309 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 310: prog 310 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 311: prog 311 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 312: prog 312 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 313: prog 313 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 314: prog 314 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 315: prog 315 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 316: prog 316 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 317: prog 317 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 319: prog 319 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 320: prog 320 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 321: prog 321 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 201 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 201
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 202 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 202
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 298 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 298
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 299 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 299
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 300 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 300
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 301 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 301
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 303 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 303
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 305 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 305
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 306 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 306
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 307 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 307
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 308 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 308
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 309 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 309
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 310 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 310
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 311 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 311
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 312 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 312
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 313 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 313
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 314 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 314
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 315 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 315
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 316 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 316
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 317 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 317
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 319 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 319
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 320 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 320
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 321 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 321
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 0,
          "not_applied": 23,
          "requested": 23
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
          "336": {
            "avg_ns_per_run": 1536.3502824858756,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 336,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1062,
            "run_time_ns_delta": 1631604,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": 1969.1992882562276,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 338,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1124,
            "run_time_ns_delta": 2213380,
            "type": "kprobe"
          },
          "339": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 339,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "340": {
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 340,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "341": {
            "avg_ns_per_run": 6089.5,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 341,
            "name": "event_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 12179,
            "type": "tracepoint"
          },
          "342": {
            "avg_ns_per_run": 727.5,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 342,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1455,
            "type": "kprobe"
          },
          "343": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 343,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "346": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 346,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 348,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 351,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 352,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "353": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 353,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 355,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 357,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 359,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 361,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "362": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 362,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "363": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 363,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 365,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 367,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "368": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 368,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "369": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 369,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 370,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 372,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "373": {
            "avg_ns_per_run": 386.2067711901979,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 373,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 124055,
            "run_time_ns_delta": 47910881,
            "type": "kprobe"
          },
          "374": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 374,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "375": {
            "avg_ns_per_run": 51.32180081415501,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 375,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 124055,
            "run_time_ns_delta": 6366726,
            "type": "kprobe"
          },
          "376": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 376,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "377": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 377,
            "name": "generic_retkprobe_actions",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 379,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "avg_ns_per_run": 1148.9719667421068,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 380,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 124602,
            "run_time_ns_delta": 143164205,
            "type": "kprobe"
          },
          "381": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 381,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "382": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 382,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "383": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 383,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "384": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 384,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 385,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "386": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 386,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 388,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 390,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 392,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "393": {
            "avg_ns_per_run": 391.0023940993914,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 393,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 124055,
            "run_time_ns_delta": 48505802,
            "type": "kprobe"
          },
          "394": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 394,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "395": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 395,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "396": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 396,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "397": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 397,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 54.779106041675064,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 399,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 124055,
            "run_time_ns_delta": 6795622,
            "type": "kprobe"
          },
          "400": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 400,
            "name": "generic_retkprobe_actions",
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 402,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "403": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 403,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 404,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 406,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "407": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 407,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": 1187.8544244875684,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 409,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 124602,
            "run_time_ns_delta": 148009037,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 411,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 412,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": 454.02069279499864,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 413,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 180111,
            "run_time_ns_delta": 81774121,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 416,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 420,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 422,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "423": {
            "avg_ns_per_run": 953.5363705762176,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 423,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 364168,
            "run_time_ns_delta": 347247433,
            "type": "kprobe"
          },
          "424": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 424,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 425,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "426": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 426,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "427": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 427,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 429,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 432,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 434,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 435,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": 8504.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 436,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 8504,
            "type": "kprobe"
          },
          "437": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 437,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "438": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 438,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "439": {
            "avg_ns_per_run": 189.42340819916865,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 439,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 360378,
            "run_time_ns_delta": 68264029,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 443,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "444": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 444,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 447,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "448": {
            "avg_ns_per_run": 536.3678487971222,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 448,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 641046,
            "run_time_ns_delta": 343836464,
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
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 452,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "453": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 453,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "454": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 454,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "455": {
            "avg_ns_per_run": 37.25303020376073,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 455,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 641046,
            "run_time_ns_delta": 23880906,
            "type": "kprobe"
          },
          "456": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 456,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 458,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "459": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 459,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "460": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 460,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "461": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 461,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "avg_ns_per_run": 5088.116947852761,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 462,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2608,
            "run_time_ns_delta": 13269809,
            "type": "kprobe"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 463,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "464": {
            "avg_ns_per_run": 61.956288343558285,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 464,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2608,
            "run_time_ns_delta": 161582,
            "type": "kprobe"
          },
          "465": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 465,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "466": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 466,
            "name": "generic_retkprobe_actions",
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
            "avg_ns_per_run": 7348.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 468,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 44088,
            "type": "kprobe"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 469,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 471,
            "name": "generic_kprobe_output",
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
          },
          "473": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 473,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "474": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 474,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "475": {
            "avg_ns_per_run": 558.8333333333334,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 475,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 3353,
            "type": "kprobe"
          },
          "476": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 476,
            "name": "generic_retkprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 478,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "479": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 479,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 481,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "482": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 482,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 484,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "485": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 485,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "486": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 486,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "487": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 487,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "488": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 488,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "489": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 489,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 492,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "493": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 493,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "494": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 494,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 496,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "497": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 497,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 498,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "499": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 499,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "500": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 500,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "501": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 501,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "502": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 502,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "503": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 503,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "504": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 504,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "505": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 505,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "506": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 506,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "507": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 507,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 509,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "510": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 510,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 511,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 512,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "513": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 513,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 514,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "515": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 515,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "516": {
            "avg_ns_per_run": 5264.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 516,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 10528,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 517,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 518,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "519": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 519,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 520,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 521,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 522,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 523,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 524,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 525,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "526": {
            "avg_ns_per_run": 1018.9743718386031,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 526,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 5828120,
            "run_time_ns_delta": 5938704916,
            "type": "tracepoint"
          },
          "527": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 527,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 528,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "529": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 529,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "530": {
            "avg_ns_per_run": 3802.5,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 530,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 7605,
            "type": "raw_tracepoint"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 531,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "532": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 532,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 533,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "534": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 534,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "535": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 535,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "536": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 536,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": 506.71224379719524,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 538,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 25956,
            "run_time_ns_delta": 13152223,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 539,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "540": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 540,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "541": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 541,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "542": {
            "avg_ns_per_run": 3146.6898263027297,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 542,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 806,
            "run_time_ns_delta": 2536232,
            "type": "kprobe"
          },
          "543": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 543,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 545,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 547,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 549,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "550": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 550,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "551": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 551,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "552": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 552,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "553": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 553,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "554": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 554,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "555": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 555,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "556": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 556,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "557": {
            "avg_ns_per_run": 402.1560920559429,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 557,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 124055,
            "run_time_ns_delta": 49889474,
            "type": "kprobe"
          },
          "558": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 558,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "559": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 559,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "560": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 560,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "561": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 561,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "562": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 562,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "563": {
            "avg_ns_per_run": 59.5934303333199,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 563,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 124055,
            "run_time_ns_delta": 7392863,
            "type": "kprobe"
          },
          "564": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 564,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "565": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 565,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "566": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 566,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "567": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 567,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "568": {
            "avg_ns_per_run": 1188.5312113770244,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 568,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 124602,
            "run_time_ns_delta": 148093366,
            "type": "kprobe"
          },
          "569": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 569,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "570": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 570,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "571": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 571,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "572": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 572,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "573": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 573,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "574": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 574,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "575": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 575,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "576": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 576,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "577": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 577,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "578": {
            "avg_ns_per_run": 1332.5294117647059,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 578,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 17,
            "run_time_ns_delta": 22653,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 579,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 580,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 581,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 582,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 583,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "584": {
            "avg_ns_per_run": 1465.6,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 584,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 5,
            "run_time_ns_delta": 7328,
            "type": "kprobe"
          },
          "585": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 585,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "586": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 586,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 587,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "588": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 588,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "589": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 589,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "590": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 590,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "591": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 591,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "592": {
            "avg_ns_per_run": 4233.5,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 592,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8467,
            "type": "kprobe"
          },
          "593": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 593,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "594": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 594,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "595": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 595,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "596": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 596,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "597": {
            "avg_ns_per_run": 2579.0,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 597,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 5158,
            "type": "kprobe"
          },
          "598": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 598,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "599": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 599,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "600": {
            "avg_ns_per_run": 6057.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 600,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 18171,
            "type": "kprobe"
          },
          "601": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 601,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "602": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 602,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 603,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 604,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "605": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 605,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "606": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 606,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "607": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 607,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "608": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 608,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "609": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 609,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "610": {
            "avg_ns_per_run": 1901.8,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 610,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 5,
            "run_time_ns_delta": 9509,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 611,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "612": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 612,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "613": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 613,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "614": {
            "avg_ns_per_run": 1195.0549799155424,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 614,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 145635,
            "run_time_ns_delta": 174041832,
            "type": "kprobe"
          },
          "615": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 615,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "616": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 616,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "617": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 617,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "618": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 618,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "619": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 619,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "620": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 620,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 621,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "622": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 622,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "623": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 623,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 624,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 625,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1381231980000166,
            "ops_per_sec": 20635977.758182604,
            "ops_total": 23486285.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [11692] setting to a 1 secs run per stressor\nstress-ng: info:  [11692] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set, 1 aio, 1 aiol, 1 hdd, 1 io, 1 iomix, 1 io-uring, 1 sync-file, 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 udp-flood\nstress-ng: info:  [11692] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [11701] io: this is a legacy I/O sync stressor, consider using iomix instead\nstress-ng: metrc: [11692] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11692]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11692] cap               91101      1.00      0.01      0.87     91101.20      103100.80\nstress-ng: metrc: [11692] eventfd           55135      1.00      0.05      0.86     55120.44       60414.63\nstress-ng: metrc: [11692] get                 522      1.00      0.01      0.22       521.45        2195.53\nstress-ng: metrc: [11692] prctl              1011      1.00      0.60      0.15      1010.75        1347.04\nstress-ng: metrc: [11692] set                6106      1.00      0.02      0.61      6105.95        9654.84\nstress-ng: metrc: [11692] aio                5541      1.00      0.02      0.07      5540.27       58838.52\nstress-ng: metrc: [11692] aiol               1267      1.12      0.00      0.20      1133.84        6447.61\nstress-ng: metrc: [11692] hdd               20480      1.00      0.38      0.36     20472.88       27758.76\nstress-ng: metrc: [11692] io                   42      1.02      0.00      0.03        41.26        1491.58\nstress-ng: metrc: [11692] iomix              1102      1.02      0.01      0.26      1081.98        4012.00\nstress-ng: metrc: [11692] io-uring           8922      1.02      0.00      0.44      8734.85       20194.75\nstress-ng: metrc: [11692] sync-file            13      1.00      0.00      0.61        12.96          21.44\nstress-ng: metrc: [11692] epoll             24973      1.04      0.03      1.09     24059.95       22222.36\nstress-ng: metrc: [11692] netdev            35957      1.00      0.02      0.86     35957.10       40954.24\nstress-ng: metrc: [11692] sctp               7088      1.00      0.01      0.14      7086.73       46267.83\nstress-ng: metrc: [11692] sock                285      1.00      0.00      0.86       284.22         330.09\nstress-ng: metrc: [11692] sockdiag       22914154      1.00      0.05      0.92  22909402.04    23615608.42\nstress-ng: metrc: [11692] sockfd            80365      1.00      0.04      0.85     80286.02       90493.69\nstress-ng: metrc: [11692] sockpair         107816      1.05      0.05      1.28    102452.39       80952.48\nstress-ng: metrc: [11692] udp-flood        124405      1.00      0.01      0.96    124402.39      127977.23\nstress-ng: info:  [11692] skipped: 0\nstress-ng: info:  [11692] passed: 20: cap (1) eventfd (1) get (1) prctl (1) set (1) aio (1) aiol (1) hdd (1) io (1) iomix (1) io-uring (1) sync-file (1) epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) udp-flood (1)\nstress-ng: info:  [11692] failed: 0\nstress-ng: info:  [11692] metrics untrustworthy: 0\nstress-ng: info:  [11692] successful run completed in 1.12 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "336": {
            "avg_ns_per_run": 1615.9856596558318,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 336,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1046,
            "run_time_ns_delta": 1690321,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": 1929.2117117117118,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 338,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1110,
            "run_time_ns_delta": 2141425,
            "type": "kprobe"
          },
          "339": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 339,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "340": {
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 340,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "341": {
            "avg_ns_per_run": 6932.5,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 341,
            "name": "event_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 13865,
            "type": "tracepoint"
          },
          "342": {
            "avg_ns_per_run": 678.0,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 342,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1356,
            "type": "kprobe"
          },
          "343": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 343,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "346": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 346,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 348,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 351,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 352,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "353": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 353,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 355,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 357,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 359,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 361,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "362": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 362,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "363": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 363,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 365,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 367,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "368": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 368,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "369": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 369,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 370,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 372,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "373": {
            "avg_ns_per_run": 450.88617138653916,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 373,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 97884,
            "run_time_ns_delta": 44134542,
            "type": "kprobe"
          },
          "374": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 374,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "375": {
            "avg_ns_per_run": 86.74178619590536,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 375,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 97884,
            "run_time_ns_delta": 8490633,
            "type": "kprobe"
          },
          "376": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 376,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "377": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 377,
            "name": "generic_retkprobe_actions",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 379,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "avg_ns_per_run": 1325.128497262792,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 380,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 99006,
            "run_time_ns_delta": 131195672,
            "type": "kprobe"
          },
          "381": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 381,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "382": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 382,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "383": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 383,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "384": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 384,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 385,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "386": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 386,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 388,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 390,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 392,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "393": {
            "avg_ns_per_run": 468.51327081034697,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 393,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 97884,
            "run_time_ns_delta": 45859953,
            "type": "kprobe"
          },
          "394": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 394,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "395": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 395,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "396": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 396,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "397": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 397,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 111.66390829961996,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 399,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 97884,
            "run_time_ns_delta": 10930110,
            "type": "kprobe"
          },
          "400": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 400,
            "name": "generic_retkprobe_actions",
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 402,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "403": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 403,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 404,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 406,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "407": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 407,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": 1375.9241359109549,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 409,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 99006,
            "run_time_ns_delta": 136224745,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 411,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 412,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": 514.6700205969593,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 413,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 198573,
            "run_time_ns_delta": 102199570,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 416,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 420,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 422,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "423": {
            "avg_ns_per_run": 868.2120842087811,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 423,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 313649,
            "run_time_ns_delta": 272313852,
            "type": "kprobe"
          },
          "424": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 424,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 425,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "426": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 426,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "427": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 427,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 429,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 432,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 434,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 435,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 436,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "437": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 437,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "438": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 438,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "439": {
            "avg_ns_per_run": 185.28975399054139,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 439,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 326898,
            "run_time_ns_delta": 60570850,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 443,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "444": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 444,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 447,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "448": {
            "avg_ns_per_run": 546.152374124804,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 448,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 591439,
            "run_time_ns_delta": 323015814,
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
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 452,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "453": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 453,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "454": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 454,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "455": {
            "avg_ns_per_run": 37.58816378358546,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 455,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 591439,
            "run_time_ns_delta": 22231106,
            "type": "kprobe"
          },
          "456": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 456,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 458,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "459": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 459,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "460": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 460,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "461": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 461,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "avg_ns_per_run": 7148.2987361164305,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 462,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2611,
            "run_time_ns_delta": 18664208,
            "type": "kprobe"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 463,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "464": {
            "avg_ns_per_run": 81.38184603600153,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 464,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2611,
            "run_time_ns_delta": 212488,
            "type": "kprobe"
          },
          "465": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 465,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "466": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 466,
            "name": "generic_retkprobe_actions",
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
            "avg_ns_per_run": 7418.5,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 468,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 29674,
            "type": "kprobe"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 469,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 471,
            "name": "generic_kprobe_output",
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
          },
          "473": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 473,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "474": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 474,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "475": {
            "avg_ns_per_run": 514.25,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 475,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 2057,
            "type": "kprobe"
          },
          "476": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 476,
            "name": "generic_retkprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 478,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "479": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 479,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 481,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "482": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 482,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 484,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "485": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 485,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "486": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 486,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "487": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 487,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "488": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 488,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "489": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 489,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 492,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "493": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 493,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "494": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 494,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 496,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "497": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 497,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 498,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "499": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 499,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "500": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 500,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "501": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 501,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "502": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 502,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "503": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 503,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "504": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 504,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "505": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 505,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "506": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 506,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "507": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 507,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 509,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "510": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 510,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 511,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 512,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "513": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 513,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 514,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "515": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 515,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "516": {
            "avg_ns_per_run": 5984.5,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 516,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 11969,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 517,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 518,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "519": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 519,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 520,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 521,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 522,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 523,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 524,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 525,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "526": {
            "avg_ns_per_run": 1018.7801254060806,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 526,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 6097312,
            "run_time_ns_delta": 6211820284,
            "type": "tracepoint"
          },
          "527": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 527,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 528,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "529": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 529,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "530": {
            "avg_ns_per_run": 4108.5,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 530,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8217,
            "type": "raw_tracepoint"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 531,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "532": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 532,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 533,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "534": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 534,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "535": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 535,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "536": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 536,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": 635.5634141317037,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 538,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 14563,
            "run_time_ns_delta": 9255710,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 539,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "540": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 540,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "541": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 541,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "542": {
            "avg_ns_per_run": 4433.316313823163,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 542,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 803,
            "run_time_ns_delta": 3559953,
            "type": "kprobe"
          },
          "543": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 543,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 545,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 547,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 549,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "550": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 550,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "551": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 551,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "552": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 552,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "553": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 553,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "554": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 554,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "555": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 555,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "556": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 556,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "557": {
            "avg_ns_per_run": 467.00940909648153,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 557,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 97884,
            "run_time_ns_delta": 45712749,
            "type": "kprobe"
          },
          "558": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 558,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "559": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 559,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "560": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 560,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "561": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 561,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "562": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 562,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "563": {
            "avg_ns_per_run": 101.16413305545339,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 563,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 97884,
            "run_time_ns_delta": 9902350,
            "type": "kprobe"
          },
          "564": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 564,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "565": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 565,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "566": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 566,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "567": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 567,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "568": {
            "avg_ns_per_run": 1398.316788881482,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 568,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 99006,
            "run_time_ns_delta": 138441752,
            "type": "kprobe"
          },
          "569": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 569,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "570": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 570,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "571": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 571,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "572": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 572,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "573": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 573,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "574": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 574,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "575": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 575,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "576": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 576,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "577": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 577,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "578": {
            "avg_ns_per_run": 1325.5882352941176,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 578,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 17,
            "run_time_ns_delta": 22535,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 579,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 580,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 581,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 582,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 583,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "584": {
            "avg_ns_per_run": 1679.8,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 584,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 5,
            "run_time_ns_delta": 8399,
            "type": "kprobe"
          },
          "585": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 585,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "586": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 586,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 587,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "588": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 588,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "589": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 589,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "590": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 590,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "591": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 591,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "592": {
            "avg_ns_per_run": 7727.5,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 592,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 15455,
            "type": "kprobe"
          },
          "593": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 593,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "594": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 594,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "595": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 595,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "596": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 596,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "597": {
            "avg_ns_per_run": 3004.5,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 597,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 6009,
            "type": "kprobe"
          },
          "598": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 598,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "599": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 599,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "600": {
            "avg_ns_per_run": 5633.666666666667,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 600,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 16901,
            "type": "kprobe"
          },
          "601": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 601,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "602": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 602,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 603,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 604,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "605": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 605,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "606": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 606,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "607": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 607,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "608": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 608,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "609": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 609,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "610": {
            "avg_ns_per_run": 1910.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 610,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 5,
            "run_time_ns_delta": 9550,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 611,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "612": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 612,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "613": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 613,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "614": {
            "avg_ns_per_run": 1275.6332195459295,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 614,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 135926,
            "run_time_ns_delta": 173391721,
            "type": "kprobe"
          },
          "615": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 615,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "616": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 616,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "617": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 617,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "618": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 618,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "619": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 619,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "620": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 620,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 621,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "622": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 622,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "623": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 623,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 624,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 625,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1851502430000096,
            "ops_per_sec": 23491126.263895787,
            "ops_total": 27840514.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [13736] setting to a 1 secs run per stressor\nstress-ng: info:  [13736] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set, 1 aio, 1 aiol, 1 hdd, 1 io, 1 iomix, 1 io-uring, 1 sync-file, 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 udp-flood\nstress-ng: info:  [13736] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [13745] io: this is a legacy I/O sync stressor, consider using iomix instead\nstress-ng: metrc: [13736] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13736]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13736] cap               93696      1.00      0.02      0.87     93695.26      105071.93\nstress-ng: metrc: [13736] eventfd           44224      1.00      0.02      0.69     44203.90       62096.22\nstress-ng: metrc: [13736] get                 263      1.00      0.01      0.14       263.00        1732.15\nstress-ng: metrc: [13736] prctl               997      1.00      0.58      0.14       996.30        1384.55\nstress-ng: metrc: [13736] set                7583      1.00      0.01      0.77      7582.78        9695.15\nstress-ng: metrc: [13736] aio                8745      1.00      0.00      0.12      8726.62       70044.61\nstress-ng: metrc: [13736] aiol               1410      1.16      0.02      0.19      1211.68        6814.79\nstress-ng: metrc: [13736] hdd               20217      1.01      0.37      0.38     20104.52       26826.34\nstress-ng: metrc: [13736] io                   75      1.01      0.00      0.02        74.59        4376.75\nstress-ng: metrc: [13736] iomix              1535      1.01      0.03      0.31      1526.45        4414.55\nstress-ng: metrc: [13736] io-uring           7982      1.01      0.00      0.33      7892.11       24302.17\nstress-ng: metrc: [13736] sync-file            12      1.00      0.02      0.58        11.98          20.02\nstress-ng: metrc: [13736] epoll             12168      1.00      0.01      0.88     12150.66       13591.83\nstress-ng: metrc: [13736] netdev            40293      1.00      0.01      0.92     40293.18       43124.97\nstress-ng: metrc: [13736] sctp              21894      1.00      0.01      0.46     21889.27       46698.33\nstress-ng: metrc: [13736] sock                266      1.00      0.01      0.94       265.64         279.69\nstress-ng: metrc: [13736] sockdiag       27287254      1.00      0.08      0.79  27286460.32    31465675.44\nstress-ng: metrc: [13736] sockfd            83974      1.00      0.01      0.84     83898.05       98412.84\nstress-ng: metrc: [13736] sockpair         109775      1.06      0.01      1.48    103714.15       73711.95\nstress-ng: metrc: [13736] udp-flood         98151      1.00      0.02      0.90     98149.92      106991.38\nstress-ng: info:  [13736] skipped: 0\nstress-ng: info:  [13736] passed: 20: cap (1) eventfd (1) get (1) prctl (1) set (1) aio (1) aiol (1) hdd (1) io (1) iomix (1) io-uring (1) sync-file (1) epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) udp-flood (1)\nstress-ng: info:  [13736] failed: 0\nstress-ng: info:  [13736] metrics untrustworthy: 0\nstress-ng: info:  [13736] successful run completed in 1.17 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 336: prog 336 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 338: prog 338 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 339: prog 339 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 340: prog 340 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 341: prog 341 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 342: prog 342 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 343: prog 343 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 346: prog 346 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 347: prog 347 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 348: prog 348 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 349: prog 349 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 350: prog 350 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 351: prog 351 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 352: prog 352 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 353: prog 353 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 354: prog 354 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 355: prog 355 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 356: prog 356 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 357: prog 357 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 358: prog 358 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 359: prog 359 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 360: prog 360 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 361: prog 361 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 362: prog 362 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 363: prog 363 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 364: prog 364 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 365: prog 365 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 366: prog 366 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 367: prog 367 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 368: prog 368 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 369: prog 369 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 370: prog 370 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 371: prog 371 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 372: prog 372 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 373: prog 373 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 374: prog 374 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 375: prog 375 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 376: prog 376 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 377: prog 377 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 378: prog 378 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 379: prog 379 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 380: prog 380 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 381: prog 381 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 382: prog 382 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 383: prog 383 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 384: prog 384 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 385: prog 385 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 386: prog 386 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 387: prog 387 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 388: prog 388 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 389: prog 389 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 390: prog 390 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 391: prog 391 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 392: prog 392 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 393: prog 393 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 394: prog 394 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 395: prog 395 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 396: prog 396 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 397: prog 397 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 398: prog 398 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 399: prog 399 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 400: prog 400 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 401: prog 401 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 402: prog 402 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 403: prog 403 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 404: prog 404 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 405: prog 405 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 406: prog 406 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 407: prog 407 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 408: prog 408 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 409: prog 409 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 410: prog 410 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 411: prog 411 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 412: prog 412 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 413: prog 413 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 414: prog 414 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 415: prog 415 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 416: prog 416 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 417: prog 417 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 418: prog 418 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 419: prog 419 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 420: prog 420 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 421: prog 421 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 422: prog 422 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 423: prog 423 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 424: prog 424 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 425: prog 425 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 426: prog 426 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 427: prog 427 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 428: prog 428 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 429: prog 429 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 430: prog 430 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 431: prog 431 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 432: prog 432 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 433: prog 433 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 434: prog 434 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 435: prog 435 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 436: prog 436 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 437: prog 437 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 438: prog 438 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 439: prog 439 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 440: prog 440 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 441: prog 441 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 442: prog 442 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 443: prog 443 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 444: prog 444 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 445: prog 445 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 446: prog 446 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 447: prog 447 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 448: prog 448 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 449: prog 449 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 450: prog 450 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 451: prog 451 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 452: prog 452 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 453: prog 453 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 454: prog 454 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 455: prog 455 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 456: prog 456 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 457: prog 457 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 458: prog 458 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 459: prog 459 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 460: prog 460 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 461: prog 461 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 462: prog 462 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 463: prog 463 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 464: prog 464 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 465: prog 465 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 466: prog 466 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 467: prog 467 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 468: prog 468 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 469: prog 469 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 470: prog 470 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 471: prog 471 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 472: prog 472 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 473: prog 473 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 474: prog 474 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 475: prog 475 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 476: prog 476 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 477: prog 477 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 478: prog 478 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 479: prog 479 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 480: prog 480 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 481: prog 481 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 482: prog 482 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 483: prog 483 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 484: prog 484 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 485: prog 485 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 486: prog 486 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 487: prog 487 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 488: prog 488 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 489: prog 489 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 490: prog 490 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 491: prog 491 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 492: prog 492 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 493: prog 493 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 494: prog 494 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 495: prog 495 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 496: prog 496 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 497: prog 497 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 498: prog 498 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 499: prog 499 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 500: prog 500 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 501: prog 501 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 502: prog 502 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 503: prog 503 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 504: prog 504 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 505: prog 505 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 506: prog 506 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 507: prog 507 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 508: prog 508 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 509: prog 509 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 510: prog 510 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 511: prog 511 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 512: prog 512 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 513: prog 513 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 514: prog 514 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 515: prog 515 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 516: prog 516 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 517: prog 517 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 518: prog 518 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 519: prog 519 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 520: prog 520 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 521: prog 521 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 522: prog 522 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 523: prog 523 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 524: prog 524 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 525: prog 525 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 526: prog 526 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 527: prog 527 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 528: prog 528 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 529: prog 529 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 530: prog 530 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 531: prog 531 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 532: prog 532 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 533: prog 533 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 534: prog 534 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 535: prog 535 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 536: prog 536 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 537: prog 537 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 538: prog 538 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 539: prog 539 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 540: prog 540 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 541: prog 541 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 542: prog 542 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 543: prog 543 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 544: prog 544 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 545: prog 545 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 546: prog 546 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 547: prog 547 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 548: prog 548 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 549: prog 549 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 550: prog 550 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 551: prog 551 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 552: prog 552 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 553: prog 553 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 554: prog 554 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 555: prog 555 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 556: prog 556 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 557: prog 557 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 558: prog 558 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 559: prog 559 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 560: prog 560 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 561: prog 561 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 562: prog 562 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 563: prog 563 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 564: prog 564 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 565: prog 565 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 566: prog 566 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 567: prog 567 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 568: prog 568 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 569: prog 569 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 570: prog 570 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 571: prog 571 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 572: prog 572 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 573: prog 573 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 574: prog 574 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 575: prog 575 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 576: prog 576 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 577: prog 577 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 578: prog 578 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 579: prog 579 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 580: prog 580 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 581: prog 581 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 582: prog 582 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 583: prog 583 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 584: prog 584 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 585: prog 585 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 586: prog 586 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 587: prog 587 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 588: prog 588 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 589: prog 589 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 590: prog 590 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 591: prog 591 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 592: prog 592 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 593: prog 593 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 594: prog 594 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 595: prog 595 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 596: prog 596 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 597: prog 597 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 598: prog 598 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 599: prog 599 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 600: prog 600 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 601: prog 601 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 602: prog 602 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 603: prog 603 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 604: prog 604 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 605: prog 605 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 606: prog 606 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 607: prog 607 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 608: prog 608 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 609: prog 609 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 610: prog 610 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 611: prog 611 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 612: prog 612 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 613: prog 613 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 614: prog 614 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 615: prog 615 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 616: prog 616 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 617: prog 617 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 618: prog 618 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 619: prog 619 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 620: prog 620 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 621: prog 621 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 622: prog 622 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 623: prog 623 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 624: prog 624 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 625: prog 625 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 336 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 336
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 338 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 338
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 339 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 339
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 340 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 340
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 341 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 341
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 342 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 342
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 343 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 343
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 346 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 346
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 347 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 347
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 348 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 348
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 349 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 349
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 350 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 350
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 351 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 351
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 352 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 352
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 353 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 353
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 354 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 354
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 355 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 355
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 356 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 356
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 357 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 357
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 358 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 358
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 359 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 359
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 360 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 360
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 361 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 361
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 362 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 362
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 363 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 363
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 364 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 364
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 365 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 365
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 366 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 366
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 367 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 367
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 368 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 368
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 369 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 369
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 370 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 370
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 371 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 371
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 372 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 372
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 373 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 373
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 374 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 374
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 375 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 375
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 376 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 376
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 377 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 377
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 378 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 378
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 379 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 379
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 380 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 380
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 381 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 381
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 382 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 382
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 383 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 383
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 384 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 384
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 385 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 385
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 386 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 386
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 387 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 387
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 388 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 388
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 389 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 389
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 390 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 390
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 391 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 391
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 392 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 392
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 393 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 393
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 394 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 394
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 395 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 395
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 396 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 396
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 397 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 397
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 398 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 398
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 399 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 399
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 400 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 400
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 401 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 401
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 402 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 402
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 403 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 403
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 404 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 404
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 405 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 405
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 406 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 406
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 407 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 407
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 408 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 408
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 409 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 409
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 410 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 410
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 411 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 411
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 412 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 412
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 413 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 413
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 414 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 414
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 415 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 415
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 416 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 416
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 417 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 417
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 418 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 418
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 419 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 419
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 420 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 420
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 421 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 421
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 422 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 422
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 423 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 423
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 424 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 424
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 425 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 425
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 426 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 426
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 427 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 427
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 428 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 428
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 429 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 429
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 430 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 430
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 431 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 431
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 432 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 432
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 433 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 433
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 434 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 434
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 435 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 435
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 436 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 436
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 437 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 437
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 438 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 438
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 439 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 439
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 440 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 440
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 441 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 441
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 442 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 442
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 443 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 443
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 444 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 444
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 445 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 445
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 446 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 446
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 447 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 447
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 448 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 448
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 449 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 449
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 450 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 450
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 451 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 451
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 452 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 452
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 453 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 453
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 454 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 454
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 455 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 455
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 456 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 456
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 457 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 457
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 458 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 458
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 459 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 459
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 460 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 460
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 461 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 461
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 462 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 462
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 463 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 463
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 464 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 464
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 465 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 465
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 466 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 466
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 467 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 467
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 468 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 468
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 469 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 469
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 470 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 470
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 471 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 471
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 472 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 472
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 473 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 473
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 474 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 474
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 475 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 475
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 476 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 476
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 477 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 477
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 478 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 478
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 479 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 479
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 480 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 480
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 481 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 481
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 482 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 482
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 483 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 483
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 484 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 484
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 485 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 485
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 486 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 486
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 487 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 487
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 488 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 488
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 489 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 489
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 490 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 490
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 491 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 491
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 492 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 492
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 493 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 493
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 494 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 494
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 495 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 495
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 496 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 496
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 497 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 497
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 498 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 498
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 499 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 499
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 500 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 500
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 501 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 501
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 502 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 502
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 503 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 503
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 504 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 504
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 505 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 505
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 506 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 506
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 507 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 507
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 508 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 508
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 509 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 509
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 510 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 510
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 511 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 511
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 512 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 512
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 513 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 513
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 514 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 514
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 515 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 515
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 516 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 516
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 517 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 517
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 518 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 518
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 519 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 519
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 520 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 520
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 521 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 521
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 522 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 522
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 523 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 523
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 524 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 524
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 525 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 525
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 526 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 526
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 527 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 527
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 528 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 528
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 529 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 529
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 530 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 530
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 531 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 531
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 532 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 532
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 533 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 533
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 534 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 534
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 535 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 535
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 536 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 536
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 537 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 537
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 538 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 538
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 539 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 539
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 540 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 540
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 541 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 541
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 542 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 542
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 543 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 543
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 544 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 544
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 545 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 545
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 546 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 546
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 547 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 547
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 548 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 548
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 549 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 549
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 550 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 550
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 551 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 551
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 552 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 552
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 553 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 553
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 554 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 554
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 555 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 555
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 556 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 556
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 557 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 557
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 558 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 558
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 559 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 559
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 560 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 560
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 561 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 561
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 562 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 562
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 563 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 563
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 564 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 564
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 565 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 565
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 566 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 566
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 567 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 567
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 568 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 568
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 569 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 569
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 570 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 570
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 571 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 571
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 572 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 572
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 573 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 573
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 574 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 574
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 575 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 575
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 576 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 576
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 577 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 577
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 578 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 578
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 579 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 579
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 580 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 580
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 581 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 581
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 582 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 582
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 583 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 583
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 584 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 584
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 585 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 585
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 586 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 586
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 587 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 587
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 588 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 588
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 589 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 589
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 590 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 590
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 591 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 591
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 592 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 592
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 593 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 593
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 594 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 594
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 595 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 595
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 596 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 596
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 597 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 597
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 598 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 598
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 599 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 599
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 600 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 600
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 601 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 601
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 602 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 602
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 603 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 603
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 604 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 604
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 605 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 605
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 606 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 606
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 607 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 607
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 608 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 608
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 609 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 609
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 610 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 610
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 611 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 611
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 612 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 612
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 613 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 613
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 614 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 614
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 615 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 615
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 616 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 616
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 617 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 617
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 618 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 618
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 619 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 619
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 620 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 620
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 621 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 621
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 622 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 622
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 623 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 623
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 624 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 624
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 625 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 625
          }
        ],
        "exit_code": 1,
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
          "632": {
            "avg_ns_per_run": 324.36304295656345,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 632,
            "name": "xdp_root",
            "run_cnt_delta": 41670,
            "run_time_ns_delta": 13516208,
            "type": "xdp"
          },
          "638": {
            "avg_ns_per_run": null,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 638,
            "name": "balancer_ingress",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "640": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 640,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0005523279999693,
            "ops_per_sec": 6941.166199555545,
            "ops_total": 6945.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "632": {
            "avg_ns_per_run": 336.333457822926,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 632,
            "name": "xdp_root",
            "run_cnt_delta": 40164,
            "run_time_ns_delta": 13508497,
            "type": "xdp"
          },
          "638": {
            "avg_ns_per_run": null,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 638,
            "name": "balancer_ingress",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "640": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 640,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0005292420000274,
            "ops_per_sec": 6690.45912802998,
            "ops_total": 6694.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 632: prog 632 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 638: prog 638 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 640: prog 640 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 632 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 632
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 638 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 638
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 640 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 640
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 0,
          "not_applied": 3,
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
          "655": {
            "avg_ns_per_run": 148.3740077991518,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 655,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 30652564,
            "run_time_ns_delta": 4548043770,
            "type": "raw_tracepoint"
          },
          "656": {
            "avg_ns_per_run": null,
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 656,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "657": {
            "avg_ns_per_run": null,
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 657,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "658": {
            "avg_ns_per_run": 300.7704679173873,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 658,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 30652569,
            "run_time_ns_delta": 9219387521,
            "type": "raw_tracepoint"
          },
          "659": {
            "avg_ns_per_run": null,
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 659,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "660": {
            "avg_ns_per_run": null,
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 660,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "661": {
            "avg_ns_per_run": 259.6021894285907,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 661,
            "name": "trace_sys_enter",
            "run_cnt_delta": 30652564,
            "run_time_ns_delta": 7957472726,
            "type": "raw_tracepoint"
          },
          "662": {
            "avg_ns_per_run": 253.82586930968168,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 662,
            "name": "trace_sys_exit",
            "run_cnt_delta": 30652569,
            "run_time_ns_delta": 7780414973,
            "type": "raw_tracepoint"
          },
          "663": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 663,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 664,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "665": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 665,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "666": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 666,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "667": {
            "avg_ns_per_run": 67.8134771724855,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 667,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 1045427,
            "run_time_ns_delta": 70894040,
            "type": "kprobe"
          },
          "668": {
            "avg_ns_per_run": 277.02744907104943,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 668,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 1045427,
            "run_time_ns_delta": 289611975,
            "type": "kprobe"
          },
          "669": {
            "avg_ns_per_run": 239.90019255455712,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 669,
            "name": "trace_dup",
            "run_cnt_delta": 3116,
            "run_time_ns_delta": 747529,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 1000.900513478819,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 670,
            "name": "trace_ret_dup",
            "run_cnt_delta": 3116,
            "run_time_ns_delta": 3118806,
            "type": "kprobe"
          },
          "671": {
            "avg_ns_per_run": 585.75,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 671,
            "name": "trace_dup2",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 2343,
            "type": "kprobe"
          },
          "672": {
            "avg_ns_per_run": 1404.25,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 672,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5617,
            "type": "kprobe"
          },
          "673": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 673,
            "name": "trace_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "674": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 674,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "675": {
            "avg_ns_per_run": null,
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 675,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "676": {
            "avg_ns_per_run": null,
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 676,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "677": {
            "avg_ns_per_run": null,
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 677,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "678": {
            "avg_ns_per_run": null,
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 678,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "679": {
            "avg_ns_per_run": null,
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 679,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "680": {
            "avg_ns_per_run": 1944.6413470993116,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 680,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 4068,
            "run_time_ns_delta": 7910801,
            "type": "raw_tracepoint"
          },
          "681": {
            "avg_ns_per_run": null,
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 681,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "682": {
            "avg_ns_per_run": null,
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 682,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "683": {
            "avg_ns_per_run": null,
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 683,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "684": {
            "avg_ns_per_run": null,
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 684,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": null,
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 685,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": null,
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 686,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "687": {
            "avg_ns_per_run": null,
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 687,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "688": {
            "avg_ns_per_run": 4312.0,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 688,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8624,
            "type": "raw_tracepoint"
          },
          "689": {
            "avg_ns_per_run": null,
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 689,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "690": {
            "avg_ns_per_run": 1405.7574857708487,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 690,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 4041,
            "run_time_ns_delta": 5680666,
            "type": "raw_tracepoint"
          },
          "691": {
            "avg_ns_per_run": 945.9834240475012,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 691,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 4042,
            "run_time_ns_delta": 3823665,
            "type": "raw_tracepoint"
          },
          "692": {
            "avg_ns_per_run": null,
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 692,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "693": {
            "avg_ns_per_run": 372.2682224305487,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 693,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 1825127,
            "run_time_ns_delta": 679436784,
            "type": "raw_tracepoint"
          },
          "694": {
            "avg_ns_per_run": 16.74392578774055,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 694,
            "name": "trace_filldir64",
            "run_cnt_delta": 529616,
            "run_time_ns_delta": 8867851,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": null,
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 695,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": 895.1841128433556,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 696,
            "name": "trace_do_exit",
            "run_cnt_delta": 4041,
            "run_time_ns_delta": 3617439,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": null,
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 697,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "698": {
            "avg_ns_per_run": null,
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 698,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "699": {
            "avg_ns_per_run": null,
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 699,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "700": {
            "avg_ns_per_run": 92.61685238443657,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 700,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 4432263,
            "run_time_ns_delta": 410502248,
            "type": "kprobe"
          },
          "701": {
            "avg_ns_per_run": null,
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 701,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "702": {
            "avg_ns_per_run": null,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 702,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "703": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 703,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "704": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 704,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "705": {
            "avg_ns_per_run": 3853.5,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 705,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 7707,
            "type": "kprobe"
          },
          "706": {
            "avg_ns_per_run": 564.2128137652934,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 706,
            "name": "trace_security_file_open",
            "run_cnt_delta": 728092,
            "run_time_ns_delta": 410798836,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": null,
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 707,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": 2095.706896551724,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 708,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 116,
            "run_time_ns_delta": 243102,
            "type": "kprobe"
          },
          "709": {
            "avg_ns_per_run": 250.6558194336462,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 709,
            "name": "trace_commit_creds",
            "run_cnt_delta": 374289,
            "run_time_ns_delta": 93817716,
            "type": "kprobe"
          },
          "710": {
            "avg_ns_per_run": 523.8126701311556,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 710,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 4041,
            "run_time_ns_delta": 2116727,
            "type": "kprobe"
          },
          "711": {
            "avg_ns_per_run": 134.27410416398206,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 711,
            "name": "trace_cap_capable",
            "run_cnt_delta": 2491053,
            "run_time_ns_delta": 334483910,
            "type": "kprobe"
          },
          "712": {
            "avg_ns_per_run": 304.37530535474133,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 712,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 887083,
            "run_time_ns_delta": 270006159,
            "type": "kprobe"
          },
          "713": {
            "avg_ns_per_run": null,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 713,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "714": {
            "avg_ns_per_run": null,
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 714,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": null,
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 715,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": null,
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 716,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": 2348.25,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 717,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 9393,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 380.20584178898633,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 718,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 203020,
            "run_time_ns_delta": 77189390,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 454.2815885165638,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 719,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 209554,
            "run_time_ns_delta": 95196524,
            "type": "kprobe"
          },
          "720": {
            "avg_ns_per_run": 1379.25,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 720,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5517,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 349.63695557589307,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 721,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 66653,
            "run_time_ns_delta": 23304352,
            "type": "kprobe"
          },
          "722": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 722,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "723": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 723,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "724": {
            "avg_ns_per_run": 65.81727679367884,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 724,
            "name": "trace_vfs_write",
            "run_cnt_delta": 930462,
            "run_time_ns_delta": 61240475,
            "type": "kprobe"
          },
          "725": {
            "avg_ns_per_run": 81.24998549107863,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 725,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 930462,
            "run_time_ns_delta": 75600024,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": 668.0130623281767,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 726,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 930462,
            "run_time_ns_delta": 621560770,
            "type": "kprobe"
          },
          "727": {
            "avg_ns_per_run": 41.71275452409663,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 727,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 930462,
            "run_time_ns_delta": 38812133,
            "type": "kprobe"
          },
          "728": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 728,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "729": {
            "avg_ns_per_run": 694.2156862745098,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 729,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 51,
            "run_time_ns_delta": 35405,
            "type": "kprobe"
          },
          "730": {
            "avg_ns_per_run": 518.0196078431372,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 730,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 51,
            "run_time_ns_delta": 26419,
            "type": "kprobe"
          },
          "731": {
            "avg_ns_per_run": 5162.274509803921,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 731,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 51,
            "run_time_ns_delta": 263276,
            "type": "kprobe"
          },
          "732": {
            "avg_ns_per_run": 3604.529411764706,
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 732,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 51,
            "run_time_ns_delta": 183831,
            "type": "kprobe"
          },
          "733": {
            "avg_ns_per_run": null,
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 733,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "734": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 734,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "735": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 735,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "736": {
            "avg_ns_per_run": null,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 736,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "737": {
            "avg_ns_per_run": null,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 737,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "738": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 738,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "739": {
            "avg_ns_per_run": 63.842785203689566,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 739,
            "name": "trace_vfs_read",
            "run_cnt_delta": 1188107,
            "run_time_ns_delta": 75852060,
            "type": "kprobe"
          },
          "740": {
            "avg_ns_per_run": 620.3211444760447,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 740,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 1188107,
            "run_time_ns_delta": 737007894,
            "type": "kprobe"
          },
          "741": {
            "avg_ns_per_run": null,
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 741,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "742": {
            "avg_ns_per_run": 470.7843137254902,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 742,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 51,
            "run_time_ns_delta": 24010,
            "type": "kprobe"
          },
          "743": {
            "avg_ns_per_run": 2841.627450980392,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 743,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 51,
            "run_time_ns_delta": 144923,
            "type": "kprobe"
          },
          "744": {
            "avg_ns_per_run": null,
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 744,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "745": {
            "avg_ns_per_run": 134.417912291538,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 745,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 8095,
            "run_time_ns_delta": 1088113,
            "type": "kprobe"
          },
          "746": {
            "avg_ns_per_run": 74.35696168735817,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 746,
            "name": "trace_do_mmap",
            "run_cnt_delta": 7491,
            "run_time_ns_delta": 557008,
            "type": "kprobe"
          },
          "747": {
            "avg_ns_per_run": 379.2025096782806,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 747,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 7491,
            "run_time_ns_delta": 2840606,
            "type": "kprobe"
          },
          "748": {
            "avg_ns_per_run": 133.5283044058745,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 748,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 7490,
            "run_time_ns_delta": 1000127,
            "type": "kprobe"
          },
          "749": {
            "avg_ns_per_run": 1105.076923076923,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 749,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 39,
            "run_time_ns_delta": 43098,
            "type": "kprobe"
          },
          "750": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 750,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "751": {
            "avg_ns_per_run": 259.8723360655738,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 751,
            "name": "trace_security_bpf",
            "run_cnt_delta": 9760,
            "run_time_ns_delta": 2536354,
            "type": "kprobe"
          },
          "752": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 752,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "753": {
            "avg_ns_per_run": null,
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 753,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "754": {
            "avg_ns_per_run": 244.28469871360866,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 754,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2954,
            "run_time_ns_delta": 721617,
            "type": "kprobe"
          },
          "755": {
            "avg_ns_per_run": 646.0574162679426,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 755,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 209,
            "run_time_ns_delta": 135026,
            "type": "kprobe"
          },
          "756": {
            "avg_ns_per_run": null,
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 756,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "757": {
            "avg_ns_per_run": null,
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 757,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "758": {
            "avg_ns_per_run": null,
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 758,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "759": {
            "avg_ns_per_run": null,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 759,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "760": {
            "avg_ns_per_run": null,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 760,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "761": {
            "avg_ns_per_run": 1366.25,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 761,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5465,
            "type": "kprobe"
          },
          "762": {
            "avg_ns_per_run": null,
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 762,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "763": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 763,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "764": {
            "avg_ns_per_run": null,
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 764,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "765": {
            "avg_ns_per_run": null,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 765,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "766": {
            "avg_ns_per_run": null,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 766,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "767": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 767,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "768": {
            "avg_ns_per_run": null,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 768,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "769": {
            "avg_ns_per_run": 1302.25,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 769,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5209,
            "type": "kprobe"
          },
          "770": {
            "avg_ns_per_run": 52.25277842707418,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 770,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 3165820,
            "run_time_ns_delta": 165422891,
            "type": "kprobe"
          },
          "771": {
            "avg_ns_per_run": 943.2111515151515,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 771,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 4125,
            "run_time_ns_delta": 3890746,
            "type": "raw_tracepoint"
          },
          "772": {
            "avg_ns_per_run": null,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 772,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "773": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 773,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "774": {
            "avg_ns_per_run": null,
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 774,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "775": {
            "avg_ns_per_run": 1000.4880136986301,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 775,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 8176,
            "run_time_ns_delta": 8179990,
            "type": "kprobe"
          },
          "776": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 776,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "777": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 777,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "778": {
            "avg_ns_per_run": 2915.6679536679535,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 778,
            "name": "trace_do_truncate",
            "run_cnt_delta": 259,
            "run_time_ns_delta": 755158,
            "type": "kprobe"
          },
          "779": {
            "avg_ns_per_run": 150.23047905419259,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 779,
            "name": "trace_fd_install",
            "run_cnt_delta": 2121785,
            "run_time_ns_delta": 318756777,
            "type": "kprobe"
          },
          "780": {
            "avg_ns_per_run": 292.3658411721686,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 780,
            "name": "trace_filp_close",
            "run_cnt_delta": 396530,
            "run_time_ns_delta": 115931827,
            "type": "kprobe"
          },
          "781": {
            "avg_ns_per_run": 187.20189451263943,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 781,
            "name": "trace_file_update_time",
            "run_cnt_delta": 35682,
            "run_time_ns_delta": 6679738,
            "type": "kprobe"
          },
          "782": {
            "avg_ns_per_run": 644.0865702595146,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 782,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 35682,
            "run_time_ns_delta": 22982297,
            "type": "kprobe"
          },
          "783": {
            "avg_ns_per_run": 125.67433373280831,
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 783,
            "name": "trace_file_modified",
            "run_cnt_delta": 350460,
            "run_time_ns_delta": 44043827,
            "type": "kprobe"
          },
          "784": {
            "avg_ns_per_run": 503.68370427438225,
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 784,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 350460,
            "run_time_ns_delta": 176520991,
            "type": "kprobe"
          },
          "785": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 785,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "786": {
            "avg_ns_per_run": null,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 786,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "787": {
            "avg_ns_per_run": null,
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 787,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "788": {
            "avg_ns_per_run": 99.5,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 788,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 199,
            "type": "kprobe"
          },
          "789": {
            "avg_ns_per_run": 3092.0,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 789,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 6184,
            "type": "kprobe"
          },
          "790": {
            "avg_ns_per_run": 5159.5,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 790,
            "name": "trace_execute_finished",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 10319,
            "type": "kprobe"
          },
          "791": {
            "avg_ns_per_run": null,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 791,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "792": {
            "avg_ns_per_run": 2342.5,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 792,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 4685,
            "type": "kprobe"
          },
          "793": {
            "avg_ns_per_run": 288.15217937121577,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 793,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 621326,
            "run_time_ns_delta": 179036441,
            "type": "kprobe"
          },
          "794": {
            "avg_ns_per_run": null,
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 794,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "795": {
            "avg_ns_per_run": null,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 795,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "796": {
            "avg_ns_per_run": 345.39225349032984,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 796,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 365868,
            "run_time_ns_delta": 126367973,
            "type": "kprobe"
          },
          "797": {
            "avg_ns_per_run": null,
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 797,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "798": {
            "avg_ns_per_run": null,
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 798,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "799": {
            "avg_ns_per_run": 30.60747559579988,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 799,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 1096635,
            "run_time_ns_delta": 33565229,
            "type": "kprobe"
          },
          "800": {
            "avg_ns_per_run": 106.82087385502012,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 800,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 1096635,
            "run_time_ns_delta": 117143509,
            "type": "kprobe"
          },
          "801": {
            "avg_ns_per_run": 107.4121385446457,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 801,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 3147,
            "run_time_ns_delta": 338026,
            "type": "kprobe"
          },
          "802": {
            "avg_ns_per_run": 159.58407783653948,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 802,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 1691956,
            "run_time_ns_delta": 270009238,
            "type": "kprobe"
          },
          "803": {
            "avg_ns_per_run": 160.57588139121447,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 803,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 3850305,
            "run_time_ns_delta": 618266119,
            "type": "kprobe"
          },
          "804": {
            "avg_ns_per_run": 173.51362156575482,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 804,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 2885241,
            "run_time_ns_delta": 500628615,
            "type": "kprobe"
          },
          "806": {
            "avg_ns_per_run": 251.89080374173892,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 806,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 557281,
            "run_time_ns_delta": 140373959,
            "type": "cgroup_skb"
          },
          "807": {
            "avg_ns_per_run": 193.87091988204406,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 807,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 2009225,
            "run_time_ns_delta": 389530299,
            "type": "cgroup_skb"
          },
          "808": {
            "avg_ns_per_run": null,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 808,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "809": {
            "avg_ns_per_run": null,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 809,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "810": {
            "avg_ns_per_run": 67.5,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 810,
            "name": "empty_kprobe",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 135,
            "type": "kprobe"
          },
          "811": {
            "avg_ns_per_run": 894.0,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 811,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1788,
            "type": "raw_tracepoint"
          },
          "812": {
            "avg_ns_per_run": 271.7925825307791,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 812,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 728092,
            "run_time_ns_delta": 197890005,
            "type": "lsm"
          },
          "813": {
            "avg_ns_per_run": null,
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 813,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.118997093000019,
            "ops_per_sec": 23953987.62145762,
            "ops_total": 122620393.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [15295] setting to a 5 secs run per stressor\nstress-ng: info:  [15295] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set, 1 aio, 1 aiol, 1 hdd, 1 io, 1 iomix, 1 io-uring, 1 sync-file, 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 udp-flood\nstress-ng: info:  [15295] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [15304] io: this is a legacy I/O sync stressor, consider using iomix instead\nstress-ng: metrc: [15295] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15295]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15295] cap              492795      5.00      0.12      4.56     98558.36      105422.29\nstress-ng: metrc: [15295] eventfd          207753      5.00      0.12      4.32     41548.81       46770.23\nstress-ng: metrc: [15295] get                2303      5.00      0.04      1.24       460.57        1812.61\nstress-ng: metrc: [15295] prctl              3975      5.00      2.81      0.69       794.88        1135.66\nstress-ng: metrc: [15295] set               39750      5.00      0.19      4.55      7949.98        8375.25\nstress-ng: metrc: [15295] aio               38767      5.00      0.05      0.69      7752.75       52563.07\nstress-ng: metrc: [15295] aiol              10388      5.09      0.13      0.81      2042.59       10996.34\nstress-ng: metrc: [15295] hdd              103844      5.01      2.27      1.81     20731.54       25405.73\nstress-ng: metrc: [15295] io                  481      5.01      0.00      0.15        96.02        3152.51\nstress-ng: metrc: [15295] iomix              5640      5.01      0.07      0.70      1125.34        7296.57\nstress-ng: metrc: [15295] io-uring          62322      5.02      0.01      2.34     12411.33       26496.89\nstress-ng: metrc: [15295] sync-file            69      5.01      0.20      3.35        13.78          19.44\nstress-ng: metrc: [15295] epoll            199600      5.02      0.22      7.45     39734.61       26020.38\nstress-ng: metrc: [15295] netdev           187297      5.00      0.06      4.83     37459.27       38335.98\nstress-ng: metrc: [15295] sctp              40280      5.00      0.00      0.63      8055.55       63950.92\nstress-ng: metrc: [15295] sock               2080      5.00      0.06      5.08       415.81         405.00\nstress-ng: metrc: [15295] sockdiag      119733881      5.00      0.16      4.60  23944821.48    25159361.83\nstress-ng: metrc: [15295] sockfd           375268      5.01      0.12      4.77     74931.15       76649.28\nstress-ng: metrc: [15295] sockpair         384161      5.04      0.17      6.75     76248.71       55534.88\nstress-ng: metrc: [15295] udp-flood        729739      5.00      0.07      4.39    145947.20      163697.04\nstress-ng: info:  [15295] skipped: 0\nstress-ng: info:  [15295] passed: 20: cap (1) eventfd (1) get (1) prctl (1) set (1) aio (1) aiol (1) hdd (1) io (1) iomix (1) io-uring (1) sync-file (1) epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) udp-flood (1)\nstress-ng: info:  [15295] failed: 0\nstress-ng: info:  [15295] metrics untrustworthy: 0\nstress-ng: info:  [15295] successful run completed in 5.09 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "655": {
            "avg_ns_per_run": 148.96527275331255,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 655,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 29618962,
            "run_time_ns_delta": 4412196753,
            "type": "raw_tracepoint"
          },
          "656": {
            "avg_ns_per_run": null,
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 656,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "657": {
            "avg_ns_per_run": null,
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 657,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "658": {
            "avg_ns_per_run": 300.9426852057332,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 658,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 29618967,
            "run_time_ns_delta": 8913611462,
            "type": "raw_tracepoint"
          },
          "659": {
            "avg_ns_per_run": null,
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 659,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "660": {
            "avg_ns_per_run": null,
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 660,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "661": {
            "avg_ns_per_run": 259.30723311640696,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 661,
            "name": "trace_sys_enter",
            "run_cnt_delta": 29618962,
            "run_time_ns_delta": 7680411084,
            "type": "raw_tracepoint"
          },
          "662": {
            "avg_ns_per_run": 254.64237125487867,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 662,
            "name": "trace_sys_exit",
            "run_cnt_delta": 29618967,
            "run_time_ns_delta": 7542243991,
            "type": "raw_tracepoint"
          },
          "663": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 663,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 664,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "665": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 665,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "666": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 666,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "667": {
            "avg_ns_per_run": 68.23974661935904,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 667,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 1022809,
            "run_time_ns_delta": 69796227,
            "type": "kprobe"
          },
          "668": {
            "avg_ns_per_run": 278.8277703852821,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 668,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 1022809,
            "run_time_ns_delta": 285187553,
            "type": "kprobe"
          },
          "669": {
            "avg_ns_per_run": 218.953006993007,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 669,
            "name": "trace_dup",
            "run_cnt_delta": 3575,
            "run_time_ns_delta": 782757,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 858.0772027972027,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 670,
            "name": "trace_ret_dup",
            "run_cnt_delta": 3575,
            "run_time_ns_delta": 3067626,
            "type": "kprobe"
          },
          "671": {
            "avg_ns_per_run": 601.75,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 671,
            "name": "trace_dup2",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 2407,
            "type": "kprobe"
          },
          "672": {
            "avg_ns_per_run": 1838.25,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 672,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 7353,
            "type": "kprobe"
          },
          "673": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 673,
            "name": "trace_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "674": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 674,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "675": {
            "avg_ns_per_run": null,
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 675,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "676": {
            "avg_ns_per_run": null,
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 676,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "677": {
            "avg_ns_per_run": null,
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 677,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "678": {
            "avg_ns_per_run": null,
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 678,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "679": {
            "avg_ns_per_run": null,
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 679,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "680": {
            "avg_ns_per_run": 2385.4974054855447,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 680,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 4047,
            "run_time_ns_delta": 9654108,
            "type": "raw_tracepoint"
          },
          "681": {
            "avg_ns_per_run": null,
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 681,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "682": {
            "avg_ns_per_run": null,
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 682,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "683": {
            "avg_ns_per_run": null,
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 683,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "684": {
            "avg_ns_per_run": null,
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 684,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": null,
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 685,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": null,
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 686,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "687": {
            "avg_ns_per_run": null,
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 687,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "688": {
            "avg_ns_per_run": 5668.5,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 688,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 11337,
            "type": "raw_tracepoint"
          },
          "689": {
            "avg_ns_per_run": null,
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 689,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "690": {
            "avg_ns_per_run": 1428.8897597977243,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 690,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 3955,
            "run_time_ns_delta": 5651259,
            "type": "raw_tracepoint"
          },
          "691": {
            "avg_ns_per_run": 963.1116738414788,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 691,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 3949,
            "run_time_ns_delta": 3803328,
            "type": "raw_tracepoint"
          },
          "692": {
            "avg_ns_per_run": null,
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 692,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "693": {
            "avg_ns_per_run": 391.82437951344394,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 693,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 1492901,
            "run_time_ns_delta": 584955008,
            "type": "raw_tracepoint"
          },
          "694": {
            "avg_ns_per_run": 16.768480049132354,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 694,
            "name": "trace_filldir64",
            "run_cnt_delta": 491733,
            "run_time_ns_delta": 8245615,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": null,
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 695,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": 865.5418457648547,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 696,
            "name": "trace_do_exit",
            "run_cnt_delta": 3955,
            "run_time_ns_delta": 3423218,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": null,
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 697,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "698": {
            "avg_ns_per_run": null,
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 698,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "699": {
            "avg_ns_per_run": null,
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 699,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "700": {
            "avg_ns_per_run": 93.93860933186974,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 700,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 4129569,
            "run_time_ns_delta": 387925969,
            "type": "kprobe"
          },
          "701": {
            "avg_ns_per_run": null,
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 701,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "702": {
            "avg_ns_per_run": null,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 702,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "703": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 703,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "704": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 704,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "705": {
            "avg_ns_per_run": 4335.0,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 705,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8670,
            "type": "kprobe"
          },
          "706": {
            "avg_ns_per_run": 557.6961294479845,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 706,
            "name": "trace_security_file_open",
            "run_cnt_delta": 698350,
            "run_time_ns_delta": 389467092,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": null,
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 707,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": 2146.310344827586,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 708,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 116,
            "run_time_ns_delta": 248972,
            "type": "kprobe"
          },
          "709": {
            "avg_ns_per_run": 240.467199743544,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 709,
            "name": "trace_commit_creds",
            "run_cnt_delta": 386811,
            "run_time_ns_delta": 93015358,
            "type": "kprobe"
          },
          "710": {
            "avg_ns_per_run": 500.9714285714286,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 710,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 3955,
            "run_time_ns_delta": 1981342,
            "type": "kprobe"
          },
          "711": {
            "avg_ns_per_run": 133.5297820075574,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 711,
            "name": "trace_cap_capable",
            "run_cnt_delta": 2526005,
            "run_time_ns_delta": 337296897,
            "type": "kprobe"
          },
          "712": {
            "avg_ns_per_run": 296.5141066790104,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 712,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 784203,
            "run_time_ns_delta": 232527252,
            "type": "kprobe"
          },
          "713": {
            "avg_ns_per_run": null,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 713,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "714": {
            "avg_ns_per_run": null,
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 714,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": null,
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 715,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": null,
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 716,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": 1346.5,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 717,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5386,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 348.2518950437318,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 718,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 123480,
            "run_time_ns_delta": 43002144,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 443.1538081844037,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 719,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 127633,
            "run_time_ns_delta": 56561050,
            "type": "kprobe"
          },
          "720": {
            "avg_ns_per_run": 1417.5,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 720,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5670,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 351.0636151490107,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 721,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 123414,
            "run_time_ns_delta": 43326165,
            "type": "kprobe"
          },
          "722": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 722,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "723": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 723,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "724": {
            "avg_ns_per_run": 61.92908918238438,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 724,
            "name": "trace_vfs_write",
            "run_cnt_delta": 905560,
            "run_time_ns_delta": 56080506,
            "type": "kprobe"
          },
          "725": {
            "avg_ns_per_run": 82.27086443747515,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 725,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 905560,
            "run_time_ns_delta": 74501204,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": 625.5313198462829,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 726,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 905560,
            "run_time_ns_delta": 566456142,
            "type": "kprobe"
          },
          "727": {
            "avg_ns_per_run": 41.7001899377181,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 727,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 905560,
            "run_time_ns_delta": 37762024,
            "type": "kprobe"
          },
          "728": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 728,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "729": {
            "avg_ns_per_run": 657.3921568627451,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 729,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 51,
            "run_time_ns_delta": 33527,
            "type": "kprobe"
          },
          "730": {
            "avg_ns_per_run": 484.0980392156863,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 730,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 51,
            "run_time_ns_delta": 24689,
            "type": "kprobe"
          },
          "731": {
            "avg_ns_per_run": 4890.450980392156,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 731,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 51,
            "run_time_ns_delta": 249413,
            "type": "kprobe"
          },
          "732": {
            "avg_ns_per_run": 3573.0196078431372,
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 732,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 51,
            "run_time_ns_delta": 182224,
            "type": "kprobe"
          },
          "733": {
            "avg_ns_per_run": null,
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 733,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "734": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 734,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "735": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 735,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "736": {
            "avg_ns_per_run": null,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 736,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "737": {
            "avg_ns_per_run": null,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 737,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "738": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 738,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "739": {
            "avg_ns_per_run": 62.55351038261155,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 739,
            "name": "trace_vfs_read",
            "run_cnt_delta": 1138779,
            "run_time_ns_delta": 71234624,
            "type": "kprobe"
          },
          "740": {
            "avg_ns_per_run": 606.8005381202147,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 740,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 1138779,
            "run_time_ns_delta": 691011710,
            "type": "kprobe"
          },
          "741": {
            "avg_ns_per_run": null,
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 741,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "742": {
            "avg_ns_per_run": 494.7450980392157,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 742,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 51,
            "run_time_ns_delta": 25232,
            "type": "kprobe"
          },
          "743": {
            "avg_ns_per_run": 2696.627450980392,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 743,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 51,
            "run_time_ns_delta": 137528,
            "type": "kprobe"
          },
          "744": {
            "avg_ns_per_run": null,
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 744,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "745": {
            "avg_ns_per_run": 147.07634342186535,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 745,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 8095,
            "run_time_ns_delta": 1190583,
            "type": "kprobe"
          },
          "746": {
            "avg_ns_per_run": 90.768522226672,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 746,
            "name": "trace_do_mmap",
            "run_cnt_delta": 7491,
            "run_time_ns_delta": 679947,
            "type": "kprobe"
          },
          "747": {
            "avg_ns_per_run": 415.8063008944066,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 747,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 7491,
            "run_time_ns_delta": 3114805,
            "type": "kprobe"
          },
          "748": {
            "avg_ns_per_run": 147.01535380507343,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 748,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 7490,
            "run_time_ns_delta": 1101145,
            "type": "kprobe"
          },
          "749": {
            "avg_ns_per_run": 1198.7435897435898,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 749,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 39,
            "run_time_ns_delta": 46751,
            "type": "kprobe"
          },
          "750": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 750,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "751": {
            "avg_ns_per_run": 253.6762295081967,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 751,
            "name": "trace_security_bpf",
            "run_cnt_delta": 9760,
            "run_time_ns_delta": 2475880,
            "type": "kprobe"
          },
          "752": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 752,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "753": {
            "avg_ns_per_run": null,
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 753,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "754": {
            "avg_ns_per_run": 245.99627623561273,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 754,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2954,
            "run_time_ns_delta": 726673,
            "type": "kprobe"
          },
          "755": {
            "avg_ns_per_run": 744.3253588516747,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 755,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 209,
            "run_time_ns_delta": 155564,
            "type": "kprobe"
          },
          "756": {
            "avg_ns_per_run": null,
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 756,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "757": {
            "avg_ns_per_run": null,
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 757,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "758": {
            "avg_ns_per_run": null,
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 758,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "759": {
            "avg_ns_per_run": null,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 759,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "760": {
            "avg_ns_per_run": null,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 760,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "761": {
            "avg_ns_per_run": 1466.0,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 761,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5864,
            "type": "kprobe"
          },
          "762": {
            "avg_ns_per_run": null,
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 762,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "763": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 763,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "764": {
            "avg_ns_per_run": null,
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 764,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "765": {
            "avg_ns_per_run": null,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 765,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "766": {
            "avg_ns_per_run": null,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 766,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "767": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 767,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "768": {
            "avg_ns_per_run": null,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 768,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "769": {
            "avg_ns_per_run": 1658.5,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 769,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 6634,
            "type": "kprobe"
          },
          "770": {
            "avg_ns_per_run": 52.17014291638271,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 770,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 3043318,
            "run_time_ns_delta": 158770335,
            "type": "kprobe"
          },
          "771": {
            "avg_ns_per_run": 967.9584055459272,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 771,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 4039,
            "run_time_ns_delta": 3909584,
            "type": "raw_tracepoint"
          },
          "772": {
            "avg_ns_per_run": null,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 772,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "773": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 773,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "774": {
            "avg_ns_per_run": null,
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 774,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "775": {
            "avg_ns_per_run": 985.3325837081459,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 775,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 8004,
            "run_time_ns_delta": 7886602,
            "type": "kprobe"
          },
          "776": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 776,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "777": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 777,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "778": {
            "avg_ns_per_run": 2929.59778597786,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 778,
            "name": "trace_do_truncate",
            "run_cnt_delta": 271,
            "run_time_ns_delta": 793921,
            "type": "kprobe"
          },
          "779": {
            "avg_ns_per_run": 148.38408014281765,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 779,
            "name": "trace_fd_install",
            "run_cnt_delta": 1920771,
            "run_time_ns_delta": 285011838,
            "type": "kprobe"
          },
          "780": {
            "avg_ns_per_run": 295.8449559471925,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 780,
            "name": "trace_filp_close",
            "run_cnt_delta": 393959,
            "run_time_ns_delta": 116550783,
            "type": "kprobe"
          },
          "781": {
            "avg_ns_per_run": 185.5912970182278,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 781,
            "name": "trace_file_update_time",
            "run_cnt_delta": 37964,
            "run_time_ns_delta": 7045788,
            "type": "kprobe"
          },
          "782": {
            "avg_ns_per_run": 643.2255557896955,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 782,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 37964,
            "run_time_ns_delta": 24419415,
            "type": "kprobe"
          },
          "783": {
            "avg_ns_per_run": 119.2491544008865,
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 783,
            "name": "trace_file_modified",
            "run_cnt_delta": 344726,
            "run_time_ns_delta": 41108284,
            "type": "kprobe"
          },
          "784": {
            "avg_ns_per_run": 507.0901730649849,
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 784,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 344726,
            "run_time_ns_delta": 174807167,
            "type": "kprobe"
          },
          "785": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 785,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "786": {
            "avg_ns_per_run": null,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 786,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "787": {
            "avg_ns_per_run": null,
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 787,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "788": {
            "avg_ns_per_run": 101.0,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 788,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 202,
            "type": "kprobe"
          },
          "789": {
            "avg_ns_per_run": 3633.5,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 789,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 7267,
            "type": "kprobe"
          },
          "790": {
            "avg_ns_per_run": 5828.5,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 790,
            "name": "trace_execute_finished",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 11657,
            "type": "kprobe"
          },
          "791": {
            "avg_ns_per_run": null,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 791,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "792": {
            "avg_ns_per_run": 2804.5,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 792,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 5609,
            "type": "kprobe"
          },
          "793": {
            "avg_ns_per_run": 271.94217846883464,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 793,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 634262,
            "run_time_ns_delta": 172482590,
            "type": "kprobe"
          },
          "794": {
            "avg_ns_per_run": null,
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 794,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "795": {
            "avg_ns_per_run": null,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 795,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "796": {
            "avg_ns_per_run": 350.0520706455542,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 796,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 357956,
            "run_time_ns_delta": 125303239,
            "type": "kprobe"
          },
          "797": {
            "avg_ns_per_run": null,
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 797,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "798": {
            "avg_ns_per_run": null,
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 798,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "799": {
            "avg_ns_per_run": 28.63943656411145,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 799,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 911834,
            "run_time_ns_delta": 26114412,
            "type": "kprobe"
          },
          "800": {
            "avg_ns_per_run": 102.63809969797134,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 800,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 911834,
            "run_time_ns_delta": 93588909,
            "type": "kprobe"
          },
          "801": {
            "avg_ns_per_run": 124.87775311592965,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 801,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 5857,
            "run_time_ns_delta": 731409,
            "type": "kprobe"
          },
          "802": {
            "avg_ns_per_run": 213.24856575619654,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 802,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 1835462,
            "run_time_ns_delta": 391409639,
            "type": "kprobe"
          },
          "803": {
            "avg_ns_per_run": 195.34304209092323,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 803,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 4265599,
            "run_time_ns_delta": 833255085,
            "type": "kprobe"
          },
          "804": {
            "avg_ns_per_run": 198.1991179416509,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 804,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 2629758,
            "run_time_ns_delta": 521215716,
            "type": "kprobe"
          },
          "806": {
            "avg_ns_per_run": 308.0630264145792,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 806,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 439530,
            "run_time_ns_delta": 135402942,
            "type": "cgroup_skb"
          },
          "807": {
            "avg_ns_per_run": 197.7344298992601,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 807,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 1919994,
            "run_time_ns_delta": 379648919,
            "type": "cgroup_skb"
          },
          "808": {
            "avg_ns_per_run": null,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 808,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "809": {
            "avg_ns_per_run": null,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 809,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "810": {
            "avg_ns_per_run": 78.5,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 810,
            "name": "empty_kprobe",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 157,
            "type": "kprobe"
          },
          "811": {
            "avg_ns_per_run": 1024.5,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 811,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2049,
            "type": "raw_tracepoint"
          },
          "812": {
            "avg_ns_per_run": 265.2369556812487,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 812,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 698350,
            "run_time_ns_delta": 185228228,
            "type": "lsm"
          },
          "813": {
            "avg_ns_per_run": null,
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 813,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.146182522999993,
            "ops_per_sec": 19606790.577101365,
            "ops_total": 100900123.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [23814] setting to a 5 secs run per stressor\nstress-ng: info:  [23814] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set, 1 aio, 1 aiol, 1 hdd, 1 io, 1 iomix, 1 io-uring, 1 sync-file, 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 udp-flood\nstress-ng: info:  [23814] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [23823] io: this is a legacy I/O sync stressor, consider using iomix instead\nstress-ng: metrc: [23814] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23814]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23814] cap              464049      5.00      0.19      4.37     92809.63      101741.33\nstress-ng: metrc: [23814] eventfd          195886      5.00      0.13      3.94     39175.79       48094.37\nstress-ng: metrc: [23814] get                2041      5.00      0.05      1.14       408.20        1717.88\nstress-ng: metrc: [23814] prctl              3889      5.00      2.77      0.74       777.75        1107.96\nstress-ng: metrc: [23814] set               41198      5.00      0.13      4.72      8239.49        8500.14\nstress-ng: metrc: [23814] aio               58931      5.01      0.02      0.99     11764.66       58401.01\nstress-ng: metrc: [23814] aiol               9547      5.09      0.18      0.71      1877.45       10676.30\nstress-ng: metrc: [23814] hdd              104448      5.01      2.09      1.83     20851.64       26652.97\nstress-ng: metrc: [23814] io                  561      5.01      0.00      0.15       111.98        3668.61\nstress-ng: metrc: [23814] iomix              6842      5.01      0.04      0.78      1364.59        8379.28\nstress-ng: metrc: [23814] io-uring          71502      5.02      0.01      2.42     14247.33       29403.26\nstress-ng: metrc: [23814] sync-file            73      5.00      0.15      3.61        14.60          19.42\nstress-ng: metrc: [23814] epoll            117240      5.11      0.13      4.19     22932.17       27140.04\nstress-ng: metrc: [23814] netdev           173590      5.00      0.11      4.53     34718.01       37433.39\nstress-ng: metrc: [23814] sctp              38702      5.00      0.03      1.00      7739.96       37427.37\nstress-ng: metrc: [23814] sock               3082      5.00      0.13      6.91       616.31         437.49\nstress-ng: metrc: [23814] sockdiag       98112726      5.00      0.21      4.64  19621753.65    20236070.48\nstress-ng: metrc: [23814] sockfd           376461      5.00      0.09      4.82     75259.20       76755.84\nstress-ng: metrc: [23814] sockpair         372601      5.04      0.11      6.44     73951.28       56910.45\nstress-ng: metrc: [23814] udp-flood        746754      5.00      0.07      4.48    149350.51      164155.74\nstress-ng: info:  [23814] skipped: 0\nstress-ng: info:  [23814] passed: 20: cap (1) eventfd (1) get (1) prctl (1) set (1) aio (1) aiol (1) hdd (1) io (1) iomix (1) io-uring (1) sync-file (1) epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) udp-flood (1)\nstress-ng: info:  [23814] failed: 0\nstress-ng: info:  [23814] metrics untrustworthy: 0\nstress-ng: info:  [23814] successful run completed in 5.12 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 655: prog 655 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 656: prog 656 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 657: prog 657 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 658: prog 658 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 659: prog 659 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 660: prog 660 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 661: prog 661 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 662: prog 662 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 663: prog 663 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 664: prog 664 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 665: prog 665 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 666: prog 666 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 667: prog 667 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 668: prog 668 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 669: prog 669 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 670: prog 670 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 671: prog 671 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 672: prog 672 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 673: prog 673 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 674: prog 674 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 675: prog 675 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 676: prog 676 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 677: prog 677 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 678: prog 678 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 679: prog 679 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 680: prog 680 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 681: prog 681 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 682: prog 682 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 683: prog 683 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 684: prog 684 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 685: prog 685 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 686: prog 686 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 687: prog 687 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 688: prog 688 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 689: prog 689 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 690: prog 690 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 691: prog 691 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 692: prog 692 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 693: prog 693 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 694: prog 694 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 695: prog 695 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 696: prog 696 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 697: prog 697 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 698: prog 698 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 699: prog 699 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 700: prog 700 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 701: prog 701 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 702: prog 702 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 703: prog 703 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 704: prog 704 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 705: prog 705 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 706: prog 706 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 707: prog 707 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 708: prog 708 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 709: prog 709 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 710: prog 710 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 711: prog 711 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 712: prog 712 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 713: prog 713 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 714: prog 714 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 715: prog 715 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 716: prog 716 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 717: prog 717 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 718: prog 718 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 719: prog 719 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 720: prog 720 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 721: prog 721 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 722: prog 722 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 723: prog 723 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 724: prog 724 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 725: prog 725 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 726: prog 726 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 727: prog 727 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 728: prog 728 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 729: prog 729 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 730: prog 730 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 731: prog 731 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 732: prog 732 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 733: prog 733 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 734: prog 734 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 735: prog 735 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 736: prog 736 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 737: prog 737 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 738: prog 738 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 739: prog 739 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 740: prog 740 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 741: prog 741 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 742: prog 742 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 743: prog 743 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 744: prog 744 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 745: prog 745 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 746: prog 746 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 747: prog 747 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 748: prog 748 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 749: prog 749 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 750: prog 750 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 751: prog 751 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 752: prog 752 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 753: prog 753 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 754: prog 754 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 755: prog 755 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 756: prog 756 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 757: prog 757 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 758: prog 758 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 759: prog 759 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 760: prog 760 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 761: prog 761 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 762: prog 762 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 763: prog 763 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 764: prog 764 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 765: prog 765 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 766: prog 766 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 767: prog 767 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 768: prog 768 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 769: prog 769 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 770: prog 770 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 771: prog 771 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 772: prog 772 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 773: prog 773 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 774: prog 774 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 775: prog 775 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 776: prog 776 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 777: prog 777 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 778: prog 778 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 779: prog 779 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 780: prog 780 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 781: prog 781 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 782: prog 782 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 783: prog 783 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 784: prog 784 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 785: prog 785 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 786: prog 786 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 787: prog 787 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 788: prog 788 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 789: prog 789 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 790: prog 790 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 791: prog 791 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 792: prog 792 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 793: prog 793 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 794: prog 794 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 795: prog 795 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 796: prog 796 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 797: prog 797 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 798: prog 798 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 799: prog 799 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 800: prog 800 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 801: prog 801 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 802: prog 802 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 803: prog 803 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 804: prog 804 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 806: prog 806 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 807: prog 807 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 808: prog 808 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 809: prog 809 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 810: prog 810 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 811: prog 811 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 812: prog 812 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 813: prog 813 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 655 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 655
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 656 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 656
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 657 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 657
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 658 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 658
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 659 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 659
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 660 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 660
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 661 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 661
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 662 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 662
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 663 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 663
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 664 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 664
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 665 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 665
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 666 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 666
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 667 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 667
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 668 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 668
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 669 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 669
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 670 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 670
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 671 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 671
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 672 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 672
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 673 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 673
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 674 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 674
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 675 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 675
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 676 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 676
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 677 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 677
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 678 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 678
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 679 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 679
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 680 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 680
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 681 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 681
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 682 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 682
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 683 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 683
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 684 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 684
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 685 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 685
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 686 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 686
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 687 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 687
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 688 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 688
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 689 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 689
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 690 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 690
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 691 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 691
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 692 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 692
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 693 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 693
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 694 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 694
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 695 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 695
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 696 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 696
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 697 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 697
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 698 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 698
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 699 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 699
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 700 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 700
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 701 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 701
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 702 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 702
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 703 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 703
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 704 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 704
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 705 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 705
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 706 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 706
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 707 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 707
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 708 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 708
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 709 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 709
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 710 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 710
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 711 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 711
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 712 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 712
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 713 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 713
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 714 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 714
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 715 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 715
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 716 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 716
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 717 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 717
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 718 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 718
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 719 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 719
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 720 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 720
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 721 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 721
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 722 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 722
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 723 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 723
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 724 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 724
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 725 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 725
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 726 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 726
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 727 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 727
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 728 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 728
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 729 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 729
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 730 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 730
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 731 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 731
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 732 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 732
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 733 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 733
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 734 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 734
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 735 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 735
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 736 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 736
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 737 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 737
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 738 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 738
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 739 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 739
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 740 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 740
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 741 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 741
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 742 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 742
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 743 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 743
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 744 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 744
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 745 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 745
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 746 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 746
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 747 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 747
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 748 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 748
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 749 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 749
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 750 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 750
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 751 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 751
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 752 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 752
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 753 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 753
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 754 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 754
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 755 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 755
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 756 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 756
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 757 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 757
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 758 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 758
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 759 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 759
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 760 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 760
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 761 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 761
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 762 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 762
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 763 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 763
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 764 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 764
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 765 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 765
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 766 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 766
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 767 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 767
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 768 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 768
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 769 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 769
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 770 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 770
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 771 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 771
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 772 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 772
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 773 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 773
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 774 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 774
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 775 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 775
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 776 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 776
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 777 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 777
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 778 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 778
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 779 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 779
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 780 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 780
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 781 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 781
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 782 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 782
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 783 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 783
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 784 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 784
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 785 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 785
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 786 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 786
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 787 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 787
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 788 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 788
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 789 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 789
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 790 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 790
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 791 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 791
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 792 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 792
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 793 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 793
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 794 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 794
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 795 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 795
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 796 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 796
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 797 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 797
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 798 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 798
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 799 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 799
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 800 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 800
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 801 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 801
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 802 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 802
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 803 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 803
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 804 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 804
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 806 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 806
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 807 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 807
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 808 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 808
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 809 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 809
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 810 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 810
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 811 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 811
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 812 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 812
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 813 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 813
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 0,
          "not_applied": 158,
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
          "819": {
            "avg_ns_per_run": 169.2051392662339,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 819,
            "name": "cap_capable",
            "run_cnt_delta": 1205425,
            "run_time_ns_delta": 203964105,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0161616030000005,
            "ops_per_sec": 1393033.3480628468,
            "ops_total": 1415547.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [31247] setting to a 1 secs run per stressor\nstress-ng: info:  [31247] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [31247] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31247] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31247]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31247] cap             1185793      1.00      0.23      0.77   1185782.82     1185506.11\nstress-ng: metrc: [31247] eventfd          140835      1.00      0.07      0.63    140808.71      200291.55\nstress-ng: metrc: [31247] get                 927      1.00      0.01      0.18       926.18        4771.12\nstress-ng: metrc: [31247] prctl              3264      1.00      0.58      0.39      3263.24        3369.87\nstress-ng: metrc: [31247] set               84728      1.00      0.14      0.84     84726.24       86546.43\nstress-ng: info:  [31247] skipped: 0\nstress-ng: info:  [31247] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [31247] failed: 0\nstress-ng: info:  [31247] metrics untrustworthy: 0\nstress-ng: info:  [31247] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "819": {
            "avg_ns_per_run": 162.8636923566074,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 819,
            "name": "cap_capable",
            "run_cnt_delta": 1226615,
            "run_time_ns_delta": 199771048,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0153342520000024,
            "ops_per_sec": 1417630.693699868,
            "ops_total": 1439369.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5454] setting to a 1 secs run per stressor\nstress-ng: info:  [5454] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [5454] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5454] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5454]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5454] cap             1210118      1.00      0.23      0.77   1210117.42     1209891.75\nstress-ng: metrc: [5454] eventfd          139598      1.00      0.05      0.66    139522.06      195809.94\nstress-ng: metrc: [5454] get                 873      1.00      0.01      0.16       872.67        5200.05\nstress-ng: metrc: [5454] prctl              3448      1.00      0.60      0.37      3446.66        3544.04\nstress-ng: metrc: [5454] set               85332      1.00      0.16      0.82     85316.66       87168.91\nstress-ng: info:  [5454] skipped: 0\nstress-ng: info:  [5454] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [5454] failed: 0\nstress-ng: info:  [5454] metrics untrustworthy: 0\nstress-ng: info:  [5454] successful run completed in 1.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 819: prog 819 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 819 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 819
          }
        ],
        "exit_code": 1,
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
          "826": {
            "avg_ns_per_run": 447.9566590198555,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 826,
            "name": "block_io_start",
            "run_cnt_delta": 1350454,
            "run_time_ns_delta": 604944862,
            "type": "tracepoint"
          },
          "827": {
            "avg_ns_per_run": 820.2217703627407,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 827,
            "name": "block_io_done",
            "run_cnt_delta": 1350469,
            "run_time_ns_delta": 1107684074,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.3423403890000145,
            "ops_per_sec": 339872.0163429847,
            "ops_total": 1815712.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.065640,\n        \"1000\" : 9.731695\n      },\n      \"latency_us\" : {\n        \"2\" : 37.702831,\n        \"4\" : 1.889186,\n        \"10\" : 8.641236,\n        \"20\" : 36.691493,\n        \"50\" : 2.677968,\n        \"100\" : 2.081464,\n        \"250\" : 0.475391,\n        \"500\" : 0.042213,\n        \"750\" : 0.010000,\n        \"1000\" : 0.010000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "826": {
            "avg_ns_per_run": 437.153357065407,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 826,
            "name": "block_io_start",
            "run_cnt_delta": 1381534,
            "run_time_ns_delta": 603942226,
            "type": "tracepoint"
          },
          "827": {
            "avg_ns_per_run": 789.6577211521271,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 827,
            "name": "block_io_done",
            "run_cnt_delta": 1381549,
            "run_time_ns_delta": 1090950835,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.359064513999954,
            "ops_per_sec": 344202.2381296558,
            "ops_total": 1844602.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.073690,\n        \"1000\" : 9.624162\n      },\n      \"latency_us\" : {\n        \"2\" : 37.758886,\n        \"4\" : 1.879625,\n        \"10\" : 8.908659,\n        \"20\" : 36.983741,\n        \"50\" : 2.643749,\n        \"100\" : 1.761419,\n        \"250\" : 0.334737,\n        \"500\" : 0.028309,\n        \"750\" : 0.010000,\n        \"1000\" : 0.010000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.010000,\n        \"4\" : 0.010000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 826: prog 826 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 827: prog 827 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 826 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 826
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 827 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 827
          }
        ],
        "exit_code": 1,
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
          "834": {
            "avg_ns_per_run": 1371.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 834,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1371,
            "type": "perf_event"
          },
          "835": {
            "avg_ns_per_run": 31.64129024083062,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 835,
            "name": "vfs_create",
            "run_cnt_delta": 1562592,
            "run_time_ns_delta": 49442427,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1304390270000226,
            "ops_per_sec": 2347586.1471650577,
            "ops_total": 2653803.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [23738] setting to a 1 secs run per stressor\nstress-ng: info:  [23738] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [23738] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [23756] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [23743] dentry: 73369 dentries allocated\nstress-ng: metrc: [23738] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23738]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23738] access            10905      1.00      0.19      1.65     10856.78        5922.06\nstress-ng: metrc: [23738] chdir                48      1.08      0.05      0.84        44.41          54.08\nstress-ng: metrc: [23738] chmod               146      1.01      0.00      0.03       144.15        4436.75\nstress-ng: metrc: [23738] chown               176      1.01      0.00      0.01       173.77       13108.89\nstress-ng: metrc: [23738] dentry            14336      1.05      0.05      0.45     13700.76       28787.38\nstress-ng: metrc: [23738] dir                8192      1.10      0.05      0.89      7441.79        8716.65\nstress-ng: metrc: [23738] dirmany            8865      1.00      0.00      0.21      8826.29       42784.54\nstress-ng: metrc: [23738] fallocate             2      1.01      0.01      0.00         1.98         232.34\nstress-ng: metrc: [23738] file-ioctl        77150      1.00      0.07      0.70     76847.51       99758.85\nstress-ng: metrc: [23738] filename           3545      1.01      0.06      0.63      3502.21        5112.59\nstress-ng: metrc: [23738] flock           2178422      1.00      0.39      0.56   2170764.84     2301304.77\nstress-ng: metrc: [23738] fpunch             1022      1.01      0.00      0.28      1009.55        3653.51\nstress-ng: metrc: [23738] fstat              2657      1.00      0.14      0.60      2656.91        3585.22\nstress-ng: metrc: [23738] getdent          192252      1.00      0.13      0.87    192248.10      193305.52\nstress-ng: metrc: [23738] hdd               28672      1.02      0.48      0.20     28155.39       42505.75\nstress-ng: metrc: [23738] inotify               2      1.03      0.00      0.00         1.95         784.31\nstress-ng: metrc: [23738] open              16330      1.03      0.02      0.22     15857.44       66409.38\nstress-ng: metrc: [23738] rename              525      1.01      0.00      0.02       519.05       26701.25\nstress-ng: metrc: [23738] touch             64418      1.03      0.06      1.71     62700.19       36481.08\nstress-ng: metrc: [23738] utime             46138      1.01      0.02      0.73     45603.44       61675.22\nstress-ng: info:  [23738] skipped: 0\nstress-ng: info:  [23738] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [23738] failed: 0\nstress-ng: info:  [23738] metrics untrustworthy: 0\nstress-ng: info:  [23738] successful run completed in 1.12 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "834": {
            "avg_ns_per_run": 1992.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 834,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1992,
            "type": "perf_event"
          },
          "835": {
            "avg_ns_per_run": 31.46389237347477,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 835,
            "name": "vfs_create",
            "run_cnt_delta": 1678025,
            "run_time_ns_delta": 52797198,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1195860599999605,
            "ops_per_sec": 2374041.70609278,
            "ops_total": 2657944.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [13953] setting to a 1 secs run per stressor\nstress-ng: info:  [13953] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [13953] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [13970] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [13958] dentry: 75385 dentries allocated\nstress-ng: metrc: [13953] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13953]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13953] access            10564      1.00      0.23      1.41     10557.45        6454.25\nstress-ng: metrc: [13953] chdir                47      1.07      0.13      0.76        43.94          53.11\nstress-ng: metrc: [13953] chmod               143      1.01      0.02      0.02       141.47        3988.84\nstress-ng: metrc: [13953] chown               165      1.01      0.01      0.00       163.27       12193.32\nstress-ng: metrc: [13953] dentry            14336      1.02      0.02      0.42     14012.75       32354.02\nstress-ng: metrc: [13953] dir                8193      1.10      0.03      1.03      7468.59        7735.28\nstress-ng: metrc: [13953] dirmany           11103      1.00      0.00      0.25     11084.40       43966.01\nstress-ng: metrc: [13953] fallocate             2      1.01      0.01      0.00         1.98         170.26\nstress-ng: metrc: [13953] file-ioctl        79503      1.00      0.10      0.73     79354.41       95878.35\nstress-ng: metrc: [13953] filename           3934      1.01      0.02      0.76      3894.67        5050.69\nstress-ng: metrc: [13953] flock           2164347      1.00      0.36      0.67   2160560.37     2098046.63\nstress-ng: metrc: [13953] fpunch             1335      1.01      0.00      0.24      1320.54        5483.65\nstress-ng: metrc: [13953] fstat              1994      1.00      0.10      0.55      1993.49        3062.57\nstress-ng: metrc: [13953] getdent          198355      1.00      0.06      0.94    198349.18      199074.46\nstress-ng: metrc: [13953] hdd               26624      1.00      0.36      0.27     26591.34       42311.96\nstress-ng: metrc: [13953] inotify               2      1.01      0.00      0.00         1.98         671.14\nstress-ng: metrc: [13953] open              16431      1.01      0.04      0.20     16263.09       66763.91\nstress-ng: metrc: [13953] rename              471      1.01      0.00      0.01       466.14       33695.81\nstress-ng: metrc: [13953] touch             72688      1.01      0.06      1.74     71943.00       40375.58\nstress-ng: metrc: [13953] utime             47707      1.01      0.05      0.72     47231.02       61997.96\nstress-ng: info:  [13953] skipped: 0\nstress-ng: info:  [13953] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [13953] failed: 0\nstress-ng: info:  [13953] metrics untrustworthy: 0\nstress-ng: info:  [13953] successful run completed in 1.11 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 834: prog 834 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 835: prog 835 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 834 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 834
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 835 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 835
          }
        ],
        "exit_code": 1,
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
          "842": {
            "avg_ns_per_run": 65.58925928159314,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 842,
            "name": "sched_wakeup",
            "run_cnt_delta": 878917,
            "run_time_ns_delta": 57647515,
            "type": "tracepoint"
          },
          "843": {
            "avg_ns_per_run": 151.2433289986996,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 843,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 19225,
            "run_time_ns_delta": 2907653,
            "type": "tracepoint"
          },
          "844": {
            "avg_ns_per_run": 130.2495294137748,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 844,
            "name": "sched_switch",
            "run_cnt_delta": 12407928,
            "run_time_ns_delta": 1616126783,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0196453209999845,
            "ops_per_sec": 21452030.96557958,
            "ops_total": 21873463.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [8692] setting to a 1 secs run per stressor\nstress-ng: info:  [8692] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [8692] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8692] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8692]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8692] clone               661      1.01      0.21      0.84       656.38         631.69\nstress-ng: metrc: [8692] fork               2396      1.00      0.22      0.26      2395.66        5047.52\nstress-ng: metrc: [8692] futex            404302      2.00      0.22      1.15    202135.67      295661.48\nstress-ng: metrc: [8692] sem             1211824      1.00      0.15      0.58   1211183.80     1662079.74\nstress-ng: metrc: [8692] sem-sysv        4028385      1.00      0.09      0.85   4026859.44     4297539.93\nstress-ng: metrc: [8692] switch           457681      1.00      0.08      0.88    457580.63      474714.22\nstress-ng: metrc: [8692] vfork             15980      1.00      0.15      0.18     15979.89       47456.28\nstress-ng: metrc: [8692] yield          15752234      1.00      3.17      6.83  15693762.69     1575336.98\nstress-ng: info:  [8692] skipped: 0\nstress-ng: info:  [8692] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [8692] failed: 0\nstress-ng: info:  [8692] metrics untrustworthy: 0\nstress-ng: info:  [8692] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "842": {
            "avg_ns_per_run": 92.9753368256532,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 842,
            "name": "sched_wakeup",
            "run_cnt_delta": 593111,
            "run_time_ns_delta": 55144695,
            "type": "tracepoint"
          },
          "843": {
            "avg_ns_per_run": 135.75827778384877,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 843,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 27453,
            "run_time_ns_delta": 3726972,
            "type": "tracepoint"
          },
          "844": {
            "avg_ns_per_run": 139.0055919736062,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 844,
            "name": "sched_switch",
            "run_cnt_delta": 11897946,
            "run_time_ns_delta": 1653881027,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0235547300000007,
            "ops_per_sec": 20285828.780254852,
            "ops_total": 20763656.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [24729] setting to a 1 secs run per stressor\nstress-ng: info:  [24729] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [24729] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24729] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24729]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24729] clone               839      1.01      0.24      0.88       832.10         752.57\nstress-ng: metrc: [24729] fork               3248      1.00      0.30      0.35      3246.35        4990.14\nstress-ng: metrc: [24729] futex            310174      2.00      0.21      1.09    155071.07      239579.69\nstress-ng: metrc: [24729] sem             2165054      1.00      0.17      0.47   2164984.83     3402257.85\nstress-ng: metrc: [24729] sem-sysv        2628344      1.00      0.23      0.76   2627410.00     2640726.37\nstress-ng: metrc: [24729] switch           305835      1.00      0.13      0.75    305768.37      344734.88\nstress-ng: metrc: [24729] vfork             23136      1.00      0.22      0.23     23135.97       50862.21\nstress-ng: metrc: [24729] yield          15327026      1.01      3.16      6.51  15157651.34     1586443.86\nstress-ng: info:  [24729] skipped: 0\nstress-ng: info:  [24729] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [24729] failed: 0\nstress-ng: info:  [24729] metrics untrustworthy: 0\nstress-ng: info:  [24729] successful run completed in 1.01 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 842: prog 842 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 843: prog 843 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 844: prog 844 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 842 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 842
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 843 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 843
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 844 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 844
          }
        ],
        "exit_code": 1,
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
          "852": {
            "avg_ns_per_run": 820.3932664756447,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 852,
            "name": "tcp_set_state",
            "run_cnt_delta": 2792,
            "run_time_ns_delta": 2290538,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0002109440000027,
            "ops_per_sec": 309.93462115127505,
            "ops_total": 310.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "852": {
            "avg_ns_per_run": 915.8705374656728,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 852,
            "name": "tcp_set_state",
            "run_cnt_delta": 2549,
            "run_time_ns_delta": 2334554,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0007044550000046,
            "ops_per_sec": 282.8007795768219,
            "ops_total": 283.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 852: prog 852 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 852 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 852
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 0,
          "not_applied": 1,
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
          "859": {
            "avg_ns_per_run": null,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 859,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.121206465,
            "ops_per_sec": 18820532.94642945,
            "ops_total": 96383835.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [23015] setting to a 5 secs run per stressor\nstress-ng: info:  [23015] dispatching hogs: 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 udp-flood\nstress-ng: info:  [23015] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [23015] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23015]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23015] epoll             79765      5.11      0.08      0.74     15616.15       97383.77\nstress-ng: metrc: [23015] netdev          2509789      5.00      1.02      3.98    501956.65      501936.52\nstress-ng: metrc: [23015] sctp              94829      5.00      0.11      2.91     18963.35       31375.96\nstress-ng: metrc: [23015] sock              21327      5.00      0.24      9.08      4264.96        2286.00\nstress-ng: metrc: [23015] sockdiag       87797755      5.00      0.16      4.83  17558879.51    17588702.52\nstress-ng: metrc: [23015] sockfd          2983226      5.00      0.82      7.34    596544.36      365268.28\nstress-ng: metrc: [23015] sockpair        1379076      5.04      0.49      6.28    273707.30      203759.73\nstress-ng: metrc: [23015] udp-flood       1518068      5.00      0.18      4.76    303613.35      307462.29\nstress-ng: info:  [23015] skipped: 0\nstress-ng: info:  [23015] passed: 8: epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) udp-flood (1)\nstress-ng: info:  [23015] failed: 0\nstress-ng: info:  [23015] metrics untrustworthy: 0\nstress-ng: info:  [23015] successful run completed in 5.11 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "859": {
            "avg_ns_per_run": null,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 859,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.126411920999999,
            "ops_per_sec": 19675187.3541065,
            "ops_total": 100863115.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [23064] setting to a 5 secs run per stressor\nstress-ng: info:  [23064] dispatching hogs: 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 udp-flood\nstress-ng: info:  [23064] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [23064] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23064]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23064] epoll            185445      5.11      0.09      1.61     36300.55      108936.88\nstress-ng: metrc: [23064] netdev          2487059      5.00      0.82      4.18    497409.76      497400.56\nstress-ng: metrc: [23064] sctp               6293      5.00      0.03      0.00      1258.48      243631.44\nstress-ng: metrc: [23064] sock              21562      5.00      0.31      9.02      4311.92        2311.01\nstress-ng: metrc: [23064] sockdiag       92240460      5.00      0.18      4.81  18448035.70    18480417.95\nstress-ng: metrc: [23064] sockfd          3034527      5.00      0.72      7.37    606859.56      375142.55\nstress-ng: metrc: [23064] sockpair        1359438      5.02      0.45      6.20    270843.50      204316.47\nstress-ng: metrc: [23064] udp-flood       1528331      5.00      0.12      4.83    305662.77      308638.39\nstress-ng: info:  [23064] skipped: 0\nstress-ng: info:  [23064] passed: 8: epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) udp-flood (1)\nstress-ng: info:  [23064] failed: 0\nstress-ng: info:  [23064] metrics untrustworthy: 0\nstress-ng: info:  [23064] successful run completed in 5.11 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 859: prog 859 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 859 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 859
          }
        ],
        "exit_code": 1,
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
    "losses": 92,
    "per_program_geomean": 1.0582282701278507,
    "program_count": 151,
    "wins": 59
  },
  "workload_seconds": 1.0
}
```
