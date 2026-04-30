# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-28T17:39:46.071928+00:00`
- Duration per phase: `5s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## tcplife

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1348": {
        "avg_ns_per_run": 1187.2,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 10,
        "run_time_ns_delta": 11872,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 21522.80122202241
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
      "1348": {
        "avg_ns_per_run": 1480.125,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 8,
        "run_time_ns_delta": 11841,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 20193.9263672634
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
  "stdout_tail": "PID   COMM       LADDR           LPORT RADDR           RPORT TX_KB RX_KB MS\n12421 stress-ng- 127.0.0.1       57360 127.0.0.1       22080      0 408736 35\n12420 stress-ng- 127.0.0.1       22080 127.0.0.1       57360  408736     0 35\n12445 stress-ng- 127.0.0.1       57364 127.0.0.1       22080      0 408800 59\n12445 stress-ng- 127.0.0.1       22080 127.0.0.1       57364  408713     0 59"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1355": {
        "avg_ns_per_run": 291.0413919229543,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 59601,
        "run_time_ns_delta": 17346358,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 1365.0464304884595,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 59616,
        "run_time_ns_delta": 81378608,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 11053.854491164579
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
      "1355": {
        "avg_ns_per_run": 302.59995486765604,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 75334,
        "run_time_ns_delta": 22796065,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 1359.5681996151038,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 75345,
        "run_time_ns_delta": 102436666,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 10661.89963659852
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
    "applied": 2,
    "not_applied": 0,
    "requested": 2
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "20891        7     0        fio              12494        0\n20892        7     0        fio              12493        0\n20892        7     0        fio              12496        0\n20892        7     0        fio              12495        0\n20892        7     0        fio              12494        0\n20892        7     0        fio              12493        0\n20892        7     0        fio              12496        0\n20892        7     0        fio              12495        0\n20892        7     0        fio              12494        0\n20892        7     0        fio              12493        0\n20892        7     0        fio              12496        0\n20892        7     0        fio              12495        0\n20892        7     0        fio              12494        0\n20892        7     0        fio              12493        0\n20892        7     0        fio              12496        0\n20892        7     0        fio              12495        0\n20892        7     0        fio              12494        0\n20893        7     0        fio              12493        0\n20893        7     0        fio              12496        0\n20893        7     0        fio              12495        0\n20893        7     0        fio              12494        0\n20893        7     0        fio              12493        0\n20893        7     0        fio              12496        0\n20893        7     0        fio              12495        0\n20893        7     0        fio              12494        0\n20893        7     0        fio              12493        0\n20893        7     0        fio              12496        0\n20893        7     0        fio              12495        0\n20893        7     0        fio              12494        0\n20893        7     0        fio              12493        0\n20893        7     0        fio              12496        0\n20893        7     0        fio              12495        0\n20893        7     0        fio              12494        0\n20894        7     0        fio              12493        0\n20894        7     0        fio              12496        0\n20894        7     0        fio              12495        0\n20894        7     0        fio              12494        0\n20894        7     0        fio              12493        0\n20894        7     0        fio              12496        0\n21077        7     0        jbd2/loop0-8     1368       188"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1363": {
        "avg_ns_per_run": 144.18151491365776,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 15288,
        "run_time_ns_delta": 2204247,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 219.20149253731344,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "tracepoint_sched_sched_wakeup_new",
        "run_cnt_delta": 536,
        "run_time_ns_delta": 117492,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 138.39061023686182,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 30693,
        "run_time_ns_delta": 4247623,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 1119.6025306619863
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
      "1363": {
        "avg_ns_per_run": 266.5380138232084,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 5498,
        "run_time_ns_delta": 1465426,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 220.65055762081784,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 538,
        "run_time_ns_delta": 118710,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 269.268227358397,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 10081,
        "run_time_ns_delta": 2714493,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 1119.0982593663389
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
    "applied": 3,
    "not_applied": 0,
    "requested": 3
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "Tracing CPU scheduler... Hit Ctrl-C to end.\n@usecs:\n[0]                17908 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n[1]                  375 |@                                                   |\n[2, 4)              1050 |@@@                                                 |\n[4, 8)               375 |@                                                   |\n[8, 16)             1039 |@@@                                                 |\n[16, 32)             344 |                                                    |\n[32, 64)             180 |                                                    |\n[64, 128)            184 |                                                    |\n[128, 256)            64 |                                                    |\n[256, 512)             4 |                                                    |\n[512, 1K)              8 |                                                    |\n[1K, 2K)               2 |                                                    |"
}
```

## tcpretrans

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1372": {
        "avg_ns_per_run": null,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "kprobe_tcp_retransmit_skb",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 22175.81872657821
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
      "1372": {
        "avg_ns_per_run": null,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "tcp_retransmit_",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2856.6744457145755
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
      "1379": {
        "avg_ns_per_run": 176.06687357704368,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 93116,
        "run_time_ns_delta": 16394643,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 13635.294555100752
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
      "1379": {
        "avg_ns_per_run": 190.7350616435414,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 93116,
        "run_time_ns_delta": 17760486,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 14071.280731253903
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
  "stdout_tail": "17:39:11  0      15713  stress-ng        21   CAP_SYS_ADMIN        2\n17:39:11  0      15713  stress-ng        21   CAP_SYS_ADMIN        2\n17:39:11  0      15713  stress-ng        21   CAP_SYS_ADMIN        2\n17:39:11  0      15713  stress-ng        21   CAP_SYS_ADMIN        2\n17:39:11  0      15713  stress-ng        21   CAP_SYS_ADMIN        2\n17:39:11  0      15713  stress-ng        21   CAP_SYS_ADMIN        2\n17:39:11  0      15714  stress-ng-timer  24   CAP_SYS_RESOURCE     2\n17:39:11  0      15714  stress-ng-timer  21   CAP_SYS_ADMIN        0\n17:39:11  0      15714  stress-ng-timer  21   CAP_SYS_ADMIN        0\n17:39:11  0      15714  stress-ng-timer  21   CAP_SYS_ADMIN        0\n17:39:11  0      15714  stress-ng-timer  21   CAP_SYS_ADMIN        0\n17:39:11  0      15715  python3          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        2\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        0\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        0\n17:39:11  0      15715  bpftool          39   CAP_BPF              0\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        0\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        0\n17:39:11  0      15715  bpftool          39   CAP_BPF              0\n17:39:11  0      15715  bpftool          39   CAP_BPF              0\n17:39:11  0      15715  bpftool          39   CAP_BPF              0\n17:39:11  0      15715  bpftool          39   CAP_BPF              0\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        0\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        0\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        0\n17:39:11  0      15715  bpftool          21   CAP_SYS_ADMIN        0"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1386": {
        "avg_ns_per_run": 2069.625,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 16,
        "run_time_ns_delta": 33114,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 42.11656058734919,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 73687,
        "run_time_ns_delta": 3103443,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 521.8754888232971
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
      "1386": {
        "avg_ns_per_run": 1988.642857142857,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 14,
        "run_time_ns_delta": 27841,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 41.4938058110586,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 67079,
        "run_time_ns_delta": 2783363,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 608.3263683242674
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
    "applied": 2,
    "not_applied": 0,
    "requested": 2
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "@[vfs_fsync]: 65\n@[vfs_create]: 2513\n@[vfs_read]: 3525\n@[vfs_write]: 4394\n@[vfs_open]: 11781\n17:39:37\n@[vfs_write]: 1\n@[vfs_read]: 2\n17:39:38\n@[vfs_write]: 1\n17:39:39\n@[vfs_read]: 1\n@[vfs_write]: 1\n17:39:40\n@[vfs_read]: 1\n@[vfs_write]: 1\n17:39:41\n@[vfs_writev]: 1\n@[vfs_readv]: 1\n@[vfs_fsync]: 2\n@[vfs_create]: 9\n@[vfs_write]: 195\n@[vfs_read]: 1531\n@[vfs_open]: 2763\n17:39:42\n@[vfs_create]: 48\n@[vfs_write]: 49\n@[vfs_read]: 65\n@[vfs_open]: 184\n17:39:43\n@[vfs_create]: 26\n@[vfs_write]: 28\n@[vfs_read]: 38\n@[vfs_open]: 100\n17:39:44\n@[vfs_fsync]: 46\n@[vfs_write]: 47\n@[vfs_create]: 80\n@[vfs_read]: 885\n@[vfs_open]: 1279"
}
```

