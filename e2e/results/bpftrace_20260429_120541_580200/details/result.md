# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-29T12:07:14.204214+00:00`
- Duration per phase: `5s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Error: `tcplife post_rejit failed: prog 3024: bpfverify final verification failed for prog 3024: subprocess "bpfverify" "--prog-type" "kprobe" "--map-fds" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-603/map_fds.json" "--input" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-603/opt.bin" "--output" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-603/verified.bin" failed: BPF_PROG_LOAD dry-run failed: Permission denied (os error 13)`

## tcplife

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3024": {
        "avg_ns_per_run": 1784.5555555555557,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 3024,
        "name": "tcp_set_state",
        "run_cnt_delta": 9,
        "run_time_ns_delta": 16061,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 12482.277358658846
  },
  "phase": "baseline",
  "reason": "",
  "status": "ok"
}
```

### Post-ReJIT

```json
{
  "measurement": {
    "bpf": {
      "3024": {
        "avg_ns_per_run": 2735.714285714286,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 3024,
        "name": "tcp_set_state",
        "run_cnt_delta": 7,
        "run_time_ns_delta": 19150,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 12438.629078327589
  },
  "phase": "post_rejit",
  "reason": "prog 3024: bpfverify final verification failed for prog 3024: subprocess \"bpfverify\" \"--prog-type\" \"kprobe\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-603/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-603/opt.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-603/verified.bin\" failed: BPF_PROG_LOAD dry-run failed: Permission denied (os error 13)",
  "status": "error"
}
```

### ReJIT Result

```json
{
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
  "error": "prog 3024: bpfverify final verification failed for prog 3024: subprocess \"bpfverify\" \"--prog-type\" \"kprobe\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-603/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-603/opt.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-603/verified.bin\" failed: BPF_PROG_LOAD dry-run failed: Permission denied (os error 13)",
  "error_programs": [
    {
      "applied": false,
      "changed": false,
      "error": "bpfverify final verification failed for prog 3024: subprocess \"bpfverify\" \"--prog-type\" \"kprobe\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-603/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-603/opt.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-603/verified.bin\" failed: BPF_PROG_LOAD dry-run failed: Permission denied (os error 13)",
      "exit_code": 1,
      "prog_id": 3024
    }
  ],
  "exit_code": 1,
  "program_counts": {
    "applied": 0,
    "not_applied": 1,
    "requested": 1
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "PID   COMM       LADDR           LPORT RADDR           RPORT TX_KB RX_KB MS\n15792 stress-ng- 127.0.0.1       34456 127.0.0.1       22084      0 408776 65\n15792 stress-ng- 127.0.0.1       22084 127.0.0.1       34456  408776     0 65\n15822 stress-ng- 127.0.0.1       34464 127.0.0.1       22084      0 406503 50\n15822 stress-ng- 127.0.0.1       22084 127.0.0.1       34464  406376     0 50"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3036": {
        "avg_ns_per_run": 440.19507358484384,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 3036,
        "name": "block_io_start",
        "run_cnt_delta": 61018,
        "run_time_ns_delta": 26859823,
        "type": "tracepoint"
      },
      "3037": {
        "avg_ns_per_run": 1481.264168564547,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 3037,
        "name": "block_io_done",
        "run_cnt_delta": 61033,
        "run_time_ns_delta": 90405996,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 10448.365532228021
  },
  "phase": "baseline",
  "reason": "",
  "status": "ok"
}
```

### Post-ReJIT

```json
{
  "measurement": {
    "bpf": {
      "3036": {
        "avg_ns_per_run": 414.3705945116868,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 3036,
        "name": "block_io_start",
        "run_cnt_delta": 59982,
        "run_time_ns_delta": 24854777,
        "type": "tracepoint"
      },
      "3037": {
        "avg_ns_per_run": 1433.7475207093687,
        "bytes_jited": 889,
        "bytes_xlated": 1488,
        "id": 3037,
        "name": "block_io_done",
        "run_cnt_delta": 59997,
        "run_time_ns_delta": 86020550,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 8614.4504196046
  },
  "phase": "post_rejit",
  "reason": "",
  "status": "ok"
}
```

### ReJIT Result

```json
{
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
  "noop_programs": [
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3036
    }
  ],
  "program_counts": {
    "applied": 1,
    "not_applied": 1,
    "requested": 2
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "20476        7     0        fio              15885        0\n20476        7     0        fio              15884        0\n20476        7     0        fio              15886        0\n20476        7     0        fio              15883        0\n20477        7     0        fio              15885        0\n20477        7     0        fio              15884        0\n20477        7     0        fio              15886        0\n20477        7     0        fio              15883        0\n20477        7     0        fio              15885        0\n20477        7     0        fio              15884        0\n20477        7     0        fio              15886        0\n20477        7     0        fio              15883        0\n20477        7     0        fio              15885        0\n20477        7     0        fio              15884        0\n20477        7     0        fio              15886        0\n20477        7     0        fio              15883        0\n20477        7     0        fio              15885        0\n20477        7     0        fio              15884        0\n20477        7     0        fio              15886        0\n20477        7     0        fio              15883        0\n20478        7     0        fio              15885        0\n20478        7     0        fio              15884        0\n20478        7     0        fio              15886        0\n20478        7     0        fio              15883        0\n20478        7     0        fio              15885        0\n20478        7     0        jbd2/loop0-8     1368         0\n20478        7     0        fio              15884        0\n20478        7     0        fio              15883        0\n20478        7     0        fio              15885        0\n20478        7     0        fio              15886        0\n20478        7     0        fio              15884        0\n20478        7     0        fio              15883        0\n20478        7     0        fio              15885        0\n20478        7     0        fio              15886        0\n20479        7     0        fio              15884        0\n20512        7     0        fio              15883       33\n20513        7     0        fio              15885       34\n20708        7     0        fio              15886      229\n20708        7     0        jbd2/loop0-8     1368       230\n20709        7     0        fio              15884      230"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3053": {
        "avg_ns_per_run": 243.86051375906922,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 3053,
        "name": "sched_wakeup",
        "run_cnt_delta": 15299,
        "run_time_ns_delta": 3730822,
        "type": "tracepoint"
      },
      "3054": {
        "avg_ns_per_run": 267.14232209737827,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 3054,
        "name": "tracepoint_sched_sched_wakeup_new",
        "run_cnt_delta": 534,
        "run_time_ns_delta": 142654,
        "type": "tracepoint"
      },
      "3055": {
        "avg_ns_per_run": 176.88643573150617,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 3055,
        "name": "sched_switch",
        "run_cnt_delta": 31524,
        "run_time_ns_delta": 5576168,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 1115.3180198033233
  },
  "phase": "baseline",
  "reason": "",
  "status": "ok"
}
```

### Post-ReJIT

```json
{
  "measurement": {
    "bpf": {
      "3053": {
        "avg_ns_per_run": 470.95728960173005,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 3053,
        "name": "sched_wakeup",
        "run_cnt_delta": 5549,
        "run_time_ns_delta": 2613342,
        "type": "tracepoint"
      },
      "3054": {
        "avg_ns_per_run": 264.46828358208955,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 3054,
        "name": "tracepoint_sched_sched_wakeup_new",
        "run_cnt_delta": 536,
        "run_time_ns_delta": 141755,
        "type": "tracepoint"
      },
      "3055": {
        "avg_ns_per_run": 303.84154100932625,
        "bytes_jited": 506,
        "bytes_xlated": 872,
        "id": 3055,
        "name": "sched_switch",
        "run_cnt_delta": 11473,
        "run_time_ns_delta": 3485974,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 1117.6206036656931
  },
  "phase": "post_rejit",
  "reason": "",
  "status": "ok"
}
```

### ReJIT Result

```json
{
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
  "noop_programs": [
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3053
    },
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3054
    }
  ],
  "program_counts": {
    "applied": 1,
    "not_applied": 2,
    "requested": 3
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "Tracing CPU scheduler... Hit Ctrl-C to end.\n@usecs:\n[0]                18570 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n[1]                 2029 |@@@@@                                               |\n[2, 4)              1813 |@@@@@                                               |\n[4, 8)               346 |                                                    |\n[8, 16)              599 |@                                                   |\n[16, 32)             271 |                                                    |\n[32, 64)             155 |                                                    |\n[64, 128)            106 |                                                    |\n[128, 256)            53 |                                                    |\n[256, 512)             6 |                                                    |\n[512, 1K)              6 |                                                    |\n[1K, 2K)               4 |                                                    |\n[2K, 4K)               2 |                                                    |"
}
```

## tcpretrans

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3074": {
        "avg_ns_per_run": null,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 3074,
        "name": "kprobe_tcp_retransmit_skb",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 12562.634544739876
  },
  "phase": "baseline",
  "reason": "",
  "status": "ok"
}
```

### Post-ReJIT

```json
{
  "measurement": {
    "bpf": {
      "3074": {
        "avg_ns_per_run": null,
        "bytes_jited": 926,
        "bytes_xlated": 1568,
        "id": 3074,
        "name": "tcp_retransmit_",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 7992.166876656204
  },
  "phase": "post_rejit",
  "reason": "",
  "status": "ok"
}
```

### ReJIT Result

```json
{
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
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "Tracing tcp retransmits. Hit Ctrl-C to end.\nTIME     PID               LADDR:LPORT           RADDR:RPORT  STATE"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3087": {
        "avg_ns_per_run": 185.08811400588502,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 3087,
        "name": "cap_capable",
        "run_cnt_delta": 93118,
        "run_time_ns_delta": 17235035,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 12621.394996310648
  },
  "phase": "baseline",
  "reason": "",
  "status": "ok"
}
```

### Post-ReJIT

```json
{
  "measurement": {
    "bpf": {
      "3087": {
        "avg_ns_per_run": 200.6099339526392,
        "bytes_jited": 697,
        "bytes_xlated": 1216,
        "id": 3087,
        "name": "cap_capable",
        "run_cnt_delta": 93115,
        "run_time_ns_delta": 18679794,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 13416.338275343362
  },
  "phase": "post_rejit",
  "reason": "",
  "status": "ok"
}
```

### ReJIT Result

```json
{
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
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "12:06:39  0      19130  stress-ng        21   CAP_SYS_ADMIN        2\n12:06:39  0      19130  stress-ng        21   CAP_SYS_ADMIN        2\n12:06:39  0      19130  stress-ng        21   CAP_SYS_ADMIN        2\n12:06:39  0      19130  stress-ng        21   CAP_SYS_ADMIN        2\n12:06:39  0      19130  stress-ng        21   CAP_SYS_ADMIN        2\n12:06:39  0      19130  stress-ng        21   CAP_SYS_ADMIN        2\n12:06:39  0      19131  stress-ng-timer  24   CAP_SYS_RESOURCE     2\n12:06:39  0      19131  stress-ng-timer  21   CAP_SYS_ADMIN        0\n12:06:39  0      19131  stress-ng-timer  21   CAP_SYS_ADMIN        0\n12:06:39  0      19131  stress-ng-timer  21   CAP_SYS_ADMIN        0\n12:06:39  0      19131  stress-ng-timer  21   CAP_SYS_ADMIN        0\n12:06:39  0      19132  python3          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        2\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        0\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        0\n12:06:39  0      19132  bpftool          39   CAP_BPF              0\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        0\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        0\n12:06:39  0      19132  bpftool          39   CAP_BPF              0\n12:06:39  0      19132  bpftool          39   CAP_BPF              0\n12:06:39  0      19132  bpftool          39   CAP_BPF              0\n12:06:39  0      19132  bpftool          39   CAP_BPF              0\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        0\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        0\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        0\n12:06:39  0      19132  bpftool          21   CAP_SYS_ADMIN        0"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3100": {
        "avg_ns_per_run": 2734.6428571428573,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 3100,
        "name": "1",
        "run_cnt_delta": 14,
        "run_time_ns_delta": 38285,
        "type": "perf_event"
      },
      "3101": {
        "avg_ns_per_run": 45.756691225720026,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 3101,
        "name": "vfs_create",
        "run_cnt_delta": 74650,
        "run_time_ns_delta": 3415737,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 604.0594537168397
  },
  "phase": "baseline",
  "reason": "",
  "status": "ok"
}
```

### Post-ReJIT

```json
{
  "measurement": {
    "bpf": {
      "3100": {
        "avg_ns_per_run": 3663.8125,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 3100,
        "name": "1",
        "run_cnt_delta": 16,
        "run_time_ns_delta": 58621,
        "type": "perf_event"
      },
      "3101": {
        "avg_ns_per_run": 48.908425585880735,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 3101,
        "name": "vfs_create",
        "run_cnt_delta": 75698,
        "run_time_ns_delta": 3702270,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 511.0871444395132
  },
  "phase": "post_rejit",
  "reason": "",
  "status": "ok"
}
```

### ReJIT Result

```json
{
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
  "noop_programs": [
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3100
    },
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3101
    }
  ],
  "program_counts": {
    "applied": 0,
    "not_applied": 2,
    "requested": 2
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "12:07:04\n@[vfs_read]: 1\n@[vfs_write]: 1\n12:07:05\n@[vfs_read]: 2\n@[vfs_write]: 2\n12:07:06\n@[vfs_writev]: 1\n@[vfs_readv]: 1\n@[vfs_create]: 2\n@[vfs_fsync]: 2\n@[vfs_write]: 186\n@[vfs_read]: 1517\n@[vfs_open]: 2737\n12:07:07\n@[vfs_create]: 10\n@[vfs_write]: 11\n@[vfs_read]: 14\n@[vfs_open]: 38\n12:07:08\n@[vfs_create]: 10\n@[vfs_write]: 14\n@[vfs_read]: 19\n@[vfs_open]: 40\n12:07:09\n@[vfs_create]: 11\n@[vfs_write]: 13\n@[vfs_read]: 15\n@[vfs_open]: 42\n12:07:10\n@[vfs_write]: 9\n@[vfs_create]: 9\n@[vfs_read]: 13\n@[vfs_open]: 34\n12:07:11\n@[vfs_fsync]: 1\n@[vfs_create]: 12\n@[vfs_write]: 15\n@[vfs_read]: 17\n@[vfs_open]: 44"
}
```

