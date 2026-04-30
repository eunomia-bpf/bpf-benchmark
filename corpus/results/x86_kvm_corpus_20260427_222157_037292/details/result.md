# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-04-27T22:30:25.332398+00:00",
  "kinsn_modules": {
    "captured_at": "2026-04-27T22:21:57.067925+00:00",
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
      "invoked_at": "2026-04-27T22:21:57.067850+00:00",
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
        "captured_at": "2026-04-27T22:21:57.067839+00:00",
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
      "captured_at": "2026-04-27T22:21:57.059277+00:00",
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
      "baseline_avg_ns_per_run": 115.24227294341416,
      "baseline_run_cnt_delta": 109356,
      "baseline_run_time_ns_delta": 12602434,
      "post_rejit_avg_ns_per_run": 71.0910739145919,
      "post_rejit_run_cnt_delta": 123548,
      "post_rejit_run_time_ns_delta": 8783160,
      "program": "cap_capable",
      "program_id": 6,
      "ratio": 0.6168836495397725,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 2138.8267223382045,
      "baseline_run_cnt_delta": 958,
      "baseline_run_time_ns_delta": 2048996,
      "post_rejit_avg_ns_per_run": 2523.7481865284976,
      "post_rejit_run_cnt_delta": 965,
      "post_rejit_run_time_ns_delta": 2435417,
      "program": "syscall__execve",
      "program_id": 9,
      "ratio": 1.1799685127224753,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 1651.071676300578,
      "baseline_run_cnt_delta": 865,
      "baseline_run_time_ns_delta": 1428177,
      "post_rejit_avg_ns_per_run": 1938.2912087912089,
      "post_rejit_run_cnt_delta": 910,
      "post_rejit_run_time_ns_delta": 1763845,
      "program": "do_ret_sys_exec",
      "program_id": 10,
      "ratio": 1.1739594571291903,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 75.94110514463884,
      "baseline_run_cnt_delta": 23092,
      "baseline_run_time_ns_delta": 1753632,
      "post_rejit_avg_ns_per_run": 59.51622566150774,
      "post_rejit_run_cnt_delta": 54081,
      "post_rejit_run_time_ns_delta": 3218697,
      "program": "bindsnoop_entry",
      "program_id": 13,
      "ratio": 0.7837155588946465,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "bind_storm"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 875.1952191235059,
      "baseline_run_cnt_delta": 11546,
      "baseline_run_time_ns_delta": 10105004,
      "post_rejit_avg_ns_per_run": 737.9486705373322,
      "post_rejit_run_cnt_delta": 27041,
      "post_rejit_run_time_ns_delta": 19954870,
      "program": "bindsnoop_v4_re",
      "program_id": 14,
      "ratio": 0.8431817889457578,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "bind_storm"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 880.2329811190023,
      "baseline_run_cnt_delta": 11546,
      "baseline_run_time_ns_delta": 10163170,
      "post_rejit_avg_ns_per_run": 754.0628328402366,
      "post_rejit_run_cnt_delta": 27040,
      "post_rejit_run_time_ns_delta": 20389859,
      "program": "bindsnoop_v6_re",
      "program_id": 15,
      "ratio": 0.8566627802126081,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "bind_storm"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 216.45670121130004,
      "baseline_run_cnt_delta": 245769,
      "baseline_run_time_ns_delta": 53198347,
      "post_rejit_avg_ns_per_run": 218.62694119666597,
      "post_rejit_run_cnt_delta": 524290,
      "post_rejit_run_time_ns_delta": 114623919,
      "program": "trace_pid_start",
      "program_id": 18,
      "ratio": 1.0100262083512368,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 234.03043915221204,
      "baseline_run_cnt_delta": 245769,
      "baseline_run_time_ns_delta": 57517427,
      "post_rejit_avg_ns_per_run": 230.70796617152274,
      "post_rejit_run_cnt_delta": 524292,
      "post_rejit_run_time_ns_delta": 120958341,
      "program": "trace_req_start",
      "program_id": 19,
      "ratio": 0.9858032442586309,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "block_io"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 447.72971807318135,
      "baseline_run_cnt_delta": 245773,
      "baseline_run_time_ns_delta": 110039876,
      "post_rejit_avg_ns_per_run": 426.4330841723998,
      "post_rejit_run_cnt_delta": 524293,
      "post_rejit_run_time_ns_delta": 223575881,
      "program": "trace_req_compl",
      "program_id": 20,
      "ratio": 0.9524341739198544,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 55.380514705882355,
      "baseline_run_cnt_delta": 544,
      "baseline_run_time_ns_delta": 30127,
      "post_rejit_avg_ns_per_run": 31.346020761245676,
      "post_rejit_run_cnt_delta": 289,
      "post_rejit_run_time_ns_delta": 9059,
      "program": "vfs_open",
      "program_id": 25,
      "ratio": 0.5660117268270205,
      "runner": "bcc",
      "type": "tracing",
      "workload": "vfs_create_fsync_exact"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 34.3003355704698,
      "baseline_run_cnt_delta": 5364,
      "baseline_run_time_ns_delta": 183987,
      "post_rejit_avg_ns_per_run": 38.590610636900855,
      "post_rejit_run_cnt_delta": 3046,
      "post_rejit_run_time_ns_delta": 117547,
      "program": "vfs_read",
      "program_id": 26,
      "ratio": 1.1250796820228397,
      "runner": "bcc",
      "type": "tracing",
      "workload": "vfs_create_fsync_exact"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 28.789344951463733,
      "baseline_run_cnt_delta": 13083,
      "baseline_run_time_ns_delta": 376651,
      "post_rejit_avg_ns_per_run": 31.178466557911907,
      "post_rejit_run_cnt_delta": 6130,
      "post_rejit_run_time_ns_delta": 191124,
      "program": "vfs_write",
      "program_id": 27,
      "ratio": 1.0829863135293984,
      "runner": "bcc",
      "type": "tracing",
      "workload": "vfs_create_fsync_exact"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 1356.8690890990542,
      "baseline_run_cnt_delta": 2009,
      "baseline_run_time_ns_delta": 2725950,
      "post_rejit_avg_ns_per_run": 1825.0907079646017,
      "post_rejit_run_cnt_delta": 2260,
      "post_rejit_run_time_ns_delta": 4124705,
      "program": "__x64_sys_opena",
      "program_id": 31,
      "ratio": 1.345075013225072,
      "runner": "bcc",
      "type": "tracing",
      "workload": "open_family_storm"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 1272.7901907356948,
      "baseline_run_cnt_delta": 734,
      "baseline_run_time_ns_delta": 934228,
      "post_rejit_avg_ns_per_run": 1914.447927199191,
      "post_rejit_run_cnt_delta": 989,
      "post_rejit_run_time_ns_delta": 1893389,
      "program": "__x64_sys_opena",
      "program_id": 32,
      "ratio": 1.5041347278867754,
      "runner": "bcc",
      "type": "tracing",
      "workload": "open_family_storm"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 74.57329218021022,
      "baseline_run_cnt_delta": 909449,
      "baseline_run_time_ns_delta": 67820606,
      "post_rejit_avg_ns_per_run": 92.1281679474249,
      "post_rejit_run_cnt_delta": 278611,
      "post_rejit_run_time_ns_delta": 25667921,
      "program": "raw_syscalls__s",
      "program_id": 35,
      "ratio": 1.235404328466449,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "file_open_storm"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 68.8209115924273,
      "baseline_run_cnt_delta": 909266,
      "baseline_run_time_ns_delta": 62576515,
      "post_rejit_avg_ns_per_run": 109.56121606683989,
      "post_rejit_run_cnt_delta": 278636,
      "post_rejit_run_time_ns_delta": 30527699,
      "program": "raw_syscalls__s",
      "program_id": 36,
      "ratio": 1.5919756587312548,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "file_open_storm"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 719.92,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 35996,
      "post_rejit_avg_ns_per_run": 732.0598290598291,
      "post_rejit_run_cnt_delta": 117,
      "post_rejit_run_time_ns_delta": 85651,
      "program": "trace_connect_e",
      "program_id": 39,
      "ratio": 1.0168627473327996,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 5977.08,
      "baseline_run_cnt_delta": 25,
      "baseline_run_time_ns_delta": 149427,
      "post_rejit_avg_ns_per_run": 4817.118644067797,
      "post_rejit_run_cnt_delta": 59,
      "post_rejit_run_time_ns_delta": 284210,
      "program": "trace_connect_v",
      "program_id": 40,
      "ratio": 0.8059317666934016,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 5672.64,
      "baseline_run_cnt_delta": 25,
      "baseline_run_time_ns_delta": 141816,
      "post_rejit_avg_ns_per_run": 4545.0344827586205,
      "post_rejit_run_cnt_delta": 58,
      "post_rejit_run_time_ns_delta": 263612,
      "program": "trace_connect_v",
      "program_id": 41,
      "ratio": 0.8012203282349347,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bcc/tcplife",
      "baseline_avg_ns_per_run": 956.2234042553191,
      "baseline_run_cnt_delta": 564,
      "baseline_run_time_ns_delta": 539310,
      "post_rejit_avg_ns_per_run": 1000.8026101141925,
      "post_rejit_run_cnt_delta": 1226,
      "post_rejit_run_time_ns_delta": 1226984,
      "program": "sock__inet_sock",
      "program_id": 44,
      "ratio": 1.0466200739915903,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "network"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 210.54220514878733,
      "baseline_run_cnt_delta": 87205,
      "baseline_run_time_ns_delta": 18360333,
      "post_rejit_avg_ns_per_run": 206.38066525500176,
      "post_rejit_run_cnt_delta": 105313,
      "post_rejit_run_time_ns_delta": 21734567,
      "program": "sched_switch",
      "program_id": 47,
      "ratio": 0.9802341773192473,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 140.0517754183075,
      "baseline_run_cnt_delta": 60183,
      "baseline_run_time_ns_delta": 8428736,
      "post_rejit_avg_ns_per_run": 143.29066051136363,
      "post_rejit_run_cnt_delta": 67584,
      "post_rejit_run_time_ns_delta": 9684156,
      "program": "sched_wakeup",
      "program_id": 48,
      "ratio": 1.0231263408363243,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 286.3818953323904,
      "baseline_run_cnt_delta": 2828,
      "baseline_run_time_ns_delta": 809888,
      "post_rejit_avg_ns_per_run": 290.01464530892446,
      "post_rejit_run_cnt_delta": 4370,
      "post_rejit_run_time_ns_delta": 1267364,
      "program": "sched_wakeup_ne",
      "program_id": 49,
      "ratio": 1.0126849847554702,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "cilium/agent",
      "baseline_avg_ns_per_run": 322.1531386525638,
      "baseline_run_cnt_delta": 4349,
      "baseline_run_time_ns_delta": 1401044,
      "post_rejit_avg_ns_per_run": 250.90492393915133,
      "post_rejit_run_cnt_delta": 9992,
      "post_rejit_run_time_ns_delta": 2507042,
      "program": "cil_from_netdev",
      "program_id": 235,
      "ratio": 0.7788374342357336,
      "runner": "cilium",
      "type": "sched_cls",
      "workload": "network"
    },
    {
      "app": "katran",
      "baseline_avg_ns_per_run": 50.03125,
      "baseline_run_cnt_delta": 1024,
      "baseline_run_time_ns_delta": 51232,
      "post_rejit_avg_ns_per_run": 57.646484375,
      "post_rejit_run_cnt_delta": 1024,
      "post_rejit_run_time_ns_delta": 59030,
      "program": "balancer_ingress",
      "program_id": 553,
      "ratio": 1.1522095565271706,
      "runner": "katran",
      "type": "xdp",
      "workload": "test_run"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 205.99182042968113,
      "baseline_run_cnt_delta": 857380,
      "baseline_run_time_ns_delta": 176613267,
      "post_rejit_avg_ns_per_run": 191.06507187840782,
      "post_rejit_run_cnt_delta": 823474,
      "post_rejit_run_time_ns_delta": 157337119,
      "program": "tracepoint__raw",
      "program_id": 570,
      "ratio": 0.9275371783202974,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 294.03938503394374,
      "baseline_run_cnt_delta": 857153,
      "baseline_run_time_ns_delta": 252036741,
      "post_rejit_avg_ns_per_run": 262.9205632667334,
      "post_rejit_run_cnt_delta": 823624,
      "post_rejit_run_time_ns_delta": 216547686,
      "program": "tracepoint__raw",
      "program_id": 573,
      "ratio": 0.8941678450197479,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 290.20045185397834,
      "baseline_run_cnt_delta": 856914,
      "baseline_run_time_ns_delta": 248676830,
      "post_rejit_avg_ns_per_run": 261.768929719441,
      "post_rejit_run_cnt_delta": 823784,
      "post_rejit_run_time_ns_delta": 215641056,
      "program": "trace_sys_enter",
      "program_id": 576,
      "ratio": 0.9020279880582566,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 284.26512835115795,
      "baseline_run_cnt_delta": 856868,
      "baseline_run_time_ns_delta": 243577692,
      "post_rejit_avg_ns_per_run": 254.69331900998992,
      "post_rejit_run_cnt_delta": 823830,
      "post_rejit_run_time_ns_delta": 209823997,
      "program": "trace_sys_exit",
      "program_id": 577,
      "ratio": 0.8959710270735796,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 801.704081632653,
      "baseline_run_cnt_delta": 98,
      "baseline_run_time_ns_delta": 78567,
      "post_rejit_avg_ns_per_run": 724.9042553191489,
      "post_rejit_run_cnt_delta": 94,
      "post_rejit_run_time_ns_delta": 68141,
      "program": "trace_ptrace",
      "program_id": 578,
      "ratio": 0.9042042717842936,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2549.122448979592,
      "baseline_run_cnt_delta": 98,
      "baseline_run_time_ns_delta": 249814,
      "post_rejit_avg_ns_per_run": 2356.446808510638,
      "post_rejit_run_cnt_delta": 94,
      "post_rejit_run_time_ns_delta": 221506,
      "program": "trace_ret_ptrac",
      "program_id": 579,
      "ratio": 0.9244149136319123,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 459.0204081632653,
      "baseline_run_cnt_delta": 49,
      "baseline_run_time_ns_delta": 22492,
      "post_rejit_avg_ns_per_run": 488.48936170212767,
      "post_rejit_run_cnt_delta": 47,
      "post_rejit_run_time_ns_delta": 22959,
      "program": "trace_process_v",
      "program_id": 580,
      "ratio": 1.0641996586966147,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3609.285714285714,
      "baseline_run_cnt_delta": 49,
      "baseline_run_time_ns_delta": 176855,
      "post_rejit_avg_ns_per_run": 3103.9574468085107,
      "post_rejit_run_cnt_delta": 47,
      "post_rejit_run_time_ns_delta": 145886,
      "program": "trace_ret_proce",
      "program_id": 581,
      "ratio": 0.8599921681242658,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1168.936507936508,
      "baseline_run_cnt_delta": 63,
      "baseline_run_time_ns_delta": 73643,
      "post_rejit_avg_ns_per_run": 1149.135593220339,
      "post_rejit_run_cnt_delta": 59,
      "post_rejit_run_time_ns_delta": 67799,
      "program": "trace_arch_prct",
      "program_id": 582,
      "ratio": 0.983060744033803,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3146.253968253968,
      "baseline_run_cnt_delta": 63,
      "baseline_run_time_ns_delta": 198214,
      "post_rejit_avg_ns_per_run": 2875.6271186440677,
      "post_rejit_run_cnt_delta": 59,
      "post_rejit_run_time_ns_delta": 169662,
      "program": "trace_ret_arch_",
      "program_id": 583,
      "ratio": 0.9139844232727066,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1205.3506493506493,
      "baseline_run_cnt_delta": 77,
      "baseline_run_time_ns_delta": 92812,
      "post_rejit_avg_ns_per_run": 1161.056338028169,
      "post_rejit_run_cnt_delta": 71,
      "post_rejit_run_time_ns_delta": 82435,
      "program": "trace_dup2",
      "program_id": 586,
      "ratio": 0.9632519289334247,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4186.649350649351,
      "baseline_run_cnt_delta": 77,
      "baseline_run_time_ns_delta": 322372,
      "post_rejit_avg_ns_per_run": 3502.4647887323945,
      "post_rejit_run_cnt_delta": 71,
      "post_rejit_run_time_ns_delta": 248675,
      "program": "trace_ret_dup2",
      "program_id": 587,
      "ratio": 0.8365794446552256,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 8393.334745762711,
      "baseline_run_cnt_delta": 236,
      "baseline_run_time_ns_delta": 1980827,
      "post_rejit_avg_ns_per_run": 7816.040358744394,
      "post_rejit_run_cnt_delta": 223,
      "post_rejit_run_time_ns_delta": 1742977,
      "program": "tracepoint__sch",
      "program_id": 595,
      "ratio": 0.9312199019216101,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 8545.126984126984,
      "baseline_run_cnt_delta": 63,
      "baseline_run_time_ns_delta": 538343,
      "post_rejit_avg_ns_per_run": 7629.728813559322,
      "post_rejit_run_cnt_delta": 59,
      "post_rejit_run_time_ns_delta": 450154,
      "program": "tracepoint__sch",
      "program_id": 603,
      "ratio": 0.8928748312028526,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2913.8771186440677,
      "baseline_run_cnt_delta": 236,
      "baseline_run_time_ns_delta": 687675,
      "post_rejit_avg_ns_per_run": 2739.4454545454546,
      "post_rejit_run_cnt_delta": 220,
      "post_rejit_run_time_ns_delta": 602678,
      "program": "tracepoint__sch",
      "program_id": 605,
      "ratio": 0.9401376046427852,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2244.8474576271187,
      "baseline_run_cnt_delta": 236,
      "baseline_run_time_ns_delta": 529784,
      "post_rejit_avg_ns_per_run": 2081.3,
      "post_rejit_run_cnt_delta": 220,
      "post_rejit_run_time_ns_delta": 457886,
      "program": "tracepoint__sch",
      "program_id": 606,
      "ratio": 0.9271454026546668,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 427.14690137830473,
      "baseline_run_cnt_delta": 897044,
      "baseline_run_time_ns_delta": 383169565,
      "post_rejit_avg_ns_per_run": 391.8933315817072,
      "post_rejit_run_cnt_delta": 890601,
      "post_rejit_run_time_ns_delta": 349020593,
      "program": "tracepoint__sch",
      "program_id": 608,
      "ratio": 0.9174673404328993,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 19.29968576889436,
      "baseline_run_cnt_delta": 30869,
      "baseline_run_time_ns_delta": 595762,
      "post_rejit_avg_ns_per_run": 17.963405057326842,
      "post_rejit_run_cnt_delta": 12734,
      "post_rejit_run_time_ns_delta": 228746,
      "program": "trace_filldir64",
      "program_id": 609,
      "ratio": 0.9307615301322043,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2280.0381355932204,
      "baseline_run_cnt_delta": 236,
      "baseline_run_time_ns_delta": 538089,
      "post_rejit_avg_ns_per_run": 2089.181818181818,
      "post_rejit_run_cnt_delta": 220,
      "post_rejit_run_time_ns_delta": 459620,
      "program": "trace_do_exit",
      "program_id": 611,
      "ratio": 0.9162924889579773,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1051.3645833333333,
      "baseline_run_cnt_delta": 288,
      "baseline_run_time_ns_delta": 302793,
      "post_rejit_avg_ns_per_run": 918.5347985347985,
      "post_rejit_run_cnt_delta": 273,
      "post_rejit_run_time_ns_delta": 250760,
      "program": "trace_security_",
      "program_id": 615,
      "ratio": 0.8736596353879449,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4318.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 4318,
      "post_rejit_avg_ns_per_run": 2723.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 2723,
      "program": "tracepoint__cgr",
      "program_id": 617,
      "ratio": 0.6306160259379342,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1827.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1827,
      "post_rejit_avg_ns_per_run": 2039.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 2039,
      "program": "tracepoint__cgr",
      "program_id": 618,
      "ratio": 1.1160372194854953,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1590.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1590,
      "post_rejit_avg_ns_per_run": 2421.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 2421,
      "program": "tracepoint__cgr",
      "program_id": 619,
      "ratio": 1.5226415094339623,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4679.507936507936,
      "baseline_run_cnt_delta": 63,
      "baseline_run_time_ns_delta": 294809,
      "post_rejit_avg_ns_per_run": 4691.135593220339,
      "post_rejit_run_cnt_delta": 59,
      "post_rejit_run_time_ns_delta": 276777,
      "program": "trace_security_",
      "program_id": 620,
      "ratio": 1.002484803289185,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1436.4492869732414,
      "baseline_run_cnt_delta": 6241,
      "baseline_run_time_ns_delta": 8964880,
      "post_rejit_avg_ns_per_run": 1388.5555789473685,
      "post_rejit_run_cnt_delta": 4750,
      "post_rejit_run_time_ns_delta": 6595639,
      "program": "trace_security_file_open",
      "program_id": 621,
      "ratio": 0.9666582673957184,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3100.310185185185,
      "baseline_run_cnt_delta": 216,
      "baseline_run_time_ns_delta": 669667,
      "post_rejit_avg_ns_per_run": 2645.531707317073,
      "post_rejit_run_cnt_delta": 205,
      "post_rejit_run_time_ns_delta": 542334,
      "program": "trace_security_",
      "program_id": 623,
      "ratio": 0.8533119427722851,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 725.7177700348432,
      "baseline_run_cnt_delta": 287,
      "baseline_run_time_ns_delta": 208281,
      "post_rejit_avg_ns_per_run": 1230.764705882353,
      "post_rejit_run_cnt_delta": 119,
      "post_rejit_run_time_ns_delta": 146461,
      "program": "trace_commit_cr",
      "program_id": 624,
      "ratio": 1.695927475805452,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1521.0127118644068,
      "baseline_run_cnt_delta": 236,
      "baseline_run_time_ns_delta": 358959,
      "post_rejit_avg_ns_per_run": 1332.2272727272727,
      "post_rejit_run_cnt_delta": 220,
      "post_rejit_run_time_ns_delta": 293090,
      "program": "trace_switch_ta",
      "program_id": 625,
      "ratio": 0.8758817479534887,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 210.96504233566384,
      "baseline_run_cnt_delta": 28463,
      "baseline_run_time_ns_delta": 6004698,
      "post_rejit_avg_ns_per_run": 205.4534620837644,
      "post_rejit_run_cnt_delta": 26097,
      "post_rejit_run_time_ns_delta": 5361719,
      "program": "trace_cap_capab",
      "program_id": 626,
      "ratio": 0.9738744381965898,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1627.59,
      "baseline_run_cnt_delta": 200,
      "baseline_run_time_ns_delta": 325518,
      "post_rejit_avg_ns_per_run": 1537.6894736842105,
      "post_rejit_run_cnt_delta": 190,
      "post_rejit_run_time_ns_delta": 292161,
      "program": "trace_security_",
      "program_id": 627,
      "ratio": 0.9447646358629695,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4071.387755102041,
      "baseline_run_cnt_delta": 49,
      "baseline_run_time_ns_delta": 199498,
      "post_rejit_avg_ns_per_run": 3555.978723404255,
      "post_rejit_run_cnt_delta": 47,
      "post_rejit_run_time_ns_delta": 167131,
      "program": "trace_security_",
      "program_id": 628,
      "ratio": 0.8734070389016857,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3085.5714285714284,
      "baseline_run_cnt_delta": 49,
      "baseline_run_time_ns_delta": 151193,
      "post_rejit_avg_ns_per_run": 2529.404255319149,
      "post_rejit_run_cnt_delta": 47,
      "post_rejit_run_time_ns_delta": 118882,
      "program": "trace_security_",
      "program_id": 632,
      "ratio": 0.8197522934966454,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2849.98,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 142499,
      "post_rejit_avg_ns_per_run": 2810.4893617021276,
      "post_rejit_run_cnt_delta": 47,
      "post_rejit_run_time_ns_delta": 132093,
      "program": "trace_security_",
      "program_id": 633,
      "ratio": 0.9861435384466304,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4251.384615384615,
      "baseline_run_cnt_delta": 143,
      "baseline_run_time_ns_delta": 607948,
      "post_rejit_avg_ns_per_run": 3878.6666666666665,
      "post_rejit_run_cnt_delta": 141,
      "post_rejit_run_time_ns_delta": 546892,
      "program": "trace_security_",
      "program_id": 634,
      "ratio": 0.9123302212250609,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2988.326923076923,
      "baseline_run_cnt_delta": 52,
      "baseline_run_time_ns_delta": 155393,
      "post_rejit_avg_ns_per_run": 2610.938775510204,
      "post_rejit_run_cnt_delta": 49,
      "post_rejit_run_time_ns_delta": 127936,
      "program": "trace_security_",
      "program_id": 635,
      "ratio": 0.873712563156195,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2690.4,
      "baseline_run_cnt_delta": 65,
      "baseline_run_time_ns_delta": 174876,
      "post_rejit_avg_ns_per_run": 2656.0943396226417,
      "post_rejit_run_cnt_delta": 53,
      "post_rejit_run_time_ns_delta": 140773,
      "program": "trace_security_",
      "program_id": 636,
      "ratio": 0.9872488624823973,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 113.55939846017317,
      "baseline_run_cnt_delta": 41693,
      "baseline_run_time_ns_delta": 4734632,
      "post_rejit_avg_ns_per_run": 98.63049055430304,
      "post_rejit_run_cnt_delta": 38589,
      "post_rejit_run_time_ns_delta": 3806052,
      "program": "trace_vfs_write",
      "program_id": 639,
      "ratio": 0.8685365710958226,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 70.08883236550368,
      "baseline_run_cnt_delta": 41674,
      "baseline_run_time_ns_delta": 2920882,
      "post_rejit_avg_ns_per_run": 50.02930583266396,
      "post_rejit_run_cnt_delta": 38593,
      "post_rejit_run_time_ns_delta": 1930781,
      "program": "vfs_write_magic",
      "program_id": 640,
      "ratio": 0.7137985345763498,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 57.92257120234182,
      "baseline_run_cnt_delta": 41677,
      "baseline_run_time_ns_delta": 2414039,
      "post_rejit_avg_ns_per_run": 117.90548488224474,
      "post_rejit_run_cnt_delta": 38597,
      "post_rejit_run_time_ns_delta": 4550798,
      "program": "trace_ret_vfs_w",
      "program_id": 641,
      "ratio": 2.0355706322214817,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 56.93625498007968,
      "baseline_run_cnt_delta": 41666,
      "baseline_run_time_ns_delta": 2372306,
      "post_rejit_avg_ns_per_run": 61.409832246039144,
      "post_rejit_run_cnt_delta": 38628,
      "post_rejit_run_time_ns_delta": 2372139,
      "program": "vfs_write_magic",
      "program_id": 642,
      "ratio": 1.0785716810409227,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 158.58355437665782,
      "baseline_run_cnt_delta": 4524,
      "baseline_run_time_ns_delta": 717432,
      "post_rejit_avg_ns_per_run": 89.21385199240987,
      "post_rejit_run_cnt_delta": 5270,
      "post_rejit_run_time_ns_delta": 470157,
      "program": "trace_vfs_write",
      "program_id": 644,
      "ratio": 0.5625668584808906,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 66.17749778956676,
      "baseline_run_cnt_delta": 4524,
      "baseline_run_time_ns_delta": 299387,
      "post_rejit_avg_ns_per_run": 67.0055028462998,
      "post_rejit_run_cnt_delta": 5270,
      "post_rejit_run_time_ns_delta": 353119,
      "program": "vfs_writev_magi",
      "program_id": 645,
      "ratio": 1.0125118822014993,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 77.2236958443855,
      "baseline_run_cnt_delta": 4524,
      "baseline_run_time_ns_delta": 349360,
      "post_rejit_avg_ns_per_run": 57.45047438330171,
      "post_rejit_run_cnt_delta": 5270,
      "post_rejit_run_time_ns_delta": 302764,
      "program": "trace_ret_vfs_w",
      "program_id": 646,
      "ratio": 0.7439487809424574,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 163.7687886825818,
      "baseline_run_cnt_delta": 4524,
      "baseline_run_time_ns_delta": 740890,
      "post_rejit_avg_ns_per_run": 107.2696394686907,
      "post_rejit_run_cnt_delta": 5270,
      "post_rejit_run_time_ns_delta": 565311,
      "program": "vfs_writev_magi",
      "program_id": 647,
      "ratio": 0.6550066122587114,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 203.47778488093334,
      "baseline_run_cnt_delta": 12514,
      "baseline_run_time_ns_delta": 2546321,
      "post_rejit_avg_ns_per_run": 163.24766559036564,
      "post_rejit_run_cnt_delta": 11459,
      "post_rejit_run_time_ns_delta": 1870655,
      "program": "trace_vfs_read",
      "program_id": 654,
      "ratio": 0.802287412780178,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2545.8,
      "baseline_run_cnt_delta": 20,
      "baseline_run_time_ns_delta": 50916,
      "post_rejit_avg_ns_per_run": 400.64251861882195,
      "post_rejit_run_cnt_delta": 5908,
      "post_rejit_run_time_ns_delta": 2366996,
      "program": "trace_ret_vfs_r",
      "program_id": 655,
      "ratio": 0.15737391728290592,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 214.67020335985853,
      "baseline_run_cnt_delta": 4524,
      "baseline_run_time_ns_delta": 971168,
      "post_rejit_avg_ns_per_run": 135.67381404174574,
      "post_rejit_run_cnt_delta": 5270,
      "post_rejit_run_time_ns_delta": 715001,
      "program": "trace_vfs_readv",
      "program_id": 657,
      "ratio": 0.632010460316709,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 209.5079575596817,
      "baseline_run_cnt_delta": 4524,
      "baseline_run_time_ns_delta": 947814,
      "post_rejit_avg_ns_per_run": 130.72941176470587,
      "post_rejit_run_cnt_delta": 5270,
      "post_rejit_run_time_ns_delta": 688944,
      "program": "trace_ret_vfs_r",
      "program_id": 658,
      "ratio": 0.6239830376250292,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 238.8053053053053,
      "baseline_run_cnt_delta": 1998,
      "baseline_run_time_ns_delta": 477133,
      "post_rejit_avg_ns_per_run": 251.9343657817109,
      "post_rejit_run_cnt_delta": 1356,
      "post_rejit_run_time_ns_delta": 341623,
      "program": "trace_mmap_aler",
      "program_id": 660,
      "ratio": 1.0549780938058329,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 166.76327769347498,
      "baseline_run_cnt_delta": 1318,
      "baseline_run_time_ns_delta": 219794,
      "post_rejit_avg_ns_per_run": 146.78618421052633,
      "post_rejit_run_cnt_delta": 1216,
      "post_rejit_run_time_ns_delta": 178492,
      "program": "trace_do_mmap",
      "program_id": 661,
      "ratio": 0.8802068791207844,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 55.04931714719272,
      "baseline_run_cnt_delta": 1318,
      "baseline_run_time_ns_delta": 72555,
      "post_rejit_avg_ns_per_run": 229.93503289473685,
      "post_rejit_run_cnt_delta": 1216,
      "post_rejit_run_time_ns_delta": 279601,
      "program": "trace_ret_do_mm",
      "program_id": 662,
      "ratio": 4.176891645720669,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1455.4742033383916,
      "baseline_run_cnt_delta": 1318,
      "baseline_run_time_ns_delta": 1918315,
      "post_rejit_avg_ns_per_run": 1349.6151315789473,
      "post_rejit_run_cnt_delta": 1216,
      "post_rejit_run_time_ns_delta": 1641132,
      "program": "trace_security_mmap_file",
      "program_id": 663,
      "ratio": 0.9272683284137654,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2257.7124463519312,
      "baseline_run_cnt_delta": 233,
      "baseline_run_time_ns_delta": 526047,
      "post_rejit_avg_ns_per_run": 2010.6666666666667,
      "post_rejit_run_cnt_delta": 216,
      "post_rejit_run_time_ns_delta": 434304,
      "program": "trace_security_file_mprotect",
      "program_id": 664,
      "ratio": 0.8905769509822,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 588.8205565989415,
      "baseline_run_cnt_delta": 11714,
      "baseline_run_time_ns_delta": 6897444,
      "post_rejit_avg_ns_per_run": 623.439005371686,
      "post_rejit_run_cnt_delta": 11542,
      "post_rejit_run_time_ns_delta": 7195733,
      "program": "trace_security_",
      "program_id": 666,
      "ratio": 1.0587928671728148,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 447.41342121030556,
      "baseline_run_cnt_delta": 3338,
      "baseline_run_time_ns_delta": 1493466,
      "post_rejit_avg_ns_per_run": 442.3334375,
      "post_rejit_run_cnt_delta": 3200,
      "post_rejit_run_time_ns_delta": 1415467,
      "program": "trace_security_",
      "program_id": 669,
      "ratio": 0.9886458843890654,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1244.4067164179105,
      "baseline_run_cnt_delta": 268,
      "baseline_run_time_ns_delta": 333501,
      "post_rejit_avg_ns_per_run": 1173.0559701492537,
      "post_rejit_run_cnt_delta": 268,
      "post_rejit_run_time_ns_delta": 314379,
      "program": "trace_security_",
      "program_id": 670,
      "ratio": 0.9426628405911825,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4216.833333333333,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 50602,
      "post_rejit_avg_ns_per_run": 3090.7,
      "post_rejit_run_cnt_delta": 10,
      "post_rejit_run_time_ns_delta": 30907,
      "program": "trace_security_",
      "program_id": 674,
      "ratio": 0.7329433619224537,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5172.5,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 62070,
      "post_rejit_avg_ns_per_run": 3882.9,
      "post_rejit_run_cnt_delta": 10,
      "post_rejit_run_time_ns_delta": 38829,
      "program": "trace_security_",
      "program_id": 675,
      "ratio": 0.750681488641856,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3692.0,
      "baseline_run_cnt_delta": 49,
      "baseline_run_time_ns_delta": 180908,
      "post_rejit_avg_ns_per_run": 3310.9574468085107,
      "post_rejit_run_cnt_delta": 47,
      "post_rejit_run_time_ns_delta": 155615,
      "program": "trace_security_",
      "program_id": 676,
      "ratio": 0.8967923745418501,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 11215.833333333334,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 134590,
      "post_rejit_avg_ns_per_run": 7645.3,
      "post_rejit_run_cnt_delta": 10,
      "post_rejit_run_time_ns_delta": 76453,
      "program": "tracepoint__mod",
      "program_id": 680,
      "ratio": 0.6816524258860241,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 12148.833333333334,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 145786,
      "post_rejit_avg_ns_per_run": 8152.6,
      "post_rejit_run_cnt_delta": 10,
      "post_rejit_run_time_ns_delta": 81526,
      "program": "tracepoint__mod",
      "program_id": 681,
      "ratio": 0.6710603212928539,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 655.0,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 7860,
      "post_rejit_avg_ns_per_run": 554.3,
      "post_rejit_run_cnt_delta": 10,
      "post_rejit_run_time_ns_delta": 5543,
      "program": "trace_do_init_m",
      "program_id": 682,
      "ratio": 0.8462595419847327,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 377.5833333333333,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 4531,
      "post_rejit_avg_ns_per_run": 216.2,
      "post_rejit_run_cnt_delta": 10,
      "post_rejit_run_time_ns_delta": 2162,
      "program": "trace_ret_do_in",
      "program_id": 683,
      "ratio": 0.5725888324873096,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2695.0079365079364,
      "baseline_run_cnt_delta": 126,
      "baseline_run_time_ns_delta": 339571,
      "post_rejit_avg_ns_per_run": 2471.822033898305,
      "post_rejit_run_cnt_delta": 118,
      "post_rejit_run_time_ns_delta": 291675,
      "program": "trace_load_elf_",
      "program_id": 684,
      "ratio": 0.9171854377175508,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 69.89730479479996,
      "baseline_run_cnt_delta": 73538,
      "baseline_run_time_ns_delta": 5140108,
      "post_rejit_avg_ns_per_run": 49.65658102651138,
      "post_rejit_run_cnt_delta": 68348,
      "post_rejit_run_time_ns_delta": 3393928,
      "program": "trace_security_",
      "program_id": 685,
      "ratio": 0.7104219708083165,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3613.3076923076924,
      "baseline_run_cnt_delta": 65,
      "baseline_run_time_ns_delta": 234865,
      "post_rejit_avg_ns_per_run": 3523.27868852459,
      "post_rejit_run_cnt_delta": 61,
      "post_rejit_run_time_ns_delta": 214920,
      "program": "tracepoint__tas",
      "program_id": 686,
      "ratio": 0.9750840472360648,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4436.959183673469,
      "baseline_run_cnt_delta": 49,
      "baseline_run_time_ns_delta": 217411,
      "post_rejit_avg_ns_per_run": 3744.340425531915,
      "post_rejit_run_cnt_delta": 47,
      "post_rejit_run_time_ns_delta": 175984,
      "program": "trace_security_",
      "program_id": 687,
      "ratio": 0.8438978747674398,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 797.6656217345873,
      "baseline_run_cnt_delta": 957,
      "baseline_run_time_ns_delta": 763366,
      "post_rejit_avg_ns_per_run": 740.3912515188335,
      "post_rejit_run_cnt_delta": 823,
      "post_rejit_run_time_ns_delta": 609342,
      "program": "trace_do_sigact",
      "program_id": 690,
      "ratio": 0.9281975195430812,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4446.074626865671,
      "baseline_run_cnt_delta": 67,
      "baseline_run_time_ns_delta": 297887,
      "post_rejit_avg_ns_per_run": 3841.0,
      "post_rejit_run_cnt_delta": 62,
      "post_rejit_run_time_ns_delta": 238142,
      "program": "trace_vfs_utime",
      "program_id": 691,
      "ratio": 0.8639081262357875,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2081.4742535698833,
      "baseline_run_cnt_delta": 2311,
      "baseline_run_time_ns_delta": 4810287,
      "post_rejit_avg_ns_per_run": 1665.758389261745,
      "post_rejit_run_cnt_delta": 2682,
      "post_rejit_run_time_ns_delta": 4467564,
      "program": "trace_do_trunca",
      "program_id": 693,
      "ratio": 0.8002781616946956,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 386.1812783416109,
      "baseline_run_cnt_delta": 9262,
      "baseline_run_time_ns_delta": 3576811,
      "post_rejit_avg_ns_per_run": 367.5864172967237,
      "post_rejit_run_cnt_delta": 7539,
      "post_rejit_run_time_ns_delta": 2771234,
      "program": "trace_fd_instal",
      "program_id": 694,
      "ratio": 0.9518493979699388,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1106.6994978756277,
      "baseline_run_cnt_delta": 7767,
      "baseline_run_time_ns_delta": 8595735,
      "post_rejit_avg_ns_per_run": 1061.534177559913,
      "post_rejit_run_cnt_delta": 7344,
      "post_rejit_run_time_ns_delta": 7795907,
      "program": "trace_filp_clos",
      "program_id": 695,
      "ratio": 0.9591891742949082,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 146.8304987027962,
      "baseline_run_cnt_delta": 6938,
      "baseline_run_time_ns_delta": 1018710,
      "post_rejit_avg_ns_per_run": 124.94121302510564,
      "post_rejit_run_cnt_delta": 8046,
      "post_rejit_run_time_ns_delta": 1005277,
      "program": "trace_file_upda",
      "program_id": 696,
      "ratio": 0.8509213966371026,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 74.05520322859614,
      "baseline_run_cnt_delta": 6938,
      "baseline_run_time_ns_delta": 513795,
      "post_rejit_avg_ns_per_run": 55.463584389758886,
      "post_rejit_run_cnt_delta": 8046,
      "post_rejit_run_time_ns_delta": 446260,
      "program": "trace_ret_file_",
      "program_id": 697,
      "ratio": 0.7489491888713341,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 959.0816326530612,
      "baseline_run_cnt_delta": 49,
      "baseline_run_time_ns_delta": 46995,
      "post_rejit_avg_ns_per_run": 728.4893617021277,
      "post_rejit_run_cnt_delta": 47,
      "post_rejit_run_time_ns_delta": 34239,
      "program": "trace_inotify_f",
      "program_id": 700,
      "ratio": 0.7595697142973562,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 603.4285714285714,
      "baseline_run_cnt_delta": 49,
      "baseline_run_time_ns_delta": 29568,
      "post_rejit_avg_ns_per_run": 1097.2978723404256,
      "post_rejit_run_cnt_delta": 47,
      "post_rejit_run_time_ns_delta": 51573,
      "program": "trace_ret_inoti",
      "program_id": 701,
      "ratio": 1.8184387088974854,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 169.23809523809524,
      "baseline_run_cnt_delta": 63,
      "baseline_run_time_ns_delta": 10662,
      "post_rejit_avg_ns_per_run": 358.3728813559322,
      "post_rejit_run_cnt_delta": 59,
      "post_rejit_run_time_ns_delta": 21144,
      "program": "trace_exec_binp",
      "program_id": 703,
      "ratio": 2.11756626574974,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 6326.825396825397,
      "baseline_run_cnt_delta": 63,
      "baseline_run_time_ns_delta": 398590,
      "post_rejit_avg_ns_per_run": 5827.203389830508,
      "post_rejit_run_cnt_delta": 59,
      "post_rejit_run_time_ns_delta": 343805,
      "program": "trace_security_",
      "program_id": 704,
      "ratio": 0.921031168768213,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5436.723214285715,
      "baseline_run_cnt_delta": 112,
      "baseline_run_time_ns_delta": 608913,
      "post_rejit_avg_ns_per_run": 4973.396226415094,
      "post_rejit_run_cnt_delta": 106,
      "post_rejit_run_time_ns_delta": 527180,
      "program": "trace_execute_f",
      "program_id": 705,
      "ratio": 0.9147782644786537,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4783.428571428572,
      "baseline_run_cnt_delta": 49,
      "baseline_run_time_ns_delta": 234388,
      "post_rejit_avg_ns_per_run": 4528.553191489362,
      "post_rejit_run_cnt_delta": 47,
      "post_rejit_run_time_ns_delta": 212842,
      "program": "trace_security_",
      "program_id": 706,
      "ratio": 0.9467170093305917,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3755.6923076923076,
      "baseline_run_cnt_delta": 13,
      "baseline_run_time_ns_delta": 48824,
      "post_rejit_avg_ns_per_run": 3023.2727272727275,
      "post_rejit_run_cnt_delta": 11,
      "post_rejit_run_time_ns_delta": 33256,
      "program": "trace_set_fs_pw",
      "program_id": 707,
      "ratio": 0.8049841359688976,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4555.163265306122,
      "baseline_run_cnt_delta": 49,
      "baseline_run_time_ns_delta": 223203,
      "post_rejit_avg_ns_per_run": 4255.340425531915,
      "post_rejit_run_cnt_delta": 47,
      "post_rejit_run_time_ns_delta": 200001,
      "program": "trace_chmod_com",
      "program_id": 710,
      "ratio": 0.9341795623314374,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1550.5714285714287,
      "baseline_run_cnt_delta": 14,
      "baseline_run_time_ns_delta": 21708,
      "post_rejit_avg_ns_per_run": 1391.0714285714287,
      "post_rejit_run_cnt_delta": 14,
      "post_rejit_run_time_ns_delta": 19475,
      "program": "trace_security_task_prctl",
      "program_id": 711,
      "ratio": 0.8971346968859407,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 409.03779069767444,
      "baseline_run_cnt_delta": 344,
      "baseline_run_time_ns_delta": 140709,
      "post_rejit_avg_ns_per_run": 421.75757575757575,
      "post_rejit_run_cnt_delta": 330,
      "post_rejit_run_time_ns_delta": 139180,
      "program": "trace_sock_allo",
      "program_id": 714,
      "ratio": 1.0310968456929268,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1754.5552325581396,
      "baseline_run_cnt_delta": 344,
      "baseline_run_time_ns_delta": 603567,
      "post_rejit_avg_ns_per_run": 1580.4030303030304,
      "post_rejit_run_cnt_delta": 330,
      "post_rejit_run_time_ns_delta": 521533,
      "program": "trace_ret_sock_",
      "program_id": 715,
      "ratio": 0.9007428213011024,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2092.02,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 104601,
      "post_rejit_avg_ns_per_run": 1963.4255319148936,
      "post_rejit_run_cnt_delta": 47,
      "post_rejit_run_time_ns_delta": 92281,
      "program": "trace_security_",
      "program_id": 716,
      "ratio": 0.938530956642333,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 326.5613382899628,
      "baseline_run_cnt_delta": 269,
      "baseline_run_time_ns_delta": 87845,
      "post_rejit_avg_ns_per_run": 186.61212121212122,
      "post_rejit_run_cnt_delta": 165,
      "post_rejit_run_time_ns_delta": 30791,
      "program": "trace_security_",
      "program_id": 717,
      "ratio": 0.5714458490074633,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 506.08383233532936,
      "baseline_run_cnt_delta": 167,
      "baseline_run_time_ns_delta": 84516,
      "post_rejit_avg_ns_per_run": 335.9809523809524,
      "post_rejit_run_cnt_delta": 105,
      "post_rejit_run_time_ns_delta": 35278,
      "program": "trace_security_",
      "program_id": 718,
      "ratio": 0.6638839870275338,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1578.271918678526,
      "baseline_run_cnt_delta": 787,
      "baseline_run_time_ns_delta": 1242100,
      "post_rejit_avg_ns_per_run": 1711.7104,
      "post_rejit_run_cnt_delta": 625,
      "post_rejit_run_time_ns_delta": 1069819,
      "program": "cgroup_bpf_run_",
      "program_id": 719,
      "ratio": 1.084547206183077,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2424.0648967551624,
      "baseline_run_cnt_delta": 339,
      "baseline_run_time_ns_delta": 821758,
      "post_rejit_avg_ns_per_run": 2496.7173144876324,
      "post_rejit_run_cnt_delta": 283,
      "post_rejit_run_time_ns_delta": 706571,
      "program": "cgroup_skb_ingr",
      "program_id": 721,
      "ratio": 1.0299713171168488,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3385.533923303835,
      "baseline_run_cnt_delta": 339,
      "baseline_run_time_ns_delta": 1147696,
      "post_rejit_avg_ns_per_run": 3516.572438162544,
      "post_rejit_run_cnt_delta": 283,
      "post_rejit_run_time_ns_delta": 995190,
      "program": "cgroup_skb_egre",
      "program_id": 722,
      "ratio": 1.038705420718642,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2511.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 2511,
      "post_rejit_avg_ns_per_run": 2278.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 2278,
      "program": "cgroup_mkdir_si",
      "program_id": 723,
      "ratio": 0.9072082835523696,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2297.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 2297,
      "post_rejit_avg_ns_per_run": 2650.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 2650,
      "program": "cgroup_rmdir_si",
      "program_id": 724,
      "ratio": 1.153678711362647,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 161.06349206349208,
      "baseline_run_cnt_delta": 63,
      "baseline_run_time_ns_delta": 10147,
      "post_rejit_avg_ns_per_run": 178.5593220338983,
      "post_rejit_run_cnt_delta": 59,
      "post_rejit_run_time_ns_delta": 10535,
      "program": "empty_kprobe",
      "program_id": 725,
      "ratio": 1.108626913189671,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1310.1904761904761,
      "baseline_run_cnt_delta": 63,
      "baseline_run_time_ns_delta": 82542,
      "post_rejit_avg_ns_per_run": 1242.406779661017,
      "post_rejit_run_cnt_delta": 59,
      "post_rejit_run_time_ns_delta": 73302,
      "program": "tracepoint__exe",
      "program_id": 726,
      "ratio": 0.9482642426721436,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 768.7189552956257,
      "baseline_run_cnt_delta": 6241,
      "baseline_run_time_ns_delta": 4797575,
      "post_rejit_avg_ns_per_run": 778.6686315789474,
      "post_rejit_run_cnt_delta": 4750,
      "post_rejit_run_time_ns_delta": 3698676,
      "program": "lsm_file_open_t",
      "program_id": 727,
      "ratio": 1.0129431910255098,
      "runner": "tracee",
      "type": "lsm",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "bpftrace/capable",
      "baseline_avg_ns_per_run": 207.74419435201477,
      "baseline_run_cnt_delta": 114802,
      "baseline_run_time_ns_delta": 23849449,
      "post_rejit_avg_ns_per_run": 114.01909209946719,
      "post_rejit_run_cnt_delta": 165723,
      "post_rejit_run_time_ns_delta": 18895586,
      "program": "cap_capable",
      "program_id": 734,
      "ratio": 0.5488436991229035,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 249.00137621735874,
      "baseline_run_cnt_delta": 598016,
      "baseline_run_time_ns_delta": 148906807,
      "post_rejit_avg_ns_per_run": 141.44958917025863,
      "post_rejit_run_cnt_delta": 712704,
      "post_rejit_run_time_ns_delta": 100811688,
      "program": "block_io_start",
      "program_id": 740,
      "ratio": 0.5680674995417865,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 358.2687102017337,
      "baseline_run_cnt_delta": 598016,
      "baseline_run_time_ns_delta": 214250421,
      "post_rejit_avg_ns_per_run": 299.2936773190553,
      "post_rejit_run_cnt_delta": 712704,
      "post_rejit_run_time_ns_delta": 213307801,
      "program": "block_io_done",
      "program_id": 741,
      "ratio": 0.8353888263100878,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 1938.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1938,
      "post_rejit_avg_ns_per_run": 1473.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1473,
      "program": "1",
      "program_id": 747,
      "ratio": 0.760061919504644,
      "runner": "bpftrace",
      "type": "perf_event",
      "workload": "vfs_create_write_fsync"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 108.54768153980753,
      "baseline_run_cnt_delta": 12573,
      "baseline_run_time_ns_delta": 1364770,
      "post_rejit_avg_ns_per_run": 68.77901950448076,
      "post_rejit_run_cnt_delta": 9485,
      "post_rejit_run_time_ns_delta": 652369,
      "program": "vfs_create",
      "program_id": 748,
      "ratio": 0.6336295582624446,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "vfs_create_write_fsync"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 127.37657786803648,
      "baseline_run_cnt_delta": 75339,
      "baseline_run_time_ns_delta": 9596424,
      "post_rejit_avg_ns_per_run": 113.90655890219793,
      "post_rejit_run_cnt_delta": 85990,
      "post_rejit_run_time_ns_delta": 9794825,
      "program": "sched_wakeup",
      "program_id": 754,
      "ratio": 0.894250425067993,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 324.9228832951945,
      "baseline_run_cnt_delta": 4370,
      "baseline_run_time_ns_delta": 1419913,
      "post_rejit_avg_ns_per_run": 246.60503685503684,
      "post_rejit_run_cnt_delta": 4884,
      "post_rejit_run_time_ns_delta": 1204419,
      "program": "sched_wakeup_ne",
      "program_id": 755,
      "ratio": 0.7589648176025652,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 210.31624825074607,
      "baseline_run_cnt_delta": 118622,
      "baseline_run_time_ns_delta": 24948134,
      "post_rejit_avg_ns_per_run": 173.20024601886638,
      "post_rejit_run_cnt_delta": 134949,
      "post_rejit_run_time_ns_delta": 23373200,
      "program": "sched_switch",
      "program_id": 756,
      "ratio": 0.8235228968727668,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline_avg_ns_per_run": 1071.9106870229007,
      "baseline_run_cnt_delta": 1310,
      "baseline_run_time_ns_delta": 1404203,
      "post_rejit_avg_ns_per_run": 788.1736745886654,
      "post_rejit_run_cnt_delta": 1641,
      "post_rejit_run_time_ns_delta": 1293393,
      "program": "tcp_set_state",
      "program_id": 763,
      "ratio": 0.7352978976053689,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bpftrace/tcpretrans",
      "baseline_avg_ns_per_run": 5209.894736842105,
      "baseline_run_cnt_delta": 19,
      "baseline_run_time_ns_delta": 98988,
      "post_rejit_avg_ns_per_run": 4384.555555555556,
      "post_rejit_run_cnt_delta": 18,
      "post_rejit_run_time_ns_delta": 78922,
      "program": "tcp_retransmit_",
      "program_id": 769,
      "ratio": 0.841582369131163,
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
            "avg_ns_per_run": 115.24227294341416,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 109356,
            "run_time_ns_delta": 12602434,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.093068365000022,
            "ops_per_sec": 775.7977699775283,
            "ops_total": 848.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5042] setting to a 1 secs run per stressor\nstress-ng: info:  [5042] dispatching hogs: 2 exec\nstress-ng: info:  [5042] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5042] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5042]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5042] exec                848      1.04      2.24      1.12       814.92         252.07\nstress-ng: info:  [5042] skipped: 0\nstress-ng: info:  [5042] passed: 2: exec (2)\nstress-ng: info:  [5042] failed: 0\nstress-ng: info:  [5042] metrics untrustworthy: 0\nstress-ng: info:  [5042] successful run completed in 1.06 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 71.0910739145919,
            "bytes_jited": 206,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 123548,
            "run_time_ns_delta": 8783160,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0764290600000095,
            "ops_per_sec": 975.4474670165359,
            "ops_total": 1050.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [32205] setting to a 1 secs run per stressor\nstress-ng: info:  [32205] dispatching hogs: 2 exec\nstress-ng: info:  [32205] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [32205] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [32205]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [32205] exec               1050      1.04      2.58      1.05      1009.97         288.61\nstress-ng: info:  [32205] skipped: 0\nstress-ng: info:  [32205] passed: 2: exec (2)\nstress-ng: info:  [32205] failed: 0\nstress-ng: info:  [32205] metrics untrustworthy: 0\nstress-ng: info:  [32205] successful run completed in 1.05 secs"
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
            "avg_ns_per_run": 2138.8267223382045,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 958,
            "run_time_ns_delta": 2048996,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 1651.071676300578,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 865,
            "run_time_ns_delta": 1428177,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.091630562999967,
            "ops_per_sec": 874.838093004207,
            "ops_total": 955.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [7723] setting to a 1 secs run per stressor\nstress-ng: info:  [7723] dispatching hogs: 2 exec\nstress-ng: info:  [7723] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7723] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7723]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7723] exec                955      1.04      2.30      1.01       914.50         288.76\nstress-ng: info:  [7723] skipped: 0\nstress-ng: info:  [7723] passed: 2: exec (2)\nstress-ng: info:  [7723] failed: 0\nstress-ng: info:  [7723] metrics untrustworthy: 0\nstress-ng: info:  [7723] successful run completed in 1.06 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 2523.7481865284976,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 965,
            "run_time_ns_delta": 2435417,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 1938.2912087912089,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_exec",
            "run_cnt_delta": 910,
            "run_time_ns_delta": 1763845,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0650295220000316,
            "ops_per_sec": 903.2613464023501,
            "ops_total": 962.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [1336] setting to a 1 secs run per stressor\nstress-ng: info:  [1336] dispatching hogs: 2 exec\nstress-ng: info:  [1336] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [1336] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1336]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1336] exec                962      1.03      2.38      1.15       929.93         272.36\nstress-ng: info:  [1336] skipped: 0\nstress-ng: info:  [1336] passed: 2: exec (2)\nstress-ng: info:  [1336] failed: 0\nstress-ng: info:  [1336] metrics untrustworthy: 0\nstress-ng: info:  [1336] successful run completed in 1.04 secs"
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
            "avg_ns_per_run": 75.94110514463884,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 23092,
            "run_time_ns_delta": 1753632,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 875.1952191235059,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 11546,
            "run_time_ns_delta": 10105004,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": 880.2329811190023,
            "bytes_jited": 742,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_return",
            "run_cnt_delta": 11546,
            "run_time_ns_delta": 10163170,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.000084926999989,
            "ops_per_sec": 23090.03903225536,
            "ops_total": 23092.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 59.51622566150774,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 54081,
            "run_time_ns_delta": 3218697,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 737.9486705373322,
            "bytes_jited": 719,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_re",
            "run_cnt_delta": 27041,
            "run_time_ns_delta": 19954870,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": 754.0628328402366,
            "bytes_jited": 740,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_re",
            "run_cnt_delta": 27040,
            "run_time_ns_delta": 20389859,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.000003463999974,
            "ops_per_sec": 54080.81266406634,
            "ops_total": 54081.0,
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
        "output_chars": 12429,
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
            "avg_ns_per_run": 216.45670121130004,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 245769,
            "run_time_ns_delta": 53198347,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 234.03043915221204,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 245769,
            "run_time_ns_delta": 57517427,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 447.72971807318135,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 245773,
            "run_time_ns_delta": 110039876,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.002245185999982,
            "ops_per_sec": 49129.93882983186,
            "ops_total": 245760.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 218.62694119666597,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start",
            "run_cnt_delta": 524290,
            "run_time_ns_delta": 114623919,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 230.70796617152274,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 524292,
            "run_time_ns_delta": 120958341,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 426.4330841723998,
            "bytes_jited": 548,
            "bytes_xlated": 848,
            "id": 20,
            "name": "trace_req_compl",
            "run_cnt_delta": 524293,
            "run_time_ns_delta": 223575881,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.083138226999949,
            "ops_per_sec": 103142.58172543008,
            "ops_total": 524288.0,
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
        "output_chars": 13067,
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
            "avg_ns_per_run": 55.380514705882355,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 544,
            "run_time_ns_delta": 30127,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 34.3003355704698,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 5364,
            "run_time_ns_delta": 183987,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 28.789344951463733,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 13083,
            "run_time_ns_delta": 376651,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0004894259999446,
            "ops_per_sec": 93.9540164615445,
            "ops_total": 94.0,
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
            "avg_ns_per_run": 31.346020761245676,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 289,
            "run_time_ns_delta": 9059,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 38.590610636900855,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 3046,
            "run_time_ns_delta": 117547,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 31.178466557911907,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 6130,
            "run_time_ns_delta": 191124,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0015183660000275,
            "ops_per_sec": 97.8514257221293,
            "ops_total": 98.0,
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
            "avg_ns_per_run": 1356.8690890990542,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 2009,
            "run_time_ns_delta": 2725950,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 1272.7901907356948,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 734,
            "run_time_ns_delta": 934228,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0017813420000152,
            "ops_per_sec": 732.6948199440401,
            "ops_total": 734.0,
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
            "avg_ns_per_run": 1825.0907079646017,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 2260,
            "run_time_ns_delta": 4124705,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 1914.447927199191,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 989,
            "run_time_ns_delta": 1893389,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0004443980000133,
            "ops_per_sec": 988.5606856084239,
            "ops_total": 989.0,
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
            "avg_ns_per_run": 74.57329218021022,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 909449,
            "run_time_ns_delta": 67820606,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 68.8209115924273,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 909266,
            "run_time_ns_delta": 62576515,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.000332985,
            "ops_per_sec": 921.6930900264175,
            "ops_total": 922.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 92.1281679474249,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 278611,
            "run_time_ns_delta": 25667921,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 109.56121606683989,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 278636,
            "run_time_ns_delta": 30527699,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0001106549999577,
            "ops_per_sec": 1086.8797313233765,
            "ops_total": 1087.0,
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
            "avg_ns_per_run": 719.92,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 35996,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 5977.08,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 25,
            "run_time_ns_delta": 149427,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 5672.64,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 25,
            "run_time_ns_delta": 141816,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0153828129999738,
            "ops_per_sec": 49.24251165161419,
            "ops_total": 50.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 732.0598290598291,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_e",
            "run_cnt_delta": 117,
            "run_time_ns_delta": 85651,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4817.118644067797,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v",
            "run_cnt_delta": 59,
            "run_time_ns_delta": 284210,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 4545.0344827586205,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v",
            "run_cnt_delta": 58,
            "run_time_ns_delta": 263612,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0035293480000291,
            "ops_per_sec": 116.58851854524598,
            "ops_total": 117.0,
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
            "avg_ns_per_run": 956.2234042553191,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 564,
            "run_time_ns_delta": 539310,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0064509430000044,
            "ops_per_sec": 51.66670105648634,
            "ops_total": 52.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "44": {
            "avg_ns_per_run": 1000.8026101141925,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "sock__inet_sock",
            "run_cnt_delta": 1226,
            "run_time_ns_delta": 1226984,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.003116963000025,
            "ops_per_sec": 110.65509217193572,
            "ops_total": 111.0,
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
            "avg_ns_per_run": 210.54220514878733,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 87205,
            "run_time_ns_delta": 18360333,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 140.0517754183075,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 60183,
            "run_time_ns_delta": 8428736,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 286.3818953323904,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 2828,
            "run_time_ns_delta": 809888,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0021473520000086,
            "ops_per_sec": 10.976429741641333,
            "ops_total": 11.0,
            "stderr": "",
            "stdout": "Running in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.053\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.056\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.062\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.057\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.050\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.049\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.054\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.050\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.055\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.067\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.064"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 206.38066525500176,
            "bytes_jited": 645,
            "bytes_xlated": 1136,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 105313,
            "run_time_ns_delta": 21734567,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 143.29066051136363,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 67584,
            "run_time_ns_delta": 9684156,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 290.01464530892446,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 4370,
            "run_time_ns_delta": 1267364,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0340484199999764,
            "ops_per_sec": 16.44023594175637,
            "ops_total": 17.0,
            "stderr": "",
            "stdout": "Time: 0.054\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.049\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.054\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.041\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.032\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.034\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.038\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.034\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.035"
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
        "output_chars": 12832,
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
            "duration_s": 1.0132296539999857,
            "ops_per_sec": 568.4792166574392,
            "ops_total": 576.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    10.01ms    7.02ms  45.43ms   75.91%\n    Req/Sec   288.25     82.58   380.00     65.00%\n  576 requests in 1.01s, 87.46KB read\nRequests/sec:    572.79\nTransfer/sec:     86.97KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "102": {
            "avg_ns_per_run": 216429.0,
            "bytes_jited": 865,
            "bytes_xlated": 1544,
            "id": 102,
            "name": "conntrack_cleanup",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 216429,
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
            "duration_s": 1.007272960000023,
            "ops_per_sec": 1959.7468396252343,
            "ops_total": 1974.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     2.91ms    1.52ms  12.82ms   89.46%\n    Req/Sec     0.99k   374.45     1.80k    70.00%\n  1974 requests in 1.00s, 298.80KB read\nRequests/sec:   1970.07\nTransfer/sec:    298.20KB"
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
        "output_chars": 25747,
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
      "baseline": null,
      "error": "native CPU burner compile failed: error: unknown target triple 'unknown'",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "otelcol-ebpf-profiler",
      "selected_workload": "exec_storm",
      "status": "error"
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
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 213,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 215,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "216": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 216,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 217,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 218,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 220,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 222,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "223": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 223,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "224": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 224,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "228": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 228,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "231": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 231,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "232": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 232,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "233": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 233,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "235": {
            "avg_ns_per_run": 322.1531386525638,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 235,
            "name": "cil_from_netdev",
            "run_cnt_delta": 4349,
            "run_time_ns_delta": 1401044,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1103785610000045,
            "ops_per_sec": 694.3577866864064,
            "ops_total": 771.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     7.80ms    5.35ms  39.63ms   80.77%\n    Req/Sec   367.38    165.33   710.00     71.43%\n  771 requests in 1.10s, 116.97KB read\nRequests/sec:    698.97\nTransfer/sec:    106.05KB"
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
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 213,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 215,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "216": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 216,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 217,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 218,
            "name": "tail_drop_notif",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 220,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 222,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "223": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 223,
            "name": "tail_drop_notif",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "224": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 224,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "228": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 228,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "231": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 231,
            "name": "tail_drop_notif",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "232": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 232,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "233": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 233,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "235": {
            "avg_ns_per_run": 250.90492393915133,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 235,
            "name": "cil_from_netdev",
            "run_cnt_delta": 9992,
            "run_time_ns_delta": 2507042,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0061523660000375,
            "ops_per_sec": 1795.950654257004,
            "ops_total": 1807.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     3.15ms    1.70ms  14.94ms   87.84%\n    Req/Sec     0.91k   128.35     1.09k    65.00%\n  1807 requests in 1.00s, 273.52KB read\nRequests/sec:   1804.95\nTransfer/sec:    273.21KB"
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
        "output_chars": 101895,
        "output_stripped": true,
        "program_counts": {
          "applied": 16,
          "not_applied": 0,
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
            "avg_ns_per_run": 50.03125,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 553,
            "name": "balancer_ingress",
            "run_cnt_delta": 1024,
            "run_time_ns_delta": 51232,
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
            "duration_s": 1.0307651350000242,
            "ops_per_sec": 993.4367832493441,
            "ops_total": 1024.0,
            "stderr": "{'retval': 2, 'duration_ns': 73, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
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
            "avg_ns_per_run": 57.646484375,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 553,
            "name": "balancer_ingress",
            "run_cnt_delta": 1024,
            "run_time_ns_delta": 59030,
            "type": "xdp"
          },
          "555": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 555,
            "name": "healthcheck_enc",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.001534088000085,
            "ops_per_sec": 1022.4315001047804,
            "ops_total": 1024.0,
            "stderr": "{'retval': 2, 'duration_ns': 80, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
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
          "570": {
            "avg_ns_per_run": 205.99182042968113,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 570,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 857380,
            "run_time_ns_delta": 176613267,
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
            "avg_ns_per_run": 294.03938503394374,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 573,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 857153,
            "run_time_ns_delta": 252036741,
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
            "avg_ns_per_run": 290.20045185397834,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 576,
            "name": "trace_sys_enter",
            "run_cnt_delta": 856914,
            "run_time_ns_delta": 248676830,
            "type": "raw_tracepoint"
          },
          "577": {
            "avg_ns_per_run": 284.26512835115795,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 577,
            "name": "trace_sys_exit",
            "run_cnt_delta": 856868,
            "run_time_ns_delta": 243577692,
            "type": "raw_tracepoint"
          },
          "578": {
            "avg_ns_per_run": 801.704081632653,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 578,
            "name": "trace_ptrace",
            "run_cnt_delta": 98,
            "run_time_ns_delta": 78567,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": 2549.122448979592,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 579,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 98,
            "run_time_ns_delta": 249814,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": 459.0204081632653,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 580,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 22492,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": 3609.285714285714,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 581,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 176855,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": 1168.936507936508,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 582,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 73643,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": 3146.253968253968,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 583,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 198214,
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
            "avg_ns_per_run": 1205.3506493506493,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 586,
            "name": "trace_dup2",
            "run_cnt_delta": 77,
            "run_time_ns_delta": 92812,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 4186.649350649351,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 587,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 77,
            "run_time_ns_delta": 322372,
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
            "avg_ns_per_run": 8393.334745762711,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 595,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 236,
            "run_time_ns_delta": 1980827,
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
            "avg_ns_per_run": 20633.0,
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 598,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 20633,
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
            "avg_ns_per_run": 8545.126984126984,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 603,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 538343,
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
            "avg_ns_per_run": 2913.8771186440677,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 605,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 236,
            "run_time_ns_delta": 687675,
            "type": "raw_tracepoint"
          },
          "606": {
            "avg_ns_per_run": 2244.8474576271187,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 606,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 236,
            "run_time_ns_delta": 529784,
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
            "avg_ns_per_run": 427.14690137830473,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 608,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 897044,
            "run_time_ns_delta": 383169565,
            "type": "raw_tracepoint"
          },
          "609": {
            "avg_ns_per_run": 19.29968576889436,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 609,
            "name": "trace_filldir64",
            "run_cnt_delta": 30869,
            "run_time_ns_delta": 595762,
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
            "avg_ns_per_run": 2280.0381355932204,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 611,
            "name": "trace_do_exit",
            "run_cnt_delta": 236,
            "run_time_ns_delta": 538089,
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
            "avg_ns_per_run": 1051.3645833333333,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 615,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 288,
            "run_time_ns_delta": 302793,
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
            "avg_ns_per_run": 4318.0,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 617,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 4318,
            "type": "raw_tracepoint"
          },
          "618": {
            "avg_ns_per_run": 1827.0,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 618,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1827,
            "type": "raw_tracepoint"
          },
          "619": {
            "avg_ns_per_run": 1590.0,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 619,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1590,
            "type": "raw_tracepoint"
          },
          "620": {
            "avg_ns_per_run": 4679.507936507936,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 620,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 294809,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": 1436.4492869732414,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 621,
            "name": "trace_security_file_open",
            "run_cnt_delta": 6241,
            "run_time_ns_delta": 8964880,
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
            "avg_ns_per_run": 3100.310185185185,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 623,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 216,
            "run_time_ns_delta": 669667,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": 725.7177700348432,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 624,
            "name": "trace_commit_creds",
            "run_cnt_delta": 287,
            "run_time_ns_delta": 208281,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": 1521.0127118644068,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 625,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 236,
            "run_time_ns_delta": 358959,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 210.96504233566384,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 626,
            "name": "trace_cap_capable",
            "run_cnt_delta": 28463,
            "run_time_ns_delta": 6004698,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 1627.59,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 627,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 200,
            "run_time_ns_delta": 325518,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": 4071.387755102041,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 628,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 199498,
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
            "avg_ns_per_run": 3085.5714285714284,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 632,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 151193,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": 2849.98,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 633,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 142499,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 4251.384615384615,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 634,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 143,
            "run_time_ns_delta": 607948,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 2988.326923076923,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 635,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 52,
            "run_time_ns_delta": 155393,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": 2690.4,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 636,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 65,
            "run_time_ns_delta": 174876,
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
            "avg_ns_per_run": 113.55939846017317,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 639,
            "name": "trace_vfs_write",
            "run_cnt_delta": 41693,
            "run_time_ns_delta": 4734632,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": 70.08883236550368,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 640,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 41674,
            "run_time_ns_delta": 2920882,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": 57.92257120234182,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 641,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 41677,
            "run_time_ns_delta": 2414039,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": 56.93625498007968,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 642,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 41666,
            "run_time_ns_delta": 2372306,
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
            "avg_ns_per_run": 158.58355437665782,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 644,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 4524,
            "run_time_ns_delta": 717432,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": 66.17749778956676,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 645,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 4524,
            "run_time_ns_delta": 299387,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": 77.2236958443855,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 646,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 4524,
            "run_time_ns_delta": 349360,
            "type": "kprobe"
          },
          "647": {
            "avg_ns_per_run": 163.7687886825818,
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 647,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 4524,
            "run_time_ns_delta": 740890,
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
            "avg_ns_per_run": 203.47778488093334,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 654,
            "name": "trace_vfs_read",
            "run_cnt_delta": 12514,
            "run_time_ns_delta": 2546321,
            "type": "kprobe"
          },
          "655": {
            "avg_ns_per_run": 2545.8,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 655,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 50916,
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
            "avg_ns_per_run": 214.67020335985853,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 657,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 4524,
            "run_time_ns_delta": 971168,
            "type": "kprobe"
          },
          "658": {
            "avg_ns_per_run": 209.5079575596817,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 658,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 4524,
            "run_time_ns_delta": 947814,
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
            "avg_ns_per_run": 238.8053053053053,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 660,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 1998,
            "run_time_ns_delta": 477133,
            "type": "kprobe"
          },
          "661": {
            "avg_ns_per_run": 166.76327769347498,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 661,
            "name": "trace_do_mmap",
            "run_cnt_delta": 1318,
            "run_time_ns_delta": 219794,
            "type": "kprobe"
          },
          "662": {
            "avg_ns_per_run": 55.04931714719272,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 662,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 1318,
            "run_time_ns_delta": 72555,
            "type": "kprobe"
          },
          "663": {
            "avg_ns_per_run": 1455.4742033383916,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 663,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 1318,
            "run_time_ns_delta": 1918315,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 2257.7124463519312,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 664,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 233,
            "run_time_ns_delta": 526047,
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
            "avg_ns_per_run": 588.8205565989415,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 666,
            "name": "trace_security_bpf",
            "run_cnt_delta": 11714,
            "run_time_ns_delta": 6897444,
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
            "avg_ns_per_run": 447.41342121030556,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 669,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 3338,
            "run_time_ns_delta": 1493466,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 1244.4067164179105,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 670,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 268,
            "run_time_ns_delta": 333501,
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
            "avg_ns_per_run": 4216.833333333333,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 674,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 50602,
            "type": "kprobe"
          },
          "675": {
            "avg_ns_per_run": 5172.5,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 675,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 62070,
            "type": "kprobe"
          },
          "676": {
            "avg_ns_per_run": 3692.0,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 676,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 180908,
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
            "avg_ns_per_run": 11215.833333333334,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 680,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 134590,
            "type": "raw_tracepoint"
          },
          "681": {
            "avg_ns_per_run": 12148.833333333334,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 681,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 145786,
            "type": "raw_tracepoint"
          },
          "682": {
            "avg_ns_per_run": 655.0,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 682,
            "name": "trace_do_init_module",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 7860,
            "type": "kprobe"
          },
          "683": {
            "avg_ns_per_run": 377.5833333333333,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 683,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 4531,
            "type": "kprobe"
          },
          "684": {
            "avg_ns_per_run": 2695.0079365079364,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 684,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 126,
            "run_time_ns_delta": 339571,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 69.89730479479996,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 685,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 73538,
            "run_time_ns_delta": 5140108,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 3613.3076923076924,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 686,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 65,
            "run_time_ns_delta": 234865,
            "type": "raw_tracepoint"
          },
          "687": {
            "avg_ns_per_run": 4436.959183673469,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 687,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 217411,
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
            "avg_ns_per_run": 797.6656217345873,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 690,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 957,
            "run_time_ns_delta": 763366,
            "type": "kprobe"
          },
          "691": {
            "avg_ns_per_run": 4446.074626865671,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 691,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 67,
            "run_time_ns_delta": 297887,
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
            "avg_ns_per_run": 2081.4742535698833,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 693,
            "name": "trace_do_truncate",
            "run_cnt_delta": 2311,
            "run_time_ns_delta": 4810287,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 386.1812783416109,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 694,
            "name": "trace_fd_install",
            "run_cnt_delta": 9262,
            "run_time_ns_delta": 3576811,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": 1106.6994978756277,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 695,
            "name": "trace_filp_close",
            "run_cnt_delta": 7767,
            "run_time_ns_delta": 8595735,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": 146.8304987027962,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 696,
            "name": "trace_file_update_time",
            "run_cnt_delta": 6938,
            "run_time_ns_delta": 1018710,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": 74.05520322859614,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 697,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 6938,
            "run_time_ns_delta": 513795,
            "type": "kprobe"
          },
          "698": {
            "avg_ns_per_run": 432.2,
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 698,
            "name": "trace_file_modified",
            "run_cnt_delta": 5,
            "run_time_ns_delta": 2161,
            "type": "kprobe"
          },
          "699": {
            "avg_ns_per_run": 234.0,
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 699,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 5,
            "run_time_ns_delta": 1170,
            "type": "kprobe"
          },
          "700": {
            "avg_ns_per_run": 959.0816326530612,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 700,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 46995,
            "type": "kprobe"
          },
          "701": {
            "avg_ns_per_run": 603.4285714285714,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 701,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 29568,
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
            "avg_ns_per_run": 169.23809523809524,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 703,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 10662,
            "type": "kprobe"
          },
          "704": {
            "avg_ns_per_run": 6326.825396825397,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 704,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 398590,
            "type": "kprobe"
          },
          "705": {
            "avg_ns_per_run": 5436.723214285715,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 705,
            "name": "trace_execute_finished",
            "run_cnt_delta": 112,
            "run_time_ns_delta": 608913,
            "type": "kprobe"
          },
          "706": {
            "avg_ns_per_run": 4783.428571428572,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 706,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 234388,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": 3755.6923076923076,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 707,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 13,
            "run_time_ns_delta": 48824,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": null,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 708,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 4555.163265306122,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 710,
            "name": "trace_chmod_common",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 223203,
            "type": "kprobe"
          },
          "711": {
            "avg_ns_per_run": 1550.5714285714287,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 711,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 21708,
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
            "avg_ns_per_run": 409.03779069767444,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 714,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 344,
            "run_time_ns_delta": 140709,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": 1754.5552325581396,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 715,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 344,
            "run_time_ns_delta": 603567,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": 2092.02,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 716,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 104601,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": 326.5613382899628,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 717,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 269,
            "run_time_ns_delta": 87845,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 506.08383233532936,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 718,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 167,
            "run_time_ns_delta": 84516,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 1578.271918678526,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 719,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 787,
            "run_time_ns_delta": 1242100,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 2424.0648967551624,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 721,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 339,
            "run_time_ns_delta": 821758,
            "type": "cgroup_skb"
          },
          "722": {
            "avg_ns_per_run": 3385.533923303835,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 722,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 339,
            "run_time_ns_delta": 1147696,
            "type": "cgroup_skb"
          },
          "723": {
            "avg_ns_per_run": 2511.0,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 723,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2511,
            "type": "raw_tracepoint"
          },
          "724": {
            "avg_ns_per_run": 2297.0,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 724,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2297,
            "type": "raw_tracepoint"
          },
          "725": {
            "avg_ns_per_run": 161.06349206349208,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 725,
            "name": "empty_kprobe",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 10147,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": 1310.1904761904761,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 726,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 82542,
            "type": "raw_tracepoint"
          },
          "727": {
            "avg_ns_per_run": 768.7189552956257,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 727,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 6241,
            "run_time_ns_delta": 4797575,
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
            "duration_s": 5.191054793999967,
            "ops_per_sec": 446.34473954659137,
            "ops_total": 2317.0,
            "stderr": "module_load_candidate=vcan",
            "stdout": ""
          }
        ]
      },
      "error": "prog 665: BPF_PROG_REJIT: Invalid argument (os error 22)",
      "post_rejit": {
        "bpf": {
          "570": {
            "avg_ns_per_run": 191.06507187840782,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 570,
            "name": "tracepoint__raw",
            "run_cnt_delta": 823474,
            "run_time_ns_delta": 157337119,
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
            "bytes_jited": 17415,
            "bytes_xlated": 30288,
            "id": 572,
            "name": "sys_enter_submi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "573": {
            "avg_ns_per_run": 262.9205632667334,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 573,
            "name": "tracepoint__raw",
            "run_cnt_delta": 823624,
            "run_time_ns_delta": 216547686,
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
            "bytes_jited": 11545,
            "bytes_xlated": 19792,
            "id": 575,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "576": {
            "avg_ns_per_run": 261.768929719441,
            "bytes_jited": 8131,
            "bytes_xlated": 13608,
            "id": 576,
            "name": "trace_sys_enter",
            "run_cnt_delta": 823784,
            "run_time_ns_delta": 215641056,
            "type": "raw_tracepoint"
          },
          "577": {
            "avg_ns_per_run": 254.69331900998992,
            "bytes_jited": 8164,
            "bytes_xlated": 13664,
            "id": 577,
            "name": "trace_sys_exit",
            "run_cnt_delta": 823830,
            "run_time_ns_delta": 209823997,
            "type": "raw_tracepoint"
          },
          "578": {
            "avg_ns_per_run": 724.9042553191489,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 578,
            "name": "trace_ptrace",
            "run_cnt_delta": 94,
            "run_time_ns_delta": 68141,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": 2356.446808510638,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 579,
            "name": "trace_ret_ptrac",
            "run_cnt_delta": 94,
            "run_time_ns_delta": 221506,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": 488.48936170212767,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 580,
            "name": "trace_process_v",
            "run_cnt_delta": 47,
            "run_time_ns_delta": 22959,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": 3103.9574468085107,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 581,
            "name": "trace_ret_proce",
            "run_cnt_delta": 47,
            "run_time_ns_delta": 145886,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": 1149.135593220339,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 582,
            "name": "trace_arch_prct",
            "run_cnt_delta": 59,
            "run_time_ns_delta": 67799,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": 2875.6271186440677,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 583,
            "name": "trace_ret_arch_",
            "run_cnt_delta": 59,
            "run_time_ns_delta": 169662,
            "type": "kprobe"
          },
          "584": {
            "avg_ns_per_run": null,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 584,
            "name": "trace_dup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "585": {
            "avg_ns_per_run": null,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 585,
            "name": "trace_ret_dup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "586": {
            "avg_ns_per_run": 1161.056338028169,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 586,
            "name": "trace_dup2",
            "run_cnt_delta": 71,
            "run_time_ns_delta": 82435,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 3502.4647887323945,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 587,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 71,
            "run_time_ns_delta": 248675,
            "type": "kprobe"
          },
          "588": {
            "avg_ns_per_run": null,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 588,
            "name": "trace_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "589": {
            "avg_ns_per_run": null,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 589,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "590": {
            "avg_ns_per_run": null,
            "bytes_jited": 20725,
            "bytes_xlated": 31976,
            "id": 590,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "591": {
            "avg_ns_per_run": null,
            "bytes_jited": 20696,
            "bytes_xlated": 31992,
            "id": 591,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "592": {
            "avg_ns_per_run": null,
            "bytes_jited": 21000,
            "bytes_xlated": 32400,
            "id": 592,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "593": {
            "avg_ns_per_run": null,
            "bytes_jited": 20968,
            "bytes_xlated": 32408,
            "id": 593,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "594": {
            "avg_ns_per_run": null,
            "bytes_jited": 12211,
            "bytes_xlated": 18576,
            "id": 594,
            "name": "sys_dup_exit_ta",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "595": {
            "avg_ns_per_run": 7816.040358744394,
            "bytes_jited": 19847,
            "bytes_xlated": 32320,
            "id": 595,
            "name": "tracepoint__sch",
            "run_cnt_delta": 223,
            "run_time_ns_delta": 1742977,
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
            "bytes_jited": 6021,
            "bytes_xlated": 9904,
            "id": 597,
            "name": "uprobe_lkm_seek",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "598": {
            "avg_ns_per_run": null,
            "bytes_jited": 4308,
            "bytes_xlated": 7696,
            "id": 598,
            "name": "uprobe_lkm_seek",
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
            "bytes_jited": 648,
            "bytes_xlated": 1040,
            "id": 600,
            "name": "lkm_seeker_mod_",
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
            "bytes_jited": 3772,
            "bytes_xlated": 6224,
            "id": 602,
            "name": "lkm_seeker_new_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": 7629.728813559322,
            "bytes_jited": 20525,
            "bytes_xlated": 35336,
            "id": 603,
            "name": "tracepoint__sch",
            "run_cnt_delta": 59,
            "run_time_ns_delta": 450154,
            "type": "raw_tracepoint"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 23905,
            "bytes_xlated": 37632,
            "id": 604,
            "name": "sched_process_e",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "605": {
            "avg_ns_per_run": 2739.4454545454546,
            "bytes_jited": 8680,
            "bytes_xlated": 14464,
            "id": 605,
            "name": "tracepoint__sch",
            "run_cnt_delta": 220,
            "run_time_ns_delta": 602678,
            "type": "raw_tracepoint"
          },
          "606": {
            "avg_ns_per_run": 2081.3,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 606,
            "name": "tracepoint__sch",
            "run_cnt_delta": 220,
            "run_time_ns_delta": 457886,
            "type": "raw_tracepoint"
          },
          "607": {
            "avg_ns_per_run": null,
            "bytes_jited": 9084,
            "bytes_xlated": 13696,
            "id": 607,
            "name": "syscall__accept",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "608": {
            "avg_ns_per_run": 391.8933315817072,
            "bytes_jited": 8925,
            "bytes_xlated": 14840,
            "id": 608,
            "name": "tracepoint__sch",
            "run_cnt_delta": 890601,
            "run_time_ns_delta": 349020593,
            "type": "raw_tracepoint"
          },
          "609": {
            "avg_ns_per_run": 17.963405057326842,
            "bytes_jited": 8163,
            "bytes_xlated": 13680,
            "id": 609,
            "name": "trace_filldir64",
            "run_cnt_delta": 12734,
            "run_time_ns_delta": 228746,
            "type": "kprobe"
          },
          "610": {
            "avg_ns_per_run": null,
            "bytes_jited": 23491,
            "bytes_xlated": 36696,
            "id": 610,
            "name": "trace_call_user",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": 2089.181818181818,
            "bytes_jited": 7921,
            "bytes_xlated": 13312,
            "id": 611,
            "name": "trace_do_exit",
            "run_cnt_delta": 220,
            "run_time_ns_delta": 459620,
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
            "bytes_jited": 6749,
            "bytes_xlated": 11160,
            "id": 613,
            "name": "uprobe_seq_ops_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "614": {
            "avg_ns_per_run": null,
            "bytes_jited": 6533,
            "bytes_xlated": 10904,
            "id": 614,
            "name": "uprobe_mem_dump",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "615": {
            "avg_ns_per_run": 918.5347985347985,
            "bytes_jited": 11470,
            "bytes_xlated": 18264,
            "id": 615,
            "name": "trace_security_",
            "run_cnt_delta": 273,
            "run_time_ns_delta": 250760,
            "type": "kprobe"
          },
          "616": {
            "avg_ns_per_run": null,
            "bytes_jited": 9740,
            "bytes_xlated": 15632,
            "id": 616,
            "name": "trace_tracepoin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "617": {
            "avg_ns_per_run": 2723.0,
            "bytes_jited": 8620,
            "bytes_xlated": 14352,
            "id": 617,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2723,
            "type": "raw_tracepoint"
          },
          "618": {
            "avg_ns_per_run": 2039.0,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 618,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2039,
            "type": "raw_tracepoint"
          },
          "619": {
            "avg_ns_per_run": 2421.0,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 619,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2421,
            "type": "raw_tracepoint"
          },
          "620": {
            "avg_ns_per_run": 4691.135593220339,
            "bytes_jited": 33373,
            "bytes_xlated": 52824,
            "id": 620,
            "name": "trace_security_",
            "run_cnt_delta": 59,
            "run_time_ns_delta": 276777,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": 1388.5555789473685,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 621,
            "name": "trace_security_file_open",
            "run_cnt_delta": 4750,
            "run_time_ns_delta": 6595639,
            "type": "kprobe"
          },
          "622": {
            "avg_ns_per_run": null,
            "bytes_jited": 18607,
            "bytes_xlated": 30576,
            "id": 622,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "623": {
            "avg_ns_per_run": 2645.531707317073,
            "bytes_jited": 9984,
            "bytes_xlated": 16352,
            "id": 623,
            "name": "trace_security_",
            "run_cnt_delta": 205,
            "run_time_ns_delta": 542334,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": 1230.764705882353,
            "bytes_jited": 10723,
            "bytes_xlated": 16880,
            "id": 624,
            "name": "trace_commit_cr",
            "run_cnt_delta": 119,
            "run_time_ns_delta": 146461,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": 1332.2272727272727,
            "bytes_jited": 10045,
            "bytes_xlated": 16520,
            "id": 625,
            "name": "trace_switch_ta",
            "run_cnt_delta": 220,
            "run_time_ns_delta": 293090,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 205.4534620837644,
            "bytes_jited": 8174,
            "bytes_xlated": 13680,
            "id": 626,
            "name": "trace_cap_capab",
            "run_cnt_delta": 26097,
            "run_time_ns_delta": 5361719,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 1537.6894736842105,
            "bytes_jited": 8471,
            "bytes_xlated": 14120,
            "id": 627,
            "name": "trace_security_",
            "run_cnt_delta": 190,
            "run_time_ns_delta": 292161,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": 3555.978723404255,
            "bytes_jited": 9144,
            "bytes_xlated": 15208,
            "id": 628,
            "name": "trace_security_",
            "run_cnt_delta": 47,
            "run_time_ns_delta": 167131,
            "type": "kprobe"
          },
          "629": {
            "avg_ns_per_run": null,
            "bytes_jited": 8276,
            "bytes_xlated": 13824,
            "id": 629,
            "name": "trace_proc_crea",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "630": {
            "avg_ns_per_run": null,
            "bytes_jited": 9497,
            "bytes_xlated": 15760,
            "id": 630,
            "name": "trace_debugfs_c",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "631": {
            "avg_ns_per_run": null,
            "bytes_jited": 9197,
            "bytes_xlated": 15328,
            "id": 631,
            "name": "trace_debugfs_c",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "632": {
            "avg_ns_per_run": 2529.404255319149,
            "bytes_jited": 10780,
            "bytes_xlated": 16456,
            "id": 632,
            "name": "trace_security_",
            "run_cnt_delta": 47,
            "run_time_ns_delta": 118882,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": 2810.4893617021276,
            "bytes_jited": 10075,
            "bytes_xlated": 15400,
            "id": 633,
            "name": "trace_security_",
            "run_cnt_delta": 47,
            "run_time_ns_delta": 132093,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 3878.6666666666665,
            "bytes_jited": 11260,
            "bytes_xlated": 17192,
            "id": 634,
            "name": "trace_security_",
            "run_cnt_delta": 141,
            "run_time_ns_delta": 546892,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 2610.938775510204,
            "bytes_jited": 10589,
            "bytes_xlated": 16080,
            "id": 635,
            "name": "trace_security_",
            "run_cnt_delta": 49,
            "run_time_ns_delta": 127936,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": 2656.0943396226417,
            "bytes_jited": 11025,
            "bytes_xlated": 16864,
            "id": 636,
            "name": "trace_security_",
            "run_cnt_delta": 53,
            "run_time_ns_delta": 140773,
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
            "avg_ns_per_run": 98.63049055430304,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 639,
            "name": "trace_vfs_write",
            "run_cnt_delta": 38589,
            "run_time_ns_delta": 3806052,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": 50.02930583266396,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 640,
            "name": "vfs_write_magic",
            "run_cnt_delta": 38593,
            "run_time_ns_delta": 1930781,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": 117.90548488224474,
            "bytes_jited": 19108,
            "bytes_xlated": 31720,
            "id": 641,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 38597,
            "run_time_ns_delta": 4550798,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": 61.409832246039144,
            "bytes_jited": 23757,
            "bytes_xlated": 36648,
            "id": 642,
            "name": "vfs_write_magic",
            "run_cnt_delta": 38628,
            "run_time_ns_delta": 2372139,
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
            "avg_ns_per_run": 89.21385199240987,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 644,
            "name": "trace_vfs_write",
            "run_cnt_delta": 5270,
            "run_time_ns_delta": 470157,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": 67.0055028462998,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 645,
            "name": "vfs_writev_magi",
            "run_cnt_delta": 5270,
            "run_time_ns_delta": 353119,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": 57.45047438330171,
            "bytes_jited": 19107,
            "bytes_xlated": 31712,
            "id": 646,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 5270,
            "run_time_ns_delta": 302764,
            "type": "kprobe"
          },
          "647": {
            "avg_ns_per_run": 107.2696394686907,
            "bytes_jited": 23786,
            "bytes_xlated": 36696,
            "id": 647,
            "name": "vfs_writev_magi",
            "run_cnt_delta": 5270,
            "run_time_ns_delta": 565311,
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
            "name": "trace_kernel_wr",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "650": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 650,
            "name": "kernel_write_ma",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "651": {
            "avg_ns_per_run": null,
            "bytes_jited": 19111,
            "bytes_xlated": 31720,
            "id": 651,
            "name": "trace_ret_kerne",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "652": {
            "avg_ns_per_run": null,
            "bytes_jited": 23757,
            "bytes_xlated": 36648,
            "id": 652,
            "name": "kernel_write_ma",
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
            "avg_ns_per_run": 163.24766559036564,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 654,
            "name": "trace_vfs_read",
            "run_cnt_delta": 11459,
            "run_time_ns_delta": 1870655,
            "type": "kprobe"
          },
          "655": {
            "avg_ns_per_run": 400.64251861882195,
            "bytes_jited": 19111,
            "bytes_xlated": 31720,
            "id": 655,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 5908,
            "run_time_ns_delta": 2366996,
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
            "avg_ns_per_run": 135.67381404174574,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 657,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 5270,
            "run_time_ns_delta": 715001,
            "type": "kprobe"
          },
          "658": {
            "avg_ns_per_run": 130.72941176470587,
            "bytes_jited": 19107,
            "bytes_xlated": 31712,
            "id": 658,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 5270,
            "run_time_ns_delta": 688944,
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
            "avg_ns_per_run": 251.9343657817109,
            "bytes_jited": 20715,
            "bytes_xlated": 32736,
            "id": 660,
            "name": "trace_mmap_aler",
            "run_cnt_delta": 1356,
            "run_time_ns_delta": 341623,
            "type": "kprobe"
          },
          "661": {
            "avg_ns_per_run": 146.78618421052633,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 661,
            "name": "trace_do_mmap",
            "run_cnt_delta": 1216,
            "run_time_ns_delta": 178492,
            "type": "kprobe"
          },
          "662": {
            "avg_ns_per_run": 229.93503289473685,
            "bytes_jited": 19426,
            "bytes_xlated": 31584,
            "id": 662,
            "name": "trace_ret_do_mm",
            "run_cnt_delta": 1216,
            "run_time_ns_delta": 279601,
            "type": "kprobe"
          },
          "663": {
            "avg_ns_per_run": 1349.6151315789473,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 663,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 1216,
            "run_time_ns_delta": 1641132,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 2010.6666666666667,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 664,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 216,
            "run_time_ns_delta": 434304,
            "type": "kprobe"
          },
          "665": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 665,
            "name": "syscall__init_m",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "666": {
            "avg_ns_per_run": 623.439005371686,
            "bytes_jited": 15585,
            "bytes_xlated": 26904,
            "id": 666,
            "name": "trace_security_",
            "run_cnt_delta": 11542,
            "run_time_ns_delta": 7195733,
            "type": "kprobe"
          },
          "667": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 667,
            "name": "trace_register_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "668": {
            "avg_ns_per_run": null,
            "bytes_jited": 8807,
            "bytes_xlated": 14640,
            "id": 668,
            "name": "trace_ret_regis",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "669": {
            "avg_ns_per_run": 442.3334375,
            "bytes_jited": 8333,
            "bytes_xlated": 13904,
            "id": 669,
            "name": "trace_security_",
            "run_cnt_delta": 3200,
            "run_time_ns_delta": 1415467,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 1173.0559701492537,
            "bytes_jited": 9581,
            "bytes_xlated": 15448,
            "id": 670,
            "name": "trace_security_",
            "run_cnt_delta": 268,
            "run_time_ns_delta": 314379,
            "type": "kprobe"
          },
          "671": {
            "avg_ns_per_run": null,
            "bytes_jited": 6345,
            "bytes_xlated": 10528,
            "id": 671,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "672": {
            "avg_ns_per_run": null,
            "bytes_jited": 6581,
            "bytes_xlated": 11008,
            "id": 672,
            "name": "trace_check_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "673": {
            "avg_ns_per_run": null,
            "bytes_jited": 6587,
            "bytes_xlated": 11016,
            "id": 673,
            "name": "trace_check_hel",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "674": {
            "avg_ns_per_run": 3090.7,
            "bytes_jited": 18641,
            "bytes_xlated": 30648,
            "id": 674,
            "name": "trace_security_",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 30907,
            "type": "kprobe"
          },
          "675": {
            "avg_ns_per_run": 3882.9,
            "bytes_jited": 17247,
            "bytes_xlated": 30448,
            "id": 675,
            "name": "trace_security_",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 38829,
            "type": "kprobe"
          },
          "676": {
            "avg_ns_per_run": 3310.9574468085107,
            "bytes_jited": 9225,
            "bytes_xlated": 15352,
            "id": 676,
            "name": "trace_security_",
            "run_cnt_delta": 47,
            "run_time_ns_delta": 155615,
            "type": "kprobe"
          },
          "677": {
            "avg_ns_per_run": null,
            "bytes_jited": 8647,
            "bytes_xlated": 14344,
            "id": 677,
            "name": "trace_device_ad",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "678": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 678,
            "name": "trace___registe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "679": {
            "avg_ns_per_run": null,
            "bytes_jited": 8814,
            "bytes_xlated": 14632,
            "id": 679,
            "name": "trace_ret__regi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "680": {
            "avg_ns_per_run": 7645.3,
            "bytes_jited": 19868,
            "bytes_xlated": 32648,
            "id": 680,
            "name": "tracepoint__mod",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 76453,
            "type": "raw_tracepoint"
          },
          "681": {
            "avg_ns_per_run": 8152.6,
            "bytes_jited": 8959,
            "bytes_xlated": 14920,
            "id": 681,
            "name": "tracepoint__mod",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 81526,
            "type": "raw_tracepoint"
          },
          "682": {
            "avg_ns_per_run": 554.3,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 682,
            "name": "trace_do_init_m",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 5543,
            "type": "kprobe"
          },
          "683": {
            "avg_ns_per_run": 216.2,
            "bytes_jited": 14542,
            "bytes_xlated": 23904,
            "id": 683,
            "name": "trace_ret_do_in",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 2162,
            "type": "kprobe"
          },
          "684": {
            "avg_ns_per_run": 2471.822033898305,
            "bytes_jited": 18482,
            "bytes_xlated": 30352,
            "id": 684,
            "name": "trace_load_elf_",
            "run_cnt_delta": 118,
            "run_time_ns_delta": 291675,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 49.65658102651138,
            "bytes_jited": 8681,
            "bytes_xlated": 14496,
            "id": 685,
            "name": "trace_security_",
            "run_cnt_delta": 68348,
            "run_time_ns_delta": 3393928,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 3523.27868852459,
            "bytes_jited": 8474,
            "bytes_xlated": 14112,
            "id": 686,
            "name": "tracepoint__tas",
            "run_cnt_delta": 61,
            "run_time_ns_delta": 214920,
            "type": "raw_tracepoint"
          },
          "687": {
            "avg_ns_per_run": 3744.340425531915,
            "bytes_jited": 9792,
            "bytes_xlated": 16344,
            "id": 687,
            "name": "trace_security_",
            "run_cnt_delta": 47,
            "run_time_ns_delta": 175984,
            "type": "kprobe"
          },
          "688": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 688,
            "name": "trace_kallsyms_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "689": {
            "avg_ns_per_run": null,
            "bytes_jited": 8406,
            "bytes_xlated": 14024,
            "id": 689,
            "name": "trace_ret_kalls",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "690": {
            "avg_ns_per_run": 740.3912515188335,
            "bytes_jited": 10109,
            "bytes_xlated": 16296,
            "id": 690,
            "name": "trace_do_sigact",
            "run_cnt_delta": 823,
            "run_time_ns_delta": 609342,
            "type": "kprobe"
          },
          "691": {
            "avg_ns_per_run": 3841.0,
            "bytes_jited": 18560,
            "bytes_xlated": 30528,
            "id": 691,
            "name": "trace_vfs_utime",
            "run_cnt_delta": 62,
            "run_time_ns_delta": 238142,
            "type": "kprobe"
          },
          "692": {
            "avg_ns_per_run": null,
            "bytes_jited": 18560,
            "bytes_xlated": 30528,
            "id": 692,
            "name": "trace_utimes_co",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "693": {
            "avg_ns_per_run": 1665.758389261745,
            "bytes_jited": 9530,
            "bytes_xlated": 15824,
            "id": 693,
            "name": "trace_do_trunca",
            "run_cnt_delta": 2682,
            "run_time_ns_delta": 4467564,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 367.5864172967237,
            "bytes_jited": 16708,
            "bytes_xlated": 27176,
            "id": 694,
            "name": "trace_fd_instal",
            "run_cnt_delta": 7539,
            "run_time_ns_delta": 2771234,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": 1061.534177559913,
            "bytes_jited": 16636,
            "bytes_xlated": 27024,
            "id": 695,
            "name": "trace_filp_clos",
            "run_cnt_delta": 7344,
            "run_time_ns_delta": 7795907,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": 124.94121302510564,
            "bytes_jited": 459,
            "bytes_xlated": 768,
            "id": 696,
            "name": "trace_file_upda",
            "run_cnt_delta": 8046,
            "run_time_ns_delta": 1005277,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": 55.463584389758886,
            "bytes_jited": 20054,
            "bytes_xlated": 31168,
            "id": 697,
            "name": "trace_ret_file_",
            "run_cnt_delta": 8046,
            "run_time_ns_delta": 446260,
            "type": "kprobe"
          },
          "698": {
            "avg_ns_per_run": null,
            "bytes_jited": 459,
            "bytes_xlated": 768,
            "id": 698,
            "name": "trace_file_modi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "699": {
            "avg_ns_per_run": null,
            "bytes_jited": 20140,
            "bytes_xlated": 31288,
            "id": 699,
            "name": "trace_ret_file_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "700": {
            "avg_ns_per_run": 728.4893617021277,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 700,
            "name": "trace_inotify_f",
            "run_cnt_delta": 47,
            "run_time_ns_delta": 34239,
            "type": "kprobe"
          },
          "701": {
            "avg_ns_per_run": 1097.2978723404256,
            "bytes_jited": 18025,
            "bytes_xlated": 29936,
            "id": 701,
            "name": "trace_ret_inoti",
            "run_cnt_delta": 47,
            "run_time_ns_delta": 51573,
            "type": "kprobe"
          },
          "702": {
            "avg_ns_per_run": null,
            "bytes_jited": 12830,
            "bytes_xlated": 20080,
            "id": 702,
            "name": "process_execute",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "703": {
            "avg_ns_per_run": 358.3728813559322,
            "bytes_jited": 16472,
            "bytes_xlated": 28872,
            "id": 703,
            "name": "trace_exec_binp",
            "run_cnt_delta": 59,
            "run_time_ns_delta": 21144,
            "type": "kprobe"
          },
          "704": {
            "avg_ns_per_run": 5827.203389830508,
            "bytes_jited": 16702,
            "bytes_xlated": 29144,
            "id": 704,
            "name": "trace_security_",
            "run_cnt_delta": 59,
            "run_time_ns_delta": 343805,
            "type": "kprobe"
          },
          "705": {
            "avg_ns_per_run": 4973.396226415094,
            "bytes_jited": 24469,
            "bytes_xlated": 38320,
            "id": 705,
            "name": "trace_execute_f",
            "run_cnt_delta": 106,
            "run_time_ns_delta": 527180,
            "type": "kprobe"
          },
          "706": {
            "avg_ns_per_run": 4528.553191489362,
            "bytes_jited": 18391,
            "bytes_xlated": 30200,
            "id": 706,
            "name": "trace_security_",
            "run_cnt_delta": 47,
            "run_time_ns_delta": 212842,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": 3023.2727272727275,
            "bytes_jited": 18194,
            "bytes_xlated": 29912,
            "id": 707,
            "name": "trace_set_fs_pw",
            "run_cnt_delta": 11,
            "run_time_ns_delta": 33256,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": null,
            "bytes_jited": 8631,
            "bytes_xlated": 14360,
            "id": 708,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "709": {
            "avg_ns_per_run": null,
            "bytes_jited": 8656,
            "bytes_xlated": 14416,
            "id": 709,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "710": {
            "avg_ns_per_run": 4255.340425531915,
            "bytes_jited": 17561,
            "bytes_xlated": 29176,
            "id": 710,
            "name": "trace_chmod_com",
            "run_cnt_delta": 47,
            "run_time_ns_delta": 200001,
            "type": "kprobe"
          },
          "711": {
            "avg_ns_per_run": 1391.0714285714287,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 711,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 19475,
            "type": "kprobe"
          },
          "712": {
            "avg_ns_per_run": null,
            "bytes_jited": 14861,
            "bytes_xlated": 23928,
            "id": 712,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "713": {
            "avg_ns_per_run": null,
            "bytes_jited": 9482,
            "bytes_xlated": 15760,
            "id": 713,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "714": {
            "avg_ns_per_run": 421.75757575757575,
            "bytes_jited": 329,
            "bytes_xlated": 520,
            "id": 714,
            "name": "trace_sock_allo",
            "run_cnt_delta": 330,
            "run_time_ns_delta": 139180,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": 1580.4030303030304,
            "bytes_jited": 8439,
            "bytes_xlated": 12928,
            "id": 715,
            "name": "trace_ret_sock_",
            "run_cnt_delta": 330,
            "run_time_ns_delta": 521533,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": 1963.4255319148936,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 716,
            "name": "trace_security_",
            "run_cnt_delta": 47,
            "run_time_ns_delta": 92281,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": 186.61212121212122,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 717,
            "name": "trace_security_",
            "run_cnt_delta": 165,
            "run_time_ns_delta": 30791,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 335.9809523809524,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 718,
            "name": "trace_security_",
            "run_cnt_delta": 105,
            "run_time_ns_delta": 35278,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 1711.7104,
            "bytes_jited": 5282,
            "bytes_xlated": 8136,
            "id": 719,
            "name": "cgroup_bpf_run_",
            "run_cnt_delta": 625,
            "run_time_ns_delta": 1069819,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 2496.7173144876324,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 721,
            "name": "cgroup_skb_ingr",
            "run_cnt_delta": 283,
            "run_time_ns_delta": 706571,
            "type": "cgroup_skb"
          },
          "722": {
            "avg_ns_per_run": 3516.572438162544,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 722,
            "name": "cgroup_skb_egre",
            "run_cnt_delta": 283,
            "run_time_ns_delta": 995190,
            "type": "cgroup_skb"
          },
          "723": {
            "avg_ns_per_run": 2278.0,
            "bytes_jited": 916,
            "bytes_xlated": 1560,
            "id": 723,
            "name": "cgroup_mkdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2278,
            "type": "raw_tracepoint"
          },
          "724": {
            "avg_ns_per_run": 2650.0,
            "bytes_jited": 898,
            "bytes_xlated": 1520,
            "id": 724,
            "name": "cgroup_rmdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2650,
            "type": "raw_tracepoint"
          },
          "725": {
            "avg_ns_per_run": 178.5593220338983,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 725,
            "name": "empty_kprobe",
            "run_cnt_delta": 59,
            "run_time_ns_delta": 10535,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": 1242.406779661017,
            "bytes_jited": 58660,
            "bytes_xlated": 95944,
            "id": 726,
            "name": "tracepoint__exe",
            "run_cnt_delta": 59,
            "run_time_ns_delta": 73302,
            "type": "raw_tracepoint"
          },
          "727": {
            "avg_ns_per_run": 778.6686315789474,
            "bytes_jited": 7290,
            "bytes_xlated": 13264,
            "id": 727,
            "name": "lsm_file_open_t",
            "run_cnt_delta": 4750,
            "run_time_ns_delta": 3698676,
            "type": "lsm"
          },
          "728": {
            "avg_ns_per_run": null,
            "bytes_jited": 5359,
            "bytes_xlated": 9080,
            "id": 728,
            "name": "uprobe__feature",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.007781397000031,
            "ops_per_sec": 536.5649550137468,
            "ops_total": 2687.0,
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
        "error": "prog 665: BPF_PROG_REJIT: Invalid argument (os error 22)",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "BPF_PROG_REJIT: Invalid argument (os error 22)",
            "exit_code": 1,
            "prog_id": 665
          }
        ],
        "exit_code": 1,
        "output_chars": 2254081,
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
          "734": {
            "avg_ns_per_run": 207.74419435201477,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 734,
            "name": "cap_capable",
            "run_cnt_delta": 114802,
            "run_time_ns_delta": 23849449,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.053622751999967,
            "ops_per_sec": 915.8875870592724,
            "ops_total": 965.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [21636] setting to a 1 secs run per stressor\nstress-ng: info:  [21636] dispatching hogs: 2 exec\nstress-ng: info:  [21636] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21636] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21636]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21636] exec                965      1.03      2.42      1.10       935.02         274.55\nstress-ng: info:  [21636] skipped: 0\nstress-ng: info:  [21636] passed: 2: exec (2)\nstress-ng: info:  [21636] failed: 0\nstress-ng: info:  [21636] metrics untrustworthy: 0\nstress-ng: info:  [21636] successful run completed in 1.04 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "734": {
            "avg_ns_per_run": 114.01909209946719,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 734,
            "name": "cap_capable",
            "run_cnt_delta": 165723,
            "run_time_ns_delta": 18895586,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.045605389000002,
            "ops_per_sec": 1349.45746726636,
            "ops_total": 1411.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [12003] setting to a 1 secs run per stressor\nstress-ng: info:  [12003] dispatching hogs: 2 exec\nstress-ng: info:  [12003] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12003] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12003]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12003] exec               1411      1.02      2.74      0.85      1378.11         393.70\nstress-ng: info:  [12003] skipped: 0\nstress-ng: info:  [12003] passed: 2: exec (2)\nstress-ng: info:  [12003] failed: 0\nstress-ng: info:  [12003] metrics untrustworthy: 0\nstress-ng: info:  [12003] successful run completed in 1.03 secs"
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
          "740": {
            "avg_ns_per_run": 249.00137621735874,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 740,
            "name": "block_io_start",
            "run_cnt_delta": 598016,
            "run_time_ns_delta": 148906807,
            "type": "tracepoint"
          },
          "741": {
            "avg_ns_per_run": 358.2687102017337,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 741,
            "name": "block_io_done",
            "run_cnt_delta": 598016,
            "run_time_ns_delta": 214250421,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.033629649000034,
            "ops_per_sec": 118804.13174989943,
            "ops_total": 598016.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "740": {
            "avg_ns_per_run": 141.44958917025863,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 740,
            "name": "block_io_start",
            "run_cnt_delta": 712704,
            "run_time_ns_delta": 100811688,
            "type": "tracepoint"
          },
          "741": {
            "avg_ns_per_run": 299.2936773190553,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 741,
            "name": "block_io_done",
            "run_cnt_delta": 712704,
            "run_time_ns_delta": 213307801,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.005046638000067,
            "ops_per_sec": 142397.07470234175,
            "ops_total": 712704.0,
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
          "747": {
            "avg_ns_per_run": 1938.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 747,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1938,
            "type": "perf_event"
          },
          "748": {
            "avg_ns_per_run": 108.54768153980753,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 748,
            "name": "vfs_create",
            "run_cnt_delta": 12573,
            "run_time_ns_delta": 1364770,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0005775750000225,
            "ops_per_sec": 97.94343032322885,
            "ops_total": 98.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "747": {
            "avg_ns_per_run": 1473.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 747,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1473,
            "type": "perf_event"
          },
          "748": {
            "avg_ns_per_run": 68.77901950448076,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 748,
            "name": "vfs_create",
            "run_cnt_delta": 9485,
            "run_time_ns_delta": 652369,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0038400720000027,
            "ops_per_sec": 94.63658868561261,
            "ops_total": 95.0,
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
        "output_chars": 8219,
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
          "754": {
            "avg_ns_per_run": 127.37657786803648,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 754,
            "name": "sched_wakeup",
            "run_cnt_delta": 75339,
            "run_time_ns_delta": 9596424,
            "type": "tracepoint"
          },
          "755": {
            "avg_ns_per_run": 324.9228832951945,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 755,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 4370,
            "run_time_ns_delta": 1419913,
            "type": "tracepoint"
          },
          "756": {
            "avg_ns_per_run": 210.31624825074607,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 756,
            "name": "sched_switch",
            "run_cnt_delta": 118622,
            "run_time_ns_delta": 24948134,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.038057305000052,
            "ops_per_sec": 16.37674521253829,
            "ops_total": 17.0,
            "stderr": "",
            "stdout": "Time: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.032\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.049\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.038\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.058\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.033\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.045\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.038"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "754": {
            "avg_ns_per_run": 113.90655890219793,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 754,
            "name": "sched_wakeup",
            "run_cnt_delta": 85990,
            "run_time_ns_delta": 9794825,
            "type": "tracepoint"
          },
          "755": {
            "avg_ns_per_run": 246.60503685503684,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 755,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 4884,
            "run_time_ns_delta": 1204419,
            "type": "tracepoint"
          },
          "756": {
            "avg_ns_per_run": 173.20024601886638,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 756,
            "name": "sched_switch",
            "run_cnt_delta": 134949,
            "run_time_ns_delta": 23373200,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0378422900000714,
            "ops_per_sec": 18.307213131581573,
            "ops_total": 19.0,
            "stderr": "",
            "stdout": "Time: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.038\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.031\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.030\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.032\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.035\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.031\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036"
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
        "output_chars": 13106,
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
          "763": {
            "avg_ns_per_run": 1071.9106870229007,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 763,
            "name": "tcp_set_state",
            "run_cnt_delta": 1310,
            "run_time_ns_delta": 1404203,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0035104710000269,
            "ops_per_sec": 130.54173701790552,
            "ops_total": 131.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "763": {
            "avg_ns_per_run": 788.1736745886654,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 763,
            "name": "tcp_set_state",
            "run_cnt_delta": 1641,
            "run_time_ns_delta": 1293393,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0047655679999252,
            "ops_per_sec": 163.22215372731822,
            "ops_total": 164.0,
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
          "769": {
            "avg_ns_per_run": 5209.894736842105,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 769,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 19,
            "run_time_ns_delta": 98988,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 8.183356217999972,
            "ops_per_sec": 0.48879700375277174,
            "ops_total": 4.0,
            "stderr": "failed_cycles=3",
            "stdout": "successful_cycles=1"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "769": {
            "avg_ns_per_run": 4384.555555555556,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 769,
            "name": "tcp_retransmit_",
            "run_cnt_delta": 18,
            "run_time_ns_delta": 78922,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 8.187854044000005,
            "ops_per_sec": 0.48852849336404186,
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
    "losses": 34,
    "per_program_geomean": 0.9089602420949129,
    "program_count": 131,
    "wins": 97
  },
  "workload_seconds": 1.0
}
```
