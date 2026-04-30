# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-26T05:23:42.799524+00:00`
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
        "avg_ns_per_run": 570.0187335280291,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1391,
        "name": "tracepoint__sock__inet_sock_set_state",
        "run_cnt_delta": 42117,
        "run_time_ns_delta": 24007479,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 383.23087952048894
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
        "avg_ns_per_run": 612.9545613509192,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1391,
        "name": "sock__inet_sock",
        "run_cnt_delta": 40032,
        "run_time_ns_delta": 24537797,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 364.1965442482531
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
  "stderr_tail": "In file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-xj61rsre/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-xj61rsre/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/tcp.h:7:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "24097 curl       127.0.0.1       40485 127.0.0.1       59130     0     0 0.18\n24097 curl       127.0.0.1       59130 127.0.0.1       40485     0     0 0.19\n24099 curl       ::1             34353 ::1             50478     0     0 0.23\n24099 curl       ::1             50478 ::1             34353     0     0 0.24\n24101 curl       127.0.0.1       40485 127.0.0.1       59136     0     0 0.29\n24101 curl       127.0.0.1       59136 127.0.0.1       40485     0     0 0.30\n24103 curl       ::1             34353 ::1             50486     0     0 0.32\n24103 curl       ::1             50486 ::1             34353     0     0 0.33\n24105 curl       127.0.0.1       40485 127.0.0.1       59146     0     0 0.39\n24105 curl       127.0.0.1       59146 127.0.0.1       40485     0     0 0.40\n24107 curl       ::1             34353 ::1             50496     0     0 0.31\n24107 curl       ::1             50496 ::1             34353     0     0 0.32\n24109 curl       127.0.0.1       40485 127.0.0.1       59148     0     0 0.26\n24109 curl       127.0.0.1       59148 127.0.0.1       40485     0     0 0.28\n24111 curl       ::1             34353 ::1             50508     0     0 0.30\n24111 curl       ::1             50508 ::1             34353     0     0 0.31\n24113 curl       127.0.0.1       40485 127.0.0.1       59152     0     0 0.33\n24113 curl       127.0.0.1       59152 127.0.0.1       40485     0     0 0.34\n24115 curl       ::1             34353 ::1             50518     0     0 0.40\n24115 curl       ::1             50518 ::1             34353     0     0 0.41\n24117 curl       127.0.0.1       40485 127.0.0.1       59166     0     0 0.26\n24117 curl       127.0.0.1       59166 127.0.0.1       40485     0     0 0.28\n24119 curl       ::1             34353 ::1             50532     0     0 0.40\n24119 curl       ::1             50532 ::1             34353     0     0 0.42\n24121 curl       127.0.0.1       40485 127.0.0.1       59182     0     0 0.29\n24121 curl       127.0.0.1       59182 127.0.0.1       40485     0     0 0.30\n24123 curl       ::1             34353 ::1             50538     0     0 0.35\n24123 curl       ::1             50538 ::1             34353     0     0 0.36\n24125 curl       127.0.0.1       40485 127.0.0.1       59190     0     0 0.30\n24125 curl       127.0.0.1       59190 127.0.0.1       40485     0     0 0.31\n24127 curl       ::1             34353 ::1             50554     0     0 0.40\n24127 curl       ::1             50554 ::1             34353     0     0 0.41\n24129 curl       127.0.0.1       40485 127.0.0.1       59198     0     0 0.28\n24129 curl       127.0.0.1       59198 127.0.0.1       40485     0     0 0.30\n24131 curl       ::1             34353 ::1             50570     0     0 0.27\n24131 curl       ::1             50570 ::1             34353     0     0 0.28\n24133 curl       127.0.0.1       40485 127.0.0.1       59200     0     0 0.16\n24133 curl       127.0.0.1       59200 127.0.0.1       40485     0     0 0.17\n24135 curl       ::1             34353 ::1             50582     0     0 0.25\n24135 curl       ::1             50582 ::1             34353     0     0 0.27"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1394": {
        "avg_ns_per_run": 74.3701803482587,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1394,
        "name": "trace_pid_start_tp",
        "run_cnt_delta": 8232960,
        "run_time_ns_delta": 612286720,
        "type": "tracepoint"
      },
      "1395": {
        "avg_ns_per_run": 103.08149559818096,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1395,
        "name": "trace_req_start",
        "run_cnt_delta": 8232960,
        "run_time_ns_delta": 848665830,
        "type": "kprobe"
      },
      "1396": {
        "avg_ns_per_run": 288.27133898379196,
        "bytes_jited": 550,
        "bytes_xlated": 856,
        "id": 1396,
        "name": "trace_req_completion_tp",
        "run_cnt_delta": 8232960,
        "run_time_ns_delta": 2373326403,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 822887.5581969979
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
        "avg_ns_per_run": 71.18240644722204,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1394,
        "name": "trace_pid_start",
        "run_cnt_delta": 8372226,
        "run_time_ns_delta": 595955194,
        "type": "tracepoint"
      },
      "1395": {
        "avg_ns_per_run": 99.72615485388118,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1395,
        "name": "trace_req_start",
        "run_cnt_delta": 8372228,
        "run_time_ns_delta": 834930106,
        "type": "kprobe"
      },
      "1396": {
        "avg_ns_per_run": 285.715338770595,
        "bytes_jited": 548,
        "bytes_xlated": 848,
        "id": 1396,
        "name": "trace_req_compl",
        "run_cnt_delta": 8372229,
        "run_time_ns_delta": 2392074245,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 836890.5760667692
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
  "returncode": 0,
  "stderr_tail": "Possibly lost 11 samples\nPossibly lost 25 samples\nPossibly lost 13 samples\nPossibly lost 13 samples\nPossibly lost 13 samples\nPossibly lost 26 samples\nPossibly lost 13 samples\nPossibly lost 14 samples\nPossibly lost 13 samples\nPossibly lost 28 samples\nPossibly lost 15 samples\nPossibly lost 13 samples\nPossibly lost 31 samples\nPossibly lost 12 samples\nPossibly lost 12 samples\nPossibly lost 12 samples\nPossibly lost 27 samples\nPossibly lost 12 samples\nPossibly lost 14 samples\nPossibly lost 14 samples\nPossibly lost 27 samples\nPossibly lost 12 samples\nPossibly lost 13 samples\nPossibly lost 26 samples\nPossibly lost 13 samples\nPossibly lost 14 samples\nPossibly lost 14 samples\nPossibly lost 26 samples\nPossibly lost 13 samples\nPossibly lost 13 samples\nPossibly lost 13 samples\nPossibly lost 50 samples\nPossibly lost 13 samples\nPossibly lost 14 samples\nPossibly lost 31 samples\nPossibly lost 12 samples\nPossibly lost 13 samples\nPossibly lost 12 samples\nPossibly lost 27 samples\nPossibly lost 10 samples",
  "stdout_tail": "20.226675                  28228   nullb0    R 32448      4096      0.00\n20.226676                  28228   nullb0    R 32456      4096      0.00\n20.226677                  28228   nullb0    R 32464      4096      0.00\n20.226678                  28228   nullb0    R 32472      4096      0.00\n20.226679                  28228   nullb0    R 32480      4096      0.00\n20.226680                  28228   nullb0    R 32488      4096      0.00\n20.226681                  28228   nullb0    R 32496      4096      0.00\n20.226682                  28228   nullb0    R 32504      4096      0.00\n20.226684                  28228   nullb0    R 32512      4096      0.00\n20.226685                  28228   nullb0    R 32520      4096      0.00\n20.226686                  28228   nullb0    R 32528      4096      0.00\n20.226687                  28228   nullb0    R 32536      4096      0.00\n20.226688                  28228   nullb0    R 32544      4096      0.00\n20.226689                  28228   nullb0    R 32552      4096      0.00\n20.226690                  28228   nullb0    R 32560      4096      0.00\n20.226691                  28228   nullb0    R 32568      4096      0.00\n20.226693                  28228   nullb0    R 32576      4096      0.00\n20.226694                  28228   nullb0    R 32584      4096      0.00\n20.226695                  28228   nullb0    R 32592      4096      0.00\n20.226696                  28228   nullb0    R 32600      4096      0.00\n20.226697                  28228   nullb0    R 32608      4096      0.00\n20.226698                  28228   nullb0    R 32616      4096      0.00\n20.226699                  28228   nullb0    R 32624      4096      0.00\n20.226700                  28228   nullb0    R 32632      4096      0.00\n20.226701                  28228   nullb0    R 32640      4096      0.00\n20.226703                  28228   nullb0    R 32648      4096      0.00\n20.226704                  28228   nullb0    R 32656      4096      0.00\n20.226705                  28228   nullb0    R 32664      4096      0.00\n20.226706                  28228   nullb0    R 32672      4096      0.00\n20.226707                  28228   nullb0    R 32680      4096      0.00\n20.226708                  28228   nullb0    R 32688      4096      0.00\n20.226709                  28228   nullb0    R 32696      4096      0.00\n20.226710                  28228   nullb0    R 32704      4096      0.00\n20.226712                  28228   nullb0    R 32712      4096      0.00\n20.226713                  28228   nullb0    R 32720      4096      0.00\n20.226714                  28228   nullb0    R 32728      4096      0.00\n20.226715                  28228   nullb0    R 32736      4096      0.00\n20.226716                  28228   nullb0    R 32744      4096      0.00\n20.226717                  28228   nullb0    R 32752      4096      0.00\n20.226718                  28228   nullb0    R 32760      4096      0.00"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1401": {
        "avg_ns_per_run": 171.3345398729526,
        "bytes_jited": 662,
        "bytes_xlated": 1168,
        "id": 1401,
        "name": "sched_switch",
        "run_cnt_delta": 1566187,
        "run_time_ns_delta": 268341929,
        "type": "raw_tracepoint"
      },
      "1402": {
        "avg_ns_per_run": 113.7470348123561,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1402,
        "name": "sched_wakeup",
        "run_cnt_delta": 826086,
        "run_time_ns_delta": 93964833,
        "type": "raw_tracepoint"
      },
      "1403": {
        "avg_ns_per_run": 241.73530039581135,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1403,
        "name": "raw_tracepoint__sched_wakeup_new",
        "run_cnt_delta": 163967,
        "run_time_ns_delta": 39636612,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 63.768140161812035
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
        "avg_ns_per_run": 168.82263148209296,
        "bytes_jited": 645,
        "bytes_xlated": 1136,
        "id": 1401,
        "name": "sched_switch",
        "run_cnt_delta": 1532414,
        "run_time_ns_delta": 258706164,
        "type": "raw_tracepoint"
      },
      "1402": {
        "avg_ns_per_run": 115.58548643399446,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1402,
        "name": "sched_wakeup",
        "run_cnt_delta": 798577,
        "run_time_ns_delta": 92303911,
        "type": "raw_tracepoint"
      },
      "1403": {
        "avg_ns_per_run": 242.05853058677417,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1403,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 163453,
        "run_time_ns_delta": 39565193,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 63.55214904489915
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
  "stderr_tail": "In file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-kiyvl82x/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-kiyvl82x/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:6:\nIn file included from include/linux/pid_namespace.h:7:\nIn file included from include/linux/mm.h:1118:\nIn file included from include/linux/huge_mm.h:7:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "             8388608 -> 16777215             : 5087     |                    |\n            16777216 -> 33554431             : 0        |                    |\n            33554432 -> 67108863             : 0        |                    |\n            67108864 -> 134217727            : 0        |                    |\n           134217728 -> 268435455            : 0        |                    |\n           268435456 -> 536870911            : 4583     |                    |\n           536870912 -> 1073741823           : 4368     |                    |\n          1073741824 -> 2147483647           : 4256     |                    |\n          2147483648 -> 4294967295           : 4153     |                    |\n          4294967296 -> 8589934591           : 0        |                    |\n          8589934592 -> 17179869183          : 0        |                    |\n         17179869184 -> 34359738367          : 0        |                    |\n         34359738368 -> 68719476735          : 0        |                    |\n         68719476736 -> 137438953471         : 3416     |                    |\n        137438953472 -> 274877906943         : 3356     |                    |\n        274877906944 -> 549755813887         : 3329     |                    |\n        549755813888 -> 1099511627775        : 3273     |                    |\n       1099511627776 -> 2199023255551        : 0        |                    |\n       2199023255552 -> 4398046511103        : 0        |                    |\n       4398046511104 -> 8796093022207        : 0        |                    |\n       8796093022208 -> 17592186044415       : 0        |                    |\n      17592186044416 -> 35184372088831       : 2932     |                    |\n      35184372088832 -> 70368744177663       : 2831     |                    |\n      70368744177664 -> 140737488355327      : 2828     |                    |\n     140737488355328 -> 281474976710655      : 2708     |                    |\n     281474976710656 -> 562949953421311      : 0        |                    |\n     562949953421312 -> 1125899906842623     : 0        |                    |\n    1125899906842624 -> 2251799813685247     : 0        |                    |\n    2251799813685248 -> 4503599627370495     : 0        |                    |\n    4503599627370496 -> 9007199254740991     : 2655     |                    |\n    9007199254740992 -> 18014398509481983    : 2574     |                    |\n   18014398509481984 -> 36028797018963967    : 2462     |                    |\n   36028797018963968 -> 72057594037927935    : 2482     |                    |\n   72057594037927936 -> 144115188075855871   : 0        |                    |\n  144115188075855872 -> 288230376151711743   : 0        |                    |\n  288230376151711744 -> 576460752303423487   : 0        |                    |\n  576460752303423488 -> 1152921504606846975  : 0        |                    |\n 1152921504606846976 -> 2305843009213693951  : 2466     |                    |\n 2305843009213693952 -> 4611686018427387903  : 2440     |                    |\n 4611686018427387904 -> 9223372036854775807  : 2371     |                    |"
}
```

## syscount

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1408": {
        "avg_ns_per_run": 72.34387339242956,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1408,
        "name": "tracepoint__raw_syscalls__sys_enter",
        "run_cnt_delta": 63061,
        "run_time_ns_delta": 4562077,
        "type": "tracepoint"
      },
      "1409": {
        "avg_ns_per_run": 85.46380488733132,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1409,
        "name": "tracepoint__raw_syscalls__sys_exit",
        "run_cnt_delta": 63061,
        "run_time_ns_delta": 5389433,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1116.3242726917256
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
        "avg_ns_per_run": 71.74203448382221,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1408,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 64842,
        "run_time_ns_delta": 4651897,
        "type": "tracepoint"
      },
      "1409": {
        "avg_ns_per_run": 79.71186885043645,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1409,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 64842,
        "run_time_ns_delta": 5168677,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1143.2941765767055
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-itn7x94x/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-itn7x94x/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "nanosleep                     2        20448.013\nioctl                      1254          199.814\nlseek                      1254          167.692\nfutex                        19      2192145.191\n[05:21:06]\nSYSCALL                   COUNT        TIME (us)\nclock_nanosleep              11      2000672.052\nepoll_pwait                  15      1111289.854\nread                          2      1000383.457\nopenat                     1179       751878.545\nclose                      1178       148859.269\nfstat                      1179        96557.854\nnanosleep                     3        30419.558\nioctl                      1179          196.821\nlseek                      1179          164.093\nfutex                         9      2192075.542\n[05:21:07]\nSYSCALL                   COUNT        TIME (us)\nclock_nanosleep              11      2000666.780\nepoll_pwait                  15      1111287.206\nread                          9      1000624.452\nopenat                     1174       749284.231\nclose                      1175       149374.546\nfstat                      1174        97430.147\nnanosleep                     3        30525.653\nioctl                      1174          206.860\nbpf                         449          196.499\nclock_nanosleep              11      2000589.901\n[05:21:08]\nSYSCALL                   COUNT        TIME (us)\nfutex                        17      1461561.124\nread                         25      1000655.212\nepoll_pwait                  10       740854.423\nopenat                     1011       694667.162\nclose                      1027       134001.288\nfstat                      1016        98804.231\nunlinkat                    256        65079.502\nnanosleep                     2        20148.049\ngetdents64                    2         1713.760\nDetaching..."
}
```

## execsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1412": {
        "avg_ns_per_run": 1273.2819723077778,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1412,
        "name": "syscall__execve",
        "run_cnt_delta": 36039,
        "run_time_ns_delta": 45887809,
        "type": "kprobe"
      },
      "1413": {
        "avg_ns_per_run": 849.8210272205112,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1413,
        "name": "do_ret_sys_execve",
        "run_cnt_delta": 36039,
        "run_time_ns_delta": 30626700,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1801.8417833928793
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
        "avg_ns_per_run": 1272.536513308087,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1412,
        "name": "syscall__execve",
        "run_cnt_delta": 37233,
        "run_time_ns_delta": 47380352,
        "type": "kprobe"
      },
      "1413": {
        "avg_ns_per_run": 857.7318239196412,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1413,
        "name": "do_ret_sys_exec",
        "run_cnt_delta": 37233,
        "run_time_ns_delta": 31935929,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1861.5448282790303
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
  "stderr_tail": "<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-au3kynrv/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-au3kynrv/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "05:21:32 65534 true             4237    1739      0 /bin/true\n05:21:32 65534 true             4238    1739      0 /bin/true\n05:21:32 65534 true             4239    1739      0 /bin/true\n05:21:32 65534 true             4240    1739      0 /bin/true\n05:21:32 65534 true             4241    1739      0 /bin/true\n05:21:32 65534 true             4242    1739      0 /bin/true\n05:21:32 65534 true             4243    1739      0 /bin/true\n05:21:32 65534 true             4244    1739      0 /bin/true\n05:21:32 65534 true             4245    1739      0 /bin/true\n05:21:32 65534 true             4246    1739      0 /bin/true\n05:21:33 65534 true             4247    1739      0 /bin/true\n05:21:33 65534 true             4248    1739      0 /bin/true\n05:21:33 65534 true             4249    1739      0 /bin/true\n05:21:33 65534 true             4250    1739      0 /bin/true\n05:21:33 65534 true             4251    1739      0 /bin/true\n05:21:33 65534 true             4252    1739      0 /bin/true\n05:21:33 65534 true             4253    1739      0 /bin/true\n05:21:33 65534 true             4254    1739      0 /bin/true\n05:21:33 65534 true             4255    1739      0 /bin/true\n05:21:33 65534 true             4256    1739      0 /bin/true\n05:21:33 65534 true             4257    1739      0 /bin/true\n05:21:33 65534 true             4258    1739      0 /bin/true\n05:21:33 65534 true             4259    1739      0 /bin/true\n05:21:33 65534 true             4260    1739      0 /bin/true\n05:21:33 65534 true             4261    1739      0 /bin/true\n05:21:33 65534 true             4262    1739      0 /bin/true\n05:21:33 65534 true             4263    1739      0 /bin/true\n05:21:33 65534 true             4264    1739      0 /bin/true\n05:21:33 65534 true             4265    1739      0 /bin/true\n05:21:33 65534 true             4266    1739      0 /bin/true\n05:21:33 65534 true             4267    1739      0 /bin/true\n05:21:33 65534 true             4268    1739      0 /bin/true\n05:21:33 65534 true             4269    1739      0 /bin/true\n05:21:33 65534 true             4270    1739      0 /bin/true\n05:21:33 65534 true             4271    1739      0 /bin/true\n05:21:33 65534 true             4272    1739      0 /bin/true\n05:21:33 65534 true             4273    1739      0 /bin/true\n05:21:33 65534 true             4274    1739      0 /bin/true\n05:21:33 65534 true             4275    1739      0 /bin/true\n05:21:33 65534 true             4276    1739      0 /bin/true"
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
        "avg_ns_per_run": 2545.320593599735,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1417,
        "name": "kretfunc__vmlinux____x64_sys_openat",
        "run_cnt_delta": 12062,
        "run_time_ns_delta": 30701657,
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
    "throughput": 1179.1778986048803
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
        "avg_ns_per_run": 1708.2384566729918,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1417,
        "name": "__x64_sys_opena",
        "run_cnt_delta": 11067,
        "run_time_ns_delta": 18905075,
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
    "throughput": 1079.7538633051424
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-chhbi0jd/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-chhbi0jd/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-19.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-20.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-21.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-22.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-23.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-24.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-25.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-26.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-27.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-28.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-29.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-30.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-31.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-32.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-33.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-34.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-35.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-36.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-37.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-38.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-39.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-40.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-41.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-42.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-43.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-44.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8/open-45.dat\n1739   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/loopback-open-storm-zh58tta8\n4310   bpftool             3   0 /etc/ld.so.cache\n4310   bpftool             3   0 /lib/x86_64-linux-gnu/libelf.so.1\n4310   bpftool             3   0 /lib/x86_64-linux-gnu/libcrypto.so.3\n4310   bpftool             3   0 /lib/x86_64-linux-gnu/libz.so.1\n4310   bpftool             3   0 /lib/x86_64-linux-gnu/libcap.so.2\n4310   bpftool             3   0 /lib/x86_64-linux-gnu/libc.so.6\n4310   bpftool             3   0 /lib/x86_64-linux-gnu/libzstd.so.1\n4310   bpftool             4   0 /etc/localtime\n4310   bpftool             4   0 /proc/self/fdinfo/3\n4310   bpftool             4   0 /proc/self/fdinfo/3\n4310   bpftool             4   0 /proc/self/fdinfo/3\n4310   bpftool             4   0 /proc/self/fdinfo/3"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1421": {
        "avg_ns_per_run": 40.07743375510225,
        "bytes_jited": 203,
        "bytes_xlated": 344,
        "id": 1421,
        "name": "cap_capable",
        "run_cnt_delta": 2757118,
        "run_time_ns_delta": 110498214,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 2413.255248248085
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
        "avg_ns_per_run": 41.156507609849974,
        "bytes_jited": 206,
        "bytes_xlated": 344,
        "id": 1421,
        "name": "cap_capable",
        "run_cnt_delta": 2726992,
        "run_time_ns_delta": 112233467,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 2375.435331450307
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
  "output_chars": 3705,
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
  "stderr_tail": "  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-g9576y_o/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-g9576y_o/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\nIn file included from include/linux/security.h:9:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "05:22:23  65534  11160  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11151  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11161  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11166  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11167  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11152  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11168  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11153  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11179  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11181  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11162  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11163  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11183  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11194  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11184  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11185  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11186  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11137  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11195  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11189  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11192  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11196  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11193  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11197  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11198  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11199  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11200  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11201  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  65534  11202  stress-ng-exec   8    CAP_SETPCAP          1\n05:22:23  0      11243  bpftool          21   CAP_SYS_ADMIN        1\n05:22:23  0      11243  bpftool          21   CAP_SYS_ADMIN        1\n05:22:23  0      11243  bpftool          39   CAP_BPF              1\n05:22:23  0      11243  bpftool          21   CAP_SYS_ADMIN        1\n05:22:23  0      11243  bpftool          21   CAP_SYS_ADMIN        1\n05:22:23  0      11243  bpftool          39   CAP_BPF              1\n05:22:23  0      11243  bpftool          39   CAP_BPF              1\n05:22:23  0      11243  bpftool          39   CAP_BPF              1\n05:22:23  0      11243  bpftool          39   CAP_BPF              1\n05:22:23  0      11243  bpftool          21   CAP_SYS_ADMIN        1\n05:22:23  0      11243  bpftool          21   CAP_SYS_ADMIN        1"
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
        "avg_ns_per_run": 71.17961165048544,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1427,
        "name": "vfs_open",
        "run_cnt_delta": 824,
        "run_time_ns_delta": 58652,
        "type": "tracing"
      },
      "1428": {
        "avg_ns_per_run": 40.452748610253245,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1428,
        "name": "vfs_read",
        "run_cnt_delta": 1619,
        "run_time_ns_delta": 65493,
        "type": "tracing"
      },
      "1429": {
        "avg_ns_per_run": 49.60772104607721,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1429,
        "name": "vfs_write",
        "run_cnt_delta": 803,
        "run_time_ns_delta": 39835,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 79.5946398509194
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
        "avg_ns_per_run": 82.44211822660098,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1427,
        "name": "vfs_open",
        "run_cnt_delta": 812,
        "run_time_ns_delta": 66943,
        "type": "tracing"
      },
      "1428": {
        "avg_ns_per_run": 43.87781954887218,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1428,
        "name": "vfs_read",
        "run_cnt_delta": 1596,
        "run_time_ns_delta": 70029,
        "type": "tracing"
      },
      "1429": {
        "avg_ns_per_run": 55.58080808080808,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1429,
        "name": "vfs_write",
        "run_cnt_delta": 792,
        "run_time_ns_delta": 44020,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 78.48380591048584
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-fcz01bf5/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-fcz01bf5/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "TIME         READ/s  WRITE/s  FSYNC/s   OPEN/s CREATE/s\n05:22:26:      1487        5        0      132        0\n05:22:27:       100        5        0      130        0\n05:22:28:       171       69        0      117        0\n05:22:29:       172       86        0       86        0\n05:22:30:       163       83        0       80        0\n05:22:31:       155       78        0       77        0\n05:22:32:       158       79        0       79        0\n05:22:33:       146       73        0       73        0\n05:22:34:       158       79        0       79        0\n05:22:35:       164       82        0       82        0\n05:22:36:       166       82        0       83        0\n05:22:37:       160       81        0       80        0\n05:22:38:       143       44        0      114        0\n05:22:39:       164       83        0       81        0\n05:22:40:       166       83        0       83        0\n05:22:41:       154       77        0       77        0\n05:22:42:       158       79        0       79        0\n05:22:43:       153       77        0       76        0\n05:22:44:       155       78        0       77        0\n05:22:45:       152       76        0       77        0\n05:22:46:       156       78        0       77        0\n05:22:47:       158       78        0       79        0\n05:22:48:       123       53        0       78        0"
}
```

## tcpconnect

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1432": {
        "avg_ns_per_run": 668.0113576333862,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1432,
        "name": "trace_connect_entry",
        "run_cnt_delta": 3786,
        "run_time_ns_delta": 2529091,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 4264.700475435816,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1433,
        "name": "trace_connect_v4_return",
        "run_cnt_delta": 1893,
        "run_time_ns_delta": 8073078,
        "type": "kprobe"
      },
      "1434": {
        "avg_ns_per_run": 4247.244057052298,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1434,
        "name": "trace_connect_v6_return",
        "run_cnt_delta": 1893,
        "run_time_ns_delta": 8040033,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 378.59588360267725
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
        "avg_ns_per_run": 695.5717427157779,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1432,
        "name": "trace_connect_e",
        "run_cnt_delta": 3638,
        "run_time_ns_delta": 2530490,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 4197.745464540956,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1433,
        "name": "trace_connect_v",
        "run_cnt_delta": 1819,
        "run_time_ns_delta": 7635699,
        "type": "kprobe"
      },
      "1434": {
        "avg_ns_per_run": 4327.29851566795,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1434,
        "name": "trace_connect_v",
        "run_cnt_delta": 1819,
        "run_time_ns_delta": 7871356,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 363.79670869480424
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
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-qvhyj90w/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:16:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "26082   curl         4  127.0.0.1        127.0.0.1        35983\n26084   curl         6  ::1              ::1              38197\n26086   curl         4  127.0.0.1        127.0.0.1        35983\n26088   curl         6  ::1              ::1              38197\n26090   curl         4  127.0.0.1        127.0.0.1        35983\n26092   curl         6  ::1              ::1              38197\n26094   curl         4  127.0.0.1        127.0.0.1        35983\n26096   curl         6  ::1              ::1              38197\n26098   curl         4  127.0.0.1        127.0.0.1        35983\n26100   curl         6  ::1              ::1              38197\n26102   curl         4  127.0.0.1        127.0.0.1        35983\n26104   curl         6  ::1              ::1              38197\n26106   curl         4  127.0.0.1        127.0.0.1        35983\n26108   curl         6  ::1              ::1              38197\n26110   curl         4  127.0.0.1        127.0.0.1        35983\n26112   curl         6  ::1              ::1              38197\n26114   curl         4  127.0.0.1        127.0.0.1        35983\n26116   curl         6  ::1              ::1              38197\n26118   curl         4  127.0.0.1        127.0.0.1        35983\n26120   curl         6  ::1              ::1              38197\n26122   curl         4  127.0.0.1        127.0.0.1        35983\n26124   curl         6  ::1              ::1              38197\n26126   curl         4  127.0.0.1        127.0.0.1        35983\n26128   curl         6  ::1              ::1              38197\n26130   curl         4  127.0.0.1        127.0.0.1        35983\n26132   curl         6  ::1              ::1              38197\n26134   curl         4  127.0.0.1        127.0.0.1        35983\n26136   curl         6  ::1              ::1              38197\n26138   curl         4  127.0.0.1        127.0.0.1        35983\n26140   curl         6  ::1              ::1              38197\n26142   curl         4  127.0.0.1        127.0.0.1        35983\n26144   curl         6  ::1              ::1              38197\n26146   curl         4  127.0.0.1        127.0.0.1        35983\n26148   curl         6  ::1              ::1              38197\n26150   curl         4  127.0.0.1        127.0.0.1        35983\n26152   curl         6  ::1              ::1              38197\n26154   curl         4  127.0.0.1        127.0.0.1        35983\n26156   curl         6  ::1              ::1              38197\n26158   curl         4  127.0.0.1        127.0.0.1        35983\n26160   curl         6  ::1              ::1              38197"
}
```

## bindsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1437": {
        "avg_ns_per_run": 65.05847021639411,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1437,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1933463,
        "run_time_ns_delta": 125788145,
        "type": "kprobe"
      },
      "1438": {
        "avg_ns_per_run": 849.726900526723,
        "bytes_jited": 721,
        "bytes_xlated": 1160,
        "id": 1438,
        "name": "bindsnoop_v4_return",
        "run_cnt_delta": 966732,
        "run_time_ns_delta": 821458186,
        "type": "kprobe"
      },
      "1439": {
        "avg_ns_per_run": 789.2118272818395,
        "bytes_jited": 742,
        "bytes_xlated": 1184,
        "id": 1439,
        "name": "bindsnoop_v6_return",
        "run_cnt_delta": 966731,
        "run_time_ns_delta": 762955539,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 193346.1886325993
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
        "avg_ns_per_run": 64.27556833988857,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1437,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1958995,
        "run_time_ns_delta": 125915517,
        "type": "kprobe"
      },
      "1438": {
        "avg_ns_per_run": 839.3894219283756,
        "bytes_jited": 719,
        "bytes_xlated": 1160,
        "id": 1438,
        "name": "bindsnoop_v4_re",
        "run_cnt_delta": 979498,
        "run_time_ns_delta": 822180260,
        "type": "kprobe"
      },
      "1439": {
        "avg_ns_per_run": 784.429488809052,
        "bytes_jited": 740,
        "bytes_xlated": 1184,
        "id": 1439,
        "name": "bindsnoop_v6_re",
        "run_cnt_delta": 979497,
        "run_time_ns_delta": 768346331,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 195899.43300239422
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
  "stderr_tail": "arch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eecda4e7/bcc-python-fakg_pyo/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:18:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.\nPossibly lost 31 samples\nPossibly lost 132 samples\nPossibly lost 113 samples\nPossibly lost 112 samples",
  "stdout_tail": "    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   127.0.0.1       11008 ..NR.  0\n    1739 python3      IP   ::1             16128 ..NR.  0"
}
```

