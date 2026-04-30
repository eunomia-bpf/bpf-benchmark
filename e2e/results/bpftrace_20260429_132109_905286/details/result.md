# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-29T13:22:47.945564+00:00`
- Duration per phase: `5s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Error: `tcplife post_rejit failed: prog 3097: bpfverify final verification failed for prog 3097: subprocess "bpfverify" "--prog-type" "kprobe" "--map-fds" "/var/tmp/bpfrejit-runtime/run.aws-x86.e2e.2cf43c71/bpfrejit-daemon-optimize-2732-603/map_fds.json" "--input" "/var/tmp/bpfrejit-runtime/run.aws-x86.e2e.2cf43c71/bpfrejit-daemon-optimize-2732-603/opt.bin" "--output" "/var/tmp/bpfrejit-runtime/run.aws-x86.e2e.2cf43c71/bpfrejit-daemon-optimize-2732-603/verified.bin" failed: BPF_PROG_LOAD dry-run failed: Permission denied (os error 13)`

## tcplife

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3097": {
        "avg_ns_per_run": 3387.8,
        "bytes_jited": 2021,
        "bytes_xlated": 3384,
        "id": 3097,
        "name": "tcp_set_state",
        "run_cnt_delta": 15,
        "run_time_ns_delta": 50817,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 3803.614284128309
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
      "3097": {
        "avg_ns_per_run": 2407.875,
        "bytes_jited": 2021,
        "bytes_xlated": 3384,
        "id": 3097,
        "name": "tcp_set_state",
        "run_cnt_delta": 8,
        "run_time_ns_delta": 19263,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 3846.7364728173943
  },
  "phase": "post_rejit",
  "reason": "prog 3097: bpfverify final verification failed for prog 3097: subprocess \"bpfverify\" \"--prog-type\" \"kprobe\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.aws-x86.e2e.2cf43c71/bpfrejit-daemon-optimize-2732-603/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.aws-x86.e2e.2cf43c71/bpfrejit-daemon-optimize-2732-603/opt.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.aws-x86.e2e.2cf43c71/bpfrejit-daemon-optimize-2732-603/verified.bin\" failed: BPF_PROG_LOAD dry-run failed: Permission denied (os error 13)",
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
  "error": "prog 3097: bpfverify final verification failed for prog 3097: subprocess \"bpfverify\" \"--prog-type\" \"kprobe\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.aws-x86.e2e.2cf43c71/bpfrejit-daemon-optimize-2732-603/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.aws-x86.e2e.2cf43c71/bpfrejit-daemon-optimize-2732-603/opt.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.aws-x86.e2e.2cf43c71/bpfrejit-daemon-optimize-2732-603/verified.bin\" failed: BPF_PROG_LOAD dry-run failed: Permission denied (os error 13)",
  "error_programs": [
    {
      "applied": false,
      "changed": false,
      "error": "bpfverify final verification failed for prog 3097: subprocess \"bpfverify\" \"--prog-type\" \"kprobe\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.aws-x86.e2e.2cf43c71/bpfrejit-daemon-optimize-2732-603/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.aws-x86.e2e.2cf43c71/bpfrejit-daemon-optimize-2732-603/opt.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.aws-x86.e2e.2cf43c71/bpfrejit-daemon-optimize-2732-603/verified.bin\" failed: BPF_PROG_LOAD dry-run failed: Permission denied (os error 13)",
      "exit_code": 1,
      "prog_id": 3097
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
  "stdout_tail": "PID   COMM       LADDR           LPORT RADDR           RPORT TX_KB RX_KB MS\n13029 sshd       172.31.74.6     22    128.114.59.195  37038      3     2 994\n13030 sshd       172.31.74.6     22    128.114.59.195  37048      6     2 991\n13097 stress-ng- 127.0.0.1       56100 127.0.0.1       23007      0 408776 219\n13097 stress-ng- 127.0.0.1       23007 127.0.0.1       56100  408776     0 219\n13127 stress-ng- 127.0.0.1       56112 127.0.0.1       23007      0 408800 215\n13127 stress-ng- 127.0.0.1       23007 127.0.0.1       56112  408800     0 215"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3109": {
        "avg_ns_per_run": 1284.955733169382,
        "bytes_jited": 226,
        "bytes_xlated": 408,
        "id": 3109,
        "name": "block_io_start",
        "run_cnt_delta": 19518,
        "run_time_ns_delta": 25079766,
        "type": "tracepoint"
      },
      "3110": {
        "avg_ns_per_run": 1652.2572029119244,
        "bytes_jited": 935,
        "bytes_xlated": 1576,
        "id": 3110,
        "name": "block_io_done",
        "run_cnt_delta": 19506,
        "run_time_ns_delta": 32228929,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 5392.67467932153
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
      "3109": {
        "avg_ns_per_run": 1260.020467989321,
        "bytes_jited": 226,
        "bytes_xlated": 408,
        "id": 3109,
        "name": "block_io_start",
        "run_cnt_delta": 19103,
        "run_time_ns_delta": 24070171,
        "type": "tracepoint"
      },
      "3110": {
        "avg_ns_per_run": 1555.301336127849,
        "bytes_jited": 893,
        "bytes_xlated": 1488,
        "id": 3110,
        "name": "block_io_done",
        "run_cnt_delta": 19085,
        "run_time_ns_delta": 29682926,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 5669.371038927992
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
      "prog_id": 3109
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
  "stdout_tail": "15254        259   0        fio              13193        1\n15254        259   0        fio              13195        1\n15255        259   0        fio              13194        1\n15255        259   0        fio              13196        1\n15255        259   0        fio              13193        1\n15256        259   0        fio              13195        1\n15256        259   0        fio              13194        1\n15256        259   0        fio              13196        1\n15257        259   0        fio              13193        1\n15257        259   0        fio              13195        0\n15257        259   0        fio              13194        1\n15258        259   0        fio              13196        1\n15258        259   0        fio              13193        1\n15258        259   0        fio              13195        1\n15259        259   0        fio              13194        1\n15259        259   0        fio              13196        1\n15259        259   0        fio              13193        1\n15260        259   0        fio              13195        1\n15260        259   0        fio              13194        1\n15260        259   0        fio              13196        1\n15261        259   0        fio              13193        1\n15261        259   0        fio              13195        1\n15261        259   0        fio              13194        1\n15262        259   0        fio              13196        1\n15262        259   0        fio              13193        1\n15262        259   0        fio              13195        1\n15263        259   0        fio              13194        1\n15263        259   0        fio              13196        1\n15264        259   0        fio              13193        1\n15264        259   0        fio              13195        1\n15264        259   0        fio              13194        1\n15264        259   0        fio              13196        1\n15265        259   0        fio              13193        1\n15265        259   0        fio              13195        1\n15265        259   0        fio              13194        1\n15266        259   0        fio              13196        1\n15266        259   0        fio              13193        1\n15266        259   0        fio              13195        1\n15267        259   0        fio              13194        1\n15268        259   0        fio              13196        2"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3126": {
        "avg_ns_per_run": 527.2961876832844,
        "bytes_jited": 90,
        "bytes_xlated": 136,
        "id": 3126,
        "name": "sched_wakeup",
        "run_cnt_delta": 5797,
        "run_time_ns_delta": 3056736,
        "type": "tracepoint"
      },
      "3127": {
        "avg_ns_per_run": 427.4570895522388,
        "bytes_jited": 90,
        "bytes_xlated": 136,
        "id": 3127,
        "name": "tracepoint_sched_sched_wakeup_new",
        "run_cnt_delta": 536,
        "run_time_ns_delta": 229117,
        "type": "tracepoint"
      },
      "3128": {
        "avg_ns_per_run": 395.0170222255259,
        "bytes_jited": 519,
        "bytes_xlated": 896,
        "id": 3128,
        "name": "sched_switch",
        "run_cnt_delta": 13453,
        "run_time_ns_delta": 5314164,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 1072.8246891132821
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
      "3126": {
        "avg_ns_per_run": 568.6991438356164,
        "bytes_jited": 90,
        "bytes_xlated": 136,
        "id": 3126,
        "name": "sched_wakeup",
        "run_cnt_delta": 5840,
        "run_time_ns_delta": 3321203,
        "type": "tracepoint"
      },
      "3127": {
        "avg_ns_per_run": 458.2313432835821,
        "bytes_jited": 90,
        "bytes_xlated": 136,
        "id": 3127,
        "name": "tracepoint_sched_sched_wakeup_new",
        "run_cnt_delta": 536,
        "run_time_ns_delta": 245612,
        "type": "tracepoint"
      },
      "3128": {
        "avg_ns_per_run": 422.3751060820368,
        "bytes_jited": 510,
        "bytes_xlated": 872,
        "id": 3128,
        "name": "sched_switch",
        "run_cnt_delta": 14140,
        "run_time_ns_delta": 5972384,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 1072.5949020414146
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
      "prog_id": 3126
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
      "prog_id": 3127
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
  "stdout_tail": "Tracing CPU scheduler... Hit Ctrl-C to end.\n@usecs:\n[0]                   51 |                                                    |\n[1]                 9778 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n[2, 4)              4470 |@@@@@@@@@@@@@@@@@@@@@@@                             |\n[4, 8)              1804 |@@@@@@@@@                                           |\n[8, 16)             1130 |@@@@@@                                              |\n[16, 32)             526 |@@                                                  |\n[32, 64)              50 |                                                    |\n[64, 128)             31 |                                                    |\n[128, 256)            25 |                                                    |\n[256, 512)            35 |                                                    |\n[512, 1K)             34 |                                                    |\n[1K, 2K)              36 |                                                    |\n[2K, 4K)              42 |                                                    |\n[4K, 8K)               9 |                                                    |\n[8K, 16K)              4 |                                                    |"
}
```

## tcpretrans

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3147": {
        "avg_ns_per_run": null,
        "bytes_jited": 972,
        "bytes_xlated": 1640,
        "id": 3147,
        "name": "kprobe_tcp_retransmit_skb",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 5038.199221465176
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
      "3147": {
        "avg_ns_per_run": null,
        "bytes_jited": 930,
        "bytes_xlated": 1568,
        "id": 3147,
        "name": "tcp_retransmit_",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 5034.586473826269
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
      "3160": {
        "avg_ns_per_run": 1631.2806612882462,
        "bytes_jited": 773,
        "bytes_xlated": 1360,
        "id": 3160,
        "name": "cap_capable",
        "run_cnt_delta": 93212,
        "run_time_ns_delta": 152054933,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2379.4149118051746
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
      "3160": {
        "avg_ns_per_run": 1773.1340112194441,
        "bytes_jited": 701,
        "bytes_xlated": 1216,
        "id": 3160,
        "name": "cap_capable",
        "run_cnt_delta": 93231,
        "run_time_ns_delta": 165311057,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2212.595594665527
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
  "stdout_tail": "13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          39   CAP_BPF              0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          39   CAP_BPF              0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          39   CAP_BPF              0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          39   CAP_BPF              0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          39   CAP_BPF              0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          39   CAP_BPF              0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          39   CAP_BPF              0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          39   CAP_BPF              0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          39   CAP_BPF              0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          39   CAP_BPF              0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          39   CAP_BPF              0\n13:22:12  0      16447  bpftool          39   CAP_BPF              0\n13:22:12  0      16447  bpftool          39   CAP_BPF              0\n13:22:12  0      16447  bpftool          39   CAP_BPF              0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0\n13:22:12  0      16447  bpftool          21   CAP_SYS_ADMIN        0"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3173": {
        "avg_ns_per_run": 2273.0,
        "bytes_jited": 366,
        "bytes_xlated": 680,
        "id": 3173,
        "name": "1",
        "run_cnt_delta": 15,
        "run_time_ns_delta": 34095,
        "type": "perf_event"
      },
      "3174": {
        "avg_ns_per_run": 96.1119428459963,
        "bytes_jited": 144,
        "bytes_xlated": 224,
        "id": 3174,
        "name": "vfs_create",
        "run_cnt_delta": 41012,
        "run_time_ns_delta": 3941743,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 559.3307271504689
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
      "3173": {
        "avg_ns_per_run": 2156.0,
        "bytes_jited": 366,
        "bytes_xlated": 680,
        "id": 3173,
        "name": "1",
        "run_cnt_delta": 15,
        "run_time_ns_delta": 32340,
        "type": "perf_event"
      },
      "3174": {
        "avg_ns_per_run": 93.47876064450458,
        "bytes_jited": 144,
        "bytes_xlated": 224,
        "id": 3174,
        "name": "vfs_create",
        "run_cnt_delta": 40279,
        "run_time_ns_delta": 3765231,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 552.5688138629148
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
      "prog_id": 3173
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
      "prog_id": 3174
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
  "stdout_tail": "@[vfs_open]: 4333\n13:22:36\n@[vfs_read]: 650\n@[vfs_open]: 963\n@[vfs_write]: 4322\n13:22:37\n@[vfs_read]: 5\n@[vfs_write]: 7\n13:22:38\n@[vfs_write]: 7\n@[vfs_open]: 15\n@[vfs_read]: 18\n13:22:39\n@[vfs_read]: 7\n@[vfs_write]: 8\n13:22:40\n@[vfs_write]: 5\n@[vfs_read]: 6\n13:22:41\n@[vfs_readv]: 1\n@[vfs_writev]: 1\n@[vfs_write]: 197\n@[vfs_read]: 863\n@[vfs_open]: 2047\n13:22:42\n@[vfs_write]: 18\n@[vfs_read]: 23\n@[vfs_open]: 26\n13:22:43\n@[vfs_write]: 19\n@[vfs_read]: 22\n@[vfs_open]: 28\n13:22:44\n@[vfs_write]: 16\n@[vfs_read]: 21\n@[vfs_open]: 25\n13:22:45\n@[vfs_write]: 23\n@[vfs_read]: 29\n@[vfs_open]: 36"
}
```

