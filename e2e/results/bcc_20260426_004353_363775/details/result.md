# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-26T00:48:27.145622+00:00`
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
        "avg_ns_per_run": 555.6272684969754,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1391,
        "name": "tracepoint__sock__inet_sock_set_state",
        "run_cnt_delta": 42980,
        "run_time_ns_delta": 23880860,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 390.9194667979242
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
        "avg_ns_per_run": 573.965193052964,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1391,
        "name": "sock__inet_sock",
        "run_cnt_delta": 41802,
        "run_time_ns_delta": 23992893,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 380.38950592843025
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
  "stderr_tail": "In file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-mkjrxm5c/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-mkjrxm5c/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/tcp.h:7:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "29618 curl       127.0.0.1       45347 127.0.0.1       33290     0     0 0.40\n29618 curl       127.0.0.1       33290 127.0.0.1       45347     0     0 0.41\n29620 curl       ::1             36545 ::1             53934     0     0 0.30\n29620 curl       ::1             53934 ::1             36545     0     0 0.31\n29622 curl       127.0.0.1       45347 127.0.0.1       33294     0     0 0.26\n29622 curl       127.0.0.1       33294 127.0.0.1       45347     0     0 0.27\n29624 curl       ::1             36545 ::1             53940     0     0 0.27\n29624 curl       ::1             53940 ::1             36545     0     0 0.28\n29626 curl       127.0.0.1       45347 127.0.0.1       33296     0     0 0.44\n29626 curl       127.0.0.1       33296 127.0.0.1       45347     0     0 0.45\n29628 curl       ::1             36545 ::1             53950     0     0 0.25\n29628 curl       ::1             53950 ::1             36545     0     0 0.26\n29630 curl       127.0.0.1       45347 127.0.0.1       33298     0     0 0.22\n29630 curl       127.0.0.1       33298 127.0.0.1       45347     0     0 0.23\n29632 curl       ::1             36545 ::1             53956     0     0 0.28\n29632 curl       ::1             53956 ::1             36545     0     0 0.29\n29634 curl       127.0.0.1       45347 127.0.0.1       33306     0     0 0.38\n29634 curl       127.0.0.1       33306 127.0.0.1       45347     0     0 0.39\n29636 curl       ::1             36545 ::1             53962     0     0 0.27\n29636 curl       ::1             53962 ::1             36545     0     0 0.28\n29638 curl       127.0.0.1       45347 127.0.0.1       33322     0     0 0.19\n29638 curl       127.0.0.1       33322 127.0.0.1       45347     0     0 0.20\n29640 curl       ::1             36545 ::1             53968     0     0 0.24\n29640 curl       ::1             53968 ::1             36545     0     0 0.25\n29642 curl       127.0.0.1       45347 127.0.0.1       33336     0     0 0.35\n29642 curl       127.0.0.1       33336 127.0.0.1       45347     0     0 0.35\n29644 curl       ::1             36545 ::1             53972     0     0 0.25\n29644 curl       ::1             53972 ::1             36545     0     0 0.26\n29646 curl       127.0.0.1       45347 127.0.0.1       33344     0     0 0.24\n29646 curl       127.0.0.1       33344 127.0.0.1       45347     0     0 0.25\n29648 curl       ::1             36545 ::1             53986     0     0 0.22\n29648 curl       ::1             53986 ::1             36545     0     0 0.23\n29650 curl       127.0.0.1       45347 127.0.0.1       33356     0     0 0.27\n29650 curl       127.0.0.1       33356 127.0.0.1       45347     0     0 0.28\n29652 curl       ::1             36545 ::1             53988     0     0 0.39\n29652 curl       ::1             53988 ::1             36545     0     0 0.40\n29654 curl       127.0.0.1       45347 127.0.0.1       33366     0     0 0.25\n29654 curl       127.0.0.1       33366 127.0.0.1       45347     0     0 0.26\n29656 curl       ::1             36545 ::1             53994     0     0 0.26\n29656 curl       ::1             53994 ::1             36545     0     0 0.27"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1394": {
        "avg_ns_per_run": 63.33450708908859,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1394,
        "name": "trace_pid_start_tp",
        "run_cnt_delta": 9322496,
        "run_time_ns_delta": 590435689,
        "type": "tracepoint"
      },
      "1395": {
        "avg_ns_per_run": 91.7296510505341,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1395,
        "name": "trace_req_start",
        "run_cnt_delta": 9322496,
        "run_time_ns_delta": 855149305,
        "type": "kprobe"
      },
      "1396": {
        "avg_ns_per_run": 284.2543869152639,
        "bytes_jited": 550,
        "bytes_xlated": 856,
        "id": 1396,
        "name": "trace_req_completion_tp",
        "run_cnt_delta": 9322496,
        "run_time_ns_delta": 2649960385,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 931860.0403830553
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
        "avg_ns_per_run": 63.85981717438152,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1394,
        "name": "trace_pid_start",
        "run_cnt_delta": 9363458,
        "run_time_ns_delta": 597948716,
        "type": "tracepoint"
      },
      "1395": {
        "avg_ns_per_run": 91.91193394322184,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1395,
        "name": "trace_req_start",
        "run_cnt_delta": 9363460,
        "run_time_ns_delta": 860613717,
        "type": "kprobe"
      },
      "1396": {
        "avg_ns_per_run": 285.1675553515949,
        "bytes_jited": 548,
        "bytes_xlated": 848,
        "id": 1396,
        "name": "trace_req_compl",
        "run_cnt_delta": 9363461,
        "run_time_ns_delta": 2670155283,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 935616.3624561563
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
  "stderr_tail": "      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-p0u6d0qs/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/blk-mq.h:5:\nIn file included from include/linux/blkdev.h:7:\nIn file included from include/linux/blk_types.h:7:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.\nException ignored on calling ctypes callback function: <function PerfEventArray._open_perf_buffer.<locals>.raw_cb_ at 0x7f9575dafba0>\nTraceback (most recent call last):\n  File \"/usr/lib/python3/dist-packages/bcc/table.py\", line 991, in raw_cb_\n    callback(cpu, data, size)\n  File \"/usr/sbin/biosnoop-bpfcc\", line 404, in print_event\n    delta = float(event.ts) - start_ts\n            ^^^^^^^^^^^^^^^\nKeyboardInterrupt:",
  "stdout_tail": "20.294775                  1847    nullb0    R 32264      4096      0.00\n20.294776                  1847    nullb0    R 32272      4096      0.00\n20.294777                  1847    nullb0    R 32280      4096      0.00\n20.294779                  1847    nullb0    R 32288      4096      0.00\n20.294780                  1847    nullb0    R 32296      4096      0.00\n20.294781                  1847    nullb0    R 32304      4096      0.00\n20.294782                  1847    nullb0    R 32312      4096      0.00\n20.294783                  1847    nullb0    R 32320      4096      0.00\n20.294784                  1847    nullb0    R 32328      4096      0.00\n20.294785                  1847    nullb0    R 32336      4096      0.00\n20.294787                  1847    nullb0    R 32344      4096      0.00\n20.294788                  1847    nullb0    R 32352      4096      0.00\n20.294789                  1847    nullb0    R 32360      4096      0.00\n20.294791                  1847    nullb0    R 32368      4096      0.00\n20.294792                  1847    nullb0    R 32376      4096      0.00\n20.294793                  1847    nullb0    R 32384      4096      0.00\n20.294794                  1847    nullb0    R 32392      4096      0.00\n20.294795                  1847    nullb0    R 32400      4096      0.00\n20.294796                  1847    nullb0    R 32408      4096      0.00\n20.294798                  1847    nullb0    R 32416      4096      0.00\n20.294799                  1847    nullb0    R 32424      4096      0.00\n20.294800                  1847    nullb0    R 32432      4096      0.00\n20.294801                  1847    nullb0    R 32440      4096      0.00\n20.294802                  1847    nullb0    R 32448      4096      0.00\n20.294803                  1847    nullb0    R 32456      4096      0.00\n20.294804                  1847    nullb0    R 32464      4096      0.00\n20.294805                  1847    nullb0    R 32472      4096      0.00\n20.294807                  1847    nullb0    R 32480      4096      0.00\n20.294808                  1847    nullb0    R 32488      4096      0.00\n20.294809                  1847    nullb0    R 32496      4096      0.00\n20.294810                  1847    nullb0    R 32504      4096      0.00\n20.294811                  1847    nullb0    R 32512      4096      0.00\n20.294812                  1847    nullb0    R 32520      4096      0.00\n20.294813                  1847    nullb0    R 32528      4096      0.00\n20.294814                  1847    nullb0    R 32536      4096      0.00\n20.294816                  1847    nullb0    R 32544      4096      0.00\n20.294817                  1847    nullb0    R 32552      4096      0.00\n20.294818                  1847    nullb0    R 32560      4096      0.00\n20.294819                  1847    nullb0    R 32568      4096      0.00\n20.294820                  1847    nullb0    R 32576      4096"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1401": {
        "avg_ns_per_run": 171.41782046460864,
        "bytes_jited": 662,
        "bytes_xlated": 1168,
        "id": 1401,
        "name": "sched_switch",
        "run_cnt_delta": 1579566,
        "run_time_ns_delta": 270765761,
        "type": "raw_tracepoint"
      },
      "1402": {
        "avg_ns_per_run": 110.33355621706043,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1402,
        "name": "sched_wakeup",
        "run_cnt_delta": 824047,
        "run_time_ns_delta": 90920036,
        "type": "raw_tracepoint"
      },
      "1403": {
        "avg_ns_per_run": 241.93379375202045,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1403,
        "name": "raw_tracepoint__sched_wakeup_new",
        "run_cnt_delta": 170135,
        "run_time_ns_delta": 41161406,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 66.12781651546109
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
        "avg_ns_per_run": 169.97732700491,
        "bytes_jited": 645,
        "bytes_xlated": 1136,
        "id": 1401,
        "name": "sched_switch",
        "run_cnt_delta": 1527500,
        "run_time_ns_delta": 259640367,
        "type": "raw_tracepoint"
      },
      "1402": {
        "avg_ns_per_run": 114.0625240327222,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1402,
        "name": "sched_wakeup",
        "run_cnt_delta": 795790,
        "run_time_ns_delta": 90769816,
        "type": "raw_tracepoint"
      },
      "1403": {
        "avg_ns_per_run": 244.56975502043983,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1403,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 167565,
        "run_time_ns_delta": 40981331,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 65.1585628875891
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
  "output_chars": 12839,
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
  "stderr_tail": "In file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-hkmy86uj/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-hkmy86uj/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:6:\nIn file included from include/linux/pid_namespace.h:7:\nIn file included from include/linux/mm.h:1118:\nIn file included from include/linux/huge_mm.h:7:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "             8388608 -> 16777215             : 5251     |                    |\n            16777216 -> 33554431             : 0        |                    |\n            33554432 -> 67108863             : 0        |                    |\n            67108864 -> 134217727            : 0        |                    |\n           134217728 -> 268435455            : 0        |                    |\n           268435456 -> 536870911            : 4310     |                    |\n           536870912 -> 1073741823           : 4374     |                    |\n          1073741824 -> 2147483647           : 4145     |                    |\n          2147483648 -> 4294967295           : 4098     |                    |\n          4294967296 -> 8589934591           : 0        |                    |\n          8589934592 -> 17179869183          : 0        |                    |\n         17179869184 -> 34359738367          : 0        |                    |\n         34359738368 -> 68719476735          : 0        |                    |\n         68719476736 -> 137438953471         : 3592     |                    |\n        137438953472 -> 274877906943         : 3624     |                    |\n        274877906944 -> 549755813887         : 3405     |                    |\n        549755813888 -> 1099511627775        : 3425     |                    |\n       1099511627776 -> 2199023255551        : 0        |                    |\n       2199023255552 -> 4398046511103        : 0        |                    |\n       4398046511104 -> 8796093022207        : 0        |                    |\n       8796093022208 -> 17592186044415       : 0        |                    |\n      17592186044416 -> 35184372088831       : 2857     |                    |\n      35184372088832 -> 70368744177663       : 3013     |                    |\n      70368744177664 -> 140737488355327      : 2874     |                    |\n     140737488355328 -> 281474976710655      : 2977     |                    |\n     281474976710656 -> 562949953421311      : 0        |                    |\n     562949953421312 -> 1125899906842623     : 0        |                    |\n    1125899906842624 -> 2251799813685247     : 0        |                    |\n    2251799813685248 -> 4503599627370495     : 0        |                    |\n    4503599627370496 -> 9007199254740991     : 2760     |                    |\n    9007199254740992 -> 18014398509481983    : 2818     |                    |\n   18014398509481984 -> 36028797018963967    : 2660     |                    |\n   36028797018963968 -> 72057594037927935    : 2606     |                    |\n   72057594037927936 -> 144115188075855871   : 0        |                    |\n  144115188075855872 -> 288230376151711743   : 0        |                    |\n  288230376151711744 -> 576460752303423487   : 0        |                    |\n  576460752303423488 -> 1152921504606846975  : 0        |                    |\n 1152921504606846976 -> 2305843009213693951  : 2619     |                    |\n 2305843009213693952 -> 4611686018427387903  : 2589     |                    |\n 4611686018427387904 -> 9223372036854775807  : 2594     |                    |"
}
```

## syscount

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1408": {
        "avg_ns_per_run": 84.62583608671126,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1408,
        "name": "tracepoint__raw_syscalls__sys_enter",
        "run_cnt_delta": 62045,
        "run_time_ns_delta": 5250610,
        "type": "tracepoint"
      },
      "1409": {
        "avg_ns_per_run": 86.79024901281328,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1409,
        "name": "tracepoint__raw_syscalls__sys_exit",
        "run_cnt_delta": 62045,
        "run_time_ns_delta": 5384901,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1091.1699164454064
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
        "avg_ns_per_run": 89.51204073999482,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1408,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 69514,
        "run_time_ns_delta": 6222340,
        "type": "tracepoint"
      },
      "1409": {
        "avg_ns_per_run": 89.9830825445234,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1409,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 69514,
        "run_time_ns_delta": 6255084,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1250.5758166149799
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-pxck3yk8/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-pxck3yk8/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "nanosleep                     1        10171.895\nbpf                         449          420.353\nioctl                      1265          186.369\nfutex                         3      2001774.143\n[00:45:43]\nSYSCALL                   COUNT        TIME (us)\nclock_nanosleep              11      2001675.296\nepoll_pwait                   3      1006009.794\nread                          1      1000149.594\nopenat                     1294       748609.948\nclose                      1294       159392.549\nfstat                      1294        88397.673\nnanosleep                     1        10129.226\nbpf                         449          639.421\nioctl                      1294          192.635\nfutex                         3      2001741.075\n[00:45:44]\nSYSCALL                   COUNT        TIME (us)\nclock_nanosleep              11      2001582.648\nepoll_pwait                   3      1005882.127\nread                          9      1000503.094\nopenat                     1270       746321.576\nclose                      1270       159111.599\nfstat                      1270        91218.758\nnanosleep                     1        10052.672\nbpf                         449          656.137\nioctl                      1270          200.049\nfutex                         6     11996856.757\n[00:45:45]\nSYSCALL                   COUNT        TIME (us)\nepoll_pwait                   6      6009973.851\nclock_nanosleep              10      1763891.472\nread                         16      1000284.503\nopenat                     1032       598177.466\nclose                      1048       127557.167\nfstat                      1037        72343.209\nunlinkat                    256        56379.321\nnanosleep                     2        20107.212\npoll                          2         2603.713\nDetaching..."
}
```

## execsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1412": {
        "avg_ns_per_run": 1203.9896211988269,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1412,
        "name": "syscall__execve",
        "run_cnt_delta": 39889,
        "run_time_ns_delta": 48025942,
        "type": "kprobe"
      },
      "1413": {
        "avg_ns_per_run": 828.834992103086,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1413,
        "name": "do_ret_sys_execve",
        "run_cnt_delta": 39889,
        "run_time_ns_delta": 33061399,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1994.3848013917654
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
        "avg_ns_per_run": 1166.982374978,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1412,
        "name": "syscall__execve",
        "run_cnt_delta": 39773,
        "run_time_ns_delta": 46414390,
        "type": "kprobe"
      },
      "1413": {
        "avg_ns_per_run": 817.9259045080834,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1413,
        "name": "do_ret_sys_exec",
        "run_cnt_delta": 39773,
        "run_time_ns_delta": 32531367,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1988.5481897689058
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
  "stderr_tail": "<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-wj0gj6cw/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-wj0gj6cw/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "00:46:10 65534 true             24003   1731      0 /bin/true\n00:46:10 65534 true             24004   1731      0 /bin/true\n00:46:10 65534 true             24005   1731      0 /bin/true\n00:46:10 65534 true             24006   1731      0 /bin/true\n00:46:10 65534 true             24007   1731      0 /bin/true\n00:46:10 65534 true             24008   1731      0 /bin/true\n00:46:10 65534 true             24009   1731      0 /bin/true\n00:46:10 65534 true             24010   1731      0 /bin/true\n00:46:10 65534 true             24011   1731      0 /bin/true\n00:46:10 65534 true             24012   1731      0 /bin/true\n00:46:10 65534 true             24013   1731      0 /bin/true\n00:46:10 65534 true             24014   1731      0 /bin/true\n00:46:10 65534 true             24015   1731      0 /bin/true\n00:46:10 65534 true             24016   1731      0 /bin/true\n00:46:10 65534 true             24017   1731      0 /bin/true\n00:46:10 65534 true             24018   1731      0 /bin/true\n00:46:10 65534 true             24019   1731      0 /bin/true\n00:46:10 65534 true             24020   1731      0 /bin/true\n00:46:10 65534 true             24021   1731      0 /bin/true\n00:46:10 65534 true             24022   1731      0 /bin/true\n00:46:10 65534 true             24023   1731      0 /bin/true\n00:46:10 65534 true             24024   1731      0 /bin/true\n00:46:10 65534 true             24025   1731      0 /bin/true\n00:46:10 65534 true             24026   1731      0 /bin/true\n00:46:10 65534 true             24027   1731      0 /bin/true\n00:46:10 65534 true             24028   1731      0 /bin/true\n00:46:10 65534 true             24029   1731      0 /bin/true\n00:46:10 65534 true             24030   1731      0 /bin/true\n00:46:10 65534 true             24031   1731      0 /bin/true\n00:46:10 65534 true             24032   1731      0 /bin/true\n00:46:10 65534 true             24033   1731      0 /bin/true\n00:46:10 65534 true             24034   1731      0 /bin/true\n00:46:10 65534 true             24035   1731      0 /bin/true\n00:46:10 65534 true             24036   1731      0 /bin/true\n00:46:10 65534 true             24037   1731      0 /bin/true\n00:46:10 65534 true             24038   1731      0 /bin/true\n00:46:10 65534 true             24039   1731      0 /bin/true\n00:46:10 65534 true             24040   1731      0 /bin/true\n00:46:10 65534 true             24041   1731      0 /bin/true\n00:46:10 65534 true             24042   1731      0 /bin/true"
}
```

## opensnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1416": {
        "avg_ns_per_run": null,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1416,
        "name": "__x64_sys_open",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1417": {
        "avg_ns_per_run": 2789.2343222272934,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1417,
        "name": "kretfunc__vmlinux____x64_sys_openat",
        "run_cnt_delta": 10955,
        "run_time_ns_delta": 30556062,
        "type": "tracing"
      },
      "1418": {
        "avg_ns_per_run": null,
        "bytes_jited": 590,
        "bytes_xlated": 640,
        "id": 1418,
        "name": "kretfunc__vmlinux____x64_sys_openat2",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1068.5473361102718
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
        "avg_ns_per_run": null,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1416,
        "name": "__x64_sys_open",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1417": {
        "avg_ns_per_run": 2621.365522890689,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1417,
        "name": "__x64_sys_opena",
        "run_cnt_delta": 10987,
        "run_time_ns_delta": 28800943,
        "type": "tracing"
      },
      "1418": {
        "avg_ns_per_run": null,
        "bytes_jited": 590,
        "bytes_xlated": 640,
        "id": 1418,
        "name": "__x64_sys_opena",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1071.7334532833775
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
  "returncode": -15,
  "stderr_tail": "In file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-nmrlb79j/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.\nException ignored on calling ctypes callback function: <function PerfEventArray._open_perf_buffer.<locals>.raw_cb_ at 0x7f706c2300e0>\nTraceback (most recent call last):\n  File \"/usr/lib/python3/dist-packages/bcc/table.py\", line 991, in raw_cb_\n    callback(cpu, data, size)\n  File \"/usr/sbin/opensnoop-bpfcc\", line 451, in print_event\n    printb(b\"%-6d %-16s %4d %3d \" %\n  File \"/usr/lib/python3/dist-packages/bcc/utils.py\", line 57, in printb\n    buf.write(s)\nKeyboardInterrupt:",
  "stdout_tail": "1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-197.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-198.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-199.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-200.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-201.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-202.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-203.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-204.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-205.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-206.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-207.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-208.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-209.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-210.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-211.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-212.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-213.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-214.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-215.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-216.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-217.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-218.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-219.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-220.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26/open-221.dat\n1731   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/loopback-open-storm-2k4ysy26\n24076  bpftool             3   0 /etc/ld.so.cache\n24076  bpftool             3   0 /lib/x86_64-linux-gnu/libelf.so.1\n24076  bpftool             3   0 /lib/x86_64-linux-gnu/libcrypto.so.3\n24076  bpftool             3   0 /lib/x86_64-linux-gnu/libz.so.1\n24076  bpftool             3   0 /lib/x86_64-linux-gnu/libcap.so.2\n24076  bpftool             3   0 /lib/x86_64-linux-gnu/libc.so.6\n24076  bpftool             3   0 /lib/x86_64-linux-gnu/libzstd.so.1\n24076  bpftool             4   0 24076  bpftool             4   0 /proc/self/fdinfo/3\n24076  bpftool             4   0 /proc/self/fdinfo/3\n24076  bpftool             4   0 /proc/self/fdinfo/3\n24076  bpftool             4   0 /proc/self/fdinfo/3\n24046  opensnoop-bpfcc    15   0 /usr/lib/python3/dist-packages/bcc/table.py\n24046  opensnoop-bpfcc    15   0 /usr/sbin/opensnoop-bpfcc\n24046  opensnoop-bpfcc    15   0 /usr/lib/python3/dist-packages/bcc/utils.py"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1421": {
        "avg_ns_per_run": 39.67125476068681,
        "bytes_jited": 203,
        "bytes_xlated": 344,
        "id": 1421,
        "name": "cap_capable",
        "run_cnt_delta": 2766145,
        "run_time_ns_delta": 109736443,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 2416.041508001071
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
        "avg_ns_per_run": 40.62743185762265,
        "bytes_jited": 206,
        "bytes_xlated": 344,
        "id": 1421,
        "name": "cap_capable",
        "run_cnt_delta": 2779768,
        "run_time_ns_delta": 112934835,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 2430.0216676882196
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
  "stderr_tail": "  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-u0t_mc83/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-u0t_mc83/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\nIn file included from include/linux/security.h:9:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "00:47:08  65534  32072  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32073  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32089  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32090  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32091  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32116  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32096  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32097  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32098  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32099  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32100  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32101  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32102  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32104  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32103  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32105  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32106  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32107  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32108  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32109  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32110  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32111  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32112  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32113  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32114  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32118  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32115  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32117  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:08  65534  32119  stress-ng-exec   8    CAP_SETPCAP          1\n00:47:09  0      32130  bpftool          21   CAP_SYS_ADMIN        1\n00:47:09  0      32130  bpftool          21   CAP_SYS_ADMIN        1\n00:47:09  0      32130  bpftool          39   CAP_BPF              1\n00:47:09  0      32130  bpftool          21   CAP_SYS_ADMIN        1\n00:47:09  0      32130  bpftool          21   CAP_SYS_ADMIN        1\n00:47:09  0      32130  bpftool          39   CAP_BPF              1\n00:47:09  0      32130  bpftool          39   CAP_BPF              1\n00:47:09  0      32130  bpftool          39   CAP_BPF              1\n00:47:09  0      32130  bpftool          39   CAP_BPF              1\n00:47:09  0      32130  bpftool          21   CAP_SYS_ADMIN        1\n00:47:09  0      32130  bpftool          21   CAP_SYS_ADMIN        1"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1425": {
        "avg_ns_per_run": null,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1425,
        "name": "vfs_create",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1426": {
        "avg_ns_per_run": null,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1426,
        "name": "kfunc__vmlinux__vfs_fsync_range",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1427": {
        "avg_ns_per_run": 91.85512820512821,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1427,
        "name": "vfs_open",
        "run_cnt_delta": 780,
        "run_time_ns_delta": 71647,
        "type": "tracing"
      },
      "1428": {
        "avg_ns_per_run": 38.47712418300654,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1428,
        "name": "vfs_read",
        "run_cnt_delta": 1530,
        "run_time_ns_delta": 58870,
        "type": "tracing"
      },
      "1429": {
        "avg_ns_per_run": 39.66622691292876,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1429,
        "name": "vfs_write",
        "run_cnt_delta": 758,
        "run_time_ns_delta": 30067,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 75.24232142594572
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
        "avg_ns_per_run": null,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1425,
        "name": "vfs_create",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1426": {
        "avg_ns_per_run": null,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1426,
        "name": "vfs_fsync_range",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1427": {
        "avg_ns_per_run": 85.4040404040404,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1427,
        "name": "vfs_open",
        "run_cnt_delta": 792,
        "run_time_ns_delta": 67640,
        "type": "tracing"
      },
      "1428": {
        "avg_ns_per_run": 39.384565916398714,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1428,
        "name": "vfs_read",
        "run_cnt_delta": 1555,
        "run_time_ns_delta": 61243,
        "type": "tracing"
      },
      "1429": {
        "avg_ns_per_run": 38.503242542153046,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1429,
        "name": "vfs_write",
        "run_cnt_delta": 771,
        "run_time_ns_delta": 29686,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 76.44328354025531
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-k5xmvz9y/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-k5xmvz9y/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "TIME         READ/s  WRITE/s  FSYNC/s   OPEN/s CREATE/s\n00:47:11:      1487        5        0      132        0\n00:47:12:       100        5        0      130        0\n00:47:13:       165       65        0      115        0\n00:47:14:       153       76        0       76        0\n00:47:15:       150       76        0       75        0\n00:47:16:       152       77        0       75        0\n00:47:17:       154       77        0       77        0\n00:47:18:       147       74        0       73        0\n00:47:19:       152       76        0       76        0\n00:47:20:       150       75        0       75        0\n00:47:21:       152       76        0       76        0\n00:47:22:       151       76        0       75        0\n00:47:23:       142       43        0      114        0\n00:47:24:       157       79        0       78        0\n00:47:25:       159       79        0       80        0\n00:47:26:       158       79        0       78        0\n00:47:27:       152       77        0       76        0\n00:47:28:       156       78        0       78        0\n00:47:29:       155       78        0       77        0\n00:47:30:       148       74        0       74        0\n00:47:31:       149       75        0       74        0\n00:47:32:       151       76        0       75        0\n00:47:33:       112       46        0       73        0"
}
```

## tcpconnect

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1432": {
        "avg_ns_per_run": 633.1351091912647,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1432,
        "name": "trace_connect_entry",
        "run_cnt_delta": 4167,
        "run_time_ns_delta": 2638274,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 4002.806142034549,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1433,
        "name": "trace_connect_v4_return",
        "run_cnt_delta": 2084,
        "run_time_ns_delta": 8341848,
        "type": "kprobe"
      },
      "1434": {
        "avg_ns_per_run": 3995.678828612578,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1434,
        "name": "trace_connect_v6_return",
        "run_cnt_delta": 2083,
        "run_time_ns_delta": 8322999,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 416.64095893463644
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
        "avg_ns_per_run": 673.446249033256,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1432,
        "name": "trace_connect_e",
        "run_cnt_delta": 3879,
        "run_time_ns_delta": 2612298,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 4109.980412371134,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1433,
        "name": "trace_connect_v",
        "run_cnt_delta": 1940,
        "run_time_ns_delta": 7973362,
        "type": "kprobe"
      },
      "1434": {
        "avg_ns_per_run": 4058.7225373904075,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1434,
        "name": "trace_connect_v",
        "run_cnt_delta": 1939,
        "run_time_ns_delta": 7869863,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 387.83721757054633
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
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-yx672e3i/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:16:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "15801   curl         6  ::1              ::1              33599\n15803   curl         4  127.0.0.1        127.0.0.1        39353\n15805   curl         6  ::1              ::1              33599\n15807   curl         4  127.0.0.1        127.0.0.1        39353\n15809   curl         6  ::1              ::1              33599\n15811   curl         4  127.0.0.1        127.0.0.1        39353\n15813   curl         6  ::1              ::1              33599\n15815   curl         4  127.0.0.1        127.0.0.1        39353\n15817   curl         6  ::1              ::1              33599\n15819   curl         4  127.0.0.1        127.0.0.1        39353\n15821   curl         6  ::1              ::1              33599\n15823   curl         4  127.0.0.1        127.0.0.1        39353\n15825   curl         6  ::1              ::1              33599\n15827   curl         4  127.0.0.1        127.0.0.1        39353\n15829   curl         6  ::1              ::1              33599\n15831   curl         4  127.0.0.1        127.0.0.1        39353\n15833   curl         6  ::1              ::1              33599\n15835   curl         4  127.0.0.1        127.0.0.1        39353\n15837   curl         6  ::1              ::1              33599\n15839   curl         4  127.0.0.1        127.0.0.1        39353\n15841   curl         6  ::1              ::1              33599\n15843   curl         4  127.0.0.1        127.0.0.1        39353\n15845   curl         6  ::1              ::1              33599\n15847   curl         4  127.0.0.1        127.0.0.1        39353\n15849   curl         6  ::1              ::1              33599\n15851   curl         4  127.0.0.1        127.0.0.1        39353\n15853   curl         6  ::1              ::1              33599\n15855   curl         4  127.0.0.1        127.0.0.1        39353\n15857   curl         6  ::1              ::1              33599\n15859   curl         4  127.0.0.1        127.0.0.1        39353\n15861   curl         6  ::1              ::1              33599\n15863   curl         4  127.0.0.1        127.0.0.1        39353\n15865   curl         6  ::1              ::1              33599\n15867   curl         4  127.0.0.1        127.0.0.1        39353\n15869   curl         6  ::1              ::1              33599\n15871   curl         4  127.0.0.1        127.0.0.1        39353\n15873   curl         6  ::1              ::1              33599\n15875   curl         4  127.0.0.1        127.0.0.1        39353\n15877   curl         6  ::1              ::1              33599\n15879   curl         4  127.0.0.1        127.0.0.1        39353"
}
```

## bindsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1437": {
        "avg_ns_per_run": 55.826296095922295,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1437,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1987025,
        "run_time_ns_delta": 110928246,
        "type": "kprobe"
      },
      "1438": {
        "avg_ns_per_run": 816.9349631056665,
        "bytes_jited": 721,
        "bytes_xlated": 1160,
        "id": 1438,
        "name": "bindsnoop_v4_return",
        "run_cnt_delta": 993513,
        "run_time_ns_delta": 811635506,
        "type": "kprobe"
      },
      "1439": {
        "avg_ns_per_run": 787.2836805192086,
        "bytes_jited": 742,
        "bytes_xlated": 1184,
        "id": 1439,
        "name": "bindsnoop_v6_return",
        "run_cnt_delta": 993512,
        "run_time_ns_delta": 782175784,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 198702.35125142068
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
        "avg_ns_per_run": 62.63655357760517,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1437,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1997747,
        "run_time_ns_delta": 125131987,
        "type": "kprobe"
      },
      "1438": {
        "avg_ns_per_run": 825.9364974961807,
        "bytes_jited": 719,
        "bytes_xlated": 1160,
        "id": 1438,
        "name": "bindsnoop_v4_re",
        "run_cnt_delta": 998874,
        "run_time_ns_delta": 825006493,
        "type": "kprobe"
      },
      "1439": {
        "avg_ns_per_run": 778.0087308396563,
        "bytes_jited": 740,
        "bytes_xlated": 1184,
        "id": 1439,
        "name": "bindsnoop_v6_re",
        "run_cnt_delta": 998873,
        "run_time_ns_delta": 777131915,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 199774.59689633074
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
  "output_chars": 12437,
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
  "stderr_tail": "In file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.5bc0b3e0/bcc-python-i7vohciu/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:18:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.\nPossibly lost 44 samples",
  "stdout_tail": "    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0\n    1731 python3      IP   ::1             16256 ..NR.  0\n    1731 python3      IP   127.0.0.1        4992 ..NR.  0"
}
```

