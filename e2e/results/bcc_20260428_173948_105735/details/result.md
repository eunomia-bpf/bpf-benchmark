# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-28T17:43:58.031183+00:00`
- Duration per phase: `10s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Tools dir: `/usr/sbin`
- Setup rc: `0`

## tcplife

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1391": {
        "avg_ns_per_run": 785.3,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1391,
        "name": "tracepoint__sock__inet_sock_set_state",
        "run_cnt_delta": 20,
        "run_time_ns_delta": 15706,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 8019.835916340536
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
      "1391": {
        "avg_ns_per_run": 666.15,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1391,
        "name": "sock__inet_sock",
        "run_cnt_delta": 20,
        "run_time_ns_delta": 13323,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1603.9474134887575
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
  "stderr_tail": "In file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-m4dstp5q/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-m4dstp5q/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/tcp.h:7:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "PID   COMM       LADDR           LPORT RADDR           RPORT TX_KB RX_KB MS\n17492 stress-ng- 127.0.0.1       40908 127.0.0.1       22080     0 408800 63.49\n17492 stress-ng- 127.0.0.1       22080 127.0.0.1       40908 408738     0 63.49\n17516 stress-ng- 127.0.0.1       40924 127.0.0.1       22080     0 408738 37.28\n17516 stress-ng- 127.0.0.1       22080 127.0.0.1       40924 408738     0 37.28"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1394": {
        "avg_ns_per_run": 208.2881309299495,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1394,
        "name": "trace_pid_start_tp",
        "run_cnt_delta": 119942,
        "run_time_ns_delta": 24982495,
        "type": "tracepoint"
      },
      "1395": {
        "avg_ns_per_run": 191.78908581622954,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1395,
        "name": "trace_req_start",
        "run_cnt_delta": 119954,
        "run_time_ns_delta": 23005868,
        "type": "kprobe"
      },
      "1396": {
        "avg_ns_per_run": 399.1013754584862,
        "bytes_jited": 550,
        "bytes_xlated": 856,
        "id": 1396,
        "name": "trace_req_completion_tp",
        "run_cnt_delta": 119960,
        "run_time_ns_delta": 47876201,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 13331.779511898438
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
      "1394": {
        "avg_ns_per_run": 260.7503392769631,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1394,
        "name": "trace_pid_start",
        "run_cnt_delta": 106108,
        "run_time_ns_delta": 27667697,
        "type": "tracepoint"
      },
      "1395": {
        "avg_ns_per_run": 228.2078346746075,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1395,
        "name": "trace_req_start",
        "run_cnt_delta": 106118,
        "run_time_ns_delta": 24216959,
        "type": "kprobe"
      },
      "1396": {
        "avg_ns_per_run": 122.3952903262283,
        "bytes_jited": 548,
        "bytes_xlated": 848,
        "id": 1396,
        "name": "trace_req_compl",
        "run_cnt_delta": 106122,
        "run_time_ns_delta": 12988833,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 10202.222586391117
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
  "stderr_tail": "In file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-kf7n3kmf/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/blk-mq.h:5:\nIn file included from include/linux/blkdev.h:7:\nIn file included from include/linux/blk_types.h:7:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "2.171324    fio            17556   loop0     R 63491232   4096      0.66\n2.171952    fio            17559   loop0     R 63654112   4096      0.69\n2.172014    fio            17556   loop0     R 63491240   4096      0.67\n2.172287    fio            17559   loop0     R 63627072   4096      0.33\n2.172352    fio            17556   loop0     R 63491528   4096      0.32\n2.172644    fio            17559   loop0     R 63627080   4096      0.35\n2.172707    fio            17556   loop0     R 63491568   4096      0.35\n2.173447    fio            17559   loop0     R 63627088   4096      0.80\n2.173509    fio            17556   loop0     R 63491576   4096      0.80\n2.173949    fio            17559   loop0     R 63627168   4096      0.50\n2.174014    fio            17556   loop0     R 63491696   4096      0.50\n2.174640    fio            17559   loop0     R 63629856   4096      0.68\n2.174703    fio            17556   loop0     R 63491720   4096      0.68\n2.175203    fio            17559   loop0     R 63630000   4096      0.56\n2.175606    fio            17559   loop0     R 63630016   4096      0.40\n2.176504    fio            17559   loop0     R 63654168   4096      0.89\n2.177009    fio            17559   loop0     R 63654176   4096      0.50\n2.177488    fio            17559   loop0     R 63630104   4096      0.47\n2.177844    fio            17559   loop0     R 63630128   4096      0.35\n2.178342    fio            17559   loop0     R 63630272   4096      0.49\n2.178887    fio            17559   loop0     R 63630280   4096      0.53\n2.179262    fio            17559   loop0     R 63630296   4096      0.36\n2.179826    fio            17559   loop0     R 63630304   4096      0.55\n2.180200    fio            17559   loop0     R 63632952   4096      0.37\n2.180703    fio            17559   loop0     R 63656896   4096      0.50\n2.181184    fio            17559   loop0     R 63631528   4096      0.48\n2.181859    fio            17559   loop0     R 63631576   4096      0.67\n2.182235    fio            17559   loop0     R 63631584   4096      0.36\n2.182843    fio            17559   loop0     R 63632264   4096      0.59\n2.183220    fio            17559   loop0     R 63632352   4096      0.37\n2.183818    fio            17559   loop0     R 63632360   4096      0.59\n2.184192    fio            17559   loop0     R 63632368   4096      0.36\n2.184695    fio            17559   loop0     R 63632824   4096      0.50\n2.185176    fio            17559   loop0     R 63632832   4096      0.48\n2.185742    fio            17559   loop0     R 63632840   4096      0.56\n2.186617    fio            17559   loop0     R 63632896   4096      0.86\n2.187224    fio            17559   loop0     R 63632968   4096      0.59\n2.187915    fio            17559   loop0     R 63633888   4096      0.67\n2.188292    fio            17559   loop0     R 63633912   4096      0.37\n2.188585    fio            17559   loop0     R 63633928   4096      0.28"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1401": {
        "avg_ns_per_run": 181.32836409528318,
        "bytes_jited": 662,
        "bytes_xlated": 1168,
        "id": 1401,
        "name": "sched_switch",
        "run_cnt_delta": 12678,
        "run_time_ns_delta": 2298881,
        "type": "raw_tracepoint"
      },
      "1402": {
        "avg_ns_per_run": 337.5518975024327,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1402,
        "name": "sched_wakeup",
        "run_cnt_delta": 6166,
        "run_time_ns_delta": 2081345,
        "type": "raw_tracepoint"
      },
      "1403": {
        "avg_ns_per_run": 253.92134831460675,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1403,
        "name": "raw_tracepoint__sched_wakeup_new",
        "run_cnt_delta": 534,
        "run_time_ns_delta": 135594,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 566.8922071654249
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
      "1401": {
        "avg_ns_per_run": 241.71819425444596,
        "bytes_jited": 645,
        "bytes_xlated": 1136,
        "id": 1401,
        "name": "sched_switch",
        "run_cnt_delta": 9503,
        "run_time_ns_delta": 2297048,
        "type": "raw_tracepoint"
      },
      "1402": {
        "avg_ns_per_run": 499.0024942440522,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1402,
        "name": "sched_wakeup",
        "run_cnt_delta": 5212,
        "run_time_ns_delta": 2600801,
        "type": "raw_tracepoint"
      },
      "1403": {
        "avg_ns_per_run": 257.5425925925926,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1403,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 540,
        "run_time_ns_delta": 139073,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 566.8402713578286
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
  "stderr_tail": "In file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-bro8d6gv/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-bro8d6gv/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:6:\nIn file included from include/linux/pid_namespace.h:7:\nIn file included from include/linux/mm.h:1118:\nIn file included from include/linux/huge_mm.h:7:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "Tracing run queue latency... Hit Ctrl-C to end.\n     usecs               : count     distribution\n         0 -> 1          : 8404     |****************************************|\n         2 -> 3          : 970      |****                                    |\n         4 -> 7          : 437      |**                                      |\n         8 -> 15         : 1120     |*****                                   |\n        16 -> 31         : 506      |**                                      |\n        32 -> 63         : 283      |*                                       |\n        64 -> 127        : 240      |*                                       |\n       128 -> 255        : 103      |                                        |\n       256 -> 511        : 5        |                                        |\n       512 -> 1023       : 6        |                                        |\n      1024 -> 2047       : 2        |                                        |\n      2048 -> 4095       : 0        |                                        |\n      4096 -> 8191       : 1        |                                        |\n      8192 -> 16383      : 3        |                                        |\n     16384 -> 32767      : 0        |                                        |\n     32768 -> 65535      : 0        |                                        |\n     65536 -> 131071     : 0        |                                        |\n    131072 -> 262143     : 0        |                                        |\n    262144 -> 524287     : 0        |                                        |\n    524288 -> 1048575    : 0        |                                        |\n   1048576 -> 2097151    : 2        |                                        |\n   2097152 -> 4194303    : 2        |                                        |\n   4194304 -> 8388607    : 2        |                                        |\n   8388608 -> 16777215   : 1        |                                        |\n  16777216 -> 33554431   : 0        |                                        |\n  33554432 -> 67108863   : 0        |                                        |\n  67108864 -> 134217727  : 0        |                                        |\n 134217728 -> 268435455  : 0        |                                        |\n 268435456 -> 536870911  : 3        |                                        |\n 536870912 -> 1073741823 : 0        |                                        |\n1073741824 -> 2147483647 : 1        |                                        |"
}
```

## syscount

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1408": {
        "avg_ns_per_run": 54.21920353629016,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1408,
        "name": "tracepoint__raw_syscalls__sys_enter",
        "run_cnt_delta": 551086,
        "run_time_ns_delta": 29879444,
        "type": "tracepoint"
      },
      "1409": {
        "avg_ns_per_run": 55.84069121572456,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1409,
        "name": "tracepoint__raw_syscalls__sys_exit",
        "run_cnt_delta": 551087,
        "run_time_ns_delta": 30773079,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 12122.29330191104
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
      "1408": {
        "avg_ns_per_run": 54.7815260344026,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1408,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 550656,
        "run_time_ns_delta": 30165776,
        "type": "tracepoint"
      },
      "1409": {
        "avg_ns_per_run": 55.56853903609688,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1409,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 550657,
        "run_time_ns_delta": 30599205,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 11640.011010282917
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-1aeyxbg5/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-1aeyxbg5/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "read                       1462         1074.998\nopenat                       56          600.878\nmprotect                     40          471.931\nclock_nanosleep              16      3002115.698\n[17:41:14]\nSYSCALL                   COUNT        TIME (us)\nfutex                         3      2457763.859\nepoll_pwait                   2      1233583.286\nnanosleep                     1        10062.413\npoll                         10         8976.496\nvfork                         5         2736.257\nexecve                        5         1518.369\nmmap                        150         1022.440\nopenat                       55          493.766\nmprotect                     40          353.269\nclock_nanosleep              32      2212800.513\n[17:41:15]\nSYSCALL                   COUNT        TIME (us)\nread                      13688      1023421.121\npoll                         58       853652.968\nwait4                      1026       843662.484\nopenat                    16159       138563.319\nstatfs                    18423        97167.258\nclone                      1013        65329.967\nclose                     16913        52277.350\nfstatfs                    9200        50152.723\nmmap                       1492        36620.006\nfutex                         5      3142044.689\n[17:41:16]\nSYSCALL                   COUNT        TIME (us)\nepoll_pwait                   3      1576584.507\nread                       1800      1001256.500\nclock_nanosleep               8       603037.516\nwait4                      1011       462443.975\npoll                         15       300989.131\nclone                      1001        65771.169\narch_prctl               262740        26490.126\nnanosleep                     2        20127.709\nprctl                     91931        14775.701\nDetaching..."
}
```

## execsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1412": {
        "avg_ns_per_run": 1150.888888888889,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1412,
        "name": "syscall__execve",
        "run_cnt_delta": 9,
        "run_time_ns_delta": 10358,
        "type": "kprobe"
      },
      "1413": {
        "avg_ns_per_run": 125.0,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1413,
        "name": "do_ret_sys_execve",
        "run_cnt_delta": 9,
        "run_time_ns_delta": 1125,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 567.5933007358217
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
      "1412": {
        "avg_ns_per_run": 1299.7777777777778,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1412,
        "name": "syscall__execve",
        "run_cnt_delta": 9,
        "run_time_ns_delta": 11698,
        "type": "kprobe"
      },
      "1413": {
        "avg_ns_per_run": 241.11111111111111,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1413,
        "name": "do_ret_sys_exec",
        "run_cnt_delta": 9,
        "run_time_ns_delta": 2170,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 567.512583887152
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
  "stderr_tail": "<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-l_q8x2z3/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-l_q8x2z3/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "TIME     UID   PCOMM            PID     PPID    RET ARGS"
}
```

## opensnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1416": {
        "avg_ns_per_run": 702.979797979798,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1416,
        "name": "__x64_sys_open",
        "run_cnt_delta": 99,
        "run_time_ns_delta": 69595,
        "type": "tracing"
      },
      "1417": {
        "avg_ns_per_run": 791.5752946578907,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1417,
        "name": "kretfunc__vmlinux____x64_sys_openat",
        "run_cnt_delta": 32665,
        "run_time_ns_delta": 25856807,
        "type": "tracing"
      },
      "1418": {
        "avg_ns_per_run": 631.6818181818181,
        "bytes_jited": 590,
        "bytes_xlated": 640,
        "id": 1418,
        "name": "kretfunc__vmlinux____x64_sys_openat2",
        "run_cnt_delta": 22,
        "run_time_ns_delta": 13897,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 331.64509257398726
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
      "1416": {
        "avg_ns_per_run": 735.8488372093024,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1416,
        "name": "__x64_sys_open",
        "run_cnt_delta": 86,
        "run_time_ns_delta": 63283,
        "type": "tracing"
      },
      "1417": {
        "avg_ns_per_run": 719.3772028718922,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1417,
        "name": "__x64_sys_opena",
        "run_cnt_delta": 33706,
        "run_time_ns_delta": 24247328,
        "type": "tracing"
      },
      "1418": {
        "avg_ns_per_run": 698.5,
        "bytes_jited": 590,
        "bytes_xlated": 640,
        "id": 1418,
        "name": "__x64_sys_opena",
        "run_cnt_delta": 8,
        "run_time_ns_delta": 5588,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 329.840355303603
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
  "stderr_tail": "Possibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 6 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 5 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 9 samples\nPossibly lost 11 samples\nPossibly lost 12 samples\nPossibly lost 11 samples\nPossibly lost 11 samples\nPossibly lost 12 samples\nPossibly lost 11 samples\nPossibly lost 11 samples\nPossibly lost 9 samples\nPossibly lost 11 samples\nPossibly lost 11 samples\nPossibly lost 142 samples\nPossibly lost 10 samples",
  "stdout_tail": "23540  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index1/level\n23540  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index1/coherency_line_size\n23540  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index1/ways_of_associativity\n23540  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/type\n23540  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/size\n23540  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/level\n23540  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/coherency_line_size\n23540  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/ways_of_associativity\n23540  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/type\n23540  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/size\n23540  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/level\n23540  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/coherency_line_size\n23540  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/ways_of_associativity\n23540  stress-ng           3   0 /sys/kernel/debug/clear_warn_once\n23540  stress-ng           3   0 /sys/devices/system/clocksource\n23540  stress-ng           4   0 /sys/devices/system/clocksource/clocksource0/current_clocksource\n23540  stress-ng           3   0 /proc/sys/kernel/sched_autogroup_enabled\n23540  stress-ng           3   0 /sys/devices/system/cpu\n23540  stress-ng          -1   2 /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor\n23540  stress-ng          -1   2 /sys/devices/system/cpu/cpu1/cpufreq/scaling_governor\n23540  stress-ng          -1   2 /sys/devices/system/cpu/cpu2/cpufreq/scaling_governor\n23540  stress-ng          -1   2 /sys/devices/system/cpu/cpu3/cpufreq/scaling_governor\n23541  stress-ng-utime     3   0 /proc/self/coredump_filter\n23541  stress-ng-utime     3   0 /proc/self/oom_score_adj\n23541  stress-ng-utime     3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/tmp-stress-ng-utime-23541-0\n23541  stress-ng-utime     4   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/tmp-stress-ng-utime-23541-0/stress-ng-utime-23541-0-3674436330\n23540  stress-ng           3   0 /sys/devices/system/clocksource\n23540  stress-ng           4   0 /sys/devices/system/clocksource/clocksource0/current_clocksource\n23542  bpftool             3   0 /etc/ld.so.cache\n23542  bpftool             3   0 /lib/x86_64-linux-gnu/libelf.so.1\n23542  bpftool             3   0 /lib/x86_64-linux-gnu/libcrypto.so.3\n23542  bpftool             3   0 /lib/x86_64-linux-gnu/libz.so.1\n23542  bpftool             3   0 /lib/x86_64-linux-gnu/libcap.so.2\n23542  bpftool             3   0 /lib/x86_64-linux-gnu/libc.so.6\n23542  bpftool             3   0 /lib/x86_64-linux-gnu/libzstd.so.1\n23542  bpftool             4   0 /etc/localtime\n23542  bpftool             4   0 /proc/self/fdinfo/3\n23542  bpftool             4   0 /proc/self/fdinfo/3\n23542  bpftool             4   0 /proc/self/fdinfo/3\n23542  bpftool             4   0 /proc/self/fdinfo/3"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1421": {
        "avg_ns_per_run": 125.06571443913441,
        "bytes_jited": 203,
        "bytes_xlated": 344,
        "id": 1421,
        "name": "cap_capable",
        "run_cnt_delta": 93115,
        "run_time_ns_delta": 11645494,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 13660.96854440536
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
      "1421": {
        "avg_ns_per_run": 124.52617730763035,
        "bytes_jited": 206,
        "bytes_xlated": 344,
        "id": 1421,
        "name": "cap_capable",
        "run_cnt_delta": 93115,
        "run_time_ns_delta": 11595255,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 13669.263747714767
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
  "stderr_tail": "  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-t4sxe_h5/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-t4sxe_h5/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\nIn file included from include/linux/security.h:9:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "17:42:58  0      25588  stress-ng-set    21   CAP_SYS_ADMIN        1\n17:42:58  0      25588  stress-ng-set    21   CAP_SYS_ADMIN        1\n17:42:58  0      25588  stress-ng-set    6    CAP_SETGID           1\n17:42:58  0      25588  stress-ng-set    21   CAP_SYS_ADMIN        1\n17:42:58  0      25588  stress-ng-set    21   CAP_SYS_ADMIN        1\n17:42:58  0      25588  stress-ng-set    7    CAP_SETUID           1\n17:42:58  0      25588  stress-ng-set    6    CAP_SETGID           1\n17:42:58  0      25588  stress-ng-set    6    CAP_SETGID           1\n17:42:58  0      25588  stress-ng-set    6    CAP_SETGID           1\n17:42:58  0      25588  stress-ng-set    6    CAP_SETGID           1\n17:42:58  0      25588  stress-ng-set    21   CAP_SYS_ADMIN        1\n17:42:58  0      25588  stress-ng-set    21   CAP_SYS_ADMIN        1\n17:42:58  0      25588  stress-ng-set    21   CAP_SYS_ADMIN        1\n17:42:58  0      25588  stress-ng-set    6    CAP_SETGID           1\n17:42:58  0      25588  stress-ng-set    21   CAP_SYS_ADMIN        1\n17:42:58  0      25588  stress-ng-set    21   CAP_SYS_ADMIN        1\n17:42:58  0      25588  stress-ng-set    7    CAP_SETUID           1\n17:42:58  0      25588  stress-ng-set    6    CAP_SETGID           1\n17:42:58  0      25588  stress-ng-set    6    CAP_SETGID           1\n17:42:58  0      25588  stress-ng-set    6    CAP_SETGID           1\n17:42:58  0      25588  stress-ng-set    6    CAP_SETGID           1\n17:42:58  0      25588  stress-ng-set    21   CAP_SYS_ADMIN        1\n17:42:58  0      25588  stress-ng-set    21   CAP_SYS_ADMIN        1\n17:42:58  0      25588  stress-ng-set    21   CAP_SYS_ADMIN        1\n17:42:58  0      25589  stress-ng        24   CAP_SYS_RESOURCE     1\n17:42:58  0      25590  stress-ng-timer  21   CAP_SYS_ADMIN        1\n17:42:58  0      25590  stress-ng-timer  21   CAP_SYS_ADMIN        1\n17:42:58  0      25590  stress-ng-timer  21   CAP_SYS_ADMIN        1\n17:42:58  0      25590  stress-ng-timer  21   CAP_SYS_ADMIN        1\n17:42:58  0      25591  bpftool          21   CAP_SYS_ADMIN        1\n17:42:58  0      25591  bpftool          21   CAP_SYS_ADMIN        1\n17:42:58  0      25591  bpftool          39   CAP_BPF              1\n17:42:58  0      25591  bpftool          21   CAP_SYS_ADMIN        1\n17:42:58  0      25591  bpftool          21   CAP_SYS_ADMIN        1\n17:42:58  0      25591  bpftool          39   CAP_BPF              1\n17:42:58  0      25591  bpftool          39   CAP_BPF              1\n17:42:58  0      25591  bpftool          39   CAP_BPF              1\n17:42:58  0      25591  bpftool          39   CAP_BPF              1\n17:42:58  0      25591  bpftool          21   CAP_SYS_ADMIN        1\n17:42:58  0      25591  bpftool          21   CAP_SYS_ADMIN        1"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1425": {
        "avg_ns_per_run": 32.165645424836605,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1425,
        "name": "vfs_create",
        "run_cnt_delta": 4896,
        "run_time_ns_delta": 157483,
        "type": "tracing"
      },
      "1426": {
        "avg_ns_per_run": 111.48895899053628,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1426,
        "name": "kfunc__vmlinux__vfs_fsync_range",
        "run_cnt_delta": 317,
        "run_time_ns_delta": 35342,
        "type": "tracing"
      },
      "1427": {
        "avg_ns_per_run": 25.956864661129337,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1427,
        "name": "vfs_open",
        "run_cnt_delta": 57308,
        "run_time_ns_delta": 1487536,
        "type": "tracing"
      },
      "1428": {
        "avg_ns_per_run": 25.482751623376622,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1428,
        "name": "vfs_read",
        "run_cnt_delta": 9856,
        "run_time_ns_delta": 251158,
        "type": "tracing"
      },
      "1429": {
        "avg_ns_per_run": 26.99627714581179,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1429,
        "name": "vfs_write",
        "run_cnt_delta": 4835,
        "run_time_ns_delta": 130527,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 322.0912605824043
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
      "1425": {
        "avg_ns_per_run": 32.02350296341713,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1425,
        "name": "vfs_create",
        "run_cnt_delta": 4893,
        "run_time_ns_delta": 156691,
        "type": "tracing"
      },
      "1426": {
        "avg_ns_per_run": 110.30599369085174,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1426,
        "name": "vfs_fsync_range",
        "run_cnt_delta": 317,
        "run_time_ns_delta": 34967,
        "type": "tracing"
      },
      "1427": {
        "avg_ns_per_run": 24.581892848301273,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1427,
        "name": "vfs_open",
        "run_cnt_delta": 68669,
        "run_time_ns_delta": 1688014,
        "type": "tracing"
      },
      "1428": {
        "avg_ns_per_run": 26.35211124644742,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1428,
        "name": "vfs_read",
        "run_cnt_delta": 9852,
        "run_time_ns_delta": 259621,
        "type": "tracing"
      },
      "1429": {
        "avg_ns_per_run": 27.436992293272233,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1429,
        "name": "vfs_write",
        "run_cnt_delta": 4801,
        "run_time_ns_delta": 131725,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 418.5813204301334
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
    "applied": 5,
    "not_applied": 0,
    "requested": 5
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-0vwq3v7g/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-0vwq3v7g/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "17:43:09:         0        0        0        0        0\n17:43:10:         0        0        0        0        0\n17:43:11:         1        1        0        0        0\n17:43:12:         0        0        0        0        0\n17:43:13:         2        2        0        0        0\n17:43:14:         0        0        0        0        0\n17:43:15:         0        0        0        0        0\n17:43:16:         0        0        0        0        0\n17:43:17:      1520      188        0     2745        4\n17:43:18:        13       10        0       38       10\n17:43:19:        14       10        0       38       10\n17:43:20:        13       11        0       42       11\n17:43:21:        15       11        0       38       10\n17:43:22:        14       11        0       42       11\n17:43:23:        14       11        0       38       10\n17:43:24:        14       11        0       42       11\n17:43:25:        13       10        0       38       10\n17:43:26:        14       11        0       40       11\n17:43:27:       864       31       28     1252       72\n17:43:28:      1578       58        5    10425      210\n17:43:29:       379       14       45      437        1\n17:43:30:       380       14       57      435        1\n17:43:31:         0        0       60        0        0\n17:43:32:      1520       57       47    41285     2001\n17:43:33:         4        4       57        0        0\n17:43:34:      3522     4339       18    11781     2513\n17:43:35:         0        0        0        0        0\n17:43:36:         0        0        0        0        0\n17:43:37:         0        0        0        0        0\n17:43:38:         0        0        0        0        0\n17:43:39:         0        0        0        0        0\n17:43:40:         0        0        0        0        0\n17:43:41:         1        1        0        0        0\n17:43:42:         0        0        0        0        0\n17:43:43:         2        2        0        0        0\n17:43:44:      1535      199        0     2787       15\n17:43:45:        34       25        0       98       26\n17:43:46:        50       40        0      150       40\n17:43:47:       509       35        0      770       58\n17:43:47:      1162       49       33     1870      236"
}
```

## tcpconnect

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1432": {
        "avg_ns_per_run": 1907.0,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1432,
        "name": "trace_connect_entry",
        "run_cnt_delta": 1,
        "run_time_ns_delta": 1907,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 6006.0,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1433,
        "name": "trace_connect_v4_return",
        "run_cnt_delta": 1,
        "run_time_ns_delta": 6006,
        "type": "kprobe"
      },
      "1434": {
        "avg_ns_per_run": null,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1434,
        "name": "trace_connect_v6_return",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 22238.6266117867
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
      "1432": {
        "avg_ns_per_run": 1994.0,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1432,
        "name": "trace_connect_e",
        "run_cnt_delta": 1,
        "run_time_ns_delta": 1994,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 5544.0,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1433,
        "name": "trace_connect_v",
        "run_cnt_delta": 1,
        "run_time_ns_delta": 5544,
        "type": "kprobe"
      },
      "1434": {
        "avg_ns_per_run": null,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1434,
        "name": "trace_connect_v",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 6185.617969406299
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
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-cga6tati/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:16:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "27355   stress-ng-so 4  127.0.0.1        127.0.0.1        22080\nTracing connect ... Hit Ctrl-C to end\nPID     COMM         IP SADDR            DADDR            DPORT\n27379   stress-ng-so 4  127.0.0.1        127.0.0.1        22080"
}
```

## bindsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1437": {
        "avg_ns_per_run": 1623.0,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1437,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 2,
        "run_time_ns_delta": 3246,
        "type": "kprobe"
      },
      "1438": {
        "avg_ns_per_run": 5521.0,
        "bytes_jited": 721,
        "bytes_xlated": 1160,
        "id": 1438,
        "name": "bindsnoop_v4_return",
        "run_cnt_delta": 2,
        "run_time_ns_delta": 11042,
        "type": "kprobe"
      },
      "1439": {
        "avg_ns_per_run": null,
        "bytes_jited": 742,
        "bytes_xlated": 1184,
        "id": 1439,
        "name": "bindsnoop_v6_return",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 22297.962796188716
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
      "1437": {
        "avg_ns_per_run": 1780.5,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1437,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 2,
        "run_time_ns_delta": 3561,
        "type": "kprobe"
      },
      "1438": {
        "avg_ns_per_run": 5566.0,
        "bytes_jited": 719,
        "bytes_xlated": 1160,
        "id": 1438,
        "name": "bindsnoop_v4_re",
        "run_cnt_delta": 2,
        "run_time_ns_delta": 11132,
        "type": "kprobe"
      },
      "1439": {
        "avg_ns_per_run": null,
        "bytes_jited": 740,
        "bytes_xlated": 1184,
        "id": 1439,
        "name": "bindsnoop_v6_re",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 20915.614766668295
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
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.679bfc7f/bcc-python-z9s6pco1/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:18:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "   27420 stress-ng-sc IP   0.0.0.0         21980 ..NR.  0\nTracing binds ... Hit Ctrl-C to end\n     PID COMM         PROT ADDR            PORT   OPTS IF\n   27423 stress-ng-so IP   0.0.0.0         22080 ..NR.  0\n   27444 stress-ng-sc IP   0.0.0.0         15040 ..NR.  0\n   27447 stress-ng-so IP   0.0.0.0         15040 ..NR.  0"
}
```

