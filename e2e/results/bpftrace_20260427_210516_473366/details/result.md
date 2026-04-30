# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-27T21:06:55.892236+00:00`
- Duration per phase: `5s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## tcplife

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1348": {
        "avg_ns_per_run": 1227.1147695202258,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 12756,
        "run_time_ns_delta": 15653076,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 255.08372579747328
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
        "avg_ns_per_run": 1433.2007060010085,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 11898,
        "run_time_ns_delta": 17052222,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 237.86835817960656
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
  "output_chars": 7027,
  "output_stripped": true,
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
  "stdout_tail": "14178 curl       127.0.0.1       35387 127.0.0.1       52348      0     0 0\n14178 curl       127.0.0.1       52348 127.0.0.1       35387      0     0 0\n14180 curl       0.0.0.0         35585 0.0.0.0         39284      0     0 0\n14180 curl       0.0.0.0         39284 0.0.0.0         35585      0     0 0\n14182 curl       127.0.0.1       35387 127.0.0.1       52354      0     0 0\n14182 curl       127.0.0.1       52354 127.0.0.1       35387      0     0 0\n14184 curl       0.0.0.0         35585 0.0.0.0         39296      0     0 0\n14184 curl       0.0.0.0         39296 0.0.0.0         35585      0     0 0\n14186 curl       127.0.0.1       35387 127.0.0.1       52362      0     0 0\n14186 curl       127.0.0.1       52362 127.0.0.1       35387      0     0 0\n14188 curl       0.0.0.0         35585 0.0.0.0         39304      0     0 0\n14188 curl       0.0.0.0         39304 0.0.0.0         35585      0     0 0\n14190 curl       127.0.0.1       35387 127.0.0.1       52370      0     0 0\n14190 curl       127.0.0.1       52370 127.0.0.1       35387      0     0 0\n14192 curl       0.0.0.0         35585 0.0.0.0         39314      0     0 0\n14192 curl       0.0.0.0         39314 0.0.0.0         35585      0     0 0\n14194 curl       127.0.0.1       35387 127.0.0.1       52386      0     0 0\n14194 curl       127.0.0.1       52386 127.0.0.1       35387      0     0 0\n14196 curl       0.0.0.0         35585 0.0.0.0         39318      0     0 0\n14196 curl       0.0.0.0         39318 0.0.0.0         35585      0     0 0\n14198 curl       127.0.0.1       35387 127.0.0.1       52394      0     0 0\n14198 curl       127.0.0.1       52394 127.0.0.1       35387      0     0 0\n14200 curl       0.0.0.0         35585 0.0.0.0         39330      0     0 0\n14200 curl       0.0.0.0         39330 0.0.0.0         35585      0     0 0\n14202 curl       127.0.0.1       35387 127.0.0.1       52404      0     0 0\n14202 curl       127.0.0.1       52404 127.0.0.1       35387      0     0 0\n14204 curl       0.0.0.0         35585 0.0.0.0         39344      0     0 0\n14204 curl       0.0.0.0         39344 0.0.0.0         35585      0     0 0\n14206 curl       127.0.0.1       35387 127.0.0.1       52414      0     0 0\n14206 curl       127.0.0.1       52414 127.0.0.1       35387      0     0 0\n14208 curl       0.0.0.0         35585 0.0.0.0         39358      0     0 0\n14208 curl       0.0.0.0         39358 0.0.0.0         35585      0     0 0\n14210 curl       127.0.0.1       35387 127.0.0.1       52424      0     0 0\n14210 curl       127.0.0.1       52424 127.0.0.1       35387      0     0 0\n14212 curl       0.0.0.0         35585 0.0.0.0         39366      0     0 0\n14212 curl       0.0.0.0         39366 0.0.0.0         35585      0     0 0\n14214 curl       127.0.0.1       35387 127.0.0.1       52430      0     0 0\n14214 curl       127.0.0.1       52430 127.0.0.1       35387      0     0 0\n14216 curl       0.0.0.0         35585 0.0.0.0         39368      0     0 0\n14216 curl       0.0.0.0         39368 0.0.0.0         35585      0     0 0"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1355": {
        "avg_ns_per_run": 247.25389806324614,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 2473985,
        "run_time_ns_delta": 611702435,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 620.881681982712,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 2473985,
        "run_time_ns_delta": 1536051968,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 494370.7252062458
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
        "avg_ns_per_run": 225.51112917636303,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 2695168,
        "run_time_ns_delta": 607790379,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 556.8463383358662,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 2695168,
        "run_time_ns_delta": 1500794432,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 537439.6349810589
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
  "output_chars": 12598,
  "output_stripped": true,
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
  "stdout_tail": "12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0\n12176        252   0        dd               15518        0"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1363": {
        "avg_ns_per_run": 159.14670355443087,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 334709,
        "run_time_ns_delta": 53267834,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 311.92600153545504,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "tracepoint_sched_sched_wakeup_new",
        "run_cnt_delta": 57312,
        "run_time_ns_delta": 17877103,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 228.6715334055688,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 600813,
        "run_time_ns_delta": 137388830,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 44.46076806369205
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
        "avg_ns_per_run": 161.55074255142515,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 325230,
        "run_time_ns_delta": 52541148,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 310.03069165270796,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 57312,
        "run_time_ns_delta": 17768479,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 229.09342350626025,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 581845,
        "run_time_ns_delta": 133296863,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 44.449418119505054
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
  "output_chars": 13111,
  "output_stripped": true,
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
  "stdout_tail": "Tracing CPU scheduler... Hit Ctrl-C to end.\n@usecs:\n[0]               190500 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@       |\n[1]               220022 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n[2, 4)            180448 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@          |\n[4, 8)             71603 |@@@@@@@@@@@@@@@@                                    |\n[8, 16)            53536 |@@@@@@@@@@@@                                        |\n[16, 32)           32220 |@@@@@@@                                             |\n[32, 64)           20667 |@@@@                                                |\n[64, 128)          26484 |@@@@@@                                              |\n[128, 256)         16483 |@@@                                                 |\n[256, 512)         15732 |@@@                                                 |\n[512, 1K)          17817 |@@@@                                                |\n[1K, 2K)           16784 |@@@                                                 |\n[2K, 4K)           24849 |@@@@@                                               |\n[4K, 8K)           43223 |@@@@@@@@@@                                          |\n[8K, 16K)          16971 |@@@@                                                |\n[16K, 32K)            10 |                                                    |"
}
```

## tcpretrans

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1372": {
        "avg_ns_per_run": 13831.0625,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "kprobe_tcp_retransmit_skb",
        "run_cnt_delta": 16,
        "run_time_ns_delta": 221297,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 0.48920264430994725
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
        "avg_ns_per_run": 12978.333333333334,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "tcp_retransmit_",
        "run_cnt_delta": 18,
        "run_time_ns_delta": 233610,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 0.4893487707948586
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
  "output_chars": 5744,
  "output_stripped": true,
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
  "stdout_tail": "Tracing tcp retransmits. Hit Ctrl-C to end.\nTIME     PID               LADDR:LPORT           RADDR:RPORT  STATE\n21:06:12 0             127.0.0.1:42189       127.0.0.1:33426  ESTABLISHED\n21:06:12 0             127.0.0.1:42189       127.0.0.1:33426  FIN_WAIT1\n21:06:13 0             127.0.0.1:42189       127.0.0.1:33426  FIN_WAIT1\n21:06:14 0             127.0.0.1:41161       127.0.0.1:52476  ESTABLISHED\n21:06:15 0             127.0.0.1:42189       127.0.0.1:33426  CLOSING\n21:06:15 0             127.0.0.1:41161       127.0.0.1:52476  FIN_WAIT1\n21:06:16 0             127.0.0.1:41161       127.0.0.1:52476  FIN_WAIT1\n21:06:17 0             127.0.0.1:44393       127.0.0.1:54196  ESTABLISHED\n21:06:17 0             127.0.0.1:44393       127.0.0.1:54196  FIN_WAIT1\n21:06:17 0             127.0.0.1:41161       127.0.0.1:52476  CLOSING\n21:06:18 0             127.0.0.1:42189       127.0.0.1:33426  CLOSING\n21:06:18 0             127.0.0.1:44393       127.0.0.1:54196  FIN_WAIT1\n21:06:19 0             127.0.0.1:43567       127.0.0.1:47224  ESTABLISHED\n21:06:20 0             127.0.0.1:44393       127.0.0.1:54196  CLOSING\n21:06:20 0             127.0.0.1:43567       127.0.0.1:47224  FIN_WAIT1\n21:06:20 0             127.0.0.1:43567       127.0.0.1:47224  FIN_WAIT1\n21:06:20 0             127.0.0.1:36353       127.0.0.1:44982  ESTABLISHED\n21:06:21 0             127.0.0.1:36353       127.0.0.1:44982  FIN_WAIT1\n21:06:21 0             127.0.0.1:41161       127.0.0.1:52476  CLOSING\n21:06:21 0             127.0.0.1:36353       127.0.0.1:44982  FIN_WAIT1\n21:06:23 0             127.0.0.1:41999       127.0.0.1:49526  ESTABLISHED\n21:06:23 0             127.0.0.1:41999       127.0.0.1:49526  FIN_WAIT1\n21:06:23 0             127.0.0.1:36353       127.0.0.1:44982  CLOSING\n21:06:24 0             127.0.0.1:41999       127.0.0.1:49526  FIN_WAIT1\n21:06:25 0             127.0.0.1:42189       127.0.0.1:33426  CLOSING\n21:06:25 0             127.0.0.1:43729       127.0.0.1:50128  ESTABLISHED\n21:06:26 0             127.0.0.1:41999       127.0.0.1:49526  CLOSING\n21:06:26 0             127.0.0.1:43729       127.0.0.1:50128  FIN_WAIT1\n21:06:26 0             127.0.0.1:36353       127.0.0.1:44982  CLOSING\n21:06:26 0             127.0.0.1:43729       127.0.0.1:50128  FIN_WAIT1\n21:06:28 0             127.0.0.1:41161       127.0.0.1:52476  CLOSING\n21:06:28 0             127.0.0.1:41065       127.0.0.1:55760  ESTABLISHED\n21:06:28 0             127.0.0.1:41065       127.0.0.1:55760  FIN_WAIT1\n21:06:28 0             127.0.0.1:41065       127.0.0.1:55760  FIN_WAIT1"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1379": {
        "avg_ns_per_run": 177.16074277664714,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 1059861,
        "run_time_ns_delta": 187765762,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 1855.8230165751506
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
        "avg_ns_per_run": 163.67186543542994,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 1109237,
        "run_time_ns_delta": 181550889,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 1943.3058963462581
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
  "output_chars": 5259,
  "output_stripped": true,
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
  "stdout_tail": "21:06:41  65534  29685  stress-ng        21   CAP_SYS_ADMIN        2\n21:06:41  65534  29685  stress-ng        21   CAP_SYS_ADMIN        2\n21:06:41  65534  29685  stress-ng        21   CAP_SYS_ADMIN        2\n21:06:41  65534  29685  stress-ng        21   CAP_SYS_ADMIN        2\n21:06:41  65534  29685  stress-ng        21   CAP_SYS_ADMIN        2\n21:06:41  65534  29685  stress-ng        21   CAP_SYS_ADMIN        2\n21:06:41  65534  29685  stress-ng        21   CAP_SYS_ADMIN        2\n21:06:41  65534  29685  stress-ng        21   CAP_SYS_ADMIN        2\n21:06:41  65534  29685  stress-ng        21   CAP_SYS_ADMIN        2\n21:06:41  65534  29685  stress-ng        21   CAP_SYS_ADMIN        2\n21:06:41  65534  29685  stress-ng        21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  python3          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        2\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        0\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        0\n21:06:41  0      29701  bpftool          39   CAP_BPF              0\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        0\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        0\n21:06:41  0      29701  bpftool          39   CAP_BPF              0\n21:06:41  0      29701  bpftool          39   CAP_BPF              0\n21:06:41  0      29701  bpftool          39   CAP_BPF              0\n21:06:41  0      29701  bpftool          39   CAP_BPF              0\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        0\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        0\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        0\n21:06:41  0      29701  bpftool          21   CAP_SYS_ADMIN        0"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1386": {
        "avg_ns_per_run": 3078.2,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 15391,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 695.5165900969882,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 1959,
        "run_time_ns_delta": 1362517,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 94.34904470386005
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
        "avg_ns_per_run": 3092.0,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 15460,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 705.8853538123972,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 1823,
        "run_time_ns_delta": 1286829,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 87.59624944394606
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
  "output_chars": 8220,
  "output_stripped": true,
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
  "stdout_tail": "21:06:44\n@[vfs_write]: 88\n@[vfs_open]: 128\n@[vfs_read]: 201\n21:06:45\n@[vfs_open]: 91\n@[vfs_write]: 92\n@[vfs_read]: 183\n21:06:46\n@[vfs_open]: 94\n@[vfs_write]: 95\n@[vfs_read]: 188\n21:06:47\n@[vfs_open]: 96\n@[vfs_write]: 97\n@[vfs_read]: 193\n21:06:48\n@[vfs_open]: 96\n@[vfs_write]: 99\n@[vfs_read]: 195\n21:06:49\n@[vfs_write]: 83\n@[vfs_open]: 133\n@[vfs_read]: 201\n21:06:50\n@[vfs_write]: 94\n@[vfs_open]: 94\n@[vfs_read]: 189\n21:06:51\n@[vfs_open]: 81\n@[vfs_write]: 84\n@[vfs_read]: 163\n21:06:52\n@[vfs_open]: 83\n@[vfs_write]: 84\n@[vfs_read]: 166\n21:06:53\n@[vfs_open]: 89\n@[vfs_write]: 90\n@[vfs_read]: 180"
}
```

