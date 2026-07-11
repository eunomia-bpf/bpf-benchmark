# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T15:03:37.686262+00:00",
  "kop_modules": {
    "captured_at": "2026-05-05T15:02:28.287373+00:00",
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
      "invoked_at": "2026-05-05T15:02:28.287307+00:00",
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
        "captured_at": "2026-05-05T15:02:28.287299+00:00",
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
      "captured_at": "2026-05-05T15:02:28.275188+00:00",
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
            "run_cnt_delta": 85004622,
            "run_time_ns_delta": 9183713921,
            "type": "tracepoint"
          },
          "7": {
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 7,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 85005089,
            "run_time_ns_delta": 2372629877,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.044325150000006,
            "ops_per_sec": 2965738.0717036687,
            "ops_total": 9028671.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [19458] setting to a 3 secs run per stressor\nstress-ng: info:  [19458] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 dup, 4 kill, 4 sigfd, 4 signal, 4 pty, 4 itimer, 4 timerfd\nstress-ng: info:  [19458] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19458] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19458]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19458] cap             2549671      3.00      0.81      6.33    849218.13      356657.35\nstress-ng: metrc: [19458] eventfd          978699      3.00      0.59      5.02    326194.32      174581.34\nstress-ng: metrc: [19458] get                7461      3.00      0.13      1.05      2486.62        6357.65\nstress-ng: metrc: [19458] prctl              8467      3.00      2.08      1.03      2819.70        2716.57\nstress-ng: metrc: [19458] set               87508      3.00      0.20      2.95     29135.65       27791.95\nstress-ng: metrc: [19458] dup                4041      3.00      0.69      0.62      1346.95        3079.33\nstress-ng: metrc: [19458] kill             330737      3.00      0.44      4.85    110206.57       62471.55\nstress-ng: metrc: [19458] sigfd           4228782      3.00      0.65      5.74   1408913.33      661735.66\nstress-ng: metrc: [19458] signal                0      3.00      0.01      0.00         0.00           0.00\nstress-ng: metrc: [19458] pty                 225      3.01      0.19      4.13        74.87          52.10\nstress-ng: metrc: [19458] itimer              568      3.00      0.35      4.46       189.33         118.16\nstress-ng: metrc: [19458] timerfd          832512      3.00      0.40      4.57    277107.33      167661.98\nstress-ng: info:  [19458] skipped: 0\nstress-ng: info:  [19458] passed: 48: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4)\nstress-ng: info:  [19458] failed: 0\nstress-ng: info:  [19458] metrics untrustworthy: 0\nstress-ng: info:  [19458] successful run completed in 3.03 secs"
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
            "run_cnt_delta": 82370530,
            "run_time_ns_delta": 9014668117,
            "type": "tracepoint"
          },
          "7": {
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 7,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 82370937,
            "run_time_ns_delta": 2493598298,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.038832579000001,
            "ops_per_sec": 2865492.1828123513,
            "ops_total": 8707751.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [22005] setting to a 3 secs run per stressor\nstress-ng: info:  [22005] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 dup, 4 kill, 4 sigfd, 4 signal, 4 pty, 4 itimer, 4 timerfd\nstress-ng: info:  [22005] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22005] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22005]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22005] cap             1708068      3.00      0.46      4.20    568605.63      366555.58\nstress-ng: metrc: [22005] eventfd         1101929      3.00      0.68      5.46    367044.86      179656.75\nstress-ng: metrc: [22005] get                6248      3.00      0.15      1.17      2080.65        4733.35\nstress-ng: metrc: [22005] prctl              9046      3.00      2.31      0.98      3015.10        2751.10\nstress-ng: metrc: [22005] set               73697      3.00      0.23      2.63     24536.88       25767.07\nstress-ng: metrc: [22005] dup                4198      3.00      0.71      0.59      1399.27        3219.02\nstress-ng: metrc: [22005] kill             343525      3.00      0.22      4.94    114498.32       66489.62\nstress-ng: metrc: [22005] sigfd           4614368      3.00      0.45      6.21   1537461.94      692531.31\nstress-ng: metrc: [22005] signal                0      3.00      0.01      0.03         0.00           0.00\nstress-ng: metrc: [22005] pty               12516      3.00      0.22      5.48      4167.64        2196.61\nstress-ng: metrc: [22005] itimer              620      3.00      0.44      4.96       206.66         114.80\nstress-ng: metrc: [22005] timerfd          833536      3.00      0.54      4.25    277423.07      173942.95\nstress-ng: info:  [22005] skipped: 0\nstress-ng: info:  [22005] passed: 48: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4)\nstress-ng: info:  [22005] failed: 0\nstress-ng: info:  [22005] metrics untrustworthy: 0\nstress-ng: info:  [22005] successful run completed in 3.03 secs"
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
          "87": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 87,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3176,
            "type": "sched_cls"
          },
          "88": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 88,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "89": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 89,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "90": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 90,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "91": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 91,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "92": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 92,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "93": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 93,
            "name": "cil_from_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3695,
            "type": "sched_cls"
          },
          "94": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 94,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "95": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 95,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "96": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 96,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1020,
            "type": "sched_cls"
          },
          "97": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 97,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "98": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 98,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "99": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 99,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "100": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 100,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "101": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 101,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "102": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 102,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "103": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 103,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "104": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 104,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "105": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 105,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "107": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 107,
            "name": "cil_from_netdev",
            "run_cnt_delta": 919,
            "run_time_ns_delta": 1427575,
            "type": "sched_cls"
          },
          "108": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 108,
            "name": "tail_handle_ipv4_from_netdev",
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
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 110,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 6.146537418999998,
            "ops_per_sec": 58.24417482489585,
            "ops_total": 358.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   286.07ms  221.13ms   1.41s    89.91%\n    Req/Sec    21.71     15.11    70.00     66.67%\n  358 requests in 5.01s, 57.56KB read\n  Socket errors: connect 0, read 0, write 0, timeout 11\nRequests/sec:     71.43\nTransfer/sec:     11.48KB"
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
          "87": {
            "bytes_jited": 543,
            "bytes_xlated": 984,
            "id": 87,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2292,
            "type": "sched_cls"
          },
          "88": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 88,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "89": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 89,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "90": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 90,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "91": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 91,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "92": {
            "bytes_jited": 383,
            "bytes_xlated": 712,
            "id": 92,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "93": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 93,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "94": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 94,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "95": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 95,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "96": {
            "bytes_jited": 543,
            "bytes_xlated": 984,
            "id": 96,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "97": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 97,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "98": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 98,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "99": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 99,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "100": {
            "bytes_jited": 383,
            "bytes_xlated": 712,
            "id": 100,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "101": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 101,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "102": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 102,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "103": {
            "bytes_jited": 543,
            "bytes_xlated": 984,
            "id": 103,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "104": {
            "bytes_jited": 383,
            "bytes_xlated": 712,
            "id": 104,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "105": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 105,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "107": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 107,
            "name": "cil_from_netdev",
            "run_cnt_delta": 908,
            "run_time_ns_delta": 1036809,
            "type": "sched_cls"
          },
          "108": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 108,
            "name": "tail_handle_ipv4_from_netdev",
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
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 110,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 6.072224656000003,
            "ops_per_sec": 55.33392109726973,
            "ops_total": 336.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   285.08ms  214.34ms   1.22s    86.85%\n    Req/Sec    22.47     16.45    80.00     61.65%\n  336 requests in 5.01s, 54.23KB read\n  Socket errors: connect 0, read 0, write 0, timeout 9\nRequests/sec:     67.06\nTransfer/sec:     10.82KB"
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
            "prog_id": 88
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
            "prog_id": 89
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
            "prog_id": 97
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
            "prog_id": 98
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
            "prog_id": 105
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
            "prog_id": 107
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
          "applied": 6,
          "not_applied": 19,
          "requested": 25
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
            "run_cnt_delta": 7237147,
            "run_time_ns_delta": 699883702,
            "type": "tracepoint"
          },
          "117": {
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 117,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 27477,
            "type": "tracepoint"
          },
          "118": {
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 118,
            "name": "sched_switch",
            "run_cnt_delta": 25946855,
            "run_time_ns_delta": 4991707710,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.027228670999989,
            "ops_per_sec": 8364526.35460656,
            "ops_total": 25321334.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [8353] setting to a 3 secs run per stressor\nstress-ng: info:  [8353] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [8353] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8353] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8353]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8353] futex           1707916      6.00      1.33      9.51    284632.95      157485.68\nstress-ng: metrc: [8353] sem             4229287      3.00      1.11      2.56   1408837.45     1154374.01\nstress-ng: metrc: [8353] sem-sysv        1114475      3.00      0.48      1.95    371300.67      458080.29\nstress-ng: metrc: [8353] switch          2772378      3.00      0.95      6.70    924003.15      362182.30\nstress-ng: metrc: [8353] yield          15497278      3.00      4.27      9.46   5162652.82     1128649.95\nstress-ng: info:  [8353] skipped: 0\nstress-ng: info:  [8353] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [8353] failed: 0\nstress-ng: info:  [8353] metrics untrustworthy: 0\nstress-ng: info:  [8353] successful run completed in 3.02 secs"
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
            "run_cnt_delta": 5164276,
            "run_time_ns_delta": 706985943,
            "type": "tracepoint"
          },
          "117": {
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 117,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 28483,
            "type": "tracepoint"
          },
          "118": {
            "bytes_jited": 596,
            "bytes_xlated": 1024,
            "id": 118,
            "name": "sched_switch",
            "run_cnt_delta": 22890105,
            "run_time_ns_delta": 4824168746,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0263333999999986,
            "ops_per_sec": 8588505.152803063,
            "ops_total": 25991680.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [8529] setting to a 3 secs run per stressor\nstress-ng: info:  [8529] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [8529] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8529] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8529]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8529] futex           1256520      6.00      1.44      8.48    209333.17      126697.24\nstress-ng: metrc: [8529] sem             6343223      3.00      0.97      3.17   2113843.08     1530777.37\nstress-ng: metrc: [8529] sem-sysv        1345769      3.00      0.32      1.49    448480.76      744676.12\nstress-ng: metrc: [8529] switch          2334742      3.00      0.98      6.39    778172.15      316635.72\nstress-ng: metrc: [8529] yield          14711426      3.00      4.20      9.96   4900873.50     1039002.10\nstress-ng: info:  [8529] skipped: 0\nstress-ng: info:  [8529] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [8529] failed: 0\nstress-ng: info:  [8529] metrics untrustworthy: 0\nstress-ng: info:  [8529] successful run completed in 3.01 secs"
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
