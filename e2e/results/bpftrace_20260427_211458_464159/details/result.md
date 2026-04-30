# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-27T21:16:38.222511+00:00`
- Duration per phase: `5s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## tcplife

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1348": {
        "avg_ns_per_run": 1371.2802896354299,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 11877,
        "run_time_ns_delta": 16286696,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 237.4799086899836
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
        "avg_ns_per_run": 1500.157074025405,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 11415,
        "run_time_ns_delta": 17124293,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 228.21160702801967
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
  "stdout_tail": "17122 curl       127.0.0.1       38267 127.0.0.1       41144      0     0 0\n17122 curl       127.0.0.1       41144 127.0.0.1       38267      0     0 0\n17124 curl       0.0.0.0         45601 0.0.0.0         42026      0     0 0\n17124 curl       0.0.0.0         42026 0.0.0.0         45601      0     0 0\n17126 curl       127.0.0.1       38267 127.0.0.1       41158      0     0 0\n17126 curl       127.0.0.1       41158 127.0.0.1       38267      0     0 0\n17128 curl       0.0.0.0         45601 0.0.0.0         42040      0     0 0\n17128 curl       0.0.0.0         42040 0.0.0.0         45601      0     0 0\n17130 curl       127.0.0.1       38267 127.0.0.1       41174      0     0 0\n17130 curl       127.0.0.1       41174 127.0.0.1       38267      0     0 0\n17132 curl       0.0.0.0         45601 0.0.0.0         42046      0     0 0\n17132 curl       0.0.0.0         42046 0.0.0.0         45601      0     0 0\n17134 curl       127.0.0.1       38267 127.0.0.1       41180      0     0 0\n17134 curl       127.0.0.1       41180 127.0.0.1       38267      0     0 0\n17136 curl       0.0.0.0         45601 0.0.0.0         42062      0     0 0\n17136 curl       0.0.0.0         42062 0.0.0.0         45601      0     0 0\n17138 curl       127.0.0.1       38267 127.0.0.1       41194      0     0 0\n17138 curl       127.0.0.1       41194 127.0.0.1       38267      0     0 0\n17140 curl       0.0.0.0         45601 0.0.0.0         42074      0     0 0\n17140 curl       0.0.0.0         42074 0.0.0.0         45601      0     0 0\n17142 curl       127.0.0.1       38267 127.0.0.1       41200      0     0 0\n17142 curl       127.0.0.1       41200 127.0.0.1       38267      0     0 0\n17144 curl       0.0.0.0         45601 0.0.0.0         42082      0     0 0\n17144 curl       0.0.0.0         42082 0.0.0.0         45601      0     0 0\n17146 curl       127.0.0.1       38267 127.0.0.1       41210      0     0 0\n17146 curl       127.0.0.1       41210 127.0.0.1       38267      0     0 0\n17148 curl       0.0.0.0         45601 0.0.0.0         42084      0     0 0\n17148 curl       0.0.0.0         42084 0.0.0.0         45601      0     0 0\n17150 curl       127.0.0.1       41218 127.0.0.1       38267      0     0 0\n1735  python3    127.0.0.1       38267 127.0.0.1       41218      0     0 0\n17152 curl       0.0.0.0         45601 0.0.0.0         42086      0     0 0\n17152 curl       0.0.0.0         42086 0.0.0.0         45601      0     0 0\n17154 curl       127.0.0.1       38267 127.0.0.1       41230      0     0 0\n17154 curl       127.0.0.1       41230 127.0.0.1       38267      0     0 0\n17156 curl       0.0.0.0         45601 0.0.0.0         42088      0     0 0\n17156 curl       0.0.0.0         42088 0.0.0.0         45601      0     0 0\n17158 curl       127.0.0.1       38267 127.0.0.1       41234      0     0 0\n17158 curl       127.0.0.1       41234 127.0.0.1       38267      0     0 0\n17160 curl       0.0.0.0         45601 0.0.0.0         42102      0     0 0\n17160 curl       0.0.0.0         42102 0.0.0.0         45601      0     0 0"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1355": {
        "avg_ns_per_run": 198.21564639662043,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 3186689,
        "run_time_ns_delta": 631651620,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 437.04705228530304,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 3186689,
        "run_time_ns_delta": 1392733034,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 636571.9751517461
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
        "avg_ns_per_run": 233.46544370440654,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 2596864,
        "run_time_ns_delta": 606278006,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 563.4116996500394,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 2596864,
        "run_time_ns_delta": 1463103560,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 518224.85152537597
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
  "stdout_tail": "12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0\n12185        252   0        dd               18612        0"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1363": {
        "avg_ns_per_run": 153.12479590485856,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 339915,
        "run_time_ns_delta": 52049415,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 297.3672556026853,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "tracepoint_sched_sched_wakeup_new",
        "run_cnt_delta": 59882,
        "run_time_ns_delta": 17806946,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 225.0530003175632,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 610902,
        "run_time_ns_delta": 137485328,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 46.58474452103335
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
        "avg_ns_per_run": 158.34949242628826,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 325864,
        "run_time_ns_delta": 51600399,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 306.21513762243916,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 59111,
        "run_time_ns_delta": 18100683,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 231.41245386190442,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 591431,
        "run_time_ns_delta": 136864499,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 45.889175868953366
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
  "stdout_tail": "Tracing CPU scheduler... Hit Ctrl-C to end.\n@usecs:\n[0]               210055 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n[1]               207675 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ |\n[2, 4)            179373 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@        |\n[4, 8)             66973 |@@@@@@@@@@@@@@@@                                    |\n[8, 16)            49421 |@@@@@@@@@@@@                                        |\n[16, 32)           29263 |@@@@@@@                                             |\n[32, 64)           20771 |@@@@@                                               |\n[64, 128)          24332 |@@@@@@                                              |\n[128, 256)         14931 |@@@                                                 |\n[256, 512)         15710 |@@@                                                 |\n[512, 1K)          17903 |@@@@                                                |\n[1K, 2K)           18278 |@@@@                                                |\n[2K, 4K)           26947 |@@@@@@                                              |\n[4K, 8K)           47252 |@@@@@@@@@@@                                         |\n[8K, 16K)          13835 |@@@                                                 |"
}
```

## tcpretrans

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1372": {
        "avg_ns_per_run": 13382.066666666668,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "kprobe_tcp_retransmit_skb",
        "run_cnt_delta": 15,
        "run_time_ns_delta": 200731,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 0.4877962135387909
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
        "avg_ns_per_run": 13825.947368421053,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "tcp_retransmit_",
        "run_cnt_delta": 19,
        "run_time_ns_delta": 262693,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 0.4883935596522944
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
  "stdout_tail": "Tracing tcp retransmits. Hit Ctrl-C to end.\nTIME     PID               LADDR:LPORT           RADDR:RPORT  STATE\n21:15:54 0             127.0.0.1:40263       127.0.0.1:42344  ESTABLISHED\n21:15:55 0             127.0.0.1:40263       127.0.0.1:42344  FIN_WAIT1\n21:15:55 0             127.0.0.1:40263       127.0.0.1:42344  FIN_WAIT1\n21:15:57 0             127.0.0.1:36463       127.0.0.1:46558  ESTABLISHED\n21:15:57 0             127.0.0.1:36463       127.0.0.1:46558  FIN_WAIT1\n21:15:57 0             127.0.0.1:40263       127.0.0.1:42344  CLOSING\n21:15:58 0             127.0.0.1:36463       127.0.0.1:46558  FIN_WAIT1\n21:15:59 0             127.0.0.1:45465       127.0.0.1:57392  ESTABLISHED\n21:16:00 0             127.0.0.1:36463       127.0.0.1:46558  CLOSING\n21:16:00 0             127.0.0.1:45465       127.0.0.1:57392  FIN_WAIT1\n21:16:00 0             127.0.0.1:40263       127.0.0.1:42344  CLOSING\n21:16:00 0             127.0.0.1:45465       127.0.0.1:57392  FIN_WAIT1\n21:16:02 0             127.0.0.1:41135       127.0.0.1:54576  ESTABLISHED\n21:16:02 0             127.0.0.1:41135       127.0.0.1:54576  FIN_WAIT1\n21:16:02 33            127.0.0.1:41135       127.0.0.1:54576  FIN_WAIT1\n21:16:02 0             127.0.0.1:45465       127.0.0.1:57392  CLOSING\n21:16:02 0             127.0.0.1:40073       127.0.0.1:39630  ESTABLISHED\n21:16:03 0             127.0.0.1:40073       127.0.0.1:39630  FIN_WAIT1\n21:16:03 0             127.0.0.1:36463       127.0.0.1:46558  CLOSING\n21:16:04 0             127.0.0.1:40073       127.0.0.1:39630  FIN_WAIT1\n21:16:05 0             127.0.0.1:38891       127.0.0.1:53892  ESTABLISHED\n21:16:05 0             127.0.0.1:38891       127.0.0.1:53892  FIN_WAIT1\n21:16:05 0             127.0.0.1:40073       127.0.0.1:39630  CLOSING\n21:16:06 0             127.0.0.1:38891       127.0.0.1:53892  FIN_WAIT1\n21:16:07 0             127.0.0.1:40263       127.0.0.1:42344  CLOSING\n21:16:07 0             127.0.0.1:35963       127.0.0.1:50166  ESTABLISHED\n21:16:08 0             127.0.0.1:35963       127.0.0.1:50166  FIN_WAIT1\n21:16:08 0             127.0.0.1:38891       127.0.0.1:53892  CLOSING\n21:16:09 0             127.0.0.1:35963       127.0.0.1:50166  FIN_WAIT1\n21:16:09 0             127.0.0.1:40073       127.0.0.1:39630  CLOSING\n21:16:10 0             127.0.0.1:36463       127.0.0.1:46558  CLOSING\n21:16:10 0             127.0.0.1:41553       127.0.0.1:50752  ESTABLISHED\n21:16:10 0             127.0.0.1:35963       127.0.0.1:50166  CLOSING\n21:16:10 0             127.0.0.1:41553       127.0.0.1:50752  FIN_WAIT1\n21:16:10 0             127.0.0.1:41553       127.0.0.1:50752  FIN_WAIT1"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1379": {
        "avg_ns_per_run": 208.26270579813888,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 993267,
        "run_time_ns_delta": 206860473,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 1734.4156470280159
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
        "avg_ns_per_run": 160.55545948921724,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 1133476,
        "run_time_ns_delta": 181985760,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 1980.0495190369857
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
  "stdout_tail": "21:16:23  65534  4079   stress-ng        21   CAP_SYS_ADMIN        2\n21:16:23  65534  4079   stress-ng        21   CAP_SYS_ADMIN        2\n21:16:23  65534  4079   stress-ng        21   CAP_SYS_ADMIN        2\n21:16:23  65534  4079   stress-ng        21   CAP_SYS_ADMIN        2\n21:16:23  65534  3997   stress-ng        21   CAP_SYS_ADMIN        2\n21:16:23  65534  4078   stress-ng        21   CAP_SYS_ADMIN        2\n21:16:23  65534  4079   stress-ng        21   CAP_SYS_ADMIN        2\n21:16:23  65534  3997   stress-ng        21   CAP_SYS_ADMIN        2\n21:16:23  65534  4078   stress-ng        21   CAP_SYS_ADMIN        2\n21:16:23  65534  4079   stress-ng        21   CAP_SYS_ADMIN        2\n21:16:23  65534  3995   stress-ng        21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   python3          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        2\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        0\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        0\n21:16:23  0      4089   bpftool          39   CAP_BPF              0\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        0\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        0\n21:16:23  0      4089   bpftool          39   CAP_BPF              0\n21:16:23  0      4089   bpftool          39   CAP_BPF              0\n21:16:23  0      4089   bpftool          39   CAP_BPF              0\n21:16:23  0      4089   bpftool          39   CAP_BPF              0\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        0\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        0\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        0\n21:16:23  0      4089   bpftool          21   CAP_SYS_ADMIN        0"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1386": {
        "avg_ns_per_run": 5007.2,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 25036,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 575.8636363636364,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 1892,
        "run_time_ns_delta": 1089534,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 91.05995456142699
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
        "avg_ns_per_run": 2747.2,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 13736,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 494.1907692307692,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 1950,
        "run_time_ns_delta": 963672,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 93.62487644747841
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
  "stdout_tail": "21:16:27\n@[vfs_write]: 82\n@[vfs_open]: 125\n@[vfs_read]: 193\n21:16:28\n@[vfs_open]: 90\n@[vfs_write]: 92\n@[vfs_read]: 181\n21:16:29\n@[vfs_open]: 87\n@[vfs_write]: 89\n@[vfs_read]: 176\n21:16:30\n@[vfs_open]: 91\n@[vfs_write]: 92\n@[vfs_read]: 184\n21:16:31\n@[vfs_open]: 93\n@[vfs_write]: 95\n@[vfs_read]: 187\n21:16:32\n@[vfs_write]: 82\n@[vfs_open]: 133\n@[vfs_read]: 200\n21:16:33\n@[vfs_open]: 92\n@[vfs_write]: 93\n@[vfs_read]: 185\n21:16:34\n@[vfs_open]: 98\n@[vfs_write]: 100\n@[vfs_read]: 197\n21:16:35\n@[vfs_open]: 93\n@[vfs_write]: 96\n@[vfs_read]: 189\n21:16:36\n@[vfs_open]: 93\n@[vfs_write]: 94\n@[vfs_read]: 188"
}
```

