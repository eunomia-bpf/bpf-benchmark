# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-04-27T03:57:30.057983+00:00",
  "kinsn_modules": {
    "captured_at": "2026-04-27T03:41:46.321209+00:00",
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
      "invoked_at": "2026-04-27T03:41:46.321122+00:00",
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
        "captured_at": "2026-04-27T03:41:46.321114+00:00",
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
      "captured_at": "2026-04-27T03:41:46.313666+00:00",
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
            "avg_ns_per_run": 78.8908100613983,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 151470,
            "run_time_ns_delta": 11949591,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0787215499999547,
            "ops_per_sec": 1128.1873436199091,
            "ops_total": 1217.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5922] setting to a 1 secs run per stressor\nstress-ng: info:  [5922] dispatching hogs: 2 exec\nstress-ng: info:  [5922] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5922] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5922]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5922] exec               1217      1.03      2.52      0.90      1186.36         356.16\nstress-ng: info:  [5922] skipped: 0\nstress-ng: info:  [5922] passed: 2: exec (2)\nstress-ng: info:  [5922] failed: 0\nstress-ng: info:  [5922] metrics untrustworthy: 0\nstress-ng: info:  [5922] successful run completed in 1.05 secs"
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 81.23399735547223,
            "bytes_jited": 206,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 138399,
            "run_time_ns_delta": 11242704,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0810963540000103,
            "ops_per_sec": 1036.9103511008504,
            "ops_total": 1121.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [8452] setting to a 1 secs run per stressor\nstress-ng: info:  [8452] dispatching hogs: 2 exec\nstress-ng: info:  [8452] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8452] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8452]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8452] exec               1121      1.03      2.36      0.87      1088.14         346.98\nstress-ng: info:  [8452] skipped: 0\nstress-ng: info:  [8452] passed: 2: exec (2)\nstress-ng: info:  [8452] failed: 0\nstress-ng: info:  [8452] metrics untrustworthy: 0\nstress-ng: info:  [8452] successful run completed in 1.04 secs"
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
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "bcc/execsnoop",
      "baseline": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 1748.7806080525884,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 1217,
            "run_time_ns_delta": 2128266,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 1483.032553407935,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 983,
            "run_time_ns_delta": 1457821,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.1018454599999359,
            "ops_per_sec": 1101.7879040859964,
            "ops_total": 1214.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [9506] setting to a 1 secs run per stressor\nstress-ng: info:  [9506] dispatching hogs: 2 exec\nstress-ng: info:  [9506] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9506] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9506]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9506] exec               1214      1.06      2.55      0.94      1142.18         347.14\nstress-ng: info:  [9506] skipped: 0\nstress-ng: info:  [9506] passed: 2: exec (2)\nstress-ng: info:  [9506] failed: 0\nstress-ng: info:  [9506] metrics untrustworthy: 0\nstress-ng: info:  [9506] successful run completed in 1.07 secs"
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 1790.7695614789338,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 1163,
            "run_time_ns_delta": 2082665,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 1493.3802133850631,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_exec",
            "run_cnt_delta": 1031,
            "run_time_ns_delta": 1539675,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.1076451769999949,
            "ops_per_sec": 1047.2667818965326,
            "ops_total": 1160.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [10114] setting to a 1 secs run per stressor\nstress-ng: info:  [10114] dispatching hogs: 2 exec\nstress-ng: info:  [10114] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10114] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10114]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10114] exec               1160      1.04      2.51      0.90      1119.67         340.23\nstress-ng: info:  [10114] skipped: 0\nstress-ng: info:  [10114] passed: 2: exec (2)\nstress-ng: info:  [10114] failed: 0\nstress-ng: info:  [10114] metrics untrustworthy: 0\nstress-ng: info:  [10114] successful run completed in 1.07 secs"
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
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "bcc/bindsnoop",
      "baseline": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 54.452501057701696,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 30727,
            "run_time_ns_delta": 1673162,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 659.1444936214527,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 15364,
            "run_time_ns_delta": 10127096,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": 658.349020373625,
            "bytes_jited": 742,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_return",
            "run_cnt_delta": 15363,
            "run_time_ns_delta": 10114216,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0000439359999973,
            "ops_per_sec": 30725.65003784002,
            "ops_total": 30727.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 58.45516356638871,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 31180,
            "run_time_ns_delta": 1822632,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 680.7006414368185,
            "bytes_jited": 719,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_re",
            "run_cnt_delta": 15590,
            "run_time_ns_delta": 10612123,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": 681.8454778704298,
            "bytes_jited": 740,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_re",
            "run_cnt_delta": 15590,
            "run_time_ns_delta": 10629971,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0000444969998625,
            "ops_per_sec": 31178.612645277408,
            "ops_total": 31180.0,
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
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "bcc/biosnoop",
      "baseline": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 147.37330065275492,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 311296,
            "run_time_ns_delta": 45876719,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 166.74323152240953,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 311296,
            "run_time_ns_delta": 51906501,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 368.9870380602385,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 311296,
            "run_time_ns_delta": 114864189,
            "type": "tracepoint"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 5.053766178999922,
            "ops_per_sec": 61596.83471181123,
            "ops_total": 311296.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 157.39841665872714,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start",
            "run_cnt_delta": 335872,
            "run_time_ns_delta": 52865721,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 181.1534929973323,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 335872,
            "run_time_ns_delta": 60844386,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 373.8594405011433,
            "bytes_jited": 548,
            "bytes_xlated": 848,
            "id": 20,
            "name": "trace_req_compl",
            "run_cnt_delta": 335872,
            "run_time_ns_delta": 125568918,
            "type": "tracepoint"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 5.124533102999976,
            "ops_per_sec": 65541.97099505039,
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
      "status": "ok",
      "workload_miss": false
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
            "avg_ns_per_run": 44.37546468401487,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 538,
            "run_time_ns_delta": 23874,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 28.324912280701753,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 5700,
            "run_time_ns_delta": 161452,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 24.836309289703454,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 12713,
            "run_time_ns_delta": 315744,
            "type": "tracing"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0145868639999662,
            "ops_per_sec": 54.20925694145576,
            "ops_total": 55.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "limitations": [],
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
            "avg_ns_per_run": 35.782931354359924,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 539,
            "run_time_ns_delta": 19287,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 27.74649629018961,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 4852,
            "run_time_ns_delta": 134626,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 25.538905644118913,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 11605,
            "run_time_ns_delta": 296379,
            "type": "tracing"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0114252959999703,
            "ops_per_sec": 71.18667121017123,
            "ops_total": 72.0,
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
      "status": "ok",
      "workload_miss": false
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
            "avg_ns_per_run": 1306.955140186916,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 1605,
            "run_time_ns_delta": 2097663,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 1323.3234200743495,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 538,
            "run_time_ns_delta": 711948,
            "type": "tracing"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0025847549999298,
            "ops_per_sec": 536.6129868990853,
            "ops_total": 538.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "limitations": [],
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
            "avg_ns_per_run": 1397.258650519031,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 1156,
            "run_time_ns_delta": 1615231,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 1628.279365079365,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 315,
            "run_time_ns_delta": 512908,
            "type": "tracing"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0041159810000408,
            "ops_per_sec": 313.7087806194245,
            "ops_total": 315.0,
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
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "bcc/syscount",
      "baseline": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 62.47933120659595,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 1195885,
            "run_time_ns_delta": 74718095,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 61.94551557301174,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 1195883,
            "run_time_ns_delta": 74079589,
            "type": "tracepoint"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0000956220000035,
            "ops_per_sec": 661.9367042884602,
            "ops_total": 662.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 67.13210382541997,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 964234,
            "run_time_ns_delta": 64731057,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 55.981938844086024,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 964224,
            "run_time_ns_delta": 53979129,
            "type": "tracepoint"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0013022549999278,
            "ops_per_sec": 630.1793457960858,
            "ops_total": 631.0,
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
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "bcc/tcpconnect",
      "baseline": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 672.9459459459459,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 74,
            "run_time_ns_delta": 49798,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 3890.945945945946,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 37,
            "run_time_ns_delta": 143965,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 4090.5405405405404,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 37,
            "run_time_ns_delta": 151350,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0170019810000213,
            "ops_per_sec": 72.76288678143534,
            "ops_total": 74.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 663.6338028169014,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_e",
            "run_cnt_delta": 71,
            "run_time_ns_delta": 47118,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4518.138888888889,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v",
            "run_cnt_delta": 36,
            "run_time_ns_delta": 162653,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 4292.457142857143,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v",
            "run_cnt_delta": 35,
            "run_time_ns_delta": 150236,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0061074420000296,
            "ops_per_sec": 70.56900390167068,
            "ops_total": 71.0,
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
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "bcc/tcplife",
      "baseline": {
        "bpf": {
          "44": {
            "avg_ns_per_run": 655.9018058690745,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 886,
            "run_time_ns_delta": 581129,
            "type": "tracepoint"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0148303739999847,
            "ops_per_sec": 79.8162945012535,
            "ops_total": 81.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "44": {
            "avg_ns_per_run": 754.1421254801536,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "sock__inet_sock",
            "run_cnt_delta": 781,
            "run_time_ns_delta": 588985,
            "type": "tracepoint"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0102418559999933,
            "ops_per_sec": 70.28020030878672,
            "ops_total": 71.0,
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
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "bcc/runqlat",
      "baseline": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 181.45631578947368,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 91200,
            "run_time_ns_delta": 16548816,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 118.41269788479447,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 60136,
            "run_time_ns_delta": 7120866,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 242.30950644298565,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 4113,
            "run_time_ns_delta": 996619,
            "type": "raw_tracepoint"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0355577779999976,
            "ops_per_sec": 15.450610617691712,
            "ops_total": 16.0,
            "stderr": "",
            "stdout": "Time: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.052\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.038\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.041\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.035\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044"
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 170.9903663177926,
            "bytes_jited": 645,
            "bytes_xlated": 1136,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 109304,
            "run_time_ns_delta": 18689931,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 114.3544953584565,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 74221,
            "run_time_ns_delta": 8487505,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 243.74631842178383,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 3599,
            "run_time_ns_delta": 877243,
            "type": "raw_tracepoint"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.036449753999932,
            "ops_per_sec": 13.50764949865666,
            "ops_total": 14.0,
            "stderr": "",
            "stdout": "Time: 0.049\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.046\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.056\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.045\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.045\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.053\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.048\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.053\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.055"
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
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "calico/felix",
      "baseline": null,
      "error": "Calico felix did not finish attaching to bpfbench0: Felix did not attach any sched_cls programs to bpfbench0 within 90s\n2026-04-27 03:42:37.914 [INFO][2149] felix/bpf_ep_mgr.go 3613: Starting map cleanup runner.\n2026-04-27 03:42:37.916 [INFO][2149] felix/bpf_ep_mgr.go 1709: BPF Interface state map synced.\n2026-04-27 03:42:37.916 [INFO][2149] felix/bpf_ep_mgr.go 1716: Default BPF policy programs loaded.\n2026-04-27 03:42:37.916 [INFO][2149] felix/bpf_ep_mgr.go 1723: BPF counters synced.\n2026-04-27 03:42:37.917 [INFO][2149] felix/bpf_ep_mgr.go 3568: /proc/sys/net/ipv4/conf/bpfout.cali/accept_local set to 1\n2026-04-27 03:42:37.917 [INFO][2149] felix/bpf_ep_mgr.go 3568: /proc/sys/net/ipv4/conf/lo/accept_local set to 1\n2026-04-27 03:42:37.917 [INFO][2149] felix/bpf_ep_mgr.go 3568: /proc/sys/net/ipv4/conf/bpfbench0/accept_local set to 1\n2026-04-27 03:42:37.917 [INFO][2149] felix/bpf_ep_mgr.go 2086: Applied program to host interface id=\"bpfout.cali\"\n2026-04-27 03:42:37.917 [INFO][2149] felix/bpf_ep_mgr.go 2086: Applied program to host interface id=\"lo\"\n2026-04-27 03:42:37.917 [INFO][2149] felix/bpf_ep_mgr.go 2086: Applied program to host interface id=\"bpfbench0\"\n2026-04-27 03:42:37.917 [INFO][2149] felix/bpf_ep_mgr.go 1764: Copy delta entries from old map to the new map\n2026-04-27 03:42:37.920 [INFO][2149] felix/health.go 204: Health of component changed name=\"BPFEndpointManager\" newReport=\"ready\" oldReport=\"non-ready\"\n2026-04-27 03:42:37.920 [INFO][2149] felix/masq_mgr.go 145: IPAM pools updated, refreshing iptables rule ipVersion=0x4\n2026-04-27 03:42:37.920 [INFO][2149] felix/wireguard.go 1763: Trying to connect to linkClient ipVersion=0x4\n2026-04-27 03:42:37.921 [INFO][2149] felix/wireguard.go 648: Public key out of sync or updated ipVersion=0x4 ourPublicKey=AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA=\n2026-04-27 03:42:37.927 [INFO][2149] felix/table.go 1048: Flushing chain chainName=\"nat-POSTROUTING\" ipVersion=0x4 table=\"calico\"\n2026-04-27 03:42:37.927 [INFO][2149] felix/table.go 1048: Flushing chain chainName=\"mangle-PREROUTING\" ipVersion=0x4 table=\"calico\"\n2026-04-27 03:42:37.927 [INFO][2149] felix/table.go 1048: Flushing chain chainName=\"mangle-OUTPUT\" ipVersion=0x4 table=\"calico\"\n2026-04-27 03:42:37.927 [INFO][2149] felix/table.go 1048: Flushing chain chainName=\"mangle-POSTROUTING\" ipVersion=0x4 table=\"calico\"\n2026-04-27 03:42:37.927 [INFO][2149] felix/table.go 1048: Flushing chain chainName=\"filter-INPUT\" ipVersion=0x4 table=\"calico\"\n2026-04-27 03:42:37.927 [INFO][2149] felix/table.go 1048: Flushing chain chainName=\"nat-OUTPUT\" ipVersion=0x4 table=\"calico\"\n2026-04-27 03:42:37.927 [INFO][2149] felix/table.go 1048: Flushing chain chainName=\"mangle-INPUT\" ipVersion=0x4 table=\"calico\"\n2026-04-27 03:42:37.927 [INFO][2149] felix/table.go 1048: Flushing chain chainName=\"mangle-FORWARD\" ipVersion=0x4 table=\"calico\"\n2026-04-27 03:42:37.927 [INFO][2149] felix/table.go 1048: Flushing chain chainName=\"raw-PREROUTING\" ipVersion=0x4 table=\"calico\"\n2026-04-27 03:42:37.927 [INFO][2149] felix/table.go 1048: Flushing chain chainName=\"raw-OUTPUT\" ipVersion=0x4 table=\"calico\"\n2026-04-27 03:42:37.927 [INFO][2149] felix/table.go 1048: Flushing chain chainName=\"filter-FORWARD\" ipVersion=0x4 table=\"calico\"\n2026-04-27 03:42:37.927 [INFO][2149] felix/table.go 1048: Flushing chain chainName=\"nat-PREROUTING\" ipVersion=0x4 table=\"calico\"\n2026-04-27 03:42:37.927 [INFO][2149] felix/table.go 1048: Flushing chain chainName=\"nat-INPUT\" ipVersion=0x4 table=\"calico\"\n2026-04-27 03:42:38.718 [INFO][2149] felix/int_dataplane.go 2307: Completed first update to dataplane. secsSinceStart=1.99833873\n2026-04-27 03:42:38.720 [INFO][2149] felix/health.go 204: Health of component changed name=\"InternalDataplaneMainLoop\" newReport=\"live,ready\" oldReport=\"live,non-ready\"\n2026-04-27 03:42:39.238 [INFO][2149] felix/iface_monitor.go 246: Netlink address update for known interface.  addr=\"fe80::41f:2fff:fefa:a747\" exists=true ifIndex=6\n2026-04-27 03:42:39.238 [INFO][2149] felix/int_dataplane.go 1781: Linux interface addrs changed. addrs=set.Set{fe80::41f:2fff:fefa:a747} ifaceName=\"bpfout.cali\"\n2026-04-27 03:42:39.238 [INFO][2149] felix/int_dataplane.go 2442: Received interface addresses update msg=&intdataplane.ifaceAddrsUpdate{Name:\"bpfout.cali\", Addrs:set.Typed[string]{\"fe80::41f:2fff:fefa:a747\":set.v{}}}\n2026-04-27 03:42:39.388 [INFO][2149] felix/iface_monitor.go 246: Netlink address update for known interface.  addr=\"fe80::eca0:f2ff:fea1:dd2c\" exists=true ifIndex=7\n2026-04-27 03:42:39.388 [INFO][2149] felix/int_dataplane.go 1781: Linux interface addrs changed. addrs=set.Set{fe80::eca0:f2ff:fea1:dd2c} ifaceName=\"bpfin.cali\"\n2026-04-27 03:42:39.388 [INFO][2149] felix/int_dataplane.go 2442: Received interface addresses update msg=&intdataplane.ifaceAddrsUpdate{Name:\"bpfin.cali\", Addrs:set.Typed[string]{\"fe80::eca0:f2ff:fea1:dd2c\":set.v{}}}\n2026-04-27 03:43:07.911 [WARNING][2149] felix/int_dataplane.go 1456: Failed to auto-detect host MTU - no interfaces matched the MTU interface pattern. To use auto-MTU, set mtuIfacePattern to match your host's interfaces\n2026-04-27 03:43:37.912 [WARNING][2149] felix/int_dataplane.go 1456: Failed to auto-detect host MTU - no interfaces matched the MTU interface pattern. To use auto-MTU, set mtuIfacePattern to match your host's interfaces\n2026-04-27 03:43:56.886 [INFO][2149] felix/summary.go 100: Summarising 8 dataplane reconciliation loops over 1m20.2s: avg=110ms longest=804ms (resync-bpf-ipsets,resync-bpf-routes,resync-calico-v4,resync-failsafes,resync-filter-v4,resync-ipsets-v4,resync-mangle-v4,resync-nat-v4,resync-nft-sets-v4,resync-raw-v4,resync-routes-v4,resync-routes-v4,resync-rules-v4,update-bpf-routes,update-calico-v4,update-data-iface,update-data-iface,update-data-iface)\n2026-04-27 03:44:07.913 [WARNING][2149] felix/int_dataplane.go 1456: Failed to auto-detect host MTU - no interfaces matched the MTU interface pattern. To use auto-MTU, set mtuIfacePattern to match your host's interfaces\nstderr tail:\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.",
      "limitations": [],
      "post_rejit": null,
      "rejit_result": null,
      "runner": "calico",
      "selected_workload": "network",
      "status": "error",
      "workload_miss": false
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
            "avg_ns_per_run": 417.3658088235294,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 131,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 1632,
            "run_time_ns_delta": 681141,
            "type": "tracepoint"
          },
          "132": {
            "avg_ns_per_run": 15245.681818181818,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 132,
            "name": "native_tracer_entry",
            "run_cnt_delta": 88,
            "run_time_ns_delta": 1341620,
            "type": "perf_event"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0735267090000207,
            "ops_per_sec": 1129.920652956923,
            "ops_total": 1213.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [21802] setting to a 1 secs run per stressor\nstress-ng: info:  [21802] dispatching hogs: 2 exec\nstress-ng: info:  [21802] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21802] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21802]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21802] exec               1213      1.03      2.55      0.86      1174.77         354.80\nstress-ng: info:  [21802] skipped: 0\nstress-ng: info:  [21802] passed: 2: exec (2)\nstress-ng: info:  [21802] failed: 0\nstress-ng: info:  [21802] metrics untrustworthy: 0\nstress-ng: info:  [21802] successful run completed in 1.05 secs"
          }
        ]
      },
      "error": "",
      "limitations": [],
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
            "avg_ns_per_run": 333.1664402173913,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 131,
            "name": "tracepoint__sch",
            "run_cnt_delta": 1472,
            "run_time_ns_delta": 490421,
            "type": "tracepoint"
          },
          "132": {
            "avg_ns_per_run": 14187.87341772152,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 132,
            "name": "native_tracer_e",
            "run_cnt_delta": 79,
            "run_time_ns_delta": 1120842,
            "type": "perf_event"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0728134149999278,
            "ops_per_sec": 1087.7940037691258,
            "ops_total": 1167.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [15854] setting to a 1 secs run per stressor\nstress-ng: info:  [15854] dispatching hogs: 2 exec\nstress-ng: info:  [15854] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [15854] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15854]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15854] exec               1167      1.02      2.46      0.80      1144.76         358.49\nstress-ng: info:  [15854] skipped: 0\nstress-ng: info:  [15854] passed: 2: exec (2)\nstress-ng: info:  [15854] failed: 0\nstress-ng: info:  [15854] metrics untrustworthy: 0\nstress-ng: info:  [15854] successful run completed in 1.04 secs"
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
      "status": "ok",
      "workload_miss": false
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
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 217,
            "name": "tail_drop_notify",
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
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 219,
            "name": "cil_to_host",
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
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 221,
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
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 229,
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
            "avg_ns_per_run": 260.6759499136442,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 234,
            "name": "cil_from_netdev",
            "run_cnt_delta": 4632,
            "run_time_ns_delta": 1207451,
            "type": "sched_cls"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0155821050000213,
            "ops_per_sec": 812.3420016346022,
            "ops_total": 825.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     7.77ms    7.93ms  55.47ms   89.79%\n    Req/Sec   412.55    231.56     0.87k    60.00%\n  825 requests in 1.01s, 125.01KB read\nRequests/sec:    817.87\nTransfer/sec:    123.93KB"
          }
        ]
      },
      "error": "",
      "limitations": [],
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
            "name": "tail_handle_ipv",
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
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 217,
            "name": "tail_drop_notif",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 218,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 219,
            "name": "cil_to_host",
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
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 221,
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
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 229,
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
            "avg_ns_per_run": 258.12031165066134,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 234,
            "name": "cil_from_netdev",
            "run_cnt_delta": 5519,
            "run_time_ns_delta": 1424566,
            "type": "sched_cls"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.1071572030000425,
            "ops_per_sec": 890.5691055689787,
            "ops_total": 986.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     6.42ms    5.38ms  36.57ms   83.52%\n    Req/Sec   470.81    217.01     1.08k    80.95%\n  986 requests in 1.10s, 149.38KB read\nRequests/sec:    896.15\nTransfer/sec:    135.77KB"
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
        "output_chars": 101875,
        "output_stripped": true,
        "program_counts": {
          "applied": 16,
          "not_applied": 0,
          "requested": 16
        }
      },
      "runner": "cilium",
      "selected_workload": "network",
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "tetragon/observer",
      "baseline": {
        "bpf": {
          "251": {
            "avg_ns_per_run": 523.8510822510823,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 251,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1155,
            "run_time_ns_delta": 605048,
            "type": "kprobe"
          },
          "253": {
            "avg_ns_per_run": 722.0040415704387,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 253,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1732,
            "run_time_ns_delta": 1250511,
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
            "avg_ns_per_run": 2986.885462555066,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 256,
            "name": "event_execve",
            "run_cnt_delta": 908,
            "run_time_ns_delta": 2712092,
            "type": "tracepoint"
          },
          "257": {
            "avg_ns_per_run": 282.86453744493394,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 257,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 908,
            "run_time_ns_delta": 256841,
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 261,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 263,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "264": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 264,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 268,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 269,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 271,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 272,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 273,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 276,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "277": {
            "avg_ns_per_run": 1506.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 277,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 15,
            "run_time_ns_delta": 22590,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 278,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 280,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 648.1686746987951,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 282,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2241,
            "run_time_ns_delta": 1452546,
            "type": "kprobe"
          },
          "283": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 283,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 284,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 285,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 288,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 289,
            "name": "generic_retkprobe_actions",
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
            "avg_ns_per_run": 550.6184738955824,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 292,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2241,
            "run_time_ns_delta": 1233936,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 293,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 294,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "avg_ns_per_run": 562.1150083512289,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 295,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4191,
            "run_time_ns_delta": 2355824,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 297,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 302,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 303,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "avg_ns_per_run": 628.9195406683962,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 304,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 26212,
            "run_time_ns_delta": 16485239,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 305,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 306,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 307,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 622.2681838464971,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 309,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2241,
            "run_time_ns_delta": 1394503,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 312,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 313,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 315,
            "name": "generic_retkprobe_filter_arg",
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
            "avg_ns_per_run": 543.1106648817492,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 317,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2241,
            "run_time_ns_delta": 1217111,
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 319,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "320": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 320,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "321": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 321,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": 553.386542591267,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 322,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4191,
            "run_time_ns_delta": 2319243,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 324,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": 656.4378147413398,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 325,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 13106,
            "run_time_ns_delta": 8603274,
            "type": "kprobe"
          },
          "326": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 326,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "327": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 327,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 328,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "329": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 329,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 330,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 334,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 335,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": 704.9740993469807,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 337,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 13629,
            "run_time_ns_delta": 9608092,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 338,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 340,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "341": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 341,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "342": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 342,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "343": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 343,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 348,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 353,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 356,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "357": {
            "avg_ns_per_run": 266.4499255051681,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 357,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 42956,
            "run_time_ns_delta": 11445623,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 359,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 360,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 483.68013946025184,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 362,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 151441,
            "run_time_ns_delta": 73249004,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 364,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "365": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 365,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 368,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 40.727086780962466,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 370,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 151070,
            "run_time_ns_delta": 6152641,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 373,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "374": {
            "avg_ns_per_run": 995.1553823267874,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 374,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 120329,
            "run_time_ns_delta": 119746052,
            "type": "kprobe"
          },
          "375": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 375,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "376": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 376,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 378,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "379": {
            "avg_ns_per_run": 48.52302437483898,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 379,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 120329,
            "run_time_ns_delta": 5838727,
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 386,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 387,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 390,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 391,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "392": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 392,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "393": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 393,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 397,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "398": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 398,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 405,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 410,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 411,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 412,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 413,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 414,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "415": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 415,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 416,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 420,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 422,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 425,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "426": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 426,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "427": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 427,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 431,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 434,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "avg_ns_per_run": 1812.4460352422907,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 435,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 908,
            "run_time_ns_delta": 1645701,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 436,
            "name": "generic_tracepoint_filter",
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
            "avg_ns_per_run": 436.79847920893303,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 438,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 938985,
            "run_time_ns_delta": 410147220,
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 441,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "442": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 442,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "443": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 443,
            "name": "generic_rawtp_process_filter",
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
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 445,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "446": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 446,
            "name": "generic_rawtp_output",
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
            "avg_ns_per_run": 1593.192731277533,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 448,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 908,
            "run_time_ns_delta": 1446619,
            "type": "raw_tracepoint"
          },
          "449": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 449,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "450": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 450,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": 842.5080572963294,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 453,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2234,
            "run_time_ns_delta": 1882163,
            "type": "kprobe"
          },
          "454": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 454,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "455": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 455,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 2679.994407113005,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 458,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 48812,
            "run_time_ns_delta": 130815887,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 460,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "461": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 461,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 462,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 464,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "465": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 465,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 468,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 469,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "470": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 470,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "471": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 471,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "472": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 472,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 474,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "475": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 475,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "476": {
            "avg_ns_per_run": 695.8683623382418,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 476,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2241,
            "run_time_ns_delta": 1559441,
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
            "avg_ns_per_run": 520.0240963855422,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 480,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2241,
            "run_time_ns_delta": 1165374,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 482,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": 621.1660701503221,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 485,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4191,
            "run_time_ns_delta": 2603307,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 487,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 489,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 492,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "493": {
            "avg_ns_per_run": 399.44464982542615,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 493,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 19476,
            "run_time_ns_delta": 7779584,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 495,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "496": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 496,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "497": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 497,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": 645.8782296113233,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 499,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4451,
            "run_time_ns_delta": 2874804,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 503,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 507,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "508": {
            "avg_ns_per_run": 661.9334831460674,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 508,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2225,
            "run_time_ns_delta": 1472802,
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
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 510,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": 531.1015730337078,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 511,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2225,
            "run_time_ns_delta": 1181701,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 513,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": 833.850786516854,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 514,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2225,
            "run_time_ns_delta": 1855318,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 516,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 517,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 519,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 520,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 521,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 522,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 524,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 525,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "526": {
            "avg_ns_per_run": 725.5848124017075,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 526,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4451,
            "run_time_ns_delta": 3229578,
            "type": "kprobe"
          },
          "527": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 527,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 528,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 530,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 531,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "532": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 532,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": 2165.2631578947367,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 533,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 19,
            "run_time_ns_delta": 41140,
            "type": "kprobe"
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 539,
            "name": "generic_kprobe_process_event",
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
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.7189459329999863,
            "ops_per_sec": 1963.412539747419,
            "ops_total": 3375.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [27052] setting to a 1 secs run per stressor\nstress-ng: info:  [27052] dispatching hogs: 2 exec\nstress-ng: info:  [27052] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [27052] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [27052]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [27052] exec               1151      1.04      2.44      0.87      1110.91         347.73\nstress-ng: info:  [27052] skipped: 0\nstress-ng: info:  [27052] passed: 2: exec (2)\nstress-ng: info:  [27052] failed: 0\nstress-ng: info:  [27052] metrics untrustworthy: 0\nstress-ng: info:  [27052] successful run completed in 1.05 secs"
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "251": {
            "avg_ns_per_run": 533.3897707231041,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 251,
            "name": "event_exit_acct",
            "run_cnt_delta": 1134,
            "run_time_ns_delta": 604864,
            "type": "kprobe"
          },
          "253": {
            "avg_ns_per_run": 750.5083477259643,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 253,
            "name": "event_wake_up_n",
            "run_cnt_delta": 1737,
            "run_time_ns_delta": 1303633,
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
            "avg_ns_per_run": 2951.353616532721,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 256,
            "name": "event_execve",
            "run_cnt_delta": 871,
            "run_time_ns_delta": 2570629,
            "type": "tracepoint"
          },
          "257": {
            "avg_ns_per_run": 312.96785304247993,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 257,
            "name": "tg_kp_bprm_comm",
            "run_cnt_delta": 871,
            "run_time_ns_delta": 272595,
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 263,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "264": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 268,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 269,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 271,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 272,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 273,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "274": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 274,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 276,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "277": {
            "avg_ns_per_run": 1815.0666666666666,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 277,
            "name": "generic_kprobe_",
            "run_cnt_delta": 15,
            "run_time_ns_delta": 27226,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 278,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 280,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 281,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "282": {
            "avg_ns_per_run": 532.545945945946,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 282,
            "name": "generic_kprobe_",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 98521,
            "type": "kprobe"
          },
          "283": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 283,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 284,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 285,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 286,
            "name": "generic_kprobe_",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 288,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 289,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 290,
            "name": "generic_retkpro",
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
            "avg_ns_per_run": 483.25405405405405,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 292,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 89402,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 293,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 294,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "avg_ns_per_run": 528.7796610169491,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 295,
            "name": "generic_kprobe_",
            "run_cnt_delta": 354,
            "run_time_ns_delta": 187188,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 297,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 300,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 301,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 302,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 303,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "avg_ns_per_run": 555.3310479921646,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 304,
            "name": "generic_kprobe_",
            "run_cnt_delta": 2042,
            "run_time_ns_delta": 1133986,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 305,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 306,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 307,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 569.6540540540541,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 309,
            "name": "generic_kprobe_",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 105386,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 312,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 313,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 315,
            "name": "generic_retkprobe_filter_arg",
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
            "avg_ns_per_run": 514.7351351351351,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 317,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 95226,
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 319,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "320": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 320,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "321": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 321,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": 576.5932203389831,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 322,
            "name": "generic_kprobe_",
            "run_cnt_delta": 354,
            "run_time_ns_delta": 204114,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 324,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": 617.7688540646425,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 325,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1021,
            "run_time_ns_delta": 630742,
            "type": "kprobe"
          },
          "326": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 326,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "327": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 327,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 328,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "329": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 329,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 330,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 334,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 335,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": 660.2240343347639,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 337,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1165,
            "run_time_ns_delta": 769161,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 338,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 340,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "341": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 341,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "342": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 342,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "343": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 343,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 347,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "348": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 348,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "349": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 349,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "350": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 350,
            "name": "generic_kprobe_",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 353,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 356,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "357": {
            "avg_ns_per_run": 262.4412287314236,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 357,
            "name": "generic_kprobe_",
            "run_cnt_delta": 37144,
            "run_time_ns_delta": 9748117,
            "type": "kprobe"
          },
          "358": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 358,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "359": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 359,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 360,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": 491.09272758830167,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 362,
            "name": "generic_kprobe_",
            "run_cnt_delta": 138276,
            "run_time_ns_delta": 67906338,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 364,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "365": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 365,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 368,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 40.648341211611516,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 370,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 137932,
            "run_time_ns_delta": 5606707,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 373,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "374": {
            "avg_ns_per_run": 986.9076062484846,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 374,
            "name": "generic_kprobe_",
            "run_cnt_delta": 115484,
            "run_time_ns_delta": 113972038,
            "type": "kprobe"
          },
          "375": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 375,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "376": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 376,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 378,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "379": {
            "avg_ns_per_run": 48.02154411000658,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 379,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 115484,
            "run_time_ns_delta": 5545720,
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
            "name": "generic_retkpro",
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
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 385,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "386": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 386,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 387,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 390,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 391,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "392": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 392,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "393": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 393,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 397,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "398": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 398,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "399": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 399,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 405,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "406": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 406,
            "name": "generic_kprobe_",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 410,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 411,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 412,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 413,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 414,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "415": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 415,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 416,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 420,
            "name": "generic_kprobe_",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 422,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 425,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "426": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 426,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "427": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 427,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "428": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 428,
            "name": "generic_kprobe_",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 430,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 431,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 434,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "avg_ns_per_run": 1695.808266360505,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 435,
            "name": "generic_kprobe_",
            "run_cnt_delta": 871,
            "run_time_ns_delta": 1477049,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 436,
            "name": "generic_tracepoint_filter",
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
            "avg_ns_per_run": 469.7556889417872,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 438,
            "name": "generic_tracepo",
            "run_cnt_delta": 1227513,
            "run_time_ns_delta": 576631215,
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 441,
            "name": "generic_tracepo",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "442": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 442,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "443": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 443,
            "name": "generic_rawtp_process_filter",
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
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 445,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "446": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 446,
            "name": "generic_rawtp_o",
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
            "avg_ns_per_run": 1639.195177956372,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 448,
            "name": "generic_rawtp_e",
            "run_cnt_delta": 871,
            "run_time_ns_delta": 1427739,
            "type": "raw_tracepoint"
          },
          "449": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 449,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "450": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 450,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": 649.9887640449438,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 453,
            "name": "generic_kprobe_",
            "run_cnt_delta": 178,
            "run_time_ns_delta": 115698,
            "type": "kprobe"
          },
          "454": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 454,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "455": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 455,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": 2670.7889796442014,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 458,
            "name": "generic_kprobe_",
            "run_cnt_delta": 46768,
            "run_time_ns_delta": 124907459,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 460,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "461": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 461,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 464,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "465": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 465,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 468,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 469,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "470": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 470,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "471": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 471,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "472": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 472,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 474,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "475": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 475,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "476": {
            "avg_ns_per_run": 623.4594594594595,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 476,
            "name": "generic_kprobe_",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 115340,
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
            "avg_ns_per_run": 511.23243243243246,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 480,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 94578,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 482,
            "name": "generic_kprobe_",
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
            "avg_ns_per_run": 585.8474576271186,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 485,
            "name": "generic_kprobe_",
            "run_cnt_delta": 354,
            "run_time_ns_delta": 207390,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 487,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 489,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "490": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 490,
            "name": "generic_kprobe_",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 492,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "493": {
            "avg_ns_per_run": 400.2102496714849,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 493,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1522,
            "run_time_ns_delta": 609120,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 495,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "496": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 496,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "497": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 497,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": 697.3569321533923,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 499,
            "name": "generic_kprobe_",
            "run_cnt_delta": 339,
            "run_time_ns_delta": 236404,
            "type": "kprobe"
          },
          "500": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 500,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "501": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 501,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 503,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 507,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "508": {
            "avg_ns_per_run": 481.2603550295858,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 508,
            "name": "generic_kprobe_",
            "run_cnt_delta": 169,
            "run_time_ns_delta": 81333,
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
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 510,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": 465.7869822485207,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 511,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 169,
            "run_time_ns_delta": 78718,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 513,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": 678.3372781065088,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 514,
            "name": "generic_kprobe_",
            "run_cnt_delta": 169,
            "run_time_ns_delta": 114639,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 516,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 517,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 518,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "519": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 519,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 520,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 521,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 522,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 524,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 525,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "526": {
            "avg_ns_per_run": 741.4837758112094,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 526,
            "name": "generic_kprobe_",
            "run_cnt_delta": 339,
            "run_time_ns_delta": 251363,
            "type": "kprobe"
          },
          "527": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 527,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 528,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 530,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 531,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "532": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 532,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": 2647.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 533,
            "name": "generic_kprobe_",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 10588,
            "type": "kprobe"
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
            "name": "generic_kprobe_",
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
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 539,
            "name": "generic_kprobe_process_event",
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
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 2.368416606999972,
            "ops_per_sec": 548.4676961649152,
            "ops_total": 1299.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [18615] setting to a 1 secs run per stressor\nstress-ng: info:  [18615] dispatching hogs: 2 exec\nstress-ng: info:  [18615] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18615] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18615]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18615] exec               1130      1.04      2.40      0.79      1087.04         353.46\nstress-ng: info:  [18615] skipped: 0\nstress-ng: info:  [18615] passed: 2: exec (2)\nstress-ng: info:  [18615] failed: 0\nstress-ng: info:  [18615] metrics untrustworthy: 0\nstress-ng: info:  [18615] successful run completed in 1.05 secs"
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
        "output_chars": 3618489,
        "output_stripped": true,
        "program_counts": {
          "applied": 287,
          "not_applied": 0,
          "requested": 287
        }
      },
      "runner": "tetragon",
      "selected_workload": "tetragon_exec_connect_mix",
      "status": "ok",
      "workload_miss": false
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
            "avg_ns_per_run": 53.2216796875,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 553,
            "name": "balancer_ingress",
            "run_cnt_delta": 1024,
            "run_time_ns_delta": 54499,
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
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0400259190000725,
            "ops_per_sec": 984.5908465286321,
            "ops_total": 1024.0,
            "stderr": "{'retval': 2, 'duration_ns': 66, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "limitations": [],
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
            "avg_ns_per_run": 50.77430555555556,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 553,
            "name": "balancer_ingress",
            "run_cnt_delta": 1152,
            "run_time_ns_delta": 58492,
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
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.1173380829998223,
            "ops_per_sec": 1031.021870217757,
            "ops_total": 1152.0,
            "stderr": "{'retval': 2, 'duration_ns': 73, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
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
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "tracee/monitor",
      "baseline": {
        "bpf": {
          "570": {
            "avg_ns_per_run": 148.80689163439487,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 570,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 2675969,
            "run_time_ns_delta": 398202629,
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
            "avg_ns_per_run": 371.6869089915686,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 573,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 2675829,
            "run_time_ns_delta": 994570610,
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
            "avg_ns_per_run": 342.54173930167997,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 576,
            "name": "trace_sys_enter",
            "run_cnt_delta": 2676051,
            "run_time_ns_delta": 916659164,
            "type": "raw_tracepoint"
          },
          "577": {
            "avg_ns_per_run": 314.314434829672,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 577,
            "name": "trace_sys_exit",
            "run_cnt_delta": 2675397,
            "run_time_ns_delta": 840915896,
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
            "avg_ns_per_run": 1409.6707317073171,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 582,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 164,
            "run_time_ns_delta": 231186,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": 1787.841463414634,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 583,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 164,
            "run_time_ns_delta": 293206,
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
            "avg_ns_per_run": 1577.969696969697,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 586,
            "name": "trace_dup2",
            "run_cnt_delta": 165,
            "run_time_ns_delta": 260365,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 2608.830303030303,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 587,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 165,
            "run_time_ns_delta": 430457,
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
            "avg_ns_per_run": 4679.869653767821,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 595,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 491,
            "run_time_ns_delta": 2297816,
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
            "avg_ns_per_run": 5072.707317073171,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 603,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 164,
            "run_time_ns_delta": 831924,
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
            "avg_ns_per_run": 1707.095918367347,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 605,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 490,
            "run_time_ns_delta": 836477,
            "type": "raw_tracepoint"
          },
          "606": {
            "avg_ns_per_run": 1075.0530612244897,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 606,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 490,
            "run_time_ns_delta": 526776,
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
            "avg_ns_per_run": 276.92079407806193,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 608,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 237760,
            "run_time_ns_delta": 65840688,
            "type": "raw_tracepoint"
          },
          "609": {
            "avg_ns_per_run": 18.585492227979273,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 609,
            "name": "trace_filldir64",
            "run_cnt_delta": 193,
            "run_time_ns_delta": 3587,
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
            "avg_ns_per_run": 1300.6897959183673,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 611,
            "name": "trace_do_exit",
            "run_cnt_delta": 490,
            "run_time_ns_delta": 637338,
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
            "avg_ns_per_run": 840.1006097560976,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 615,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 328,
            "run_time_ns_delta": 275553,
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
            "avg_ns_per_run": 1587.0,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 618,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1587,
            "type": "raw_tracepoint"
          },
          "619": {
            "avg_ns_per_run": 1445.0,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 619,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1445,
            "type": "raw_tracepoint"
          },
          "620": {
            "avg_ns_per_run": 3387.859756097561,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 620,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 164,
            "run_time_ns_delta": 555609,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": 1450.508845829823,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 621,
            "name": "trace_security_file_open",
            "run_cnt_delta": 2374,
            "run_time_ns_delta": 3443508,
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
            "avg_ns_per_run": 2550.0,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 623,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2550,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": 1608.7012195121952,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 624,
            "name": "trace_commit_creds",
            "run_cnt_delta": 164,
            "run_time_ns_delta": 263827,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": 1069.134693877551,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 625,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 490,
            "run_time_ns_delta": 523876,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 174.94662605354702,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 626,
            "name": "trace_cap_capable",
            "run_cnt_delta": 57781,
            "run_time_ns_delta": 10108591,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 916.7779479326186,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 627,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 653,
            "run_time_ns_delta": 598656,
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
            "avg_ns_per_run": 1782.2208588957055,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 632,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 290502,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": 1584.601226993865,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 633,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 258290,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 2091.9681528662422,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 634,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 314,
            "run_time_ns_delta": 656878,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 1704.0792682926829,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 635,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 164,
            "run_time_ns_delta": 279469,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": 1806.282208588957,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 636,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 294424,
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
            "avg_ns_per_run": 69.86395555338319,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 639,
            "name": "trace_vfs_write",
            "run_cnt_delta": 61377,
            "run_time_ns_delta": 4288040,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": 40.13668713255053,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 640,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 61403,
            "run_time_ns_delta": 2464513,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": 40.791739923162076,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 641,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 61428,
            "run_time_ns_delta": 2505755,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": 49.51680864257972,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 642,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 61278,
            "run_time_ns_delta": 3034291,
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
            "avg_ns_per_run": 114.26104120404638,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 654,
            "name": "trace_vfs_read",
            "run_cnt_delta": 16212,
            "run_time_ns_delta": 1852400,
            "type": "kprobe"
          },
          "655": {
            "avg_ns_per_run": 166.54439024390243,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 655,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 3075,
            "run_time_ns_delta": 512124,
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
            "avg_ns_per_run": 218.01230425055928,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 660,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 3576,
            "run_time_ns_delta": 779612,
            "type": "kprobe"
          },
          "661": {
            "avg_ns_per_run": 137.09029505865624,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 661,
            "name": "trace_do_mmap",
            "run_cnt_delta": 2813,
            "run_time_ns_delta": 385635,
            "type": "kprobe"
          },
          "662": {
            "avg_ns_per_run": 67.42324093816632,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 662,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 2814,
            "run_time_ns_delta": 189729,
            "type": "kprobe"
          },
          "663": {
            "avg_ns_per_run": 969.2800284292822,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 663,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 2814,
            "run_time_ns_delta": 2727554,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 1486.460764587525,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 664,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 497,
            "run_time_ns_delta": 738771,
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
            "avg_ns_per_run": 461.25468164794006,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 666,
            "name": "trace_security_bpf",
            "run_cnt_delta": 22161,
            "run_time_ns_delta": 10221865,
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
            "avg_ns_per_run": 392.71910291076824,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 669,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 6287,
            "run_time_ns_delta": 2469025,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 1240.7081712062256,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 670,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 514,
            "run_time_ns_delta": 637724,
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
            "avg_ns_per_run": 1813.4786585365853,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 684,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 328,
            "run_time_ns_delta": 594821,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 40.97806283695854,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 685,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 80685,
            "run_time_ns_delta": 3306315,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 2003.1036585365853,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 686,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 164,
            "run_time_ns_delta": 328509,
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
            "avg_ns_per_run": 789.3492063492064,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 690,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 49729,
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
            "avg_ns_per_run": 2850.2901234567903,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 693,
            "name": "trace_do_truncate",
            "run_cnt_delta": 162,
            "run_time_ns_delta": 461747,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 331.0864618885097,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 694,
            "name": "trace_fd_install",
            "run_cnt_delta": 9669,
            "run_time_ns_delta": 3201275,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": 928.5204240926239,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 695,
            "name": "trace_filp_close",
            "run_cnt_delta": 15374,
            "run_time_ns_delta": 14275073,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": 434.20245398773005,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 696,
            "name": "trace_file_update_time",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 70775,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": 220.3680981595092,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 697,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 35920,
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
            "avg_ns_per_run": 160.1341463414634,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 703,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 164,
            "run_time_ns_delta": 26262,
            "type": "kprobe"
          },
          "704": {
            "avg_ns_per_run": 5129.798780487805,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 704,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 164,
            "run_time_ns_delta": 841287,
            "type": "kprobe"
          },
          "705": {
            "avg_ns_per_run": 3567.5565749235475,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 705,
            "name": "trace_execute_finished",
            "run_cnt_delta": 327,
            "run_time_ns_delta": 1166591,
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
            "avg_ns_per_run": 3151.0,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 707,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3151,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": 1289.8333333333333,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 708,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 7739,
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
            "avg_ns_per_run": 529.0,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 711,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 3174,
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
            "avg_ns_per_run": 381.78409090909093,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 714,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 968,
            "run_time_ns_delta": 369567,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": 1167.3626033057851,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 715,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 968,
            "run_time_ns_delta": 1130007,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": 1611.3742331288342,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 716,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 262654,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": 241.33333333333334,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 717,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 174,
            "run_time_ns_delta": 41992,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 629.3333333333334,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 718,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 168,
            "run_time_ns_delta": 105728,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 1426.667175572519,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 719,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 1965,
            "run_time_ns_delta": 2803401,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 1232.6939393939394,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 721,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 990,
            "run_time_ns_delta": 1220367,
            "type": "cgroup_skb"
          },
          "722": {
            "avg_ns_per_run": 1822.920202020202,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 722,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 990,
            "run_time_ns_delta": 1804691,
            "type": "cgroup_skb"
          },
          "723": {
            "avg_ns_per_run": 2335.0,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 723,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2335,
            "type": "raw_tracepoint"
          },
          "724": {
            "avg_ns_per_run": 795.0,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 724,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 795,
            "type": "raw_tracepoint"
          },
          "725": {
            "avg_ns_per_run": 53.78048780487805,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 725,
            "name": "empty_kprobe",
            "run_cnt_delta": 164,
            "run_time_ns_delta": 8820,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": 946.25,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 726,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 164,
            "run_time_ns_delta": 155185,
            "type": "raw_tracepoint"
          },
          "727": {
            "avg_ns_per_run": 681.2101723413199,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 727,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 2379,
            "run_time_ns_delta": 1620599,
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
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 5.014290770999992,
            "ops_per_sec": 32.50708972497284,
            "ops_total": 163.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "prog 665: BPF_PROG_REJIT: Invalid argument (os error 22)",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "570": {
            "avg_ns_per_run": 151.9938586123721,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 570,
            "name": "tracepoint__raw",
            "run_cnt_delta": 2505297,
            "run_time_ns_delta": 380789758,
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
            "avg_ns_per_run": 374.10290598304243,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 573,
            "name": "tracepoint__raw",
            "run_cnt_delta": 2505899,
            "run_time_ns_delta": 937464098,
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
            "avg_ns_per_run": 352.28237751083526,
            "bytes_jited": 8131,
            "bytes_xlated": 13608,
            "id": 576,
            "name": "trace_sys_enter",
            "run_cnt_delta": 2505242,
            "run_time_ns_delta": 882552608,
            "type": "raw_tracepoint"
          },
          "577": {
            "avg_ns_per_run": 316.78610505335394,
            "bytes_jited": 8164,
            "bytes_xlated": 13664,
            "id": 577,
            "name": "trace_sys_exit",
            "run_cnt_delta": 2504594,
            "run_time_ns_delta": 793420578,
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
            "avg_ns_per_run": 1547.4358974358975,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 582,
            "name": "trace_arch_prct",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 241400,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": 1917.5064102564102,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 583,
            "name": "trace_ret_arch_",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 299131,
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
            "avg_ns_per_run": 1777.7770700636943,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 586,
            "name": "trace_dup2",
            "run_cnt_delta": 157,
            "run_time_ns_delta": 279111,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 2824.7006369426754,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 587,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 157,
            "run_time_ns_delta": 443478,
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
            "avg_ns_per_run": 5181.242489270387,
            "bytes_jited": 19847,
            "bytes_xlated": 32320,
            "id": 595,
            "name": "tracepoint__sch",
            "run_cnt_delta": 466,
            "run_time_ns_delta": 2414459,
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
            "avg_ns_per_run": 5438.929487179487,
            "bytes_jited": 20525,
            "bytes_xlated": 35336,
            "id": 603,
            "name": "tracepoint__sch",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 848473,
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
            "avg_ns_per_run": 1810.3390557939915,
            "bytes_jited": 8680,
            "bytes_xlated": 14464,
            "id": 605,
            "name": "tracepoint__sch",
            "run_cnt_delta": 466,
            "run_time_ns_delta": 843618,
            "type": "raw_tracepoint"
          },
          "606": {
            "avg_ns_per_run": 1100.8154506437768,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 606,
            "name": "tracepoint__sch",
            "run_cnt_delta": 466,
            "run_time_ns_delta": 512980,
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
            "avg_ns_per_run": 272.0582964854539,
            "bytes_jited": 8925,
            "bytes_xlated": 14840,
            "id": 608,
            "name": "tracepoint__sch",
            "run_cnt_delta": 249449,
            "run_time_ns_delta": 67864670,
            "type": "raw_tracepoint"
          },
          "609": {
            "avg_ns_per_run": 20.8860103626943,
            "bytes_jited": 8163,
            "bytes_xlated": 13680,
            "id": 609,
            "name": "trace_filldir64",
            "run_cnt_delta": 193,
            "run_time_ns_delta": 4031,
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
            "avg_ns_per_run": 1326.7725321888413,
            "bytes_jited": 7921,
            "bytes_xlated": 13312,
            "id": 611,
            "name": "trace_do_exit",
            "run_cnt_delta": 466,
            "run_time_ns_delta": 618276,
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
            "avg_ns_per_run": 795.5833333333334,
            "bytes_jited": 11470,
            "bytes_xlated": 18264,
            "id": 615,
            "name": "trace_security_",
            "run_cnt_delta": 312,
            "run_time_ns_delta": 248222,
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
            "avg_ns_per_run": 1439.0,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 618,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1439,
            "type": "raw_tracepoint"
          },
          "619": {
            "avg_ns_per_run": 1672.0,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 619,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1672,
            "type": "raw_tracepoint"
          },
          "620": {
            "avg_ns_per_run": 3458.8846153846152,
            "bytes_jited": 33373,
            "bytes_xlated": 52824,
            "id": 620,
            "name": "trace_security_",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 539586,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": 1424.1841990397206,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 621,
            "name": "trace_security_file_open",
            "run_cnt_delta": 2291,
            "run_time_ns_delta": 3262806,
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
            "avg_ns_per_run": 2738.0,
            "bytes_jited": 9984,
            "bytes_xlated": 16352,
            "id": 623,
            "name": "trace_security_",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2738,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": 1556.8910256410256,
            "bytes_jited": 10723,
            "bytes_xlated": 16880,
            "id": 624,
            "name": "trace_commit_cr",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 242875,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": 1059.2210300429185,
            "bytes_jited": 10045,
            "bytes_xlated": 16520,
            "id": 625,
            "name": "trace_switch_ta",
            "run_cnt_delta": 466,
            "run_time_ns_delta": 493597,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 168.53887632317017,
            "bytes_jited": 8174,
            "bytes_xlated": 13680,
            "id": 626,
            "name": "trace_cap_capab",
            "run_cnt_delta": 55265,
            "run_time_ns_delta": 9314301,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 957.7942122186495,
            "bytes_jited": 8471,
            "bytes_xlated": 14120,
            "id": 627,
            "name": "trace_security_",
            "run_cnt_delta": 622,
            "run_time_ns_delta": 595748,
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
            "avg_ns_per_run": 1760.6580645161291,
            "bytes_jited": 10780,
            "bytes_xlated": 16456,
            "id": 632,
            "name": "trace_security_",
            "run_cnt_delta": 155,
            "run_time_ns_delta": 272902,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": 1739.9935897435898,
            "bytes_jited": 10075,
            "bytes_xlated": 15400,
            "id": 633,
            "name": "trace_security_",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 271439,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 2119.7879746835442,
            "bytes_jited": 11260,
            "bytes_xlated": 17192,
            "id": 634,
            "name": "trace_security_",
            "run_cnt_delta": 316,
            "run_time_ns_delta": 669853,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 1689.474358974359,
            "bytes_jited": 10589,
            "bytes_xlated": 16080,
            "id": 635,
            "name": "trace_security_",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 263558,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": 1795.4363636363637,
            "bytes_jited": 11025,
            "bytes_xlated": 16864,
            "id": 636,
            "name": "trace_security_",
            "run_cnt_delta": 165,
            "run_time_ns_delta": 296247,
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
            "avg_ns_per_run": 67.85355732885343,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 639,
            "name": "trace_vfs_write",
            "run_cnt_delta": 59525,
            "run_time_ns_delta": 4038983,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": 39.947135823629246,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 640,
            "name": "vfs_write_magic",
            "run_cnt_delta": 59511,
            "run_time_ns_delta": 2377294,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": 38.89338531863404,
            "bytes_jited": 19108,
            "bytes_xlated": 31720,
            "id": 641,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 59504,
            "run_time_ns_delta": 2314312,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": 53.531381315762935,
            "bytes_jited": 23757,
            "bytes_xlated": 36648,
            "id": 642,
            "name": "vfs_write_magic",
            "run_cnt_delta": 59494,
            "run_time_ns_delta": 3184796,
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
            "avg_ns_per_run": 122.42655767787139,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 654,
            "name": "trace_vfs_read",
            "run_cnt_delta": 11989,
            "run_time_ns_delta": 1467772,
            "type": "kprobe"
          },
          "655": {
            "avg_ns_per_run": 102.60666137985726,
            "bytes_jited": 19111,
            "bytes_xlated": 31720,
            "id": 655,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 3783,
            "run_time_ns_delta": 388161,
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
            "avg_ns_per_run": 240.4430641821946,
            "bytes_jited": 20715,
            "bytes_xlated": 32736,
            "id": 660,
            "name": "trace_mmap_aler",
            "run_cnt_delta": 2898,
            "run_time_ns_delta": 696804,
            "type": "kprobe"
          },
          "661": {
            "avg_ns_per_run": 131.32499066118788,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 661,
            "name": "trace_do_mmap",
            "run_cnt_delta": 2677,
            "run_time_ns_delta": 351557,
            "type": "kprobe"
          },
          "662": {
            "avg_ns_per_run": 72.21441912588719,
            "bytes_jited": 19426,
            "bytes_xlated": 31584,
            "id": 662,
            "name": "trace_ret_do_mm",
            "run_cnt_delta": 2677,
            "run_time_ns_delta": 193318,
            "type": "kprobe"
          },
          "663": {
            "avg_ns_per_run": 957.9667538289129,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 663,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 2677,
            "run_time_ns_delta": 2564477,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 1493.4820295983086,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 664,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 473,
            "run_time_ns_delta": 706417,
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
            "avg_ns_per_run": 421.60414866032846,
            "bytes_jited": 15585,
            "bytes_xlated": 26904,
            "id": 666,
            "name": "trace_security_",
            "run_cnt_delta": 21983,
            "run_time_ns_delta": 9268124,
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
            "avg_ns_per_run": 353.22966818477556,
            "bytes_jited": 8333,
            "bytes_xlated": 13904,
            "id": 669,
            "name": "trace_security_",
            "run_cnt_delta": 6148,
            "run_time_ns_delta": 2171656,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 1078.9941634241245,
            "bytes_jited": 9581,
            "bytes_xlated": 15448,
            "id": 670,
            "name": "trace_security_",
            "run_cnt_delta": 514,
            "run_time_ns_delta": 554603,
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
            "avg_ns_per_run": 1765.0608974358975,
            "bytes_jited": 18482,
            "bytes_xlated": 30352,
            "id": 684,
            "name": "trace_load_elf_",
            "run_cnt_delta": 312,
            "run_time_ns_delta": 550699,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 42.72964648804819,
            "bytes_jited": 8681,
            "bytes_xlated": 14496,
            "id": 685,
            "name": "trace_security_",
            "run_cnt_delta": 73378,
            "run_time_ns_delta": 3135416,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 2230.9166666666665,
            "bytes_jited": 8474,
            "bytes_xlated": 14112,
            "id": 686,
            "name": "tracepoint__tas",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 348023,
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
            "avg_ns_per_run": 695.968253968254,
            "bytes_jited": 10109,
            "bytes_xlated": 16296,
            "id": 690,
            "name": "trace_do_sigact",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 43846,
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
            "avg_ns_per_run": 3025.5974025974024,
            "bytes_jited": 9530,
            "bytes_xlated": 15824,
            "id": 693,
            "name": "trace_do_trunca",
            "run_cnt_delta": 154,
            "run_time_ns_delta": 465942,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 357.13764823229525,
            "bytes_jited": 16708,
            "bytes_xlated": 27176,
            "id": 694,
            "name": "trace_fd_instal",
            "run_cnt_delta": 9023,
            "run_time_ns_delta": 3222453,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": 1020.1092189850909,
            "bytes_jited": 16636,
            "bytes_xlated": 27024,
            "id": 695,
            "name": "trace_filp_clos",
            "run_cnt_delta": 14622,
            "run_time_ns_delta": 14916037,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": 509.85276073619633,
            "bytes_jited": 459,
            "bytes_xlated": 768,
            "id": 696,
            "name": "trace_file_upda",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 83106,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": 373.50306748466255,
            "bytes_jited": 20054,
            "bytes_xlated": 31168,
            "id": 697,
            "name": "trace_ret_file_",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 60881,
            "type": "kprobe"
          },
          "698": {
            "avg_ns_per_run": 466.5,
            "bytes_jited": 459,
            "bytes_xlated": 768,
            "id": 698,
            "name": "trace_file_modi",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 2799,
            "type": "kprobe"
          },
          "699": {
            "avg_ns_per_run": 394.6666666666667,
            "bytes_jited": 20140,
            "bytes_xlated": 31288,
            "id": 699,
            "name": "trace_ret_file_",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 2368,
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
            "avg_ns_per_run": 352.02564102564105,
            "bytes_jited": 16472,
            "bytes_xlated": 28872,
            "id": 703,
            "name": "trace_exec_binp",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 54916,
            "type": "kprobe"
          },
          "704": {
            "avg_ns_per_run": 4969.288461538462,
            "bytes_jited": 16702,
            "bytes_xlated": 29144,
            "id": 704,
            "name": "trace_security_",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 775209,
            "type": "kprobe"
          },
          "705": {
            "avg_ns_per_run": 3803.372990353698,
            "bytes_jited": 24469,
            "bytes_xlated": 38320,
            "id": 705,
            "name": "trace_execute_f",
            "run_cnt_delta": 311,
            "run_time_ns_delta": 1182849,
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
            "avg_ns_per_run": 2949.0,
            "bytes_jited": 18194,
            "bytes_xlated": 29912,
            "id": 707,
            "name": "trace_set_fs_pw",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2949,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": 1088.5,
            "bytes_jited": 8631,
            "bytes_xlated": 14360,
            "id": 708,
            "name": "trace_security_",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 4354,
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
            "avg_ns_per_run": 505.8333333333333,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 711,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 3035,
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
            "avg_ns_per_run": 379.9605543710021,
            "bytes_jited": 329,
            "bytes_xlated": 520,
            "id": 714,
            "name": "trace_sock_allo",
            "run_cnt_delta": 938,
            "run_time_ns_delta": 356403,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": 1321.2046908315565,
            "bytes_jited": 8439,
            "bytes_xlated": 12928,
            "id": 715,
            "name": "trace_ret_sock_",
            "run_cnt_delta": 938,
            "run_time_ns_delta": 1239290,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": 1614.2115384615386,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 716,
            "name": "trace_security_",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 251817,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": 388.9695431472081,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 717,
            "name": "trace_security_",
            "run_cnt_delta": 197,
            "run_time_ns_delta": 76627,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 606.4124293785311,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 718,
            "name": "trace_security_",
            "run_cnt_delta": 177,
            "run_time_ns_delta": 107335,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 1461.3214100570244,
            "bytes_jited": 5282,
            "bytes_xlated": 8136,
            "id": 719,
            "name": "cgroup_bpf_run_",
            "run_cnt_delta": 1929,
            "run_time_ns_delta": 2818889,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 1255.880412371134,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 721,
            "name": "cgroup_skb_ingr",
            "run_cnt_delta": 970,
            "run_time_ns_delta": 1218204,
            "type": "cgroup_skb"
          },
          "722": {
            "avg_ns_per_run": 1817.8278350515463,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 722,
            "name": "cgroup_skb_egre",
            "run_cnt_delta": 970,
            "run_time_ns_delta": 1763293,
            "type": "cgroup_skb"
          },
          "723": {
            "avg_ns_per_run": 2414.0,
            "bytes_jited": 916,
            "bytes_xlated": 1560,
            "id": 723,
            "name": "cgroup_mkdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2414,
            "type": "raw_tracepoint"
          },
          "724": {
            "avg_ns_per_run": 704.0,
            "bytes_jited": 898,
            "bytes_xlated": 1520,
            "id": 724,
            "name": "cgroup_rmdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 704,
            "type": "raw_tracepoint"
          },
          "725": {
            "avg_ns_per_run": 171.30128205128204,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 725,
            "name": "empty_kprobe",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 26723,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": 1035.2051282051282,
            "bytes_jited": 58660,
            "bytes_xlated": 95944,
            "id": 726,
            "name": "tracepoint__exe",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 161492,
            "type": "raw_tracepoint"
          },
          "727": {
            "avg_ns_per_run": 619.2722902097902,
            "bytes_jited": 7290,
            "bytes_xlated": 13264,
            "id": 727,
            "name": "lsm_file_open_t",
            "run_cnt_delta": 2288,
            "run_time_ns_delta": 1416895,
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
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 5.018195846000026,
            "ops_per_sec": 30.887594816282345,
            "ops_total": 155.0,
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
        "output_chars": 2254117,
        "output_stripped": true,
        "program_counts": {
          "applied": 157,
          "not_applied": 1,
          "requested": 158
        }
      },
      "runner": "tracee",
      "selected_workload": "tracee_system_edge_mix",
      "status": "error",
      "workload_miss": false
    },
    {
      "app": "bpftrace/capable",
      "baseline": {
        "bpf": {
          "734": {
            "avg_ns_per_run": 111.54100173043645,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 734,
            "name": "cap_capable",
            "run_cnt_delta": 145628,
            "run_time_ns_delta": 16243493,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0622752510000737,
            "ops_per_sec": 1096.7025720529746,
            "ops_total": 1165.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [31527] setting to a 1 secs run per stressor\nstress-ng: info:  [31527] dispatching hogs: 2 exec\nstress-ng: info:  [31527] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31527] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31527]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31527] exec               1165      1.03      2.50      0.86      1125.78         347.31\nstress-ng: info:  [31527] skipped: 0\nstress-ng: info:  [31527] passed: 2: exec (2)\nstress-ng: info:  [31527] failed: 0\nstress-ng: info:  [31527] metrics untrustworthy: 0\nstress-ng: info:  [31527] successful run completed in 1.05 secs"
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "734": {
            "avg_ns_per_run": 116.17305833954555,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 734,
            "name": "cap_capable",
            "run_cnt_delta": 144876,
            "run_time_ns_delta": 16830688,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.1049800060000052,
            "ops_per_sec": 1070.6076069941073,
            "ops_total": 1183.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [20831] setting to a 1 secs run per stressor\nstress-ng: info:  [20831] dispatching hogs: 2 exec\nstress-ng: info:  [20831] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [20831] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [20831]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [20831] exec               1183      1.06      2.43      0.94      1119.07         350.94\nstress-ng: info:  [20831] skipped: 0\nstress-ng: info:  [20831] passed: 2: exec (2)\nstress-ng: info:  [20831] failed: 0\nstress-ng: info:  [20831] metrics untrustworthy: 0\nstress-ng: info:  [20831] successful run completed in 1.08 secs"
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
        "output_chars": 5258,
        "output_stripped": true,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bpftrace",
      "selected_workload": "exec_storm",
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline": {
        "bpf": {
          "740": {
            "avg_ns_per_run": 170.39964211402415,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 740,
            "name": "block_io_start",
            "run_cnt_delta": 360450,
            "run_time_ns_delta": 61420551,
            "type": "tracepoint"
          },
          "741": {
            "avg_ns_per_run": 296.6200836170042,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 741,
            "name": "block_io_done",
            "run_cnt_delta": 360453,
            "run_time_ns_delta": 106917599,
            "type": "tracepoint"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 5.105342687000075,
            "ops_per_sec": 70602.11666453307,
            "ops_total": 360448.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "740": {
            "avg_ns_per_run": 179.35172799482197,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 740,
            "name": "block_io_start",
            "run_cnt_delta": 352258,
            "run_time_ns_delta": 63178081,
            "type": "tracepoint"
          },
          "741": {
            "avg_ns_per_run": 286.6024169578807,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 741,
            "name": "block_io_done",
            "run_cnt_delta": 352261,
            "run_time_ns_delta": 100958854,
            "type": "tracepoint"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 5.031187135000209,
            "ops_per_sec": 70014.48973135548,
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
        "output_chars": 12594,
        "output_stripped": true,
        "program_counts": {
          "applied": 2,
          "not_applied": 0,
          "requested": 2
        }
      },
      "runner": "bpftrace",
      "selected_workload": "block_io",
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline": {
        "bpf": {
          "747": {
            "avg_ns_per_run": 1107.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 747,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1107,
            "type": "perf_event"
          },
          "748": {
            "avg_ns_per_run": 54.40340991888085,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 748,
            "name": "vfs_create",
            "run_cnt_delta": 20587,
            "run_time_ns_delta": 1120003,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0235600099999829,
            "ops_per_sec": 52.75704352693586,
            "ops_total": 54.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "747": {
            "avg_ns_per_run": 1411.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 747,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1411,
            "type": "perf_event"
          },
          "748": {
            "avg_ns_per_run": 51.073916220165614,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 748,
            "name": "vfs_create",
            "run_cnt_delta": 16424,
            "run_time_ns_delta": 838838,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0032973779998429,
            "ops_per_sec": 52.82581332531729,
            "ops_total": 53.0,
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
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "bpftrace/runqlat",
      "baseline": {
        "bpf": {
          "754": {
            "avg_ns_per_run": 99.28888632086374,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 754,
            "name": "sched_wakeup",
            "run_cnt_delta": 60574,
            "run_time_ns_delta": 6014325,
            "type": "tracepoint"
          },
          "755": {
            "avg_ns_per_run": 219.0789946140036,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 755,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 3342,
            "run_time_ns_delta": 732162,
            "type": "tracepoint"
          },
          "756": {
            "avg_ns_per_run": 159.65382481661837,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 756,
            "name": "sched_switch",
            "run_cnt_delta": 97338,
            "run_time_ns_delta": 15540384,
            "type": "tracepoint"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0002533340000355,
            "ops_per_sec": 12.996707492103734,
            "ops_total": 13.0,
            "stderr": "",
            "stdout": "Running in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.041\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.057\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.052\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.062\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.050"
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "754": {
            "avg_ns_per_run": 105.72779637401662,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 754,
            "name": "sched_wakeup",
            "run_cnt_delta": 58853,
            "run_time_ns_delta": 6222398,
            "type": "tracepoint"
          },
          "755": {
            "avg_ns_per_run": 215.9094917012448,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 755,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 3856,
            "run_time_ns_delta": 832547,
            "type": "tracepoint"
          },
          "756": {
            "avg_ns_per_run": 159.45654319756719,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 756,
            "name": "sched_switch",
            "run_cnt_delta": 100295,
            "run_time_ns_delta": 15992694,
            "type": "tracepoint"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0735782750000453,
            "ops_per_sec": 13.971966785560529,
            "ops_total": 15.0,
            "stderr": "",
            "stdout": "Time: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.049\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.045\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.048\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.045\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.049"
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
        "output_chars": 13107,
        "output_stripped": true,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bpftrace",
      "selected_workload": "hackbench",
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "bpftrace/tcplife",
      "baseline": {
        "bpf": {
          "763": {
            "avg_ns_per_run": 936.9716840536513,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 763,
            "name": "tcp_set_state",
            "run_cnt_delta": 671,
            "run_time_ns_delta": 628708,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0093547889999854,
            "ops_per_sec": 67.36977001651793,
            "ops_total": 68.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "763": {
            "avg_ns_per_run": 956.7579250720461,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 763,
            "name": "tcp_set_state",
            "run_cnt_delta": 694,
            "run_time_ns_delta": 663990,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 1.0118940170000315,
            "ops_per_sec": 69.17720514597906,
            "ops_total": 70.0,
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
      "status": "ok",
      "workload_miss": false
    },
    {
      "app": "bpftrace/tcpretrans",
      "baseline": {
        "bpf": {
          "769": {
            "avg_ns_per_run": 5892.555555555556,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 769,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 18,
            "run_time_ns_delta": 106066,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 8.269574791999958,
            "ops_per_sec": 0.4837008069471271,
            "ops_total": 4.0,
            "stderr": "failed_cycles=3",
            "stdout": "successful_cycles=1"
          }
        ]
      },
      "error": "",
      "limitations": [],
      "post_rejit": {
        "bpf": {
          "769": {
            "avg_ns_per_run": 5997.0,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 769,
            "name": "tcp_retransmit_",
            "run_cnt_delta": 15,
            "run_time_ns_delta": 89955,
            "type": "kprobe"
          }
        },
        "limitations": [],
        "workload_miss": false,
        "workloads": [
          {
            "duration_s": 8.259543067999857,
            "ops_per_sec": 0.4842882913822793,
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
      "status": "ok",
      "workload_miss": false
    }
  ],
  "samples": 1,
  "status": "error",
  "suite_name": "macro_apps",
  "workload_seconds": 1.0
}
```
