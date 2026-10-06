# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-04-28T18:21:57.163009+00:00",
  "kinsn_modules": {
    "captured_at": "2026-04-28T18:09:43.619655+00:00",
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
      "invoked_at": "2026-04-28T18:09:43.619599+00:00",
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
        "captured_at": "2026-04-28T18:09:43.619593+00:00",
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
      "captured_at": "2026-04-28T18:09:43.612432+00:00",
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
      "baseline_avg_ns_per_run": 299.96061106523535,
      "baseline_run_cnt_delta": 60550,
      "baseline_run_time_ns_delta": 18162615,
      "post_rejit_avg_ns_per_run": 197.45494192012478,
      "post_rejit_run_cnt_delta": 97452,
      "post_rejit_run_time_ns_delta": 19242379,
      "program": "cap_capable",
      "program_id": 6,
      "ratio": 0.6582695681906793,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 394.55555555555554,
      "baseline_run_cnt_delta": 9,
      "baseline_run_time_ns_delta": 3551,
      "post_rejit_avg_ns_per_run": 312.0,
      "post_rejit_run_cnt_delta": 9,
      "post_rejit_run_time_ns_delta": 2808,
      "program": "syscall__execve",
      "program_id": 9,
      "ratio": 0.7907631653055478,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 149.22222222222223,
      "baseline_run_cnt_delta": 9,
      "baseline_run_time_ns_delta": 1343,
      "post_rejit_avg_ns_per_run": 185.11111111111111,
      "post_rejit_run_cnt_delta": 9,
      "post_rejit_run_time_ns_delta": 1666,
      "program": "do_ret_sys_exec",
      "program_id": 10,
      "ratio": 1.240506329113924,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 773.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 1547,
      "post_rejit_avg_ns_per_run": 721.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 1443,
      "program": "bindsnoop_entry",
      "program_id": 13,
      "ratio": 0.9327731092436975,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 3750.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 7500,
      "post_rejit_avg_ns_per_run": 3452.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 6904,
      "program": "bindsnoop_v4_re",
      "program_id": 14,
      "ratio": 0.9205333333333333,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 321.60516538104275,
      "baseline_run_cnt_delta": 49522,
      "baseline_run_time_ns_delta": 15926531,
      "post_rejit_avg_ns_per_run": 262.37626854020294,
      "post_rejit_run_cnt_delta": 60207,
      "post_rejit_run_time_ns_delta": 15796888,
      "program": "trace_pid_start",
      "program_id": 18,
      "ratio": 0.8158335026408406,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 319.5540256803682,
      "baseline_run_cnt_delta": 49532,
      "baseline_run_time_ns_delta": 15828150,
      "post_rejit_avg_ns_per_run": 225.08539400481607,
      "post_rejit_run_cnt_delta": 60215,
      "post_rejit_run_time_ns_delta": 13553517,
      "program": "trace_req_start",
      "program_id": 19,
      "ratio": 0.7043735203322277,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 606.90311369744,
      "baseline_run_cnt_delta": 49491,
      "baseline_run_time_ns_delta": 30036242,
      "post_rejit_avg_ns_per_run": 132.52116793170455,
      "post_rejit_run_cnt_delta": 60209,
      "post_rejit_run_time_ns_delta": 7978967,
      "program": "trace_req_compl",
      "program_id": 20,
      "ratio": 0.21835638167078258,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 49.2324661810614,
      "baseline_run_cnt_delta": 4805,
      "baseline_run_time_ns_delta": 236562,
      "post_rejit_avg_ns_per_run": 53.34830526096901,
      "post_rejit_run_cnt_delta": 4809,
      "post_rejit_run_time_ns_delta": 256552,
      "program": "vfs_create",
      "program_id": 23,
      "ratio": 1.083600099673473,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 83.73113207547169,
      "baseline_run_cnt_delta": 212,
      "baseline_run_time_ns_delta": 17751,
      "post_rejit_avg_ns_per_run": 78.44578313253012,
      "post_rejit_run_cnt_delta": 249,
      "post_rejit_run_time_ns_delta": 19533,
      "program": "vfs_fsync_range",
      "program_id": 24,
      "ratio": 0.936877135040076,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 33.2312181287666,
      "baseline_run_cnt_delta": 36671,
      "baseline_run_time_ns_delta": 1218622,
      "post_rejit_avg_ns_per_run": 39.71168945258881,
      "post_rejit_run_cnt_delta": 36426,
      "post_rejit_run_time_ns_delta": 1446538,
      "program": "vfs_open",
      "program_id": 25,
      "ratio": 1.1950115490413633,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 28.88704659889035,
      "baseline_run_cnt_delta": 62362,
      "baseline_run_time_ns_delta": 1801454,
      "post_rejit_avg_ns_per_run": 34.51889278042896,
      "post_rejit_run_cnt_delta": 94507,
      "post_rejit_run_time_ns_delta": 3262277,
      "program": "vfs_read",
      "program_id": 26,
      "ratio": 1.19496095463615,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 32.762511901928114,
      "baseline_run_cnt_delta": 134432,
      "baseline_run_time_ns_delta": 4404330,
      "post_rejit_avg_ns_per_run": 34.506859929481344,
      "post_rejit_run_cnt_delta": 140672,
      "post_rejit_run_time_ns_delta": 4854149,
      "program": "vfs_write",
      "program_id": 27,
      "ratio": 1.0532421943950694,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 545.2314814814815,
      "baseline_run_cnt_delta": 108,
      "baseline_run_time_ns_delta": 58885,
      "post_rejit_avg_ns_per_run": 637.3103448275862,
      "post_rejit_run_cnt_delta": 87,
      "post_rejit_run_time_ns_delta": 55446,
      "program": "__x64_sys_open",
      "program_id": 30,
      "ratio": 1.168880313176179,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 649.9852771584532,
      "baseline_run_cnt_delta": 26014,
      "baseline_run_time_ns_delta": 16908717,
      "post_rejit_avg_ns_per_run": 707.7943009795191,
      "post_rejit_run_cnt_delta": 26952,
      "post_rejit_run_time_ns_delta": 19076472,
      "program": "__x64_sys_opena",
      "program_id": 31,
      "ratio": 1.0889389742392168,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 568.125,
      "baseline_run_cnt_delta": 8,
      "baseline_run_time_ns_delta": 4545,
      "post_rejit_avg_ns_per_run": 724.7777777777778,
      "post_rejit_run_cnt_delta": 18,
      "post_rejit_run_time_ns_delta": 13046,
      "program": "__x64_sys_opena",
      "program_id": 32,
      "ratio": 1.2757364625351424,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 59.62333995194875,
      "baseline_run_cnt_delta": 1923363,
      "baseline_run_time_ns_delta": 114677326,
      "post_rejit_avg_ns_per_run": 69.30168498949836,
      "post_rejit_run_cnt_delta": 825109,
      "post_rejit_run_time_ns_delta": 57181444,
      "program": "raw_syscalls__s",
      "program_id": 35,
      "ratio": 1.1623247715634433,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 60.427051467881704,
      "baseline_run_cnt_delta": 1923452,
      "baseline_run_time_ns_delta": 116228533,
      "post_rejit_avg_ns_per_run": 38.16777904495042,
      "post_rejit_run_cnt_delta": 825109,
      "post_rejit_run_time_ns_delta": 31492578,
      "program": "raw_syscalls__s",
      "program_id": 36,
      "ratio": 0.6316339804406547,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 478.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 956,
      "post_rejit_avg_ns_per_run": 659.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 659,
      "program": "trace_connect_e",
      "program_id": 39,
      "ratio": 1.3786610878661087,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 3988.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 7977,
      "post_rejit_avg_ns_per_run": 3185.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 3185,
      "program": "trace_connect_v",
      "program_id": 40,
      "ratio": 0.7985458192302871,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/tcplife",
      "baseline_avg_ns_per_run": 529.75,
      "baseline_run_cnt_delta": 20,
      "baseline_run_time_ns_delta": 10595,
      "post_rejit_avg_ns_per_run": 21.65974897477321,
      "post_rejit_run_cnt_delta": 8047,
      "post_rejit_run_time_ns_delta": 174296,
      "program": "sock__inet_sock",
      "program_id": 44,
      "ratio": 0.04088673709254027,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 138.07672505173895,
      "baseline_run_cnt_delta": 79244,
      "baseline_run_time_ns_delta": 10941752,
      "post_rejit_avg_ns_per_run": 133.5165249219507,
      "post_rejit_run_cnt_delta": 46445,
      "post_rejit_run_time_ns_delta": 6201175,
      "program": "sched_switch",
      "program_id": 47,
      "ratio": 0.9669734335886118,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 100.37056997810552,
      "baseline_run_cnt_delta": 41563,
      "baseline_run_time_ns_delta": 4171702,
      "post_rejit_avg_ns_per_run": 147.2068152981693,
      "post_rejit_run_cnt_delta": 22068,
      "post_rejit_run_time_ns_delta": 3248560,
      "program": "sched_wakeup",
      "program_id": 48,
      "ratio": 1.4666332504665507,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 244.56985294117646,
      "baseline_run_cnt_delta": 544,
      "baseline_run_time_ns_delta": 133046,
      "post_rejit_avg_ns_per_run": 240.30960854092527,
      "post_rejit_run_cnt_delta": 562,
      "post_rejit_run_time_ns_delta": 135054,
      "program": "sched_wakeup_ne",
      "program_id": 49,
      "ratio": 0.9825806641782793,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 3978.3333333333335,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 11935,
      "post_rejit_avg_ns_per_run": 2582.3333333333335,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 7747,
      "program": "tracepoint__sch",
      "program_id": 131,
      "ratio": 0.6490992878089652,
      "runner": "otelcol-ebpf-profiler",
      "type": "tracepoint",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 13952.181818181818,
      "baseline_run_cnt_delta": 66,
      "baseline_run_time_ns_delta": 920844,
      "post_rejit_avg_ns_per_run": 2728.883333333333,
      "post_rejit_run_cnt_delta": 60,
      "post_rejit_run_time_ns_delta": 163733,
      "program": "native_tracer_e",
      "program_id": 132,
      "ratio": 0.19558828639813042,
      "runner": "otelcol-ebpf-profiler",
      "type": "perf_event",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "cilium/agent",
      "baseline_avg_ns_per_run": 208.08833922261485,
      "baseline_run_cnt_delta": 4528,
      "baseline_run_time_ns_delta": 942224,
      "post_rejit_avg_ns_per_run": 153.52118156409273,
      "post_rejit_run_cnt_delta": 18247,
      "post_rejit_run_time_ns_delta": 2801301,
      "program": "cil_from_netdev",
      "program_id": 256,
      "ratio": 0.7377692673103337,
      "runner": "cilium",
      "type": "sched_cls",
      "workload": "network"
    },
    {
      "app": "katran",
      "baseline_avg_ns_per_run": 51.542410714285715,
      "baseline_run_cnt_delta": 1792,
      "baseline_run_time_ns_delta": 92364,
      "post_rejit_avg_ns_per_run": 57.642299107142854,
      "post_rejit_run_cnt_delta": 1792,
      "post_rejit_run_time_ns_delta": 103295,
      "program": "balancer_ingress",
      "program_id": 577,
      "ratio": 1.1183469750119093,
      "runner": "katran",
      "type": "xdp",
      "workload": "test_run"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 113.52455198697942,
      "baseline_run_cnt_delta": 812867,
      "baseline_run_time_ns_delta": 92280362,
      "post_rejit_avg_ns_per_run": 113.54617455341089,
      "post_rejit_run_cnt_delta": 789764,
      "post_rejit_run_time_ns_delta": 89674681,
      "program": "tracepoint__raw",
      "program_id": 594,
      "ratio": 1.0001904659921843,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 205.62924440332935,
      "baseline_run_cnt_delta": 812894,
      "baseline_run_time_ns_delta": 167154779,
      "post_rejit_avg_ns_per_run": 201.7150806371972,
      "post_rejit_run_cnt_delta": 789834,
      "post_rejit_run_time_ns_delta": 159321429,
      "program": "tracepoint__raw",
      "program_id": 597,
      "ratio": 0.9809649460246288,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 247.03448301312133,
      "baseline_run_cnt_delta": 812951,
      "baseline_run_time_ns_delta": 200826930,
      "post_rejit_avg_ns_per_run": 245.8525427248165,
      "post_rejit_run_cnt_delta": 789822,
      "post_rejit_run_time_ns_delta": 194179747,
      "program": "trace_sys_enter",
      "program_id": 600,
      "ratio": 0.99521548460001,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 235.42220440033802,
      "baseline_run_cnt_delta": 812983,
      "baseline_run_time_ns_delta": 191394250,
      "post_rejit_avg_ns_per_run": 234.48296856543476,
      "post_rejit_run_cnt_delta": 789863,
      "post_rejit_run_time_ns_delta": 185209421,
      "program": "trace_sys_exit",
      "program_id": 601,
      "ratio": 0.9960104195044148,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 64.29114814434597,
      "baseline_run_cnt_delta": 263007,
      "baseline_run_time_ns_delta": 16909022,
      "post_rejit_avg_ns_per_run": 64.17837167832035,
      "post_rejit_run_cnt_delta": 263007,
      "post_rejit_run_time_ns_delta": 16879361,
      "program": "trace_arch_prct",
      "program_id": 606,
      "ratio": 0.9982458476900674,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 231.55397384860478,
      "baseline_run_cnt_delta": 263007,
      "baseline_run_time_ns_delta": 60900316,
      "post_rejit_avg_ns_per_run": 234.79609668183735,
      "post_rejit_run_cnt_delta": 263007,
      "post_rejit_run_time_ns_delta": 61753017,
      "program": "trace_ret_arch_",
      "program_id": 607,
      "ratio": 1.0140015858045794,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 374.07142857142856,
      "baseline_run_cnt_delta": 14,
      "baseline_run_time_ns_delta": 5237,
      "post_rejit_avg_ns_per_run": 371.57142857142856,
      "post_rejit_run_cnt_delta": 14,
      "post_rejit_run_time_ns_delta": 5202,
      "program": "trace_dup2",
      "program_id": 610,
      "ratio": 0.9933167844185602,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1224.642857142857,
      "baseline_run_cnt_delta": 14,
      "baseline_run_time_ns_delta": 17145,
      "post_rejit_avg_ns_per_run": 1477.4285714285713,
      "post_rejit_run_cnt_delta": 14,
      "post_rejit_run_time_ns_delta": 20684,
      "program": "trace_ret_dup2",
      "program_id": 611,
      "ratio": 1.2064158646835812,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1523.783037475345,
      "baseline_run_cnt_delta": 1014,
      "baseline_run_time_ns_delta": 1545116,
      "post_rejit_avg_ns_per_run": 1547.621301775148,
      "post_rejit_run_cnt_delta": 1014,
      "post_rejit_run_time_ns_delta": 1569288,
      "program": "tracepoint__sch",
      "program_id": 619,
      "ratio": 1.0156441328676942,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3917.8571428571427,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 27425,
      "post_rejit_avg_ns_per_run": 3586.8571428571427,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 25108,
      "program": "tracepoint__sch",
      "program_id": 627,
      "ratio": 0.9155150410209663,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 566.4142011834319,
      "baseline_run_cnt_delta": 1014,
      "baseline_run_time_ns_delta": 574344,
      "post_rejit_avg_ns_per_run": 594.8343195266273,
      "post_rejit_run_cnt_delta": 1014,
      "post_rejit_run_time_ns_delta": 603162,
      "program": "tracepoint__sch",
      "program_id": 629,
      "ratio": 1.0501755045756551,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 327.99112426035504,
      "baseline_run_cnt_delta": 1014,
      "baseline_run_time_ns_delta": 332583,
      "post_rejit_avg_ns_per_run": 341.4461994076999,
      "post_rejit_run_cnt_delta": 1013,
      "post_rejit_run_time_ns_delta": 345885,
      "program": "tracepoint__sch",
      "program_id": 630,
      "ratio": 1.0410226806523717,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 323.6159792572315,
      "baseline_run_cnt_delta": 103747,
      "baseline_run_time_ns_delta": 33574187,
      "post_rejit_avg_ns_per_run": 320.2722089743745,
      "post_rejit_run_cnt_delta": 82613,
      "post_rejit_run_time_ns_delta": 26458648,
      "program": "tracepoint__sch",
      "program_id": 632,
      "ratio": 0.9896674747318359,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 17.51252276867031,
      "baseline_run_cnt_delta": 4392,
      "baseline_run_time_ns_delta": 76915,
      "post_rejit_avg_ns_per_run": 17.59214501510574,
      "post_rejit_run_cnt_delta": 4634,
      "post_rejit_run_time_ns_delta": 81522,
      "program": "trace_filldir64",
      "program_id": 633,
      "ratio": 1.0045465891743406,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 354.82544378698225,
      "baseline_run_cnt_delta": 1014,
      "baseline_run_time_ns_delta": 359793,
      "post_rejit_avg_ns_per_run": 355.92702169625244,
      "post_rejit_run_cnt_delta": 1014,
      "post_rejit_run_time_ns_delta": 360910,
      "program": "trace_do_exit",
      "program_id": 635,
      "ratio": 1.0031045629014461,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 450.5238095238095,
      "baseline_run_cnt_delta": 21,
      "baseline_run_time_ns_delta": 9461,
      "post_rejit_avg_ns_per_run": 438.3333333333333,
      "post_rejit_run_cnt_delta": 21,
      "post_rejit_run_time_ns_delta": 9205,
      "program": "trace_security_",
      "program_id": 639,
      "ratio": 0.9729415495190783,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2751.5714285714284,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 19261,
      "post_rejit_avg_ns_per_run": 2564.285714285714,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 17950,
      "program": "trace_security_",
      "program_id": 644,
      "ratio": 0.9319349981828565,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 528.4404322377308,
      "baseline_run_cnt_delta": 11105,
      "baseline_run_time_ns_delta": 5868331,
      "post_rejit_avg_ns_per_run": 525.4174696082846,
      "post_rejit_run_cnt_delta": 11105,
      "post_rejit_run_time_ns_delta": 5834761,
      "program": "trace_security_file_open",
      "program_id": 645,
      "ratio": 0.9942794637862111,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1507.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 3014,
      "post_rejit_avg_ns_per_run": 1597.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 3194,
      "program": "trace_security_",
      "program_id": 647,
      "ratio": 1.059721300597213,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 237.05108704002458,
      "baseline_run_cnt_delta": 13017,
      "baseline_run_time_ns_delta": 3085694,
      "post_rejit_avg_ns_per_run": 235.13560623512248,
      "post_rejit_run_cnt_delta": 13023,
      "post_rejit_run_time_ns_delta": 3062171,
      "program": "trace_commit_cr",
      "program_id": 648,
      "ratio": 0.9919195443108063,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 213.39644970414201,
      "baseline_run_cnt_delta": 1014,
      "baseline_run_time_ns_delta": 216384,
      "post_rejit_avg_ns_per_run": 202.7051282051282,
      "post_rejit_run_cnt_delta": 1014,
      "post_rejit_run_time_ns_delta": 205543,
      "program": "trace_switch_ta",
      "program_id": 649,
      "ratio": 0.9498992531795327,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 135.9124505327245,
      "baseline_run_cnt_delta": 98550,
      "baseline_run_time_ns_delta": 13394172,
      "post_rejit_avg_ns_per_run": 135.80492463137142,
      "post_rejit_run_cnt_delta": 97388,
      "post_rejit_run_time_ns_delta": 13225770,
      "program": "trace_cap_capab",
      "program_id": 650,
      "ratio": 0.9992088590785345,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 504.8333333333333,
      "baseline_run_cnt_delta": 36,
      "baseline_run_time_ns_delta": 18174,
      "post_rejit_avg_ns_per_run": 473.7352941176471,
      "post_rejit_run_cnt_delta": 34,
      "post_rejit_run_time_ns_delta": 16107,
      "program": "trace_security_",
      "program_id": 651,
      "ratio": 0.9383993940924009,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 564.9090909090909,
      "baseline_run_cnt_delta": 33,
      "baseline_run_time_ns_delta": 18642,
      "post_rejit_avg_ns_per_run": 543.6176470588235,
      "post_rejit_run_cnt_delta": 34,
      "post_rejit_run_time_ns_delta": 18483,
      "program": "trace_security_",
      "program_id": 657,
      "ratio": 0.9623099642174219,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1869.642857142857,
      "baseline_run_cnt_delta": 14,
      "baseline_run_time_ns_delta": 26175,
      "post_rejit_avg_ns_per_run": 1925.5333333333333,
      "post_rejit_run_cnt_delta": 15,
      "post_rejit_run_time_ns_delta": 28883,
      "program": "trace_security_",
      "program_id": 658,
      "ratio": 1.029893664438077,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 50.88335523040892,
      "baseline_run_cnt_delta": 122543,
      "baseline_run_time_ns_delta": 6235399,
      "post_rejit_avg_ns_per_run": 47.95846313603323,
      "post_rejit_run_cnt_delta": 121338,
      "post_rejit_run_time_ns_delta": 5819184,
      "program": "trace_vfs_write",
      "program_id": 663,
      "ratio": 0.9425177038516573,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 30.403442057073843,
      "baseline_run_cnt_delta": 122543,
      "baseline_run_time_ns_delta": 3725729,
      "post_rejit_avg_ns_per_run": 29.373040597339664,
      "post_rejit_run_cnt_delta": 121338,
      "post_rejit_run_time_ns_delta": 3564066,
      "program": "vfs_write_magic",
      "program_id": 664,
      "ratio": 0.9661090524618926,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 352.7085839256424,
      "baseline_run_cnt_delta": 122543,
      "baseline_run_time_ns_delta": 43221968,
      "post_rejit_avg_ns_per_run": 33.2708580564346,
      "post_rejit_run_cnt_delta": 121344,
      "post_rejit_run_time_ns_delta": 4037219,
      "program": "trace_ret_vfs_w",
      "program_id": 665,
      "ratio": 0.09432959551517102,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 30.017439061212166,
      "baseline_run_cnt_delta": 122541,
      "baseline_run_time_ns_delta": 3678367,
      "post_rejit_avg_ns_per_run": 29.58158430364309,
      "post_rejit_run_cnt_delta": 121353,
      "post_rejit_run_time_ns_delta": 3589814,
      "program": "vfs_write_magic",
      "program_id": 666,
      "ratio": 0.9854799486165269,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 48.75147140028822,
      "baseline_run_cnt_delta": 74249,
      "baseline_run_time_ns_delta": 3619748,
      "post_rejit_avg_ns_per_run": 51.67893438238694,
      "post_rejit_run_cnt_delta": 57957,
      "post_rejit_run_time_ns_delta": 2995156,
      "program": "trace_vfs_read",
      "program_id": 678,
      "ratio": 1.0600487102853149,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 649.9166666666666,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 7799,
      "post_rejit_avg_ns_per_run": 152.9970004285102,
      "post_rejit_run_cnt_delta": 14002,
      "post_rejit_run_time_ns_delta": 2142264,
      "program": "trace_ret_vfs_r",
      "program_id": 679,
      "ratio": 0.2354101814517403,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 122.72988881621976,
      "baseline_run_cnt_delta": 1529,
      "baseline_run_time_ns_delta": 187654,
      "post_rejit_avg_ns_per_run": 114.20502512562814,
      "post_rejit_run_cnt_delta": 995,
      "post_rejit_run_time_ns_delta": 113634,
      "program": "trace_mmap_aler",
      "program_id": 684,
      "ratio": 0.9305396283430432,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 67.64983534577388,
      "baseline_run_cnt_delta": 911,
      "baseline_run_time_ns_delta": 61629,
      "post_rejit_avg_ns_per_run": 58.578485181119646,
      "post_rejit_run_cnt_delta": 911,
      "post_rejit_run_time_ns_delta": 53365,
      "program": "trace_do_mmap",
      "program_id": 685,
      "ratio": 0.8659072839085494,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 511.5137211855104,
      "baseline_run_cnt_delta": 911,
      "baseline_run_time_ns_delta": 465989,
      "post_rejit_avg_ns_per_run": 115.19648737650932,
      "post_rejit_run_cnt_delta": 911,
      "post_rejit_run_time_ns_delta": 104944,
      "program": "trace_ret_do_mm",
      "program_id": 686,
      "ratio": 0.22520703278403567,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 507.0472008781559,
      "baseline_run_cnt_delta": 911,
      "baseline_run_time_ns_delta": 461920,
      "post_rejit_avg_ns_per_run": 468.8781558726674,
      "post_rejit_run_cnt_delta": 911,
      "post_rejit_run_time_ns_delta": 427148,
      "program": "trace_security_mmap_file",
      "program_id": 687,
      "ratio": 0.9247228957395219,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 704.7712765957447,
      "baseline_run_cnt_delta": 188,
      "baseline_run_time_ns_delta": 132497,
      "post_rejit_avg_ns_per_run": 660.9414893617021,
      "post_rejit_run_cnt_delta": 188,
      "post_rejit_run_time_ns_delta": 124257,
      "program": "trace_security_file_mprotect",
      "program_id": 688,
      "ratio": 0.9378099126772682,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 258.70630102574836,
      "baseline_run_cnt_delta": 14331,
      "baseline_run_time_ns_delta": 3707520,
      "post_rejit_avg_ns_per_run": 270.15499629903775,
      "post_rejit_run_cnt_delta": 13510,
      "post_rejit_run_time_ns_delta": 3649794,
      "program": "trace_security_",
      "program_id": 690,
      "ratio": 1.0442536390798998,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 262.9846994535519,
      "baseline_run_cnt_delta": 2745,
      "baseline_run_time_ns_delta": 721893,
      "post_rejit_avg_ns_per_run": 260.34180138568126,
      "post_rejit_run_cnt_delta": 2598,
      "post_rejit_run_time_ns_delta": 676368,
      "program": "trace_security_",
      "program_id": 693,
      "ratio": 0.9899503732598808,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 725.175965665236,
      "baseline_run_cnt_delta": 233,
      "baseline_run_time_ns_delta": 168966,
      "post_rejit_avg_ns_per_run": 741.5800865800866,
      "post_rejit_run_cnt_delta": 231,
      "post_rejit_run_time_ns_delta": 171305,
      "program": "trace_security_",
      "program_id": 694,
      "ratio": 1.022620883332506,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1202.7142857142858,
      "baseline_run_cnt_delta": 14,
      "baseline_run_time_ns_delta": 16838,
      "post_rejit_avg_ns_per_run": 1265.2142857142858,
      "post_rejit_run_cnt_delta": 14,
      "post_rejit_run_time_ns_delta": 17713,
      "program": "trace_load_elf_",
      "program_id": 708,
      "ratio": 1.0519657916617176,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 30.35366712430784,
      "baseline_run_cnt_delta": 197389,
      "baseline_run_time_ns_delta": 5991480,
      "post_rejit_avg_ns_per_run": 30.153057425016254,
      "post_rejit_run_cnt_delta": 179939,
      "post_rejit_run_time_ns_delta": 5425711,
      "program": "trace_security_",
      "program_id": 709,
      "ratio": 0.9933909237895366,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 404.06232023010546,
      "baseline_run_cnt_delta": 1043,
      "baseline_run_time_ns_delta": 421437,
      "post_rejit_avg_ns_per_run": 431.88398849472674,
      "post_rejit_run_cnt_delta": 1043,
      "post_rejit_run_time_ns_delta": 450455,
      "program": "tracepoint__tas",
      "program_id": 710,
      "ratio": 1.068854894088559,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 402.4012345679012,
      "baseline_run_cnt_delta": 2592,
      "baseline_run_time_ns_delta": 1043024,
      "post_rejit_avg_ns_per_run": 396.2511574074074,
      "post_rejit_run_cnt_delta": 2592,
      "post_rejit_run_time_ns_delta": 1027083,
      "program": "trace_do_sigact",
      "program_id": 714,
      "ratio": 0.9847165549402507,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 242.05339575276477,
      "baseline_run_cnt_delta": 14739,
      "baseline_run_time_ns_delta": 3567625,
      "post_rejit_avg_ns_per_run": 235.79404553415063,
      "post_rejit_run_cnt_delta": 14275,
      "post_rejit_run_time_ns_delta": 3365960,
      "program": "trace_fd_instal",
      "program_id": 718,
      "ratio": 0.9741406221583956,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 571.3081446633344,
      "baseline_run_cnt_delta": 3401,
      "baseline_run_time_ns_delta": 1943019,
      "post_rejit_avg_ns_per_run": 591.0667257159729,
      "post_rejit_run_cnt_delta": 3387,
      "post_rejit_run_time_ns_delta": 2001943,
      "program": "trace_filp_clos",
      "program_id": 719,
      "ratio": 1.0345848054805555,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 116.5,
      "baseline_run_cnt_delta": 288,
      "baseline_run_time_ns_delta": 33552,
      "post_rejit_avg_ns_per_run": 102.51712328767124,
      "post_rejit_run_cnt_delta": 292,
      "post_rejit_run_time_ns_delta": 29935,
      "program": "trace_file_upda",
      "program_id": 720,
      "ratio": 0.879975307190311,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 399.4375,
      "baseline_run_cnt_delta": 288,
      "baseline_run_time_ns_delta": 115038,
      "post_rejit_avg_ns_per_run": 39.81164383561644,
      "post_rejit_run_cnt_delta": 292,
      "post_rejit_run_time_ns_delta": 11625,
      "program": "trace_ret_file_",
      "program_id": 721,
      "ratio": 0.09966926949927445,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 81.0,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 567,
      "post_rejit_avg_ns_per_run": 168.71428571428572,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 1181,
      "program": "trace_exec_binp",
      "program_id": 727,
      "ratio": 2.0828924162257496,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2819.4285714285716,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 19736,
      "post_rejit_avg_ns_per_run": 2419.285714285714,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 16935,
      "program": "trace_security_",
      "program_id": 728,
      "ratio": 0.8580766112687475,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3458.285714285714,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 24208,
      "post_rejit_avg_ns_per_run": 3315.714285714286,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 23210,
      "program": "trace_execute_f",
      "program_id": 729,
      "ratio": 0.9587739590218111,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2014.2857142857142,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 14100,
      "post_rejit_avg_ns_per_run": 2447.285714285714,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 17131,
      "program": "trace_set_fs_pw",
      "program_id": 731,
      "ratio": 1.2149645390070922,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 255.74794562240032,
      "baseline_run_cnt_delta": 19714,
      "baseline_run_time_ns_delta": 5041815,
      "post_rejit_avg_ns_per_run": 255.45647763011058,
      "post_rejit_run_cnt_delta": 19714,
      "post_rejit_run_time_ns_delta": 5036069,
      "program": "trace_security_",
      "program_id": 732,
      "ratio": 0.998860331051417,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 270.18988799443775,
      "baseline_run_cnt_delta": 92049,
      "baseline_run_time_ns_delta": 24870709,
      "post_rejit_avg_ns_per_run": 272.39633238818453,
      "post_rejit_run_cnt_delta": 92049,
      "post_rejit_run_time_ns_delta": 25073810,
      "program": "trace_security_task_prctl",
      "program_id": 735,
      "ratio": 1.008166273024223,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 114.83673469387755,
      "baseline_run_cnt_delta": 49,
      "baseline_run_time_ns_delta": 5627,
      "post_rejit_avg_ns_per_run": 87.9795918367347,
      "post_rejit_run_cnt_delta": 49,
      "post_rejit_run_time_ns_delta": 4311,
      "program": "trace_sock_allo",
      "program_id": 738,
      "ratio": 0.7661275990758842,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 508.83673469387753,
      "baseline_run_cnt_delta": 49,
      "baseline_run_time_ns_delta": 24933,
      "post_rejit_avg_ns_per_run": 544.8163265306123,
      "post_rejit_run_cnt_delta": 49,
      "post_rejit_run_time_ns_delta": 26696,
      "program": "trace_ret_sock_",
      "program_id": 739,
      "ratio": 1.0707095014639234,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 496.45454545454544,
      "baseline_run_cnt_delta": 11,
      "baseline_run_time_ns_delta": 5461,
      "post_rejit_avg_ns_per_run": 579.4375,
      "post_rejit_run_cnt_delta": 32,
      "post_rejit_run_time_ns_delta": 18542,
      "program": "trace_security_",
      "program_id": 741,
      "ratio": 1.1671511627906976,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 861.4285714285714,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 6030,
      "post_rejit_avg_ns_per_run": 852.8235294117648,
      "post_rejit_run_cnt_delta": 17,
      "post_rejit_run_time_ns_delta": 14498,
      "program": "trace_security_",
      "program_id": 742,
      "ratio": 0.9900107306604234,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 980.4,
      "baseline_run_cnt_delta": 20,
      "baseline_run_time_ns_delta": 19608,
      "post_rejit_avg_ns_per_run": 658.95,
      "post_rejit_run_cnt_delta": 60,
      "post_rejit_run_time_ns_delta": 39537,
      "program": "cgroup_bpf_run_",
      "program_id": 743,
      "ratio": 0.672123623011016,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 614.0,
      "baseline_run_cnt_delta": 8,
      "baseline_run_time_ns_delta": 4912,
      "post_rejit_avg_ns_per_run": 564.4242424242424,
      "post_rejit_run_cnt_delta": 33,
      "post_rejit_run_time_ns_delta": 18626,
      "program": "cgroup_skb_ingr",
      "program_id": 745,
      "ratio": 0.9192577238179843,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1034.75,
      "baseline_run_cnt_delta": 8,
      "baseline_run_time_ns_delta": 8278,
      "post_rejit_avg_ns_per_run": 641.4242424242424,
      "post_rejit_run_cnt_delta": 33,
      "post_rejit_run_time_ns_delta": 21167,
      "program": "cgroup_skb_egre",
      "program_id": 746,
      "ratio": 0.6198832978248295,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 52.0,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 364,
      "post_rejit_avg_ns_per_run": 35.714285714285715,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 250,
      "program": "empty_kprobe",
      "program_id": 749,
      "ratio": 0.6868131868131868,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 858.5714285714286,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 6010,
      "post_rejit_avg_ns_per_run": 774.8571428571429,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 5424,
      "program": "tracepoint__exe",
      "program_id": 750,
      "ratio": 0.902495840266223,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 232.99576767221973,
      "baseline_run_cnt_delta": 11105,
      "baseline_run_time_ns_delta": 2587418,
      "post_rejit_avg_ns_per_run": 234.05592075641601,
      "post_rejit_run_cnt_delta": 11105,
      "post_rejit_run_time_ns_delta": 2599191,
      "program": "lsm_file_open_t",
      "program_id": 751,
      "ratio": 1.0045500958870965,
      "runner": "tracee",
      "type": "lsm",
      "workload": "stress_ng_os"
    },
    {
      "app": "bpftrace/capable",
      "baseline_avg_ns_per_run": 161.5043926390326,
      "baseline_run_cnt_delta": 98574,
      "baseline_run_time_ns_delta": 15920134,
      "post_rejit_avg_ns_per_run": 168.61468379913515,
      "post_rejit_run_cnt_delta": 97359,
      "post_rejit_run_time_ns_delta": 16416157,
      "program": "cap_capable",
      "program_id": 758,
      "ratio": 1.0440253732045188,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 1407.625,
      "baseline_run_cnt_delta": 8,
      "baseline_run_time_ns_delta": 11261,
      "post_rejit_avg_ns_per_run": 1218.125,
      "post_rejit_run_cnt_delta": 8,
      "post_rejit_run_time_ns_delta": 9745,
      "program": "1",
      "program_id": 771,
      "ratio": 0.8653760767249801,
      "runner": "bpftrace",
      "type": "perf_event",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 37.76227649351559,
      "baseline_run_cnt_delta": 271189,
      "baseline_run_time_ns_delta": 10240714,
      "post_rejit_avg_ns_per_run": 36.233751687622096,
      "post_rejit_run_cnt_delta": 265166,
      "post_rejit_run_time_ns_delta": 9607959,
      "program": "vfs_create",
      "program_id": 772,
      "ratio": 0.9595224401750257,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 110.03719757618647,
      "baseline_run_cnt_delta": 22609,
      "baseline_run_time_ns_delta": 2487831,
      "post_rejit_avg_ns_per_run": 124.93017588472134,
      "post_rejit_run_cnt_delta": 18876,
      "post_rejit_run_time_ns_delta": 2358182,
      "program": "sched_wakeup",
      "program_id": 778,
      "ratio": 1.1353449436789174,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 203.1764705882353,
      "baseline_run_cnt_delta": 544,
      "baseline_run_time_ns_delta": 110528,
      "post_rejit_avg_ns_per_run": 202.431654676259,
      "post_rejit_run_cnt_delta": 556,
      "post_rejit_run_time_ns_delta": 112552,
      "program": "sched_wakeup_ne",
      "program_id": 779,
      "ratio": 0.9963341428767813,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 137.45732499350532,
      "baseline_run_cnt_delta": 50041,
      "baseline_run_time_ns_delta": 6878502,
      "post_rejit_avg_ns_per_run": 148.70083321361872,
      "post_rejit_run_cnt_delta": 41766,
      "post_rejit_run_time_ns_delta": 6210639,
      "program": "sched_switch",
      "program_id": 780,
      "ratio": 1.0817963554917474,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline_avg_ns_per_run": 1475.7,
      "baseline_run_cnt_delta": 10,
      "baseline_run_time_ns_delta": 14757,
      "post_rejit_avg_ns_per_run": 1335.5,
      "post_rejit_run_cnt_delta": 10,
      "post_rejit_run_time_ns_delta": 13355,
      "program": "tcp_set_state",
      "program_id": 787,
      "ratio": 0.9049942400216846,
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
            "avg_ns_per_run": 299.96061106523535,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 60550,
            "run_time_ns_delta": 18162615,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.267902922000019,
            "ops_per_sec": 2502.752628844645,
            "ops_total": 5676.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [3750]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [3750] get                 200      0.60      0.00      0.16       331.18        1203.17\nstress-ng: info:  [3750] skipped: 0\nstress-ng: info:  [3750] passed: 1: get (1)\nstress-ng: info:  [3750] failed: 0\nstress-ng: info:  [3750] metrics untrustworthy: 0\nstress-ng: info:  [3750] successful run completed in 0.61 secs\nstress-ng: info:  [3758] setting to a 1 secs run per stressor\nstress-ng: info:  [3758] dispatching hogs: 1 prctl\nstress-ng: info:  [3758] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [3758] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [3758]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [3758] prctl               452      1.00      0.37      0.09       451.87         973.69\nstress-ng: info:  [3758] skipped: 0\nstress-ng: info:  [3758] passed: 1: prctl (1)\nstress-ng: info:  [3758] failed: 0\nstress-ng: info:  [3758] metrics untrustworthy: 0\nstress-ng: info:  [3758] successful run completed in 1.00 secs\nstress-ng: info:  [4212] setting to a 1 secs run per stressor\nstress-ng: info:  [4212] dispatching hogs: 1 set\nstress-ng: info:  [4212] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4212] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4212]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4212] set                1000      0.31      0.00      0.19      3217.10        5349.02\nstress-ng: info:  [4212] skipped: 0\nstress-ng: info:  [4212] passed: 1: set (1)\nstress-ng: info:  [4212] failed: 0\nstress-ng: info:  [4212] metrics untrustworthy: 0\nstress-ng: info:  [4212] successful run completed in 0.32 secs\nstress-ng: info:  [4214] setting to a 1 secs run per stressor\nstress-ng: info:  [4214] dispatching hogs: 1 timerfd\nstress-ng: info:  [4214] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4214] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4214]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4214] timerfd            1024      0.02      0.00      0.02     41636.06       57098.25\nstress-ng: info:  [4214] skipped: 0\nstress-ng: info:  [4214] passed: 1: timerfd (1)\nstress-ng: info:  [4214] failed: 0\nstress-ng: info:  [4214] metrics untrustworthy: 0\nstress-ng: info:  [4214] successful run completed in 0.05 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 197.45494192012478,
            "bytes_jited": 206,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 97452,
            "run_time_ns_delta": 19242379,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.3564180470000338,
            "ops_per_sec": 4588.5558760925605,
            "ops_total": 6224.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [23635]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23635] get                 200      0.27      0.00      0.11       738.00        1822.27\nstress-ng: info:  [23635] skipped: 0\nstress-ng: info:  [23635] passed: 1: get (1)\nstress-ng: info:  [23635] failed: 0\nstress-ng: info:  [23635] metrics untrustworthy: 0\nstress-ng: info:  [23635] successful run completed in 0.27 secs\nstress-ng: info:  [23637] setting to a 1 secs run per stressor\nstress-ng: info:  [23637] dispatching hogs: 1 prctl\nstress-ng: info:  [23637] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [23637] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23637]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23637] prctl              1000      0.81      0.60      0.17      1241.23        1293.55\nstress-ng: info:  [23637] skipped: 0\nstress-ng: info:  [23637] passed: 1: prctl (1)\nstress-ng: info:  [23637] failed: 0\nstress-ng: info:  [23637] metrics untrustworthy: 0\nstress-ng: info:  [23637] successful run completed in 0.81 secs\nstress-ng: info:  [24640] setting to a 1 secs run per stressor\nstress-ng: info:  [24640] dispatching hogs: 1 set\nstress-ng: info:  [24640] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24640] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24640]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24640] set                1000      0.13      0.00      0.13      7526.52        7590.31\nstress-ng: info:  [24640] skipped: 0\nstress-ng: info:  [24640] passed: 1: set (1)\nstress-ng: info:  [24640] failed: 0\nstress-ng: info:  [24640] metrics untrustworthy: 0\nstress-ng: info:  [24640] successful run completed in 0.13 secs\nstress-ng: info:  [24642] setting to a 1 secs run per stressor\nstress-ng: info:  [24642] dispatching hogs: 1 timerfd\nstress-ng: info:  [24642] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24642] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24642]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24642] timerfd            1024      0.01      0.00      0.01     71127.57       69816.60\nstress-ng: info:  [24642] skipped: 0\nstress-ng: info:  [24642] passed: 1: timerfd (1)\nstress-ng: info:  [24642] failed: 0\nstress-ng: info:  [24642] metrics untrustworthy: 0\nstress-ng: info:  [24642] successful run completed in 0.02 secs"
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
          "9": {
            "avg_ns_per_run": 394.55555555555554,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 3551,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 149.22222222222223,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 1343,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.4263236869999787,
            "ops_per_sec": 3356.6589296967586,
            "ops_total": 11501.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [5080]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5080] sem-sysv           1001      0.01      0.01      0.00     88783.83      137764.93\nstress-ng: info:  [5080] skipped: 0\nstress-ng: info:  [5080] passed: 1: sem-sysv (1)\nstress-ng: info:  [5080] failed: 0\nstress-ng: info:  [5080] metrics untrustworthy: 0\nstress-ng: info:  [5080] successful run completed in 0.03 secs\nstress-ng: info:  [5084] setting to a 1 secs run per stressor\nstress-ng: info:  [5084] dispatching hogs: 1 switch\nstress-ng: info:  [5084] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5084] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5084]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5084] switch             1000      0.07      0.01      0.01     14403.62       84168.00\nstress-ng: info:  [5084] skipped: 0\nstress-ng: info:  [5084] passed: 1: switch (1)\nstress-ng: info:  [5084] failed: 0\nstress-ng: info:  [5084] metrics untrustworthy: 0\nstress-ng: info:  [5084] successful run completed in 0.08 secs\nstress-ng: info:  [5087] setting to a 1 secs run per stressor\nstress-ng: info:  [5087] dispatching hogs: 1 vfork\nstress-ng: info:  [5087] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5087] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5087]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5087] vfork               200      0.08      0.01      0.00      2550.33       25963.91\nstress-ng: info:  [5087] skipped: 0\nstress-ng: info:  [5087] passed: 1: vfork (1)\nstress-ng: info:  [5087] failed: 0\nstress-ng: info:  [5087] metrics untrustworthy: 0\nstress-ng: info:  [5087] successful run completed in 0.08 secs\nstress-ng: info:  [5289] setting to a 1 secs run per stressor\nstress-ng: info:  [5289] dispatching hogs: 1 yield\nstress-ng: info:  [5289] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5289] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5289]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5289] yield              5000      1.00      0.01      0.00      4998.54      314901.12\nstress-ng: info:  [5289] skipped: 0\nstress-ng: info:  [5289] passed: 1: yield (1)\nstress-ng: info:  [5289] failed: 0\nstress-ng: info:  [5289] metrics untrustworthy: 0\nstress-ng: info:  [5289] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 312.0,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 2808,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 185.11111111111111,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_exec",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 1666,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.320167321000099,
            "ops_per_sec": 4956.970083969004,
            "ops_total": 11501.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [25526]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25526] sem-sysv           1001      0.00      0.00      0.00    293745.07      265799.26\nstress-ng: info:  [25526] skipped: 0\nstress-ng: info:  [25526] passed: 1: sem-sysv (1)\nstress-ng: info:  [25526] failed: 0\nstress-ng: info:  [25526] metrics untrustworthy: 0\nstress-ng: info:  [25526] successful run completed in 0.01 secs\nstress-ng: info:  [25530] setting to a 1 secs run per stressor\nstress-ng: info:  [25530] dispatching hogs: 1 switch\nstress-ng: info:  [25530] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25530] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25530]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25530] switch             1000      0.00      0.01      0.00    265933.55      168634.06\nstress-ng: info:  [25530] skipped: 0\nstress-ng: info:  [25530] passed: 1: switch (1)\nstress-ng: info:  [25530] failed: 0\nstress-ng: info:  [25530] metrics untrustworthy: 0\nstress-ng: info:  [25530] successful run completed in 0.01 secs\nstress-ng: info:  [25533] setting to a 1 secs run per stressor\nstress-ng: info:  [25533] dispatching hogs: 1 vfork\nstress-ng: info:  [25533] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25533] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25533]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25533] vfork               200      0.01      0.01      0.00     39098.62       34680.08\nstress-ng: info:  [25533] skipped: 0\nstress-ng: info:  [25533] passed: 1: vfork (1)\nstress-ng: info:  [25533] failed: 0\nstress-ng: info:  [25533] metrics untrustworthy: 0\nstress-ng: info:  [25533] successful run completed in 0.01 secs\nstress-ng: info:  [25735] setting to a 1 secs run per stressor\nstress-ng: info:  [25735] dispatching hogs: 1 yield\nstress-ng: info:  [25735] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25735] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25735]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25735] yield              5000      1.00      0.01      0.00      4997.68      384556.22\nstress-ng: info:  [25735] skipped: 0\nstress-ng: info:  [25735] passed: 1: yield (1)\nstress-ng: info:  [25735] failed: 0\nstress-ng: info:  [25735] metrics untrustworthy: 0\nstress-ng: info:  [25735] successful run completed in 1.00 secs"
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
          "13": {
            "avg_ns_per_run": 773.5,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1547,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 3750.0,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 7500,
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
            "duration_s": 1.8493609610000021,
            "ops_per_sec": 2944.2602687231665,
            "ops_total": 5445.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [5342]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5342] sockdiag           1034      0.00      0.00      0.00   1783269.05     1141280.35\nstress-ng: info:  [5342] skipped: 0\nstress-ng: info:  [5342] passed: 1: sockdiag (1)\nstress-ng: info:  [5342] failed: 0\nstress-ng: info:  [5342] metrics untrustworthy: 0\nstress-ng: info:  [5342] successful run completed in 0.00 secs\nstress-ng: info:  [5344] setting to a 1 secs run per stressor\nstress-ng: info:  [5344] dispatching hogs: 1 sockfd\nstress-ng: info:  [5344] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5344] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5344]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5344] sockfd              200      0.01      0.00      0.00     18413.03       58702.67\nstress-ng: info:  [5344] skipped: 0\nstress-ng: info:  [5344] passed: 1: sockfd (1)\nstress-ng: info:  [5344] failed: 0\nstress-ng: info:  [5344] metrics untrustworthy: 0\nstress-ng: info:  [5344] successful run completed in 0.02 secs\nstress-ng: info:  [5347] setting to a 1 secs run per stressor\nstress-ng: info:  [5347] dispatching hogs: 1 sockpair\nstress-ng: info:  [5347] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5347] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5347]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5347] sockpair            500      0.11      0.00      0.06      4718.47        8149.69\nstress-ng: info:  [5347] skipped: 0\nstress-ng: info:  [5347] passed: 1: sockpair (1)\nstress-ng: info:  [5347] failed: 0\nstress-ng: info:  [5347] metrics untrustworthy: 0\nstress-ng: info:  [5347] successful run completed in 0.13 secs\nstress-ng: info:  [5351] setting to a 1 secs run per stressor\nstress-ng: info:  [5351] dispatching hogs: 1 udp-flood\nstress-ng: info:  [5351] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5351] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5351]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5351] udp-flood          1000      0.02      0.01      0.00     55860.74      111383.38\nstress-ng: info:  [5351] skipped: 0\nstress-ng: info:  [5351] passed: 1: udp-flood (1)\nstress-ng: info:  [5351] failed: 0\nstress-ng: info:  [5351] metrics untrustworthy: 0\nstress-ng: info:  [5351] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 721.5,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1443,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 3452.0,
            "bytes_jited": 719,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_re",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 6904,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_re",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.5284794909999846,
            "ops_per_sec": 3342.5374891078936,
            "ops_total": 5109.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [25780]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25780] sockdiag           1034      0.00      0.00      0.00   2546629.67     1646496.82\nstress-ng: info:  [25780] skipped: 0\nstress-ng: info:  [25780] passed: 1: sockdiag (1)\nstress-ng: info:  [25780] failed: 0\nstress-ng: info:  [25780] metrics untrustworthy: 0\nstress-ng: info:  [25780] successful run completed in 0.00 secs\nstress-ng: info:  [25782] setting to a 1 secs run per stressor\nstress-ng: info:  [25782] dispatching hogs: 1 sockfd\nstress-ng: info:  [25782] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25782] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25782]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25782] sockfd              200      0.00      0.00      0.00     90394.48       81766.15\nstress-ng: info:  [25782] skipped: 0\nstress-ng: info:  [25782] passed: 1: sockfd (1)\nstress-ng: info:  [25782] failed: 0\nstress-ng: info:  [25782] metrics untrustworthy: 0\nstress-ng: info:  [25782] successful run completed in 0.00 secs\nstress-ng: info:  [25785] setting to a 1 secs run per stressor\nstress-ng: info:  [25785] dispatching hogs: 1 sockpair\nstress-ng: info:  [25785] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25785] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25785]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25785] sockpair            500      0.03      0.00      0.03     19961.47       16485.33\nstress-ng: info:  [25785] skipped: 0\nstress-ng: info:  [25785] passed: 1: sockpair (1)\nstress-ng: info:  [25785] failed: 0\nstress-ng: info:  [25785] metrics untrustworthy: 0\nstress-ng: info:  [25785] successful run completed in 0.03 secs\nstress-ng: info:  [25789] setting to a 1 secs run per stressor\nstress-ng: info:  [25789] dispatching hogs: 1 udp-flood\nstress-ng: info:  [25789] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25789] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25789]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25789] udp-flood          1000      0.01      0.00      0.01    184324.50      175901.50\nstress-ng: info:  [25789] skipped: 0\nstress-ng: info:  [25789] passed: 1: udp-flood (1)\nstress-ng: info:  [25789] failed: 0\nstress-ng: info:  [25789] metrics untrustworthy: 0\nstress-ng: info:  [25789] successful run completed in 0.01 secs"
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
          "18": {
            "avg_ns_per_run": 321.60516538104275,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 49522,
            "run_time_ns_delta": 15926531,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 319.5540256803682,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 49532,
            "run_time_ns_delta": 15828150,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 606.90311369744,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 49491,
            "run_time_ns_delta": 30036242,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 18.843825550999952,
            "ops_per_sec": 3478.062340506124,
            "ops_total": 65540.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_us\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 47.030821,\n        \"20\" : 2.087275,\n        \"50\" : 0.524870,\n        \"100\" : 0.439426,\n        \"250\" : 23.039365,\n        \"500\" : 21.684468,\n        \"750\" : 2.532804,\n        \"1000\" : 0.561489\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.585902,\n        \"4\" : 0.500458,\n        \"10\" : 0.665243,\n        \"20\" : 0.280745,\n        \"50\" : 0.042722,\n        \"100\" : 0.024413,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 262.37626854020294,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start",
            "run_cnt_delta": 60207,
            "run_time_ns_delta": 15796888,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 225.08539400481607,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 60215,
            "run_time_ns_delta": 13553517,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 132.52116793170455,
            "bytes_jited": 548,
            "bytes_xlated": 848,
            "id": 20,
            "name": "trace_req_compl",
            "run_cnt_delta": 60209,
            "run_time_ns_delta": 7978967,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 10.224357684999973,
            "ops_per_sec": 8487.476932395703,
            "ops_total": 86779.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_us\" : {\n        \"2\" : 0.000000,\n        \"4\" : 13.197197,\n        \"10\" : 36.360284,\n        \"20\" : 0.442519,\n        \"50\" : 0.032267,\n        \"100\" : 0.013829,\n        \"250\" : 40.836176,\n        \"500\" : 8.592237,\n        \"750\" : 0.391813,\n        \"1000\" : 0.078363\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.036877,\n        \"4\" : 0.018438,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
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
          "23": {
            "avg_ns_per_run": 49.2324661810614,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 4805,
            "run_time_ns_delta": 236562,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": 83.73113207547169,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 212,
            "run_time_ns_delta": 17751,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 33.2312181287666,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 36671,
            "run_time_ns_delta": 1218622,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 28.88704659889035,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 62362,
            "run_time_ns_delta": 1801454,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 32.762511901928114,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 134432,
            "run_time_ns_delta": 4404330,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 11.2978489730001,
            "ops_per_sec": 730.7585735771835,
            "ops_total": 8256.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [7083]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7083] open                100      0.53      0.01      0.00       190.39       14790.71\nstress-ng: info:  [7083] skipped: 0\nstress-ng: info:  [7083] passed: 1: open (1)\nstress-ng: info:  [7083] failed: 0\nstress-ng: info:  [7083] metrics untrustworthy: 0\nstress-ng: info:  [7083] successful run completed in 0.54 secs\nstress-ng: info:  [7085] setting to a 1 secs run per stressor\nstress-ng: info:  [7085] dispatching hogs: 1 rename\nstress-ng: info:  [7085] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7085] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7085]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7085] rename              100      0.98      0.00      0.01       102.08       12422.36\nstress-ng: info:  [7085] skipped: 0\nstress-ng: info:  [7085] passed: 1: rename (1)\nstress-ng: info:  [7085] failed: 0\nstress-ng: info:  [7085] metrics untrustworthy: 0\nstress-ng: info:  [7085] successful run completed in 0.98 secs\nstress-ng: info:  [7087] setting to a 1 secs run per stressor\nstress-ng: info:  [7087] dispatching hogs: 1 touch\nstress-ng: info:  [7087] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7087] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7087]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7087] touch               200      0.03      0.00      0.00      5824.37       27225.70\nstress-ng: info:  [7087] skipped: 0\nstress-ng: info:  [7087] passed: 1: touch (1)\nstress-ng: info:  [7087] failed: 0\nstress-ng: info:  [7087] metrics untrustworthy: 0\nstress-ng: info:  [7087] successful run completed in 0.04 secs\nstress-ng: info:  [7093] setting to a 1 secs run per stressor\nstress-ng: info:  [7093] dispatching hogs: 1 utime\nstress-ng: info:  [7093] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7093] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7093]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7093] utime               200      0.02      0.00      0.02     12987.67       12827.09\nstress-ng: info:  [7093] skipped: 0\nstress-ng: info:  [7093] passed: 1: utime (1)\nstress-ng: info:  [7093] failed: 0\nstress-ng: info:  [7093] metrics untrustworthy: 0\nstress-ng: info:  [7093] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "23": {
            "avg_ns_per_run": 53.34830526096901,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 4809,
            "run_time_ns_delta": 256552,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": 78.44578313253012,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "vfs_fsync_range",
            "run_cnt_delta": 249,
            "run_time_ns_delta": 19533,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 39.71168945258881,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 36426,
            "run_time_ns_delta": 1446538,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 34.51889278042896,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 94507,
            "run_time_ns_delta": 3262277,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 34.506859929481344,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 140672,
            "run_time_ns_delta": 4854149,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 8.067761381999958,
            "ops_per_sec": 1026.8028028794324,
            "ops_total": 8284.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [27515]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [27515] open                100      0.07      0.00      0.01      1395.47       15946.42\nstress-ng: info:  [27515] skipped: 0\nstress-ng: info:  [27515] passed: 1: open (1)\nstress-ng: info:  [27515] failed: 0\nstress-ng: info:  [27515] metrics untrustworthy: 0\nstress-ng: info:  [27515] successful run completed in 0.07 secs\nstress-ng: info:  [27517] setting to a 1 secs run per stressor\nstress-ng: info:  [27517] dispatching hogs: 1 rename\nstress-ng: info:  [27517] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [27517] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [27517]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [27517] rename              100      0.59      0.00      0.01       168.80       16611.30\nstress-ng: info:  [27517] skipped: 0\nstress-ng: info:  [27517] passed: 1: rename (1)\nstress-ng: info:  [27517] failed: 0\nstress-ng: info:  [27517] metrics untrustworthy: 0\nstress-ng: info:  [27517] successful run completed in 0.59 secs\nstress-ng: info:  [27519] setting to a 1 secs run per stressor\nstress-ng: info:  [27519] dispatching hogs: 1 touch\nstress-ng: info:  [27519] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [27519] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [27519]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [27519] touch               202      0.02      0.00      0.01      8110.13       30126.77\nstress-ng: info:  [27519] skipped: 0\nstress-ng: info:  [27519] passed: 1: touch (1)\nstress-ng: info:  [27519] failed: 0\nstress-ng: info:  [27519] metrics untrustworthy: 0\nstress-ng: info:  [27519] successful run completed in 0.03 secs\nstress-ng: info:  [27525] setting to a 1 secs run per stressor\nstress-ng: info:  [27525] dispatching hogs: 1 utime\nstress-ng: info:  [27525] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [27525] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [27525]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [27525] utime               200      0.01      0.00      0.01     16318.98       16030.78\nstress-ng: info:  [27525] skipped: 0\nstress-ng: info:  [27525] passed: 1: utime (1)\nstress-ng: info:  [27525] failed: 0\nstress-ng: info:  [27525] metrics untrustworthy: 0\nstress-ng: info:  [27525] successful run completed in 0.01 secs"
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
          "30": {
            "avg_ns_per_run": 545.2314814814815,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 108,
            "run_time_ns_delta": 58885,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 649.9852771584532,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 26014,
            "run_time_ns_delta": 16908717,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 568.125,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 4545,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 10.489481343999955,
            "ops_per_sec": 783.165509388987,
            "ops_total": 8215.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [8795]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8795] open                100      0.39      0.01      0.00       259.09       13424.62\nstress-ng: info:  [8795] skipped: 0\nstress-ng: info:  [8795] passed: 1: open (1)\nstress-ng: info:  [8795] failed: 0\nstress-ng: info:  [8795] metrics untrustworthy: 0\nstress-ng: info:  [8795] successful run completed in 0.39 secs\nstress-ng: info:  [8797] setting to a 1 secs run per stressor\nstress-ng: info:  [8797] dispatching hogs: 1 rename\nstress-ng: info:  [8797] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8797] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8797]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8797] rename               99      1.01      0.01      0.00        97.79       12690.68\nstress-ng: info:  [8797] skipped: 0\nstress-ng: info:  [8797] passed: 1: rename (1)\nstress-ng: info:  [8797] failed: 0\nstress-ng: info:  [8797] metrics untrustworthy: 0\nstress-ng: info:  [8797] successful run completed in 1.01 secs\nstress-ng: info:  [8799] setting to a 1 secs run per stressor\nstress-ng: info:  [8799] dispatching hogs: 1 touch\nstress-ng: info:  [8799] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8799] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8799]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8799] touch               200      0.03      0.01      0.00      7746.86       24387.27\nstress-ng: info:  [8799] skipped: 0\nstress-ng: info:  [8799] passed: 1: touch (1)\nstress-ng: info:  [8799] failed: 0\nstress-ng: info:  [8799] metrics untrustworthy: 0\nstress-ng: info:  [8799] successful run completed in 0.03 secs\nstress-ng: info:  [8805] setting to a 1 secs run per stressor\nstress-ng: info:  [8805] dispatching hogs: 1 utime\nstress-ng: info:  [8805] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8805] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8805]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8805] utime               200      0.02      0.00      0.02     12687.14       13112.17\nstress-ng: info:  [8805] skipped: 0\nstress-ng: info:  [8805] passed: 1: utime (1)\nstress-ng: info:  [8805] failed: 0\nstress-ng: info:  [8805] metrics untrustworthy: 0\nstress-ng: info:  [8805] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "30": {
            "avg_ns_per_run": 637.3103448275862,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 87,
            "run_time_ns_delta": 55446,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 707.7943009795191,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 26952,
            "run_time_ns_delta": 19076472,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 724.7777777777778,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 18,
            "run_time_ns_delta": 13046,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 8.155175222999901,
            "ops_per_sec": 1015.3062041693547,
            "ops_total": 8280.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [29227]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29227] open                100      0.10      0.00      0.01      1023.53       15330.37\nstress-ng: info:  [29227] skipped: 0\nstress-ng: info:  [29227] passed: 1: open (1)\nstress-ng: info:  [29227] failed: 0\nstress-ng: info:  [29227] metrics untrustworthy: 0\nstress-ng: info:  [29227] successful run completed in 0.10 secs\nstress-ng: info:  [29229] setting to a 1 secs run per stressor\nstress-ng: info:  [29229] dispatching hogs: 1 rename\nstress-ng: info:  [29229] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [29229] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [29229]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29229] rename              100      0.55      0.01      0.00       181.39       14214.64\nstress-ng: info:  [29229] skipped: 0\nstress-ng: info:  [29229] passed: 1: rename (1)\nstress-ng: info:  [29229] failed: 0\nstress-ng: info:  [29229] metrics untrustworthy: 0\nstress-ng: info:  [29229] successful run completed in 0.55 secs\nstress-ng: info:  [29231] setting to a 1 secs run per stressor\nstress-ng: info:  [29231] dispatching hogs: 1 touch\nstress-ng: info:  [29231] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [29231] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [29231]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29231] touch               201      0.02      0.01      0.00      8518.46       28088.32\nstress-ng: info:  [29231] skipped: 0\nstress-ng: info:  [29231] passed: 1: touch (1)\nstress-ng: info:  [29231] failed: 0\nstress-ng: info:  [29231] metrics untrustworthy: 0\nstress-ng: info:  [29231] successful run completed in 0.03 secs\nstress-ng: info:  [29237] setting to a 1 secs run per stressor\nstress-ng: info:  [29237] dispatching hogs: 1 utime\nstress-ng: info:  [29237] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [29237] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [29237]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29237] utime               200      0.01      0.00      0.01     15511.19       15772.87\nstress-ng: info:  [29237] skipped: 0\nstress-ng: info:  [29237] passed: 1: utime (1)\nstress-ng: info:  [29237] failed: 0\nstress-ng: info:  [29237] metrics untrustworthy: 0\nstress-ng: info:  [29237] successful run completed in 0.01 secs"
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
          "35": {
            "avg_ns_per_run": 59.62333995194875,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 1923363,
            "run_time_ns_delta": 114677326,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 60.427051467881704,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 1923452,
            "run_time_ns_delta": 116228533,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 2.3819428379999863,
            "ops_per_sec": 2381.249419386794,
            "ops_total": 5672.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [9263]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9263] get                 200      0.81      0.00      0.15       248.34        1303.78\nstress-ng: info:  [9263] skipped: 0\nstress-ng: info:  [9263] passed: 1: get (1)\nstress-ng: info:  [9263] failed: 0\nstress-ng: info:  [9263] metrics untrustworthy: 0\nstress-ng: info:  [9263] successful run completed in 0.82 secs\nstress-ng: info:  [9265] setting to a 1 secs run per stressor\nstress-ng: info:  [9265] dispatching hogs: 1 prctl\nstress-ng: info:  [9265] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9265] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9265]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9265] prctl               448      1.00      0.34      0.07       446.91        1099.93\nstress-ng: info:  [9265] skipped: 0\nstress-ng: info:  [9265] passed: 1: prctl (1)\nstress-ng: info:  [9265] failed: 0\nstress-ng: info:  [9265] metrics untrustworthy: 0\nstress-ng: info:  [9265] successful run completed in 1.01 secs\nstress-ng: info:  [9715] setting to a 1 secs run per stressor\nstress-ng: info:  [9715] dispatching hogs: 1 set\nstress-ng: info:  [9715] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9715] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9715]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9715] set                1000      0.30      0.00      0.19      3335.43        5388.34\nstress-ng: info:  [9715] skipped: 0\nstress-ng: info:  [9715] passed: 1: set (1)\nstress-ng: info:  [9715] failed: 0\nstress-ng: info:  [9715] metrics untrustworthy: 0\nstress-ng: info:  [9715] successful run completed in 0.31 secs\nstress-ng: info:  [9717] setting to a 1 secs run per stressor\nstress-ng: info:  [9717] dispatching hogs: 1 timerfd\nstress-ng: info:  [9717] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9717] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9717]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9717] timerfd            1024      0.02      0.00      0.02     54192.44       55264.72\nstress-ng: info:  [9717] skipped: 0\nstress-ng: info:  [9717] passed: 1: timerfd (1)\nstress-ng: info:  [9717] failed: 0\nstress-ng: info:  [9717] metrics untrustworthy: 0\nstress-ng: info:  [9717] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 69.30168498949836,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 825109,
            "run_time_ns_delta": 57181444,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 38.16777904495042,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 825109,
            "run_time_ns_delta": 31492578,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.2905017719999705,
            "ops_per_sec": 4822.930223764266,
            "ops_total": 6224.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [30259]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [30259] get                 200      0.26      0.01      0.10       766.83        1829.64\nstress-ng: info:  [30259] skipped: 0\nstress-ng: info:  [30259] passed: 1: get (1)\nstress-ng: info:  [30259] failed: 0\nstress-ng: info:  [30259] metrics untrustworthy: 0\nstress-ng: info:  [30259] successful run completed in 0.26 secs\nstress-ng: info:  [30261] setting to a 1 secs run per stressor\nstress-ng: info:  [30261] dispatching hogs: 1 prctl\nstress-ng: info:  [30261] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [30261] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [30261]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [30261] prctl              1000      0.75      0.58      0.14      1335.84        1379.09\nstress-ng: info:  [30261] skipped: 0\nstress-ng: info:  [30261] passed: 1: prctl (1)\nstress-ng: info:  [30261] failed: 0\nstress-ng: info:  [30261] metrics untrustworthy: 0\nstress-ng: info:  [30261] successful run completed in 0.75 secs\nstress-ng: info:  [31263] setting to a 1 secs run per stressor\nstress-ng: info:  [31263] dispatching hogs: 1 set\nstress-ng: info:  [31263] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31263] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31263]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31263] set                1000      0.13      0.00      0.13      7502.17        7535.91\nstress-ng: info:  [31263] skipped: 0\nstress-ng: info:  [31263] passed: 1: set (1)\nstress-ng: info:  [31263] failed: 0\nstress-ng: info:  [31263] metrics untrustworthy: 0\nstress-ng: info:  [31263] successful run completed in 0.13 secs\nstress-ng: info:  [31265] setting to a 1 secs run per stressor\nstress-ng: info:  [31265] dispatching hogs: 1 timerfd\nstress-ng: info:  [31265] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31265] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31265]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31265] timerfd            1024      0.01      0.00      0.01     70674.62       69588.85\nstress-ng: info:  [31265] skipped: 0\nstress-ng: info:  [31265] passed: 1: timerfd (1)\nstress-ng: info:  [31265] failed: 0\nstress-ng: info:  [31265] metrics untrustworthy: 0\nstress-ng: info:  [31265] successful run completed in 0.02 secs"
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
          "39": {
            "avg_ns_per_run": 478.0,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 956,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 3988.5,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 7977,
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
            "duration_s": 1.724998216999893,
            "ops_per_sec": 3156.525001788067,
            "ops_total": 5445.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [9760]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9760] sockdiag           1034      0.00      0.00      0.00   1721679.37     1199535.96\nstress-ng: info:  [9760] skipped: 0\nstress-ng: info:  [9760] passed: 1: sockdiag (1)\nstress-ng: info:  [9760] failed: 0\nstress-ng: info:  [9760] metrics untrustworthy: 0\nstress-ng: info:  [9760] successful run completed in 0.00 secs\nstress-ng: info:  [9762] setting to a 1 secs run per stressor\nstress-ng: info:  [9762] dispatching hogs: 1 sockfd\nstress-ng: info:  [9762] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9762] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9762]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9762] sockfd              200      0.02      0.00      0.00     12721.96       55944.06\nstress-ng: info:  [9762] skipped: 0\nstress-ng: info:  [9762] passed: 1: sockfd (1)\nstress-ng: info:  [9762] failed: 0\nstress-ng: info:  [9762] metrics untrustworthy: 0\nstress-ng: info:  [9762] successful run completed in 0.02 secs\nstress-ng: info:  [9765] setting to a 1 secs run per stressor\nstress-ng: info:  [9765] dispatching hogs: 1 sockpair\nstress-ng: info:  [9765] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9765] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9765]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9765] sockpair            500      0.06      0.00      0.05      8918.17       10342.33\nstress-ng: info:  [9765] skipped: 0\nstress-ng: info:  [9765] passed: 1: sockpair (1)\nstress-ng: info:  [9765] failed: 0\nstress-ng: info:  [9765] metrics untrustworthy: 0\nstress-ng: info:  [9765] successful run completed in 0.06 secs\nstress-ng: info:  [9769] setting to a 1 secs run per stressor\nstress-ng: info:  [9769] dispatching hogs: 1 udp-flood\nstress-ng: info:  [9769] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9769] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9769]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9769] udp-flood          1000      0.01      0.00      0.01    116359.76      112650.67\nstress-ng: info:  [9769] skipped: 0\nstress-ng: info:  [9769] passed: 1: udp-flood (1)\nstress-ng: info:  [9769] failed: 0\nstress-ng: info:  [9769] metrics untrustworthy: 0\nstress-ng: info:  [9769] successful run completed in 0.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 659.0,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_e",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 659,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 3185.0,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3185,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": null,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.535887460999902,
            "ops_per_sec": 3328.368861525803,
            "ops_total": 5112.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [31302]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31302] sockdiag           1034      0.00      0.00      0.00   2628430.51     1458392.10\nstress-ng: info:  [31302] skipped: 0\nstress-ng: info:  [31302] passed: 1: sockdiag (1)\nstress-ng: info:  [31302] failed: 0\nstress-ng: info:  [31302] metrics untrustworthy: 0\nstress-ng: info:  [31302] successful run completed in 0.00 secs\nstress-ng: info:  [31304] setting to a 1 secs run per stressor\nstress-ng: info:  [31304] dispatching hogs: 1 sockfd\nstress-ng: info:  [31304] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31304] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31304]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31304] sockfd              200      0.00      0.00      0.00     78354.27       74156.47\nstress-ng: info:  [31304] skipped: 0\nstress-ng: info:  [31304] passed: 1: sockfd (1)\nstress-ng: info:  [31304] failed: 0\nstress-ng: info:  [31304] metrics untrustworthy: 0\nstress-ng: info:  [31304] successful run completed in 0.00 secs\nstress-ng: info:  [31307] setting to a 1 secs run per stressor\nstress-ng: info:  [31307] dispatching hogs: 1 sockpair\nstress-ng: info:  [31307] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31307] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31307]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31307] sockpair            500      0.02      0.01      0.02     21838.51       16178.61\nstress-ng: info:  [31307] skipped: 0\nstress-ng: info:  [31307] passed: 1: sockpair (1)\nstress-ng: info:  [31307] failed: 0\nstress-ng: info:  [31307] metrics untrustworthy: 0\nstress-ng: info:  [31307] successful run completed in 0.02 secs\nstress-ng: info:  [31311] setting to a 1 secs run per stressor\nstress-ng: info:  [31311] dispatching hogs: 1 udp-flood\nstress-ng: info:  [31311] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31311] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31311]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31311] udp-flood          1000      0.01      0.00      0.01    182337.26      176616.04\nstress-ng: info:  [31311] skipped: 0\nstress-ng: info:  [31311] passed: 1: udp-flood (1)\nstress-ng: info:  [31311] failed: 0\nstress-ng: info:  [31311] metrics untrustworthy: 0\nstress-ng: info:  [31311] successful run completed in 0.01 secs"
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
          "44": {
            "avg_ns_per_run": 529.75,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 10595,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 2.6066801960000703,
            "ops_per_sec": 2086.5620601814144,
            "ops_total": 5439.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [9810]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9810] sockdiag           1034      0.00      0.00      0.00   1909691.91     1268711.66\nstress-ng: info:  [9810] skipped: 0\nstress-ng: info:  [9810] passed: 1: sockdiag (1)\nstress-ng: info:  [9810] failed: 0\nstress-ng: info:  [9810] metrics untrustworthy: 0\nstress-ng: info:  [9810] successful run completed in 0.00 secs\nstress-ng: info:  [9812] setting to a 1 secs run per stressor\nstress-ng: info:  [9812] dispatching hogs: 1 sockfd\nstress-ng: info:  [9812] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9812] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9812]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9812] sockfd              200      0.01      0.00      0.00     34399.28       51586.28\nstress-ng: info:  [9812] skipped: 0\nstress-ng: info:  [9812] passed: 1: sockfd (1)\nstress-ng: info:  [9812] failed: 0\nstress-ng: info:  [9812] metrics untrustworthy: 0\nstress-ng: info:  [9812] successful run completed in 0.01 secs\nstress-ng: info:  [9815] setting to a 1 secs run per stressor\nstress-ng: info:  [9815] dispatching hogs: 1 sockpair\nstress-ng: info:  [9815] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9815] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9815]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9815] sockpair            500      0.08      0.00      0.06      6251.14        8048.68\nstress-ng: info:  [9815] skipped: 0\nstress-ng: info:  [9815] passed: 1: sockpair (1)\nstress-ng: info:  [9815] failed: 0\nstress-ng: info:  [9815] metrics untrustworthy: 0\nstress-ng: info:  [9815] successful run completed in 0.08 secs\nstress-ng: info:  [9819] setting to a 1 secs run per stressor\nstress-ng: info:  [9819] dispatching hogs: 1 udp-flood\nstress-ng: info:  [9819] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9819] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9819]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9819] udp-flood          1000      0.01      0.00      0.01    115095.33      112183.08\nstress-ng: info:  [9819] skipped: 0\nstress-ng: info:  [9819] passed: 1: udp-flood (1)\nstress-ng: info:  [9819] failed: 0\nstress-ng: info:  [9819] metrics untrustworthy: 0\nstress-ng: info:  [9819] successful run completed in 0.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "44": {
            "avg_ns_per_run": 21.65974897477321,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "sock__inet_sock",
            "run_cnt_delta": 8047,
            "run_time_ns_delta": 174296,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.5573736670000926,
            "ops_per_sec": 3193.8385150567105,
            "ops_total": 4974.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [31348]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31348] sockdiag           1034      0.00      0.00      0.00   2626838.48     1628346.46\nstress-ng: info:  [31348] skipped: 0\nstress-ng: info:  [31348] passed: 1: sockdiag (1)\nstress-ng: info:  [31348] failed: 0\nstress-ng: info:  [31348] metrics untrustworthy: 0\nstress-ng: info:  [31348] successful run completed in 0.00 secs\nstress-ng: info:  [31350] setting to a 1 secs run per stressor\nstress-ng: info:  [31350] dispatching hogs: 1 sockfd\nstress-ng: info:  [31350] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31350] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31350]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31350] sockfd              200      0.00      0.00      0.00     59116.34       54674.69\nstress-ng: info:  [31350] skipped: 0\nstress-ng: info:  [31350] passed: 1: sockfd (1)\nstress-ng: info:  [31350] failed: 0\nstress-ng: info:  [31350] metrics untrustworthy: 0\nstress-ng: info:  [31350] successful run completed in 0.01 secs\nstress-ng: info:  [31353] setting to a 1 secs run per stressor\nstress-ng: info:  [31353] dispatching hogs: 1 sockpair\nstress-ng: info:  [31353] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31353] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31353]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31353] sockpair            500      0.03      0.00      0.03     19976.68       16306.83\nstress-ng: info:  [31353] skipped: 0\nstress-ng: info:  [31353] passed: 1: sockpair (1)\nstress-ng: info:  [31353] failed: 0\nstress-ng: info:  [31353] metrics untrustworthy: 0\nstress-ng: info:  [31353] successful run completed in 0.03 secs\nstress-ng: info:  [31357] setting to a 1 secs run per stressor\nstress-ng: info:  [31357] dispatching hogs: 1 udp-flood\nstress-ng: info:  [31357] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31357] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31357]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31357] udp-flood          1000      0.01      0.01      0.00    185991.93      177493.79\nstress-ng: info:  [31357] skipped: 0\nstress-ng: info:  [31357] passed: 1: udp-flood (1)\nstress-ng: info:  [31357] failed: 0\nstress-ng: info:  [31357] metrics untrustworthy: 0\nstress-ng: info:  [31357] successful run completed in 0.01 secs"
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
          "47": {
            "avg_ns_per_run": 138.07672505173895,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 79244,
            "run_time_ns_delta": 10941752,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 100.37056997810552,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 41563,
            "run_time_ns_delta": 4171702,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 244.56985294117646,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 544,
            "run_time_ns_delta": 133046,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 2.8553102529999705,
            "ops_per_sec": 4027.933562707001,
            "ops_total": 11501.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [10696]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10696] sem-sysv           1001      0.02      0.01      0.00     55495.32      161503.71\nstress-ng: info:  [10696] skipped: 0\nstress-ng: info:  [10696] passed: 1: sem-sysv (1)\nstress-ng: info:  [10696] failed: 0\nstress-ng: info:  [10696] metrics untrustworthy: 0\nstress-ng: info:  [10696] successful run completed in 0.02 secs\nstress-ng: info:  [10700] setting to a 1 secs run per stressor\nstress-ng: info:  [10700] dispatching hogs: 1 switch\nstress-ng: info:  [10700] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10700] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10700]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10700] switch             1000      0.02      0.01      0.00     53368.08      100806.45\nstress-ng: info:  [10700] skipped: 0\nstress-ng: info:  [10700] passed: 1: switch (1)\nstress-ng: info:  [10700] failed: 0\nstress-ng: info:  [10700] metrics untrustworthy: 0\nstress-ng: info:  [10700] successful run completed in 0.02 secs\nstress-ng: info:  [10703] setting to a 1 secs run per stressor\nstress-ng: info:  [10703] dispatching hogs: 1 vfork\nstress-ng: info:  [10703] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10703] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10703]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10703] vfork               200      0.11      0.01      0.00      1790.93       29828.49\nstress-ng: info:  [10703] skipped: 0\nstress-ng: info:  [10703] passed: 1: vfork (1)\nstress-ng: info:  [10703] failed: 0\nstress-ng: info:  [10703] metrics untrustworthy: 0\nstress-ng: info:  [10703] successful run completed in 0.12 secs\nstress-ng: info:  [10905] setting to a 1 secs run per stressor\nstress-ng: info:  [10905] dispatching hogs: 1 yield\nstress-ng: info:  [10905] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10905] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10905]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10905] yield              5000      1.00      0.01      0.00      4998.92      369877.20\nstress-ng: info:  [10905] skipped: 0\nstress-ng: info:  [10905] passed: 1: yield (1)\nstress-ng: info:  [10905] failed: 0\nstress-ng: info:  [10905] metrics untrustworthy: 0\nstress-ng: info:  [10905] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 133.5165249219507,
            "bytes_jited": 645,
            "bytes_xlated": 1136,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 46445,
            "run_time_ns_delta": 6201175,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 147.2068152981693,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 22068,
            "run_time_ns_delta": 3248560,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 240.30960854092527,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 562,
            "run_time_ns_delta": 135054,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 2.3360186060000387,
            "ops_per_sec": 4923.334073821075,
            "ops_total": 11501.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [32241]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [32241] sem-sysv           1001      0.00      0.00      0.00    216618.42      247343.71\nstress-ng: info:  [32241] skipped: 0\nstress-ng: info:  [32241] passed: 1: sem-sysv (1)\nstress-ng: info:  [32241] failed: 0\nstress-ng: info:  [32241] metrics untrustworthy: 0\nstress-ng: info:  [32241] successful run completed in 0.01 secs\nstress-ng: info:  [32245] setting to a 1 secs run per stressor\nstress-ng: info:  [32245] dispatching hogs: 1 switch\nstress-ng: info:  [32245] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [32245] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [32245]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [32245] switch             1000      0.00      0.00      0.00    208319.46      166861.34\nstress-ng: info:  [32245] skipped: 0\nstress-ng: info:  [32245] passed: 1: switch (1)\nstress-ng: info:  [32245] failed: 0\nstress-ng: info:  [32245] metrics untrustworthy: 0\nstress-ng: info:  [32245] successful run completed in 0.01 secs\nstress-ng: info:  [32248] setting to a 1 secs run per stressor\nstress-ng: info:  [32248] dispatching hogs: 1 vfork\nstress-ng: info:  [32248] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [32248] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [32248]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [32248] vfork               200      0.00      0.01      0.00     41068.29       35880.88\nstress-ng: info:  [32248] skipped: 0\nstress-ng: info:  [32248] passed: 1: vfork (1)\nstress-ng: info:  [32248] failed: 0\nstress-ng: info:  [32248] metrics untrustworthy: 0\nstress-ng: info:  [32248] successful run completed in 0.01 secs\nstress-ng: info:  [32450] setting to a 1 secs run per stressor\nstress-ng: info:  [32450] dispatching hogs: 1 yield\nstress-ng: info:  [32450] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [32450] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [32450]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [32450] yield              5000      1.00      0.01      0.00      4999.33      393329.14\nstress-ng: info:  [32450] skipped: 0\nstress-ng: info:  [32450] passed: 1: yield (1)\nstress-ng: info:  [32450] failed: 0\nstress-ng: info:  [32450] metrics untrustworthy: 0\nstress-ng: info:  [32450] successful run completed in 1.00 secs"
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
            "duration_s": 1.113258975000008,
            "ops_per_sec": 718.6108694969149,
            "ops_total": 800.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     8.30ms    7.47ms  41.33ms   83.86%\n    Req/Sec   364.59    186.74   707.00     59.09%\n  800 requests in 1.11s, 121.09KB read\nRequests/sec:    721.90\nTransfer/sec:    109.27KB"
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
            "duration_s": 1.1028676439999572,
            "ops_per_sec": 4499.179957808421,
            "ops_total": 4962.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     1.23ms  686.17us  13.48ms   96.55%\n    Req/Sec     2.38k     0.92k    4.62k    85.71%\n  4962 requests in 1.10s, 751.35KB read\nRequests/sec:   4512.92\nTransfer/sec:    683.35KB"
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
            "avg_ns_per_run": 3978.3333333333335,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 131,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 11935,
            "type": "tracepoint"
          },
          "132": {
            "avg_ns_per_run": 13952.181818181818,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 132,
            "name": "native_tracer_entry",
            "run_cnt_delta": 66,
            "run_time_ns_delta": 920844,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 0.719648879000033,
            "ops_per_sec": 2786.0809048795973,
            "ops_total": 2005.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [12668] setting to a 5 secs run per stressor\nstress-ng: info:  [12668] dispatching hogs: 1 cpu\nstress-ng: info:  [12668] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12668] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12668]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12668] cpu                2005      0.69      0.69      0.00      2895.29        2904.89\nstress-ng: info:  [12668] skipped: 0\nstress-ng: info:  [12668] passed: 1: cpu (1)\nstress-ng: info:  [12668] failed: 0\nstress-ng: info:  [12668] metrics untrustworthy: 0\nstress-ng: info:  [12668] successful run completed in 0.70 secs"
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
            "avg_ns_per_run": 2582.3333333333335,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 131,
            "name": "tracepoint__sch",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 7747,
            "type": "tracepoint"
          },
          "132": {
            "avg_ns_per_run": 2728.883333333333,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 132,
            "name": "native_tracer_e",
            "run_cnt_delta": 60,
            "run_time_ns_delta": 163733,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 0.702037281999992,
            "ops_per_sec": 2855.9736803265996,
            "ops_total": 2005.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [10195] setting to a 5 secs run per stressor\nstress-ng: info:  [10195] dispatching hogs: 1 cpu\nstress-ng: info:  [10195] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10195] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10195]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10195] cpu                2005      0.69      0.69      0.00      2915.45        2915.21\nstress-ng: info:  [10195] skipped: 0\nstress-ng: info:  [10195] passed: 1: cpu (1)\nstress-ng: info:  [10195] failed: 0\nstress-ng: info:  [10195] metrics untrustworthy: 0\nstress-ng: info:  [10195] successful run completed in 0.69 secs"
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
          "237": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 237,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "239": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 239,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "241": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 241,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "242": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 242,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "243": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 243,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "244": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 244,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "245": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 245,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "246": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 246,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "249": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 249,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "251": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 251,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "253": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 253,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "254": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 254,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "256": {
            "avg_ns_per_run": 208.08833922261485,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 256,
            "name": "cil_from_netdev",
            "run_cnt_delta": 4528,
            "run_time_ns_delta": 942224,
            "type": "sched_cls"
          },
          "260": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 260,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1121862640000018,
            "ops_per_sec": 712.1109346842272,
            "ops_total": 792.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     8.39ms    7.23ms  40.58ms   83.05%\n    Req/Sec   362.00    228.97     0.89k    68.18%\n  792 requests in 1.10s, 120.02KB read\nRequests/sec:    719.81\nTransfer/sec:    109.08KB"
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
          "237": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 237,
            "name": "tail_drop_notif",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "239": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 239,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "241": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 241,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "242": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 242,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "243": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 243,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "244": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 244,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "245": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 245,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "246": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 246,
            "name": "tail_drop_notif",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "249": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 249,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "251": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 251,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "253": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 253,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "254": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 254,
            "name": "tail_drop_notif",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "256": {
            "avg_ns_per_run": 153.52118156409273,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 256,
            "name": "cil_from_netdev",
            "run_cnt_delta": 18247,
            "run_time_ns_delta": 2801301,
            "type": "sched_cls"
          },
          "260": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 260,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0047848890000068,
            "ops_per_sec": 3373.856471282956,
            "ops_total": 3390.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     1.52ms    1.05ms  13.48ms   91.54%\n    Req/Sec     1.70k   663.10     2.37k    55.00%\n  3390 requests in 1.00s, 513.27KB read\nRequests/sec:   3385.73\nTransfer/sec:    512.62KB"
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
      "baseline": null,
      "error": "stress_ng_os_io_network workload stressor io timed out",
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
            "avg_ns_per_run": 51.542410714285715,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 577,
            "name": "balancer_ingress",
            "run_cnt_delta": 1792,
            "run_time_ns_delta": 92364,
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
            "duration_s": 1.0098979399999735,
            "ops_per_sec": 1774.4367316959247,
            "ops_total": 1792.0,
            "stderr": "{'retval': 2, 'duration_ns': 142, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
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
            "avg_ns_per_run": 57.642299107142854,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 577,
            "name": "balancer_ingress",
            "run_cnt_delta": 1792,
            "run_time_ns_delta": 103295,
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
            "duration_s": 1.0186864250000554,
            "ops_per_sec": 1759.1281831402657,
            "ops_total": 1792.0,
            "stderr": "{'retval': 2, 'duration_ns': 131, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
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
          "594": {
            "avg_ns_per_run": 113.52455198697942,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 594,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 812867,
            "run_time_ns_delta": 92280362,
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
            "avg_ns_per_run": 205.62924440332935,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 597,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 812894,
            "run_time_ns_delta": 167154779,
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
            "avg_ns_per_run": 247.03448301312133,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 600,
            "name": "trace_sys_enter",
            "run_cnt_delta": 812951,
            "run_time_ns_delta": 200826930,
            "type": "raw_tracepoint"
          },
          "601": {
            "avg_ns_per_run": 235.42220440033802,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 601,
            "name": "trace_sys_exit",
            "run_cnt_delta": 812983,
            "run_time_ns_delta": 191394250,
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
            "avg_ns_per_run": 64.29114814434597,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 606,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 263007,
            "run_time_ns_delta": 16909022,
            "type": "kprobe"
          },
          "607": {
            "avg_ns_per_run": 231.55397384860478,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 607,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 263007,
            "run_time_ns_delta": 60900316,
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
            "avg_ns_per_run": 374.07142857142856,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 610,
            "name": "trace_dup2",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 5237,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": 1224.642857142857,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 611,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 17145,
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
            "avg_ns_per_run": 1523.783037475345,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 619,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 1545116,
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
            "avg_ns_per_run": 3917.8571428571427,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 627,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 27425,
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
            "avg_ns_per_run": 566.4142011834319,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 629,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 574344,
            "type": "raw_tracepoint"
          },
          "630": {
            "avg_ns_per_run": 327.99112426035504,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 630,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 332583,
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
            "avg_ns_per_run": 323.6159792572315,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 632,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 103747,
            "run_time_ns_delta": 33574187,
            "type": "raw_tracepoint"
          },
          "633": {
            "avg_ns_per_run": 17.51252276867031,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 633,
            "name": "trace_filldir64",
            "run_cnt_delta": 4392,
            "run_time_ns_delta": 76915,
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
            "avg_ns_per_run": 354.82544378698225,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 635,
            "name": "trace_do_exit",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 359793,
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
            "avg_ns_per_run": 450.5238095238095,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 639,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 9461,
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
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 642,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "643": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 643,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "644": {
            "avg_ns_per_run": 2751.5714285714284,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 644,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 19261,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": 528.4404322377308,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 645,
            "name": "trace_security_file_open",
            "run_cnt_delta": 11105,
            "run_time_ns_delta": 5868331,
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
            "avg_ns_per_run": 1507.0,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 647,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 3014,
            "type": "kprobe"
          },
          "648": {
            "avg_ns_per_run": 237.05108704002458,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 648,
            "name": "trace_commit_creds",
            "run_cnt_delta": 13017,
            "run_time_ns_delta": 3085694,
            "type": "kprobe"
          },
          "649": {
            "avg_ns_per_run": 213.39644970414201,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 649,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 216384,
            "type": "kprobe"
          },
          "650": {
            "avg_ns_per_run": 135.9124505327245,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 650,
            "name": "trace_cap_capable",
            "run_cnt_delta": 98550,
            "run_time_ns_delta": 13394172,
            "type": "kprobe"
          },
          "651": {
            "avg_ns_per_run": 504.8333333333333,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 651,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 36,
            "run_time_ns_delta": 18174,
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
            "avg_ns_per_run": null,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 656,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "657": {
            "avg_ns_per_run": 564.9090909090909,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 657,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 33,
            "run_time_ns_delta": 18642,
            "type": "kprobe"
          },
          "658": {
            "avg_ns_per_run": 1869.642857142857,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 658,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 26175,
            "type": "kprobe"
          },
          "659": {
            "avg_ns_per_run": 425.6666666666667,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 659,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 1277,
            "type": "kprobe"
          },
          "660": {
            "avg_ns_per_run": null,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 660,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 50.88335523040892,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 663,
            "name": "trace_vfs_write",
            "run_cnt_delta": 122543,
            "run_time_ns_delta": 6235399,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 30.403442057073843,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 664,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 122543,
            "run_time_ns_delta": 3725729,
            "type": "kprobe"
          },
          "665": {
            "avg_ns_per_run": 352.7085839256424,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 665,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 122543,
            "run_time_ns_delta": 43221968,
            "type": "kprobe"
          },
          "666": {
            "avg_ns_per_run": 30.017439061212166,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 666,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 122541,
            "run_time_ns_delta": 3678367,
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
            "avg_ns_per_run": 48.75147140028822,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 678,
            "name": "trace_vfs_read",
            "run_cnt_delta": 74249,
            "run_time_ns_delta": 3619748,
            "type": "kprobe"
          },
          "679": {
            "avg_ns_per_run": 649.9166666666666,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 679,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 7799,
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
            "avg_ns_per_run": 122.72988881621976,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 684,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 1529,
            "run_time_ns_delta": 187654,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 67.64983534577388,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 685,
            "name": "trace_do_mmap",
            "run_cnt_delta": 911,
            "run_time_ns_delta": 61629,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 511.5137211855104,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 686,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 911,
            "run_time_ns_delta": 465989,
            "type": "kprobe"
          },
          "687": {
            "avg_ns_per_run": 507.0472008781559,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 687,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 911,
            "run_time_ns_delta": 461920,
            "type": "kprobe"
          },
          "688": {
            "avg_ns_per_run": 704.7712765957447,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 688,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 188,
            "run_time_ns_delta": 132497,
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
            "avg_ns_per_run": 258.70630102574836,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 690,
            "name": "trace_security_bpf",
            "run_cnt_delta": 14331,
            "run_time_ns_delta": 3707520,
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
            "avg_ns_per_run": 262.9846994535519,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 693,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2745,
            "run_time_ns_delta": 721893,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 725.175965665236,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 694,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 233,
            "run_time_ns_delta": 168966,
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
            "avg_ns_per_run": 1202.7142857142858,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 708,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 16838,
            "type": "kprobe"
          },
          "709": {
            "avg_ns_per_run": 30.35366712430784,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 709,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 197389,
            "run_time_ns_delta": 5991480,
            "type": "kprobe"
          },
          "710": {
            "avg_ns_per_run": 404.06232023010546,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 710,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 1043,
            "run_time_ns_delta": 421437,
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
            "avg_ns_per_run": 402.4012345679012,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 714,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 2592,
            "run_time_ns_delta": 1043024,
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
            "avg_ns_per_run": null,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 717,
            "name": "trace_do_truncate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 242.05339575276477,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 718,
            "name": "trace_fd_install",
            "run_cnt_delta": 14739,
            "run_time_ns_delta": 3567625,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 571.3081446633344,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 719,
            "name": "trace_filp_close",
            "run_cnt_delta": 3401,
            "run_time_ns_delta": 1943019,
            "type": "kprobe"
          },
          "720": {
            "avg_ns_per_run": 116.5,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 720,
            "name": "trace_file_update_time",
            "run_cnt_delta": 288,
            "run_time_ns_delta": 33552,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 399.4375,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 721,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 288,
            "run_time_ns_delta": 115038,
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
            "avg_ns_per_run": 81.0,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 727,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 567,
            "type": "kprobe"
          },
          "728": {
            "avg_ns_per_run": 2819.4285714285716,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 728,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 19736,
            "type": "kprobe"
          },
          "729": {
            "avg_ns_per_run": 3458.285714285714,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 729,
            "name": "trace_execute_finished",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 24208,
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
            "avg_ns_per_run": 2014.2857142857142,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 731,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 14100,
            "type": "kprobe"
          },
          "732": {
            "avg_ns_per_run": 255.74794562240032,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 732,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 19714,
            "run_time_ns_delta": 5041815,
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
            "avg_ns_per_run": 270.18988799443775,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 735,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 92049,
            "run_time_ns_delta": 24870709,
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
            "avg_ns_per_run": 114.83673469387755,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 738,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 5627,
            "type": "kprobe"
          },
          "739": {
            "avg_ns_per_run": 508.83673469387753,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 739,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 24933,
            "type": "kprobe"
          },
          "740": {
            "avg_ns_per_run": null,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 740,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "741": {
            "avg_ns_per_run": 496.45454545454544,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 741,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 11,
            "run_time_ns_delta": 5461,
            "type": "kprobe"
          },
          "742": {
            "avg_ns_per_run": 861.4285714285714,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 742,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 6030,
            "type": "kprobe"
          },
          "743": {
            "avg_ns_per_run": 980.4,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 743,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 19608,
            "type": "kprobe"
          },
          "745": {
            "avg_ns_per_run": 614.0,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 745,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 4912,
            "type": "cgroup_skb"
          },
          "746": {
            "avg_ns_per_run": 1034.75,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 746,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 8278,
            "type": "cgroup_skb"
          },
          "747": {
            "avg_ns_per_run": null,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 747,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "748": {
            "avg_ns_per_run": null,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 748,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "749": {
            "avg_ns_per_run": 52.0,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 749,
            "name": "empty_kprobe",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 364,
            "type": "kprobe"
          },
          "750": {
            "avg_ns_per_run": 858.5714285714286,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 750,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 6010,
            "type": "raw_tracepoint"
          },
          "751": {
            "avg_ns_per_run": 232.99576767221973,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 751,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 11105,
            "run_time_ns_delta": 2587418,
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
            "duration_s": 1.2769238099999711,
            "ops_per_sec": 4874.21406920131,
            "ops_total": 6224.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [16630]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16630] get                 200      0.25      0.01      0.10       795.70        1825.95\nstress-ng: info:  [16630] skipped: 0\nstress-ng: info:  [16630] passed: 1: get (1)\nstress-ng: info:  [16630] failed: 0\nstress-ng: info:  [16630] metrics untrustworthy: 0\nstress-ng: info:  [16630] successful run completed in 0.25 secs\nstress-ng: info:  [16632] setting to a 5 secs run per stressor\nstress-ng: info:  [16632] dispatching hogs: 1 prctl\nstress-ng: info:  [16632] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16632] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16632]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16632] prctl              1000      0.75      0.59      0.15      1337.17        1352.45\nstress-ng: info:  [16632] skipped: 0\nstress-ng: info:  [16632] passed: 1: prctl (1)\nstress-ng: info:  [16632] failed: 0\nstress-ng: info:  [16632] metrics untrustworthy: 0\nstress-ng: info:  [16632] successful run completed in 0.75 secs\nstress-ng: info:  [17634] setting to a 5 secs run per stressor\nstress-ng: info:  [17634] dispatching hogs: 1 set\nstress-ng: info:  [17634] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [17634] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [17634]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [17634] set                1000      0.13      0.00      0.13      7443.02        7433.18\nstress-ng: info:  [17634] skipped: 0\nstress-ng: info:  [17634] passed: 1: set (1)\nstress-ng: info:  [17634] failed: 0\nstress-ng: info:  [17634] metrics untrustworthy: 0\nstress-ng: info:  [17634] successful run completed in 0.14 secs\nstress-ng: info:  [17636] setting to a 5 secs run per stressor\nstress-ng: info:  [17636] dispatching hogs: 1 timerfd\nstress-ng: info:  [17636] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [17636] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [17636]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [17636] timerfd            1024      0.02      0.00      0.02     65546.00       64621.99\nstress-ng: info:  [17636] skipped: 0\nstress-ng: info:  [17636] passed: 1: timerfd (1)\nstress-ng: info:  [17636] failed: 0\nstress-ng: info:  [17636] metrics untrustworthy: 0\nstress-ng: info:  [17636] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "prog 689: BPF_PROG_REJIT: Invalid argument (os error 22)",
      "post_rejit": {
        "bpf": {
          "594": {
            "avg_ns_per_run": 113.54617455341089,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 594,
            "name": "tracepoint__raw",
            "run_cnt_delta": 789764,
            "run_time_ns_delta": 89674681,
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
            "avg_ns_per_run": 201.7150806371972,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 597,
            "name": "tracepoint__raw",
            "run_cnt_delta": 789834,
            "run_time_ns_delta": 159321429,
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
            "avg_ns_per_run": 245.8525427248165,
            "bytes_jited": 8131,
            "bytes_xlated": 13608,
            "id": 600,
            "name": "trace_sys_enter",
            "run_cnt_delta": 789822,
            "run_time_ns_delta": 194179747,
            "type": "raw_tracepoint"
          },
          "601": {
            "avg_ns_per_run": 234.48296856543476,
            "bytes_jited": 8164,
            "bytes_xlated": 13664,
            "id": 601,
            "name": "trace_sys_exit",
            "run_cnt_delta": 789863,
            "run_time_ns_delta": 185209421,
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
            "avg_ns_per_run": 64.17837167832035,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 606,
            "name": "trace_arch_prct",
            "run_cnt_delta": 263007,
            "run_time_ns_delta": 16879361,
            "type": "kprobe"
          },
          "607": {
            "avg_ns_per_run": 234.79609668183735,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 607,
            "name": "trace_ret_arch_",
            "run_cnt_delta": 263007,
            "run_time_ns_delta": 61753017,
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
            "avg_ns_per_run": 371.57142857142856,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 610,
            "name": "trace_dup2",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 5202,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": 1477.4285714285713,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 611,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 20684,
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
            "avg_ns_per_run": 1547.621301775148,
            "bytes_jited": 19847,
            "bytes_xlated": 32320,
            "id": 619,
            "name": "tracepoint__sch",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 1569288,
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
            "avg_ns_per_run": 3586.8571428571427,
            "bytes_jited": 20525,
            "bytes_xlated": 35336,
            "id": 627,
            "name": "tracepoint__sch",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 25108,
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
            "avg_ns_per_run": 594.8343195266273,
            "bytes_jited": 8680,
            "bytes_xlated": 14464,
            "id": 629,
            "name": "tracepoint__sch",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 603162,
            "type": "raw_tracepoint"
          },
          "630": {
            "avg_ns_per_run": 341.4461994076999,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 630,
            "name": "tracepoint__sch",
            "run_cnt_delta": 1013,
            "run_time_ns_delta": 345885,
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
            "avg_ns_per_run": 320.2722089743745,
            "bytes_jited": 8925,
            "bytes_xlated": 14840,
            "id": 632,
            "name": "tracepoint__sch",
            "run_cnt_delta": 82613,
            "run_time_ns_delta": 26458648,
            "type": "raw_tracepoint"
          },
          "633": {
            "avg_ns_per_run": 17.59214501510574,
            "bytes_jited": 8163,
            "bytes_xlated": 13680,
            "id": 633,
            "name": "trace_filldir64",
            "run_cnt_delta": 4634,
            "run_time_ns_delta": 81522,
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
            "avg_ns_per_run": 355.92702169625244,
            "bytes_jited": 7921,
            "bytes_xlated": 13312,
            "id": 635,
            "name": "trace_do_exit",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 360910,
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
            "avg_ns_per_run": 438.3333333333333,
            "bytes_jited": 11470,
            "bytes_xlated": 18264,
            "id": 639,
            "name": "trace_security_",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 9205,
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
            "avg_ns_per_run": null,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 642,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "643": {
            "avg_ns_per_run": null,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 643,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "644": {
            "avg_ns_per_run": 2564.285714285714,
            "bytes_jited": 33373,
            "bytes_xlated": 52824,
            "id": 644,
            "name": "trace_security_",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 17950,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": 525.4174696082846,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 645,
            "name": "trace_security_file_open",
            "run_cnt_delta": 11105,
            "run_time_ns_delta": 5834761,
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
            "avg_ns_per_run": 1597.0,
            "bytes_jited": 9984,
            "bytes_xlated": 16352,
            "id": 647,
            "name": "trace_security_",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 3194,
            "type": "kprobe"
          },
          "648": {
            "avg_ns_per_run": 235.13560623512248,
            "bytes_jited": 10723,
            "bytes_xlated": 16880,
            "id": 648,
            "name": "trace_commit_cr",
            "run_cnt_delta": 13023,
            "run_time_ns_delta": 3062171,
            "type": "kprobe"
          },
          "649": {
            "avg_ns_per_run": 202.7051282051282,
            "bytes_jited": 10045,
            "bytes_xlated": 16520,
            "id": 649,
            "name": "trace_switch_ta",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 205543,
            "type": "kprobe"
          },
          "650": {
            "avg_ns_per_run": 135.80492463137142,
            "bytes_jited": 8174,
            "bytes_xlated": 13680,
            "id": 650,
            "name": "trace_cap_capab",
            "run_cnt_delta": 97388,
            "run_time_ns_delta": 13225770,
            "type": "kprobe"
          },
          "651": {
            "avg_ns_per_run": 473.7352941176471,
            "bytes_jited": 8471,
            "bytes_xlated": 14120,
            "id": 651,
            "name": "trace_security_",
            "run_cnt_delta": 34,
            "run_time_ns_delta": 16107,
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
            "avg_ns_per_run": null,
            "bytes_jited": 10780,
            "bytes_xlated": 16456,
            "id": 656,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "657": {
            "avg_ns_per_run": 543.6176470588235,
            "bytes_jited": 10075,
            "bytes_xlated": 15400,
            "id": 657,
            "name": "trace_security_",
            "run_cnt_delta": 34,
            "run_time_ns_delta": 18483,
            "type": "kprobe"
          },
          "658": {
            "avg_ns_per_run": 1925.5333333333333,
            "bytes_jited": 11260,
            "bytes_xlated": 17192,
            "id": 658,
            "name": "trace_security_",
            "run_cnt_delta": 15,
            "run_time_ns_delta": 28883,
            "type": "kprobe"
          },
          "659": {
            "avg_ns_per_run": null,
            "bytes_jited": 10589,
            "bytes_xlated": 16080,
            "id": 659,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "660": {
            "avg_ns_per_run": 458.7,
            "bytes_jited": 11025,
            "bytes_xlated": 16864,
            "id": 660,
            "name": "trace_security_",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 4587,
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
            "avg_ns_per_run": 47.95846313603323,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 663,
            "name": "trace_vfs_write",
            "run_cnt_delta": 121338,
            "run_time_ns_delta": 5819184,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 29.373040597339664,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 664,
            "name": "vfs_write_magic",
            "run_cnt_delta": 121338,
            "run_time_ns_delta": 3564066,
            "type": "kprobe"
          },
          "665": {
            "avg_ns_per_run": 33.2708580564346,
            "bytes_jited": 19108,
            "bytes_xlated": 31720,
            "id": 665,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 121344,
            "run_time_ns_delta": 4037219,
            "type": "kprobe"
          },
          "666": {
            "avg_ns_per_run": 29.58158430364309,
            "bytes_jited": 23757,
            "bytes_xlated": 36648,
            "id": 666,
            "name": "vfs_write_magic",
            "run_cnt_delta": 121353,
            "run_time_ns_delta": 3589814,
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
            "avg_ns_per_run": 51.67893438238694,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 678,
            "name": "trace_vfs_read",
            "run_cnt_delta": 57957,
            "run_time_ns_delta": 2995156,
            "type": "kprobe"
          },
          "679": {
            "avg_ns_per_run": 152.9970004285102,
            "bytes_jited": 19111,
            "bytes_xlated": 31720,
            "id": 679,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 14002,
            "run_time_ns_delta": 2142264,
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
            "avg_ns_per_run": 114.20502512562814,
            "bytes_jited": 20715,
            "bytes_xlated": 32736,
            "id": 684,
            "name": "trace_mmap_aler",
            "run_cnt_delta": 995,
            "run_time_ns_delta": 113634,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 58.578485181119646,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 685,
            "name": "trace_do_mmap",
            "run_cnt_delta": 911,
            "run_time_ns_delta": 53365,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 115.19648737650932,
            "bytes_jited": 19426,
            "bytes_xlated": 31584,
            "id": 686,
            "name": "trace_ret_do_mm",
            "run_cnt_delta": 911,
            "run_time_ns_delta": 104944,
            "type": "kprobe"
          },
          "687": {
            "avg_ns_per_run": 468.8781558726674,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 687,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 911,
            "run_time_ns_delta": 427148,
            "type": "kprobe"
          },
          "688": {
            "avg_ns_per_run": 660.9414893617021,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 688,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 188,
            "run_time_ns_delta": 124257,
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
            "avg_ns_per_run": 270.15499629903775,
            "bytes_jited": 15585,
            "bytes_xlated": 26904,
            "id": 690,
            "name": "trace_security_",
            "run_cnt_delta": 13510,
            "run_time_ns_delta": 3649794,
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
            "avg_ns_per_run": 260.34180138568126,
            "bytes_jited": 8333,
            "bytes_xlated": 13904,
            "id": 693,
            "name": "trace_security_",
            "run_cnt_delta": 2598,
            "run_time_ns_delta": 676368,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 741.5800865800866,
            "bytes_jited": 9581,
            "bytes_xlated": 15448,
            "id": 694,
            "name": "trace_security_",
            "run_cnt_delta": 231,
            "run_time_ns_delta": 171305,
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
            "avg_ns_per_run": 1265.2142857142858,
            "bytes_jited": 18482,
            "bytes_xlated": 30352,
            "id": 708,
            "name": "trace_load_elf_",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 17713,
            "type": "kprobe"
          },
          "709": {
            "avg_ns_per_run": 30.153057425016254,
            "bytes_jited": 8681,
            "bytes_xlated": 14496,
            "id": 709,
            "name": "trace_security_",
            "run_cnt_delta": 179939,
            "run_time_ns_delta": 5425711,
            "type": "kprobe"
          },
          "710": {
            "avg_ns_per_run": 431.88398849472674,
            "bytes_jited": 8474,
            "bytes_xlated": 14112,
            "id": 710,
            "name": "tracepoint__tas",
            "run_cnt_delta": 1043,
            "run_time_ns_delta": 450455,
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
            "avg_ns_per_run": 396.2511574074074,
            "bytes_jited": 10109,
            "bytes_xlated": 16296,
            "id": 714,
            "name": "trace_do_sigact",
            "run_cnt_delta": 2592,
            "run_time_ns_delta": 1027083,
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
            "avg_ns_per_run": null,
            "bytes_jited": 9530,
            "bytes_xlated": 15824,
            "id": 717,
            "name": "trace_do_trunca",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 235.79404553415063,
            "bytes_jited": 16708,
            "bytes_xlated": 27176,
            "id": 718,
            "name": "trace_fd_instal",
            "run_cnt_delta": 14275,
            "run_time_ns_delta": 3365960,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 591.0667257159729,
            "bytes_jited": 16636,
            "bytes_xlated": 27024,
            "id": 719,
            "name": "trace_filp_clos",
            "run_cnt_delta": 3387,
            "run_time_ns_delta": 2001943,
            "type": "kprobe"
          },
          "720": {
            "avg_ns_per_run": 102.51712328767124,
            "bytes_jited": 459,
            "bytes_xlated": 768,
            "id": 720,
            "name": "trace_file_upda",
            "run_cnt_delta": 292,
            "run_time_ns_delta": 29935,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 39.81164383561644,
            "bytes_jited": 20054,
            "bytes_xlated": 31168,
            "id": 721,
            "name": "trace_ret_file_",
            "run_cnt_delta": 292,
            "run_time_ns_delta": 11625,
            "type": "kprobe"
          },
          "722": {
            "avg_ns_per_run": 204.33333333333334,
            "bytes_jited": 459,
            "bytes_xlated": 768,
            "id": 722,
            "name": "trace_file_modi",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 1226,
            "type": "kprobe"
          },
          "723": {
            "avg_ns_per_run": 269.0,
            "bytes_jited": 20140,
            "bytes_xlated": 31288,
            "id": 723,
            "name": "trace_ret_file_",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 1614,
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
            "avg_ns_per_run": 168.71428571428572,
            "bytes_jited": 16472,
            "bytes_xlated": 28872,
            "id": 727,
            "name": "trace_exec_binp",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 1181,
            "type": "kprobe"
          },
          "728": {
            "avg_ns_per_run": 2419.285714285714,
            "bytes_jited": 16702,
            "bytes_xlated": 29144,
            "id": 728,
            "name": "trace_security_",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 16935,
            "type": "kprobe"
          },
          "729": {
            "avg_ns_per_run": 3315.714285714286,
            "bytes_jited": 24469,
            "bytes_xlated": 38320,
            "id": 729,
            "name": "trace_execute_f",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 23210,
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
            "avg_ns_per_run": 2447.285714285714,
            "bytes_jited": 18194,
            "bytes_xlated": 29912,
            "id": 731,
            "name": "trace_set_fs_pw",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 17131,
            "type": "kprobe"
          },
          "732": {
            "avg_ns_per_run": 255.45647763011058,
            "bytes_jited": 8631,
            "bytes_xlated": 14360,
            "id": 732,
            "name": "trace_security_",
            "run_cnt_delta": 19714,
            "run_time_ns_delta": 5036069,
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
            "avg_ns_per_run": 272.39633238818453,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 735,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 92049,
            "run_time_ns_delta": 25073810,
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
            "avg_ns_per_run": 87.9795918367347,
            "bytes_jited": 329,
            "bytes_xlated": 520,
            "id": 738,
            "name": "trace_sock_allo",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 4311,
            "type": "kprobe"
          },
          "739": {
            "avg_ns_per_run": 544.8163265306123,
            "bytes_jited": 8439,
            "bytes_xlated": 12928,
            "id": 739,
            "name": "trace_ret_sock_",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 26696,
            "type": "kprobe"
          },
          "740": {
            "avg_ns_per_run": 230.0,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 740,
            "name": "trace_security_",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 230,
            "type": "kprobe"
          },
          "741": {
            "avg_ns_per_run": 579.4375,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 741,
            "name": "trace_security_",
            "run_cnt_delta": 32,
            "run_time_ns_delta": 18542,
            "type": "kprobe"
          },
          "742": {
            "avg_ns_per_run": 852.8235294117648,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 742,
            "name": "trace_security_",
            "run_cnt_delta": 17,
            "run_time_ns_delta": 14498,
            "type": "kprobe"
          },
          "743": {
            "avg_ns_per_run": 658.95,
            "bytes_jited": 5282,
            "bytes_xlated": 8136,
            "id": 743,
            "name": "cgroup_bpf_run_",
            "run_cnt_delta": 60,
            "run_time_ns_delta": 39537,
            "type": "kprobe"
          },
          "745": {
            "avg_ns_per_run": 564.4242424242424,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 745,
            "name": "cgroup_skb_ingr",
            "run_cnt_delta": 33,
            "run_time_ns_delta": 18626,
            "type": "cgroup_skb"
          },
          "746": {
            "avg_ns_per_run": 641.4242424242424,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 746,
            "name": "cgroup_skb_egre",
            "run_cnt_delta": 33,
            "run_time_ns_delta": 21167,
            "type": "cgroup_skb"
          },
          "747": {
            "avg_ns_per_run": null,
            "bytes_jited": 916,
            "bytes_xlated": 1560,
            "id": 747,
            "name": "cgroup_mkdir_si",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "748": {
            "avg_ns_per_run": null,
            "bytes_jited": 898,
            "bytes_xlated": 1520,
            "id": 748,
            "name": "cgroup_rmdir_si",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "749": {
            "avg_ns_per_run": 35.714285714285715,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 749,
            "name": "empty_kprobe",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 250,
            "type": "kprobe"
          },
          "750": {
            "avg_ns_per_run": 774.8571428571429,
            "bytes_jited": 58660,
            "bytes_xlated": 95944,
            "id": 750,
            "name": "tracepoint__exe",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 5424,
            "type": "raw_tracepoint"
          },
          "751": {
            "avg_ns_per_run": 234.05592075641601,
            "bytes_jited": 7290,
            "bytes_xlated": 13264,
            "id": 751,
            "name": "lsm_file_open_t",
            "run_cnt_delta": 11105,
            "run_time_ns_delta": 2599191,
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
            "duration_s": 1.2819643699999688,
            "ops_per_sec": 4855.049130577749,
            "ops_total": 6224.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [19639]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19639] get                 200      0.26      0.02      0.09       780.22        1806.41\nstress-ng: info:  [19639] skipped: 0\nstress-ng: info:  [19639] passed: 1: get (1)\nstress-ng: info:  [19639] failed: 0\nstress-ng: info:  [19639] metrics untrustworthy: 0\nstress-ng: info:  [19639] successful run completed in 0.26 secs\nstress-ng: info:  [19641] setting to a 5 secs run per stressor\nstress-ng: info:  [19641] dispatching hogs: 1 prctl\nstress-ng: info:  [19641] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19641] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19641]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19641] prctl              1000      0.75      0.58      0.15      1331.81        1359.21\nstress-ng: info:  [19641] skipped: 0\nstress-ng: info:  [19641] passed: 1: prctl (1)\nstress-ng: info:  [19641] failed: 0\nstress-ng: info:  [19641] metrics untrustworthy: 0\nstress-ng: info:  [19641] successful run completed in 0.75 secs\nstress-ng: info:  [20645] setting to a 5 secs run per stressor\nstress-ng: info:  [20645] dispatching hogs: 1 set\nstress-ng: info:  [20645] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [20645] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [20645]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [20645] set                1000      0.13      0.01      0.12      7533.29        7538.75\nstress-ng: info:  [20645] skipped: 0\nstress-ng: info:  [20645] passed: 1: set (1)\nstress-ng: info:  [20645] failed: 0\nstress-ng: info:  [20645] metrics untrustworthy: 0\nstress-ng: info:  [20645] successful run completed in 0.13 secs\nstress-ng: info:  [20647] setting to a 5 secs run per stressor\nstress-ng: info:  [20647] dispatching hogs: 1 timerfd\nstress-ng: info:  [20647] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [20647] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [20647]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [20647] timerfd            1024      0.01      0.00      0.01     70984.16       69731.02\nstress-ng: info:  [20647] skipped: 0\nstress-ng: info:  [20647] passed: 1: timerfd (1)\nstress-ng: info:  [20647] failed: 0\nstress-ng: info:  [20647] metrics untrustworthy: 0\nstress-ng: info:  [20647] successful run completed in 0.02 secs"
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
          "758": {
            "avg_ns_per_run": 161.5043926390326,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 758,
            "name": "cap_capable",
            "run_cnt_delta": 98574,
            "run_time_ns_delta": 15920134,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.2787013789999264,
            "ops_per_sec": 4867.438248066797,
            "ops_total": 6224.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [18658]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18658] get                 200      0.26      0.01      0.10       765.31        1809.17\nstress-ng: info:  [18658] skipped: 0\nstress-ng: info:  [18658] passed: 1: get (1)\nstress-ng: info:  [18658] failed: 0\nstress-ng: info:  [18658] metrics untrustworthy: 0\nstress-ng: info:  [18658] successful run completed in 0.26 secs\nstress-ng: info:  [18660] setting to a 1 secs run per stressor\nstress-ng: info:  [18660] dispatching hogs: 1 prctl\nstress-ng: info:  [18660] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18660] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18660]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18660] prctl              1000      0.75      0.58      0.15      1340.64        1355.78\nstress-ng: info:  [18660] skipped: 0\nstress-ng: info:  [18660] passed: 1: prctl (1)\nstress-ng: info:  [18660] failed: 0\nstress-ng: info:  [18660] metrics untrustworthy: 0\nstress-ng: info:  [18660] successful run completed in 0.75 secs\nstress-ng: info:  [19662] setting to a 1 secs run per stressor\nstress-ng: info:  [19662] dispatching hogs: 1 set\nstress-ng: info:  [19662] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19662] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19662]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19662] set                1000      0.13      0.00      0.13      7576.36        7580.70\nstress-ng: info:  [19662] skipped: 0\nstress-ng: info:  [19662] passed: 1: set (1)\nstress-ng: info:  [19662] failed: 0\nstress-ng: info:  [19662] metrics untrustworthy: 0\nstress-ng: info:  [19662] successful run completed in 0.13 secs\nstress-ng: info:  [19664] setting to a 1 secs run per stressor\nstress-ng: info:  [19664] dispatching hogs: 1 timerfd\nstress-ng: info:  [19664] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19664] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19664]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19664] timerfd            1024      0.01      0.00      0.01     70716.51       69339.11\nstress-ng: info:  [19664] skipped: 0\nstress-ng: info:  [19664] passed: 1: timerfd (1)\nstress-ng: info:  [19664] failed: 0\nstress-ng: info:  [19664] metrics untrustworthy: 0\nstress-ng: info:  [19664] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "758": {
            "avg_ns_per_run": 168.61468379913515,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 758,
            "name": "cap_capable",
            "run_cnt_delta": 97359,
            "run_time_ns_delta": 16416157,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.2716038639999852,
            "ops_per_sec": 4894.606076786877,
            "ops_total": 6224.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [21670]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21670] get                 200      0.25      0.00      0.11       786.61        1788.46\nstress-ng: info:  [21670] skipped: 0\nstress-ng: info:  [21670] passed: 1: get (1)\nstress-ng: info:  [21670] failed: 0\nstress-ng: info:  [21670] metrics untrustworthy: 0\nstress-ng: info:  [21670] successful run completed in 0.26 secs\nstress-ng: info:  [21672] setting to a 1 secs run per stressor\nstress-ng: info:  [21672] dispatching hogs: 1 prctl\nstress-ng: info:  [21672] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21672] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21672]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21672] prctl              1000      0.75      0.58      0.14      1339.32        1386.54\nstress-ng: info:  [21672] skipped: 0\nstress-ng: info:  [21672] passed: 1: prctl (1)\nstress-ng: info:  [21672] failed: 0\nstress-ng: info:  [21672] metrics untrustworthy: 0\nstress-ng: info:  [21672] successful run completed in 0.75 secs\nstress-ng: info:  [22674] setting to a 1 secs run per stressor\nstress-ng: info:  [22674] dispatching hogs: 1 set\nstress-ng: info:  [22674] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22674] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22674]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22674] set                1000      0.13      0.00      0.13      7533.06        7566.24\nstress-ng: info:  [22674] skipped: 0\nstress-ng: info:  [22674] passed: 1: set (1)\nstress-ng: info:  [22674] failed: 0\nstress-ng: info:  [22674] metrics untrustworthy: 0\nstress-ng: info:  [22674] successful run completed in 0.13 secs\nstress-ng: info:  [22676] setting to a 1 secs run per stressor\nstress-ng: info:  [22676] dispatching hogs: 1 timerfd\nstress-ng: info:  [22676] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22676] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22676]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22676] timerfd            1024      0.01      0.00      0.01     70068.15       69189.19\nstress-ng: info:  [22676] skipped: 0\nstress-ng: info:  [22676] passed: 1: timerfd (1)\nstress-ng: info:  [22676] failed: 0\nstress-ng: info:  [22676] metrics untrustworthy: 0\nstress-ng: info:  [22676] successful run completed in 0.02 secs"
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
      "baseline": null,
      "error": "Command '['/usr/bin/fio', '--name=bench', '--rw=randrw', '--bs=4k', '--size=64M', '--numjobs=4', '--runtime=5', '--time_based', '--ioengine=sync', '--output-format=json']' timed out after 65.0 seconds",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bpftrace",
      "selected_workload": "fio_randrw",
      "status": "error"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline": {
        "bpf": {
          "771": {
            "avg_ns_per_run": 1407.625,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 771,
            "name": "1",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 11261,
            "type": "perf_event"
          },
          "772": {
            "avg_ns_per_run": 37.76227649351559,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 772,
            "name": "vfs_create",
            "run_cnt_delta": 271189,
            "run_time_ns_delta": 10240714,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 8.48074890700002,
            "ops_per_sec": 972.5556186661877,
            "ops_total": 8248.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [21412]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21412] open                100      0.34      0.00      0.01       289.90       15905.84\nstress-ng: info:  [21412] skipped: 0\nstress-ng: info:  [21412] passed: 1: open (1)\nstress-ng: info:  [21412] failed: 0\nstress-ng: info:  [21412] metrics untrustworthy: 0\nstress-ng: info:  [21412] successful run completed in 0.35 secs\nstress-ng: info:  [21414] setting to a 1 secs run per stressor\nstress-ng: info:  [21414] dispatching hogs: 1 rename\nstress-ng: info:  [21414] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21414] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21414]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21414] rename              100      0.65      0.01      0.00       152.73       15979.55\nstress-ng: info:  [21414] skipped: 0\nstress-ng: info:  [21414] passed: 1: rename (1)\nstress-ng: info:  [21414] failed: 0\nstress-ng: info:  [21414] metrics untrustworthy: 0\nstress-ng: info:  [21414] successful run completed in 0.66 secs\nstress-ng: info:  [21416] setting to a 1 secs run per stressor\nstress-ng: info:  [21416] dispatching hogs: 1 touch\nstress-ng: info:  [21416] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21416] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21416]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21416] touch               203      0.03      0.01      0.00      6306.48       31429.01\nstress-ng: info:  [21416] skipped: 0\nstress-ng: info:  [21416] passed: 1: touch (1)\nstress-ng: info:  [21416] failed: 0\nstress-ng: info:  [21416] metrics untrustworthy: 0\nstress-ng: info:  [21416] successful run completed in 0.03 secs\nstress-ng: info:  [21422] setting to a 1 secs run per stressor\nstress-ng: info:  [21422] dispatching hogs: 1 utime\nstress-ng: info:  [21422] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21422] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21422]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21422] utime               200      0.01      0.00      0.01     16078.14       15827.79\nstress-ng: info:  [21422] skipped: 0\nstress-ng: info:  [21422] passed: 1: utime (1)\nstress-ng: info:  [21422] failed: 0\nstress-ng: info:  [21422] metrics untrustworthy: 0\nstress-ng: info:  [21422] successful run completed in 0.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "771": {
            "avg_ns_per_run": 1218.125,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 771,
            "name": "1",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 9745,
            "type": "perf_event"
          },
          "772": {
            "avg_ns_per_run": 36.233751687622096,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 772,
            "name": "vfs_create",
            "run_cnt_delta": 265166,
            "run_time_ns_delta": 9607959,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 8.03151616799994,
            "ops_per_sec": 1030.5650672756092,
            "ops_total": 8277.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [24391]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24391] open                100      0.07      0.01      0.00      1504.74       15931.18\nstress-ng: info:  [24391] skipped: 0\nstress-ng: info:  [24391] passed: 1: open (1)\nstress-ng: info:  [24391] failed: 0\nstress-ng: info:  [24391] metrics untrustworthy: 0\nstress-ng: info:  [24391] successful run completed in 0.07 secs\nstress-ng: info:  [24393] setting to a 1 secs run per stressor\nstress-ng: info:  [24393] dispatching hogs: 1 rename\nstress-ng: info:  [24393] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24393] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24393]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24393] rename              100      0.60      0.01      0.00       167.73       15595.76\nstress-ng: info:  [24393] skipped: 0\nstress-ng: info:  [24393] passed: 1: rename (1)\nstress-ng: info:  [24393] failed: 0\nstress-ng: info:  [24393] metrics untrustworthy: 0\nstress-ng: info:  [24393] successful run completed in 0.60 secs\nstress-ng: info:  [24395] setting to a 1 secs run per stressor\nstress-ng: info:  [24395] dispatching hogs: 1 touch\nstress-ng: info:  [24395] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24395] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24395]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24395] touch               201      0.03      0.01      0.00      7300.38       28442.05\nstress-ng: info:  [24395] skipped: 0\nstress-ng: info:  [24395] passed: 1: touch (1)\nstress-ng: info:  [24395] failed: 0\nstress-ng: info:  [24395] metrics untrustworthy: 0\nstress-ng: info:  [24395] successful run completed in 0.03 secs\nstress-ng: info:  [24407] setting to a 1 secs run per stressor\nstress-ng: info:  [24407] dispatching hogs: 1 utime\nstress-ng: info:  [24407] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24407] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24407]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24407] utime               200      0.01      0.00      0.01     15818.61       15680.13\nstress-ng: info:  [24407] skipped: 0\nstress-ng: info:  [24407] passed: 1: utime (1)\nstress-ng: info:  [24407] failed: 0\nstress-ng: info:  [24407] metrics untrustworthy: 0\nstress-ng: info:  [24407] successful run completed in 0.01 secs"
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
          "778": {
            "avg_ns_per_run": 110.03719757618647,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 778,
            "name": "sched_wakeup",
            "run_cnt_delta": 22609,
            "run_time_ns_delta": 2487831,
            "type": "tracepoint"
          },
          "779": {
            "avg_ns_per_run": 203.1764705882353,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 779,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 544,
            "run_time_ns_delta": 110528,
            "type": "tracepoint"
          },
          "780": {
            "avg_ns_per_run": 137.45732499350532,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 780,
            "name": "sched_switch",
            "run_cnt_delta": 50041,
            "run_time_ns_delta": 6878502,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 2.335919972999932,
            "ops_per_sec": 4923.541959029405,
            "ops_total": 11501.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [22281]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22281] sem-sysv           1001      0.00      0.00      0.00    206324.55      170586.23\nstress-ng: info:  [22281] skipped: 0\nstress-ng: info:  [22281] passed: 1: sem-sysv (1)\nstress-ng: info:  [22281] failed: 0\nstress-ng: info:  [22281] metrics untrustworthy: 0\nstress-ng: info:  [22281] successful run completed in 0.01 secs\nstress-ng: info:  [22285] setting to a 1 secs run per stressor\nstress-ng: info:  [22285] dispatching hogs: 1 switch\nstress-ng: info:  [22285] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22285] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22285]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22285] switch             1000      0.00      0.01      0.00    232139.92      157853.20\nstress-ng: info:  [22285] skipped: 0\nstress-ng: info:  [22285] passed: 1: switch (1)\nstress-ng: info:  [22285] failed: 0\nstress-ng: info:  [22285] metrics untrustworthy: 0\nstress-ng: info:  [22285] successful run completed in 0.01 secs\nstress-ng: info:  [22288] setting to a 1 secs run per stressor\nstress-ng: info:  [22288] dispatching hogs: 1 vfork\nstress-ng: info:  [22288] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22288] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22288]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22288] vfork               200      0.00      0.01      0.00     41343.56       36049.03\nstress-ng: info:  [22288] skipped: 0\nstress-ng: info:  [22288] passed: 1: vfork (1)\nstress-ng: info:  [22288] failed: 0\nstress-ng: info:  [22288] metrics untrustworthy: 0\nstress-ng: info:  [22288] successful run completed in 0.01 secs\nstress-ng: info:  [22490] setting to a 1 secs run per stressor\nstress-ng: info:  [22490] dispatching hogs: 1 yield\nstress-ng: info:  [22490] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22490] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22490]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22490] yield              5000      1.00      0.01      0.00      4998.60      378043.25\nstress-ng: info:  [22490] skipped: 0\nstress-ng: info:  [22490] passed: 1: yield (1)\nstress-ng: info:  [22490] failed: 0\nstress-ng: info:  [22490] metrics untrustworthy: 0\nstress-ng: info:  [22490] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "778": {
            "avg_ns_per_run": 124.93017588472134,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 778,
            "name": "sched_wakeup",
            "run_cnt_delta": 18876,
            "run_time_ns_delta": 2358182,
            "type": "tracepoint"
          },
          "779": {
            "avg_ns_per_run": 202.431654676259,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 779,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 556,
            "run_time_ns_delta": 112552,
            "type": "tracepoint"
          },
          "780": {
            "avg_ns_per_run": 148.70083321361872,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 780,
            "name": "sched_switch",
            "run_cnt_delta": 41766,
            "run_time_ns_delta": 6210639,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 2.3187496660000306,
            "ops_per_sec": 4960.000714453946,
            "ops_total": 11501.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [25309]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25309] sem-sysv           1001      0.01      0.01      0.00    148772.13      111993.73\nstress-ng: info:  [25309] skipped: 0\nstress-ng: info:  [25309] passed: 1: sem-sysv (1)\nstress-ng: info:  [25309] failed: 0\nstress-ng: info:  [25309] metrics untrustworthy: 0\nstress-ng: info:  [25309] successful run completed in 0.01 secs\nstress-ng: info:  [25313] setting to a 1 secs run per stressor\nstress-ng: info:  [25313] dispatching hogs: 1 switch\nstress-ng: info:  [25313] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25313] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25313]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25313] switch             1000      0.01      0.01      0.00    165638.73      130770.24\nstress-ng: info:  [25313] skipped: 0\nstress-ng: info:  [25313] passed: 1: switch (1)\nstress-ng: info:  [25313] failed: 0\nstress-ng: info:  [25313] metrics untrustworthy: 0\nstress-ng: info:  [25313] successful run completed in 0.01 secs\nstress-ng: info:  [25316] setting to a 1 secs run per stressor\nstress-ng: info:  [25316] dispatching hogs: 1 vfork\nstress-ng: info:  [25316] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25316] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25316]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25316] vfork               200      0.01      0.01      0.00     39453.52       33904.05\nstress-ng: info:  [25316] skipped: 0\nstress-ng: info:  [25316] passed: 1: vfork (1)\nstress-ng: info:  [25316] failed: 0\nstress-ng: info:  [25316] metrics untrustworthy: 0\nstress-ng: info:  [25316] successful run completed in 0.01 secs\nstress-ng: info:  [25518] setting to a 1 secs run per stressor\nstress-ng: info:  [25518] dispatching hogs: 1 yield\nstress-ng: info:  [25518] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25518] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25518]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25518] yield              5000      1.00      0.01      0.00      4998.39      378787.88\nstress-ng: info:  [25518] skipped: 0\nstress-ng: info:  [25518] passed: 1: yield (1)\nstress-ng: info:  [25518] failed: 0\nstress-ng: info:  [25518] metrics untrustworthy: 0\nstress-ng: info:  [25518] successful run completed in 1.00 secs"
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
          "787": {
            "avg_ns_per_run": 1475.7,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 787,
            "name": "tcp_set_state",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 14757,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.7037785510000276,
            "ops_per_sec": 7468.258293083151,
            "ops_total": 5256.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [22535]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22535] sockdiag           1034      0.00      0.00      0.00   2737948.44     1752542.37\nstress-ng: info:  [22535] skipped: 0\nstress-ng: info:  [22535] passed: 1: sockdiag (1)\nstress-ng: info:  [22535] failed: 0\nstress-ng: info:  [22535] metrics untrustworthy: 0\nstress-ng: info:  [22535] successful run completed in 0.00 secs\nstress-ng: info:  [22537] setting to a 1 secs run per stressor\nstress-ng: info:  [22537] dispatching hogs: 1 sockfd\nstress-ng: info:  [22537] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22537] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22537]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22537] sockfd              200      0.01      0.00      0.00     16072.29       54555.37\nstress-ng: info:  [22537] skipped: 0\nstress-ng: info:  [22537] passed: 1: sockfd (1)\nstress-ng: info:  [22537] failed: 0\nstress-ng: info:  [22537] metrics untrustworthy: 0\nstress-ng: info:  [22537] successful run completed in 0.01 secs\nstress-ng: info:  [22540] setting to a 1 secs run per stressor\nstress-ng: info:  [22540] dispatching hogs: 1 sockpair\nstress-ng: info:  [22540] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22540] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22540]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22540] sockpair            500      0.03      0.00      0.03     18780.58       16677.79\nstress-ng: info:  [22540] skipped: 0\nstress-ng: info:  [22540] passed: 1: sockpair (1)\nstress-ng: info:  [22540] failed: 0\nstress-ng: info:  [22540] metrics untrustworthy: 0\nstress-ng: info:  [22540] successful run completed in 0.03 secs\nstress-ng: info:  [22544] setting to a 1 secs run per stressor\nstress-ng: info:  [22544] dispatching hogs: 1 udp-flood\nstress-ng: info:  [22544] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22544] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22544]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22544] udp-flood          1000      0.01      0.01      0.00    184130.30      175901.50\nstress-ng: info:  [22544] skipped: 0\nstress-ng: info:  [22544] passed: 1: udp-flood (1)\nstress-ng: info:  [22544] failed: 0\nstress-ng: info:  [22544] metrics untrustworthy: 0\nstress-ng: info:  [22544] successful run completed in 0.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "787": {
            "avg_ns_per_run": 1335.5,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 787,
            "name": "tcp_set_state",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 13355,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.7638542510001116,
            "ops_per_sec": 6726.414094407192,
            "ops_total": 5138.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [25563]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25563] sockdiag           1034      0.00      0.00      0.00   2603187.48     1554887.22\nstress-ng: info:  [25563] skipped: 0\nstress-ng: info:  [25563] passed: 1: sockdiag (1)\nstress-ng: info:  [25563] failed: 0\nstress-ng: info:  [25563] metrics untrustworthy: 0\nstress-ng: info:  [25563] successful run completed in 0.00 secs\nstress-ng: info:  [25565] setting to a 1 secs run per stressor\nstress-ng: info:  [25565] dispatching hogs: 1 sockfd\nstress-ng: info:  [25565] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25565] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25565]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25565] sockfd              200      0.00      0.00      0.00     87829.63       55617.35\nstress-ng: info:  [25565] skipped: 0\nstress-ng: info:  [25565] passed: 1: sockfd (1)\nstress-ng: info:  [25565] failed: 0\nstress-ng: info:  [25565] metrics untrustworthy: 0\nstress-ng: info:  [25565] successful run completed in 0.00 secs\nstress-ng: info:  [25568] setting to a 1 secs run per stressor\nstress-ng: info:  [25568] dispatching hogs: 1 sockpair\nstress-ng: info:  [25568] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25568] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25568]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25568] sockpair            500      0.02      0.00      0.03     20347.46       16765.02\nstress-ng: info:  [25568] skipped: 0\nstress-ng: info:  [25568] passed: 1: sockpair (1)\nstress-ng: info:  [25568] failed: 0\nstress-ng: info:  [25568] metrics untrustworthy: 0\nstress-ng: info:  [25568] successful run completed in 0.03 secs\nstress-ng: info:  [25572] setting to a 1 secs run per stressor\nstress-ng: info:  [25572] dispatching hogs: 1 udp-flood\nstress-ng: info:  [25572] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25572] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25572]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25572] udp-flood          1000      0.01      0.01      0.00    181744.69      172950.54\nstress-ng: info:  [25572] skipped: 0\nstress-ng: info:  [25572] passed: 1: udp-flood (1)\nstress-ng: info:  [25572] failed: 0\nstress-ng: info:  [25572] metrics untrustworthy: 0\nstress-ng: info:  [25572] successful run completed in 0.01 secs"
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
          "793": {
            "avg_ns_per_run": null,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 793,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 4.797555060000036,
            "ops_per_sec": 1097.017112712399,
            "ops_total": 5263.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [22581]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22581] sockdiag           1034      0.00      0.00      0.00   2566219.13     1581039.76\nstress-ng: info:  [22581] skipped: 0\nstress-ng: info:  [22581] passed: 1: sockdiag (1)\nstress-ng: info:  [22581] failed: 0\nstress-ng: info:  [22581] metrics untrustworthy: 0\nstress-ng: info:  [22581] successful run completed in 0.00 secs\nstress-ng: info:  [22583] setting to a 5 secs run per stressor\nstress-ng: info:  [22583] dispatching hogs: 1 sockfd\nstress-ng: info:  [22583] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22583] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22583]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22583] sockfd              200      0.00      0.00      0.00     87100.07       55370.99\nstress-ng: info:  [22583] skipped: 0\nstress-ng: info:  [22583] passed: 1: sockfd (1)\nstress-ng: info:  [22583] failed: 0\nstress-ng: info:  [22583] metrics untrustworthy: 0\nstress-ng: info:  [22583] successful run completed in 0.00 secs\nstress-ng: info:  [22586] setting to a 5 secs run per stressor\nstress-ng: info:  [22586] dispatching hogs: 1 sockpair\nstress-ng: info:  [22586] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22586] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22586]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22586] sockpair            500      0.03      0.00      0.03     19895.19       16362.86\nstress-ng: info:  [22586] skipped: 0\nstress-ng: info:  [22586] passed: 1: sockpair (1)\nstress-ng: info:  [22586] failed: 0\nstress-ng: info:  [22586] metrics untrustworthy: 0\nstress-ng: info:  [22586] successful run completed in 0.03 secs\nstress-ng: info:  [22590] setting to a 5 secs run per stressor\nstress-ng: info:  [22590] dispatching hogs: 1 udp-flood\nstress-ng: info:  [22590] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22590] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22590]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22590] udp-flood          1000      0.01      0.01      0.00    185843.59      176584.85\nstress-ng: info:  [22590] skipped: 0\nstress-ng: info:  [22590] passed: 1: udp-flood (1)\nstress-ng: info:  [22590] failed: 0\nstress-ng: info:  [22590] metrics untrustworthy: 0\nstress-ng: info:  [22590] successful run completed in 0.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "793": {
            "avg_ns_per_run": 15662.0,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 793,
            "name": "tcp_retransmit_",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 15662,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.6213586669998676,
            "ops_per_sec": 3358.2945654309347,
            "ops_total": 5445.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [25609]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25609] sockdiag           1034      0.00      0.00      0.00   2566219.13     1536404.16\nstress-ng: info:  [25609] skipped: 0\nstress-ng: info:  [25609] passed: 1: sockdiag (1)\nstress-ng: info:  [25609] failed: 0\nstress-ng: info:  [25609] metrics untrustworthy: 0\nstress-ng: info:  [25609] successful run completed in 0.00 secs\nstress-ng: info:  [25611] setting to a 5 secs run per stressor\nstress-ng: info:  [25611] dispatching hogs: 1 sockfd\nstress-ng: info:  [25611] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25611] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25611]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25611] sockfd              200      0.01      0.00      0.00     15670.56       48983.59\nstress-ng: info:  [25611] skipped: 0\nstress-ng: info:  [25611] passed: 1: sockfd (1)\nstress-ng: info:  [25611] failed: 0\nstress-ng: info:  [25611] metrics untrustworthy: 0\nstress-ng: info:  [25611] successful run completed in 0.01 secs\nstress-ng: info:  [25614] setting to a 5 secs run per stressor\nstress-ng: info:  [25614] dispatching hogs: 1 sockpair\nstress-ng: info:  [25614] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25614] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25614]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25614] sockpair            500      0.02      0.00      0.03     22522.41       16833.32\nstress-ng: info:  [25614] skipped: 0\nstress-ng: info:  [25614] passed: 1: sockpair (1)\nstress-ng: info:  [25614] failed: 0\nstress-ng: info:  [25614] metrics untrustworthy: 0\nstress-ng: info:  [25614] successful run completed in 0.02 secs\nstress-ng: info:  [25618] setting to a 5 secs run per stressor\nstress-ng: info:  [25618] dispatching hogs: 1 udp-flood\nstress-ng: info:  [25618] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25618] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25618]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25618] udp-flood          1000      0.01      0.01      0.00    178640.66      170096.96\nstress-ng: info:  [25618] skipped: 0\nstress-ng: info:  [25618] passed: 1: udp-flood (1)\nstress-ng: info:  [25618] failed: 0\nstress-ng: info:  [25618] metrics untrustworthy: 0\nstress-ng: info:  [25618] successful run completed in 0.01 secs"
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
    "losses": 37,
    "per_program_geomean": 0.8505769437118628,
    "program_count": 98,
    "wins": 61
  },
  "workload_seconds": 1.0
}
```
