# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-24T23:47:04.788053+00:00`
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
      "1411": {
        "avg_ns_per_run": 522.9907098462545,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1411,
        "name": "tracepoint__sock__inet_sock_set_state",
        "run_cnt_delta": 45855,
        "run_time_ns_delta": 23981739,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 417.2454776989475
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
      "1411": {
        "avg_ns_per_run": 563.34670433145,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1411,
        "name": "sock__inet_sock",
        "run_cnt_delta": 42480,
        "run_time_ns_delta": 23930968,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 386.4719034153244
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
  "output_chars": 4885,
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
  "stderr_tail": "In file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-79jjv1c_/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-79jjv1c_/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/tcp.h:7:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "3384  curl       ::1             41575 ::1             52994     0     0 0.30\n3384  curl       ::1             52994 ::1             41575     0     0 0.31\n3386  curl       127.0.0.1       37151 127.0.0.1       40060     0     0 0.38\n3386  curl       127.0.0.1       40060 127.0.0.1       37151     0     0 0.39\n3388  curl       ::1             41575 ::1             52996     0     0 0.32\n3388  curl       ::1             52996 ::1             41575     0     0 0.33\n3390  curl       127.0.0.1       37151 127.0.0.1       40072     0     0 0.37\n3390  curl       127.0.0.1       40072 127.0.0.1       37151     0     0 0.39\n3392  curl       ::1             41575 ::1             53006     0     0 0.30\n3392  curl       ::1             53006 ::1             41575     0     0 0.31\n3394  curl       127.0.0.1       37151 127.0.0.1       40084     0     0 0.31\n3394  curl       127.0.0.1       40084 127.0.0.1       37151     0     0 0.32\n3396  curl       ::1             41575 ::1             53016     0     0 0.42\n3396  curl       ::1             53016 ::1             41575     0     0 0.43\n3398  curl       127.0.0.1       37151 127.0.0.1       40096     0     0 0.37\n3398  curl       127.0.0.1       40096 127.0.0.1       37151     0     0 0.38\n3400  curl       ::1             41575 ::1             53020     0     0 0.34\n3400  curl       ::1             53020 ::1             41575     0     0 0.35\n3402  curl       127.0.0.1       37151 127.0.0.1       40112     0     0 0.22\n3402  curl       127.0.0.1       40112 127.0.0.1       37151     0     0 0.23\n3404  curl       ::1             41575 ::1             53022     0     0 0.39\n3404  curl       ::1             53022 ::1             41575     0     0 0.40\n3406  curl       127.0.0.1       37151 127.0.0.1       40118     0     0 0.37\n3406  curl       127.0.0.1       40118 127.0.0.1       37151     0     0 0.39\n3408  curl       ::1             41575 ::1             53036     0     0 0.33\n3408  curl       ::1             53036 ::1             41575     0     0 0.34\n3410  curl       127.0.0.1       37151 127.0.0.1       40122     0     0 0.54\n3410  curl       127.0.0.1       40122 127.0.0.1       37151     0     0 0.55\n3412  curl       ::1             41575 ::1             53050     0     0 0.31\n3412  curl       ::1             53050 ::1             41575     0     0 0.32\n3414  curl       127.0.0.1       37151 127.0.0.1       40136     0     0 0.49\n3414  curl       127.0.0.1       40136 127.0.0.1       37151     0     0 0.50\n3416  curl       ::1             41575 ::1             53066     0     0 0.32\n3416  curl       ::1             53066 ::1             41575     0     0 0.33\n3418  curl       127.0.0.1       37151 127.0.0.1       40152     0     0 0.41\n3418  curl       127.0.0.1       40152 127.0.0.1       37151     0     0 0.42\n3420  curl       ::1             41575 ::1             53070     0     0 0.32\n3420  curl       ::1             53070 ::1             41575     0     0 0.33\n3422  curl       127.0.0.1       37151 127.0.0.1       40154     0     0 0.50\n3422  curl       127.0.0.1       40154 127.0.0.1       37151     0     0 0.52"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1414": {
        "avg_ns_per_run": 61.51113201134769,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1414,
        "name": "trace_pid_start_tp",
        "run_cnt_delta": 9486336,
        "run_time_ns_delta": 583515266,
        "type": "tracepoint"
      },
      "1415": {
        "avg_ns_per_run": 92.26578923622355,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1415,
        "name": "trace_req_start",
        "run_cnt_delta": 9486336,
        "run_time_ns_delta": 875264278,
        "type": "kprobe"
      },
      "1416": {
        "avg_ns_per_run": 282.89910835964486,
        "bytes_jited": 550,
        "bytes_xlated": 856,
        "id": 1416,
        "name": "trace_req_completion_tp",
        "run_cnt_delta": 9486336,
        "run_time_ns_delta": 2683675996,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 947899.634677566
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
      "1414": {
        "avg_ns_per_run": 62.00208070977667,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1414,
        "name": "trace_pid_start",
        "run_cnt_delta": 9428994,
        "run_time_ns_delta": 584617247,
        "type": "tracepoint"
      },
      "1415": {
        "avg_ns_per_run": 94.0516842938527,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1415,
        "name": "trace_req_start",
        "run_cnt_delta": 9428996,
        "run_time_ns_delta": 886812955,
        "type": "kprobe"
      },
      "1416": {
        "avg_ns_per_run": 283.52084224865064,
        "bytes_jited": 548,
        "bytes_xlated": 848,
        "id": 1416,
        "name": "trace_req_compl",
        "run_cnt_delta": 9428997,
        "run_time_ns_delta": 2673317171,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 942506.3540208287
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
  "output_chars": 13075,
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
  "returncode": -15,
  "stderr_tail": "  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-a2kqka0a/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/blk-mq.h:5:\nIn file included from include/linux/blkdev.h:7:\nIn file included from include/linux/blk_types.h:7:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.\nException ignored on calling ctypes callback function: <function PerfEventArray._open_perf_buffer.<locals>.raw_cb_ at 0x7fb3503dfba0>\nTraceback (most recent call last):\n  File \"/usr/lib/python3/dist-packages/bcc/table.py\", line 991, in raw_cb_\n    callback(cpu, data, size)\n  File \"/usr/sbin/biosnoop-bpfcc\", line 421, in print_event\n    print(\"%7.2f\" % (float(event.delta) / 1000000))\nKeyboardInterrupt:",
  "stdout_tail": "20.296106                  8082    nullb0    R 32312      4096      0.00\n20.296107                  8082    nullb0    R 32320      4096      0.00\n20.296108                  8082    nullb0    R 32328      4096      0.00\n20.296110                  8082    nullb0    R 32336      4096      0.00\n20.296111                  8082    nullb0    R 32344      4096      0.00\n20.296112                  8082    nullb0    R 32352      4096      0.00\n20.296113                  8082    nullb0    R 32360      4096      0.00\n20.296114                  8082    nullb0    R 32368      4096      0.00\n20.296115                  8082    nullb0    R 32376      4096      0.00\n20.296117                  8082    nullb0    R 32384      4096      0.00\n20.296118                  8082    nullb0    R 32392      4096      0.00\n20.296119                  8082    nullb0    R 32400      4096      0.00\n20.296120                  8082    nullb0    R 32408      4096      0.00\n20.296121                  8082    nullb0    R 32416      4096      0.00\n20.296122                  8082    nullb0    R 32424      4096      0.00\n20.296123                  8082    nullb0    R 32432      4096      0.00\n20.296125                  8082    nullb0    R 32440      4096      0.00\n20.296126                  8082    nullb0    R 32448      4096      0.00\n20.296127                  8082    nullb0    R 32456      4096      0.00\n20.296128                  8082    nullb0    R 32464      4096      0.00\n20.296129                  8082    nullb0    R 32472      4096      0.00\n20.296131                  8082    nullb0    R 32480      4096      0.00\n20.296132                  8082    nullb0    R 32488      4096      0.00\n20.296133                  8082    nullb0    R 32496      4096      0.00\n20.296134                  8082    nullb0    R 32504      4096      0.00\n20.296135                  8082    nullb0    R 32512      4096      0.00\n20.296136                  8082    nullb0    R 32520      4096      0.00\n20.296138                  8082    nullb0    R 32528      4096      0.00\n20.296139                  8082    nullb0    R 32536      4096      0.00\n20.296140                  8082    nullb0    R 32544      4096      0.00\n20.296141                  8082    nullb0    R 32552      4096      0.00\n20.296142                  8082    nullb0    R 32560      4096      0.00\n20.296143                  8082    nullb0    R 32568      4096      0.00\n20.296145                  8082    nullb0    R 32576      4096      0.00\n20.296146                  8082    nullb0    R 32584      4096      0.00\n20.296147                  8082    nullb0    R 32592      4096      0.00\n20.296148                  8082    nullb0    R 32600      4096      0.00\n20.296149                  8082    nullb0    R 32608      4096      0.00\n20.296150                  8082    nullb0    R 32616      4096      0.00\n20.296152                  8082    nullb0    R 32624      4096"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1421": {
        "avg_ns_per_run": 171.61370338612167,
        "bytes_jited": 662,
        "bytes_xlated": 1168,
        "id": 1421,
        "name": "sched_switch",
        "run_cnt_delta": 1572064,
        "run_time_ns_delta": 269787725,
        "type": "raw_tracepoint"
      },
      "1422": {
        "avg_ns_per_run": 110.19789303571754,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1422,
        "name": "sched_wakeup",
        "run_cnt_delta": 822985,
        "run_time_ns_delta": 90691213,
        "type": "raw_tracepoint"
      },
      "1423": {
        "avg_ns_per_run": 231.36246011843795,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1423,
        "name": "raw_tracepoint__sched_wakeup_new",
        "run_cnt_delta": 169878,
        "run_time_ns_delta": 39303392,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 66.0763962227806
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
        "avg_ns_per_run": 170.2210439706893,
        "bytes_jited": 645,
        "bytes_xlated": 1136,
        "id": 1421,
        "name": "sched_switch",
        "run_cnt_delta": 1511939,
        "run_time_ns_delta": 257363835,
        "type": "raw_tracepoint"
      },
      "1422": {
        "avg_ns_per_run": 114.46417025689202,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1422,
        "name": "sched_wakeup",
        "run_cnt_delta": 779199,
        "run_time_ns_delta": 89190367,
        "type": "raw_tracepoint"
      },
      "1423": {
        "avg_ns_per_run": 235.72552645958555,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1423,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 166537,
        "run_time_ns_delta": 39257022,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 64.75914444011097
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
  "output_chars": 12840,
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
  "stderr_tail": "In file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-iwmn4nw6/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-iwmn4nw6/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:6:\nIn file included from include/linux/pid_namespace.h:7:\nIn file included from include/linux/mm.h:1118:\nIn file included from include/linux/huge_mm.h:7:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "             8388608 -> 16777215             : 5250     |                    |\n            16777216 -> 33554431             : 0        |                    |\n            33554432 -> 67108863             : 0        |                    |\n            67108864 -> 134217727            : 0        |                    |\n           134217728 -> 268435455            : 0        |                    |\n           268435456 -> 536870911            : 4543     |                    |\n           536870912 -> 1073741823           : 4493     |                    |\n          1073741824 -> 2147483647           : 4421     |                    |\n          2147483648 -> 4294967295           : 4158     |                    |\n          4294967296 -> 8589934591           : 0        |                    |\n          8589934592 -> 17179869183          : 0        |                    |\n         17179869184 -> 34359738367          : 0        |                    |\n         34359738368 -> 68719476735          : 0        |                    |\n         68719476736 -> 137438953471         : 3711     |                    |\n        137438953472 -> 274877906943         : 3651     |                    |\n        274877906944 -> 549755813887         : 3499     |                    |\n        549755813888 -> 1099511627775        : 3380     |                    |\n       1099511627776 -> 2199023255551        : 0        |                    |\n       2199023255552 -> 4398046511103        : 0        |                    |\n       4398046511104 -> 8796093022207        : 0        |                    |\n       8796093022208 -> 17592186044415       : 0        |                    |\n      17592186044416 -> 35184372088831       : 3017     |                    |\n      35184372088832 -> 70368744177663       : 2985     |                    |\n      70368744177664 -> 140737488355327      : 2881     |                    |\n     140737488355328 -> 281474976710655      : 2899     |                    |\n     281474976710656 -> 562949953421311      : 0        |                    |\n     562949953421312 -> 1125899906842623     : 0        |                    |\n    1125899906842624 -> 2251799813685247     : 0        |                    |\n    2251799813685248 -> 4503599627370495     : 0        |                    |\n    4503599627370496 -> 9007199254740991     : 2642     |                    |\n    9007199254740992 -> 18014398509481983    : 2742     |                    |\n   18014398509481984 -> 36028797018963967    : 2555     |                    |\n   36028797018963968 -> 72057594037927935    : 2600     |                    |\n   72057594037927936 -> 144115188075855871   : 0        |                    |\n  144115188075855872 -> 288230376151711743   : 0        |                    |\n  288230376151711744 -> 576460752303423487   : 0        |                    |\n  576460752303423488 -> 1152921504606846975  : 0        |                    |\n 1152921504606846976 -> 2305843009213693951  : 2723     |                    |\n 2305843009213693952 -> 4611686018427387903  : 2592     |                    |\n 4611686018427387904 -> 9223372036854775807  : 2563     |                    |"
}
```

## syscount

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1428": {
        "avg_ns_per_run": 84.91647804775681,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1428,
        "name": "tracepoint__raw_syscalls__sys_enter",
        "run_cnt_delta": 66713,
        "run_time_ns_delta": 5665033,
        "type": "tracepoint"
      },
      "1429": {
        "avg_ns_per_run": 87.29499497848995,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1429,
        "name": "tracepoint__raw_syscalls__sys_exit",
        "run_cnt_delta": 66713,
        "run_time_ns_delta": 5823711,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1193.3419773263684
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
      "1428": {
        "avg_ns_per_run": 82.80298488525162,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1428,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 63051,
        "run_time_ns_delta": 5220811,
        "type": "tracepoint"
      },
      "1429": {
        "avg_ns_per_run": 82.52587587825728,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1429,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 63051,
        "run_time_ns_delta": 5203339,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1108.501595098755
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
  "output_chars": 9098,
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-5uektk3y/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-5uektk3y/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "nanosleep                     4        10252.915\nbpf                         449          357.170\nioctl                      1103          182.071\nfutex                        35      8231517.979\n[23:44:29]\nSYSCALL                   COUNT        TIME (us)\nepoll_pwait                  19      3804592.127\nclock_nanosleep              11      2001403.137\nread                          2      1000115.201\nopenat                     1106       744673.799\nclose                      1106       144916.892\nfstat                      1106       107678.168\nnanosleep                     6        40694.475\nbpf                         449          720.360\nioctl                      1106          181.648\nclock_nanosleep              11      2001228.843\n[23:44:30]\nSYSCALL                   COUNT        TIME (us)\nfutex                        31      1328627.979\nread                          1      1000503.996\nopenat                     1052       711453.787\nepoll_pwait                   6       666678.745\nclose                      1052       138090.943\nfstat                      1053       102746.365\nunlinkat                    170        42651.821\nnanosleep                     5        20396.878\ngetdents64                    2         1469.343\nread                         18      1000164.831\n[23:44:30]\nSYSCALL                   COUNT        TIME (us)\nclock_nanosleep               2       125060.846\nunlinkat                     86        21748.933\npoll                          2         1927.537\nrmdir                         1          490.944\nvfork                         1          427.667\nexecve                        1          321.107\nclose                        27          198.343\nbpf                         471          158.996\nmmap                         30          139.486\nDetaching..."
}
```

## execsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1432": {
        "avg_ns_per_run": 1202.966331645759,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1432,
        "name": "syscall__execve",
        "run_cnt_delta": 40097,
        "run_time_ns_delta": 48235341,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 813.0164600842955,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1433,
        "name": "do_ret_sys_execve",
        "run_cnt_delta": 40097,
        "run_time_ns_delta": 32599521,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 2004.7733361136782
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
        "avg_ns_per_run": 1191.2480189177631,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1432,
        "name": "syscall__execve",
        "run_cnt_delta": 39751,
        "run_time_ns_delta": 47353300,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 815.05303011245,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1433,
        "name": "do_ret_sys_exec",
        "run_cnt_delta": 39751,
        "run_time_ns_delta": 32399173,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1987.486189753456
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
  "output_chars": 7428,
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
  "stderr_tail": "<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-3qznsjin/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-3qznsjin/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "23:44:55 65534 true             28440   1720      0 /bin/true\n23:44:55 65534 true             28441   1720      0 /bin/true\n23:44:55 65534 true             28442   1720      0 /bin/true\n23:44:55 65534 true             28443   1720      0 /bin/true\n23:44:55 65534 true             28444   1720      0 /bin/true\n23:44:55 65534 true             28445   1720      0 /bin/true\n23:44:55 65534 true             28446   1720      0 /bin/true\n23:44:55 65534 true             28447   1720      0 /bin/true\n23:44:55 65534 true             28448   1720      0 /bin/true\n23:44:55 65534 true             28449   1720      0 /bin/true\n23:44:55 65534 true             28450   1720      0 /bin/true\n23:44:55 65534 true             28451   1720      0 /bin/true\n23:44:55 65534 true             28452   1720      0 /bin/true\n23:44:55 65534 true             28453   1720      0 /bin/true\n23:44:55 65534 true             28454   1720      0 /bin/true\n23:44:55 65534 true             28455   1720      0 /bin/true\n23:44:55 65534 true             28456   1720      0 /bin/true\n23:44:55 65534 true             28457   1720      0 /bin/true\n23:44:55 65534 true             28458   1720      0 /bin/true\n23:44:55 65534 true             28459   1720      0 /bin/true\n23:44:55 65534 true             28460   1720      0 /bin/true\n23:44:55 65534 true             28461   1720      0 /bin/true\n23:44:55 65534 true             28462   1720      0 /bin/true\n23:44:55 65534 true             28463   1720      0 /bin/true\n23:44:55 65534 true             28464   1720      0 /bin/true\n23:44:55 65534 true             28465   1720      0 /bin/true\n23:44:55 65534 true             28466   1720      0 /bin/true\n23:44:55 65534 true             28467   1720      0 /bin/true\n23:44:55 65534 true             28468   1720      0 /bin/true\n23:44:55 65534 true             28469   1720      0 /bin/true\n23:44:55 65534 true             28470   1720      0 /bin/true\n23:44:55 65534 true             28471   1720      0 /bin/true\n23:44:55 65534 true             28472   1720      0 /bin/true\n23:44:55 65534 true             28473   1720      0 /bin/true\n23:44:55 65534 true             28474   1720      0 /bin/true\n23:44:55 65534 true             28475   1720      0 /bin/true\n23:44:55 65534 true             28476   1720      0 /bin/true\n23:44:55 65534 true             28477   1720      0 /bin/true\n23:44:55 65534 true             28478   1720      0 /bin/true\n23:44:55 65534 true             28479   1720      0 /bin/true"
}
```

## opensnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1436": {
        "avg_ns_per_run": null,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1436,
        "name": "__x64_sys_open",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1437": {
        "avg_ns_per_run": 2700.5080520425804,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1437,
        "name": "kretfunc__vmlinux____x64_sys_openat",
        "run_cnt_delta": 10991,
        "run_time_ns_delta": 29681284,
        "type": "tracing"
      },
      "1438": {
        "avg_ns_per_run": null,
        "bytes_jited": 590,
        "bytes_xlated": 640,
        "id": 1438,
        "name": "kretfunc__vmlinux____x64_sys_openat2",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1072.178228884981
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
      "1436": {
        "avg_ns_per_run": null,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1436,
        "name": "__x64_sys_open",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1437": {
        "avg_ns_per_run": 2706.9391130498,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1437,
        "name": "__x64_sys_opena",
        "run_cnt_delta": 11004,
        "run_time_ns_delta": 29787158,
        "type": "tracing"
      },
      "1438": {
        "avg_ns_per_run": null,
        "bytes_jited": 590,
        "bytes_xlated": 640,
        "id": 1438,
        "name": "__x64_sys_opena",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1073.435679090041
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
  "output_chars": 11107,
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-hzvwmm4g/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-hzvwmm4g/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-212.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-213.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-214.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-215.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-216.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-217.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-218.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-219.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-220.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-221.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-222.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-223.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-224.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-225.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-226.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-227.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-228.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-229.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-230.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-231.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-232.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-233.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-234.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-235.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-236.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-237.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17/open-238.dat\n1720   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/loopback-open-storm-vz2ell17\n28512  bpftool             3   0 /etc/ld.so.cache\n28512  bpftool             3   0 /lib/x86_64-linux-gnu/libelf.so.1\n28512  bpftool             3   0 /lib/x86_64-linux-gnu/libcrypto.so.3\n28512  bpftool             3   0 /lib/x86_64-linux-gnu/libz.so.1\n28512  bpftool             3   0 /lib/x86_64-linux-gnu/libcap.so.2\n28512  bpftool             3   0 /lib/x86_64-linux-gnu/libc.so.6\n28512  bpftool             3   0 /lib/x86_64-linux-gnu/libzstd.so.1\n28512  bpftool             4   0 /etc/localtime\n28512  bpftool             4   0 /proc/self/fdinfo/3\n28512  bpftool             4   0 /proc/self/fdinfo/3\n28512  bpftool             4   0 /proc/self/fdinfo/3\n28512  bpftool             4   0 /proc/self/fdinfo/3"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1441": {
        "avg_ns_per_run": 40.15256018956562,
        "bytes_jited": 203,
        "bytes_xlated": 344,
        "id": 1441,
        "name": "cap_capable",
        "run_cnt_delta": 2780673,
        "run_time_ns_delta": 111651140,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 2428.420768569699
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
      "1441": {
        "avg_ns_per_run": 40.51724469746006,
        "bytes_jited": 206,
        "bytes_xlated": 344,
        "id": 1441,
        "name": "cap_capable",
        "run_cnt_delta": 2774708,
        "run_time_ns_delta": 112423523,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 2426.8683200417327
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
  "output_chars": 3704,
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
  "stderr_tail": "  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-dln9qbwe/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-dln9qbwe/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\nIn file included from include/linux/security.h:9:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "23:45:46  65534  4281   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4283   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4284   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4286   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4288   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4292   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4298   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4302   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4279   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4280   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4282   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4304   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4290   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4285   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4307   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4308   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4309   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4291   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4310   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4287   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4289   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4295   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4301   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4303   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4305   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4306   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4313   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4311   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  65534  4312   stress-ng-exec   8    CAP_SETPCAP          1\n23:45:46  0      4330   bpftool          21   CAP_SYS_ADMIN        1\n23:45:46  0      4330   bpftool          21   CAP_SYS_ADMIN        1\n23:45:46  0      4330   bpftool          39   CAP_BPF              1\n23:45:46  0      4330   bpftool          21   CAP_SYS_ADMIN        1\n23:45:46  0      4330   bpftool          21   CAP_SYS_ADMIN        1\n23:45:46  0      4330   bpftool          39   CAP_BPF              1\n23:45:46  0      4330   bpftool          39   CAP_BPF              1\n23:45:46  0      4330   bpftool          39   CAP_BPF              1\n23:45:46  0      4330   bpftool          39   CAP_BPF              1\n23:45:46  0      4330   bpftool          21   CAP_SYS_ADMIN        1\n23:45:46  0      4330   bpftool          21   CAP_SYS_ADMIN        1"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1445": {
        "avg_ns_per_run": null,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1445,
        "name": "vfs_create",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1446": {
        "avg_ns_per_run": null,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1446,
        "name": "kfunc__vmlinux__vfs_fsync_range",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1447": {
        "avg_ns_per_run": 75.17972972972973,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1447,
        "name": "vfs_open",
        "run_cnt_delta": 740,
        "run_time_ns_delta": 55633,
        "type": "tracing"
      },
      "1448": {
        "avg_ns_per_run": 34.42650103519669,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1448,
        "name": "vfs_read",
        "run_cnt_delta": 1449,
        "run_time_ns_delta": 49884,
        "type": "tracing"
      },
      "1449": {
        "avg_ns_per_run": 35.71129707112971,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1449,
        "name": "vfs_write",
        "run_cnt_delta": 717,
        "run_time_ns_delta": 25605,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 71.17574398406707
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
      "1445": {
        "avg_ns_per_run": null,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1445,
        "name": "vfs_create",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1446": {
        "avg_ns_per_run": null,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1446,
        "name": "vfs_fsync_range",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1447": {
        "avg_ns_per_run": 71.46008119079838,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1447,
        "name": "vfs_open",
        "run_cnt_delta": 739,
        "run_time_ns_delta": 52809,
        "type": "tracing"
      },
      "1448": {
        "avg_ns_per_run": 33.908085694540425,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1448,
        "name": "vfs_read",
        "run_cnt_delta": 1447,
        "run_time_ns_delta": 49065,
        "type": "tracing"
      },
      "1449": {
        "avg_ns_per_run": 34.339385474860336,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1449,
        "name": "vfs_write",
        "run_cnt_delta": 716,
        "run_time_ns_delta": 24587,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 71.18889577806459
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
  "output_chars": 19744,
  "output_stripped": true,
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-xk0tcysc/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-xk0tcysc/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "TIME         READ/s  WRITE/s  FSYNC/s   OPEN/s CREATE/s\n23:45:49:      1487        5        0      132        0\n23:45:50:       100        5        0      130        0\n23:45:51:       164       65        0      114        0\n23:45:52:       148       74        0       74        0\n23:45:53:       140       70        0       71        0\n23:45:54:       135       68        0       66        0\n23:45:55:       142       71        0       71        0\n23:45:56:       139       70        0       69        0\n23:45:57:       153       77        0       76        0\n23:45:58:       138       69        0       69        0\n23:45:59:       142       71        0       71        0\n23:46:00:       142       71        0       71        0\n23:46:01:       131       38        0      109        0\n23:46:02:       145       72        0       72        0\n23:46:03:       146       74        0       72        0\n23:46:04:       146       72        0       73        0\n23:46:05:       147       75        0       73        0\n23:46:06:       146       73        0       73        0\n23:46:07:       141       71        0       70        0\n23:46:08:       140       70        0       70        0\n23:46:09:       140       69        0       70        0\n23:46:10:       136       68        0       68        0\n23:46:11:       116       49        0       75        0"
}
```

## tcpconnect

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1452": {
        "avg_ns_per_run": 599.3254574936299,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1452,
        "name": "trace_connect_entry",
        "run_cnt_delta": 4317,
        "run_time_ns_delta": 2587288,
        "type": "kprobe"
      },
      "1453": {
        "avg_ns_per_run": 3972.5567392311254,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1453,
        "name": "trace_connect_v4_return",
        "run_cnt_delta": 2159,
        "run_time_ns_delta": 8576750,
        "type": "kprobe"
      },
      "1454": {
        "avg_ns_per_run": 3960.6983317886934,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1454,
        "name": "trace_connect_v6_return",
        "run_cnt_delta": 2158,
        "run_time_ns_delta": 8547187,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 431.6686354317895
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
      "1452": {
        "avg_ns_per_run": 594.3247625665972,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1452,
        "name": "trace_connect_e",
        "run_cnt_delta": 4317,
        "run_time_ns_delta": 2565700,
        "type": "kprobe"
      },
      "1453": {
        "avg_ns_per_run": 4024.9847151459007,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1453,
        "name": "trace_connect_v",
        "run_cnt_delta": 2159,
        "run_time_ns_delta": 8689942,
        "type": "kprobe"
      },
      "1454": {
        "avg_ns_per_run": 3972.4101019462464,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1454,
        "name": "trace_connect_v",
        "run_cnt_delta": 2158,
        "run_time_ns_delta": 8572461,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 431.67451808053465
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
  "output_chars": 12348,
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
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-an3supf1/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:16:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "21589   curl         6  ::1              ::1              33371\n21591   curl         4  127.0.0.1        127.0.0.1        34639\n21593   curl         6  ::1              ::1              33371\n21595   curl         4  127.0.0.1        127.0.0.1        34639\n21597   curl         6  ::1              ::1              33371\n21599   curl         4  127.0.0.1        127.0.0.1        34639\n21601   curl         6  ::1              ::1              33371\n21603   curl         4  127.0.0.1        127.0.0.1        34639\n21605   curl         6  ::1              ::1              33371\n21607   curl         4  127.0.0.1        127.0.0.1        34639\n21609   curl         6  ::1              ::1              33371\n21611   curl         4  127.0.0.1        127.0.0.1        34639\n21613   curl         6  ::1              ::1              33371\n21615   curl         4  127.0.0.1        127.0.0.1        34639\n21617   curl         6  ::1              ::1              33371\n21619   curl         4  127.0.0.1        127.0.0.1        34639\n21621   curl         6  ::1              ::1              33371\n21623   curl         4  127.0.0.1        127.0.0.1        34639\n21625   curl         6  ::1              ::1              33371\n21627   curl         4  127.0.0.1        127.0.0.1        34639\n21629   curl         6  ::1              ::1              33371\n21631   curl         4  127.0.0.1        127.0.0.1        34639\n21633   curl         6  ::1              ::1              33371\n21635   curl         4  127.0.0.1        127.0.0.1        34639\n21637   curl         6  ::1              ::1              33371\n21639   curl         4  127.0.0.1        127.0.0.1        34639\n21641   curl         6  ::1              ::1              33371\n21643   curl         4  127.0.0.1        127.0.0.1        34639\n21645   curl         6  ::1              ::1              33371\n21647   curl         4  127.0.0.1        127.0.0.1        34639\n21649   curl         6  ::1              ::1              33371\n21651   curl         4  127.0.0.1        127.0.0.1        34639\n21653   curl         6  ::1              ::1              33371\n21655   curl         4  127.0.0.1        127.0.0.1        34639\n21657   curl         6  ::1              ::1              33371\n21659   curl         4  127.0.0.1        127.0.0.1        34639\n21661   curl         6  ::1              ::1              33371\n21663   curl         4  127.0.0.1        127.0.0.1        34639\n21665   curl         6  ::1              ::1              33371\n21667   curl         4  127.0.0.1        127.0.0.1        34639"
}
```

## bindsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1457": {
        "avg_ns_per_run": 57.31381210561753,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1457,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1981262,
        "run_time_ns_delta": 113553678,
        "type": "kprobe"
      },
      "1458": {
        "avg_ns_per_run": 842.2608610067724,
        "bytes_jited": 721,
        "bytes_xlated": 1160,
        "id": 1458,
        "name": "bindsnoop_v4_return",
        "run_cnt_delta": 990631,
        "run_time_ns_delta": 834369719,
        "type": "kprobe"
      },
      "1459": {
        "avg_ns_per_run": 785.8425417738795,
        "bytes_jited": 742,
        "bytes_xlated": 1184,
        "id": 1459,
        "name": "bindsnoop_v6_return",
        "run_cnt_delta": 990631,
        "run_time_ns_delta": 778479983,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 198126.10402771656
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
      "1457": {
        "avg_ns_per_run": 56.545483340562676,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1457,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1982660,
        "run_time_ns_delta": 112110468,
        "type": "kprobe"
      },
      "1458": {
        "avg_ns_per_run": 837.9337859239607,
        "bytes_jited": 719,
        "bytes_xlated": 1160,
        "id": 1458,
        "name": "bindsnoop_v4_re",
        "run_cnt_delta": 991330,
        "run_time_ns_delta": 830668900,
        "type": "kprobe"
      },
      "1459": {
        "avg_ns_per_run": 790.6355401329527,
        "bytes_jited": 740,
        "bytes_xlated": 1184,
        "id": 1459,
        "name": "bindsnoop_v6_re",
        "run_cnt_delta": 991330,
        "run_time_ns_delta": 783780730,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 198265.895375089
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
  "output_chars": 12436,
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
  "stderr_tail": "arch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8742eb1c/bcc-python-58rmj1rt/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:18:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.\nPossibly lost 69 samples\nPossibly lost 56 samples\nPossibly lost 17 samples\nPossibly lost 227 samples",
  "stdout_tail": "    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   127.0.0.1       11904 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0\n    1720 python3      IP   ::1             17024 ..NR.  0"
}
```

