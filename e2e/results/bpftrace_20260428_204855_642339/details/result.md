# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-28T20:50:35.696898+00:00`
- Duration per phase: `5s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## tcplife

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1424": {
        "avg_ns_per_run": 3852.0,
        "bytes_jited": 2021,
        "bytes_xlated": 3384,
        "id": 1424,
        "name": "tcp_set_state",
        "run_cnt_delta": 10,
        "run_time_ns_delta": 38520,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 4906.706674195916
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
      "1424": {
        "avg_ns_per_run": 2496.625,
        "bytes_jited": 2021,
        "bytes_xlated": 3384,
        "id": 1424,
        "name": "tcp_set_state",
        "run_cnt_delta": 8,
        "run_time_ns_delta": 19973,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 3203.854314638295
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
  "stdout_tail": "PID   COMM       LADDR           LPORT RADDR           RPORT TX_KB RX_KB MS\n9580  stress-ng- 127.0.0.1       54102 127.0.0.1       23007      0 408768 206\n9579  stress-ng- 127.0.0.1       23007 127.0.0.1       54102  408768     0 206\n9604  stress-ng- 127.0.0.1       54116 127.0.0.1       23007      0 408800 412\n9604  stress-ng- 127.0.0.1       23007 127.0.0.1       54116  408800     0 412"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1431": {
        "avg_ns_per_run": 1480.2266919800913,
        "bytes_jited": 226,
        "bytes_xlated": 408,
        "id": 1431,
        "name": "block_io_start",
        "run_cnt_delta": 19489,
        "run_time_ns_delta": 28848138,
        "type": "tracepoint"
      },
      "1432": {
        "avg_ns_per_run": 2065.4479054227704,
        "bytes_jited": 935,
        "bytes_xlated": 1576,
        "id": 1432,
        "name": "block_io_done",
        "run_cnt_delta": 19455,
        "run_time_ns_delta": 40183289,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 5450.714759513095
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
      "1431": {
        "avg_ns_per_run": 1506.9679315593344,
        "bytes_jited": 226,
        "bytes_xlated": 408,
        "id": 1431,
        "name": "block_io_start",
        "run_cnt_delta": 19053,
        "run_time_ns_delta": 28712260,
        "type": "tracepoint"
      },
      "1432": {
        "avg_ns_per_run": 2125.372488164124,
        "bytes_jited": 935,
        "bytes_xlated": 1576,
        "id": 1432,
        "name": "block_io_done",
        "run_cnt_delta": 19010,
        "run_time_ns_delta": 40403331,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 5690.420738276973
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
  "stdout_tail": "15266        259   0        fio              9658         0\n15266        259   0        fio              9659         1\n15267        259   0        fio              9660         1\n15267        259   0        fio              9661         1\n15267        259   0        fio              9658         1\n15268        259   0        fio              9659         1\n15268        259   0        fio              9660         1\n15268        259   0        fio              9661         1\n15269        259   0        fio              9658         1\n15269        259   0        fio              9659         1\n15269        259   0        fio              9660         1\n15270        259   0        fio              9661         1\n15270        259   0        fio              9658         1\n15270        259   0        fio              9659         1\n15270        259   0        fio              9660         1\n15271        259   0        fio              9661         1\n15271        259   0        fio              9658         1\n15272        259   0        fio              9659         1\n15272        259   0        fio              9660         1\n15272        259   0        fio              9661         1\n15273        259   0        fio              9658         1\n15273        259   0        fio              9659         1\n15274        259   0        fio              9661         1\n15274        259   0        fio              9660         1\n15274        259   0        fio              9658         1\n15274        259   0        fio              9659         1\n15275        259   0        fio              9661         1\n15275        259   0        fio              9660         1\n15275        259   0        fio              9658         1\n15275        259   0        fio              9659         0\n15276        259   0        fio              9661         1\n15276        259   0        fio              9660         1\n15277        259   0        fio              9658         1\n15277        259   0        fio              9659         1\n15277        259   0        fio              9661         1\n15278        259   0        fio              9660         1\n15278        259   0        fio              9658         1\n15278        259   0        fio              9659         1\n15279        259   0        fio              9661         1\n15279        259   0        fio              9660         1"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1439": {
        "avg_ns_per_run": 1110.5638857572342,
        "bytes_jited": 90,
        "bytes_xlated": 136,
        "id": 1439,
        "name": "sched_wakeup",
        "run_cnt_delta": 5322,
        "run_time_ns_delta": 5910421,
        "type": "tracepoint"
      },
      "1440": {
        "avg_ns_per_run": 504.3063909774436,
        "bytes_jited": 90,
        "bytes_xlated": 136,
        "id": 1440,
        "name": "tracepoint_sched_sched_wakeup_new",
        "run_cnt_delta": 532,
        "run_time_ns_delta": 268291,
        "type": "tracepoint"
      },
      "1441": {
        "avg_ns_per_run": 496.968996782685,
        "bytes_jited": 519,
        "bytes_xlated": 896,
        "id": 1441,
        "name": "sched_switch",
        "run_cnt_delta": 10257,
        "run_time_ns_delta": 5097411,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 1072.3276504395217
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
      "1439": {
        "avg_ns_per_run": 857.9001596027664,
        "bytes_jited": 90,
        "bytes_xlated": 136,
        "id": 1439,
        "name": "sched_wakeup",
        "run_cnt_delta": 5639,
        "run_time_ns_delta": 4837699,
        "type": "tracepoint"
      },
      "1440": {
        "avg_ns_per_run": 519.1603773584906,
        "bytes_jited": 90,
        "bytes_xlated": 136,
        "id": 1440,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 530,
        "run_time_ns_delta": 275155,
        "type": "tracepoint"
      },
      "1441": {
        "avg_ns_per_run": 470.4985580122754,
        "bytes_jited": 519,
        "bytes_xlated": 896,
        "id": 1441,
        "name": "sched_switch",
        "run_cnt_delta": 13523,
        "run_time_ns_delta": 6362552,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 1069.010718142385
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
  "program_counts": {
    "applied": 0,
    "not_applied": 3,
    "requested": 3
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "Tracing CPU scheduler... Hit Ctrl-C to end.\n@usecs:\n[0]                    1 |                                                    |\n[1]                 4174 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n[2, 4)              3711 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      |\n[4, 8)              2997 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@               |\n[8, 16)             2155 |@@@@@@@@@@@@@@@@@@@@@@@@@@                          |\n[16, 32)             906 |@@@@@@@@@@@                                         |\n[32, 64)              72 |                                                    |\n[64, 128)            151 |@                                                   |\n[128, 256)            88 |@                                                   |\n[256, 512)            45 |                                                    |\n[512, 1K)             54 |                                                    |\n[1K, 2K)              90 |@                                                   |\n[2K, 4K)              58 |                                                    |\n[4K, 8K)              16 |                                                    |\n[8K, 16K)              8 |                                                    |\n[16K, 32K)             0 |                                                    |\n[32K, 64K)             0 |                                                    |\n[64K, 128K)            0 |                                                    |\n[128K, 256K)           0 |                                                    |\n[256K, 512K)           0 |                                                    |\n[512K, 1M)             0 |                                                    |\n[1M, 2M)               0 |                                                    |\n[2M, 4M)               0 |                                                    |\n[4M, 8M)               0 |                                                    |\n[8M, 16M)              0 |                                                    |\n[16M, 32M)             2 |                                                    |"
}
```

## tcpretrans

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1448": {
        "avg_ns_per_run": null,
        "bytes_jited": 972,
        "bytes_xlated": 1640,
        "id": 1448,
        "name": "kprobe_tcp_retransmit_skb",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 5081.004832173969
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
      "1448": {
        "avg_ns_per_run": null,
        "bytes_jited": 972,
        "bytes_xlated": 1640,
        "id": 1448,
        "name": "tcp_retransmit_",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 5097.125842829486
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
  "stdout_tail": "Tracing tcp retransmits. Hit Ctrl-C to end.\nTIME     PID               LADDR:LPORT           RADDR:RPORT  STATE"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1455": {
        "avg_ns_per_run": 1846.814375878802,
        "bytes_jited": 773,
        "bytes_xlated": 1360,
        "id": 1455,
        "name": "cap_capable",
        "run_cnt_delta": 94589,
        "run_time_ns_delta": 174688325,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2165.7583954760144
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
      "1455": {
        "avg_ns_per_run": 1837.5274009359034,
        "bytes_jited": 773,
        "bytes_xlated": 1360,
        "id": 1455,
        "name": "cap_capable",
        "run_cnt_delta": 93172,
        "run_time_ns_delta": 171206103,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2266.877340864437
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
  "stdout_tail": "20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          39   CAP_BPF              0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          39   CAP_BPF              0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          39   CAP_BPF              0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          39   CAP_BPF              0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          39   CAP_BPF              0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          39   CAP_BPF              0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          39   CAP_BPF              0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          39   CAP_BPF              0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          39   CAP_BPF              0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          39   CAP_BPF              0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          39   CAP_BPF              0\n20:49:58  0      12919  bpftool          39   CAP_BPF              0\n20:49:58  0      12919  bpftool          39   CAP_BPF              0\n20:49:58  0      12919  bpftool          39   CAP_BPF              0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0\n20:49:58  0      12919  bpftool          21   CAP_SYS_ADMIN        0"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1462": {
        "avg_ns_per_run": 2476.125,
        "bytes_jited": 366,
        "bytes_xlated": 680,
        "id": 1462,
        "name": "1",
        "run_cnt_delta": 16,
        "run_time_ns_delta": 39618,
        "type": "perf_event"
      },
      "1463": {
        "avg_ns_per_run": 167.08311204864128,
        "bytes_jited": 144,
        "bytes_xlated": 224,
        "id": 1463,
        "name": "vfs_create",
        "run_cnt_delta": 40295,
        "run_time_ns_delta": 6732614,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 511.770057929092
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
      "1462": {
        "avg_ns_per_run": 2197.6875,
        "bytes_jited": 366,
        "bytes_xlated": 680,
        "id": 1462,
        "name": "1",
        "run_cnt_delta": 16,
        "run_time_ns_delta": 35163,
        "type": "perf_event"
      },
      "1463": {
        "avg_ns_per_run": 91.19165861274254,
        "bytes_jited": 144,
        "bytes_xlated": 224,
        "id": 1463,
        "name": "vfs_create",
        "run_cnt_delta": 40353,
        "run_time_ns_delta": 3679857,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 520.2987880567329
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
  "stdout_tail": "@[vfs_write]: 4329\n@[vfs_open]: 5309\n20:50:24\n@[vfs_read]: 5\n@[vfs_write]: 8\n20:50:25\n@[vfs_write]: 5\n@[vfs_read]: 6\n20:50:26\n@[vfs_read]: 7\n@[vfs_write]: 9\n20:50:27\n@[vfs_write]: 5\n@[vfs_read]: 6\n20:50:28\n@[vfs_writev]: 1\n@[vfs_readv]: 1\n@[vfs_write]: 194\n@[vfs_read]: 859\n@[vfs_open]: 2039\n20:50:29\n@[vfs_write]: 17\n@[vfs_read]: 20\n@[vfs_open]: 27\n20:50:30\n@[vfs_write]: 18\n@[vfs_read]: 22\n@[vfs_open]: 28\n20:50:31\n@[vfs_write]: 18\n@[vfs_read]: 23\n@[vfs_open]: 29\n20:50:32\n@[vfs_write]: 14\n@[vfs_read]: 19\n@[vfs_open]: 23\n20:50:33\n@[vfs_write]: 13\n@[vfs_read]: 27\n@[vfs_open]: 30"
}
```

