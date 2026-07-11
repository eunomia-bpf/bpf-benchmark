# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T03:03:59.290996+00:00",
  "kop_modules": {
    "captured_at": "2026-05-05T02:59:48.719202+00:00",
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
      "invoked_at": "2026-05-05T02:59:48.719145+00:00",
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
        "captured_at": "2026-05-05T02:59:48.719139+00:00",
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
      "captured_at": "2026-05-05T02:59:48.705180+00:00",
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
      "baseline_avg_ns_per_run": 331.7715707022793,
      "baseline_run_cnt_delta": 1068834,
      "baseline_run_time_ns_delta": 354608735,
      "post_rejit_avg_ns_per_run": 337.08689249995564,
      "post_rejit_run_cnt_delta": 1070967,
      "post_rejit_run_time_ns_delta": 361008938,
      "program": "cap_capable",
      "program_id": 6,
      "ratio": 1.0160210285240086,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 1117.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 2235,
      "post_rejit_avg_ns_per_run": 1162.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 2325,
      "program": "syscall__execve",
      "program_id": 9,
      "ratio": 1.0402684563758389,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 130.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 261,
      "post_rejit_avg_ns_per_run": 170.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 341,
      "program": "do_ret_sys_execve",
      "program_id": 10,
      "ratio": 1.3065134099616857,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 1508.3333333333333,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 4525,
      "post_rejit_avg_ns_per_run": 1436.3333333333333,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 4309,
      "program": "bindsnoop_entry",
      "program_id": 13,
      "ratio": 0.9522651933701658,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 4614.333333333333,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 13843,
      "post_rejit_avg_ns_per_run": 4627.0,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 13881,
      "program": "bindsnoop_v4_return",
      "program_id": 14,
      "ratio": 1.002745069710323,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 211.96888324287664,
      "baseline_run_cnt_delta": 1742823,
      "baseline_run_time_ns_delta": 369424245,
      "post_rejit_avg_ns_per_run": 213.72229433931136,
      "post_rejit_run_cnt_delta": 1745618,
      "post_rejit_run_time_ns_delta": 373077484,
      "program": "trace_pid_start_tp",
      "program_id": 18,
      "ratio": 1.0082720212024028,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 198.55914422093224,
      "baseline_run_cnt_delta": 1742833,
      "baseline_run_time_ns_delta": 346055429,
      "post_rejit_avg_ns_per_run": 199.24169238806894,
      "post_rejit_run_cnt_delta": 1745628,
      "post_rejit_run_time_ns_delta": 347801877,
      "program": "trace_req_start",
      "program_id": 19,
      "ratio": 1.0034375055846194,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 95.20018555941516,
      "baseline_run_cnt_delta": 1742838,
      "baseline_run_time_ns_delta": 165918501,
      "post_rejit_avg_ns_per_run": 94.96410184729551,
      "post_rejit_run_cnt_delta": 1745633,
      "post_rejit_run_time_ns_delta": 165772470,
      "program": "trace_req_completion_tp",
      "program_id": 20,
      "ratio": 0.9975201339080131,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 60.48561854439071,
      "baseline_run_cnt_delta": 133992,
      "baseline_run_time_ns_delta": 8104589,
      "post_rejit_avg_ns_per_run": 60.680415783898304,
      "post_rejit_run_cnt_delta": 135936,
      "post_rejit_run_time_ns_delta": 8248653,
      "program": "vfs_create",
      "program_id": 23,
      "ratio": 1.0032205546408464,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 68.77183600713012,
      "baseline_run_cnt_delta": 561,
      "baseline_run_time_ns_delta": 38581,
      "post_rejit_avg_ns_per_run": 78.97040498442368,
      "post_rejit_run_cnt_delta": 642,
      "post_rejit_run_time_ns_delta": 50699,
      "program": "kfunc__vmlinux__vfs_fsync_range",
      "program_id": 24,
      "ratio": 1.148295720594637,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 45.35342350453969,
      "baseline_run_cnt_delta": 1311653,
      "baseline_run_time_ns_delta": 59487954,
      "post_rejit_avg_ns_per_run": 45.46302634225687,
      "post_rejit_run_cnt_delta": 1382038,
      "post_rejit_run_time_ns_delta": 62831630,
      "program": "vfs_open",
      "program_id": 25,
      "ratio": 1.0024166386845352,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 42.69148380795204,
      "baseline_run_cnt_delta": 59381,
      "baseline_run_time_ns_delta": 2535063,
      "post_rejit_avg_ns_per_run": 44.69372258951365,
      "post_rejit_run_cnt_delta": 61108,
      "post_rejit_run_time_ns_delta": 2731144,
      "program": "vfs_read",
      "program_id": 26,
      "ratio": 1.0469001918642298,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 52.39639141353743,
      "baseline_run_cnt_delta": 66896,
      "baseline_run_time_ns_delta": 3505109,
      "post_rejit_avg_ns_per_run": 54.50121674918184,
      "post_rejit_run_cnt_delta": 83419,
      "post_rejit_run_time_ns_delta": 4546437,
      "program": "vfs_write",
      "program_id": 27,
      "ratio": 1.040171188871236,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 419.1118536756947,
      "baseline_run_cnt_delta": 17058,
      "baseline_run_time_ns_delta": 7149210,
      "post_rejit_avg_ns_per_run": 410.5140381734089,
      "post_rejit_run_cnt_delta": 15351,
      "post_rejit_run_time_ns_delta": 6301801,
      "program": "__x64_sys_open",
      "program_id": 30,
      "ratio": 0.9794856303230719,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 360.71377801325235,
      "baseline_run_cnt_delta": 581332,
      "baseline_run_time_ns_delta": 209694462,
      "post_rejit_avg_ns_per_run": 406.56075817203435,
      "post_rejit_run_cnt_delta": 610099,
      "post_rejit_run_time_ns_delta": 248042312,
      "program": "kretfunc__vmlinux____x64_sys_openat",
      "program_id": 31,
      "ratio": 1.127100717946786,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 435.46358267716533,
      "baseline_run_cnt_delta": 3048,
      "baseline_run_time_ns_delta": 1327293,
      "post_rejit_avg_ns_per_run": 442.95319001386963,
      "post_rejit_run_cnt_delta": 2884,
      "post_rejit_run_time_ns_delta": 1277477,
      "program": "kretfunc__vmlinux____x64_sys_openat2",
      "program_id": 32,
      "ratio": 1.0171991588611367,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 56.49905729755703,
      "baseline_run_cnt_delta": 9556568,
      "baseline_run_time_ns_delta": 539937083,
      "post_rejit_avg_ns_per_run": 57.93722064954958,
      "post_rejit_run_cnt_delta": 9519181,
      "post_rejit_run_time_ns_delta": 551514890,
      "program": "tracepoint__raw_syscalls__sys_enter",
      "program_id": 35,
      "ratio": 1.0254546433300353,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 56.97072851145636,
      "baseline_run_cnt_delta": 9556569,
      "baseline_run_time_ns_delta": 544444698,
      "post_rejit_avg_ns_per_run": 56.317238287911714,
      "post_rejit_run_cnt_delta": 9519182,
      "post_rejit_run_time_ns_delta": 536094041,
      "program": "tracepoint__raw_syscalls__sys_exit",
      "program_id": 36,
      "ratio": 0.9885293686666964,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 738.4803921568628,
      "baseline_run_cnt_delta": 306,
      "baseline_run_time_ns_delta": 225975,
      "post_rejit_avg_ns_per_run": 766.3921568627451,
      "post_rejit_run_cnt_delta": 306,
      "post_rejit_run_time_ns_delta": 234516,
      "program": "trace_connect_entry",
      "program_id": 39,
      "ratio": 1.037796216395619,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 4274.267973856209,
      "baseline_run_cnt_delta": 153,
      "baseline_run_time_ns_delta": 653963,
      "post_rejit_avg_ns_per_run": 4443.64705882353,
      "post_rejit_run_cnt_delta": 153,
      "post_rejit_run_time_ns_delta": 679878,
      "program": "trace_connect_v4_return",
      "program_id": 40,
      "ratio": 1.039627624192806,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 4258.150326797386,
      "baseline_run_cnt_delta": 153,
      "baseline_run_time_ns_delta": 651497,
      "post_rejit_avg_ns_per_run": 4640.777777777777,
      "post_rejit_run_cnt_delta": 153,
      "post_rejit_run_time_ns_delta": 710039,
      "program": "trace_connect_v6_return",
      "program_id": 41,
      "ratio": 1.089857666267074,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcplife",
      "baseline_avg_ns_per_run": 851.8909626719058,
      "baseline_run_cnt_delta": 3054,
      "baseline_run_time_ns_delta": 2601675,
      "post_rejit_avg_ns_per_run": 814.6624122527122,
      "post_rejit_run_cnt_delta": 3134,
      "post_rejit_run_time_ns_delta": 2553152,
      "program": "tracepoint__sock__inet_sock_set_state",
      "program_id": 44,
      "ratio": 0.9562989255075223,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 195.96852191321375,
      "baseline_run_cnt_delta": 13297981,
      "baseline_run_time_ns_delta": 2605985681,
      "post_rejit_avg_ns_per_run": 201.7708873911154,
      "post_rejit_run_cnt_delta": 14742327,
      "post_rejit_run_time_ns_delta": 2974572401,
      "program": "sched_switch",
      "program_id": 47,
      "ratio": 1.0296086607239465,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 77.6975326285578,
      "baseline_run_cnt_delta": 1014602,
      "baseline_run_time_ns_delta": 78832072,
      "post_rejit_avg_ns_per_run": 73.52940786475824,
      "post_rejit_run_cnt_delta": 950239,
      "post_rejit_run_time_ns_delta": 69870511,
      "program": "sched_wakeup",
      "program_id": 48,
      "ratio": 0.9463544771270181,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 293.31111111111113,
      "baseline_run_cnt_delta": 45,
      "baseline_run_time_ns_delta": 13199,
      "post_rejit_avg_ns_per_run": 301.2888888888889,
      "post_rejit_run_cnt_delta": 45,
      "post_rejit_run_time_ns_delta": 13558,
      "program": "raw_tracepoint__sched_wakeup_new",
      "program_id": 49,
      "ratio": 1.0271990302295628,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 3003.6666666666665,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 9011,
      "post_rejit_avg_ns_per_run": 3878.0,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 11634,
      "program": "tracepoint__sched_process_free",
      "program_id": 63,
      "ratio": 1.2910886694040618,
      "runner": "otelcol-ebpf-profiler",
      "type": "tracepoint",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 983.135625,
      "baseline_run_cnt_delta": 1600,
      "baseline_run_time_ns_delta": 1573017,
      "post_rejit_avg_ns_per_run": 999.8866171003717,
      "post_rejit_run_cnt_delta": 1614,
      "post_rejit_run_time_ns_delta": 1613817,
      "program": "native_tracer_entry",
      "program_id": 64,
      "ratio": 1.0170383329363857,
      "runner": "otelcol-ebpf-profiler",
      "type": "perf_event",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "cilium/agent",
      "baseline_avg_ns_per_run": 854.0911016949152,
      "baseline_run_cnt_delta": 472,
      "baseline_run_time_ns_delta": 403131,
      "post_rejit_avg_ns_per_run": 1132.531779661017,
      "post_rejit_run_cnt_delta": 472,
      "post_rejit_run_time_ns_delta": 534555,
      "program": "cil_from_netdev",
      "program_id": 165,
      "ratio": 1.3260081710411753,
      "runner": "cilium",
      "type": "sched_cls",
      "workload": "network_lossy_multi"
    },
    {
      "app": "katran",
      "baseline_avg_ns_per_run": 331.3708603761025,
      "baseline_run_cnt_delta": 36054,
      "baseline_run_time_ns_delta": 11947245,
      "post_rejit_avg_ns_per_run": 320.64271085960655,
      "post_rejit_run_cnt_delta": 37110,
      "post_rejit_run_time_ns_delta": 11899051,
      "program": "xdp_root",
      "program_id": 175,
      "ratio": 0.9676249459463044,
      "runner": "katran",
      "type": "xdp",
      "workload": "network"
    },
    {
      "app": "bpftrace/capable",
      "baseline_avg_ns_per_run": 165.93788518313875,
      "baseline_run_cnt_delta": 1223444,
      "baseline_run_time_ns_delta": 203015710,
      "post_rejit_avg_ns_per_run": 169.05262313259814,
      "post_rejit_run_cnt_delta": 1240025,
      "post_rejit_run_time_ns_delta": 209629479,
      "program": "cap_capable",
      "program_id": 189,
      "ratio": 1.0187705052768499,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 447.74789796463756,
      "baseline_run_cnt_delta": 1455613,
      "baseline_run_time_ns_delta": 651747661,
      "post_rejit_avg_ns_per_run": 410.0068238191487,
      "post_rejit_run_cnt_delta": 1415483,
      "post_rejit_run_time_ns_delta": 580357689,
      "program": "block_io_start",
      "program_id": 196,
      "ratio": 0.915709098095041,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 763.1403181307312,
      "baseline_run_cnt_delta": 1455628,
      "baseline_run_time_ns_delta": 1110848415,
      "post_rejit_avg_ns_per_run": 789.4404845503137,
      "post_rejit_run_cnt_delta": 1415498,
      "post_rejit_run_time_ns_delta": 1117451427,
      "program": "block_io_done",
      "program_id": 197,
      "ratio": 1.0344630807660684,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 2335.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 2335,
      "post_rejit_avg_ns_per_run": 1701.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1701,
      "program": "1",
      "program_id": 204,
      "ratio": 0.7284796573875802,
      "runner": "bpftrace",
      "type": "perf_event",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 34.19108696019729,
      "baseline_run_cnt_delta": 1656068,
      "baseline_run_time_ns_delta": 56622765,
      "post_rejit_avg_ns_per_run": 32.9609328862543,
      "post_rejit_run_cnt_delta": 1618804,
      "post_rejit_run_time_ns_delta": 53357290,
      "program": "vfs_create",
      "program_id": 205,
      "ratio": 0.9640212060126944,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 74.79641730071279,
      "baseline_run_cnt_delta": 848913,
      "baseline_run_time_ns_delta": 63495651,
      "post_rejit_avg_ns_per_run": 94.24903561659492,
      "post_rejit_run_cnt_delta": 1154883,
      "post_rejit_run_time_ns_delta": 108846609,
      "program": "sched_wakeup",
      "program_id": 212,
      "ratio": 1.2600741989776663,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 274.35555555555555,
      "baseline_run_cnt_delta": 45,
      "baseline_run_time_ns_delta": 12346,
      "post_rejit_avg_ns_per_run": 282.68888888888887,
      "post_rejit_run_cnt_delta": 45,
      "post_rejit_run_time_ns_delta": 12721,
      "program": "tracepoint_sched_sched_wakeup_new",
      "program_id": 213,
      "ratio": 1.0303742102705329,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 133.79827595702673,
      "baseline_run_cnt_delta": 15015751,
      "baseline_run_time_ns_delta": 2009081596,
      "post_rejit_avg_ns_per_run": 135.09658094476478,
      "post_rejit_run_cnt_delta": 15894771,
      "post_rejit_run_time_ns_delta": 2147329217,
      "program": "sched_switch",
      "program_id": 214,
      "ratio": 1.0097034507989853,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    }
  ],
  "results": [
    {
      "app": "bcc/capable",
      "baseline": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 331.7715707022793,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 1068834,
            "run_time_ns_delta": 354608735,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0144730739999943,
            "ops_per_sec": 1424871.7260681165,
            "ops_total": 1445494.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5935] setting to a 1 secs run per stressor\nstress-ng: info:  [5935] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [5935] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5935] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5935]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5935] cap             1222088      1.00      0.16      0.84   1222080.42     1223267.23\nstress-ng: metrc: [5935] eventfd          151093      1.00      0.09      0.63    151075.31      209617.90\nstress-ng: metrc: [5935] get                 959      1.00      0.03      0.10       958.83        7787.25\nstress-ng: metrc: [5935] prctl              3948      1.00      0.62      0.37      3947.55        3993.72\nstress-ng: metrc: [5935] set               67406      1.00      0.17      0.82     67405.26       68625.27\nstress-ng: info:  [5935] skipped: 0\nstress-ng: info:  [5935] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [5935] failed: 0\nstress-ng: info:  [5935] metrics untrustworthy: 0\nstress-ng: info:  [5935] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 337.08689249995564,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 1070967,
            "run_time_ns_delta": 361008938,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0112595639999995,
            "ops_per_sec": 1446672.1028707135,
            "ops_total": 1462961.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [13967] setting to a 1 secs run per stressor\nstress-ng: info:  [13967] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [13967] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13967] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13967]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13967] cap             1246342      1.00      0.27      0.73   1246336.95     1247242.51\nstress-ng: metrc: [13967] eventfd          146363      1.00      0.12      0.62    146301.05      197064.56\nstress-ng: metrc: [13967] get                 903      1.00      0.02      0.08       902.66        8343.42\nstress-ng: metrc: [13967] prctl              4292      1.00      0.60      0.39      4291.54        4333.09\nstress-ng: metrc: [13967] set               65061      1.00      0.14      0.84     65061.95       66294.14\nstress-ng: info:  [13967] skipped: 0\nstress-ng: info:  [13967] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [13967] failed: 0\nstress-ng: info:  [13967] metrics untrustworthy: 0\nstress-ng: info:  [13967] successful run completed in 1.00 secs"
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
            "avg_ns_per_run": 1117.5,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2235,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 130.5,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 261,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.019507817999994,
            "ops_per_sec": 46310.58160262218,
            "ops_total": 47214.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [7283] exec stressor must not run as root, skipping the stressor\nstress-ng: info:  [7283] setting to a 1 secs run per stressor\nstress-ng: info:  [7283] dispatching hogs: 1 clone, 1 fork, 1 vfork\nstress-ng: info:  [7283] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7283] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7283]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7283] clone               861      1.01      0.27      1.02       856.62         669.83\nstress-ng: metrc: [7283] fork               4673      1.00      0.51      0.50      4672.68        4622.63\nstress-ng: metrc: [7283] vfork             41680      1.00      0.45      0.48     41680.12       45004.82\nstress-ng: info:  [7283] skipped: 1: exec (1)\nstress-ng: info:  [7283] passed: 3: clone (1) fork (1) vfork (1)\nstress-ng: info:  [7283] failed: 0\nstress-ng: info:  [7283] metrics untrustworthy: 0\nstress-ng: info:  [7283] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 1162.5,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2325,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 170.5,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 341,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.016731567999983,
            "ops_per_sec": 49845.01474631192,
            "ops_total": 50679.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [10404] exec stressor must not run as root, skipping the stressor\nstress-ng: info:  [10404] setting to a 1 secs run per stressor\nstress-ng: info:  [10404] dispatching hogs: 1 clone, 1 fork, 1 vfork\nstress-ng: info:  [10404] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10404] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10404]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10404] clone               813      1.01      0.27      0.97       808.87         653.14\nstress-ng: metrc: [10404] fork               4601      1.00      0.51      0.50      4600.87        4545.89\nstress-ng: metrc: [10404] vfork             45265      1.00      0.48      0.45     45264.62       48747.10\nstress-ng: info:  [10404] skipped: 1: exec (1)\nstress-ng: info:  [10404] passed: 3: clone (1) fork (1) vfork (1)\nstress-ng: info:  [10404] failed: 0\nstress-ng: info:  [10404] metrics untrustworthy: 0\nstress-ng: info:  [10404] successful run completed in 1.01 secs"
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
            "avg_ns_per_run": 1508.3333333333333,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 4525,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 4614.333333333333,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 13843,
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
            "duration_s": 1.0541590809999946,
            "ops_per_sec": 36766767.65259512,
            "ops_total": 38758022.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [29082] setting to a 1 secs run per stressor\nstress-ng: info:  [29082] dispatching hogs: 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 sockmany, 1 udp-flood\nstress-ng: info:  [29082] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [29082] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [29082]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29082] epoll            205842      1.01      0.05      1.71    203703.46      117233.31\nstress-ng: metrc: [29082] netdev          2173951      1.00      0.20      0.80   2173917.83     2173364.19\nstress-ng: metrc: [29082] sctp                771      1.00      0.01      0.00       770.66      133391.00\nstress-ng: metrc: [29082] sock               4942      1.00      0.07      1.85      4938.75        2579.44\nstress-ng: metrc: [29082] sockdiag       34372067      1.00      0.06      0.94  34365307.50    34479020.92\nstress-ng: metrc: [29082] sockfd           601108      1.00      0.17      1.48    600734.04      365117.33\nstress-ng: metrc: [29082] sockpair         329148      1.04      0.16      1.26    315870.86      232259.54\nstress-ng: metrc: [29082] sockmany          44030      1.01      0.02      1.01     43539.06       42667.33\nstress-ng: metrc: [29082] udp-flood       1026163      1.00      0.11      0.87   1026156.39     1054380.33\nstress-ng: info:  [29082] skipped: 0\nstress-ng: info:  [29082] passed: 9: epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) sockmany (1) udp-flood (1)\nstress-ng: info:  [29082] failed: 0\nstress-ng: info:  [29082] metrics untrustworthy: 0\nstress-ng: info:  [29082] successful run completed in 1.04 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 1436.3333333333333,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 4309,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 4627.0,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 13881,
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
            "duration_s": 1.2242340010000134,
            "ops_per_sec": 27400318.054064266,
            "ops_total": 33544401.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [29138] setting to a 1 secs run per stressor\nstress-ng: info:  [29138] dispatching hogs: 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 sockmany, 1 udp-flood\nstress-ng: info:  [29138] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [29138] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [29138]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29138] epoll            115260      1.21      0.10      0.86     95160.59      120620.24\nstress-ng: metrc: [29138] netdev          2174626      1.00      0.19      0.81   2174602.15     2174080.31\nstress-ng: metrc: [29138] sctp               1021      1.00      0.01      0.00      1020.37      159232.69\nstress-ng: metrc: [29138] sock               5016      1.00      0.10      1.84      5013.10        2585.19\nstress-ng: metrc: [29138] sockdiag       29297572      1.00      0.08      0.92  29294610.62    29296019.31\nstress-ng: metrc: [29138] sockfd           580888      1.00      0.17      1.45    580698.46      359364.33\nstress-ng: metrc: [29138] sockpair         332887      1.05      0.11      1.34    316924.86      229426.14\nstress-ng: metrc: [29138] sockmany          45024      1.02      0.04      1.01     44076.36       42858.49\nstress-ng: metrc: [29138] udp-flood        992107      1.00      0.05      0.92    992093.99     1020382.83\nstress-ng: info:  [29138] skipped: 0\nstress-ng: info:  [29138] passed: 9: epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) sockmany (1) udp-flood (1)\nstress-ng: info:  [29138] failed: 0\nstress-ng: info:  [29138] metrics untrustworthy: 0\nstress-ng: info:  [29138] successful run completed in 1.21 secs"
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
            "avg_ns_per_run": 211.96888324287664,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1742823,
            "run_time_ns_delta": 369424245,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 198.55914422093224,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 1742833,
            "run_time_ns_delta": 346055429,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 95.20018555941516,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1742838,
            "run_time_ns_delta": 165918501,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.3456589270000165,
            "ops_per_sec": 437334.86029045953,
            "ops_total": 2337843.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.146491,\n        \"1000\" : 15.602838\n      },\n      \"latency_us\" : {\n        \"2\" : 32.064942,\n        \"4\" : 1.568789,\n        \"10\" : 17.909901,\n        \"20\" : 29.033296,\n        \"50\" : 3.063477,\n        \"100\" : 0.502964,\n        \"250\" : 0.097889,\n        \"500\" : 0.010000,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 213.72229433931136,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1745618,
            "run_time_ns_delta": 373077484,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 199.24169238806894,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 1745628,
            "run_time_ns_delta": 347801877,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 94.96410184729551,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1745633,
            "run_time_ns_delta": 165772470,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.368035139,
            "ops_per_sec": 436558.4314033679,
            "ops_total": 2343461.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.097417,\n        \"1000\" : 15.280058\n      },\n      \"latency_us\" : {\n        \"2\" : 32.462992,\n        \"4\" : 1.507586,\n        \"10\" : 19.254076,\n        \"20\" : 28.250710,\n        \"50\" : 2.542901,\n        \"100\" : 0.496284,\n        \"250\" : 0.100824,\n        \"500\" : 0.010000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
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
            "avg_ns_per_run": 60.48561854439071,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 133992,
            "run_time_ns_delta": 8104589,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": 68.77183600713012,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 561,
            "run_time_ns_delta": 38581,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 45.35342350453969,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 1311653,
            "run_time_ns_delta": 59487954,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 42.69148380795204,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 59381,
            "run_time_ns_delta": 2535063,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 52.39639141353743,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 66896,
            "run_time_ns_delta": 3505109,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1253789360000042,
            "ops_per_sec": 2655552.63600561,
            "ops_total": 2988503.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [10513] setting to a 1 secs run per stressor\nstress-ng: info:  [10513] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [10513] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [10530] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [10518] dentry: 77925 dentries allocated\nstress-ng: metrc: [10513] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10513]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10513] access            10707      1.01      0.26      1.58     10586.67        5827.98\nstress-ng: metrc: [10513] chdir                41      1.07      0.10      0.73        38.39          49.36\nstress-ng: metrc: [10513] chmod               118      1.01      0.00      0.02       116.66        4965.49\nstress-ng: metrc: [10513] chown               135      1.01      0.00      0.00       133.73       29722.59\nstress-ng: metrc: [10513] dentry            14336      1.03      0.03      0.41     13922.20       32241.89\nstress-ng: metrc: [10513] dir                8193      1.09      0.05      0.95      7507.90        8175.60\nstress-ng: metrc: [10513] dirmany           10479      1.01      0.00      0.25     10374.43       41131.86\nstress-ng: metrc: [10513] fallocate             1      1.01      0.00      0.00         0.99         251.70\nstress-ng: metrc: [10513] file-ioctl        71018      1.01      0.06      0.73     70266.75       90055.11\nstress-ng: metrc: [10513] filename           3786      1.01      0.03      0.71      3753.63        5129.06\nstress-ng: metrc: [10513] flock           2485580      1.01      0.48      0.59   2458747.36     2337888.57\nstress-ng: metrc: [10513] fpunch             1039      1.01      0.01      0.27      1028.07        3678.93\nstress-ng: metrc: [10513] fstat              2051      1.00      0.08      0.52      2050.66        3413.00\nstress-ng: metrc: [10513] getdent          216784      1.00      0.06      0.94    216781.00      217360.00\nstress-ng: metrc: [10513] hdd               29385      1.01      0.32      0.35     29089.38       43487.85\nstress-ng: metrc: [10513] inotify               2      1.10      0.00      0.00         1.82         808.73\nstress-ng: metrc: [10513] open              18432      1.01      0.02      0.24     18190.77       70907.31\nstress-ng: metrc: [10513] rename              384      1.01      0.01      0.00       380.90       32578.26\nstress-ng: metrc: [10513] touch             62878      1.01      0.05      1.56     62227.86       38892.33\nstress-ng: metrc: [10513] utime             53154      1.01      0.03      0.85     52622.78       60452.01\nstress-ng: info:  [10513] skipped: 0\nstress-ng: info:  [10513] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [10513] failed: 0\nstress-ng: info:  [10513] metrics untrustworthy: 0\nstress-ng: info:  [10513] successful run completed in 1.11 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "23": {
            "avg_ns_per_run": 60.680415783898304,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 135936,
            "run_time_ns_delta": 8248653,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": 78.97040498442368,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 642,
            "run_time_ns_delta": 50699,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 45.46302634225687,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 1382038,
            "run_time_ns_delta": 62831630,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 44.69372258951365,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 61108,
            "run_time_ns_delta": 2731144,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 54.50121674918184,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 83419,
            "run_time_ns_delta": 4546437,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1245248129999936,
            "ops_per_sec": 2526288.4083643747,
            "ops_total": 2840874.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [27656] setting to a 1 secs run per stressor\nstress-ng: info:  [27656] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [27656] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [27673] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [27661] dentry: 111347 dentries allocated\nstress-ng: metrc: [27656] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [27656]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [27656] access            10509      1.02      0.20      1.60     10299.81        5842.33\nstress-ng: metrc: [27656] chdir                47      1.08      0.09      0.80        43.51          53.00\nstress-ng: metrc: [27656] chmod               136      1.02      0.01      0.02       133.27        4898.25\nstress-ng: metrc: [27656] chown               162      1.02      0.00      0.01       158.82       24438.08\nstress-ng: metrc: [27656] dentry            13459      1.03      0.01      0.44     13126.21       30013.47\nstress-ng: metrc: [27656] dir                8192      1.09      0.07      0.92      7494.78        8298.42\nstress-ng: metrc: [27656] dirmany           10926      1.01      0.01      0.24     10838.99       43287.40\nstress-ng: metrc: [27656] fallocate             2      1.02      0.00      0.02         1.96         125.04\nstress-ng: metrc: [27656] file-ioctl        70686      1.00      0.10      0.62     70682.49       98473.70\nstress-ng: metrc: [27656] filename           3967      1.02      0.03      0.76      3890.84        5064.96\nstress-ng: metrc: [27656] flock           2346042      1.01      0.51      0.60   2328106.22     2122114.37\nstress-ng: metrc: [27656] fpunch             1529      1.02      0.00      0.23      1497.90        6676.27\nstress-ng: metrc: [27656] fstat              2469      1.00      0.13      0.60      2468.31        3376.38\nstress-ng: metrc: [27656] getdent          209292      1.00      0.03      0.96    209284.07      211579.38\nstress-ng: metrc: [27656] hdd               30243      1.02      0.31      0.35     29679.05       45373.67\nstress-ng: metrc: [27656] inotify               2      1.07      0.00      0.00         1.87         808.08\nstress-ng: metrc: [27656] open              18432      1.02      0.05      0.23     18083.30       66333.89\nstress-ng: metrc: [27656] rename              417      1.01      0.00      0.02       412.27       23883.16\nstress-ng: metrc: [27656] touch             63459      1.02      0.05      1.61     62213.56       38260.05\nstress-ng: metrc: [27656] utime             50903      1.01      0.04      0.80     50323.99       60709.10\nstress-ng: info:  [27656] skipped: 0\nstress-ng: info:  [27656] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [27656] failed: 0\nstress-ng: info:  [27656] metrics untrustworthy: 0\nstress-ng: info:  [27656] successful run completed in 1.11 secs"
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
            "avg_ns_per_run": 419.1118536756947,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 17058,
            "run_time_ns_delta": 7149210,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 360.71377801325235,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 581332,
            "run_time_ns_delta": 209694462,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 435.46358267716533,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 3048,
            "run_time_ns_delta": 1327293,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1196656259999997,
            "ops_per_sec": 2714808.7155798785,
            "ops_total": 3039678.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [13569] setting to a 1 secs run per stressor\nstress-ng: info:  [13569] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [13569] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [13586] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [13574] dentry: 111784 dentries allocated\nstress-ng: metrc: [13569] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13569]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13569] access            10074      1.01      0.25      1.29      9965.98        6562.88\nstress-ng: metrc: [13569] chdir                51      1.07      0.14      0.79        47.58          54.82\nstress-ng: metrc: [13569] chmod               131      1.00      0.00      0.02       130.92        5219.75\nstress-ng: metrc: [13569] chown               175      1.00      0.00      0.01       174.83       31823.97\nstress-ng: metrc: [13569] dentry            16214      1.03      0.01      0.49     15750.49       32147.03\nstress-ng: metrc: [13569] dir                8193      1.10      0.09      0.81      7464.03        9158.68\nstress-ng: metrc: [13569] dirmany            9727      1.01      0.01      0.22      9591.30       41853.30\nstress-ng: metrc: [13569] fallocate             2      1.00      0.00      0.00         2.00         490.32\nstress-ng: metrc: [13569] file-ioctl        70342      1.00      0.06      0.69     70316.45       94292.73\nstress-ng: metrc: [13569] filename           3584      1.01      0.06      0.66      3548.78        4989.78\nstress-ng: metrc: [13569] flock           2566395      1.01      0.35      0.69   2540586.35     2455910.93\nstress-ng: metrc: [13569] fpunch             1500      1.02      0.01      0.26      1477.38        5461.46\nstress-ng: metrc: [13569] fstat              1828      1.01      0.12      0.43      1814.40        3356.93\nstress-ng: metrc: [13569] getdent          197407      1.00      0.07      0.93    197405.82      198225.27\nstress-ng: metrc: [13569] hdd               27885      1.01      0.29      0.31     27610.87       46202.64\nstress-ng: metrc: [13569] inotify               2      1.02      0.00      0.00         1.96         978.47\nstress-ng: metrc: [13569] open              18432      1.01      0.02      0.26     18215.91       66920.81\nstress-ng: metrc: [13569] rename              459      1.00      0.00      0.01       458.88       31727.38\nstress-ng: metrc: [13569] touch             59700      1.01      0.06      1.32     59068.95       43164.28\nstress-ng: metrc: [13569] utime             47577      1.00      0.04      0.74     47572.29       61612.52\nstress-ng: info:  [13569] skipped: 0\nstress-ng: info:  [13569] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [13569] failed: 0\nstress-ng: info:  [13569] metrics untrustworthy: 0\nstress-ng: info:  [13569] successful run completed in 1.11 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "30": {
            "avg_ns_per_run": 410.5140381734089,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 15351,
            "run_time_ns_delta": 6301801,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 406.56075817203435,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 610099,
            "run_time_ns_delta": 248042312,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 442.95319001386963,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 2884,
            "run_time_ns_delta": 1277477,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1308262539999987,
            "ops_per_sec": 2744289.840302915,
            "ops_total": 3103315.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [26934] setting to a 1 secs run per stressor\nstress-ng: info:  [26934] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [26934] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [26953] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [26939] dentry: 107727 dentries allocated\nstress-ng: metrc: [26934] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [26934]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [26934] access             9898      1.01      0.14      1.49      9768.96        6089.96\nstress-ng: metrc: [26934] chdir                49      1.08      0.09      0.83        45.51          53.52\nstress-ng: metrc: [26934] chmod               180      1.00      0.00      0.03       179.79        5307.86\nstress-ng: metrc: [26934] chown               223      1.00      0.01      0.00       222.93       35079.44\nstress-ng: metrc: [26934] dentry            13728      1.03      0.01      0.45     13333.41       30187.95\nstress-ng: metrc: [26934] dir                8193      1.10      0.03      1.00      7432.45        7919.04\nstress-ng: metrc: [26934] dirmany            9678      1.01      0.00      0.24      9561.69       40927.14\nstress-ng: metrc: [26934] fallocate             2      1.01      0.00      0.00         1.98         277.09\nstress-ng: metrc: [26934] file-ioctl        73886      1.00      0.10      0.64     73882.58       99743.37\nstress-ng: metrc: [26934] filename           3452      1.01      0.04      0.62      3413.82        5220.42\nstress-ng: metrc: [26934] flock           2631547      1.01      0.34      0.63   2600586.51     2709075.32\nstress-ng: metrc: [26934] fpunch             1843      1.02      0.00      0.28      1801.18        6682.55\nstress-ng: metrc: [26934] fstat              1395      1.00      0.10      0.27      1393.96        3822.01\nstress-ng: metrc: [26934] getdent          195877      1.00      0.03      0.95    195874.66      199488.74\nstress-ng: metrc: [26934] hdd               25709      1.02      0.45      0.23     25289.02       37523.50\nstress-ng: metrc: [26934] inotify               2      1.05      0.00      0.00         1.91         696.86\nstress-ng: metrc: [26934] open              16858      1.02      0.02      0.25     16532.34       63881.95\nstress-ng: metrc: [26934] rename              633      1.02      0.00      0.02       623.21       30356.80\nstress-ng: metrc: [26934] touch             62926      1.02      0.09      1.38     61832.66       42841.98\nstress-ng: metrc: [26934] utime             47236      1.01      0.04      0.78     46773.24       57768.74\nstress-ng: info:  [26934] skipped: 0\nstress-ng: info:  [26934] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [26934] failed: 0\nstress-ng: info:  [26934] metrics untrustworthy: 0\nstress-ng: info:  [26934] successful run completed in 1.12 secs"
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
            "avg_ns_per_run": 56.49905729755703,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 9556568,
            "run_time_ns_delta": 539937083,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 56.97072851145636,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 9556569,
            "run_time_ns_delta": 544444698,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0139861979999978,
            "ops_per_sec": 604744.9178396029,
            "ops_total": 613203.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [2914] setting to a 1 secs run per stressor\nstress-ng: info:  [2914] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [2914] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2914] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2914]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2914] cap              442971      1.00      0.15      0.85    442966.04      443084.43\nstress-ng: metrc: [2914] eventfd          125613      1.00      0.01      0.83    125596.68      149212.44\nstress-ng: metrc: [2914] get                 957      1.00      0.01      0.14       957.02        6236.15\nstress-ng: metrc: [2914] prctl              2900      1.00      0.65      0.33      2899.74        2945.61\nstress-ng: metrc: [2914] set               40762      1.00      0.07      0.92     40761.34       41369.85\nstress-ng: info:  [2914] skipped: 0\nstress-ng: info:  [2914] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [2914] failed: 0\nstress-ng: info:  [2914] metrics untrustworthy: 0\nstress-ng: info:  [2914] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 57.93722064954958,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 9519181,
            "run_time_ns_delta": 551514890,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 56.317238287911714,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 9519182,
            "run_time_ns_delta": 536094041,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.014134949999999,
            "ops_per_sec": 604924.4235197698,
            "ops_total": 613475.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [8626] setting to a 1 secs run per stressor\nstress-ng: info:  [8626] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [8626] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8626] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8626]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8626] cap              442224      1.00      0.15      0.85    442219.99      442348.30\nstress-ng: metrc: [8626] eventfd          126967      1.00      0.05      0.78    126917.92      154165.31\nstress-ng: metrc: [8626] get                 973      1.00      0.01      0.15       972.59        5946.52\nstress-ng: metrc: [8626] prctl              2848      1.00      0.64      0.34      2847.95        2885.52\nstress-ng: metrc: [8626] set               40463      1.00      0.06      0.92     40462.40       41315.46\nstress-ng: info:  [8626] skipped: 0\nstress-ng: info:  [8626] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [8626] failed: 0\nstress-ng: info:  [8626] metrics untrustworthy: 0\nstress-ng: info:  [8626] successful run completed in 1.00 secs"
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
            "avg_ns_per_run": 738.4803921568628,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 306,
            "run_time_ns_delta": 225975,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4274.267973856209,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 153,
            "run_time_ns_delta": 653963,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 4258.150326797386,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 153,
            "run_time_ns_delta": 651497,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0017697469999973,
            "ops_per_sec": 305.4594141182433,
            "ops_total": 306.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 766.3921568627451,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 306,
            "run_time_ns_delta": 234516,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4443.64705882353,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 153,
            "run_time_ns_delta": 679878,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 4640.777777777777,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 153,
            "run_time_ns_delta": 710039,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0019708789999981,
            "ops_per_sec": 305.3980973033854,
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
            "avg_ns_per_run": 851.8909626719058,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 3054,
            "run_time_ns_delta": 2601675,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0028839210000058,
            "ops_per_sec": 304.1229334855377,
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
            "avg_ns_per_run": 814.6624122527122,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 3134,
            "run_time_ns_delta": 2553152,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0016195059999973,
            "ops_per_sec": 312.49391423094033,
            "ops_total": 313.0,
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
            "avg_ns_per_run": 195.96852191321375,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 13297981,
            "run_time_ns_delta": 2605985681,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 77.6975326285578,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 1014602,
            "run_time_ns_delta": 78832072,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 293.31111111111113,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 45,
            "run_time_ns_delta": 13199,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0157010350000064,
            "ops_per_sec": 24150089.597969,
            "ops_total": 24529271.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [16633] setting to a 1 secs run per stressor\nstress-ng: info:  [16633] dispatching hogs: 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 yield\nstress-ng: info:  [16633] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16633] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16633]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16633] futex           1108388      2.00      0.30      2.60    554127.48      382741.76\nstress-ng: metrc: [16633] sem             1054563      1.00      0.09      0.64   1054328.97     1432472.05\nstress-ng: metrc: [16633] sem-sysv        2717068      1.00      0.21      0.79   2716206.05     2715949.03\nstress-ng: metrc: [16633] switch           355846      1.00      0.13      0.87    355775.26      356277.10\nstress-ng: metrc: [16633] yield          19293406      1.00      3.16      8.19  19221141.76     1699524.90\nstress-ng: info:  [16633] skipped: 0\nstress-ng: info:  [16633] passed: 5: futex (1) sem (1) sem-sysv (1) switch (1) yield (1)\nstress-ng: info:  [16633] failed: 0\nstress-ng: info:  [16633] metrics untrustworthy: 0\nstress-ng: info:  [16633] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 201.7708873911154,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 14742327,
            "run_time_ns_delta": 2974572401,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 73.52940786475824,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 950239,
            "run_time_ns_delta": 69870511,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 301.2888888888889,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 45,
            "run_time_ns_delta": 13558,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.016627762000013,
            "ops_per_sec": 19756116.005023815,
            "ops_total": 20084616.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [16743] setting to a 1 secs run per stressor\nstress-ng: info:  [16743] dispatching hogs: 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 yield\nstress-ng: info:  [16743] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16743] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16743]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16743] futex           1136382      2.00      0.05      2.88    568095.99      387518.73\nstress-ng: metrc: [16743] sem             1093036      1.00      0.27      0.56   1092987.01     1321199.17\nstress-ng: metrc: [16743] sem-sysv        4487860      1.00      0.14      0.86   4486426.67     4485931.05\nstress-ng: metrc: [16743] switch           380643      1.00      0.10      0.90    380521.88      380584.01\nstress-ng: metrc: [16743] yield          12986695      1.00      3.04      8.21  12934452.11     1155087.40\nstress-ng: info:  [16743] skipped: 0\nstress-ng: info:  [16743] passed: 5: futex (1) sem (1) sem-sysv (1) switch (1) yield (1)\nstress-ng: info:  [16743] failed: 0\nstress-ng: info:  [16743] metrics untrustworthy: 0\nstress-ng: info:  [16743] successful run completed in 1.01 secs"
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
            "avg_ns_per_run": 3003.6666666666665,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 63,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 9011,
            "type": "tracepoint"
          },
          "64": {
            "avg_ns_per_run": 983.135625,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 64,
            "name": "native_tracer_entry",
            "run_cnt_delta": 1600,
            "run_time_ns_delta": 1573017,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.017172119999998,
            "ops_per_sec": 3058.0971975902644,
            "ops_total": 15343.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [16840] setting to a 5 secs run per stressor\nstress-ng: info:  [16840] dispatching hogs: 1 cpu\nstress-ng: info:  [16840] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16840] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16840]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16840] cpu               15343      5.00      5.00      0.00      3068.49        3068.84\nstress-ng: info:  [16840] skipped: 0\nstress-ng: info:  [16840] passed: 1: cpu (1)\nstress-ng: info:  [16840] failed: 0\nstress-ng: info:  [16840] metrics untrustworthy: 0\nstress-ng: info:  [16840] successful run completed in 5.00 secs"
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
            "avg_ns_per_run": 3878.0,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 63,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 11634,
            "type": "tracepoint"
          },
          "64": {
            "avg_ns_per_run": 999.8866171003717,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 64,
            "name": "native_tracer_entry",
            "run_cnt_delta": 1614,
            "run_time_ns_delta": 1613817,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.019739899000001,
            "ops_per_sec": 2946.168585935332,
            "ops_total": 14789.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [16881] setting to a 5 secs run per stressor\nstress-ng: info:  [16881] dispatching hogs: 1 cpu\nstress-ng: info:  [16881] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16881] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16881]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16881] cpu               14789      5.00      5.00      0.00      2957.43        2957.59\nstress-ng: info:  [16881] skipped: 0\nstress-ng: info:  [16881] passed: 1: cpu (1)\nstress-ng: info:  [16881] failed: 0\nstress-ng: info:  [16881] metrics untrustworthy: 0\nstress-ng: info:  [16881] successful run completed in 5.00 secs"
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
          "115": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 115,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "116": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 116,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "118": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 118,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "119": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 119,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 120,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "123": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 123,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 125,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "126": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 126,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "127": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 127,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 128,
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
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 131,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "132": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 132,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "133": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 133,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "134": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 134,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "135": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 135,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "136": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 136,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "138": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 138,
            "name": "cil_from_host",
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
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 143,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "144": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 144,
            "name": "tail_handle_ipv4_from_netdev",
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
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 147,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "148": {
            "avg_ns_per_run": 1422.0,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 148,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1422,
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
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 152,
            "name": "tail_handle_ipv4_from_host",
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
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 155,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "156": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 156,
            "name": "tail_handle_ipv4_from_netdev",
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
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 158,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "159": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 159,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "160": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 160,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "161": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 161,
            "name": "cil_from_host",
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
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 163,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "164": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 164,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "165": {
            "avg_ns_per_run": 854.0911016949152,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 165,
            "name": "cil_from_netdev",
            "run_cnt_delta": 472,
            "run_time_ns_delta": 403131,
            "type": "sched_cls"
          },
          "166": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 166,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "168": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 168,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.015691615000037,
            "ops_per_sec": 174.26549297642234,
            "ops_total": 177.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 20 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   120.02ms  127.38ms 858.64ms   85.92%\n    Req/Sec    88.75     40.05   161.00     70.00%\n  177 requests in 1.00s, 29.22KB read\nRequests/sec:    176.56\nTransfer/sec:     29.15KB"
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
          "115": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 115,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "116": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 116,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "118": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 118,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "119": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 119,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 120,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "123": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 123,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 125,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "126": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 126,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "127": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 127,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 128,
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
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 131,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "132": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 132,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "133": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 133,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "134": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 134,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "135": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 135,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "136": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 136,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "138": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 138,
            "name": "cil_from_host",
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
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 143,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "144": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 144,
            "name": "tail_handle_ipv4_from_netdev",
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
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 147,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "148": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 148,
            "name": "cil_to_host",
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
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 152,
            "name": "tail_handle_ipv4_from_host",
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
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 155,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "156": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 156,
            "name": "tail_handle_ipv4_from_netdev",
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
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 158,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "159": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 159,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "160": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 160,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "161": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 161,
            "name": "cil_from_host",
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
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 163,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "164": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 164,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "165": {
            "avg_ns_per_run": 1132.531779661017,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 165,
            "name": "cil_from_netdev",
            "run_cnt_delta": 472,
            "run_time_ns_delta": 534555,
            "type": "sched_cls"
          },
          "166": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 166,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "168": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 168,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1109528100000148,
            "ops_per_sec": 157.5224423798862,
            "ops_total": 175.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 20 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    97.68ms   93.04ms 589.18ms   85.03%\n    Req/Sec    83.48     28.27   140.00     71.43%\n  175 requests in 1.10s, 28.92KB read\nRequests/sec:    159.00\nTransfer/sec:     26.27KB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
        ],
        "error": "prog 73: prog 73 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8cff030c5d7a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8cff030c5d9a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 130: prog 130 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd2098058a049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd2098058a004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd2098058a03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd2098058a05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8cff54207c00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...; prog 134: prog 134 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (61) r7 = *(u32 *)(r6 +48)\n      2: ......67.. (b4) w1 = 0\n      3: .1....67.. (63) *(u32 *)(r6 +48) = r1\n      4: ......67.. (18) r1 = 0xffffd2098058a004\n      6: .1....67.. (71) r1 = *(u8 *)(r1 +0)\n      7: .1....67.. (61) r2 = *(u32 *)(r6 +80)\n      8: .12...67.. (61) r3 = *(u32 *)(r6 +76)\n      9: .123..67.. (0f) r3 += r1\n     10: ..23..67.. (b4) w0 = -134\n     11: 0.23..67.. (07) r3 += 20\n     12: 0.23..67.. (2d) if r3 > r2 goto pc+118\n     13: 0.....67.. (18) r1 = 0xffffd2098058a03c\n     15: 01....67.. (61) r1 = *(u32 *)(r1 +0)\n     16: 0.....67.. (61) r1 = *(u32 *)(r6 +44)\n     17: 01....67.. (63) *(u32 *)(r10 -32) = r1\n     18: 01....67.. (61) r2 = *(u32 *)(r10 -32)\n     19: 012...67.. (63) *(u32 *)(r10 -32) = r1\n     20: 0.2...67.. (54) w2 &= 1\n     21: 0.2...67.. (61) r1 = *(u32 *)(r10 -32)\n     22: 012...67.. (54) w1 &= 2\n     23: 012...67.. (4c) w1 |= w2\n     24: 01....67.. (b4) w8 = 1\n     25: 01....678. (56) if w1 != 0x0 goto pc+1\n     26: 0.....67.. (b4) w8 = 0\n     27: 0.....678. (18) r1 = 0xffffd2098058a004\n     29: 01....678. (71) r1 = *(u8 *)(r1 +0)\n     30: 01....678. (61) r2 = *(u32 *)(r6 +80)\n     31: 012...678. (61) r9 = *(u32 *)(r6 +76)\n     32: 012...6789 (0f) r9 += r1\n     33: 0.2...6789 (bf) r1 = r9\n     34: 012...6789 (07) r1 += 20\n     35: 012...6789 (2d) if r1 > r2 goto pc+95\n     36: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     37: .1....6789 (b7) r2 = 0\n     38: .12...6789 (63) *(u32 *)(r10 -16) = r2\n     39: .12...6789 (63) *(u32 *)(r10 -20) = r2\n     40: .12...6789 (63) *(u32 *)(r10 -24) = r2\n     41: .12...6789 (63) *(u32 *)(r10 -28) = r2\n     42: .1....6789 (63) *(u32 *)(r10 -32) = r1\n     43: ......6789 (b4) w1 = 1\n     44: .1....6789 (73) *(u8 *)(r10 -16) = r1\n     45: ......6789 (bf) r2 = r10\n     46: ..2...6789 (07) r2 += -32\n     47: ..2...6789 (18) r1 = 0xffff8cfe465d6400\n     49: .12...6789 (85) call bpf_map_lookup_elem#1\n     50: 0.....6789 (15) if r0 == 0x0 goto pc+43\n     51: 0.....67.9 (18) r1 = 0xffffd2098058a004\n     53: 01....67.9 (71) r2 = *(u8 *)(r1 +0)\n     54: 0.2...67.9 (61) r1 = *(u32 *)(r0 +8)\n     55: 012...67.9 (54) w1 &= 3\n     56: 012...67.9 (56) if w1 != 0x0 goto pc+62\n     57: 0.2...67.9 (79) r1 = *(u64 *)(r0 +24)\n     58: 012...67.9 (7b) *(u64 *)(r10 -40) = r1\n     59: 0.2...67.9 (79) r1 = *(u64 *)(r0 +16)\n     60: 012...67.9 (7b) *(u64 *)(r10 -48) = r1\n     61: 0.2...67.9 (71) r3 = *(u8 *)(r9 +8)\n     62: 0.23..67.9 (a6) if w3 < 0x2 goto pc+95\n     63: 0.23..67.9 (bf) r8 = r0\n     64: ..23..6789 (bc) w4 = w3\n     65: ..234.6789 (04) w4 += -1\n     66: ..234.6789 (73) *(u8 *)(r9 +8) = r4\n     67: ..234.678. (04) w2 += 10\n     68: ..234.678. (54) w4 &= 255\n     69: ..234.678. (bf) r1 = r6\n     70: .1234.678. (b4) w5 = 2\n     71: .12345678. (85) call bpf_l3_csum_replace#10\n     72: 0.....678. (c6) if w0 s< 0x0 goto pc+105\n     73: ......678. (bf) r3 = r10\n     74: ...3..678. (07) r3 += -40\n     75: ...3..678. (bf) r1 = r6\n     76: .1.3..678. (b4) w2 = 6\n     77: .123..678. (b4) w4 = 6\n     78: .1234.678. (b4) w5 = 0\n     79: .12345678. (85) call bpf_skb_store_bytes#9\n     80: 0.....678. (bc) w1 = w0\n     81: .1....678. (b4) w0 = -141\n     82: 01....678. (c6) if w1 s< 0x0 goto pc+48\n     83: ......678. (bf) r3 = r10\n     84: ...3..678. (07) r3 += -48\n     85: ...3..678. (bf) r1 = r6\n     86: .1.3..678. (b4) w2 = 0\n     87: .123..678. (b4) w4 = 6\n     88: .1234.678. (b4) w5 = 0\n     89: .12345678. (85) call bpf_skb_store_bytes#9\n     90: 0.....678. (bc) w1 = w0\n     91: .1....678. (b4) w0 = -141\n     92: 01....678. (c6) if w1 s< 0x0 goto pc+38\n     93: ......678. (05) goto pc+88\n     94: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     95: .1....678. (b4) w2 = 0\n     96: .12...678. (63) *(u32 *)(r10 -12) = r2\n     97: .12...678. (63) *(u32 *)(r10 -16) = r2\n     98: .12...678. (63) *(u32 *)(r10 -20) = r2\n     99: .1....678. (63) *(u32 *)(r10 -24) = r1\n    100: ......678. (b4) w1 = 64\n    101: .1....678. (63) *(u32 *)(r10 -32) = r1\n    102: ......678. (b4) w1 = 16777216\n    103: .1....678\n... verifier log truncated ...; prog 142: prog 142 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd2098062a049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd2098062a004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd2098062a03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd2098062a05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8cff54207c00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...; prog 146: prog 146 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd209803bd049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd209803bd004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd209803bd03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd209803bd05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8cff54207c00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 73 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8cff030c5d7a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8cff030c5d9a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
            "exit_code": 1,
            "prog_id": 73
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 130 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd2098058a049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd2098058a004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd2098058a03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd2098058a05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8cff54207c00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 130
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 134 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (61) r7 = *(u32 *)(r6 +48)\n      2: ......67.. (b4) w1 = 0\n      3: .1....67.. (63) *(u32 *)(r6 +48) = r1\n      4: ......67.. (18) r1 = 0xffffd2098058a004\n      6: .1....67.. (71) r1 = *(u8 *)(r1 +0)\n      7: .1....67.. (61) r2 = *(u32 *)(r6 +80)\n      8: .12...67.. (61) r3 = *(u32 *)(r6 +76)\n      9: .123..67.. (0f) r3 += r1\n     10: ..23..67.. (b4) w0 = -134\n     11: 0.23..67.. (07) r3 += 20\n     12: 0.23..67.. (2d) if r3 > r2 goto pc+118\n     13: 0.....67.. (18) r1 = 0xffffd2098058a03c\n     15: 01....67.. (61) r1 = *(u32 *)(r1 +0)\n     16: 0.....67.. (61) r1 = *(u32 *)(r6 +44)\n     17: 01....67.. (63) *(u32 *)(r10 -32) = r1\n     18: 01....67.. (61) r2 = *(u32 *)(r10 -32)\n     19: 012...67.. (63) *(u32 *)(r10 -32) = r1\n     20: 0.2...67.. (54) w2 &= 1\n     21: 0.2...67.. (61) r1 = *(u32 *)(r10 -32)\n     22: 012...67.. (54) w1 &= 2\n     23: 012...67.. (4c) w1 |= w2\n     24: 01....67.. (b4) w8 = 1\n     25: 01....678. (56) if w1 != 0x0 goto pc+1\n     26: 0.....67.. (b4) w8 = 0\n     27: 0.....678. (18) r1 = 0xffffd2098058a004\n     29: 01....678. (71) r1 = *(u8 *)(r1 +0)\n     30: 01....678. (61) r2 = *(u32 *)(r6 +80)\n     31: 012...678. (61) r9 = *(u32 *)(r6 +76)\n     32: 012...6789 (0f) r9 += r1\n     33: 0.2...6789 (bf) r1 = r9\n     34: 012...6789 (07) r1 += 20\n     35: 012...6789 (2d) if r1 > r2 goto pc+95\n     36: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     37: .1....6789 (b7) r2 = 0\n     38: .12...6789 (63) *(u32 *)(r10 -16) = r2\n     39: .12...6789 (63) *(u32 *)(r10 -20) = r2\n     40: .12...6789 (63) *(u32 *)(r10 -24) = r2\n     41: .12...6789 (63) *(u32 *)(r10 -28) = r2\n     42: .1....6789 (63) *(u32 *)(r10 -32) = r1\n     43: ......6789 (b4) w1 = 1\n     44: .1....6789 (73) *(u8 *)(r10 -16) = r1\n     45: ......6789 (bf) r2 = r10\n     46: ..2...6789 (07) r2 += -32\n     47: ..2...6789 (18) r1 = 0xffff8cfe465d6400\n     49: .12...6789 (85) call bpf_map_lookup_elem#1\n     50: 0.....6789 (15) if r0 == 0x0 goto pc+43\n     51: 0.....67.9 (18) r1 = 0xffffd2098058a004\n     53: 01....67.9 (71) r2 = *(u8 *)(r1 +0)\n     54: 0.2...67.9 (61) r1 = *(u32 *)(r0 +8)\n     55: 012...67.9 (54) w1 &= 3\n     56: 012...67.9 (56) if w1 != 0x0 goto pc+62\n     57: 0.2...67.9 (79) r1 = *(u64 *)(r0 +24)\n     58: 012...67.9 (7b) *(u64 *)(r10 -40) = r1\n     59: 0.2...67.9 (79) r1 = *(u64 *)(r0 +16)\n     60: 012...67.9 (7b) *(u64 *)(r10 -48) = r1\n     61: 0.2...67.9 (71) r3 = *(u8 *)(r9 +8)\n     62: 0.23..67.9 (a6) if w3 < 0x2 goto pc+95\n     63: 0.23..67.9 (bf) r8 = r0\n     64: ..23..6789 (bc) w4 = w3\n     65: ..234.6789 (04) w4 += -1\n     66: ..234.6789 (73) *(u8 *)(r9 +8) = r4\n     67: ..234.678. (04) w2 += 10\n     68: ..234.678. (54) w4 &= 255\n     69: ..234.678. (bf) r1 = r6\n     70: .1234.678. (b4) w5 = 2\n     71: .12345678. (85) call bpf_l3_csum_replace#10\n     72: 0.....678. (c6) if w0 s< 0x0 goto pc+105\n     73: ......678. (bf) r3 = r10\n     74: ...3..678. (07) r3 += -40\n     75: ...3..678. (bf) r1 = r6\n     76: .1.3..678. (b4) w2 = 6\n     77: .123..678. (b4) w4 = 6\n     78: .1234.678. (b4) w5 = 0\n     79: .12345678. (85) call bpf_skb_store_bytes#9\n     80: 0.....678. (bc) w1 = w0\n     81: .1....678. (b4) w0 = -141\n     82: 01....678. (c6) if w1 s< 0x0 goto pc+48\n     83: ......678. (bf) r3 = r10\n     84: ...3..678. (07) r3 += -48\n     85: ...3..678. (bf) r1 = r6\n     86: .1.3..678. (b4) w2 = 0\n     87: .123..678. (b4) w4 = 6\n     88: .1234.678. (b4) w5 = 0\n     89: .12345678. (85) call bpf_skb_store_bytes#9\n     90: 0.....678. (bc) w1 = w0\n     91: .1....678. (b4) w0 = -141\n     92: 01....678. (c6) if w1 s< 0x0 goto pc+38\n     93: ......678. (05) goto pc+88\n     94: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     95: .1....678. (b4) w2 = 0\n     96: .12...678. (63) *(u32 *)(r10 -12) = r2\n     97: .12...678. (63) *(u32 *)(r10 -16) = r2\n     98: .12...678. (63) *(u32 *)(r10 -20) = r2\n     99: .1....678. (63) *(u32 *)(r10 -24) = r1\n    100: ......678. (b4) w1 = 64\n    101: .1....678. (63) *(u32 *)(r10 -32) = r1\n    102: ......678. (b4) w1 = 16777216\n    103: .1....678\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 134
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 142 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd2098062a049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd2098062a004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd2098062a03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd2098062a05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8cff54207c00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 142
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 146 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd209803bd049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd209803bd004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd209803bd03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd209803bd05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8cff54207c00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 146
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 44,
          "not_applied": 5,
          "requested": 49
        }
      },
      "runner": "cilium",
      "selected_workload": "network_lossy_multi",
      "status": "ok"
    },
    {
      "app": "tetragon/observer",
      "baseline": null,
      "error": "cannot import name 'run_exec_storm' from 'runner.libs.workload' (/home/yunwei37/workspace/bpf-benchmark/runner/libs/workload.py)",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "tetragon",
      "selected_workload": "stress_ng_os_io_network",
      "status": "error"
    },
    {
      "app": "katran",
      "baseline": {
        "bpf": {
          "175": {
            "avg_ns_per_run": 331.3708603761025,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 175,
            "name": "xdp_root",
            "run_cnt_delta": 36054,
            "run_time_ns_delta": 11947245,
            "type": "xdp"
          },
          "181": {
            "avg_ns_per_run": null,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 181,
            "name": "balancer_ingress",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "183": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 183,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0005491000000006,
            "ops_per_sec": 6005.702268884152,
            "ops_total": 6009.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "175": {
            "avg_ns_per_run": 320.64271085960655,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 175,
            "name": "xdp_root",
            "run_cnt_delta": 37110,
            "run_time_ns_delta": 11899051,
            "type": "xdp"
          },
          "181": {
            "avg_ns_per_run": null,
            "bytes_jited": 13581,
            "bytes_xlated": 23744,
            "id": 181,
            "name": "balancer_ingress",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "183": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 183,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.000321683999971,
            "ops_per_sec": 6183.011024281845,
            "ops_total": 6185.0,
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
      "error": "cannot import name 'run_scheduler_load' from 'runner.libs.workload' (/home/yunwei37/workspace/bpf-benchmark/runner/libs/workload.py)",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "tracee",
      "selected_workload": "stress_ng_os_io_network",
      "status": "error"
    },
    {
      "app": "bpftrace/capable",
      "baseline": {
        "bpf": {
          "189": {
            "avg_ns_per_run": 165.93788518313875,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 189,
            "name": "cap_capable",
            "run_cnt_delta": 1223444,
            "run_time_ns_delta": 203015710,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.012321810000003,
            "ops_per_sec": 1434672.2412312697,
            "ops_total": 1452350.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [13721] setting to a 1 secs run per stressor\nstress-ng: info:  [13721] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [13721] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13721] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13721]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13721] cap             1226323      1.00      0.26      0.74   1226326.80     1227002.76\nstress-ng: metrc: [13721] eventfd          138860      1.00      0.07      0.66    138817.04      191767.50\nstress-ng: metrc: [13721] get                 999      1.00      0.03      0.10       998.50        7349.86\nstress-ng: metrc: [13721] prctl              3842      1.00      0.62      0.38      3841.67        3843.35\nstress-ng: metrc: [13721] set               82326      1.00      0.21      0.74     82325.82       87288.99\nstress-ng: info:  [13721] skipped: 0\nstress-ng: info:  [13721] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [13721] failed: 0\nstress-ng: info:  [13721] metrics untrustworthy: 0\nstress-ng: info:  [13721] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "189": {
            "avg_ns_per_run": 169.05262313259814,
            "bytes_jited": 697,
            "bytes_xlated": 1216,
            "id": 189,
            "name": "cap_capable",
            "run_cnt_delta": 1240025,
            "run_time_ns_delta": 209629479,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0151316139999835,
            "ops_per_sec": 1380141.235558075,
            "ops_total": 1401025.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [21115] setting to a 1 secs run per stressor\nstress-ng: info:  [21115] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [21115] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21115] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21115]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21115] cap             1170766      1.00      0.16      0.84   1170768.23     1171395.04\nstress-ng: metrc: [21115] eventfd          140993      1.00      0.06      0.64    140948.98      201381.75\nstress-ng: metrc: [21115] get                 976      1.00      0.01      0.13       975.34        7013.61\nstress-ng: metrc: [21115] prctl              3749      1.00      0.58      0.42      3739.23        3750.68\nstress-ng: metrc: [21115] set               84541      1.00      0.18      0.79     84540.23       87208.71\nstress-ng: info:  [21115] skipped: 0\nstress-ng: info:  [21115] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [21115] failed: 0\nstress-ng: info:  [21115] metrics untrustworthy: 0\nstress-ng: info:  [21115] successful run completed in 1.00 secs"
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
          "196": {
            "avg_ns_per_run": 447.74789796463756,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 196,
            "name": "block_io_start",
            "run_cnt_delta": 1455613,
            "run_time_ns_delta": 651747661,
            "type": "tracepoint"
          },
          "197": {
            "avg_ns_per_run": 763.1403181307312,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 197,
            "name": "block_io_done",
            "run_cnt_delta": 1455628,
            "run_time_ns_delta": 1110848415,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.370966847999966,
            "ops_per_sec": 363459.70013330685,
            "ops_total": 1952130.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.071104,\n        \"1000\" : 13.121388\n      },\n      \"latency_us\" : {\n        \"2\" : 34.353715,\n        \"4\" : 1.829843,\n        \"10\" : 10.756936,\n        \"20\" : 35.236056,\n        \"50\" : 2.724069,\n        \"100\" : 1.616122,\n        \"250\" : 0.274989,\n        \"500\" : 0.015573,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "196": {
            "avg_ns_per_run": 410.0068238191487,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 196,
            "name": "block_io_start",
            "run_cnt_delta": 1415483,
            "run_time_ns_delta": 580357689,
            "type": "tracepoint"
          },
          "197": {
            "avg_ns_per_run": 789.4404845503137,
            "bytes_jited": 883,
            "bytes_xlated": 1480,
            "id": 197,
            "name": "block_io_done",
            "run_cnt_delta": 1415498,
            "run_time_ns_delta": 1117451427,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.368058903999952,
            "ops_per_sec": 353212.5920949129,
            "ops_total": 1896066.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.107548,\n        \"1000\" : 13.793916\n      },\n      \"latency_us\" : {\n        \"2\" : 33.783730,\n        \"4\" : 1.692144,\n        \"10\" : 10.287770,\n        \"20\" : 35.656032,\n        \"50\" : 2.528323,\n        \"100\" : 1.759072,\n        \"250\" : 0.366210,\n        \"500\" : 0.022099,\n        \"750\" : 0.010000,\n        \"1000\" : 0.010000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.010000,\n        \"4\" : 0.010000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
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
          "204": {
            "avg_ns_per_run": 2335.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 204,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2335,
            "type": "perf_event"
          },
          "205": {
            "avg_ns_per_run": 34.19108696019729,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 205,
            "name": "vfs_create",
            "run_cnt_delta": 1656068,
            "run_time_ns_delta": 56622765,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1062793600000305,
            "ops_per_sec": 2701791.3449998,
            "ops_total": 2988936.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [6992] setting to a 1 secs run per stressor\nstress-ng: info:  [6992] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [6992] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [7011] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [6997] dentry: 69362 dentries allocated\nstress-ng: metrc: [6992] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6992]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6992] access            10811      1.00      0.19      1.59     10799.36        6043.23\nstress-ng: metrc: [6992] chdir                48      1.07      0.10      0.81        44.70          52.81\nstress-ng: metrc: [6992] chmod               126      1.01      0.00      0.03       124.51        4603.75\nstress-ng: metrc: [6992] chown               148      1.00      0.00      0.00       147.76       31066.33\nstress-ng: metrc: [6992] dentry            14336      1.04      0.02      0.48     13799.17       29064.84\nstress-ng: metrc: [6992] dir                8193      1.08      0.08      0.96      7556.90        7902.95\nstress-ng: metrc: [6992] dirmany           11263      1.01      0.00      0.25     11132.15       44318.79\nstress-ng: metrc: [6992] fallocate             1      1.01      0.00      0.00         0.99         217.39\nstress-ng: metrc: [6992] file-ioctl        76764      1.00      0.08      0.72     76760.56       96470.39\nstress-ng: metrc: [6992] filename           3686      1.01      0.04      0.70      3645.90        4943.57\nstress-ng: metrc: [6992] flock           2483194      1.01      0.44      0.64   2453811.24     2296997.12\nstress-ng: metrc: [6992] fpunch             1731      1.01      0.03      0.19      1706.53        7807.92\nstress-ng: metrc: [6992] fstat              2397      1.00      0.16      0.56      2396.79        3309.93\nstress-ng: metrc: [6992] getdent          215553      1.00      0.07      0.92    215548.84      216862.42\nstress-ng: metrc: [6992] hdd               26624      1.01      0.34      0.31     26347.57       40506.88\nstress-ng: metrc: [6992] inotify               2      1.04      0.00      0.00         1.93         470.37\nstress-ng: metrc: [6992] open              17256      1.02      0.01      0.23     16948.00       70306.39\nstress-ng: metrc: [6992] rename              411      1.01      0.01      0.00       406.28       34514.61\nstress-ng: metrc: [6992] touch             66652      1.02      0.05      1.67     65584.89       38695.50\nstress-ng: metrc: [6992] utime             49740      1.01      0.05      0.79     49204.13       59531.57\nstress-ng: info:  [6992] skipped: 0\nstress-ng: info:  [6992] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [6992] failed: 0\nstress-ng: info:  [6992] metrics untrustworthy: 0\nstress-ng: info:  [6992] successful run completed in 1.09 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "204": {
            "avg_ns_per_run": 1701.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 204,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1701,
            "type": "perf_event"
          },
          "205": {
            "avg_ns_per_run": 32.9609328862543,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 205,
            "name": "vfs_create",
            "run_cnt_delta": 1618804,
            "run_time_ns_delta": 53357290,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1109967079999592,
            "ops_per_sec": 2560553.0417108173,
            "ops_total": 2844766.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [26841] setting to a 1 secs run per stressor\nstress-ng: info:  [26841] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [26841] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [26858] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [26846] dentry: 79509 dentries allocated\nstress-ng: metrc: [26841] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [26841]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [26841] access             9940      1.02      0.22      1.46      9743.96        5929.37\nstress-ng: metrc: [26841] chdir                49      1.08      0.08      0.81        45.56          54.86\nstress-ng: metrc: [26841] chmod               114      1.02      0.00      0.03       111.97        3881.12\nstress-ng: metrc: [26841] chown               129      1.02      0.00      0.01       126.69       11983.28\nstress-ng: metrc: [26841] dentry            14336      1.03      0.03      0.44     13881.10       30788.13\nstress-ng: metrc: [26841] dir                8192      1.09      0.05      0.85      7518.84        9059.52\nstress-ng: metrc: [26841] dirmany           10751      1.02      0.00      0.26     10549.88       42083.55\nstress-ng: metrc: [26841] fallocate             1      1.02      0.00      0.01         0.98         129.70\nstress-ng: metrc: [26841] file-ioctl        76115      1.01      0.07      0.67     75547.19      101656.23\nstress-ng: metrc: [26841] filename           3949      1.02      0.04      0.71      3882.47        5299.82\nstress-ng: metrc: [26841] flock           2366342      1.01      0.35      0.71   2348588.87     2236148.94\nstress-ng: metrc: [26841] fpunch             1384      1.02      0.00      0.31      1357.53        4486.05\nstress-ng: metrc: [26841] fstat              3031      1.00      0.10      0.73      3030.88        3632.29\nstress-ng: metrc: [26841] getdent          196576      1.00      0.02      0.96    196571.92      200698.55\nstress-ng: metrc: [26841] hdd               23381      1.02      0.32      0.30     22987.54       37358.14\nstress-ng: metrc: [26841] inotify               2      1.03      0.00      0.00         1.95         620.16\nstress-ng: metrc: [26841] open              18432      1.02      0.01      0.24     18087.28       74194.83\nstress-ng: metrc: [26841] rename              384      1.02      0.00      0.01       377.62       29871.65\nstress-ng: metrc: [26841] touch             63437      1.02      0.05      1.71     62374.58       36046.58\nstress-ng: metrc: [26841] utime             48221      1.01      0.06      0.74     47902.19       60235.44\nstress-ng: info:  [26841] skipped: 0\nstress-ng: info:  [26841] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [26841] failed: 0\nstress-ng: info:  [26841] metrics untrustworthy: 0\nstress-ng: info:  [26841] successful run completed in 1.10 secs"
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
          "212": {
            "avg_ns_per_run": 74.79641730071279,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 212,
            "name": "sched_wakeup",
            "run_cnt_delta": 848913,
            "run_time_ns_delta": 63495651,
            "type": "tracepoint"
          },
          "213": {
            "avg_ns_per_run": 274.35555555555555,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 213,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 45,
            "run_time_ns_delta": 12346,
            "type": "tracepoint"
          },
          "214": {
            "avg_ns_per_run": 133.79827595702673,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 214,
            "name": "sched_switch",
            "run_cnt_delta": 15015751,
            "run_time_ns_delta": 2009081596,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0154259589999697,
            "ops_per_sec": 23786768.287652887,
            "ops_total": 24153702.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [6716] setting to a 1 secs run per stressor\nstress-ng: info:  [6716] dispatching hogs: 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 yield\nstress-ng: info:  [6716] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6716] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6716]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6716] futex            843720      2.00      0.39      2.51    421804.04      291355.27\nstress-ng: metrc: [6716] sem             1512841      1.00      0.14      0.74   1511951.70     1731813.19\nstress-ng: metrc: [6716] sem-sysv        4439910      1.00      0.23      0.77   4438627.40     4437602.45\nstress-ng: metrc: [6716] switch           363126      1.00      0.12      0.88    363050.87      363212.08\nstress-ng: metrc: [6716] yield          16994105      1.00      3.26      7.95  16933964.31     1515636.40\nstress-ng: info:  [6716] skipped: 0\nstress-ng: info:  [6716] passed: 5: futex (1) sem (1) sem-sysv (1) switch (1) yield (1)\nstress-ng: info:  [6716] failed: 0\nstress-ng: info:  [6716] metrics untrustworthy: 0\nstress-ng: info:  [6716] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "212": {
            "avg_ns_per_run": 94.24903561659492,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 212,
            "name": "sched_wakeup",
            "run_cnt_delta": 1154883,
            "run_time_ns_delta": 108846609,
            "type": "tracepoint"
          },
          "213": {
            "avg_ns_per_run": 282.68888888888887,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 213,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 45,
            "run_time_ns_delta": 12721,
            "type": "tracepoint"
          },
          "214": {
            "avg_ns_per_run": 135.09658094476478,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 214,
            "name": "sched_switch",
            "run_cnt_delta": 15894771,
            "run_time_ns_delta": 2147329217,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.016553690999956,
            "ops_per_sec": 16810165.71115941,
            "ops_total": 17088436.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [6826] setting to a 1 secs run per stressor\nstress-ng: info:  [6826] dispatching hogs: 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 yield\nstress-ng: info:  [6826] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6826] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6826]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6826] futex            903312      2.00      0.20      2.26    451573.26      367653.89\nstress-ng: metrc: [6826] sem             1667415      1.00      0.27      0.74   1667023.51     1647255.88\nstress-ng: metrc: [6826] sem-sysv         331507      1.00      0.14      0.95    331430.67      304801.51\nstress-ng: metrc: [6826] switch           375263      1.00      0.16      0.84    375185.71      376612.40\nstress-ng: metrc: [6826] yield          13810939      1.00      3.16      8.08  13758663.80     1228280.35\nstress-ng: info:  [6826] skipped: 0\nstress-ng: info:  [6826] passed: 5: futex (1) sem (1) sem-sysv (1) switch (1) yield (1)\nstress-ng: info:  [6826] failed: 0\nstress-ng: info:  [6826] metrics untrustworthy: 0\nstress-ng: info:  [6826] successful run completed in 1.01 secs"
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
      "baseline": null,
      "error": "interface-bound HTTP server exited before becoming ready: Traceback (most recent call last):\n  File \"<string>\", line 32, in <module>\n  File \"/usr/lib/python3.12/socketserver.py\", line 457, in __init__\n    self.server_bind()\n  File \"/usr/lib/python3.12/http/server.py\", line 136, in server_bind\n    socketserver.TCPServer.server_bind(self)\n  File \"/usr/lib/python3.12/socketserver.py\", line 473, in server_bind\n    self.socket.bind(self.server_address)\nOSError: [Errno 99] Cannot assign requested address",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bpftrace",
      "selected_workload": "tcp_connect",
      "status": "error"
    },
    {
      "app": "bpftrace/tcpretrans",
      "baseline": null,
      "error": "failed to install netem qdisc on bpfbench0",
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
    "losses": 27,
    "per_program_geomean": 1.0320161318053458,
    "program_count": 37,
    "wins": 10
  },
  "workload_seconds": 1.0
}
```
