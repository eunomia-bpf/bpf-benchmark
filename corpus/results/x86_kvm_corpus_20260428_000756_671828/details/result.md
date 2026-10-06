# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-04-28T00:19:05.883284+00:00",
  "kinsn_modules": {
    "captured_at": "2026-04-28T00:07:56.699348+00:00",
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
      "invoked_at": "2026-04-28T00:07:56.699289+00:00",
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
        "captured_at": "2026-04-28T00:07:56.699282+00:00",
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
      "captured_at": "2026-04-28T00:07:56.691133+00:00",
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
      "baseline_avg_ns_per_run": 89.00467334614329,
      "baseline_run_cnt_delta": 145720,
      "baseline_run_time_ns_delta": 12969761,
      "post_rejit_avg_ns_per_run": 83.14723810589008,
      "post_rejit_run_cnt_delta": 143054,
      "post_rejit_run_time_ns_delta": 11894545,
      "program": "cap_capable",
      "program_id": 6,
      "ratio": 0.9341895765689362,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 1897.0237087214225,
      "baseline_run_cnt_delta": 1181,
      "baseline_run_time_ns_delta": 2240385,
      "post_rejit_avg_ns_per_run": 1742.387858347386,
      "post_rejit_run_cnt_delta": 1186,
      "post_rejit_run_time_ns_delta": 2066472,
      "program": "syscall__execve",
      "program_id": 9,
      "ratio": 0.918485019632011,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 1451.0364485981308,
      "baseline_run_cnt_delta": 1070,
      "baseline_run_time_ns_delta": 1552609,
      "post_rejit_avg_ns_per_run": 1376.516010978957,
      "post_rejit_run_cnt_delta": 1093,
      "post_rejit_run_time_ns_delta": 1504532,
      "program": "do_ret_sys_exec",
      "program_id": 10,
      "ratio": 0.948643304107785,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 56.084757630732994,
      "baseline_run_cnt_delta": 31419,
      "baseline_run_time_ns_delta": 1762127,
      "post_rejit_avg_ns_per_run": 55.68098368789927,
      "post_rejit_run_cnt_delta": 32246,
      "post_rejit_run_time_ns_delta": 1795489,
      "program": "bindsnoop_entry",
      "program_id": 13,
      "ratio": 0.9928006474505567,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "bind_storm"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 665.4666454487588,
      "baseline_run_cnt_delta": 15710,
      "baseline_run_time_ns_delta": 10454481,
      "post_rejit_avg_ns_per_run": 634.3846058425851,
      "post_rejit_run_cnt_delta": 16123,
      "post_rejit_run_time_ns_delta": 10228183,
      "program": "bindsnoop_v4_re",
      "program_id": 14,
      "ratio": 0.9532928662634722,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "bind_storm"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 650.4783881851168,
      "baseline_run_cnt_delta": 15709,
      "baseline_run_time_ns_delta": 10218365,
      "post_rejit_avg_ns_per_run": 636.9348756434906,
      "post_rejit_run_cnt_delta": 16123,
      "post_rejit_run_time_ns_delta": 10269301,
      "program": "bindsnoop_v6_re",
      "program_id": 15,
      "ratio": 0.9791791506257208,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "bind_storm"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 139.34639892578124,
      "baseline_run_cnt_delta": 327680,
      "baseline_run_time_ns_delta": 45661028,
      "post_rejit_avg_ns_per_run": 136.97427245274903,
      "post_rejit_run_cnt_delta": 344067,
      "post_rejit_run_time_ns_delta": 47128327,
      "program": "trace_pid_start",
      "program_id": 18,
      "ratio": 0.982976765159926,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 162.21393737792968,
      "baseline_run_cnt_delta": 327680,
      "baseline_run_time_ns_delta": 53154263,
      "post_rejit_avg_ns_per_run": 158.3531326565311,
      "post_rejit_run_cnt_delta": 344069,
      "post_rejit_run_time_ns_delta": 54484404,
      "program": "trace_req_start",
      "program_id": 19,
      "ratio": 0.9761993033163138,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "block_io"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 361.96965942382815,
      "baseline_run_cnt_delta": 327680,
      "baseline_run_time_ns_delta": 118610218,
      "post_rejit_avg_ns_per_run": 372.17294155259106,
      "post_rejit_run_cnt_delta": 344070,
      "post_rejit_run_time_ns_delta": 128053544,
      "program": "trace_req_compl",
      "program_id": 20,
      "ratio": 1.0281882247948742,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 28.05263157894737,
      "baseline_run_cnt_delta": 551,
      "baseline_run_time_ns_delta": 15457,
      "post_rejit_avg_ns_per_run": 40.20566037735849,
      "post_rejit_run_cnt_delta": 530,
      "post_rejit_run_time_ns_delta": 21309,
      "program": "vfs_open",
      "program_id": 25,
      "ratio": 1.4332224149527417,
      "runner": "bcc",
      "type": "tracing",
      "workload": "vfs_create_fsync_exact"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 24.672663668165917,
      "baseline_run_cnt_delta": 8004,
      "baseline_run_time_ns_delta": 197480,
      "post_rejit_avg_ns_per_run": 28.432621568275614,
      "post_rejit_run_cnt_delta": 5573,
      "post_rejit_run_time_ns_delta": 158455,
      "program": "vfs_read",
      "program_id": 26,
      "ratio": 1.1523936754733544,
      "runner": "bcc",
      "type": "tracing",
      "workload": "vfs_create_fsync_exact"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 23.840621888642108,
      "baseline_run_cnt_delta": 13057,
      "baseline_run_time_ns_delta": 311287,
      "post_rejit_avg_ns_per_run": 27.018647439085033,
      "post_rejit_run_cnt_delta": 12066,
      "post_rejit_run_time_ns_delta": 326007,
      "program": "vfs_write",
      "program_id": 27,
      "ratio": 1.1333029635421115,
      "runner": "bcc",
      "type": "tracing",
      "workload": "vfs_create_fsync_exact"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 3831.4879288437105,
      "baseline_run_cnt_delta": 1574,
      "baseline_run_time_ns_delta": 6030762,
      "post_rejit_avg_ns_per_run": 1256.2663578459758,
      "post_rejit_run_cnt_delta": 1727,
      "post_rejit_run_time_ns_delta": 2169572,
      "program": "__x64_sys_opena",
      "program_id": 31,
      "ratio": 0.32787950299639845,
      "runner": "bcc",
      "type": "tracing",
      "workload": "open_family_storm"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 1320.0349514563106,
      "baseline_run_cnt_delta": 515,
      "baseline_run_time_ns_delta": 679818,
      "post_rejit_avg_ns_per_run": 1235.1873963515754,
      "post_rejit_run_cnt_delta": 603,
      "post_rejit_run_time_ns_delta": 744818,
      "program": "__x64_sys_opena",
      "program_id": 32,
      "ratio": 0.9357232511070042,
      "runner": "bcc",
      "type": "tracing",
      "workload": "open_family_storm"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 61.96753125389376,
      "baseline_run_cnt_delta": 963080,
      "baseline_run_time_ns_delta": 59679690,
      "post_rejit_avg_ns_per_run": 65.21142432205497,
      "post_rejit_run_cnt_delta": 937281,
      "post_rejit_run_time_ns_delta": 61121429,
      "program": "raw_syscalls__s",
      "program_id": 35,
      "ratio": 1.0523482701750746,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "file_open_storm"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 60.82930552022386,
      "baseline_run_cnt_delta": 963095,
      "baseline_run_time_ns_delta": 58584400,
      "post_rejit_avg_ns_per_run": 61.61694919234411,
      "post_rejit_run_cnt_delta": 936847,
      "post_rejit_run_time_ns_delta": 57725654,
      "program": "raw_syscalls__s",
      "program_id": 36,
      "ratio": 1.0129484245362357,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "file_open_storm"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 649.917808219178,
      "baseline_run_cnt_delta": 73,
      "baseline_run_time_ns_delta": 47444,
      "post_rejit_avg_ns_per_run": 629.275,
      "post_rejit_run_cnt_delta": 80,
      "post_rejit_run_time_ns_delta": 50342,
      "program": "trace_connect_e",
      "program_id": 39,
      "ratio": 0.9682378172160864,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 4594.2972972972975,
      "baseline_run_cnt_delta": 37,
      "baseline_run_time_ns_delta": 169989,
      "post_rejit_avg_ns_per_run": 4412.55,
      "post_rejit_run_cnt_delta": 40,
      "post_rejit_run_time_ns_delta": 176502,
      "program": "trace_connect_v",
      "program_id": 40,
      "ratio": 0.9604406755731253,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 4548.833333333333,
      "baseline_run_cnt_delta": 36,
      "baseline_run_time_ns_delta": 163758,
      "post_rejit_avg_ns_per_run": 4324.575,
      "post_rejit_run_cnt_delta": 40,
      "post_rejit_run_time_ns_delta": 172983,
      "program": "trace_connect_v",
      "program_id": 41,
      "ratio": 0.9506998131389001,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bcc/tcplife",
      "baseline_avg_ns_per_run": 693.578811369509,
      "baseline_run_cnt_delta": 774,
      "baseline_run_time_ns_delta": 536830,
      "post_rejit_avg_ns_per_run": 720.283065512979,
      "post_rejit_run_cnt_delta": 809,
      "post_rejit_run_time_ns_delta": 582709,
      "program": "sock__inet_sock",
      "program_id": 44,
      "ratio": 1.0385021193060107,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "network"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 178.20798269088425,
      "baseline_run_cnt_delta": 87815,
      "baseline_run_time_ns_delta": 15649334,
      "post_rejit_avg_ns_per_run": 170.01052509979593,
      "post_rejit_run_cnt_delta": 77909,
      "post_rejit_run_time_ns_delta": 13245350,
      "program": "sched_switch",
      "program_id": 47,
      "ratio": 0.9540006150829536,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 113.67774220724516,
      "baseline_run_cnt_delta": 59350,
      "baseline_run_time_ns_delta": 6746774,
      "post_rejit_avg_ns_per_run": 113.96891311465937,
      "post_rejit_run_cnt_delta": 51919,
      "post_rejit_run_time_ns_delta": 5917152,
      "program": "sched_wakeup",
      "program_id": 48,
      "ratio": 1.0025613713094634,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 241.01847799659615,
      "baseline_run_cnt_delta": 4113,
      "baseline_run_time_ns_delta": 991309,
      "post_rejit_avg_ns_per_run": 244.71853292581272,
      "post_rejit_run_cnt_delta": 3599,
      "post_rejit_run_time_ns_delta": 880742,
      "program": "sched_wakeup_ne",
      "program_id": 49,
      "ratio": 1.0153517479654355,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 4898.4,
      "baseline_run_cnt_delta": 5,
      "baseline_run_time_ns_delta": 24492,
      "post_rejit_avg_ns_per_run": 3257.0,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 13028,
      "program": "tracepoint__sch",
      "program_id": 131,
      "ratio": 0.6649109913441125,
      "runner": "otelcol-ebpf-profiler",
      "type": "tracepoint",
      "workload": "exec_storm"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 16236.352272727272,
      "baseline_run_cnt_delta": 88,
      "baseline_run_time_ns_delta": 1428799,
      "post_rejit_avg_ns_per_run": 15377.231707317073,
      "post_rejit_run_cnt_delta": 82,
      "post_rejit_run_time_ns_delta": 1260933,
      "program": "native_tracer_e",
      "program_id": 132,
      "ratio": 0.9470866022749893,
      "runner": "otelcol-ebpf-profiler",
      "type": "perf_event",
      "workload": "exec_storm"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 564.7289107289107,
      "baseline_run_cnt_delta": 1221,
      "baseline_run_time_ns_delta": 689534,
      "post_rejit_avg_ns_per_run": 535.5484133441822,
      "post_rejit_run_cnt_delta": 1229,
      "post_rejit_run_time_ns_delta": 658189,
      "program": "event_exit_acct",
      "program_id": 251,
      "ratio": 0.9483283096892199,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 693.0899155489319,
      "baseline_run_cnt_delta": 2013,
      "baseline_run_time_ns_delta": 1395190,
      "post_rejit_avg_ns_per_run": 749.0855365474339,
      "post_rejit_run_cnt_delta": 1929,
      "post_rejit_run_time_ns_delta": 1444986,
      "program": "event_wake_up_n",
      "program_id": 253,
      "ratio": 1.0807912793741243,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2833.4699286442406,
      "baseline_run_cnt_delta": 981,
      "baseline_run_time_ns_delta": 2779634,
      "post_rejit_avg_ns_per_run": 2919.9851222104144,
      "post_rejit_run_cnt_delta": 941,
      "post_rejit_run_time_ns_delta": 2747706,
      "program": "event_execve",
      "program_id": 254,
      "ratio": 1.0305333021859773,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 268.9388379204893,
      "baseline_run_cnt_delta": 981,
      "baseline_run_time_ns_delta": 263829,
      "post_rejit_avg_ns_per_run": 285.70988310308184,
      "post_rejit_run_cnt_delta": 941,
      "post_rejit_run_time_ns_delta": 268853,
      "program": "tg_kp_bprm_comm",
      "program_id": 257,
      "ratio": 1.0623600715771326,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1059.2561505065123,
      "baseline_run_cnt_delta": 691,
      "baseline_run_time_ns_delta": 731946,
      "post_rejit_avg_ns_per_run": 1467.5328185328185,
      "post_rejit_run_cnt_delta": 259,
      "post_rejit_run_time_ns_delta": 380091,
      "program": "generic_kprobe_",
      "program_id": 287,
      "ratio": 1.3854371464645994,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 746.6801736613603,
      "baseline_run_cnt_delta": 691,
      "baseline_run_time_ns_delta": 515956,
      "post_rejit_avg_ns_per_run": 942.8030888030888,
      "post_rejit_run_cnt_delta": 259,
      "post_rejit_run_time_ns_delta": 244186,
      "program": "generic_retkprobe_event",
      "program_id": 292,
      "ratio": 1.2626598670486135,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 864.9429569266589,
      "baseline_run_cnt_delta": 859,
      "baseline_run_time_ns_delta": 742986,
      "post_rejit_avg_ns_per_run": 1069.2018927444794,
      "post_rejit_run_cnt_delta": 317,
      "post_rejit_run_time_ns_delta": 338937,
      "program": "generic_kprobe_",
      "program_id": 293,
      "ratio": 1.236153071346577,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 676.6647990255785,
      "baseline_run_cnt_delta": 4105,
      "baseline_run_time_ns_delta": 2777709,
      "post_rejit_avg_ns_per_run": 820.3836177474403,
      "post_rejit_run_cnt_delta": 1465,
      "post_rejit_run_time_ns_delta": 1201862,
      "program": "generic_kprobe_",
      "program_id": 302,
      "ratio": 1.2123929291560933,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1075.0390738060782,
      "baseline_run_cnt_delta": 691,
      "baseline_run_time_ns_delta": 742852,
      "post_rejit_avg_ns_per_run": 1463.3436293436293,
      "post_rejit_run_cnt_delta": 259,
      "post_rejit_run_time_ns_delta": 379006,
      "program": "generic_kprobe_",
      "program_id": 309,
      "ratio": 1.361200411221142,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 914.204052098408,
      "baseline_run_cnt_delta": 691,
      "baseline_run_time_ns_delta": 631715,
      "post_rejit_avg_ns_per_run": 1194.6216216216217,
      "post_rejit_run_cnt_delta": 259,
      "post_rejit_run_time_ns_delta": 309407,
      "program": "generic_retkprobe_event",
      "program_id": 317,
      "ratio": 1.3067341135488957,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 832.6088474970896,
      "baseline_run_cnt_delta": 859,
      "baseline_run_time_ns_delta": 715211,
      "post_rejit_avg_ns_per_run": 1126.9463722397477,
      "post_rejit_run_cnt_delta": 317,
      "post_rejit_run_time_ns_delta": 357242,
      "program": "generic_kprobe_",
      "program_id": 320,
      "ratio": 1.353512367334875,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 717.6789524733268,
      "baseline_run_cnt_delta": 2062,
      "baseline_run_time_ns_delta": 1479854,
      "post_rejit_avg_ns_per_run": 931.7577807848444,
      "post_rejit_run_cnt_delta": 739,
      "post_rejit_run_time_ns_delta": 688569,
      "program": "generic_kprobe_",
      "program_id": 328,
      "ratio": 1.298293307298118,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 724.8149779735683,
      "baseline_run_cnt_delta": 2043,
      "baseline_run_time_ns_delta": 1480797,
      "post_rejit_avg_ns_per_run": 935.0068965517241,
      "post_rejit_run_cnt_delta": 725,
      "post_rejit_run_time_ns_delta": 677880,
      "program": "generic_kprobe_",
      "program_id": 338,
      "ratio": 1.2899938949465541,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 266.0651364617172,
      "baseline_run_cnt_delta": 42173,
      "baseline_run_time_ns_delta": 11220765,
      "post_rejit_avg_ns_per_run": 277.76609155625863,
      "post_rejit_run_cnt_delta": 40456,
      "post_rejit_run_time_ns_delta": 11237305,
      "program": "generic_kprobe_",
      "program_id": 354,
      "ratio": 1.0439777839748088,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 489.0099170756473,
      "baseline_run_cnt_delta": 147725,
      "baseline_run_time_ns_delta": 72238990,
      "post_rejit_avg_ns_per_run": 477.7461712743435,
      "post_rejit_run_cnt_delta": 161542,
      "post_rejit_run_time_ns_delta": 77176072,
      "program": "generic_kprobe_",
      "program_id": 362,
      "ratio": 0.9769662221399052,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 39.545142764372834,
      "baseline_run_cnt_delta": 147831,
      "baseline_run_time_ns_delta": 5845998,
      "post_rejit_avg_ns_per_run": 38.31192320292749,
      "post_rejit_run_cnt_delta": 161777,
      "post_rejit_run_time_ns_delta": 6197988,
      "program": "generic_retkprobe_event",
      "program_id": 369,
      "ratio": 0.9688148916595547,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 989.7220777422135,
      "baseline_run_cnt_delta": 129968,
      "baseline_run_time_ns_delta": 128632199,
      "post_rejit_avg_ns_per_run": 987.3803118705007,
      "post_rejit_run_cnt_delta": 124603,
      "post_rejit_run_time_ns_delta": 123030549,
      "program": "generic_kprobe_",
      "program_id": 374,
      "ratio": 0.9976339156977735,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 47.665617690508434,
      "baseline_run_cnt_delta": 129968,
      "baseline_run_time_ns_delta": 6195005,
      "post_rejit_avg_ns_per_run": 48.61637360256174,
      "post_rejit_run_cnt_delta": 124603,
      "post_rejit_run_time_ns_delta": 6057746,
      "program": "generic_retkprobe_event",
      "program_id": 381,
      "ratio": 1.0199463671744806,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 6430.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 12861,
      "post_rejit_avg_ns_per_run": 5849.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 11699,
      "program": "generic_kprobe_",
      "program_id": 410,
      "ratio": 0.9096493274239951,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1560.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 3121,
      "post_rejit_avg_ns_per_run": 1624.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 3248,
      "program": "generic_retkprobe_event",
      "program_id": 411,
      "ratio": 1.0406920858699136,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2859.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 5718,
      "post_rejit_avg_ns_per_run": 3369.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 6738,
      "program": "generic_kprobe_",
      "program_id": 417,
      "ratio": 1.1783840503672613,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4051.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 8103,
      "post_rejit_avg_ns_per_run": 4934.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 9869,
      "program": "generic_kprobe_",
      "program_id": 422,
      "ratio": 1.2179439713686289,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1440.902140672783,
      "baseline_run_cnt_delta": 981,
      "baseline_run_time_ns_delta": 1413525,
      "post_rejit_avg_ns_per_run": 1596.2327311370882,
      "post_rejit_run_cnt_delta": 941,
      "post_rejit_run_time_ns_delta": 1502055,
      "program": "generic_kprobe_",
      "program_id": 435,
      "ratio": 1.1078009297645839,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 433.0221243011158,
      "baseline_run_cnt_delta": 912526,
      "baseline_run_time_ns_delta": 395143947,
      "post_rejit_avg_ns_per_run": 416.817121942728,
      "post_rejit_run_cnt_delta": 901907,
      "post_rejit_run_time_ns_delta": 375930280,
      "program": "generic_tracepo",
      "program_id": 438,
      "ratio": 0.9625769644344566,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1497.1467889908256,
      "baseline_run_cnt_delta": 981,
      "baseline_run_time_ns_delta": 1468701,
      "post_rejit_avg_ns_per_run": 1530.0648246546227,
      "post_rejit_run_cnt_delta": 941,
      "post_rejit_run_time_ns_delta": 1439791,
      "program": "generic_rawtp_e",
      "program_id": 448,
      "ratio": 1.02198717981821,
      "runner": "tetragon",
      "type": "raw_tracepoint",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2024.1525423728813,
      "baseline_run_cnt_delta": 177,
      "baseline_run_time_ns_delta": 358275,
      "post_rejit_avg_ns_per_run": 3349.4057971014495,
      "post_rejit_run_cnt_delta": 69,
      "post_rejit_run_time_ns_delta": 231109,
      "program": "generic_kprobe_",
      "program_id": 449,
      "ratio": 1.6547200504834458,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2643.3643815482023,
      "baseline_run_cnt_delta": 53068,
      "baseline_run_time_ns_delta": 140278061,
      "post_rejit_avg_ns_per_run": 2650.6689186542903,
      "post_rejit_run_cnt_delta": 51066,
      "post_rejit_run_time_ns_delta": 135359059,
      "program": "generic_kprobe_",
      "program_id": 461,
      "ratio": 1.0027633485406238,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 5173.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 5173,
      "post_rejit_avg_ns_per_run": 4729.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 4729,
      "program": "generic_kprobe_",
      "program_id": 468,
      "ratio": 0.9141697274308912,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1095.3617945007236,
      "baseline_run_cnt_delta": 691,
      "baseline_run_time_ns_delta": 756895,
      "post_rejit_avg_ns_per_run": 1564.4324324324325,
      "post_rejit_run_cnt_delta": 259,
      "post_rejit_run_time_ns_delta": 405188,
      "program": "generic_kprobe_",
      "program_id": 472,
      "ratio": 1.428233520912162,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 834.0057887120116,
      "baseline_run_cnt_delta": 691,
      "baseline_run_time_ns_delta": 576298,
      "post_rejit_avg_ns_per_run": 1102.3822393822393,
      "post_rejit_run_cnt_delta": 259,
      "post_rejit_run_time_ns_delta": 285517,
      "program": "generic_retkprobe_event",
      "program_id": 480,
      "ratio": 1.321792071832849,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 891.9697322467986,
      "baseline_run_cnt_delta": 859,
      "baseline_run_time_ns_delta": 766202,
      "post_rejit_avg_ns_per_run": 1151.006309148265,
      "post_rejit_run_cnt_delta": 317,
      "post_rejit_run_time_ns_delta": 364869,
      "program": "generic_kprobe_",
      "program_id": 485,
      "ratio": 1.2904096042014503,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 614.5833333333334,
      "baseline_run_cnt_delta": 1680,
      "baseline_run_time_ns_delta": 1032500,
      "post_rejit_avg_ns_per_run": 817.5533333333333,
      "post_rejit_run_cnt_delta": 600,
      "post_rejit_run_time_ns_delta": 490532,
      "program": "generic_kprobe_",
      "program_id": 492,
      "ratio": 1.3302562711864405,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1030.4444444444443,
      "baseline_run_cnt_delta": 504,
      "baseline_run_time_ns_delta": 519344,
      "post_rejit_avg_ns_per_run": 1602.138888888889,
      "post_rejit_run_cnt_delta": 180,
      "post_rejit_run_time_ns_delta": 288385,
      "program": "generic_kprobe_",
      "program_id": 495,
      "ratio": 1.5548037524261378,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1342.0535714285713,
      "baseline_run_cnt_delta": 168,
      "baseline_run_time_ns_delta": 225465,
      "post_rejit_avg_ns_per_run": 2160.5833333333335,
      "post_rejit_run_cnt_delta": 60,
      "post_rejit_run_time_ns_delta": 129635,
      "program": "generic_kprobe_",
      "program_id": 505,
      "ratio": 1.6099084115051119,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 962.7559523809524,
      "baseline_run_cnt_delta": 168,
      "baseline_run_time_ns_delta": 161743,
      "post_rejit_avg_ns_per_run": 1391.5333333333333,
      "post_rejit_run_cnt_delta": 60,
      "post_rejit_run_time_ns_delta": 83492,
      "program": "generic_retkprobe_event",
      "program_id": 510,
      "ratio": 1.4453645598263911,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2232.6428571428573,
      "baseline_run_cnt_delta": 168,
      "baseline_run_time_ns_delta": 375084,
      "post_rejit_avg_ns_per_run": 3667.5666666666666,
      "post_rejit_run_cnt_delta": 60,
      "post_rejit_run_time_ns_delta": 220054,
      "program": "generic_kprobe_",
      "program_id": 518,
      "ratio": 1.6427019014407438,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1206.6329365079366,
      "baseline_run_cnt_delta": 504,
      "baseline_run_time_ns_delta": 608143,
      "post_rejit_avg_ns_per_run": 1717.588888888889,
      "post_rejit_run_cnt_delta": 180,
      "post_rejit_run_time_ns_delta": 309166,
      "program": "generic_kprobe_",
      "program_id": 526,
      "ratio": 1.423455996369275,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1652.8372781065088,
      "baseline_run_cnt_delta": 338,
      "baseline_run_time_ns_delta": 558659,
      "post_rejit_avg_ns_per_run": 2534.2916666666665,
      "post_rejit_run_cnt_delta": 120,
      "post_rejit_run_time_ns_delta": 304115,
      "program": "generic_kprobe_",
      "program_id": 530,
      "ratio": 1.533297742152786,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "katran",
      "baseline_avg_ns_per_run": 52.82421875,
      "baseline_run_cnt_delta": 1024,
      "baseline_run_time_ns_delta": 54092,
      "post_rejit_avg_ns_per_run": 50.947265625,
      "post_rejit_run_cnt_delta": 1024,
      "post_rejit_run_time_ns_delta": 52170,
      "program": "balancer_ingress",
      "program_id": 553,
      "ratio": 0.9644679435036604,
      "runner": "katran",
      "type": "xdp",
      "workload": "test_run"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 146.22018926277013,
      "baseline_run_cnt_delta": 3079528,
      "baseline_run_time_ns_delta": 450289167,
      "post_rejit_avg_ns_per_run": 146.32881047863881,
      "post_rejit_run_cnt_delta": 2994053,
      "post_rejit_run_time_ns_delta": 438116214,
      "program": "tracepoint__raw",
      "program_id": 570,
      "ratio": 1.0007428605886528,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 357.9611721345326,
      "baseline_run_cnt_delta": 3080056,
      "baseline_run_time_ns_delta": 1102540456,
      "post_rejit_avg_ns_per_run": 352.25863312740336,
      "post_rejit_run_cnt_delta": 2994222,
      "post_rejit_run_time_ns_delta": 1054740549,
      "program": "tracepoint__raw",
      "program_id": 573,
      "ratio": 0.9840693922943518,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 339.39799052225,
      "baseline_run_cnt_delta": 3080900,
      "baseline_run_time_ns_delta": 1045651269,
      "post_rejit_avg_ns_per_run": 339.19053545157,
      "post_rejit_run_cnt_delta": 2994818,
      "post_rejit_run_time_ns_delta": 1015813921,
      "program": "trace_sys_enter",
      "program_id": 576,
      "ratio": 0.9993887557484923,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 304.255946311025,
      "baseline_run_cnt_delta": 3081154,
      "baseline_run_time_ns_delta": 937459426,
      "post_rejit_avg_ns_per_run": 310.33924380590844,
      "post_rejit_run_cnt_delta": 2994628,
      "post_rejit_run_time_ns_delta": 929350589,
      "program": "trace_sys_exit",
      "program_id": 577,
      "ratio": 1.0199940134897636,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 600.7592592592592,
      "baseline_run_cnt_delta": 54,
      "baseline_run_time_ns_delta": 32441,
      "post_rejit_avg_ns_per_run": 712.2666666666667,
      "post_rejit_run_cnt_delta": 60,
      "post_rejit_run_time_ns_delta": 42736,
      "program": "trace_ptrace",
      "program_id": 578,
      "ratio": 1.185610801146697,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1443.351851851852,
      "baseline_run_cnt_delta": 54,
      "baseline_run_time_ns_delta": 77941,
      "post_rejit_avg_ns_per_run": 1456.6333333333334,
      "post_rejit_run_cnt_delta": 60,
      "post_rejit_run_time_ns_delta": 87398,
      "program": "trace_ret_ptrac",
      "program_id": 579,
      "ratio": 1.0092018321550917,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 350.3703703703704,
      "baseline_run_cnt_delta": 27,
      "baseline_run_time_ns_delta": 9460,
      "post_rejit_avg_ns_per_run": 451.1666666666667,
      "post_rejit_run_cnt_delta": 30,
      "post_rejit_run_time_ns_delta": 13535,
      "program": "trace_process_v",
      "program_id": 580,
      "ratio": 1.2876849894291755,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1774.2222222222222,
      "baseline_run_cnt_delta": 27,
      "baseline_run_time_ns_delta": 47904,
      "post_rejit_avg_ns_per_run": 1962.4,
      "post_rejit_run_cnt_delta": 30,
      "post_rejit_run_time_ns_delta": 58872,
      "program": "trace_ret_proce",
      "program_id": 581,
      "ratio": 1.1060621242484971,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1001.7169811320755,
      "baseline_run_cnt_delta": 53,
      "baseline_run_time_ns_delta": 53091,
      "post_rejit_avg_ns_per_run": 1334.2954545454545,
      "post_rejit_run_cnt_delta": 44,
      "post_rejit_run_time_ns_delta": 58709,
      "program": "trace_arch_prct",
      "program_id": 582,
      "ratio": 1.3320084212184569,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1641.7358490566037,
      "baseline_run_cnt_delta": 53,
      "baseline_run_time_ns_delta": 87012,
      "post_rejit_avg_ns_per_run": 1868.5,
      "post_rejit_run_cnt_delta": 44,
      "post_rejit_run_time_ns_delta": 82214,
      "program": "trace_ret_arch_",
      "program_id": 583,
      "ratio": 1.1381246264883005,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1006.6545454545454,
      "baseline_run_cnt_delta": 55,
      "baseline_run_time_ns_delta": 55366,
      "post_rejit_avg_ns_per_run": 1094.8275862068965,
      "post_rejit_run_cnt_delta": 58,
      "post_rejit_run_time_ns_delta": 63500,
      "program": "trace_dup2",
      "program_id": 586,
      "ratio": 1.0875901679980369,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2143.7636363636366,
      "baseline_run_cnt_delta": 55,
      "baseline_run_time_ns_delta": 117907,
      "post_rejit_avg_ns_per_run": 2203.6206896551726,
      "post_rejit_run_cnt_delta": 58,
      "post_rejit_run_time_ns_delta": 127810,
      "program": "trace_ret_dup2",
      "program_id": 587,
      "ratio": 1.0279214799039453,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4561.14375,
      "baseline_run_cnt_delta": 160,
      "baseline_run_time_ns_delta": 729783,
      "post_rejit_avg_ns_per_run": 5147.775,
      "post_rejit_run_cnt_delta": 160,
      "post_rejit_run_time_ns_delta": 823644,
      "program": "tracepoint__sch",
      "program_id": 595,
      "ratio": 1.128614944442389,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4759.830188679245,
      "baseline_run_cnt_delta": 53,
      "baseline_run_time_ns_delta": 252271,
      "post_rejit_avg_ns_per_run": 4849.568181818182,
      "post_rejit_run_cnt_delta": 44,
      "post_rejit_run_time_ns_delta": 213381,
      "program": "tracepoint__sch",
      "program_id": 603,
      "ratio": 1.0188531921479824,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1758.95,
      "baseline_run_cnt_delta": 160,
      "baseline_run_time_ns_delta": 281432,
      "post_rejit_avg_ns_per_run": 1762.7125,
      "post_rejit_run_cnt_delta": 160,
      "post_rejit_run_time_ns_delta": 282034,
      "program": "tracepoint__sch",
      "program_id": 605,
      "ratio": 1.0021390602347993,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1461.3875,
      "baseline_run_cnt_delta": 160,
      "baseline_run_time_ns_delta": 233822,
      "post_rejit_avg_ns_per_run": 1554.525,
      "post_rejit_run_cnt_delta": 160,
      "post_rejit_run_time_ns_delta": 248724,
      "program": "tracepoint__sch",
      "program_id": 606,
      "ratio": 1.0637322407643421,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 269.37962148794395,
      "baseline_run_cnt_delta": 291140,
      "baseline_run_time_ns_delta": 78427183,
      "post_rejit_avg_ns_per_run": 269.16992204755985,
      "post_rejit_run_cnt_delta": 294282,
      "post_rejit_run_time_ns_delta": 79211863,
      "program": "tracepoint__sch",
      "program_id": 608,
      "ratio": 0.9992215467553714,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 18.220704453865075,
      "baseline_run_cnt_delta": 19107,
      "baseline_run_time_ns_delta": 348143,
      "post_rejit_avg_ns_per_run": 18.161744022503516,
      "post_rejit_run_cnt_delta": 25596,
      "post_rejit_run_time_ns_delta": 464868,
      "program": "trace_filldir64",
      "program_id": 609,
      "ratio": 0.996764097046256,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1363.4,
      "baseline_run_cnt_delta": 160,
      "baseline_run_time_ns_delta": 218144,
      "post_rejit_avg_ns_per_run": 1322.3,
      "post_rejit_run_cnt_delta": 160,
      "post_rejit_run_time_ns_delta": 211568,
      "program": "trace_do_exit",
      "program_id": 611,
      "ratio": 0.9698547748276367,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 725.2022471910112,
      "baseline_run_cnt_delta": 178,
      "baseline_run_time_ns_delta": 129086,
      "post_rejit_avg_ns_per_run": 689.0518134715026,
      "post_rejit_run_cnt_delta": 193,
      "post_rejit_run_time_ns_delta": 132987,
      "program": "trace_security_",
      "program_id": 615,
      "ratio": 0.9501512386930221,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2800.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 2800,
      "post_rejit_avg_ns_per_run": 3347.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 3347,
      "program": "tracepoint__cgr",
      "program_id": 617,
      "ratio": 1.1953571428571428,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1750.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1750,
      "post_rejit_avg_ns_per_run": 1959.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1959,
      "program": "tracepoint__cgr",
      "program_id": 618,
      "ratio": 1.1194285714285714,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1549.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1549,
      "post_rejit_avg_ns_per_run": 1951.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1951,
      "program": "tracepoint__cgr",
      "program_id": 619,
      "ratio": 1.2595222724338282,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3174.4716981132074,
      "baseline_run_cnt_delta": 53,
      "baseline_run_time_ns_delta": 168247,
      "post_rejit_avg_ns_per_run": 3628.4772727272725,
      "post_rejit_run_cnt_delta": 44,
      "post_rejit_run_time_ns_delta": 159653,
      "program": "trace_security_",
      "program_id": 620,
      "ratio": 1.1430176790941025,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 716.4887897031348,
      "baseline_run_cnt_delta": 9634,
      "baseline_run_time_ns_delta": 6902653,
      "post_rejit_avg_ns_per_run": 808.1322957198444,
      "post_rejit_run_cnt_delta": 7453,
      "post_rejit_run_time_ns_delta": 6023010,
      "program": "trace_security_file_open",
      "program_id": 621,
      "ratio": 1.1279064059811468,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1818.453125,
      "baseline_run_cnt_delta": 128,
      "baseline_run_time_ns_delta": 232762,
      "post_rejit_avg_ns_per_run": 1698.95,
      "post_rejit_run_cnt_delta": 140,
      "post_rejit_run_time_ns_delta": 237853,
      "program": "trace_security_",
      "program_id": 623,
      "ratio": 0.9342830874455452,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 915.1217391304348,
      "baseline_run_cnt_delta": 115,
      "baseline_run_time_ns_delta": 105239,
      "post_rejit_avg_ns_per_run": 1019.290909090909,
      "post_rejit_run_cnt_delta": 110,
      "post_rejit_run_time_ns_delta": 112122,
      "program": "trace_commit_cr",
      "program_id": 624,
      "ratio": 1.113830942383095,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1330.3875,
      "baseline_run_cnt_delta": 160,
      "baseline_run_time_ns_delta": 212862,
      "post_rejit_avg_ns_per_run": 1867.9375,
      "post_rejit_run_cnt_delta": 160,
      "post_rejit_run_time_ns_delta": 298870,
      "program": "trace_switch_ta",
      "program_id": 625,
      "ratio": 1.4040552094784413,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 228.52342871423215,
      "baseline_run_cnt_delta": 24009,
      "baseline_run_time_ns_delta": 5486619,
      "post_rejit_avg_ns_per_run": 174.39527703604807,
      "post_rejit_run_cnt_delta": 23968,
      "post_rejit_run_time_ns_delta": 4179906,
      "program": "trace_cap_capab",
      "program_id": 626,
      "ratio": 0.7631395958710598,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 970.1223021582733,
      "baseline_run_cnt_delta": 139,
      "baseline_run_time_ns_delta": 134847,
      "post_rejit_avg_ns_per_run": 929.0573770491803,
      "post_rejit_run_cnt_delta": 122,
      "post_rejit_run_time_ns_delta": 113345,
      "program": "trace_security_",
      "program_id": 627,
      "ratio": 0.9576703627803071,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2791.6666666666665,
      "baseline_run_cnt_delta": 27,
      "baseline_run_time_ns_delta": 75375,
      "post_rejit_avg_ns_per_run": 2485.5,
      "post_rejit_run_cnt_delta": 30,
      "post_rejit_run_time_ns_delta": 74565,
      "program": "trace_security_",
      "program_id": 628,
      "ratio": 0.8903283582089553,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1915.6666666666667,
      "baseline_run_cnt_delta": 27,
      "baseline_run_time_ns_delta": 51723,
      "post_rejit_avg_ns_per_run": 1785.9666666666667,
      "post_rejit_run_cnt_delta": 30,
      "post_rejit_run_time_ns_delta": 53579,
      "program": "trace_security_",
      "program_id": 632,
      "ratio": 0.9322951104924309,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1650.4444444444443,
      "baseline_run_cnt_delta": 27,
      "baseline_run_time_ns_delta": 44562,
      "post_rejit_avg_ns_per_run": 1642.9666666666667,
      "post_rejit_run_cnt_delta": 30,
      "post_rejit_run_time_ns_delta": 49289,
      "program": "trace_security_",
      "program_id": 633,
      "ratio": 0.995469233876397,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2272.9897959183672,
      "baseline_run_cnt_delta": 98,
      "baseline_run_time_ns_delta": 222753,
      "post_rejit_avg_ns_per_run": 2384.19,
      "post_rejit_run_cnt_delta": 100,
      "post_rejit_run_time_ns_delta": 238419,
      "program": "trace_security_",
      "program_id": 634,
      "ratio": 1.0489224387550338,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1099.8703703703704,
      "baseline_run_cnt_delta": 54,
      "baseline_run_time_ns_delta": 59393,
      "post_rejit_avg_ns_per_run": 1608.21875,
      "post_rejit_run_cnt_delta": 32,
      "post_rejit_run_time_ns_delta": 51463,
      "program": "trace_security_",
      "program_id": 635,
      "ratio": 1.462189357331672,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1641.1666666666667,
      "baseline_run_cnt_delta": 36,
      "baseline_run_time_ns_delta": 59082,
      "post_rejit_avg_ns_per_run": 1767.111111111111,
      "post_rejit_run_cnt_delta": 36,
      "post_rejit_run_time_ns_delta": 63616,
      "program": "trace_security_",
      "program_id": 636,
      "ratio": 1.0767408009207542,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 65.32681741068038,
      "baseline_run_cnt_delta": 39493,
      "baseline_run_time_ns_delta": 2579952,
      "post_rejit_avg_ns_per_run": 62.997339776443596,
      "post_rejit_run_cnt_delta": 40974,
      "post_rejit_run_time_ns_delta": 2581253,
      "program": "trace_vfs_write",
      "program_id": 639,
      "ratio": 0.9643411737083042,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 41.46342080623529,
      "baseline_run_cnt_delta": 39517,
      "baseline_run_time_ns_delta": 1638510,
      "post_rejit_avg_ns_per_run": 40.6414279439754,
      "post_rejit_run_cnt_delta": 40982,
      "post_rejit_run_time_ns_delta": 1665567,
      "program": "vfs_write_magic",
      "program_id": 640,
      "ratio": 0.9801754692141494,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 33.900725902319344,
      "baseline_run_cnt_delta": 39537,
      "baseline_run_time_ns_delta": 1340333,
      "post_rejit_avg_ns_per_run": 35.9941419121775,
      "post_rejit_run_cnt_delta": 40969,
      "post_rejit_run_time_ns_delta": 1474644,
      "program": "trace_ret_vfs_w",
      "program_id": 641,
      "ratio": 1.0617513623717105,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 44.826763092017096,
      "baseline_run_cnt_delta": 39547,
      "baseline_run_time_ns_delta": 1772764,
      "post_rejit_avg_ns_per_run": 43.57662807171821,
      "post_rejit_run_cnt_delta": 40938,
      "post_rejit_run_time_ns_delta": 1783940,
      "program": "vfs_write_magic",
      "program_id": 642,
      "ratio": 0.972111860547845,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 63.00070571630204,
      "baseline_run_cnt_delta": 2834,
      "baseline_run_time_ns_delta": 178544,
      "post_rejit_avg_ns_per_run": 68.93434065934066,
      "post_rejit_run_cnt_delta": 3640,
      "post_rejit_run_time_ns_delta": 250921,
      "program": "trace_vfs_write",
      "program_id": 644,
      "ratio": 1.0941836266050466,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 39.121383203952014,
      "baseline_run_cnt_delta": 2834,
      "baseline_run_time_ns_delta": 110870,
      "post_rejit_avg_ns_per_run": 45.331043956043956,
      "post_rejit_run_cnt_delta": 3640,
      "post_rejit_run_time_ns_delta": 165005,
      "program": "vfs_writev_magi",
      "program_id": 645,
      "ratio": 1.1587280470048575,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 44.50352858151023,
      "baseline_run_cnt_delta": 2834,
      "baseline_run_time_ns_delta": 126123,
      "post_rejit_avg_ns_per_run": 43.63543956043956,
      "post_rejit_run_cnt_delta": 3640,
      "post_rejit_run_time_ns_delta": 158833,
      "program": "trace_ret_vfs_w",
      "program_id": 646,
      "ratio": 0.9804939282627729,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 47.419901199717714,
      "baseline_run_cnt_delta": 2834,
      "baseline_run_time_ns_delta": 134388,
      "post_rejit_avg_ns_per_run": 49.53489010989011,
      "post_rejit_run_cnt_delta": 3640,
      "post_rejit_run_time_ns_delta": 180307,
      "program": "vfs_writev_magi",
      "program_id": 647,
      "ratio": 1.0446012930576283,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 77.32993762993763,
      "baseline_run_cnt_delta": 19240,
      "baseline_run_time_ns_delta": 1487828,
      "post_rejit_avg_ns_per_run": 79.9324002719855,
      "post_rejit_run_cnt_delta": 17648,
      "post_rejit_run_time_ns_delta": 1410647,
      "program": "trace_vfs_read",
      "program_id": 654,
      "ratio": 1.0336540119106516,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 79.36277705345502,
      "baseline_run_cnt_delta": 3068,
      "baseline_run_time_ns_delta": 243485,
      "post_rejit_avg_ns_per_run": 152.97050147492627,
      "post_rejit_run_cnt_delta": 1356,
      "post_rejit_run_time_ns_delta": 207428,
      "program": "trace_ret_vfs_r",
      "program_id": 655,
      "ratio": 1.9274842332179551,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 75.58574453069866,
      "baseline_run_cnt_delta": 2834,
      "baseline_run_time_ns_delta": 214210,
      "post_rejit_avg_ns_per_run": 74.81565934065934,
      "post_rejit_run_cnt_delta": 3640,
      "post_rejit_run_time_ns_delta": 272329,
      "program": "trace_vfs_readv",
      "program_id": 657,
      "ratio": 0.9898117668242778,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 63.92554693013409,
      "baseline_run_cnt_delta": 2834,
      "baseline_run_time_ns_delta": 181165,
      "post_rejit_avg_ns_per_run": 54.50027472527473,
      "post_rejit_run_cnt_delta": 3640,
      "post_rejit_run_time_ns_delta": 198381,
      "program": "trace_ret_vfs_r",
      "program_id": 658,
      "ratio": 0.8525585989094393,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 161.63837471783296,
      "baseline_run_cnt_delta": 2215,
      "baseline_run_time_ns_delta": 358029,
      "post_rejit_avg_ns_per_run": 190.2894033837934,
      "post_rejit_run_cnt_delta": 1123,
      "post_rejit_run_time_ns_delta": 213695,
      "program": "trace_mmap_aler",
      "program_id": 660,
      "ratio": 1.1772538774655192,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 99.18092105263158,
      "baseline_run_cnt_delta": 1520,
      "baseline_run_time_ns_delta": 150755,
      "post_rejit_avg_ns_per_run": 119.17771084337349,
      "post_rejit_run_cnt_delta": 996,
      "post_rejit_run_time_ns_delta": 118701,
      "program": "trace_do_mmap",
      "program_id": 661,
      "ratio": 1.2016193193056794,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 61.688815789473686,
      "baseline_run_cnt_delta": 1520,
      "baseline_run_time_ns_delta": 93767,
      "post_rejit_avg_ns_per_run": 65.72590361445783,
      "post_rejit_run_cnt_delta": 996,
      "post_rejit_run_time_ns_delta": 65463,
      "program": "trace_ret_do_mm",
      "program_id": 662,
      "ratio": 1.0654427836443088,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 850.9690789473684,
      "baseline_run_cnt_delta": 1520,
      "baseline_run_time_ns_delta": 1293473,
      "post_rejit_avg_ns_per_run": 835.7178714859438,
      "post_rejit_run_cnt_delta": 996,
      "post_rejit_run_time_ns_delta": 832375,
      "program": "trace_security_mmap_file",
      "program_id": 663,
      "ratio": 0.9820778359182097,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1284.0361010830325,
      "baseline_run_cnt_delta": 277,
      "baseline_run_time_ns_delta": 355678,
      "post_rejit_avg_ns_per_run": 1353.846590909091,
      "post_rejit_run_cnt_delta": 176,
      "post_rejit_run_time_ns_delta": 238277,
      "program": "trace_security_file_mprotect",
      "program_id": 664,
      "ratio": 1.0543680117460688,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 378.31150529029964,
      "baseline_run_cnt_delta": 22494,
      "baseline_run_time_ns_delta": 8509739,
      "post_rejit_avg_ns_per_run": 311.98853698305254,
      "post_rejit_run_cnt_delta": 20239,
      "post_rejit_run_time_ns_delta": 6314336,
      "program": "trace_security_",
      "program_id": 666,
      "ratio": 0.8246868853318279,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 340.0993798696136,
      "baseline_run_cnt_delta": 6289,
      "baseline_run_time_ns_delta": 2138885,
      "post_rejit_avg_ns_per_run": 271.1817737998373,
      "post_rejit_run_cnt_delta": 6145,
      "post_rejit_run_time_ns_delta": 1666412,
      "program": "trace_security_",
      "program_id": 669,
      "ratio": 0.7973603889069196,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1142.5197628458498,
      "baseline_run_cnt_delta": 506,
      "baseline_run_time_ns_delta": 578115,
      "post_rejit_avg_ns_per_run": 970.8735177865613,
      "post_rejit_run_cnt_delta": 506,
      "post_rejit_run_time_ns_delta": 491262,
      "program": "trace_security_",
      "program_id": 670,
      "ratio": 0.8497651851275265,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2439.1666666666665,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 29270,
      "post_rejit_avg_ns_per_run": 2296.4166666666665,
      "post_rejit_run_cnt_delta": 12,
      "post_rejit_run_time_ns_delta": 27557,
      "program": "trace_security_",
      "program_id": 674,
      "ratio": 0.9414759139050222,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2713.5,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 32562,
      "post_rejit_avg_ns_per_run": 2865.4166666666665,
      "post_rejit_run_cnt_delta": 12,
      "post_rejit_run_time_ns_delta": 34385,
      "program": "trace_security_",
      "program_id": 675,
      "ratio": 1.055985504575886,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2391.703703703704,
      "baseline_run_cnt_delta": 27,
      "baseline_run_time_ns_delta": 64576,
      "post_rejit_avg_ns_per_run": 2232.8333333333335,
      "post_rejit_run_cnt_delta": 30,
      "post_rejit_run_time_ns_delta": 66985,
      "program": "trace_security_",
      "program_id": 676,
      "ratio": 0.93357439296333,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 6172.916666666667,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 74075,
      "post_rejit_avg_ns_per_run": 6243.75,
      "post_rejit_run_cnt_delta": 12,
      "post_rejit_run_time_ns_delta": 74925,
      "program": "tracepoint__mod",
      "program_id": 680,
      "ratio": 1.0114748565642928,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 6438.083333333333,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 77257,
      "post_rejit_avg_ns_per_run": 6049.083333333333,
      "post_rejit_run_cnt_delta": 12,
      "post_rejit_run_time_ns_delta": 72589,
      "program": "tracepoint__mod",
      "program_id": 681,
      "ratio": 0.9395782906403303,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 522.25,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 6267,
      "post_rejit_avg_ns_per_run": 720.6666666666666,
      "post_rejit_run_cnt_delta": 12,
      "post_rejit_run_time_ns_delta": 8648,
      "program": "trace_do_init_m",
      "program_id": 682,
      "ratio": 1.3799265996489547,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 189.83333333333334,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 2278,
      "post_rejit_avg_ns_per_run": 215.5,
      "post_rejit_run_cnt_delta": 12,
      "post_rejit_run_time_ns_delta": 2586,
      "program": "trace_ret_do_in",
      "program_id": 683,
      "ratio": 1.1352063213345038,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1602.2924528301887,
      "baseline_run_cnt_delta": 106,
      "baseline_run_time_ns_delta": 169843,
      "post_rejit_avg_ns_per_run": 1760.1136363636363,
      "post_rejit_run_cnt_delta": 88,
      "post_rejit_run_time_ns_delta": 154890,
      "program": "trace_load_elf_",
      "program_id": 684,
      "ratio": 1.0984971147150335,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 35.08032277453099,
      "baseline_run_cnt_delta": 78197,
      "baseline_run_time_ns_delta": 2743176,
      "post_rejit_avg_ns_per_run": 35.66635244758959,
      "post_rejit_run_cnt_delta": 75319,
      "post_rejit_run_time_ns_delta": 2686354,
      "program": "trace_security_",
      "program_id": 685,
      "ratio": 1.0167053671890405,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1704.4545454545455,
      "baseline_run_cnt_delta": 55,
      "baseline_run_time_ns_delta": 93745,
      "post_rejit_avg_ns_per_run": 2078.3260869565215,
      "post_rejit_run_cnt_delta": 46,
      "post_rejit_run_time_ns_delta": 95603,
      "program": "tracepoint__tas",
      "program_id": 686,
      "ratio": 1.2193496696635413,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2581.740740740741,
      "baseline_run_cnt_delta": 27,
      "baseline_run_time_ns_delta": 69707,
      "post_rejit_avg_ns_per_run": 2812.3,
      "post_rejit_run_cnt_delta": 30,
      "post_rejit_run_time_ns_delta": 84369,
      "program": "trace_security_",
      "program_id": 687,
      "ratio": 1.0893038001922333,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 548.9875699192045,
      "baseline_run_cnt_delta": 1609,
      "baseline_run_time_ns_delta": 883321,
      "post_rejit_avg_ns_per_run": 438.2507903055848,
      "post_rejit_run_cnt_delta": 949,
      "post_rejit_run_time_ns_delta": 415900,
      "program": "trace_do_sigact",
      "program_id": 690,
      "ratio": 0.7982890949062527,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2554.4,
      "baseline_run_cnt_delta": 45,
      "baseline_run_time_ns_delta": 114948,
      "post_rejit_avg_ns_per_run": 2814.5208333333335,
      "post_rejit_run_cnt_delta": 48,
      "post_rejit_run_time_ns_delta": 135097,
      "program": "trace_vfs_utime",
      "program_id": 691,
      "ratio": 1.1018324590249504,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 923.1108033240997,
      "baseline_run_cnt_delta": 1444,
      "baseline_run_time_ns_delta": 1332972,
      "post_rejit_avg_ns_per_run": 785.1162162162162,
      "post_rejit_run_cnt_delta": 1850,
      "post_rejit_run_time_ns_delta": 1452465,
      "program": "trace_do_trunca",
      "program_id": 693,
      "ratio": 0.8505113507382123,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 280.7097688292319,
      "baseline_run_cnt_delta": 13410,
      "baseline_run_time_ns_delta": 3764318,
      "post_rejit_avg_ns_per_run": 294.10065695084194,
      "post_rejit_run_cnt_delta": 13243,
      "post_rejit_run_time_ns_delta": 3894775,
      "program": "trace_fd_instal",
      "program_id": 694,
      "ratio": 1.0477036769238919,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 762.452064141931,
      "baseline_run_cnt_delta": 5862,
      "baseline_run_time_ns_delta": 4469494,
      "post_rejit_avg_ns_per_run": 903.4051485148515,
      "post_rejit_run_cnt_delta": 5050,
      "post_rejit_run_time_ns_delta": 4562196,
      "program": "trace_filp_clos",
      "program_id": 695,
      "ratio": 1.1848681261444942,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 80.48906285977435,
      "baseline_run_cnt_delta": 4343,
      "baseline_run_time_ns_delta": 349564,
      "post_rejit_avg_ns_per_run": 76.4082147360836,
      "post_rejit_run_cnt_delta": 5551,
      "post_rejit_run_time_ns_delta": 424142,
      "program": "trace_file_upda",
      "program_id": 696,
      "ratio": 0.9492993460390974,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 37.32419986184665,
      "baseline_run_cnt_delta": 4343,
      "baseline_run_time_ns_delta": 162099,
      "post_rejit_avg_ns_per_run": 33.61088092235633,
      "post_rejit_run_cnt_delta": 5551,
      "post_rejit_run_time_ns_delta": 186574,
      "program": "trace_ret_file_",
      "program_id": 697,
      "ratio": 0.900511760379728,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 479.77777777777777,
      "baseline_run_cnt_delta": 27,
      "baseline_run_time_ns_delta": 12954,
      "post_rejit_avg_ns_per_run": 504.2,
      "post_rejit_run_cnt_delta": 30,
      "post_rejit_run_time_ns_delta": 15126,
      "program": "trace_inotify_f",
      "program_id": 700,
      "ratio": 1.050903195924039,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 359.0740740740741,
      "baseline_run_cnt_delta": 27,
      "baseline_run_time_ns_delta": 9695,
      "post_rejit_avg_ns_per_run": 482.2,
      "post_rejit_run_cnt_delta": 30,
      "post_rejit_run_time_ns_delta": 14466,
      "program": "trace_ret_inoti",
      "program_id": 701,
      "ratio": 1.3428984012377514,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 151.9056603773585,
      "baseline_run_cnt_delta": 53,
      "baseline_run_time_ns_delta": 8051,
      "post_rejit_avg_ns_per_run": 369.40909090909093,
      "post_rejit_run_cnt_delta": 44,
      "post_rejit_run_time_ns_delta": 16254,
      "program": "trace_exec_binp",
      "program_id": 703,
      "ratio": 2.431832296383284,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4299.943396226415,
      "baseline_run_cnt_delta": 53,
      "baseline_run_time_ns_delta": 227897,
      "post_rejit_avg_ns_per_run": 4752.068181818182,
      "post_rejit_run_cnt_delta": 44,
      "post_rejit_run_time_ns_delta": 209091,
      "program": "trace_security_",
      "program_id": 704,
      "ratio": 1.105146683090886,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3227.4,
      "baseline_run_cnt_delta": 80,
      "baseline_run_time_ns_delta": 258192,
      "post_rejit_avg_ns_per_run": 3366.7837837837837,
      "post_rejit_run_cnt_delta": 74,
      "post_rejit_run_time_ns_delta": 249142,
      "program": "trace_execute_f",
      "program_id": 705,
      "ratio": 1.0431876382796628,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2953.074074074074,
      "baseline_run_cnt_delta": 27,
      "baseline_run_time_ns_delta": 79733,
      "post_rejit_avg_ns_per_run": 2977.5,
      "post_rejit_run_cnt_delta": 30,
      "post_rejit_run_time_ns_delta": 89325,
      "program": "trace_security_",
      "program_id": 706,
      "ratio": 1.0082713556494802,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2744.153846153846,
      "baseline_run_cnt_delta": 13,
      "baseline_run_time_ns_delta": 35674,
      "post_rejit_avg_ns_per_run": 2620.6923076923076,
      "post_rejit_run_cnt_delta": 13,
      "post_rejit_run_time_ns_delta": 34069,
      "program": "trace_set_fs_pw",
      "program_id": 707,
      "ratio": 0.95500925043449,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1093.0,
      "baseline_run_cnt_delta": 26,
      "baseline_run_time_ns_delta": 28418,
      "post_rejit_avg_ns_per_run": 1528.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 3056,
      "program": "trace_security_",
      "program_id": 708,
      "ratio": 1.3979871912168345,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2751.8518518518517,
      "baseline_run_cnt_delta": 27,
      "baseline_run_time_ns_delta": 74300,
      "post_rejit_avg_ns_per_run": 2793.6,
      "post_rejit_run_cnt_delta": 30,
      "post_rejit_run_time_ns_delta": 83808,
      "program": "trace_chmod_com",
      "program_id": 710,
      "ratio": 1.0151709286675639,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1147.2857142857142,
      "baseline_run_cnt_delta": 14,
      "baseline_run_time_ns_delta": 16062,
      "post_rejit_avg_ns_per_run": 1272.5714285714287,
      "post_rejit_run_cnt_delta": 14,
      "post_rejit_run_time_ns_delta": 17816,
      "program": "trace_security_task_prctl",
      "program_id": 711,
      "ratio": 1.1092018428589219,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 343.31779661016947,
      "baseline_run_cnt_delta": 236,
      "baseline_run_time_ns_delta": 81023,
      "post_rejit_avg_ns_per_run": 346.5515695067265,
      "post_rejit_run_cnt_delta": 223,
      "post_rejit_run_time_ns_delta": 77281,
      "program": "trace_sock_allo",
      "program_id": 714,
      "ratio": 1.0094191822517984,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1152.9364406779662,
      "baseline_run_cnt_delta": 236,
      "baseline_run_time_ns_delta": 272093,
      "post_rejit_avg_ns_per_run": 1374.286995515695,
      "post_rejit_run_cnt_delta": 223,
      "post_rejit_run_time_ns_delta": 306466,
      "program": "trace_ret_sock_",
      "program_id": 715,
      "ratio": 1.191988514742033,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1676.7407407407406,
      "baseline_run_cnt_delta": 27,
      "baseline_run_time_ns_delta": 45272,
      "post_rejit_avg_ns_per_run": 1592.7666666666667,
      "post_rejit_run_cnt_delta": 30,
      "post_rejit_run_time_ns_delta": 47783,
      "program": "trace_security_",
      "program_id": 716,
      "ratio": 0.9499182717794664,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 79.98692810457516,
      "baseline_run_cnt_delta": 459,
      "baseline_run_time_ns_delta": 36714,
      "post_rejit_avg_ns_per_run": 145.02479338842974,
      "post_rejit_run_cnt_delta": 242,
      "post_rejit_run_time_ns_delta": 35096,
      "program": "trace_security_",
      "program_id": 717,
      "ratio": 1.8131061765345442,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 191.41484716157206,
      "baseline_run_cnt_delta": 229,
      "baseline_run_time_ns_delta": 43834,
      "post_rejit_avg_ns_per_run": 303.19,
      "post_rejit_run_cnt_delta": 100,
      "post_rejit_run_time_ns_delta": 30319,
      "program": "trace_security_",
      "program_id": 718,
      "ratio": 1.5839419172331979,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 669.0184331797235,
      "baseline_run_cnt_delta": 651,
      "baseline_run_time_ns_delta": 435531,
      "post_rejit_avg_ns_per_run": 1060.4581497797358,
      "post_rejit_run_cnt_delta": 454,
      "post_rejit_run_time_ns_delta": 481448,
      "program": "cgroup_bpf_run_",
      "program_id": 719,
      "ratio": 1.585095562673169,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1410.2515337423313,
      "baseline_run_cnt_delta": 163,
      "baseline_run_time_ns_delta": 229871,
      "post_rejit_avg_ns_per_run": 1365.5055555555555,
      "post_rejit_run_cnt_delta": 180,
      "post_rejit_run_time_ns_delta": 245791,
      "program": "cgroup_skb_ingr",
      "program_id": 721,
      "ratio": 0.9682709239336652,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1818.8597560975609,
      "baseline_run_cnt_delta": 164,
      "baseline_run_time_ns_delta": 298293,
      "post_rejit_avg_ns_per_run": 1852.3166666666666,
      "post_rejit_run_cnt_delta": 180,
      "post_rejit_run_time_ns_delta": 333417,
      "program": "cgroup_skb_egre",
      "program_id": 722,
      "ratio": 1.018394442153632,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2548.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 2548,
      "post_rejit_avg_ns_per_run": 2540.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 2540,
      "program": "cgroup_mkdir_si",
      "program_id": 723,
      "ratio": 0.9968602825745683,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1713.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1713,
      "post_rejit_avg_ns_per_run": 1893.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1893,
      "program": "cgroup_rmdir_si",
      "program_id": 724,
      "ratio": 1.1050788091068302,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 133.28301886792454,
      "baseline_run_cnt_delta": 53,
      "baseline_run_time_ns_delta": 7064,
      "post_rejit_avg_ns_per_run": 50.61363636363637,
      "post_rejit_run_cnt_delta": 44,
      "post_rejit_run_time_ns_delta": 2227,
      "program": "empty_kprobe",
      "program_id": 725,
      "ratio": 0.3797455729434778,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 943.0377358490566,
      "baseline_run_cnt_delta": 53,
      "baseline_run_time_ns_delta": 49981,
      "post_rejit_avg_ns_per_run": 1144.5454545454545,
      "post_rejit_run_cnt_delta": 44,
      "post_rejit_run_time_ns_delta": 50360,
      "program": "tracepoint__exe",
      "program_id": 726,
      "ratio": 1.2136793799825751,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 397.64023250986094,
      "baseline_run_cnt_delta": 9634,
      "baseline_run_time_ns_delta": 3830866,
      "post_rejit_avg_ns_per_run": 415.29706158593854,
      "post_rejit_run_cnt_delta": 7453,
      "post_rejit_run_time_ns_delta": 3095209,
      "program": "lsm_file_open_t",
      "program_id": 727,
      "ratio": 1.0444040306601514,
      "runner": "tracee",
      "type": "lsm",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "bpftrace/capable",
      "baseline_avg_ns_per_run": 116.5911920333914,
      "baseline_run_cnt_delta": 152135,
      "baseline_run_time_ns_delta": 17737601,
      "post_rejit_avg_ns_per_run": 115.28357488233742,
      "post_rejit_run_cnt_delta": 155317,
      "post_rejit_run_time_ns_delta": 17905499,
      "program": "cap_capable",
      "program_id": 734,
      "ratio": 0.988784597461878,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 173.62241949037065,
      "baseline_run_cnt_delta": 352256,
      "baseline_run_time_ns_delta": 61159539,
      "post_rejit_avg_ns_per_run": 155.6214968659157,
      "post_rejit_run_cnt_delta": 352256,
      "post_rejit_run_time_ns_delta": 54818606,
      "program": "block_io_start",
      "program_id": 740,
      "ratio": 0.8963214389173209,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 327.4065083348474,
      "baseline_run_cnt_delta": 352256,
      "baseline_run_time_ns_delta": 115330907,
      "post_rejit_avg_ns_per_run": 285.64494288244913,
      "post_rejit_run_cnt_delta": 352256,
      "post_rejit_run_time_ns_delta": 100620145,
      "program": "block_io_done",
      "program_id": 741,
      "ratio": 0.8724473570644857,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 1390.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1390,
      "post_rejit_avg_ns_per_run": 1437.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1437,
      "program": "1",
      "program_id": 747,
      "ratio": 1.0338129496402877,
      "runner": "bpftrace",
      "type": "perf_event",
      "workload": "vfs_create_write_fsync"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 47.22568109820486,
      "baseline_run_cnt_delta": 23675,
      "baseline_run_time_ns_delta": 1118068,
      "post_rejit_avg_ns_per_run": 48.77198358413133,
      "post_rejit_run_cnt_delta": 18275,
      "post_rejit_run_time_ns_delta": 891308,
      "program": "vfs_create",
      "program_id": 748,
      "ratio": 1.0327428308066318,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "vfs_create_write_fsync"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 99.55992122672173,
      "baseline_run_cnt_delta": 52302,
      "baseline_run_time_ns_delta": 5207183,
      "post_rejit_avg_ns_per_run": 100.8203137963458,
      "post_rejit_run_cnt_delta": 54239,
      "post_rejit_run_time_ns_delta": 5468393,
      "program": "sched_wakeup",
      "program_id": 754,
      "ratio": 1.0126596380761879,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 236.3150875243123,
      "baseline_run_cnt_delta": 3599,
      "baseline_run_time_ns_delta": 850498,
      "post_rejit_avg_ns_per_run": 227.58293970547373,
      "post_rejit_run_cnt_delta": 3599,
      "post_rejit_run_time_ns_delta": 819071,
      "program": "sched_wakeup_ne",
      "program_id": 755,
      "ratio": 0.9630487079334695,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 156.64952059143198,
      "baseline_run_cnt_delta": 92927,
      "baseline_run_time_ns_delta": 14556970,
      "post_rejit_avg_ns_per_run": 152.8259149665161,
      "post_rejit_run_cnt_delta": 96315,
      "post_rejit_run_time_ns_delta": 14719428,
      "program": "sched_switch",
      "program_id": 756,
      "ratio": 0.9755913352911658,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline_avg_ns_per_run": 854.2901069518716,
      "baseline_run_cnt_delta": 748,
      "baseline_run_time_ns_delta": 639009,
      "post_rejit_avg_ns_per_run": 835.7381916329284,
      "post_rejit_run_cnt_delta": 741,
      "post_rejit_run_time_ns_delta": 619282,
      "program": "tcp_set_state",
      "program_id": 763,
      "ratio": 0.9782838228278952,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bpftrace/tcpretrans",
      "baseline_avg_ns_per_run": 6143.388888888889,
      "baseline_run_cnt_delta": 18,
      "baseline_run_time_ns_delta": 110581,
      "post_rejit_avg_ns_per_run": 4671.0,
      "post_rejit_run_cnt_delta": 15,
      "post_rejit_run_time_ns_delta": 70065,
      "program": "tcp_retransmit_",
      "program_id": 769,
      "ratio": 0.7603295321981173,
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
            "avg_ns_per_run": 89.00467334614329,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 145720,
            "run_time_ns_delta": 12969761,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.06630467399998,
            "ops_per_sec": 1091.620461189146,
            "ops_total": 1164.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5393] setting to a 1 secs run per stressor\nstress-ng: info:  [5393] dispatching hogs: 2 exec\nstress-ng: info:  [5393] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5393] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5393]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5393] exec               1164      1.04      2.46      0.83      1120.29         354.04\nstress-ng: info:  [5393] skipped: 0\nstress-ng: info:  [5393] passed: 2: exec (2)\nstress-ng: info:  [5393] failed: 0\nstress-ng: info:  [5393] metrics untrustworthy: 0\nstress-ng: info:  [5393] successful run completed in 1.05 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 83.14723810589008,
            "bytes_jited": 206,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 143054,
            "run_time_ns_delta": 11894545,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0877663459999667,
            "ops_per_sec": 1067.324802122565,
            "ops_total": 1161.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5401] setting to a 1 secs run per stressor\nstress-ng: info:  [5401] dispatching hogs: 2 exec\nstress-ng: info:  [5401] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5401] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5401]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5401] exec               1161      1.04      2.43      0.87      1119.93         352.56\nstress-ng: info:  [5401] skipped: 0\nstress-ng: info:  [5401] passed: 2: exec (2)\nstress-ng: info:  [5401] failed: 0\nstress-ng: info:  [5401] metrics untrustworthy: 0\nstress-ng: info:  [5401] successful run completed in 1.05 secs"
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
            "avg_ns_per_run": 1897.0237087214225,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 1181,
            "run_time_ns_delta": 2240385,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 1451.0364485981308,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 1070,
            "run_time_ns_delta": 1552609,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0696874270000194,
            "ops_per_sec": 1101.2562831590417,
            "ops_total": 1178.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [8940] setting to a 1 secs run per stressor\nstress-ng: info:  [8940] dispatching hogs: 2 exec\nstress-ng: info:  [8940] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8940] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8940]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8940] exec               1178      1.03      2.42      0.91      1141.57         353.77\nstress-ng: info:  [8940] skipped: 0\nstress-ng: info:  [8940] passed: 2: exec (2)\nstress-ng: info:  [8940] failed: 0\nstress-ng: info:  [8940] metrics untrustworthy: 0\nstress-ng: info:  [8940] successful run completed in 1.04 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 1742.387858347386,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 1186,
            "run_time_ns_delta": 2066472,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 1376.516010978957,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_exec",
            "run_cnt_delta": 1093,
            "run_time_ns_delta": 1504532,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.067450603999987,
            "ops_per_sec": 1108.2480028275056,
            "ops_total": 1183.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [7153] setting to a 1 secs run per stressor\nstress-ng: info:  [7153] dispatching hogs: 2 exec\nstress-ng: info:  [7153] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7153] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7153]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7153] exec               1183      1.03      2.45      0.89      1145.62         354.52\nstress-ng: info:  [7153] skipped: 0\nstress-ng: info:  [7153] passed: 2: exec (2)\nstress-ng: info:  [7153] failed: 0\nstress-ng: info:  [7153] metrics untrustworthy: 0\nstress-ng: info:  [7153] successful run completed in 1.04 secs"
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
            "avg_ns_per_run": 56.084757630732994,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 31419,
            "run_time_ns_delta": 1762127,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 665.4666454487588,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 15710,
            "run_time_ns_delta": 10454481,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": 650.4783881851168,
            "bytes_jited": 742,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_return",
            "run_cnt_delta": 15709,
            "run_time_ns_delta": 10218365,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0000146220000374,
            "ops_per_sec": 31418.5405980982,
            "ops_total": 31419.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 55.68098368789927,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 32246,
            "run_time_ns_delta": 1795489,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 634.3846058425851,
            "bytes_jited": 719,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_re",
            "run_cnt_delta": 16123,
            "run_time_ns_delta": 10228183,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": 636.9348756434906,
            "bytes_jited": 740,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_re",
            "run_cnt_delta": 16123,
            "run_time_ns_delta": 10269301,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0000134650000518,
            "ops_per_sec": 32245.56581345465,
            "ops_total": 32246.0,
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
            "avg_ns_per_run": 139.34639892578124,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 327680,
            "run_time_ns_delta": 45661028,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 162.21393737792968,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 327680,
            "run_time_ns_delta": 53154263,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 361.96965942382815,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 327680,
            "run_time_ns_delta": 118610218,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.003955238999993,
            "ops_per_sec": 65484.19886855037,
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
            "avg_ns_per_run": 136.97427245274903,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start",
            "run_cnt_delta": 344067,
            "run_time_ns_delta": 47128327,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 158.3531326565311,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 344069,
            "run_time_ns_delta": 54484404,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 372.17294155259106,
            "bytes_jited": 548,
            "bytes_xlated": 848,
            "id": 20,
            "name": "trace_req_compl",
            "run_cnt_delta": 344070,
            "run_time_ns_delta": 128053544,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.114536592000036,
            "ops_per_sec": 67271.783828504,
            "ops_total": 344064.0,
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
        "output_chars": 13069,
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
            "avg_ns_per_run": 31.5,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 126,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 28.05263157894737,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 551,
            "run_time_ns_delta": 15457,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 24.672663668165917,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 8004,
            "run_time_ns_delta": 197480,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 23.840621888642108,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 13057,
            "run_time_ns_delta": 311287,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0103778850000253,
            "ops_per_sec": 81.15775416046239,
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
            "avg_ns_per_run": 40.20566037735849,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 530,
            "run_time_ns_delta": 21309,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 28.432621568275614,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 5573,
            "run_time_ns_delta": 158455,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 27.018647439085033,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 12066,
            "run_time_ns_delta": 326007,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0000790349999988,
            "ops_per_sec": 107.99146489457219,
            "ops_total": 108.0,
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
            "avg_ns_per_run": 3831.4879288437105,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 1574,
            "run_time_ns_delta": 6030762,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 1320.0349514563106,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 515,
            "run_time_ns_delta": 679818,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0002552430000264,
            "ops_per_sec": 514.8685833981541,
            "ops_total": 515.0,
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
            "avg_ns_per_run": 1256.2663578459758,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 1727,
            "run_time_ns_delta": 2169572,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 1235.1873963515754,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 603,
            "run_time_ns_delta": 744818,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0007059870000603,
            "ops_per_sec": 602.5745901727713,
            "ops_total": 603.0,
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
        "output_chars": 11096,
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
            "avg_ns_per_run": 61.96753125389376,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 963080,
            "run_time_ns_delta": 59679690,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 60.82930552022386,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 963095,
            "run_time_ns_delta": 58584400,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0005424739999853,
            "ops_per_sec": 972.4724589753041,
            "ops_total": 973.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 65.21142432205497,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 937281,
            "run_time_ns_delta": 61121429,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 61.61694919234411,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 936847,
            "run_time_ns_delta": 57725654,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0002577479999673,
            "ops_per_sec": 937.7582946750948,
            "ops_total": 938.0,
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
        "output_chars": 9097,
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
            "avg_ns_per_run": 649.917808219178,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 73,
            "run_time_ns_delta": 47444,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4594.2972972972975,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 37,
            "run_time_ns_delta": 169989,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 4548.833333333333,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 36,
            "run_time_ns_delta": 163758,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0058642370000257,
            "ops_per_sec": 72.57440648026353,
            "ops_total": 73.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 629.275,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_e",
            "run_cnt_delta": 80,
            "run_time_ns_delta": 50342,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4412.55,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v",
            "run_cnt_delta": 40,
            "run_time_ns_delta": 176502,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 4324.575,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v",
            "run_cnt_delta": 40,
            "run_time_ns_delta": 172983,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0121802209999942,
            "ops_per_sec": 79.03730811985552,
            "ops_total": 80.0,
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
            "avg_ns_per_run": 693.578811369509,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 774,
            "run_time_ns_delta": 536830,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0161077939999927,
            "ops_per_sec": 69.8744763294282,
            "ops_total": 71.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "44": {
            "avg_ns_per_run": 720.283065512979,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "sock__inet_sock",
            "run_cnt_delta": 809,
            "run_time_ns_delta": 582709,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0020166929999732,
            "ops_per_sec": 73.85106507402465,
            "ops_total": 74.0,
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
        "output_chars": 4884,
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
            "avg_ns_per_run": 178.20798269088425,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 87815,
            "run_time_ns_delta": 15649334,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 113.67774220724516,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 59350,
            "run_time_ns_delta": 6746774,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 241.01847799659615,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 4113,
            "run_time_ns_delta": 991309,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.005866162000018,
            "ops_per_sec": 15.906688786693387,
            "ops_total": 16.0,
            "stderr": "",
            "stdout": "Time: 0.034\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.038\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.034\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.041\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.041\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.041\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.038"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 170.01052509979593,
            "bytes_jited": 645,
            "bytes_xlated": 1136,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 77909,
            "run_time_ns_delta": 13245350,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 113.96891311465937,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 51919,
            "run_time_ns_delta": 5917152,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 244.71853292581272,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 3599,
            "run_time_ns_delta": 880742,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0900173810000524,
            "ops_per_sec": 12.84383189115342,
            "ops_total": 14.0,
            "stderr": "",
            "stdout": "Time: 0.049\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.051\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.034\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.050\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.041\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.056\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.063\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.059"
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
            "duration_s": 1.0253299469999888,
            "ops_per_sec": 750.9777728163912,
            "ops_total": 770.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     9.77ms   18.10ms 211.94ms   96.74%\n    Req/Sec   385.15    289.85     0.95k    80.00%\n  770 requests in 1.01s, 116.55KB read\nRequests/sec:    762.84\nTransfer/sec:    115.47KB"
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
            "duration_s": 1.0126417620000439,
            "ops_per_sec": 949.002930811339,
            "ops_total": 961.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     5.99ms    4.61ms  33.52ms   82.03%\n    Req/Sec   482.15    336.18     0.90k    55.00%\n  961 requests in 1.00s, 145.46KB read\nRequests/sec:    958.25\nTransfer/sec:    145.05KB"
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
        "output_chars": 25753,
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
            "avg_ns_per_run": 4898.4,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 131,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 5,
            "run_time_ns_delta": 24492,
            "type": "tracepoint"
          },
          "132": {
            "avg_ns_per_run": 16236.352272727272,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 132,
            "name": "native_tracer_entry",
            "run_cnt_delta": 88,
            "run_time_ns_delta": 1428799,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0294280200000117,
            "ops_per_sec": 1.942826463961975,
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
            "avg_ns_per_run": 3257.0,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 131,
            "name": "tracepoint__sch",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 13028,
            "type": "tracepoint"
          },
          "132": {
            "avg_ns_per_run": 15377.231707317073,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 132,
            "name": "native_tracer_e",
            "run_cnt_delta": 82,
            "run_time_ns_delta": 1260933,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0299406389999604,
            "ops_per_sec": 1.9418594861369258,
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
        "output_chars": 348004,
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
      "error": "failed to read BPF stats for requested program ids: 213, 218, 221, 225, 226, 227, 232, 233, 236",
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
          "251": {
            "avg_ns_per_run": 564.7289107289107,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 251,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1221,
            "run_time_ns_delta": 689534,
            "type": "kprobe"
          },
          "253": {
            "avg_ns_per_run": 693.0899155489319,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 253,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 2013,
            "run_time_ns_delta": 1395190,
            "type": "kprobe"
          },
          "254": {
            "avg_ns_per_run": 2833.4699286442406,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 254,
            "name": "event_execve",
            "run_cnt_delta": 981,
            "run_time_ns_delta": 2779634,
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
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 256,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "257": {
            "avg_ns_per_run": 268.9388379204893,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 257,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 981,
            "run_time_ns_delta": 263829,
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 261,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 262,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 263,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "264": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 264,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "265": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 265,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 266,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 268,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 269,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 270,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 271,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 272,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 273,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "274": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 274,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "275": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 275,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 277,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 278,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 280,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 281,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "282": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 282,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 283,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 284,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 286,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": 1059.2561505065123,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 287,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 691,
            "run_time_ns_delta": 731946,
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 289,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 290,
            "name": "generic_retkprobe_actions",
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
            "avg_ns_per_run": 746.6801736613603,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 292,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 691,
            "run_time_ns_delta": 515956,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": 864.9429569266589,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 293,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 859,
            "run_time_ns_delta": 742986,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 295,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 296,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 298,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 300,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": 676.6647990255785,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 302,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4105,
            "run_time_ns_delta": 2777709,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 304,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 306,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 307,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "308": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 308,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "309": {
            "avg_ns_per_run": 1075.0390738060782,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 309,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 691,
            "run_time_ns_delta": 742852,
            "type": "kprobe"
          },
          "310": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 310,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 312,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 313,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": 914.204052098408,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 317,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 691,
            "run_time_ns_delta": 631715,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 318,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": 832.6088474970896,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 320,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 859,
            "run_time_ns_delta": 715211,
            "type": "kprobe"
          },
          "321": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 321,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 323,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "324": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 324,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 325,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "326": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 326,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 717.6789524733268,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 328,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2062,
            "run_time_ns_delta": 1479854,
            "type": "kprobe"
          },
          "329": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 329,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 333,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 335,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 336,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 337,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": 724.8149779735683,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 338,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2043,
            "run_time_ns_delta": 1480797,
            "type": "kprobe"
          },
          "339": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 339,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 341,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "342": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 342,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "343": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 343,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "344": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 344,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "345": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 345,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 350,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "351": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 351,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 352,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 266.0651364617172,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 354,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 42173,
            "run_time_ns_delta": 11220765,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 356,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 360,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "361": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 361,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "362": {
            "avg_ns_per_run": 489.0099170756473,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 362,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 147725,
            "run_time_ns_delta": 72238990,
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
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 367,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "368": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 368,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "369": {
            "avg_ns_per_run": 39.545142764372834,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 369,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 147831,
            "run_time_ns_delta": 5845998,
            "type": "kprobe"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 370,
            "name": "generic_retkprobe_output",
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
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 373,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "374": {
            "avg_ns_per_run": 989.7220777422135,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 374,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 129968,
            "run_time_ns_delta": 128632199,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 376,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "377": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 377,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "378": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 378,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "379": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 379,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 380,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "381": {
            "avg_ns_per_run": 47.665617690508434,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 381,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 129968,
            "run_time_ns_delta": 6195005,
            "type": "kprobe"
          },
          "382": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 382,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 384,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 385,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "386": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 386,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 387,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "388": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 388,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "389": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 389,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 390,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 391,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "392": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 392,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "393": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 393,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "394": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 394,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "395": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 395,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "396": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 396,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 398,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "399": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 399,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 401,
            "name": "generic_retkprobe_event",
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 403,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 404,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "405": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 405,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "406": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 406,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 6430.5,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 410,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 12861,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": 1560.5,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 411,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 3121,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 415,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 416,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": 2859.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 417,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 5718,
            "type": "kprobe"
          },
          "418": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 418,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "419": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 419,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 421,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "422": {
            "avg_ns_per_run": 4051.5,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 422,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8103,
            "type": "kprobe"
          },
          "423": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 423,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 427,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "428": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 428,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 431,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 433,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": 1440.902140672783,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 435,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 981,
            "run_time_ns_delta": 1413525,
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
            "avg_ns_per_run": 433.0221243011158,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 438,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 912526,
            "run_time_ns_delta": 395143947,
            "type": "tracepoint"
          },
          "439": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 439,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "440": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 440,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "441": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 441,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "442": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 442,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "443": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 443,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "444": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 444,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "445": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 445,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "446": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 446,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "447": {
            "avg_ns_per_run": null,
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 447,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "448": {
            "avg_ns_per_run": 1497.1467889908256,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 448,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 981,
            "run_time_ns_delta": 1468701,
            "type": "raw_tracepoint"
          },
          "449": {
            "avg_ns_per_run": 2024.1525423728813,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 449,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 177,
            "run_time_ns_delta": 358275,
            "type": "kprobe"
          },
          "450": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 450,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 454,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 457,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "458": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 458,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 460,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "461": {
            "avg_ns_per_run": 2643.3643815482023,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 461,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 53068,
            "run_time_ns_delta": 140278061,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 463,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "464": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 464,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 467,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "468": {
            "avg_ns_per_run": 5173.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 468,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 5173,
            "type": "kprobe"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 469,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": 1095.3617945007236,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 472,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 691,
            "run_time_ns_delta": 756895,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 474,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "475": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 475,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "476": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 476,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "477": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 477,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "478": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 478,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 834.0057887120116,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 480,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 691,
            "run_time_ns_delta": 576298,
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
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 482,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 484,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "485": {
            "avg_ns_per_run": 891.9697322467986,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 485,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 859,
            "run_time_ns_delta": 766202,
            "type": "kprobe"
          },
          "486": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 486,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "487": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 487,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "488": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 488,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "489": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 489,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "490": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 490,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "491": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 491,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "492": {
            "avg_ns_per_run": 614.5833333333334,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 492,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1680,
            "run_time_ns_delta": 1032500,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 494,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "495": {
            "avg_ns_per_run": 1030.4444444444443,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 495,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 504,
            "run_time_ns_delta": 519344,
            "type": "kprobe"
          },
          "496": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 496,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "497": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 497,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 498,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "499": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 499,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 501,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "502": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 502,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "503": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 503,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": 1342.0535714285713,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 505,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 168,
            "run_time_ns_delta": 225465,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 507,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 509,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "510": {
            "avg_ns_per_run": 962.7559523809524,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 510,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 168,
            "run_time_ns_delta": 161743,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 511,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 512,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "513": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 513,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 514,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "515": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 515,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "516": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 516,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 517,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": 2232.6428571428573,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 518,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 168,
            "run_time_ns_delta": 375084,
            "type": "kprobe"
          },
          "519": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 519,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 520,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 521,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 522,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 523,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 525,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "526": {
            "avg_ns_per_run": 1206.6329365079366,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 526,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 504,
            "run_time_ns_delta": 608143,
            "type": "kprobe"
          },
          "527": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 527,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 529,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "530": {
            "avg_ns_per_run": 1652.8372781065088,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 530,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 338,
            "run_time_ns_delta": 558659,
            "type": "kprobe"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 531,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "532": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 532,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 533,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 537,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 540,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.6319701799999962,
            "ops_per_sec": 845.6036862144156,
            "ops_total": 1380.0,
            "stderr": "ipv6_udp_loopback_unavailable=[Errno 22] Invalid argument\ntetragon_fs_event_mix unavailable: [Errno 22] Invalid argument\nmodule_load_candidate=vcan",
            "stdout": "stress-ng: info:  [24146] setting to a 1 secs run per stressor\nstress-ng: info:  [24146] dispatching hogs: 2 exec\nstress-ng: info:  [24146] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24146] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24146]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24146] exec               1211      1.02      2.60      0.82      1186.16         354.60\nstress-ng: info:  [24146] skipped: 0\nstress-ng: info:  [24146] passed: 2: exec (2)\nstress-ng: info:  [24146] failed: 0\nstress-ng: info:  [24146] metrics untrustworthy: 0\nstress-ng: info:  [24146] successful run completed in 1.03 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "251": {
            "avg_ns_per_run": 535.5484133441822,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 251,
            "name": "event_exit_acct",
            "run_cnt_delta": 1229,
            "run_time_ns_delta": 658189,
            "type": "kprobe"
          },
          "253": {
            "avg_ns_per_run": 749.0855365474339,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 253,
            "name": "event_wake_up_n",
            "run_cnt_delta": 1929,
            "run_time_ns_delta": 1444986,
            "type": "kprobe"
          },
          "254": {
            "avg_ns_per_run": 2919.9851222104144,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 254,
            "name": "event_execve",
            "run_cnt_delta": 941,
            "run_time_ns_delta": 2747706,
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
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 256,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "257": {
            "avg_ns_per_run": 285.70988310308184,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 257,
            "name": "tg_kp_bprm_comm",
            "run_cnt_delta": 941,
            "run_time_ns_delta": 268853,
            "type": "kprobe"
          },
          "258": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 258,
            "name": "execve_map_upda",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "261": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 261,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 262,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 263,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "264": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 264,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "265": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 265,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 266,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 268,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 269,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 270,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 271,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 272,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 273,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "274": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 274,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "275": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 275,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 276,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "277": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 277,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 278,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 280,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 281,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "282": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 282,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 283,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 284,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 286,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": 1467.5328185328185,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 287,
            "name": "generic_kprobe_",
            "run_cnt_delta": 259,
            "run_time_ns_delta": 380091,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 288,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 289,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 290,
            "name": "generic_retkprobe_actions",
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
            "avg_ns_per_run": 942.8030888030888,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 292,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 259,
            "run_time_ns_delta": 244186,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": 1069.2018927444794,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 293,
            "name": "generic_kprobe_",
            "run_cnt_delta": 317,
            "run_time_ns_delta": 338937,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 295,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 296,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "297": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 297,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 298,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 300,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": 820.3836177474403,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 302,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1465,
            "run_time_ns_delta": 1201862,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 304,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 306,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 307,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "308": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 308,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "309": {
            "avg_ns_per_run": 1463.3436293436293,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 309,
            "name": "generic_kprobe_",
            "run_cnt_delta": 259,
            "run_time_ns_delta": 379006,
            "type": "kprobe"
          },
          "310": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 310,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 312,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 313,
            "name": "generic_kprobe_actions",
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
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": 1194.6216216216217,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 317,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 259,
            "run_time_ns_delta": 309407,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 318,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": 1126.9463722397477,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 320,
            "name": "generic_kprobe_",
            "run_cnt_delta": 317,
            "run_time_ns_delta": 357242,
            "type": "kprobe"
          },
          "321": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 321,
            "name": "generic_kprobe_",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 323,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "324": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 324,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 325,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "326": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 326,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 931.7577807848444,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 328,
            "name": "generic_kprobe_",
            "run_cnt_delta": 739,
            "run_time_ns_delta": 688569,
            "type": "kprobe"
          },
          "329": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 329,
            "name": "generic_kprobe_filter_arg",
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
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "332": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 332,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "333": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 333,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 335,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 336,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 337,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": 935.0068965517241,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 338,
            "name": "generic_kprobe_",
            "run_cnt_delta": 725,
            "run_time_ns_delta": 677880,
            "type": "kprobe"
          },
          "339": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 339,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 341,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "342": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 342,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "343": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 343,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "344": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 344,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "345": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 345,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": 7685.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 350,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 7685,
            "type": "kprobe"
          },
          "351": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 351,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 352,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 277.76609155625863,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 354,
            "name": "generic_kprobe_",
            "run_cnt_delta": 40456,
            "run_time_ns_delta": 11237305,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 356,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "357": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 357,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 359,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 360,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "361": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 361,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "362": {
            "avg_ns_per_run": 477.7461712743435,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 362,
            "name": "generic_kprobe_",
            "run_cnt_delta": 161542,
            "run_time_ns_delta": 77176072,
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
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "366": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 366,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "367": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 367,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "368": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 368,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "369": {
            "avg_ns_per_run": 38.31192320292749,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 369,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 161777,
            "run_time_ns_delta": 6197988,
            "type": "kprobe"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 370,
            "name": "generic_retkpro",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 372,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "373": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 373,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "374": {
            "avg_ns_per_run": 987.3803118705007,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 374,
            "name": "generic_kprobe_",
            "run_cnt_delta": 124603,
            "run_time_ns_delta": 123030549,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 376,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "377": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 377,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "378": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 378,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "379": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 379,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 380,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "381": {
            "avg_ns_per_run": 48.61637360256174,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 381,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 124603,
            "run_time_ns_delta": 6057746,
            "type": "kprobe"
          },
          "382": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 382,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 384,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 385,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "386": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 386,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 387,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "388": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 388,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "389": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 389,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 390,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 391,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "392": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 392,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "393": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 393,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "394": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 394,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "395": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 395,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "396": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 396,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 398,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "399": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 399,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 401,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "402": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 402,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "403": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 403,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 404,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "405": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 405,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "406": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 406,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": 5849.5,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 410,
            "name": "generic_kprobe_",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 11699,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": 1624.0,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 411,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 3248,
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
            "name": "generic_retkpro",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 415,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 416,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": 3369.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 417,
            "name": "generic_kprobe_",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 6738,
            "type": "kprobe"
          },
          "418": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 418,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "419": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 419,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "420": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
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
            "avg_ns_per_run": 4934.5,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 422,
            "name": "generic_kprobe_",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 9869,
            "type": "kprobe"
          },
          "423": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 423,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "424": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 424,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 425,
            "name": "generic_kprobe_",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 427,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "428": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 428,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 430,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 431,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 433,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": 1596.2327311370882,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 435,
            "name": "generic_kprobe_",
            "run_cnt_delta": 941,
            "run_time_ns_delta": 1502055,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 436,
            "name": "generic_tracepo",
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
            "avg_ns_per_run": 416.817121942728,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 438,
            "name": "generic_tracepo",
            "run_cnt_delta": 901907,
            "run_time_ns_delta": 375930280,
            "type": "tracepoint"
          },
          "439": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 439,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "440": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 440,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "441": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 441,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "442": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 442,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "443": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 443,
            "name": "generic_rawtp_o",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "444": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 444,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "445": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 445,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "446": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 446,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "447": {
            "avg_ns_per_run": null,
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 447,
            "name": "generic_rawtp_s",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "448": {
            "avg_ns_per_run": 1530.0648246546227,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 448,
            "name": "generic_rawtp_e",
            "run_cnt_delta": 941,
            "run_time_ns_delta": 1439791,
            "type": "raw_tracepoint"
          },
          "449": {
            "avg_ns_per_run": 3349.4057971014495,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 449,
            "name": "generic_kprobe_",
            "run_cnt_delta": 69,
            "run_time_ns_delta": 231109,
            "type": "kprobe"
          },
          "450": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 450,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "451": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 451,
            "name": "generic_kprobe_",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 454,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "455": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 455,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 457,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "458": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 458,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "459": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 459,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": 2650.6689186542903,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 461,
            "name": "generic_kprobe_",
            "run_cnt_delta": 51066,
            "run_time_ns_delta": 135359059,
            "type": "kprobe"
          },
          "462": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 462,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 463,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "464": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 464,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "465": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 465,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "466": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 466,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": 4729.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 468,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 4729,
            "type": "kprobe"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 469,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": 1564.4324324324325,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 472,
            "name": "generic_kprobe_",
            "run_cnt_delta": 259,
            "run_time_ns_delta": 405188,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 474,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "475": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 475,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "476": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 476,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "477": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 477,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "478": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 478,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "479": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 479,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "480": {
            "avg_ns_per_run": 1102.3822393822393,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 480,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 259,
            "run_time_ns_delta": 285517,
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
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 482,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 484,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "485": {
            "avg_ns_per_run": 1151.006309148265,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 485,
            "name": "generic_kprobe_",
            "run_cnt_delta": 317,
            "run_time_ns_delta": 364869,
            "type": "kprobe"
          },
          "486": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 486,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "487": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 487,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "488": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 488,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "489": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 489,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "490": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 490,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "491": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 491,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "492": {
            "avg_ns_per_run": 817.5533333333333,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 492,
            "name": "generic_kprobe_",
            "run_cnt_delta": 600,
            "run_time_ns_delta": 490532,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 494,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "495": {
            "avg_ns_per_run": 1602.138888888889,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 495,
            "name": "generic_kprobe_",
            "run_cnt_delta": 180,
            "run_time_ns_delta": 288385,
            "type": "kprobe"
          },
          "496": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 496,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "497": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 497,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 498,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "499": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 499,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 501,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "502": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 502,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "503": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 503,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": 2160.5833333333335,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 505,
            "name": "generic_kprobe_",
            "run_cnt_delta": 60,
            "run_time_ns_delta": 129635,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 507,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 509,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "510": {
            "avg_ns_per_run": 1391.5333333333333,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 510,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 60,
            "run_time_ns_delta": 83492,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 511,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 512,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "513": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 513,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 514,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "515": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 515,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "516": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 516,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 517,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": 3667.5666666666666,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 518,
            "name": "generic_kprobe_",
            "run_cnt_delta": 60,
            "run_time_ns_delta": 220054,
            "type": "kprobe"
          },
          "519": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 519,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 520,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 521,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 522,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 523,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 524,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 525,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "526": {
            "avg_ns_per_run": 1717.588888888889,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 526,
            "name": "generic_kprobe_",
            "run_cnt_delta": 180,
            "run_time_ns_delta": 309166,
            "type": "kprobe"
          },
          "527": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 527,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 528,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "529": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 529,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "530": {
            "avg_ns_per_run": 2534.2916666666665,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 530,
            "name": "generic_kprobe_",
            "run_cnt_delta": 120,
            "run_time_ns_delta": 304115,
            "type": "kprobe"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 531,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "532": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 532,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 533,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 536,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "537": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 537,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 540,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.6289781740000535,
            "ops_per_sec": 785.7686618703327,
            "ops_total": 1280.0,
            "stderr": "ipv6_udp_loopback_unavailable=[Errno 22] Invalid argument\ntetragon_fs_event_mix unavailable: [Errno 22] Invalid argument\nmodule_load_candidate=vcan",
            "stdout": "stress-ng: info:  [13942] setting to a 1 secs run per stressor\nstress-ng: info:  [13942] dispatching hogs: 2 exec\nstress-ng: info:  [13942] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13942] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13942]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13942] exec               1219      1.03      2.45      0.88      1187.69         365.46\nstress-ng: info:  [13942] skipped: 0\nstress-ng: info:  [13942] passed: 2: exec (2)\nstress-ng: info:  [13942] failed: 0\nstress-ng: info:  [13942] metrics untrustworthy: 0\nstress-ng: info:  [13942] successful run completed in 1.05 secs"
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
        "output_chars": 3618266,
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
            "avg_ns_per_run": 52.82421875,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 553,
            "name": "balancer_ingress",
            "run_cnt_delta": 1024,
            "run_time_ns_delta": 54092,
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
            "duration_s": 1.0205493509999997,
            "ops_per_sec": 1003.3811681881127,
            "ops_total": 1024.0,
            "stderr": "{'retval': 2, 'duration_ns': 72, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
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
            "avg_ns_per_run": 50.947265625,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 553,
            "name": "balancer_ingress",
            "run_cnt_delta": 1024,
            "run_time_ns_delta": 52170,
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
            "duration_s": 1.01173686300001,
            "ops_per_sec": 1012.1208759396461,
            "ops_total": 1024.0,
            "stderr": "{'retval': 2, 'duration_ns': 68, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
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
        "output_chars": 89602,
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
            "avg_ns_per_run": 146.22018926277013,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 570,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 3079528,
            "run_time_ns_delta": 450289167,
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
            "avg_ns_per_run": 357.9611721345326,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 573,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 3080056,
            "run_time_ns_delta": 1102540456,
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
            "avg_ns_per_run": 339.39799052225,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 576,
            "name": "trace_sys_enter",
            "run_cnt_delta": 3080900,
            "run_time_ns_delta": 1045651269,
            "type": "raw_tracepoint"
          },
          "577": {
            "avg_ns_per_run": 304.255946311025,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 577,
            "name": "trace_sys_exit",
            "run_cnt_delta": 3081154,
            "run_time_ns_delta": 937459426,
            "type": "raw_tracepoint"
          },
          "578": {
            "avg_ns_per_run": 600.7592592592592,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 578,
            "name": "trace_ptrace",
            "run_cnt_delta": 54,
            "run_time_ns_delta": 32441,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": 1443.351851851852,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 579,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 54,
            "run_time_ns_delta": 77941,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": 350.3703703703704,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 580,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 27,
            "run_time_ns_delta": 9460,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": 1774.2222222222222,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 581,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 27,
            "run_time_ns_delta": 47904,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": 1001.7169811320755,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 582,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 53,
            "run_time_ns_delta": 53091,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": 1641.7358490566037,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 583,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 53,
            "run_time_ns_delta": 87012,
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
            "avg_ns_per_run": 1006.6545454545454,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 586,
            "name": "trace_dup2",
            "run_cnt_delta": 55,
            "run_time_ns_delta": 55366,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 2143.7636363636366,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 587,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 55,
            "run_time_ns_delta": 117907,
            "type": "kprobe"
          },
          "588": {
            "avg_ns_per_run": 238.47222222222223,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 588,
            "name": "trace_dup3",
            "run_cnt_delta": 36,
            "run_time_ns_delta": 8585,
            "type": "kprobe"
          },
          "589": {
            "avg_ns_per_run": 1272.9166666666667,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 589,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 36,
            "run_time_ns_delta": 45825,
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
            "avg_ns_per_run": 4561.14375,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 595,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 160,
            "run_time_ns_delta": 729783,
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
            "avg_ns_per_run": 4759.830188679245,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 603,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 53,
            "run_time_ns_delta": 252271,
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
            "avg_ns_per_run": 1758.95,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 605,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 160,
            "run_time_ns_delta": 281432,
            "type": "raw_tracepoint"
          },
          "606": {
            "avg_ns_per_run": 1461.3875,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 606,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 160,
            "run_time_ns_delta": 233822,
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
            "avg_ns_per_run": 269.37962148794395,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 608,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 291140,
            "run_time_ns_delta": 78427183,
            "type": "raw_tracepoint"
          },
          "609": {
            "avg_ns_per_run": 18.220704453865075,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 609,
            "name": "trace_filldir64",
            "run_cnt_delta": 19107,
            "run_time_ns_delta": 348143,
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
            "avg_ns_per_run": 1363.4,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 611,
            "name": "trace_do_exit",
            "run_cnt_delta": 160,
            "run_time_ns_delta": 218144,
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
            "avg_ns_per_run": 725.2022471910112,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 615,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 178,
            "run_time_ns_delta": 129086,
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
            "avg_ns_per_run": 2800.0,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 617,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2800,
            "type": "raw_tracepoint"
          },
          "618": {
            "avg_ns_per_run": 1750.0,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 618,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1750,
            "type": "raw_tracepoint"
          },
          "619": {
            "avg_ns_per_run": 1549.0,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 619,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1549,
            "type": "raw_tracepoint"
          },
          "620": {
            "avg_ns_per_run": 3174.4716981132074,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 620,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 53,
            "run_time_ns_delta": 168247,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": 716.4887897031348,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 621,
            "name": "trace_security_file_open",
            "run_cnt_delta": 9634,
            "run_time_ns_delta": 6902653,
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
            "avg_ns_per_run": 1818.453125,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 623,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 128,
            "run_time_ns_delta": 232762,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": 915.1217391304348,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 624,
            "name": "trace_commit_creds",
            "run_cnt_delta": 115,
            "run_time_ns_delta": 105239,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": 1330.3875,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 625,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 160,
            "run_time_ns_delta": 212862,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 228.52342871423215,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 626,
            "name": "trace_cap_capable",
            "run_cnt_delta": 24009,
            "run_time_ns_delta": 5486619,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 970.1223021582733,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 627,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 139,
            "run_time_ns_delta": 134847,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": 2791.6666666666665,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 628,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 27,
            "run_time_ns_delta": 75375,
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
            "avg_ns_per_run": 1915.6666666666667,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 632,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 27,
            "run_time_ns_delta": 51723,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": 1650.4444444444443,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 633,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 27,
            "run_time_ns_delta": 44562,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 2272.9897959183672,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 634,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 98,
            "run_time_ns_delta": 222753,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 1099.8703703703704,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 635,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 54,
            "run_time_ns_delta": 59393,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": 1641.1666666666667,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 636,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 36,
            "run_time_ns_delta": 59082,
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
            "avg_ns_per_run": 65.32681741068038,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 639,
            "name": "trace_vfs_write",
            "run_cnt_delta": 39493,
            "run_time_ns_delta": 2579952,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": 41.46342080623529,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 640,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 39517,
            "run_time_ns_delta": 1638510,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": 33.900725902319344,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 641,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 39537,
            "run_time_ns_delta": 1340333,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": 44.826763092017096,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 642,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 39547,
            "run_time_ns_delta": 1772764,
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
            "avg_ns_per_run": 63.00070571630204,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 644,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 2834,
            "run_time_ns_delta": 178544,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": 39.121383203952014,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 645,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 2834,
            "run_time_ns_delta": 110870,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": 44.50352858151023,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 646,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 2834,
            "run_time_ns_delta": 126123,
            "type": "kprobe"
          },
          "647": {
            "avg_ns_per_run": 47.419901199717714,
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 647,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 2834,
            "run_time_ns_delta": 134388,
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
            "avg_ns_per_run": 77.32993762993763,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 654,
            "name": "trace_vfs_read",
            "run_cnt_delta": 19240,
            "run_time_ns_delta": 1487828,
            "type": "kprobe"
          },
          "655": {
            "avg_ns_per_run": 79.36277705345502,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 655,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 3068,
            "run_time_ns_delta": 243485,
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
            "avg_ns_per_run": 75.58574453069866,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 657,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 2834,
            "run_time_ns_delta": 214210,
            "type": "kprobe"
          },
          "658": {
            "avg_ns_per_run": 63.92554693013409,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 658,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 2834,
            "run_time_ns_delta": 181165,
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
            "avg_ns_per_run": 161.63837471783296,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 660,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 2215,
            "run_time_ns_delta": 358029,
            "type": "kprobe"
          },
          "661": {
            "avg_ns_per_run": 99.18092105263158,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 661,
            "name": "trace_do_mmap",
            "run_cnt_delta": 1520,
            "run_time_ns_delta": 150755,
            "type": "kprobe"
          },
          "662": {
            "avg_ns_per_run": 61.688815789473686,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 662,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 1520,
            "run_time_ns_delta": 93767,
            "type": "kprobe"
          },
          "663": {
            "avg_ns_per_run": 850.9690789473684,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 663,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 1520,
            "run_time_ns_delta": 1293473,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 1284.0361010830325,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 664,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 277,
            "run_time_ns_delta": 355678,
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
            "avg_ns_per_run": 378.31150529029964,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 666,
            "name": "trace_security_bpf",
            "run_cnt_delta": 22494,
            "run_time_ns_delta": 8509739,
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
            "avg_ns_per_run": 340.0993798696136,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 669,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 6289,
            "run_time_ns_delta": 2138885,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 1142.5197628458498,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 670,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 506,
            "run_time_ns_delta": 578115,
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
            "avg_ns_per_run": 2439.1666666666665,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 674,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 29270,
            "type": "kprobe"
          },
          "675": {
            "avg_ns_per_run": 2713.5,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 675,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 32562,
            "type": "kprobe"
          },
          "676": {
            "avg_ns_per_run": 2391.703703703704,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 676,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 27,
            "run_time_ns_delta": 64576,
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
            "avg_ns_per_run": 6172.916666666667,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 680,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 74075,
            "type": "raw_tracepoint"
          },
          "681": {
            "avg_ns_per_run": 6438.083333333333,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 681,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 77257,
            "type": "raw_tracepoint"
          },
          "682": {
            "avg_ns_per_run": 522.25,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 682,
            "name": "trace_do_init_module",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 6267,
            "type": "kprobe"
          },
          "683": {
            "avg_ns_per_run": 189.83333333333334,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 683,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 2278,
            "type": "kprobe"
          },
          "684": {
            "avg_ns_per_run": 1602.2924528301887,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 684,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 106,
            "run_time_ns_delta": 169843,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 35.08032277453099,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 685,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 78197,
            "run_time_ns_delta": 2743176,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 1704.4545454545455,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 686,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 55,
            "run_time_ns_delta": 93745,
            "type": "raw_tracepoint"
          },
          "687": {
            "avg_ns_per_run": 2581.740740740741,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 687,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 27,
            "run_time_ns_delta": 69707,
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
            "avg_ns_per_run": 548.9875699192045,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 690,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 1609,
            "run_time_ns_delta": 883321,
            "type": "kprobe"
          },
          "691": {
            "avg_ns_per_run": 2554.4,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 691,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 45,
            "run_time_ns_delta": 114948,
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
            "avg_ns_per_run": 923.1108033240997,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 693,
            "name": "trace_do_truncate",
            "run_cnt_delta": 1444,
            "run_time_ns_delta": 1332972,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 280.7097688292319,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 694,
            "name": "trace_fd_install",
            "run_cnt_delta": 13410,
            "run_time_ns_delta": 3764318,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": 762.452064141931,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 695,
            "name": "trace_filp_close",
            "run_cnt_delta": 5862,
            "run_time_ns_delta": 4469494,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": 80.48906285977435,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 696,
            "name": "trace_file_update_time",
            "run_cnt_delta": 4343,
            "run_time_ns_delta": 349564,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": 37.32419986184665,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 697,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 4343,
            "run_time_ns_delta": 162099,
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
            "avg_ns_per_run": 479.77777777777777,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 700,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 27,
            "run_time_ns_delta": 12954,
            "type": "kprobe"
          },
          "701": {
            "avg_ns_per_run": 359.0740740740741,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 701,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 27,
            "run_time_ns_delta": 9695,
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
            "avg_ns_per_run": 151.9056603773585,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 703,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 53,
            "run_time_ns_delta": 8051,
            "type": "kprobe"
          },
          "704": {
            "avg_ns_per_run": 4299.943396226415,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 704,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 53,
            "run_time_ns_delta": 227897,
            "type": "kprobe"
          },
          "705": {
            "avg_ns_per_run": 3227.4,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 705,
            "name": "trace_execute_finished",
            "run_cnt_delta": 80,
            "run_time_ns_delta": 258192,
            "type": "kprobe"
          },
          "706": {
            "avg_ns_per_run": 2953.074074074074,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 706,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 27,
            "run_time_ns_delta": 79733,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": 2744.153846153846,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 707,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 13,
            "run_time_ns_delta": 35674,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": 1093.0,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 708,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 26,
            "run_time_ns_delta": 28418,
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
            "avg_ns_per_run": 2751.8518518518517,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 710,
            "name": "trace_chmod_common",
            "run_cnt_delta": 27,
            "run_time_ns_delta": 74300,
            "type": "kprobe"
          },
          "711": {
            "avg_ns_per_run": 1147.2857142857142,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 711,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 16062,
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
            "avg_ns_per_run": 343.31779661016947,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 714,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 236,
            "run_time_ns_delta": 81023,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": 1152.9364406779662,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 715,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 236,
            "run_time_ns_delta": 272093,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": 1676.7407407407406,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 716,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 27,
            "run_time_ns_delta": 45272,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": 79.98692810457516,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 717,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 459,
            "run_time_ns_delta": 36714,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 191.41484716157206,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 718,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 229,
            "run_time_ns_delta": 43834,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 669.0184331797235,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 719,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 651,
            "run_time_ns_delta": 435531,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 1410.2515337423313,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 721,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 229871,
            "type": "cgroup_skb"
          },
          "722": {
            "avg_ns_per_run": 1818.8597560975609,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 722,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 164,
            "run_time_ns_delta": 298293,
            "type": "cgroup_skb"
          },
          "723": {
            "avg_ns_per_run": 2548.0,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 723,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2548,
            "type": "raw_tracepoint"
          },
          "724": {
            "avg_ns_per_run": 1713.0,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 724,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1713,
            "type": "raw_tracepoint"
          },
          "725": {
            "avg_ns_per_run": 133.28301886792454,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 725,
            "name": "empty_kprobe",
            "run_cnt_delta": 53,
            "run_time_ns_delta": 7064,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": 943.0377358490566,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 726,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 53,
            "run_time_ns_delta": 49981,
            "type": "raw_tracepoint"
          },
          "727": {
            "avg_ns_per_run": 397.64023250986094,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 727,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 9634,
            "run_time_ns_delta": 3830866,
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
            "duration_s": 5.197111237999991,
            "ops_per_sec": 279.00114767564696,
            "ops_total": 1450.0,
            "stderr": "module_load_candidate=vcan",
            "stdout": ""
          }
        ]
      },
      "error": "prog 665: BPF_PROG_REJIT: Invalid argument (os error 22)",
      "post_rejit": {
        "bpf": {
          "570": {
            "avg_ns_per_run": 146.32881047863881,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 570,
            "name": "tracepoint__raw",
            "run_cnt_delta": 2994053,
            "run_time_ns_delta": 438116214,
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
            "avg_ns_per_run": 352.25863312740336,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 573,
            "name": "tracepoint__raw",
            "run_cnt_delta": 2994222,
            "run_time_ns_delta": 1054740549,
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
            "avg_ns_per_run": 339.19053545157,
            "bytes_jited": 8131,
            "bytes_xlated": 13608,
            "id": 576,
            "name": "trace_sys_enter",
            "run_cnt_delta": 2994818,
            "run_time_ns_delta": 1015813921,
            "type": "raw_tracepoint"
          },
          "577": {
            "avg_ns_per_run": 310.33924380590844,
            "bytes_jited": 8164,
            "bytes_xlated": 13664,
            "id": 577,
            "name": "trace_sys_exit",
            "run_cnt_delta": 2994628,
            "run_time_ns_delta": 929350589,
            "type": "raw_tracepoint"
          },
          "578": {
            "avg_ns_per_run": 712.2666666666667,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 578,
            "name": "trace_ptrace",
            "run_cnt_delta": 60,
            "run_time_ns_delta": 42736,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": 1456.6333333333334,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 579,
            "name": "trace_ret_ptrac",
            "run_cnt_delta": 60,
            "run_time_ns_delta": 87398,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": 451.1666666666667,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 580,
            "name": "trace_process_v",
            "run_cnt_delta": 30,
            "run_time_ns_delta": 13535,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": 1962.4,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 581,
            "name": "trace_ret_proce",
            "run_cnt_delta": 30,
            "run_time_ns_delta": 58872,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": 1334.2954545454545,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 582,
            "name": "trace_arch_prct",
            "run_cnt_delta": 44,
            "run_time_ns_delta": 58709,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": 1868.5,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 583,
            "name": "trace_ret_arch_",
            "run_cnt_delta": 44,
            "run_time_ns_delta": 82214,
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
            "avg_ns_per_run": 1094.8275862068965,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 586,
            "name": "trace_dup2",
            "run_cnt_delta": 58,
            "run_time_ns_delta": 63500,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 2203.6206896551726,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 587,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 58,
            "run_time_ns_delta": 127810,
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
            "avg_ns_per_run": 5147.775,
            "bytes_jited": 19847,
            "bytes_xlated": 32320,
            "id": 595,
            "name": "tracepoint__sch",
            "run_cnt_delta": 160,
            "run_time_ns_delta": 823644,
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
            "avg_ns_per_run": 4849.568181818182,
            "bytes_jited": 20525,
            "bytes_xlated": 35336,
            "id": 603,
            "name": "tracepoint__sch",
            "run_cnt_delta": 44,
            "run_time_ns_delta": 213381,
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
            "avg_ns_per_run": 1762.7125,
            "bytes_jited": 8680,
            "bytes_xlated": 14464,
            "id": 605,
            "name": "tracepoint__sch",
            "run_cnt_delta": 160,
            "run_time_ns_delta": 282034,
            "type": "raw_tracepoint"
          },
          "606": {
            "avg_ns_per_run": 1554.525,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 606,
            "name": "tracepoint__sch",
            "run_cnt_delta": 160,
            "run_time_ns_delta": 248724,
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
            "avg_ns_per_run": 269.16992204755985,
            "bytes_jited": 8925,
            "bytes_xlated": 14840,
            "id": 608,
            "name": "tracepoint__sch",
            "run_cnt_delta": 294282,
            "run_time_ns_delta": 79211863,
            "type": "raw_tracepoint"
          },
          "609": {
            "avg_ns_per_run": 18.161744022503516,
            "bytes_jited": 8163,
            "bytes_xlated": 13680,
            "id": 609,
            "name": "trace_filldir64",
            "run_cnt_delta": 25596,
            "run_time_ns_delta": 464868,
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
            "avg_ns_per_run": 1322.3,
            "bytes_jited": 7921,
            "bytes_xlated": 13312,
            "id": 611,
            "name": "trace_do_exit",
            "run_cnt_delta": 160,
            "run_time_ns_delta": 211568,
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
            "avg_ns_per_run": 689.0518134715026,
            "bytes_jited": 11470,
            "bytes_xlated": 18264,
            "id": 615,
            "name": "trace_security_",
            "run_cnt_delta": 193,
            "run_time_ns_delta": 132987,
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
            "avg_ns_per_run": 3347.0,
            "bytes_jited": 8620,
            "bytes_xlated": 14352,
            "id": 617,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3347,
            "type": "raw_tracepoint"
          },
          "618": {
            "avg_ns_per_run": 1959.0,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 618,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1959,
            "type": "raw_tracepoint"
          },
          "619": {
            "avg_ns_per_run": 1951.0,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 619,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1951,
            "type": "raw_tracepoint"
          },
          "620": {
            "avg_ns_per_run": 3628.4772727272725,
            "bytes_jited": 33373,
            "bytes_xlated": 52824,
            "id": 620,
            "name": "trace_security_",
            "run_cnt_delta": 44,
            "run_time_ns_delta": 159653,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": 808.1322957198444,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 621,
            "name": "trace_security_file_open",
            "run_cnt_delta": 7453,
            "run_time_ns_delta": 6023010,
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
            "avg_ns_per_run": 1698.95,
            "bytes_jited": 9984,
            "bytes_xlated": 16352,
            "id": 623,
            "name": "trace_security_",
            "run_cnt_delta": 140,
            "run_time_ns_delta": 237853,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": 1019.290909090909,
            "bytes_jited": 10723,
            "bytes_xlated": 16880,
            "id": 624,
            "name": "trace_commit_cr",
            "run_cnt_delta": 110,
            "run_time_ns_delta": 112122,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": 1867.9375,
            "bytes_jited": 10045,
            "bytes_xlated": 16520,
            "id": 625,
            "name": "trace_switch_ta",
            "run_cnt_delta": 160,
            "run_time_ns_delta": 298870,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 174.39527703604807,
            "bytes_jited": 8174,
            "bytes_xlated": 13680,
            "id": 626,
            "name": "trace_cap_capab",
            "run_cnt_delta": 23968,
            "run_time_ns_delta": 4179906,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 929.0573770491803,
            "bytes_jited": 8471,
            "bytes_xlated": 14120,
            "id": 627,
            "name": "trace_security_",
            "run_cnt_delta": 122,
            "run_time_ns_delta": 113345,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": 2485.5,
            "bytes_jited": 9144,
            "bytes_xlated": 15208,
            "id": 628,
            "name": "trace_security_",
            "run_cnt_delta": 30,
            "run_time_ns_delta": 74565,
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
            "avg_ns_per_run": 1785.9666666666667,
            "bytes_jited": 10780,
            "bytes_xlated": 16456,
            "id": 632,
            "name": "trace_security_",
            "run_cnt_delta": 30,
            "run_time_ns_delta": 53579,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": 1642.9666666666667,
            "bytes_jited": 10075,
            "bytes_xlated": 15400,
            "id": 633,
            "name": "trace_security_",
            "run_cnt_delta": 30,
            "run_time_ns_delta": 49289,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 2384.19,
            "bytes_jited": 11260,
            "bytes_xlated": 17192,
            "id": 634,
            "name": "trace_security_",
            "run_cnt_delta": 100,
            "run_time_ns_delta": 238419,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 1608.21875,
            "bytes_jited": 10589,
            "bytes_xlated": 16080,
            "id": 635,
            "name": "trace_security_",
            "run_cnt_delta": 32,
            "run_time_ns_delta": 51463,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": 1767.111111111111,
            "bytes_jited": 11025,
            "bytes_xlated": 16864,
            "id": 636,
            "name": "trace_security_",
            "run_cnt_delta": 36,
            "run_time_ns_delta": 63616,
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
            "avg_ns_per_run": 62.997339776443596,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 639,
            "name": "trace_vfs_write",
            "run_cnt_delta": 40974,
            "run_time_ns_delta": 2581253,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": 40.6414279439754,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 640,
            "name": "vfs_write_magic",
            "run_cnt_delta": 40982,
            "run_time_ns_delta": 1665567,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": 35.9941419121775,
            "bytes_jited": 19108,
            "bytes_xlated": 31720,
            "id": 641,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 40969,
            "run_time_ns_delta": 1474644,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": 43.57662807171821,
            "bytes_jited": 23757,
            "bytes_xlated": 36648,
            "id": 642,
            "name": "vfs_write_magic",
            "run_cnt_delta": 40938,
            "run_time_ns_delta": 1783940,
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
            "avg_ns_per_run": 68.93434065934066,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 644,
            "name": "trace_vfs_write",
            "run_cnt_delta": 3640,
            "run_time_ns_delta": 250921,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": 45.331043956043956,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 645,
            "name": "vfs_writev_magi",
            "run_cnt_delta": 3640,
            "run_time_ns_delta": 165005,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": 43.63543956043956,
            "bytes_jited": 19107,
            "bytes_xlated": 31712,
            "id": 646,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 3640,
            "run_time_ns_delta": 158833,
            "type": "kprobe"
          },
          "647": {
            "avg_ns_per_run": 49.53489010989011,
            "bytes_jited": 23786,
            "bytes_xlated": 36696,
            "id": 647,
            "name": "vfs_writev_magi",
            "run_cnt_delta": 3640,
            "run_time_ns_delta": 180307,
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
            "avg_ns_per_run": 79.9324002719855,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 654,
            "name": "trace_vfs_read",
            "run_cnt_delta": 17648,
            "run_time_ns_delta": 1410647,
            "type": "kprobe"
          },
          "655": {
            "avg_ns_per_run": 152.97050147492627,
            "bytes_jited": 19111,
            "bytes_xlated": 31720,
            "id": 655,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 1356,
            "run_time_ns_delta": 207428,
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
            "avg_ns_per_run": 74.81565934065934,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 657,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 3640,
            "run_time_ns_delta": 272329,
            "type": "kprobe"
          },
          "658": {
            "avg_ns_per_run": 54.50027472527473,
            "bytes_jited": 19107,
            "bytes_xlated": 31712,
            "id": 658,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 3640,
            "run_time_ns_delta": 198381,
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
            "avg_ns_per_run": 190.2894033837934,
            "bytes_jited": 20715,
            "bytes_xlated": 32736,
            "id": 660,
            "name": "trace_mmap_aler",
            "run_cnt_delta": 1123,
            "run_time_ns_delta": 213695,
            "type": "kprobe"
          },
          "661": {
            "avg_ns_per_run": 119.17771084337349,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 661,
            "name": "trace_do_mmap",
            "run_cnt_delta": 996,
            "run_time_ns_delta": 118701,
            "type": "kprobe"
          },
          "662": {
            "avg_ns_per_run": 65.72590361445783,
            "bytes_jited": 19426,
            "bytes_xlated": 31584,
            "id": 662,
            "name": "trace_ret_do_mm",
            "run_cnt_delta": 996,
            "run_time_ns_delta": 65463,
            "type": "kprobe"
          },
          "663": {
            "avg_ns_per_run": 835.7178714859438,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 663,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 996,
            "run_time_ns_delta": 832375,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 1353.846590909091,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 664,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 176,
            "run_time_ns_delta": 238277,
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
            "avg_ns_per_run": 311.98853698305254,
            "bytes_jited": 15585,
            "bytes_xlated": 26904,
            "id": 666,
            "name": "trace_security_",
            "run_cnt_delta": 20239,
            "run_time_ns_delta": 6314336,
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
            "avg_ns_per_run": 271.1817737998373,
            "bytes_jited": 8333,
            "bytes_xlated": 13904,
            "id": 669,
            "name": "trace_security_",
            "run_cnt_delta": 6145,
            "run_time_ns_delta": 1666412,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 970.8735177865613,
            "bytes_jited": 9581,
            "bytes_xlated": 15448,
            "id": 670,
            "name": "trace_security_",
            "run_cnt_delta": 506,
            "run_time_ns_delta": 491262,
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
            "avg_ns_per_run": 2296.4166666666665,
            "bytes_jited": 18641,
            "bytes_xlated": 30648,
            "id": 674,
            "name": "trace_security_",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 27557,
            "type": "kprobe"
          },
          "675": {
            "avg_ns_per_run": 2865.4166666666665,
            "bytes_jited": 17247,
            "bytes_xlated": 30448,
            "id": 675,
            "name": "trace_security_",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 34385,
            "type": "kprobe"
          },
          "676": {
            "avg_ns_per_run": 2232.8333333333335,
            "bytes_jited": 9225,
            "bytes_xlated": 15352,
            "id": 676,
            "name": "trace_security_",
            "run_cnt_delta": 30,
            "run_time_ns_delta": 66985,
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
            "avg_ns_per_run": 6243.75,
            "bytes_jited": 19868,
            "bytes_xlated": 32648,
            "id": 680,
            "name": "tracepoint__mod",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 74925,
            "type": "raw_tracepoint"
          },
          "681": {
            "avg_ns_per_run": 6049.083333333333,
            "bytes_jited": 8959,
            "bytes_xlated": 14920,
            "id": 681,
            "name": "tracepoint__mod",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 72589,
            "type": "raw_tracepoint"
          },
          "682": {
            "avg_ns_per_run": 720.6666666666666,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 682,
            "name": "trace_do_init_m",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 8648,
            "type": "kprobe"
          },
          "683": {
            "avg_ns_per_run": 215.5,
            "bytes_jited": 14542,
            "bytes_xlated": 23904,
            "id": 683,
            "name": "trace_ret_do_in",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 2586,
            "type": "kprobe"
          },
          "684": {
            "avg_ns_per_run": 1760.1136363636363,
            "bytes_jited": 18482,
            "bytes_xlated": 30352,
            "id": 684,
            "name": "trace_load_elf_",
            "run_cnt_delta": 88,
            "run_time_ns_delta": 154890,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 35.66635244758959,
            "bytes_jited": 8681,
            "bytes_xlated": 14496,
            "id": 685,
            "name": "trace_security_",
            "run_cnt_delta": 75319,
            "run_time_ns_delta": 2686354,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 2078.3260869565215,
            "bytes_jited": 8474,
            "bytes_xlated": 14112,
            "id": 686,
            "name": "tracepoint__tas",
            "run_cnt_delta": 46,
            "run_time_ns_delta": 95603,
            "type": "raw_tracepoint"
          },
          "687": {
            "avg_ns_per_run": 2812.3,
            "bytes_jited": 9792,
            "bytes_xlated": 16344,
            "id": 687,
            "name": "trace_security_",
            "run_cnt_delta": 30,
            "run_time_ns_delta": 84369,
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
            "avg_ns_per_run": 438.2507903055848,
            "bytes_jited": 10109,
            "bytes_xlated": 16296,
            "id": 690,
            "name": "trace_do_sigact",
            "run_cnt_delta": 949,
            "run_time_ns_delta": 415900,
            "type": "kprobe"
          },
          "691": {
            "avg_ns_per_run": 2814.5208333333335,
            "bytes_jited": 18560,
            "bytes_xlated": 30528,
            "id": 691,
            "name": "trace_vfs_utime",
            "run_cnt_delta": 48,
            "run_time_ns_delta": 135097,
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
            "avg_ns_per_run": 785.1162162162162,
            "bytes_jited": 9530,
            "bytes_xlated": 15824,
            "id": 693,
            "name": "trace_do_trunca",
            "run_cnt_delta": 1850,
            "run_time_ns_delta": 1452465,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 294.10065695084194,
            "bytes_jited": 16708,
            "bytes_xlated": 27176,
            "id": 694,
            "name": "trace_fd_instal",
            "run_cnt_delta": 13243,
            "run_time_ns_delta": 3894775,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": 903.4051485148515,
            "bytes_jited": 16636,
            "bytes_xlated": 27024,
            "id": 695,
            "name": "trace_filp_clos",
            "run_cnt_delta": 5050,
            "run_time_ns_delta": 4562196,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": 76.4082147360836,
            "bytes_jited": 459,
            "bytes_xlated": 768,
            "id": 696,
            "name": "trace_file_upda",
            "run_cnt_delta": 5551,
            "run_time_ns_delta": 424142,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": 33.61088092235633,
            "bytes_jited": 20054,
            "bytes_xlated": 31168,
            "id": 697,
            "name": "trace_ret_file_",
            "run_cnt_delta": 5551,
            "run_time_ns_delta": 186574,
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
            "avg_ns_per_run": 504.2,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 700,
            "name": "trace_inotify_f",
            "run_cnt_delta": 30,
            "run_time_ns_delta": 15126,
            "type": "kprobe"
          },
          "701": {
            "avg_ns_per_run": 482.2,
            "bytes_jited": 18025,
            "bytes_xlated": 29936,
            "id": 701,
            "name": "trace_ret_inoti",
            "run_cnt_delta": 30,
            "run_time_ns_delta": 14466,
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
            "avg_ns_per_run": 369.40909090909093,
            "bytes_jited": 16472,
            "bytes_xlated": 28872,
            "id": 703,
            "name": "trace_exec_binp",
            "run_cnt_delta": 44,
            "run_time_ns_delta": 16254,
            "type": "kprobe"
          },
          "704": {
            "avg_ns_per_run": 4752.068181818182,
            "bytes_jited": 16702,
            "bytes_xlated": 29144,
            "id": 704,
            "name": "trace_security_",
            "run_cnt_delta": 44,
            "run_time_ns_delta": 209091,
            "type": "kprobe"
          },
          "705": {
            "avg_ns_per_run": 3366.7837837837837,
            "bytes_jited": 24469,
            "bytes_xlated": 38320,
            "id": 705,
            "name": "trace_execute_f",
            "run_cnt_delta": 74,
            "run_time_ns_delta": 249142,
            "type": "kprobe"
          },
          "706": {
            "avg_ns_per_run": 2977.5,
            "bytes_jited": 18391,
            "bytes_xlated": 30200,
            "id": 706,
            "name": "trace_security_",
            "run_cnt_delta": 30,
            "run_time_ns_delta": 89325,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": 2620.6923076923076,
            "bytes_jited": 18194,
            "bytes_xlated": 29912,
            "id": 707,
            "name": "trace_set_fs_pw",
            "run_cnt_delta": 13,
            "run_time_ns_delta": 34069,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": 1528.0,
            "bytes_jited": 8631,
            "bytes_xlated": 14360,
            "id": 708,
            "name": "trace_security_",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 3056,
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
            "avg_ns_per_run": 2793.6,
            "bytes_jited": 17561,
            "bytes_xlated": 29176,
            "id": 710,
            "name": "trace_chmod_com",
            "run_cnt_delta": 30,
            "run_time_ns_delta": 83808,
            "type": "kprobe"
          },
          "711": {
            "avg_ns_per_run": 1272.5714285714287,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 711,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 17816,
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
            "avg_ns_per_run": 346.5515695067265,
            "bytes_jited": 329,
            "bytes_xlated": 520,
            "id": 714,
            "name": "trace_sock_allo",
            "run_cnt_delta": 223,
            "run_time_ns_delta": 77281,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": 1374.286995515695,
            "bytes_jited": 8439,
            "bytes_xlated": 12928,
            "id": 715,
            "name": "trace_ret_sock_",
            "run_cnt_delta": 223,
            "run_time_ns_delta": 306466,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": 1592.7666666666667,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 716,
            "name": "trace_security_",
            "run_cnt_delta": 30,
            "run_time_ns_delta": 47783,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": 145.02479338842974,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 717,
            "name": "trace_security_",
            "run_cnt_delta": 242,
            "run_time_ns_delta": 35096,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 303.19,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 718,
            "name": "trace_security_",
            "run_cnt_delta": 100,
            "run_time_ns_delta": 30319,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 1060.4581497797358,
            "bytes_jited": 5282,
            "bytes_xlated": 8136,
            "id": 719,
            "name": "cgroup_bpf_run_",
            "run_cnt_delta": 454,
            "run_time_ns_delta": 481448,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 1365.5055555555555,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 721,
            "name": "cgroup_skb_ingr",
            "run_cnt_delta": 180,
            "run_time_ns_delta": 245791,
            "type": "cgroup_skb"
          },
          "722": {
            "avg_ns_per_run": 1852.3166666666666,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 722,
            "name": "cgroup_skb_egre",
            "run_cnt_delta": 180,
            "run_time_ns_delta": 333417,
            "type": "cgroup_skb"
          },
          "723": {
            "avg_ns_per_run": 2540.0,
            "bytes_jited": 916,
            "bytes_xlated": 1560,
            "id": 723,
            "name": "cgroup_mkdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2540,
            "type": "raw_tracepoint"
          },
          "724": {
            "avg_ns_per_run": 1893.0,
            "bytes_jited": 898,
            "bytes_xlated": 1520,
            "id": 724,
            "name": "cgroup_rmdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1893,
            "type": "raw_tracepoint"
          },
          "725": {
            "avg_ns_per_run": 50.61363636363637,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 725,
            "name": "empty_kprobe",
            "run_cnt_delta": 44,
            "run_time_ns_delta": 2227,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": 1144.5454545454545,
            "bytes_jited": 58660,
            "bytes_xlated": 95944,
            "id": 726,
            "name": "tracepoint__exe",
            "run_cnt_delta": 44,
            "run_time_ns_delta": 50360,
            "type": "raw_tracepoint"
          },
          "727": {
            "avg_ns_per_run": 415.29706158593854,
            "bytes_jited": 7290,
            "bytes_xlated": 13264,
            "id": 727,
            "name": "lsm_file_open_t",
            "run_cnt_delta": 7453,
            "run_time_ns_delta": 3095209,
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
            "duration_s": 5.206563644000084,
            "ops_per_sec": 356.47312256305725,
            "ops_total": 1856.0,
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
        "output_chars": 2254108,
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
            "avg_ns_per_run": 116.5911920333914,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 734,
            "name": "cap_capable",
            "run_cnt_delta": 152135,
            "run_time_ns_delta": 17737601,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0712796579999804,
            "ops_per_sec": 1144.4257256680053,
            "ops_total": 1226.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [28238] setting to a 1 secs run per stressor\nstress-ng: info:  [28238] dispatching hogs: 2 exec\nstress-ng: info:  [28238] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [28238] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [28238]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [28238] exec               1226      1.03      2.55      0.83      1189.85         362.09\nstress-ng: info:  [28238] skipped: 0\nstress-ng: info:  [28238] passed: 2: exec (2)\nstress-ng: info:  [28238] failed: 0\nstress-ng: info:  [28238] metrics untrustworthy: 0\nstress-ng: info:  [28238] successful run completed in 1.04 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "734": {
            "avg_ns_per_run": 115.28357488233742,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 734,
            "name": "cap_capable",
            "run_cnt_delta": 155317,
            "run_time_ns_delta": 17905499,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0916875120000213,
            "ops_per_sec": 1158.7564995430444,
            "ops_total": 1265.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [16043] setting to a 1 secs run per stressor\nstress-ng: info:  [16043] dispatching hogs: 2 exec\nstress-ng: info:  [16043] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16043] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16043]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16043] exec               1265      1.05      2.55      0.92      1201.29         364.61\nstress-ng: info:  [16043] skipped: 0\nstress-ng: info:  [16043] passed: 2: exec (2)\nstress-ng: info:  [16043] failed: 0\nstress-ng: info:  [16043] metrics untrustworthy: 0\nstress-ng: info:  [16043] successful run completed in 1.07 secs"
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
        "output_chars": 5257,
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
            "avg_ns_per_run": 173.62241949037065,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 740,
            "name": "block_io_start",
            "run_cnt_delta": 352256,
            "run_time_ns_delta": 61159539,
            "type": "tracepoint"
          },
          "741": {
            "avg_ns_per_run": 327.4065083348474,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 741,
            "name": "block_io_done",
            "run_cnt_delta": 352256,
            "run_time_ns_delta": 115330907,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.020000815000003,
            "ops_per_sec": 70170.50653606314,
            "ops_total": 352256.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "740": {
            "avg_ns_per_run": 155.6214968659157,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 740,
            "name": "block_io_start",
            "run_cnt_delta": 352256,
            "run_time_ns_delta": 54818606,
            "type": "tracepoint"
          },
          "741": {
            "avg_ns_per_run": 285.64494288244913,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 741,
            "name": "block_io_done",
            "run_cnt_delta": 352256,
            "run_time_ns_delta": 100620145,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.005727914999966,
            "ops_per_sec": 70370.58465452021,
            "ops_total": 352256.0,
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
        "output_chars": 12593,
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
            "avg_ns_per_run": 1390.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 747,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1390,
            "type": "perf_event"
          },
          "748": {
            "avg_ns_per_run": 47.22568109820486,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 748,
            "name": "vfs_create",
            "run_cnt_delta": 23675,
            "run_time_ns_delta": 1118068,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0051209320000112,
            "ops_per_sec": 70.63826624197615,
            "ops_total": 71.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "747": {
            "avg_ns_per_run": 1437.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 747,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1437,
            "type": "perf_event"
          },
          "748": {
            "avg_ns_per_run": 48.77198358413133,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 748,
            "name": "vfs_create",
            "run_cnt_delta": 18275,
            "run_time_ns_delta": 891308,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.006354070000043,
            "ops_per_sec": 67.57065135136492,
            "ops_total": 68.0,
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
        "output_chars": 8220,
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
            "avg_ns_per_run": 99.55992122672173,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 754,
            "name": "sched_wakeup",
            "run_cnt_delta": 52302,
            "run_time_ns_delta": 5207183,
            "type": "tracepoint"
          },
          "755": {
            "avg_ns_per_run": 236.3150875243123,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 755,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 3599,
            "run_time_ns_delta": 850498,
            "type": "tracepoint"
          },
          "756": {
            "avg_ns_per_run": 156.64952059143198,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 756,
            "name": "sched_switch",
            "run_cnt_delta": 92927,
            "run_time_ns_delta": 14556970,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0704748709999876,
            "ops_per_sec": 13.07830793535756,
            "ops_total": 14.0,
            "stderr": "",
            "stdout": "Time: 0.045\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.046\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.067\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.046\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.051\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "754": {
            "avg_ns_per_run": 100.8203137963458,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 754,
            "name": "sched_wakeup",
            "run_cnt_delta": 54239,
            "run_time_ns_delta": 5468393,
            "type": "tracepoint"
          },
          "755": {
            "avg_ns_per_run": 227.58293970547373,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 755,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 3599,
            "run_time_ns_delta": 819071,
            "type": "tracepoint"
          },
          "756": {
            "avg_ns_per_run": 152.8259149665161,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 756,
            "name": "sched_switch",
            "run_cnt_delta": 96315,
            "run_time_ns_delta": 14719428,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.023806047999983,
            "ops_per_sec": 13.674465029142151,
            "ops_total": 14.0,
            "stderr": "",
            "stdout": "Time: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.050\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.059\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.051\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.035\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.056\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.046\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.045\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043"
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
            "avg_ns_per_run": 854.2901069518716,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 763,
            "name": "tcp_set_state",
            "run_cnt_delta": 748,
            "run_time_ns_delta": 639009,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.014526370999988,
            "ops_per_sec": 74.9118033522274,
            "ops_total": 76.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "763": {
            "avg_ns_per_run": 835.7381916329284,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 763,
            "name": "tcp_set_state",
            "run_cnt_delta": 741,
            "run_time_ns_delta": 619282,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.003516940000054,
            "ops_per_sec": 74.73715391390996,
            "ops_total": 75.0,
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
            "avg_ns_per_run": 6143.388888888889,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 769,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 18,
            "run_time_ns_delta": 110581,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 8.22094836499997,
            "ops_per_sec": 0.4865618688264337,
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
            "avg_ns_per_run": 4671.0,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 769,
            "name": "tcp_retransmit_",
            "run_cnt_delta": 15,
            "run_time_ns_delta": 70065,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 8.213975757999947,
            "ops_per_sec": 0.48697489715674247,
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
        "output_chars": 5740,
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
    "losses": 106,
    "per_program_geomean": 1.068455130320735,
    "program_count": 171,
    "wins": 65
  },
  "workload_seconds": 1.0
}
```
