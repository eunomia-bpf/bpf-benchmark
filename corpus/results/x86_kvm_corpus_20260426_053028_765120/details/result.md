# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-04-26T05:44:00.655551+00:00",
  "kinsn_modules": {
    "captured_at": "2026-04-26T05:30:28.800124+00:00",
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
      "invoked_at": "2026-04-26T05:30:28.800066+00:00",
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
        "captured_at": "2026-04-26T05:30:28.800059+00:00",
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
      "captured_at": "2026-04-26T05:30:28.792165+00:00",
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
  "results": [
    {
      "app": "bcc/capable",
      "baseline": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 82.72449055155747,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 148543,
            "run_time_ns_delta": 12288144,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0572682739999664,
            "ops_per_sec": 1128.3796452971385,
            "ops_total": 1193.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [3948] setting to a 1 secs run per stressor\nstress-ng: info:  [3948] dispatching hogs: 2 exec\nstress-ng: info:  [3948] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [3948] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [3948]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [3948] exec               1193      1.03      2.53      0.85      1159.00         352.49\nstress-ng: info:  [3948] skipped: 0\nstress-ng: info:  [3948] passed: 2: exec (2)\nstress-ng: info:  [3948] failed: 0\nstress-ng: info:  [3948] metrics untrustworthy: 0\nstress-ng: info:  [3948] successful run completed in 1.03 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 85.12112238868,
            "bytes_jited": 206,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 153993,
            "run_time_ns_delta": 13108057,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0998850500000117,
            "ops_per_sec": 1139.2099565313545,
            "ops_total": 1253.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [23062] setting to a 1 secs run per stressor\nstress-ng: info:  [23062] dispatching hogs: 2 exec\nstress-ng: info:  [23062] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [23062] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23062]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23062] exec               1253      1.08      2.64      0.95      1165.39         349.58\nstress-ng: info:  [23062] skipped: 0\nstress-ng: info:  [23062] passed: 2: exec (2)\nstress-ng: info:  [23062] failed: 0\nstress-ng: info:  [23062] metrics untrustworthy: 0\nstress-ng: info:  [23062] successful run completed in 1.08 secs"
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
            "avg_ns_per_run": 1788.4159072079535,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 1207,
            "run_time_ns_delta": 2158618,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 1365.776007497657,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 1067,
            "run_time_ns_delta": 1457283,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.064339761000042,
            "ops_per_sec": 1131.2177221198,
            "ops_total": 1204.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5758] setting to a 1 secs run per stressor\nstress-ng: info:  [5758] dispatching hogs: 2 exec\nstress-ng: info:  [5758] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5758] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5758]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5758] exec               1204      1.02      2.52      0.88      1177.56         353.85\nstress-ng: info:  [5758] skipped: 0\nstress-ng: info:  [5758] passed: 2: exec (2)\nstress-ng: info:  [5758] failed: 0\nstress-ng: info:  [5758] metrics untrustworthy: 0\nstress-ng: info:  [5758] successful run completed in 1.04 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 1916.000852514919,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 1173,
            "run_time_ns_delta": 2247469,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 1392.5526315789473,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_exec",
            "run_cnt_delta": 1102,
            "run_time_ns_delta": 1534593,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0669911790000697,
            "ops_per_sec": 1085.2948204175589,
            "ops_total": 1158.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [24925] setting to a 1 secs run per stressor\nstress-ng: info:  [24925] dispatching hogs: 2 exec\nstress-ng: info:  [24925] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24925] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24925]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24925] exec               1158      1.03      2.47      0.84      1128.49         350.36\nstress-ng: info:  [24925] skipped: 0\nstress-ng: info:  [24925] passed: 2: exec (2)\nstress-ng: info:  [24925] failed: 0\nstress-ng: info:  [24925] metrics untrustworthy: 0\nstress-ng: info:  [24925] successful run completed in 1.03 secs"
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
        "output_chars": 7421,
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
            "avg_ns_per_run": 57.43934044084879,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 29171,
            "run_time_ns_delta": 1675563,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 652.5737008089949,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 14586,
            "run_time_ns_delta": 9518440,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": 650.3374014398355,
            "bytes_jited": 742,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_return",
            "run_cnt_delta": 14585,
            "run_time_ns_delta": 9485171,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0000674729999446,
            "ops_per_sec": 29169.03187791372,
            "ops_total": 29171.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 56.70635109824621,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 29365,
            "run_time_ns_delta": 1665182,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 648.865967445345,
            "bytes_jited": 719,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_re",
            "run_cnt_delta": 14683,
            "run_time_ns_delta": 9527299,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": 647.5999863778777,
            "bytes_jited": 740,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_re",
            "run_cnt_delta": 14682,
            "run_time_ns_delta": 9508063,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.003140171000041,
            "ops_per_sec": 29273.07753085566,
            "ops_total": 29365.0,
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
        "output_chars": 12433,
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
            "avg_ns_per_run": 145.93888300583185,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 327683,
            "run_time_ns_delta": 47821691,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 166.51760074461754,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 327685,
            "run_time_ns_delta": 54565320,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 378.0272242329547,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 327686,
            "run_time_ns_delta": 123874229,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.11282122099999,
            "ops_per_sec": 64089.86073170592,
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
            "avg_ns_per_run": 143.62952178495507,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start",
            "run_cnt_delta": 335874,
            "run_time_ns_delta": 48241422,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 168.4503566792507,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 335876,
            "run_time_ns_delta": 56578432,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 372.0776444948597,
            "bytes_jited": 548,
            "bytes_xlated": 848,
            "id": 20,
            "name": "trace_req_compl",
            "run_cnt_delta": 335877,
            "run_time_ns_delta": 124972323,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.136894858000005,
            "ops_per_sec": 65384.24657007057,
            "ops_total": 335872.0,
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
            "avg_ns_per_run": 46.03642987249545,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 549,
            "run_time_ns_delta": 25274,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 27.539372409709888,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 6756,
            "run_time_ns_delta": 186056,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 26.601972416981276,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 12979,
            "run_time_ns_delta": 345267,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0074735770000416,
            "ops_per_sec": 40.695856383733535,
            "ops_total": 41.0,
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
            "avg_ns_per_run": 33.443014705882355,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 544,
            "run_time_ns_delta": 18193,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 28.350925291295408,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 8754,
            "run_time_ns_delta": 248184,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 27.285063986944945,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 11643,
            "run_time_ns_delta": 317680,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0095512080001754,
            "ops_per_sec": 68.34720166070863,
            "ops_total": 69.0,
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
            "avg_ns_per_run": 1381.7691673536685,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 1213,
            "run_time_ns_delta": 1676086,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 1481.0502958579882,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 338,
            "run_time_ns_delta": 500595,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0044097740000097,
            "ops_per_sec": 336.5160403148334,
            "ops_total": 338.0,
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
            "avg_ns_per_run": 1261.5119474313024,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 1674,
            "run_time_ns_delta": 2111771,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 1406.6537785588753,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 569,
            "run_time_ns_delta": 800386,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0010111609999512,
            "ops_per_sec": 568.4252305754538,
            "ops_total": 569.0,
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
        "output_chars": 11098,
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
            "avg_ns_per_run": 61.878760789438445,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 1172327,
            "run_time_ns_delta": 72542142,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 61.33619997559941,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 1172103,
            "run_time_ns_delta": 71892344,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0000420950000262,
            "ops_per_sec": 510.97849036043493,
            "ops_total": 511.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 63.28131386292277,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 1257087,
            "run_time_ns_delta": 79550117,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 60.053204267477824,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 1257136,
            "run_time_ns_delta": 75495045,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0017862390000118,
            "ops_per_sec": 667.8071368476765,
            "ops_total": 669.0,
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
        "output_chars": 9094,
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
            "avg_ns_per_run": 655.825,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 80,
            "run_time_ns_delta": 52466,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4035.325,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 40,
            "run_time_ns_delta": 161413,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 3604.575,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 40,
            "run_time_ns_delta": 144183,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0063443349999943,
            "ops_per_sec": 79.49565294666309,
            "ops_total": 80.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 657.8271604938271,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_e",
            "run_cnt_delta": 81,
            "run_time_ns_delta": 53284,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 3733.951219512195,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v",
            "run_cnt_delta": 41,
            "run_time_ns_delta": 153092,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 3687.0,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v",
            "run_cnt_delta": 40,
            "run_time_ns_delta": 147480,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0044124309999916,
            "ops_per_sec": 80.64416319435286,
            "ops_total": 81.0,
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
        "output_chars": 12343,
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
            "avg_ns_per_run": 667.4913793103449,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 812,
            "run_time_ns_delta": 542003,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.00254388999997,
            "ops_per_sec": 73.8122298067192,
            "ops_total": 74.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "44": {
            "avg_ns_per_run": 656.0512540894221,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "sock__inet_sock",
            "run_cnt_delta": 917,
            "run_time_ns_delta": 601599,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0028758349999407,
            "ops_per_sec": 83.75912258370944,
            "ops_total": 84.0,
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
            "avg_ns_per_run": 172.20358582643752,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 75408,
            "run_time_ns_delta": 12985528,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 112.57118902145211,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 51883,
            "run_time_ns_delta": 5840531,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 237.37121422617395,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 3599,
            "run_time_ns_delta": 854299,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0369748610000897,
            "ops_per_sec": 13.500809447297478,
            "ops_total": 14.0,
            "stderr": "",
            "stdout": "Time: 0.052\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.048\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.038\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.049\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.048\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.045\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.049\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.049\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.054\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.056\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 165.8552047974655,
            "bytes_jited": 645,
            "bytes_xlated": 1136,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 88380,
            "run_time_ns_delta": 14658283,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 112.12054502175162,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 60915,
            "run_time_ns_delta": 6829823,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 236.340372325646,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 3599,
            "run_time_ns_delta": 850589,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0236971609999728,
            "ops_per_sec": 13.675919533003738,
            "ops_total": 14.0,
            "stderr": "",
            "stdout": "Time: 0.063\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.035\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.035\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.064\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.045\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.051\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.041"
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
        "output_chars": 12834,
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
            "duration_s": 1.011178915999949,
            "ops_per_sec": 757.5316176786648,
            "ops_total": 766.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://127.0.0.1:32877/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     8.02ms    6.60ms  50.76ms   89.03%\n    Req/Sec   383.70    201.68   760.00     60.00%\n  766 requests in 1.01s, 115.95KB read\nRequests/sec:    760.29\nTransfer/sec:    115.08KB"
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
            "duration_s": 1.011311558999978,
            "ops_per_sec": 779.1861894461123,
            "ops_total": 788.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://127.0.0.1:45523/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     7.54ms    5.67ms  44.07ms   82.62%\n    Req/Sec   394.90    203.96   787.00     60.00%\n  788 requests in 1.01s, 119.41KB read\nRequests/sec:    784.04\nTransfer/sec:    118.81KB"
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
        "output_chars": 25755,
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
      "app": "otelcol-ebpf-profiler/default",
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
            "avg_ns_per_run": 352.15817223198593,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 131,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 1707,
            "run_time_ns_delta": 601134,
            "type": "tracepoint"
          },
          "132": {
            "avg_ns_per_run": 13390.390243902439,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 132,
            "name": "native_tracer_entry",
            "run_cnt_delta": 82,
            "run_time_ns_delta": 1098012,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1005323379999936,
            "ops_per_sec": 1098.559268323842,
            "ops_total": 1209.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [12353] setting to a 1 secs run per stressor\nstress-ng: info:  [12353] dispatching hogs: 2 exec\nstress-ng: info:  [12353] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12353] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12353]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12353] exec               1209      1.06      2.44      0.91      1141.21         360.94\nstress-ng: info:  [12353] skipped: 0\nstress-ng: info:  [12353] passed: 2: exec (2)\nstress-ng: info:  [12353] failed: 0\nstress-ng: info:  [12353] metrics untrustworthy: 0\nstress-ng: info:  [12353] successful run completed in 1.08 secs"
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
            "avg_ns_per_run": 375.428760768721,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 131,
            "name": "tracepoint__sch",
            "run_cnt_delta": 1509,
            "run_time_ns_delta": 566522,
            "type": "tracepoint"
          },
          "132": {
            "avg_ns_per_run": 14401.794520547945,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 132,
            "name": "native_tracer_e",
            "run_cnt_delta": 73,
            "run_time_ns_delta": 1051331,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 1.080854729000066,
            "ops_per_sec": 1110.232455669745,
            "ops_total": 1200.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [31494] setting to a 1 secs run per stressor\nstress-ng: info:  [31494] dispatching hogs: 2 exec\nstress-ng: info:  [31494] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31494] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31494]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31494] exec               1200      1.03      2.54      0.86      1163.89         352.97\nstress-ng: info:  [31494] skipped: 0\nstress-ng: info:  [31494] passed: 2: exec (2)\nstress-ng: info:  [31494] failed: 0\nstress-ng: info:  [31494] metrics untrustworthy: 0\nstress-ng: info:  [31494] successful run completed in 1.06 secs"
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
        "output_chars": 348003,
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
      "app": "cilium/default",
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
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 213,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 214,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 215,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 217,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 218,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 219,
            "name": "tail_handle_ipv4_from_netdev",
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
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 225,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 227,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "230": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 230,
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
          "234": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 234,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "235": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 235,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0116746669999657,
            "ops_per_sec": 810.5372475438568,
            "ops_total": 820.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://127.0.0.1:46383/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     7.13ms    5.38ms  34.45ms   82.55%\n    Req/Sec   411.60    166.06   710.00     55.00%\n  820 requests in 1.00s, 124.26KB read\nRequests/sec:    817.14\nTransfer/sec:    123.82KB"
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
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 213,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 214,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 215,
            "name": "tail_drop_notif",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 217,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 218,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 219,
            "name": "tail_handle_ipv",
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
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 225,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 227,
            "name": "tail_drop_notif",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "230": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 230,
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
          "234": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 234,
            "name": "tail_drop_notif",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "235": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 235,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0165218849999746,
            "ops_per_sec": 875.5345193576646,
            "ops_total": 890.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://127.0.0.1:44451/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     6.67ms    5.27ms  35.27ms   84.60%\n    Req/Sec   446.25    214.57     0.90k    65.00%\n  890 requests in 1.01s, 134.85KB read\nRequests/sec:    884.48\nTransfer/sec:    134.01KB"
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
        "output_chars": 101903,
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
      "app": "tetragon/default",
      "baseline": {
        "bpf": {
          "251": {
            "avg_ns_per_run": 477.78723404255317,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 251,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1269,
            "run_time_ns_delta": 606312,
            "type": "kprobe"
          },
          "253": {
            "avg_ns_per_run": 700.529224229543,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 253,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1882,
            "run_time_ns_delta": 1318396,
            "type": "kprobe"
          },
          "254": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 254,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "255": {
            "avg_ns_per_run": 2717.81993896236,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 255,
            "name": "event_execve",
            "run_cnt_delta": 983,
            "run_time_ns_delta": 2671617,
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
            "avg_ns_per_run": 270.9766022380468,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 257,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 983,
            "run_time_ns_delta": 266370,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 261,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 262,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 265,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 266,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "267": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 267,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "268": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 268,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 269,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 270,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 271,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 274,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 276,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 2496.9,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 278,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 24969,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 279,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 281,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "282": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 282,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 283,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 285,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 286,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 287,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": 733.654794520548,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 288,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1095,
            "run_time_ns_delta": 803352,
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 290,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": 587.9716894977169,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 291,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1095,
            "run_time_ns_delta": 643829,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 292,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 293,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 576.6820083682009,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 295,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1912,
            "run_time_ns_delta": 1102616,
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 299,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 300,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": 500.302810662801,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 301,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 12417,
            "run_time_ns_delta": 6212260,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 302,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 305,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 309,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 311,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 681.3068493150685,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 313,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1095,
            "run_time_ns_delta": 746031,
            "type": "kprobe"
          },
          "314": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 314,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "315": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 315,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "316": {
            "avg_ns_per_run": 614.9123287671233,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 316,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1095,
            "run_time_ns_delta": 673329,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 317,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 319,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 321,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 322,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "323": {
            "avg_ns_per_run": 577.428870292887,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 323,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1912,
            "run_time_ns_delta": 1104044,
            "type": "kprobe"
          },
          "324": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 324,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 325,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "326": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 326,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "327": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 327,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 328,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "329": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 329,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 330,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "331": {
            "avg_ns_per_run": 567.8917351377477,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 331,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6207,
            "run_time_ns_delta": 3524904,
            "type": "kprobe"
          },
          "332": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 332,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 334,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 335,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 581.5025837885722,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 337,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6773,
            "run_time_ns_delta": 3938517,
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 339,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "340": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 340,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "341": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 341,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 344,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 346,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 348,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "349": {
            "avg_ns_per_run": 8531.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 349,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 8531,
            "type": "kprobe"
          },
          "350": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 350,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 353,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "354": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 354,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 356,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "357": {
            "avg_ns_per_run": 289.82871828116316,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 357,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 43192,
            "run_time_ns_delta": 12518282,
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 359,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 360,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "361": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 361,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 364,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "365": {
            "avg_ns_per_run": 495.4306130203496,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 365,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 142116,
            "run_time_ns_delta": 70408617,
            "type": "kprobe"
          },
          "366": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 366,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 369,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "370": {
            "avg_ns_per_run": 41.27650433828803,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 370,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 142222,
            "run_time_ns_delta": 5870427,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 372,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 374,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "375": {
            "avg_ns_per_run": 977.2790535197427,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 375,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 130251,
            "run_time_ns_delta": 127291574,
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 378,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 49.23342623089266,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 380,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 130251,
            "run_time_ns_delta": 6412703,
            "type": "kprobe"
          },
          "381": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 381,
            "name": "generic_retkprobe_actions",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 386,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 387,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 389,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 390,
            "name": "generic_retkprobe_filter_arg",
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
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 392,
            "name": "generic_retkprobe_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 401,
            "name": "generic_retkprobe_actions",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 406,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "407": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 407,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 409,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "410": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 410,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 411,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 412,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 413,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 414,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "415": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 415,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 416,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 417,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 419,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 424,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 428,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 1459.533062054934,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 431,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 983,
            "run_time_ns_delta": 1434721,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 434,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 435,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 436,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "437": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 437,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "438": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 438,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "439": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 439,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "440": {
            "avg_ns_per_run": 478.68671087987946,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 440,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 1423104,
            "run_time_ns_delta": 681220973,
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
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 442,
            "name": "generic_rawtp_setup_event",
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
            "avg_ns_per_run": 1384.7293997965412,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 444,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 983,
            "run_time_ns_delta": 1361189,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 447,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "448": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 448,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "449": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 449,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 825.9061637534498,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 451,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1087,
            "run_time_ns_delta": 897760,
            "type": "kprobe"
          },
          "452": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 452,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 456,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "457": {
            "avg_ns_per_run": 2661.7894686635505,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 457,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 52415,
            "run_time_ns_delta": 139517695,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 459,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 461,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 462,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 463,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "464": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 464,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 467,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "468": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 468,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 469,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 471,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "472": {
            "avg_ns_per_run": 714.2404021937842,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 472,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1094,
            "run_time_ns_delta": 781379,
            "type": "kprobe"
          },
          "473": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 473,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "474": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 474,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "475": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 475,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "476": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 476,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "477": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 477,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "478": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 478,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "479": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 479,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "480": {
            "avg_ns_per_run": 593.0859232175503,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 480,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1094,
            "run_time_ns_delta": 648836,
            "type": "kprobe"
          },
          "481": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 481,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 483,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "484": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 484,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "485": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 485,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "486": {
            "avg_ns_per_run": 667.9262166405024,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 486,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1911,
            "run_time_ns_delta": 1276407,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 488,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "489": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 489,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "490": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 490,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "491": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 491,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 398.3823945963613,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 493,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 9179,
            "run_time_ns_delta": 3656752,
            "type": "kprobe"
          },
          "494": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 494,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "495": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 495,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "496": {
            "avg_ns_per_run": 705.8859527121001,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 496,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2157,
            "run_time_ns_delta": 1522596,
            "type": "kprobe"
          },
          "497": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 497,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 498,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 501,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 503,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "504": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 504,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "505": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 505,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "506": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 506,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 680.5589600742804,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 508,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1077,
            "run_time_ns_delta": 732962,
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
            "avg_ns_per_run": 601.0622098421542,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 510,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1077,
            "run_time_ns_delta": 647344,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 511,
            "name": "generic_retkprobe_output",
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
            "avg_ns_per_run": 833.4962894248608,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 513,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1078,
            "run_time_ns_delta": 898509,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 514,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 517,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 518,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 520,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 521,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 522,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 792.3273064441354,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 524,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2157,
            "run_time_ns_delta": 1709050,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 526,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 529,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "530": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 530,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 531,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "532": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 532,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 533,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "534": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 534,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 536,
            "name": "generic_kprobe_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 538,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 539,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "540": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 540,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.530725152999821,
            "ops_per_sec": 925.8215959258558,
            "ops_total": 2343.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [15035] setting to a 1 secs run per stressor\nstress-ng: info:  [15035] dispatching hogs: 2 exec\nstress-ng: info:  [15035] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [15035] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15035]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15035] exec               1265      1.05      2.59      0.86      1208.97         366.70\nstress-ng: info:  [15035] skipped: 0\nstress-ng: info:  [15035] passed: 2: exec (2)\nstress-ng: info:  [15035] failed: 0\nstress-ng: info:  [15035] metrics untrustworthy: 0\nstress-ng: info:  [15035] successful run completed in 1.05 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "251": {
            "avg_ns_per_run": 507.7506404782237,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 251,
            "name": "event_exit_acct",
            "run_cnt_delta": 1171,
            "run_time_ns_delta": 594576,
            "type": "kprobe"
          },
          "253": {
            "avg_ns_per_run": 756.6427758816837,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 253,
            "name": "event_wake_up_n",
            "run_cnt_delta": 1758,
            "run_time_ns_delta": 1330178,
            "type": "kprobe"
          },
          "254": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 254,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "255": {
            "avg_ns_per_run": 2781.9197396963123,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 255,
            "name": "event_execve",
            "run_cnt_delta": 922,
            "run_time_ns_delta": 2564930,
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
            "avg_ns_per_run": 298.6344902386117,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 257,
            "name": "tg_kp_bprm_comm",
            "run_cnt_delta": 922,
            "run_time_ns_delta": 275341,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 261,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 262,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 264,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "265": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 265,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 266,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "267": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 267,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "268": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 268,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 269,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 270,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 271,
            "name": "generic_kprobe_",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 274,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "275": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 275,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 276,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 1550.4642857142858,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 278,
            "name": "generic_kprobe_",
            "run_cnt_delta": 28,
            "run_time_ns_delta": 43413,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 279,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 280,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 281,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "282": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 282,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 283,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 285,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 286,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 287,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": 586.099358974359,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 288,
            "name": "generic_kprobe_",
            "run_cnt_delta": 312,
            "run_time_ns_delta": 182863,
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 290,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": 471.3333333333333,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 291,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 312,
            "run_time_ns_delta": 147056,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 292,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 293,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 578.2362948960302,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 295,
            "name": "generic_kprobe_",
            "run_cnt_delta": 529,
            "run_time_ns_delta": 305887,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 298,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 299,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 300,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": 526.2645046117227,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 301,
            "name": "generic_kprobe_",
            "run_cnt_delta": 3361,
            "run_time_ns_delta": 1768775,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 302,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 303,
            "name": "generic_kprobe_",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 305,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 309,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
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
            "avg_ns_per_run": 592.3974358974359,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 313,
            "name": "generic_kprobe_",
            "run_cnt_delta": 312,
            "run_time_ns_delta": 184828,
            "type": "kprobe"
          },
          "314": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 314,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "315": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 315,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "316": {
            "avg_ns_per_run": 552.3878205128206,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 316,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 312,
            "run_time_ns_delta": 172345,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 317,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 319,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "320": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 320,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "321": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 321,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 322,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "323": {
            "avg_ns_per_run": 601.867674858223,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 323,
            "name": "generic_kprobe_",
            "run_cnt_delta": 529,
            "run_time_ns_delta": 318388,
            "type": "kprobe"
          },
          "324": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 324,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 325,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "326": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 326,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "327": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 327,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 328,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "329": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 329,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 330,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "331": {
            "avg_ns_per_run": 583.8467455621302,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 331,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1690,
            "run_time_ns_delta": 986701,
            "type": "kprobe"
          },
          "332": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 332,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 334,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 335,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 336,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "avg_ns_per_run": 635.0576623376624,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 337,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1925,
            "run_time_ns_delta": 1222486,
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 339,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "340": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 340,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "341": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 341,
            "name": "generic_kprobe_",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 344,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 346,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 349,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "350": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 350,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 353,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "354": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 354,
            "name": "generic_kprobe_",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 356,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "357": {
            "avg_ns_per_run": 296.060568793236,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 357,
            "name": "generic_kprobe_",
            "run_cnt_delta": 39030,
            "run_time_ns_delta": 11555244,
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 359,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 360,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "361": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 361,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 363,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "364": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 364,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "365": {
            "avg_ns_per_run": 490.5030080683703,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 365,
            "name": "generic_kprobe_",
            "run_cnt_delta": 142284,
            "run_time_ns_delta": 69790730,
            "type": "kprobe"
          },
          "366": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
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
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 369,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "370": {
            "avg_ns_per_run": 40.5064481197086,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 370,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 142212,
            "run_time_ns_delta": 5760503,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 372,
            "name": "generic_kprobe_",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 374,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "375": {
            "avg_ns_per_run": 982.7800319161995,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 375,
            "name": "generic_kprobe_",
            "run_cnt_delta": 122195,
            "run_time_ns_delta": 120090806,
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 378,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 49.58483571340889,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 380,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 122195,
            "run_time_ns_delta": 6059019,
            "type": "kprobe"
          },
          "381": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 381,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "382": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 382,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 386,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 389,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 390,
            "name": "generic_retkprobe_filter_arg",
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
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 392,
            "name": "generic_retkprobe_event",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 394,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 396,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 401,
            "name": "generic_retkprobe_actions",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 404,
            "name": "generic_kprobe_",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 406,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "407": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 407,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 409,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "410": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 410,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 411,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 412,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 413,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 414,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "415": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 415,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 416,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 417,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 419,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 422,
            "name": "generic_kprobe_",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 424,
            "name": "generic_kprobe_actions",
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
            "name": "generic_kprobe_",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 428,
            "name": "generic_kprobe_",
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
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "avg_ns_per_run": 1509.9240780911064,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 431,
            "name": "generic_kprobe_",
            "run_cnt_delta": 922,
            "run_time_ns_delta": 1392150,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 434,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 435,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 436,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "437": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 437,
            "name": "generic_tracepo",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "438": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 438,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "439": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 439,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "440": {
            "avg_ns_per_run": 477.99574878571724,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 440,
            "name": "generic_tracepo",
            "run_cnt_delta": 1326915,
            "run_time_ns_delta": 634259729,
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
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 442,
            "name": "generic_rawtp_s",
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
            "avg_ns_per_run": 1542.4913232104122,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 444,
            "name": "generic_rawtp_e",
            "run_cnt_delta": 922,
            "run_time_ns_delta": 1422177,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 447,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "448": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 448,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "449": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 449,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": 692.6118421052631,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 451,
            "name": "generic_kprobe_",
            "run_cnt_delta": 304,
            "run_time_ns_delta": 210554,
            "type": "kprobe"
          },
          "452": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 452,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 454,
            "name": "generic_kprobe_",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 456,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "457": {
            "avg_ns_per_run": 2683.191665653742,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 457,
            "name": "generic_kprobe_",
            "run_cnt_delta": 49362,
            "run_time_ns_delta": 132447707,
            "type": "kprobe"
          },
          "458": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 458,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "459": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
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
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 462,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 463,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "464": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 464,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 467,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "468": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 468,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 469,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 471,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "472": {
            "avg_ns_per_run": 630.7371794871794,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 472,
            "name": "generic_kprobe_",
            "run_cnt_delta": 312,
            "run_time_ns_delta": 196790,
            "type": "kprobe"
          },
          "473": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 473,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "474": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 474,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "475": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 475,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "476": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 476,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "477": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 477,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "478": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 478,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "479": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 479,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "480": {
            "avg_ns_per_run": 539.9423076923077,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 480,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 312,
            "run_time_ns_delta": 168462,
            "type": "kprobe"
          },
          "481": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 481,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 483,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "484": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 484,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "485": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 485,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "486": {
            "avg_ns_per_run": 679.750472589792,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 486,
            "name": "generic_kprobe_",
            "run_cnt_delta": 529,
            "run_time_ns_delta": 359588,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 488,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "489": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 489,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "490": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 490,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "491": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 491,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": 407.6293034427542,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 493,
            "name": "generic_kprobe_",
            "run_cnt_delta": 2498,
            "run_time_ns_delta": 1018258,
            "type": "kprobe"
          },
          "494": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 494,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "495": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 495,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "496": {
            "avg_ns_per_run": 678.9627749576988,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 496,
            "name": "generic_kprobe_",
            "run_cnt_delta": 591,
            "run_time_ns_delta": 401267,
            "type": "kprobe"
          },
          "497": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 497,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 498,
            "name": "generic_kprobe_",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 501,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 503,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "504": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 504,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "505": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 505,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "506": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 506,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 508.07142857142856,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 508,
            "name": "generic_kprobe_",
            "run_cnt_delta": 294,
            "run_time_ns_delta": 149373,
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
            "avg_ns_per_run": 488.3741496598639,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 510,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 294,
            "run_time_ns_delta": 143582,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 511,
            "name": "generic_retkpro",
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
            "avg_ns_per_run": 720.8779661016949,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 513,
            "name": "generic_kprobe_",
            "run_cnt_delta": 295,
            "run_time_ns_delta": 212659,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 514,
            "name": "generic_kprobe_",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 517,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 518,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 520,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 521,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 522,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": 762.4010152284264,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 524,
            "name": "generic_kprobe_",
            "run_cnt_delta": 591,
            "run_time_ns_delta": 450579,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 526,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 529,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "530": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 530,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 531,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "532": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 532,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 533,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "534": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 534,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "535": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 535,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "536": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 536,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 538,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 539,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "540": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 540,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.470298651999883,
            "ops_per_sec": 591.8312746583927,
            "ops_total": 1462.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [1746] setting to a 1 secs run per stressor\nstress-ng: info:  [1746] dispatching hogs: 2 exec\nstress-ng: info:  [1746] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [1746] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1746]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1746] exec               1167      1.06      2.45      0.85      1102.61         353.62\nstress-ng: info:  [1746] skipped: 0\nstress-ng: info:  [1746] passed: 2: exec (2)\nstress-ng: info:  [1746] failed: 0\nstress-ng: info:  [1746] metrics untrustworthy: 0\nstress-ng: info:  [1746] successful run completed in 1.10 secs"
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
        "output_chars": 3618473,
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
            "avg_ns_per_run": 46.8046875,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 553,
            "name": "balancer_ingress",
            "run_cnt_delta": 1152,
            "run_time_ns_delta": 53919,
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
            "duration_s": 1.0375434259999565,
            "ops_per_sec": 1110.3149720116373,
            "ops_total": 1152.0,
            "stderr": "{'retval': 2, 'duration_ns': 71, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
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
            "avg_ns_per_run": 47.4130859375,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 553,
            "name": "balancer_ingress",
            "run_cnt_delta": 1024,
            "run_time_ns_delta": 48551,
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
            "duration_s": 1.012056168000072,
            "ops_per_sec": 1011.8015505241476,
            "ops_total": 1024.0,
            "stderr": "{'retval': 2, 'duration_ns': 71, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
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
        "output_chars": 89604,
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
      "app": "tracee/default",
      "baseline": {
        "bpf": {
          "570": {
            "avg_ns_per_run": 158.88717836993072,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 570,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 2620907,
            "run_time_ns_delta": 416428518,
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
            "avg_ns_per_run": 377.21737798258744,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 573,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 2620753,
            "run_time_ns_delta": 988593575,
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
            "avg_ns_per_run": 337.2459775527524,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 576,
            "name": "trace_sys_enter",
            "run_cnt_delta": 2620544,
            "run_time_ns_delta": 883767923,
            "type": "raw_tracepoint"
          },
          "577": {
            "avg_ns_per_run": 319.21441696053745,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 577,
            "name": "trace_sys_exit",
            "run_cnt_delta": 2620483,
            "run_time_ns_delta": 836495953,
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
            "avg_ns_per_run": 1129.3934426229507,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 582,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 206679,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": 1736.360655737705,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 583,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 317754,
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
            "avg_ns_per_run": 1092.1467391304348,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 586,
            "name": "trace_dup2",
            "run_cnt_delta": 184,
            "run_time_ns_delta": 200955,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 2499.788043478261,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 587,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 184,
            "run_time_ns_delta": 459961,
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
            "avg_ns_per_run": 4177.714808043876,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 595,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 547,
            "run_time_ns_delta": 2285210,
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
            "avg_ns_per_run": 4774.9890710382515,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 603,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 873823,
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
            "avg_ns_per_run": 1654.3254113345522,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 605,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 547,
            "run_time_ns_delta": 904916,
            "type": "raw_tracepoint"
          },
          "606": {
            "avg_ns_per_run": 979.0676416819013,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 606,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 547,
            "run_time_ns_delta": 535550,
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
            "avg_ns_per_run": 276.3082257195566,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 608,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 245012,
            "run_time_ns_delta": 67698831,
            "type": "raw_tracepoint"
          },
          "609": {
            "avg_ns_per_run": 19.463054187192117,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 609,
            "name": "trace_filldir64",
            "run_cnt_delta": 203,
            "run_time_ns_delta": 3951,
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
            "avg_ns_per_run": 1300.0621572212067,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 611,
            "name": "trace_do_exit",
            "run_cnt_delta": 547,
            "run_time_ns_delta": 711134,
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
            "avg_ns_per_run": 818.7459016393443,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 615,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 366,
            "run_time_ns_delta": 299661,
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
            "avg_ns_per_run": 1759.0,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 618,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1759,
            "type": "raw_tracepoint"
          },
          "619": {
            "avg_ns_per_run": 1112.0,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 619,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1112,
            "type": "raw_tracepoint"
          },
          "620": {
            "avg_ns_per_run": 3180.896174863388,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 620,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 582104,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": 1433.9676549865228,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 621,
            "name": "trace_security_file_open",
            "run_cnt_delta": 2597,
            "run_time_ns_delta": 3724014,
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
            "avg_ns_per_run": 2799.0,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 623,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2799,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": 1394.4207650273224,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 624,
            "name": "trace_commit_creds",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 255179,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": 992.946983546618,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 625,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 547,
            "run_time_ns_delta": 543142,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 153.19643212313153,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 626,
            "name": "trace_cap_capable",
            "run_cnt_delta": 65361,
            "run_time_ns_delta": 10013072,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 902.6433470507544,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 627,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 729,
            "run_time_ns_delta": 658027,
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
            "avg_ns_per_run": 1849.3131868131868,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 632,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 182,
            "run_time_ns_delta": 336575,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": 1578.989010989011,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 633,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 182,
            "run_time_ns_delta": 287376,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 2175.263768115942,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 634,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 345,
            "run_time_ns_delta": 750466,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 1689.2841530054645,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 635,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 309139,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": 1870.3186813186812,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 636,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 182,
            "run_time_ns_delta": 340398,
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
            "avg_ns_per_run": 64.34462721640675,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 639,
            "name": "trace_vfs_write",
            "run_cnt_delta": 70215,
            "run_time_ns_delta": 4517958,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": 34.5503702648818,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 640,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 70220,
            "run_time_ns_delta": 2426127,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": 29.80034173430158,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 641,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 70230,
            "run_time_ns_delta": 2092878,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": 44.58112707748836,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 642,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 70217,
            "run_time_ns_delta": 3130353,
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
            "avg_ns_per_run": 131.5520343367827,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 654,
            "name": "trace_vfs_read",
            "run_cnt_delta": 17008,
            "run_time_ns_delta": 2237437,
            "type": "kprobe"
          },
          "655": {
            "avg_ns_per_run": 372.66396396396397,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 655,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 1110,
            "run_time_ns_delta": 413657,
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
            "avg_ns_per_run": 191.2683673469388,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 660,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 3920,
            "run_time_ns_delta": 749772,
            "type": "kprobe"
          },
          "661": {
            "avg_ns_per_run": 129.8432122370937,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 661,
            "name": "trace_do_mmap",
            "run_cnt_delta": 3138,
            "run_time_ns_delta": 407448,
            "type": "kprobe"
          },
          "662": {
            "avg_ns_per_run": 57.820905035054174,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 662,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 3138,
            "run_time_ns_delta": 181442,
            "type": "kprobe"
          },
          "663": {
            "avg_ns_per_run": 927.0407903123008,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 663,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 3138,
            "run_time_ns_delta": 2909054,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 1492.3068592057762,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 664,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 554,
            "run_time_ns_delta": 826738,
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
            "avg_ns_per_run": 395.4461829823691,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 666,
            "name": "trace_security_bpf",
            "run_cnt_delta": 22177,
            "run_time_ns_delta": 8769810,
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
            "avg_ns_per_run": 317.03651373233845,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 669,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 6299,
            "run_time_ns_delta": 1997013,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 1080.998076923077,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 670,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 520,
            "run_time_ns_delta": 562119,
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
            "avg_ns_per_run": 1645.308743169399,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 684,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 366,
            "run_time_ns_delta": 602183,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 36.97963710126836,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 685,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 89722,
            "run_time_ns_delta": 3317887,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 2092.896174863388,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 686,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 383000,
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
            "avg_ns_per_run": 721.2857142857143,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 690,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 45441,
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
            "avg_ns_per_run": 2760.4309392265195,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 693,
            "name": "trace_do_truncate",
            "run_cnt_delta": 181,
            "run_time_ns_delta": 499638,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 311.10320752807854,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 694,
            "name": "trace_fd_install",
            "run_cnt_delta": 9883,
            "run_time_ns_delta": 3074633,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": 770.4950053705693,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 695,
            "name": "trace_filp_close",
            "run_cnt_delta": 18620,
            "run_time_ns_delta": 14346617,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": 830.5494505494505,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 696,
            "name": "trace_file_update_time",
            "run_cnt_delta": 182,
            "run_time_ns_delta": 151160,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": 190.67032967032966,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 697,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 182,
            "run_time_ns_delta": 34702,
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
            "avg_ns_per_run": 163.30054644808743,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 703,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 29884,
            "type": "kprobe"
          },
          "704": {
            "avg_ns_per_run": 4404.207650273224,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 704,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 805970,
            "type": "kprobe"
          },
          "705": {
            "avg_ns_per_run": 3101.3397260273973,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 705,
            "name": "trace_execute_finished",
            "run_cnt_delta": 365,
            "run_time_ns_delta": 1131989,
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
            "avg_ns_per_run": 2652.0,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 707,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2652,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": 1719.375,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 708,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 13755,
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
            "avg_ns_per_run": 921.8333333333334,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 711,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 5531,
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
            "avg_ns_per_run": 377.7783985102421,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 714,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 1074,
            "run_time_ns_delta": 405734,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": 1097.195530726257,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 715,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 1074,
            "run_time_ns_delta": 1178388,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": 1525.010989010989,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 716,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 182,
            "run_time_ns_delta": 277552,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": 225.05820105820106,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 717,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 189,
            "run_time_ns_delta": 42536,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 522.4054054054054,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 718,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 96645,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 1196.5821167883212,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 719,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 2192,
            "run_time_ns_delta": 2622908,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 1275.4446460980037,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 721,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 1102,
            "run_time_ns_delta": 1405540,
            "type": "cgroup_skb"
          },
          "722": {
            "avg_ns_per_run": 1721.8522212148685,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 722,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 1103,
            "run_time_ns_delta": 1899203,
            "type": "cgroup_skb"
          },
          "723": {
            "avg_ns_per_run": 2082.0,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 723,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2082,
            "type": "raw_tracepoint"
          },
          "724": {
            "avg_ns_per_run": 409.0,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 724,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 409,
            "type": "raw_tracepoint"
          },
          "725": {
            "avg_ns_per_run": 140.10928961748633,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 725,
            "name": "empty_kprobe",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 25640,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": 858.5901639344262,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 726,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 157122,
            "type": "raw_tracepoint"
          },
          "727": {
            "avg_ns_per_run": 685.8427139552814,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 727,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 2594,
            "run_time_ns_delta": 1779076,
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
            "duration_s": 5.0054876300000615,
            "ops_per_sec": 36.36009385163494,
            "ops_total": 182.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "prog 665: BPF_PROG_REJIT: Invalid argument (os error 22)",
      "post_rejit": {
        "bpf": {
          "570": {
            "avg_ns_per_run": 162.1441059600724,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 570,
            "name": "tracepoint__raw",
            "run_cnt_delta": 2752433,
            "run_time_ns_delta": 446290788,
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
            "avg_ns_per_run": 370.3818044554437,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 573,
            "name": "tracepoint__raw",
            "run_cnt_delta": 2752498,
            "run_time_ns_delta": 1019475176,
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
            "avg_ns_per_run": 336.977965775966,
            "bytes_jited": 8131,
            "bytes_xlated": 13608,
            "id": 576,
            "name": "trace_sys_enter",
            "run_cnt_delta": 2752627,
            "run_time_ns_delta": 927574647,
            "type": "raw_tracepoint"
          },
          "577": {
            "avg_ns_per_run": 310.36474675823365,
            "bytes_jited": 8164,
            "bytes_xlated": 13664,
            "id": 577,
            "name": "trace_sys_exit",
            "run_cnt_delta": 2752666,
            "run_time_ns_delta": 854330486,
            "type": "raw_tracepoint"
          },
          "578": {
            "avg_ns_per_run": null,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 578,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": null,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 579,
            "name": "trace_ret_ptrac",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": null,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 580,
            "name": "trace_process_v",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": null,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 581,
            "name": "trace_ret_proce",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": 1256.464480874317,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 582,
            "name": "trace_arch_prct",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 229933,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": 1857.5027322404371,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 583,
            "name": "trace_ret_arch_",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 339923,
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
            "avg_ns_per_run": 1089.608695652174,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 586,
            "name": "trace_dup2",
            "run_cnt_delta": 184,
            "run_time_ns_delta": 200488,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 2572.6304347826085,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 587,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 184,
            "run_time_ns_delta": 473364,
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
            "avg_ns_per_run": 4429.358318098721,
            "bytes_jited": 19847,
            "bytes_xlated": 32320,
            "id": 595,
            "name": "tracepoint__sch",
            "run_cnt_delta": 547,
            "run_time_ns_delta": 2422859,
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
            "avg_ns_per_run": 4665.11475409836,
            "bytes_jited": 20525,
            "bytes_xlated": 35336,
            "id": 603,
            "name": "tracepoint__sch",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 853716,
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
            "avg_ns_per_run": 1528.1462522851918,
            "bytes_jited": 8680,
            "bytes_xlated": 14464,
            "id": 605,
            "name": "tracepoint__sch",
            "run_cnt_delta": 547,
            "run_time_ns_delta": 835896,
            "type": "raw_tracepoint"
          },
          "606": {
            "avg_ns_per_run": 1010.3418647166362,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 606,
            "name": "tracepoint__sch",
            "run_cnt_delta": 547,
            "run_time_ns_delta": 552657,
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
            "avg_ns_per_run": 268.4511626198435,
            "bytes_jited": 8925,
            "bytes_xlated": 14840,
            "id": 608,
            "name": "tracepoint__sch",
            "run_cnt_delta": 272230,
            "run_time_ns_delta": 73080460,
            "type": "raw_tracepoint"
          },
          "609": {
            "avg_ns_per_run": 23.244979919678716,
            "bytes_jited": 8163,
            "bytes_xlated": 13680,
            "id": 609,
            "name": "trace_filldir64",
            "run_cnt_delta": 249,
            "run_time_ns_delta": 5788,
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
            "avg_ns_per_run": 1173.63802559415,
            "bytes_jited": 7921,
            "bytes_xlated": 13312,
            "id": 611,
            "name": "trace_do_exit",
            "run_cnt_delta": 547,
            "run_time_ns_delta": 641980,
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
            "avg_ns_per_run": 768.4371584699453,
            "bytes_jited": 11470,
            "bytes_xlated": 18264,
            "id": 615,
            "name": "trace_security_",
            "run_cnt_delta": 366,
            "run_time_ns_delta": 281248,
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
            "avg_ns_per_run": null,
            "bytes_jited": 8620,
            "bytes_xlated": 14352,
            "id": 617,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "618": {
            "avg_ns_per_run": 1703.0,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 618,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1703,
            "type": "raw_tracepoint"
          },
          "619": {
            "avg_ns_per_run": 1553.0,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 619,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1553,
            "type": "raw_tracepoint"
          },
          "620": {
            "avg_ns_per_run": 3200.726775956284,
            "bytes_jited": 33373,
            "bytes_xlated": 52824,
            "id": 620,
            "name": "trace_security_",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 585733,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": 1348.6493891151426,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 621,
            "name": "trace_security_file_open",
            "run_cnt_delta": 2701,
            "run_time_ns_delta": 3642702,
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
            "avg_ns_per_run": 3471.0,
            "bytes_jited": 9984,
            "bytes_xlated": 16352,
            "id": 623,
            "name": "trace_security_",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3471,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": 1443.6284153005465,
            "bytes_jited": 10723,
            "bytes_xlated": 16880,
            "id": 624,
            "name": "trace_commit_cr",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 264184,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": 1113.3162705667276,
            "bytes_jited": 10045,
            "bytes_xlated": 16520,
            "id": 625,
            "name": "trace_switch_ta",
            "run_cnt_delta": 547,
            "run_time_ns_delta": 608984,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 156.13797047685293,
            "bytes_jited": 8174,
            "bytes_xlated": 13680,
            "id": 626,
            "name": "trace_cap_capab",
            "run_cnt_delta": 64695,
            "run_time_ns_delta": 10101346,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 928.4986263736264,
            "bytes_jited": 8471,
            "bytes_xlated": 14120,
            "id": 627,
            "name": "trace_security_",
            "run_cnt_delta": 728,
            "run_time_ns_delta": 675947,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": null,
            "bytes_jited": 9144,
            "bytes_xlated": 15208,
            "id": 628,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 1692.1593406593406,
            "bytes_jited": 10780,
            "bytes_xlated": 16456,
            "id": 632,
            "name": "trace_security_",
            "run_cnt_delta": 182,
            "run_time_ns_delta": 307973,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": 1594.3186813186812,
            "bytes_jited": 10075,
            "bytes_xlated": 15400,
            "id": 633,
            "name": "trace_security_",
            "run_cnt_delta": 182,
            "run_time_ns_delta": 290166,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 2097.7891737891737,
            "bytes_jited": 11260,
            "bytes_xlated": 17192,
            "id": 634,
            "name": "trace_security_",
            "run_cnt_delta": 351,
            "run_time_ns_delta": 736324,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 1657.8516483516485,
            "bytes_jited": 10589,
            "bytes_xlated": 16080,
            "id": 635,
            "name": "trace_security_",
            "run_cnt_delta": 182,
            "run_time_ns_delta": 301729,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": 1813.4120879120878,
            "bytes_jited": 11025,
            "bytes_xlated": 16864,
            "id": 636,
            "name": "trace_security_",
            "run_cnt_delta": 182,
            "run_time_ns_delta": 330041,
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
            "avg_ns_per_run": 67.14866216911554,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 639,
            "name": "trace_vfs_write",
            "run_cnt_delta": 69964,
            "run_time_ns_delta": 4697989,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": 37.02421279819333,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 640,
            "name": "vfs_write_magic",
            "run_cnt_delta": 69963,
            "run_time_ns_delta": 2590325,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": 136.65693295556474,
            "bytes_jited": 19108,
            "bytes_xlated": 31720,
            "id": 641,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 70237,
            "run_time_ns_delta": 9598373,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": 50.753622569533405,
            "bytes_jited": 23757,
            "bytes_xlated": 36648,
            "id": 642,
            "name": "vfs_write_magic",
            "run_cnt_delta": 70254,
            "run_time_ns_delta": 3565645,
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
            "name": "trace_vfs_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 645,
            "name": "vfs_writev_magi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": null,
            "bytes_jited": 19107,
            "bytes_xlated": 31712,
            "id": 646,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "647": {
            "avg_ns_per_run": null,
            "bytes_jited": 23786,
            "bytes_xlated": 36696,
            "id": 647,
            "name": "vfs_writev_magi",
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
            "avg_ns_per_run": 146.26070623591283,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 654,
            "name": "trace_vfs_read",
            "run_cnt_delta": 15972,
            "run_time_ns_delta": 2336076,
            "type": "kprobe"
          },
          "655": {
            "avg_ns_per_run": 965.4282516786869,
            "bytes_jited": 19111,
            "bytes_xlated": 31720,
            "id": 655,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 4021,
            "run_time_ns_delta": 3881987,
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
            "bytes_jited": 19107,
            "bytes_xlated": 31712,
            "id": 658,
            "name": "trace_ret_vfs_r",
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
            "avg_ns_per_run": 207.6771048744461,
            "bytes_jited": 20715,
            "bytes_xlated": 32736,
            "id": 660,
            "name": "trace_mmap_aler",
            "run_cnt_delta": 3385,
            "run_time_ns_delta": 702987,
            "type": "kprobe"
          },
          "661": {
            "avg_ns_per_run": 128.67644246094994,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 661,
            "name": "trace_do_mmap",
            "run_cnt_delta": 3137,
            "run_time_ns_delta": 403658,
            "type": "kprobe"
          },
          "662": {
            "avg_ns_per_run": 691.4842205929232,
            "bytes_jited": 19426,
            "bytes_xlated": 31584,
            "id": 662,
            "name": "trace_ret_do_mm",
            "run_cnt_delta": 3137,
            "run_time_ns_delta": 2169186,
            "type": "kprobe"
          },
          "663": {
            "avg_ns_per_run": 869.6764424609499,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 663,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 3137,
            "run_time_ns_delta": 2728175,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 1467.0090252707582,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 664,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 554,
            "run_time_ns_delta": 812723,
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
            "avg_ns_per_run": 411.7252447074892,
            "bytes_jited": 15585,
            "bytes_xlated": 26904,
            "id": 666,
            "name": "trace_security_",
            "run_cnt_delta": 21965,
            "run_time_ns_delta": 9043545,
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
            "avg_ns_per_run": 350.1340909090909,
            "bytes_jited": 8333,
            "bytes_xlated": 13904,
            "id": 669,
            "name": "trace_security_",
            "run_cnt_delta": 6160,
            "run_time_ns_delta": 2156826,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 1108.178846153846,
            "bytes_jited": 9581,
            "bytes_xlated": 15448,
            "id": 670,
            "name": "trace_security_",
            "run_cnt_delta": 520,
            "run_time_ns_delta": 576253,
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
            "avg_ns_per_run": null,
            "bytes_jited": 18641,
            "bytes_xlated": 30648,
            "id": 674,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "675": {
            "avg_ns_per_run": null,
            "bytes_jited": 17247,
            "bytes_xlated": 30448,
            "id": 675,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "676": {
            "avg_ns_per_run": null,
            "bytes_jited": 9225,
            "bytes_xlated": 15352,
            "id": 676,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": null,
            "bytes_jited": 19868,
            "bytes_xlated": 32648,
            "id": 680,
            "name": "tracepoint__mod",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "681": {
            "avg_ns_per_run": null,
            "bytes_jited": 8959,
            "bytes_xlated": 14920,
            "id": 681,
            "name": "tracepoint__mod",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "682": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 682,
            "name": "trace_do_init_m",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "683": {
            "avg_ns_per_run": null,
            "bytes_jited": 14542,
            "bytes_xlated": 23904,
            "id": 683,
            "name": "trace_ret_do_in",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "684": {
            "avg_ns_per_run": 1605.8825136612022,
            "bytes_jited": 18482,
            "bytes_xlated": 30352,
            "id": 684,
            "name": "trace_load_elf_",
            "run_cnt_delta": 366,
            "run_time_ns_delta": 587753,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 37.41515202607767,
            "bytes_jited": 8681,
            "bytes_xlated": 14496,
            "id": 685,
            "name": "trace_security_",
            "run_cnt_delta": 88965,
            "run_time_ns_delta": 3328639,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 2640.8579234972676,
            "bytes_jited": 8474,
            "bytes_xlated": 14112,
            "id": 686,
            "name": "tracepoint__tas",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 483277,
            "type": "raw_tracepoint"
          },
          "687": {
            "avg_ns_per_run": null,
            "bytes_jited": 9792,
            "bytes_xlated": 16344,
            "id": 687,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 717.3809523809524,
            "bytes_jited": 10109,
            "bytes_xlated": 16296,
            "id": 690,
            "name": "trace_do_sigact",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 45195,
            "type": "kprobe"
          },
          "691": {
            "avg_ns_per_run": null,
            "bytes_jited": 18560,
            "bytes_xlated": 30528,
            "id": 691,
            "name": "trace_vfs_utime",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 2630.3591160220994,
            "bytes_jited": 9530,
            "bytes_xlated": 15824,
            "id": 693,
            "name": "trace_do_trunca",
            "run_cnt_delta": 181,
            "run_time_ns_delta": 476095,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 335.4458128078818,
            "bytes_jited": 16708,
            "bytes_xlated": 27176,
            "id": 694,
            "name": "trace_fd_instal",
            "run_cnt_delta": 9338,
            "run_time_ns_delta": 3132393,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": 790.396992481203,
            "bytes_jited": 16636,
            "bytes_xlated": 27024,
            "id": 695,
            "name": "trace_filp_clos",
            "run_cnt_delta": 18620,
            "run_time_ns_delta": 14717192,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": 933.8978494623656,
            "bytes_jited": 459,
            "bytes_xlated": 768,
            "id": 696,
            "name": "trace_file_upda",
            "run_cnt_delta": 186,
            "run_time_ns_delta": 173705,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": 335.05913978494624,
            "bytes_jited": 20054,
            "bytes_xlated": 31168,
            "id": 697,
            "name": "trace_ret_file_",
            "run_cnt_delta": 186,
            "run_time_ns_delta": 62321,
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
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 700,
            "name": "trace_inotify_f",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "701": {
            "avg_ns_per_run": null,
            "bytes_jited": 18025,
            "bytes_xlated": 29936,
            "id": 701,
            "name": "trace_ret_inoti",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 300.1639344262295,
            "bytes_jited": 16472,
            "bytes_xlated": 28872,
            "id": 703,
            "name": "trace_exec_binp",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 54930,
            "type": "kprobe"
          },
          "704": {
            "avg_ns_per_run": 4296.158469945355,
            "bytes_jited": 16702,
            "bytes_xlated": 29144,
            "id": 704,
            "name": "trace_security_",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 786197,
            "type": "kprobe"
          },
          "705": {
            "avg_ns_per_run": 3297.3150684931506,
            "bytes_jited": 24469,
            "bytes_xlated": 38320,
            "id": 705,
            "name": "trace_execute_f",
            "run_cnt_delta": 365,
            "run_time_ns_delta": 1203520,
            "type": "kprobe"
          },
          "706": {
            "avg_ns_per_run": null,
            "bytes_jited": 18391,
            "bytes_xlated": 30200,
            "id": 706,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": 2881.0,
            "bytes_jited": 18194,
            "bytes_xlated": 29912,
            "id": 707,
            "name": "trace_set_fs_pw",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2881,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": 1023.0,
            "bytes_jited": 8631,
            "bytes_xlated": 14360,
            "id": 708,
            "name": "trace_security_",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 6138,
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
            "avg_ns_per_run": null,
            "bytes_jited": 17561,
            "bytes_xlated": 29176,
            "id": 710,
            "name": "trace_chmod_com",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "711": {
            "avg_ns_per_run": 984.3333333333334,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 711,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 5906,
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
            "avg_ns_per_run": 352.21779425393885,
            "bytes_jited": 329,
            "bytes_xlated": 520,
            "id": 714,
            "name": "trace_sock_allo",
            "run_cnt_delta": 1079,
            "run_time_ns_delta": 380043,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": 1221.9416126042631,
            "bytes_jited": 8439,
            "bytes_xlated": 12928,
            "id": 715,
            "name": "trace_ret_sock_",
            "run_cnt_delta": 1079,
            "run_time_ns_delta": 1318475,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": 1547.5,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 716,
            "name": "trace_security_",
            "run_cnt_delta": 182,
            "run_time_ns_delta": 281645,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": 227.05263157894737,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 717,
            "name": "trace_security_",
            "run_cnt_delta": 190,
            "run_time_ns_delta": 43140,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 370.18279569892474,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 718,
            "name": "trace_security_",
            "run_cnt_delta": 186,
            "run_time_ns_delta": 68854,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 1279.266239707228,
            "bytes_jited": 5282,
            "bytes_xlated": 8136,
            "id": 719,
            "name": "cgroup_bpf_run_",
            "run_cnt_delta": 2186,
            "run_time_ns_delta": 2796476,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 1193.764116575592,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 721,
            "name": "cgroup_skb_ingr",
            "run_cnt_delta": 1098,
            "run_time_ns_delta": 1310753,
            "type": "cgroup_skb"
          },
          "722": {
            "avg_ns_per_run": 1675.8998178506374,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 722,
            "name": "cgroup_skb_egre",
            "run_cnt_delta": 1098,
            "run_time_ns_delta": 1840138,
            "type": "cgroup_skb"
          },
          "723": {
            "avg_ns_per_run": 2053.0,
            "bytes_jited": 916,
            "bytes_xlated": 1560,
            "id": 723,
            "name": "cgroup_mkdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2053,
            "type": "raw_tracepoint"
          },
          "724": {
            "avg_ns_per_run": 598.0,
            "bytes_jited": 898,
            "bytes_xlated": 1520,
            "id": 724,
            "name": "cgroup_rmdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 598,
            "type": "raw_tracepoint"
          },
          "725": {
            "avg_ns_per_run": 155.27322404371586,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 725,
            "name": "empty_kprobe",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 28415,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": 1003.4426229508197,
            "bytes_jited": 58660,
            "bytes_xlated": 95944,
            "id": 726,
            "name": "tracepoint__exe",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 183630,
            "type": "raw_tracepoint"
          },
          "727": {
            "avg_ns_per_run": 630.3581481481482,
            "bytes_jited": 7290,
            "bytes_xlated": 13264,
            "id": 727,
            "name": "lsm_file_open_t",
            "run_cnt_delta": 2700,
            "run_time_ns_delta": 1701967,
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
            "duration_s": 5.0256478419998984,
            "ops_per_sec": 36.214236596326096,
            "ops_total": 182.0,
            "stderr": "",
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
        "output_chars": 2254112,
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
            "avg_ns_per_run": 112.94650793989432,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 734,
            "name": "cap_capable",
            "run_cnt_delta": 140619,
            "run_time_ns_delta": 15882425,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0716456619999235,
            "ops_per_sec": 1045.1215730298734,
            "ops_total": 1120.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [17477] setting to a 1 secs run per stressor\nstress-ng: info:  [17477] dispatching hogs: 2 exec\nstress-ng: info:  [17477] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [17477] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [17477]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [17477] exec               1120      1.04      2.30      0.89      1074.68         351.65\nstress-ng: info:  [17477] skipped: 0\nstress-ng: info:  [17477] passed: 2: exec (2)\nstress-ng: info:  [17477] failed: 0\nstress-ng: info:  [17477] metrics untrustworthy: 0\nstress-ng: info:  [17477] successful run completed in 1.05 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "734": {
            "avg_ns_per_run": 107.37655019348144,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 734,
            "name": "cap_capable",
            "run_cnt_delta": 138773,
            "run_time_ns_delta": 14900966,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0918415410001217,
            "ops_per_sec": 1026.7057607765769,
            "ops_total": 1121.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [4225] setting to a 1 secs run per stressor\nstress-ng: info:  [4225] dispatching hogs: 2 exec\nstress-ng: info:  [4225] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4225] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4225]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4225] exec               1121      1.02      2.42      0.80      1094.92         348.58\nstress-ng: info:  [4225] skipped: 0\nstress-ng: info:  [4225] passed: 2: exec (2)\nstress-ng: info:  [4225] failed: 0\nstress-ng: info:  [4225] metrics untrustworthy: 0\nstress-ng: info:  [4225] successful run completed in 1.05 secs"
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
            "avg_ns_per_run": 157.0353913885566,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 740,
            "name": "block_io_start",
            "run_cnt_delta": 368649,
            "run_time_ns_delta": 57890940,
            "type": "tracepoint"
          },
          "741": {
            "avg_ns_per_run": 290.71443335602856,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 741,
            "name": "block_io_done",
            "run_cnt_delta": 368653,
            "run_time_ns_delta": 107172748,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.051604423000072,
            "ops_per_sec": 72974.83514773515,
            "ops_total": 368640.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "740": {
            "avg_ns_per_run": 162.41784057617187,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 740,
            "name": "block_io_start",
            "run_cnt_delta": 327680,
            "run_time_ns_delta": 53221078,
            "type": "tracepoint"
          },
          "741": {
            "avg_ns_per_run": 311.79926147460935,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 741,
            "name": "block_io_done",
            "run_cnt_delta": 327680,
            "run_time_ns_delta": 102170382,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.007816041000069,
            "ops_per_sec": 65433.71348252676,
            "ops_total": 327680.0,
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
            "avg_ns_per_run": 1257.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 747,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1257,
            "type": "perf_event"
          },
          "748": {
            "avg_ns_per_run": 43.03291151421835,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 748,
            "name": "vfs_create",
            "run_cnt_delta": 20783,
            "run_time_ns_delta": 894353,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0200507659999403,
            "ops_per_sec": 43.13510804226245,
            "ops_total": 44.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "747": {
            "avg_ns_per_run": null,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 747,
            "name": "1",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "748": {
            "avg_ns_per_run": 46.218744535758,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 748,
            "name": "vfs_create",
            "run_cnt_delta": 22876,
            "run_time_ns_delta": 1057300,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0086062079999465,
            "ops_per_sec": 60.47950083607183,
            "ops_total": 61.0,
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
          "754": {
            "avg_ns_per_run": 101.83267428236672,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 754,
            "name": "sched_wakeup",
            "run_cnt_delta": 54624,
            "run_time_ns_delta": 5562508,
            "type": "tracepoint"
          },
          "755": {
            "avg_ns_per_run": 215.39916666666667,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 755,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 3600,
            "run_time_ns_delta": 775437,
            "type": "tracepoint"
          },
          "756": {
            "avg_ns_per_run": 154.98056939266982,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 756,
            "name": "sched_switch",
            "run_cnt_delta": 90939,
            "run_time_ns_delta": 14093778,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0599399960000255,
            "ops_per_sec": 13.208294858985266,
            "ops_total": 14.0,
            "stderr": "",
            "stdout": "Time: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.051\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.035\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.041\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.064\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.048\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.035\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.035"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "754": {
            "avg_ns_per_run": 99.06058352583779,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 754,
            "name": "sched_wakeup",
            "run_cnt_delta": 63202,
            "run_time_ns_delta": 6260827,
            "type": "tracepoint"
          },
          "755": {
            "avg_ns_per_run": 207.36205864751645,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 755,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 3342,
            "run_time_ns_delta": 693004,
            "type": "tracepoint"
          },
          "756": {
            "avg_ns_per_run": 148.26418711304746,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 756,
            "name": "sched_switch",
            "run_cnt_delta": 109025,
            "run_time_ns_delta": 16164503,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.033835831000033,
            "ops_per_sec": 12.57453031727973,
            "ops_total": 13.0,
            "stderr": "",
            "stdout": "Running in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.054\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.058\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.053\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.038\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.061\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.061"
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
        "output_chars": 13109,
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
            "avg_ns_per_run": 931.4889502762431,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 763,
            "name": "tcp_set_state",
            "run_cnt_delta": 724,
            "run_time_ns_delta": 674398,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0091901040000266,
            "ops_per_sec": 72.3352316978309,
            "ops_total": 73.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "763": {
            "avg_ns_per_run": 817.264667535854,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 763,
            "name": "tcp_set_state",
            "run_cnt_delta": 767,
            "run_time_ns_delta": 626842,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0014803440001288,
            "ops_per_sec": 76.88618200178085,
            "ops_total": 77.0,
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
            "avg_ns_per_run": 4553.0,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 769,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 63742,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 8.238784125999928,
            "ops_per_sec": 0.4855085336411247,
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
            "avg_ns_per_run": 4409.727272727273,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 769,
            "name": "tcp_retransmit_",
            "run_cnt_delta": 22,
            "run_time_ns_delta": 97014,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 8.216598517999955,
            "ops_per_sec": 0.4868194534803266,
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
  "workload_seconds": 1.0
}
```
