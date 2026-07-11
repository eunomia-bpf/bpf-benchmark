# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T15:13:21.706475+00:00",
  "kop_modules": {
    "captured_at": "2026-05-05T15:12:15.043858+00:00",
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
      "invoked_at": "2026-05-05T15:12:15.043800+00:00",
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
        "captured_at": "2026-05-05T15:12:15.043793+00:00",
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
      "captured_at": "2026-05-05T15:12:15.029367+00:00",
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
  "results": [
    {
      "app": "bcc/syscount",
      "baseline": {
        "bpf": {
          "6": {
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 6,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 76745568,
            "run_time_ns_delta": 8380572850,
            "type": "tracepoint"
          },
          "7": {
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 7,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 76745972,
            "run_time_ns_delta": 2039775404,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.049951727000007,
            "ops_per_sec": 2543298.61398491,
            "ops_total": 7756938.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [19985] setting to a 3 secs run per stressor\nstress-ng: info:  [19985] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 dup, 4 kill, 4 sigfd, 4 signal, 4 pty, 4 itimer, 4 timerfd\nstress-ng: info:  [19985] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19985] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19985]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19985] cap             2316250      3.00      0.57      6.47    772035.18      328784.32\nstress-ng: metrc: [19985] eventfd          920534      3.00      0.77      5.12    306809.91      156329.59\nstress-ng: metrc: [19985] get                7764      3.00      0.10      1.66      2587.37        4417.51\nstress-ng: metrc: [19985] prctl              8996      3.00      2.32      1.01      2997.43        2703.01\nstress-ng: metrc: [19985] set               66942      3.01      0.14      2.28     22253.53       27656.65\nstress-ng: metrc: [19985] dup                4298      3.00      0.74      0.58      1432.45        3253.56\nstress-ng: metrc: [19985] kill             293094      3.00      0.22      4.11     97688.06       67714.71\nstress-ng: metrc: [19985] sigfd           3267546      3.00      0.38      5.33   1088476.75      572046.77\nstress-ng: metrc: [19985] signal                0      3.00      0.06      1.01         0.00           0.00\nstress-ng: metrc: [19985] pty                 519      3.01      0.15      4.57       172.39         109.86\nstress-ng: metrc: [19985] itimer              595      3.00      0.30      4.29       198.26         129.60\nstress-ng: metrc: [19985] timerfd          870400      3.01      0.41      4.74    289619.65      168793.55\nstress-ng: info:  [19985] skipped: 0\nstress-ng: info:  [19985] passed: 48: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4)\nstress-ng: info:  [19985] failed: 0\nstress-ng: info:  [19985] metrics untrustworthy: 0\nstress-ng: info:  [19985] successful run completed in 3.04 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 6,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 76140730,
            "run_time_ns_delta": 8346415792,
            "type": "tracepoint"
          },
          "7": {
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 7,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 76141067,
            "run_time_ns_delta": 2117030564,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.047865846999997,
            "ops_per_sec": 2502083.2224312816,
            "ops_total": 7626014.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [22992] setting to a 3 secs run per stressor\nstress-ng: info:  [22992] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 dup, 4 kill, 4 sigfd, 4 signal, 4 pty, 4 itimer, 4 timerfd\nstress-ng: info:  [22992] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22992] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22992]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22992] cap             1694289      3.01      0.46      4.63    563555.66      332752.59\nstress-ng: metrc: [22992] eventfd         1179742      3.00      0.71      6.13    393205.90      172558.01\nstress-ng: metrc: [22992] get                7911      3.00      0.08      1.16      2635.79        6405.32\nstress-ng: metrc: [22992] prctl             11184      3.00      2.89      1.36      3724.50        2632.54\nstress-ng: metrc: [22992] set               93966      3.00      0.20      3.61     31321.13       24669.25\nstress-ng: metrc: [22992] dup                5171      3.00      0.89      0.82      1723.60        3025.90\nstress-ng: metrc: [22992] kill             217163      3.00      0.29      3.55     72383.53       56506.11\nstress-ng: metrc: [22992] sigfd           3689864      3.01      0.68      5.90   1227354.68      561199.03\nstress-ng: metrc: [22992] signal                0      3.00      0.17      1.20         0.00           0.00\nstress-ng: metrc: [22992] pty                 191      3.01      0.18      4.03        63.44          45.37\nstress-ng: metrc: [22992] itimer              517      3.00      0.42      3.67       172.33         126.21\nstress-ng: metrc: [22992] timerfd          726016      3.00      0.43      3.88    241718.52      168516.52\nstress-ng: info:  [22992] skipped: 0\nstress-ng: info:  [22992] passed: 48: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4)\nstress-ng: info:  [22992] failed: 0\nstress-ng: info:  [22992] metrics untrustworthy: 0\nstress-ng: info:  [22992] successful run completed in 3.04 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "cond_select"
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
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 6
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 7
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
      "app": "cilium/agent",
      "baseline": {
        "bpf": {
          "14": {
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 14,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "15": {
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 15,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "79": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 79,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "80": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 80,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "81": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 81,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "82": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 82,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "83": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 83,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "85": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 85,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "87": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 87,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "88": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 88,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1774,
            "type": "sched_cls"
          },
          "89": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 89,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "90": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 90,
            "name": "cil_from_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1601,
            "type": "sched_cls"
          },
          "91": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 91,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "92": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 92,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "93": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 93,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "94": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 94,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "95": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 95,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "96": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 96,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "97": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 97,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1000,
            "type": "sched_cls"
          },
          "98": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 98,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "99": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 99,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "100": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 100,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "101": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 101,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "102": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 102,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "103": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 103,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "104": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 104,
            "name": "cil_from_netdev",
            "run_cnt_delta": 969,
            "run_time_ns_delta": 1337604,
            "type": "sched_cls"
          },
          "106": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 106,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "107": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 107,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "108": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 108,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "109": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 109,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "110": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 110,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 5.078811185999996,
            "ops_per_sec": 75.60824490946143,
            "ops_total": 384.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   273.17ms  223.90ms   1.47s    87.73%\n    Req/Sec    24.92     18.58    90.00     73.76%\n  384 requests in 5.01s, 61.09KB read\n  Socket errors: connect 0, read 0, write 0, timeout 3\nRequests/sec:     76.63\nTransfer/sec:     12.19KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "14": {
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 14,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "15": {
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 15,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "79": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 79,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "80": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 80,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "81": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 81,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "82": {
            "bytes_jited": 388,
            "bytes_xlated": 720,
            "id": 82,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "83": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 83,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "85": {
            "bytes_jited": 543,
            "bytes_xlated": 984,
            "id": 85,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "87": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 87,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "88": {
            "bytes_jited": 543,
            "bytes_xlated": 984,
            "id": 88,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "89": {
            "bytes_jited": 388,
            "bytes_xlated": 720,
            "id": 89,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "90": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 90,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "91": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 91,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "92": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 92,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "93": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 93,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "94": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 94,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "95": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 95,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "96": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 96,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "97": {
            "bytes_jited": 543,
            "bytes_xlated": 984,
            "id": 97,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "98": {
            "bytes_jited": 388,
            "bytes_xlated": 720,
            "id": 98,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "99": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 99,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "100": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 100,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "101": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 101,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "102": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 102,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "103": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 103,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "104": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 104,
            "name": "cil_from_netdev",
            "run_cnt_delta": 809,
            "run_time_ns_delta": 954588,
            "type": "sched_cls"
          },
          "106": {
            "bytes_jited": 543,
            "bytes_xlated": 984,
            "id": 106,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "107": {
            "bytes_jited": 388,
            "bytes_xlated": 720,
            "id": 107,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "108": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 108,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "109": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 109,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "110": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 110,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 5.0825687610000045,
            "ops_per_sec": 59.02527129627548,
            "ops_total": 300.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   286.34ms  256.24ms   1.62s    90.03%\n    Req/Sec    20.75     14.06    60.00     68.75%\n  300 requests in 5.02s, 48.51KB read\n  Socket errors: connect 0, read 0, write 0, timeout 9\nRequests/sec:     59.82\nTransfer/sec:      9.67KB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "cond_select"
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
                "pass_name": "cond_select",
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
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 15
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 79
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 80
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 81
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 83
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 87
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 90
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 91
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 92
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 93
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 94
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 95
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 96
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 99
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 100
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 101
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
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
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 103
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 104
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 108
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 109
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "cond_select",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 110
          }
        ],
        "program_counts": {
          "applied": 8,
          "not_applied": 23,
          "requested": 31
        }
      },
      "runner": "cilium",
      "selected_workload": "network_lossy_multi",
      "status": "ok"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline": {
        "bpf": {
          "116": {
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 116,
            "name": "sched_wakeup",
            "run_cnt_delta": 7949798,
            "run_time_ns_delta": 647732933,
            "type": "tracepoint"
          },
          "117": {
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 117,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 22549,
            "type": "tracepoint"
          },
          "118": {
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 118,
            "name": "sched_switch",
            "run_cnt_delta": 38075750,
            "run_time_ns_delta": 4929613912,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0211234030000185,
            "ops_per_sec": 12924067.570767734,
            "ops_total": 39045203.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [13425] setting to a 3 secs run per stressor\nstress-ng: info:  [13425] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [13425] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13425] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13425]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13425] futex           3352608      6.00      1.00     15.41    558731.57      204338.16\nstress-ng: metrc: [13425] sem             6548011      3.00      1.29      3.80   2182402.54     1285641.44\nstress-ng: metrc: [13425] sem-sysv        1344980      3.00      0.54      2.40    448176.29      457493.93\nstress-ng: metrc: [13425] switch          2987723      3.00      1.08      7.46    995850.70      350081.87\nstress-ng: metrc: [13425] yield          24811881      3.00      5.77     13.06   8267872.72     1317633.93\nstress-ng: info:  [13425] skipped: 0\nstress-ng: info:  [13425] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [13425] failed: 0\nstress-ng: info:  [13425] metrics untrustworthy: 0\nstress-ng: info:  [13425] successful run completed in 3.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "116": {
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 116,
            "name": "sched_wakeup",
            "run_cnt_delta": 10382435,
            "run_time_ns_delta": 848718964,
            "type": "tracepoint"
          },
          "117": {
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 117,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 20082,
            "type": "tracepoint"
          },
          "118": {
            "bytes_jited": 596,
            "bytes_xlated": 1024,
            "id": 118,
            "name": "sched_switch",
            "run_cnt_delta": 35476145,
            "run_time_ns_delta": 4561235554,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0137278310000113,
            "ops_per_sec": 13514330.186374366,
            "ops_total": 40728513.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [13601] setting to a 3 secs run per stressor\nstress-ng: info:  [13601] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [13601] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13601] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13601]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13601] futex           3622116      6.00      1.12     16.46    603655.67      205974.69\nstress-ng: metrc: [13601] sem             7627189      3.00      1.60      4.74   2542203.69     1203678.62\nstress-ng: metrc: [13601] sem-sysv        1278583      3.00      0.56      2.35    426070.05      438787.69\nstress-ng: metrc: [13601] switch          4072570      3.00      1.19      9.51   1357447.39      380682.68\nstress-ng: metrc: [13601] yield          24128055      3.00      4.32     10.11   8039553.30     1672081.10\nstress-ng: info:  [13601] skipped: 0\nstress-ng: info:  [13601] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [13601] failed: 0\nstress-ng: info:  [13601] metrics untrustworthy: 0\nstress-ng: info:  [13601] successful run completed in 3.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "cond_select"
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
                "pass_name": "cond_select",
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
                "pass_name": "cond_select",
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
          "applied": 1,
          "not_applied": 2,
          "requested": 3
        }
      },
      "runner": "bpftrace",
      "selected_workload": "stress_ng_scheduler",
      "status": "ok"
    }
  ],
  "samples": 1,
  "status": "ok",
  "suite_name": "macro_apps",
  "workload_seconds": 3.0
}
```
