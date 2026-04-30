# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-25T08:40:44.923833+00:00`
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
        "avg_ns_per_run": 641.9213175485222,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1411,
        "name": "tracepoint__sock__inet_sock_set_state",
        "run_cnt_delta": 37251,
        "run_time_ns_delta": 23912211,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 338.6982279564603
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
        "avg_ns_per_run": 645.5787358904544,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1411,
        "name": "sock__inet_sock",
        "run_cnt_delta": 37829,
        "run_time_ns_delta": 24421598,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 344.04501018507955
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
  "stderr_tail": "In file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-8qcmtw9d/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-8qcmtw9d/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/tcp.h:7:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "32478 curl       ::1             35275 ::1             40842     0     0 0.28\n32478 curl       ::1             40842 ::1             35275     0     0 0.29\n32480 curl       127.0.0.1       35199 127.0.0.1       54916     0     0 0.30\n32480 curl       127.0.0.1       54916 127.0.0.1       35199     0     0 0.31\n32482 curl       ::1             35275 ::1             40846     0     0 0.40\n32482 curl       ::1             40846 ::1             35275     0     0 0.41\n32484 curl       127.0.0.1       35199 127.0.0.1       54926     0     0 0.47\n32484 curl       127.0.0.1       54926 127.0.0.1       35199     0     0 0.48\n32486 curl       ::1             35275 ::1             40862     0     0 0.34\n32486 curl       ::1             40862 ::1             35275     0     0 0.35\n32488 curl       127.0.0.1       35199 127.0.0.1       54940     0     0 0.42\n32488 curl       127.0.0.1       54940 127.0.0.1       35199     0     0 0.44\n32490 curl       ::1             35275 ::1             40876     0     0 0.22\n32490 curl       ::1             40876 ::1             35275     0     0 0.22\n32492 curl       127.0.0.1       35199 127.0.0.1       54948     0     0 0.41\n32492 curl       127.0.0.1       54948 127.0.0.1       35199     0     0 0.42\n32494 curl       ::1             35275 ::1             40878     0     0 0.39\n32494 curl       ::1             40878 ::1             35275     0     0 0.40\n32496 curl       127.0.0.1       35199 127.0.0.1       54960     0     0 0.43\n32496 curl       127.0.0.1       54960 127.0.0.1       35199     0     0 0.45\n32498 curl       ::1             35275 ::1             40884     0     0 0.40\n32498 curl       ::1             40884 ::1             35275     0     0 0.41\n32500 curl       127.0.0.1       35199 127.0.0.1       54970     0     0 0.43\n32500 curl       127.0.0.1       54970 127.0.0.1       35199     0     0 0.44\n32502 curl       ::1             35275 ::1             40888     0     0 0.35\n32502 curl       ::1             40888 ::1             35275     0     0 0.36\n32504 curl       127.0.0.1       35199 127.0.0.1       54972     0     0 0.20\n32504 curl       127.0.0.1       54972 127.0.0.1       35199     0     0 0.22\n32506 curl       ::1             35275 ::1             40892     0     0 0.43\n32506 curl       ::1             40892 ::1             35275     0     0 0.44\n32508 curl       127.0.0.1       35199 127.0.0.1       54986     0     0 0.37\n32508 curl       127.0.0.1       54986 127.0.0.1       35199     0     0 0.39\n32510 curl       ::1             35275 ::1             40898     0     0 0.38\n32510 curl       ::1             40898 ::1             35275     0     0 0.39\n32512 curl       127.0.0.1       35199 127.0.0.1       55000     0     0 0.51\n32512 curl       127.0.0.1       55000 127.0.0.1       35199     0     0 0.52\n32514 curl       ::1             35275 ::1             40900     0     0 0.34\n32514 curl       ::1             40900 ::1             35275     0     0 0.34\n32516 curl       127.0.0.1       35199 127.0.0.1       55014     0     0 0.42\n32516 curl       127.0.0.1       55014 127.0.0.1       35199     0     0 0.43"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1414": {
        "avg_ns_per_run": 67.48327659750885,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1414,
        "name": "trace_pid_start_tp",
        "run_cnt_delta": 8683520,
        "run_time_ns_delta": 585992382,
        "type": "tracepoint"
      },
      "1415": {
        "avg_ns_per_run": 97.49045283479511,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1415,
        "name": "trace_req_start",
        "run_cnt_delta": 8683520,
        "run_time_ns_delta": 846560297,
        "type": "kprobe"
      },
      "1416": {
        "avg_ns_per_run": 286.0372035764298,
        "bytes_jited": 550,
        "bytes_xlated": 856,
        "id": 1416,
        "name": "trace_req_completion_tp",
        "run_cnt_delta": 8683520,
        "run_time_ns_delta": 2483809778,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 868081.5645536092
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
        "avg_ns_per_run": 65.74265795051079,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1414,
        "name": "trace_pid_start",
        "run_cnt_delta": 8888322,
        "run_time_ns_delta": 584341913,
        "type": "tracepoint"
      },
      "1415": {
        "avg_ns_per_run": 96.05702031114077,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1415,
        "name": "trace_req_start",
        "run_cnt_delta": 8888324,
        "run_time_ns_delta": 853785919,
        "type": "kprobe"
      },
      "1416": {
        "avg_ns_per_run": 285.3452835039223,
        "bytes_jited": 548,
        "bytes_xlated": 848,
        "id": 1416,
        "name": "trace_req_compl",
        "run_cnt_delta": 8888325,
        "run_time_ns_delta": 2536241617,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 888415.7498579833
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
  "stderr_tail": "In file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-0yrrlp9p/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/blk-mq.h:5:\nIn file included from include/linux/blkdev.h:7:\nIn file included from include/linux/blk_types.h:7:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "20.290816                  4439    nullb0    R 32448      4096      0.00\n20.290817                  4439    nullb0    R 32456      4096      0.00\n20.290818                  4439    nullb0    R 32464      4096      0.00\n20.290819                  4439    nullb0    R 32472      4096      0.00\n20.290820                  4439    nullb0    R 32480      4096      0.00\n20.290822                  4439    nullb0    R 32488      4096      0.00\n20.290823                  4439    nullb0    R 32496      4096      0.00\n20.290824                  4439    nullb0    R 32504      4096      0.00\n20.290825                  4439    nullb0    R 32512      4096      0.00\n20.290826                  4439    nullb0    R 32520      4096      0.00\n20.290827                  4439    nullb0    R 32528      4096      0.00\n20.290828                  4439    nullb0    R 32536      4096      0.00\n20.290829                  4439    nullb0    R 32544      4096      0.00\n20.290831                  4439    nullb0    R 32552      4096      0.00\n20.290832                  4439    nullb0    R 32560      4096      0.00\n20.290833                  4439    nullb0    R 32568      4096      0.00\n20.290834                  4439    nullb0    R 32576      4096      0.00\n20.290835                  4439    nullb0    R 32584      4096      0.00\n20.290836                  4439    nullb0    R 32592      4096      0.00\n20.290837                  4439    nullb0    R 32600      4096      0.00\n20.290838                  4439    nullb0    R 32608      4096      0.00\n20.290840                  4439    nullb0    R 32616      4096      0.00\n20.290841                  4439    nullb0    R 32624      4096      0.00\n20.290842                  4439    nullb0    R 32632      4096      0.00\n20.290843                  4439    nullb0    R 32640      4096      0.00\n20.290844                  4439    nullb0    R 32648      4096      0.00\n20.290845                  4439    nullb0    R 32656      4096      0.00\n20.290846                  4439    nullb0    R 32664      4096      0.00\n20.290847                  4439    nullb0    R 32672      4096      0.00\n20.290849                  4439    nullb0    R 32680      4096      0.00\n20.290850                  4439    nullb0    R 32688      4096      0.00\n20.290851                  4439    nullb0    R 32696      4096      0.00\n20.290852                  4439    nullb0    R 32704      4096      0.00\n20.290853                  4439    nullb0    R 32712      4096      0.00\n20.290854                  4439    nullb0    R 32720      4096      0.00\n20.290855                  4439    nullb0    R 32728      4096      0.00\n20.290857                  4439    nullb0    R 32736      4096      0.00\n20.290858                  4439    nullb0    R 32744      4096      0.00\n20.290859                  4439    nullb0    R 32752      4096      0.00\n20.290860                  4439    nullb0    R 32760      4096      0.00"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1421": {
        "avg_ns_per_run": 172.3282602367276,
        "bytes_jited": 662,
        "bytes_xlated": 1168,
        "id": 1421,
        "name": "sched_switch",
        "run_cnt_delta": 1576749,
        "run_time_ns_delta": 271718412,
        "type": "raw_tracepoint"
      },
      "1422": {
        "avg_ns_per_run": 111.44301802533387,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1422,
        "name": "sched_wakeup",
        "run_cnt_delta": 831219,
        "run_time_ns_delta": 92633554,
        "type": "raw_tracepoint"
      },
      "1423": {
        "avg_ns_per_run": 234.9529167430212,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1423,
        "name": "raw_tracepoint__sched_wakeup_new",
        "run_cnt_delta": 163710,
        "run_time_ns_delta": 38464142,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 63.65813407591231
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
        "avg_ns_per_run": 171.00019023368537,
        "bytes_jited": 645,
        "bytes_xlated": 1136,
        "id": 1421,
        "name": "sched_switch",
        "run_cnt_delta": 1555981,
        "run_time_ns_delta": 266073047,
        "type": "raw_tracepoint"
      },
      "1422": {
        "avg_ns_per_run": 116.52248630887185,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1422,
        "name": "sched_wakeup",
        "run_cnt_delta": 821700,
        "run_time_ns_delta": 95746527,
        "type": "raw_tracepoint"
      },
      "1423": {
        "avg_ns_per_run": 239.2146221332923,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1423,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 162425,
        "run_time_ns_delta": 38854435,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 63.11861324424649
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
  "stderr_tail": "In file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-kw8a311_/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-kw8a311_/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:6:\nIn file included from include/linux/pid_namespace.h:7:\nIn file included from include/linux/mm.h:1118:\nIn file included from include/linux/huge_mm.h:7:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "             8388608 -> 16777215             : 5089     |                    |\n            16777216 -> 33554431             : 0        |                    |\n            33554432 -> 67108863             : 0        |                    |\n            67108864 -> 134217727            : 0        |                    |\n           134217728 -> 268435455            : 0        |                    |\n           268435456 -> 536870911            : 4446     |                    |\n           536870912 -> 1073741823           : 4141     |                    |\n          1073741824 -> 2147483647           : 4135     |                    |\n          2147483648 -> 4294967295           : 4241     |                    |\n          4294967296 -> 8589934591           : 0        |                    |\n          8589934592 -> 17179869183          : 0        |                    |\n         17179869184 -> 34359738367          : 0        |                    |\n         34359738368 -> 68719476735          : 0        |                    |\n         68719476736 -> 137438953471         : 3511     |                    |\n        137438953472 -> 274877906943         : 3524     |                    |\n        274877906944 -> 549755813887         : 3446     |                    |\n        549755813888 -> 1099511627775        : 3261     |                    |\n       1099511627776 -> 2199023255551        : 0        |                    |\n       2199023255552 -> 4398046511103        : 0        |                    |\n       4398046511104 -> 8796093022207        : 0        |                    |\n       8796093022208 -> 17592186044415       : 0        |                    |\n      17592186044416 -> 35184372088831       : 2933     |                    |\n      35184372088832 -> 70368744177663       : 2970     |                    |\n      70368744177664 -> 140737488355327      : 2850     |                    |\n     140737488355328 -> 281474976710655      : 2802     |                    |\n     281474976710656 -> 562949953421311      : 0        |                    |\n     562949953421312 -> 1125899906842623     : 0        |                    |\n    1125899906842624 -> 2251799813685247     : 0        |                    |\n    2251799813685248 -> 4503599627370495     : 0        |                    |\n    4503599627370496 -> 9007199254740991     : 2631     |                    |\n    9007199254740992 -> 18014398509481983    : 2541     |                    |\n   18014398509481984 -> 36028797018963967    : 2602     |                    |\n   36028797018963968 -> 72057594037927935    : 2637     |                    |\n   72057594037927936 -> 144115188075855871   : 0        |                    |\n  144115188075855872 -> 288230376151711743   : 0        |                    |\n  288230376151711744 -> 576460752303423487   : 0        |                    |\n  576460752303423488 -> 1152921504606846975  : 0        |                    |\n 1152921504606846976 -> 2305843009213693951  : 2441     |                    |\n 2305843009213693952 -> 4611686018427387903  : 2493     |                    |\n 4611686018427387904 -> 9223372036854775807  : 2435     |                    |"
}
```

## syscount

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1428": {
        "avg_ns_per_run": 68.78041005226791,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1428,
        "name": "tracepoint__raw_syscalls__sys_enter",
        "run_cnt_delta": 61797,
        "run_time_ns_delta": 4250423,
        "type": "tracepoint"
      },
      "1429": {
        "avg_ns_per_run": 76.10024758483422,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1429,
        "name": "tracepoint__raw_syscalls__sys_exit",
        "run_cnt_delta": 61797,
        "run_time_ns_delta": 4702767,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1084.821235577847
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
        "avg_ns_per_run": 72.90898893086326,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1428,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 60619,
        "run_time_ns_delta": 4419670,
        "type": "tracepoint"
      },
      "1429": {
        "avg_ns_per_run": 77.67115920750919,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1429,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 60619,
        "run_time_ns_delta": 4708348,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1070.5900456537458
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
  "output_chars": 9099,
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-rx5ktf02/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-rx5ktf02/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "nanosleep                     2        20106.341\nioctl                      1087          194.784\nlseek                      1087          158.836\nfutex                         6      2293901.105\n[08:38:08]\nSYSCALL                   COUNT        TIME (us)\nclock_nanosleep              11      2000598.486\nepoll_pwait                  10      1156549.396\nread                          3      1000202.915\nopenat                     1095       748852.497\nclose                      1095       145238.168\nfstat                      1095       102271.810\nnanosleep                     2        20106.285\nioctl                      1095          193.148\nlseek                      1095          159.182\nfutex                         9      9847473.384\n[08:38:09]\nSYSCALL                   COUNT        TIME (us)\nepoll_pwait                   9      4939542.370\nclock_nanosleep              11      2000604.128\nread                          2      1000200.772\nopenat                     1079       744880.700\nclose                      1078       144559.615\nfstat                      1078       107473.955\nnanosleep                     3        30163.277\nioctl                      1078          193.110\nlseek                      1078          157.455\nclock_nanosleep              11      1977967.010\n[08:38:10]\nSYSCALL                   COUNT        TIME (us)\nfutex                         3      1147334.009\nread                         17      1000217.155\nopenat                      979       673227.100\nepoll_pwait                   5       578686.753\nclose                       996       131549.579\nfstat                       985        97474.258\nunlinkat                    256        66360.595\nnanosleep                     1        10054.731\ngetdents64                    2         2827.375\nDetaching..."
}
```

## execsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1432": {
        "avg_ns_per_run": 1320.1763905040134,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1432,
        "name": "syscall__execve",
        "run_cnt_delta": 35257,
        "run_time_ns_delta": 46545459,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 887.9840031766742,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1433,
        "name": "do_ret_sys_execve",
        "run_cnt_delta": 35257,
        "run_time_ns_delta": 31307652,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1762.775145751866
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
        "avg_ns_per_run": 1483.270084695549,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1432,
        "name": "syscall__execve",
        "run_cnt_delta": 28691,
        "run_time_ns_delta": 42556502,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 925.8707608657767,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1433,
        "name": "do_ret_sys_exec",
        "run_cnt_delta": 28691,
        "run_time_ns_delta": 26564158,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1434.4208414858676
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
  "stderr_tail": "<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-izr7bkde/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-izr7bkde/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "08:38:35 65534 true             7074    1723      0 /bin/true\n08:38:35 65534 true             7075    1723      0 /bin/true\n08:38:35 65534 true             7076    1723      0 /bin/true\n08:38:35 65534 true             7077    1723      0 /bin/true\n08:38:35 65534 true             7078    1723      0 /bin/true\n08:38:35 65534 true             7079    1723      0 /bin/true\n08:38:35 65534 true             7080    1723      0 /bin/true\n08:38:35 65534 true             7081    1723      0 /bin/true\n08:38:35 65534 true             7082    1723      0 /bin/true\n08:38:35 65534 true             7083    1723      0 /bin/true\n08:38:35 65534 true             7084    1723      0 /bin/true\n08:38:35 65534 true             7085    1723      0 /bin/true\n08:38:35 65534 true             7086    1723      0 /bin/true\n08:38:35 65534 true             7087    1723      0 /bin/true\n08:38:35 65534 true             7088    1723      0 /bin/true\n08:38:35 65534 true             7089    1723      0 /bin/true\n08:38:35 65534 true             7090    1723      0 /bin/true\n08:38:35 65534 true             7091    1723      0 /bin/true\n08:38:35 65534 true             7092    1723      0 /bin/true\n08:38:35 65534 true             7093    1723      0 /bin/true\n08:38:35 65534 true             7094    1723      0 /bin/true\n08:38:35 65534 true             7095    1723      0 /bin/true\n08:38:35 65534 true             7096    1723      0 /bin/true\n08:38:35 65534 true             7097    1723      0 /bin/true\n08:38:35 65534 true             7098    1723      0 /bin/true\n08:38:35 65534 true             7099    1723      0 /bin/true\n08:38:35 65534 true             7100    1723      0 /bin/true\n08:38:35 65534 true             7101    1723      0 /bin/true\n08:38:35 65534 true             7102    1723      0 /bin/true\n08:38:35 65534 true             7103    1723      0 /bin/true\n08:38:35 65534 true             7104    1723      0 /bin/true\n08:38:35 65534 true             7105    1723      0 /bin/true\n08:38:35 65534 true             7106    1723      0 /bin/true\n08:38:35 65534 true             7107    1723      0 /bin/true\n08:38:35 65534 true             7108    1723      0 /bin/true\n08:38:35 65534 true             7109    1723      0 /bin/true\n08:38:35 65534 true             7110    1723      0 /bin/true\n08:38:35 65534 true             7111    1723      0 /bin/true\n08:38:35 65534 true             7112    1723      0 /bin/true\n08:38:35 65534 true             7113    1723      0 /bin/true"
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
        "avg_ns_per_run": 1512.1752955191057,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1437,
        "name": "kretfunc__vmlinux____x64_sys_openat",
        "run_cnt_delta": 10913,
        "run_time_ns_delta": 16502369,
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
    "throughput": 1064.3314749337912
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
        "avg_ns_per_run": 1400.0673654035654,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1437,
        "name": "__x64_sys_opena",
        "run_cnt_delta": 11163,
        "run_time_ns_delta": 15628952,
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
    "throughput": 1089.3789889295817
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-_jb4xpmu/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-_jb4xpmu/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-115.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-116.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-117.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-118.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-119.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-120.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-121.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-122.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-123.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-124.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-125.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-126.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-127.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-128.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-129.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-130.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-131.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-132.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-133.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-134.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-135.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-136.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-137.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-138.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-139.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-140.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m/open-141.dat\n1723   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/loopback-open-storm-cc5h6p_m\n7146   bpftool             3   0 /etc/ld.so.cache\n7146   bpftool             3   0 /lib/x86_64-linux-gnu/libelf.so.1\n7146   bpftool             3   0 /lib/x86_64-linux-gnu/libcrypto.so.3\n7146   bpftool             3   0 /lib/x86_64-linux-gnu/libz.so.1\n7146   bpftool             3   0 /lib/x86_64-linux-gnu/libcap.so.2\n7146   bpftool             3   0 /lib/x86_64-linux-gnu/libc.so.6\n7146   bpftool             3   0 /lib/x86_64-linux-gnu/libzstd.so.1\n7146   bpftool             4   0 /etc/localtime\n7146   bpftool             4   0 /proc/self/fdinfo/3\n7146   bpftool             4   0 /proc/self/fdinfo/3\n7146   bpftool             4   0 /proc/self/fdinfo/3\n7146   bpftool             4   0 /proc/self/fdinfo/3"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1441": {
        "avg_ns_per_run": 40.61544403654944,
        "bytes_jited": 203,
        "bytes_xlated": 344,
        "id": 1441,
        "name": "cap_capable",
        "run_cnt_delta": 2780672,
        "run_time_ns_delta": 112938228,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 2434.0822345206943
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
        "avg_ns_per_run": 40.608022172167296,
        "bytes_jited": 206,
        "bytes_xlated": 344,
        "id": 1441,
        "name": "cap_capable",
        "run_cnt_delta": 2762743,
        "run_time_ns_delta": 112189529,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 2410.020706532279
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
  "output_chars": 3703,
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
  "stderr_tail": "  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-pq6bib_f/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-pq6bib_f/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\nIn file included from include/linux/security.h:9:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "08:39:26  65534  15046  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15073  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15074  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15075  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15047  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  14992  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15057  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15008  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15058  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15064  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15059  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15076  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15066  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15060  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15077  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15078  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15068  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15007  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15009  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15079  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15080  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15069  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15081  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15072  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15082  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15086  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15083  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15084  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  65534  15085  stress-ng-exec   8    CAP_SETPCAP          1\n08:39:26  0      15119  bpftool          21   CAP_SYS_ADMIN        1\n08:39:26  0      15119  bpftool          21   CAP_SYS_ADMIN        1\n08:39:26  0      15119  bpftool          39   CAP_BPF              1\n08:39:26  0      15119  bpftool          21   CAP_SYS_ADMIN        1\n08:39:26  0      15119  bpftool          21   CAP_SYS_ADMIN        1\n08:39:26  0      15119  bpftool          39   CAP_BPF              1\n08:39:26  0      15119  bpftool          39   CAP_BPF              1\n08:39:26  0      15119  bpftool          39   CAP_BPF              1\n08:39:26  0      15119  bpftool          39   CAP_BPF              1\n08:39:26  0      15119  bpftool          21   CAP_SYS_ADMIN        1\n08:39:26  0      15119  bpftool          21   CAP_SYS_ADMIN        1"
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
        "avg_ns_per_run": 66.95848595848595,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1447,
        "name": "vfs_open",
        "run_cnt_delta": 819,
        "run_time_ns_delta": 54839,
        "type": "tracing"
      },
      "1448": {
        "avg_ns_per_run": 33.69096573208723,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1448,
        "name": "vfs_read",
        "run_cnt_delta": 1605,
        "run_time_ns_delta": 54074,
        "type": "tracing"
      },
      "1449": {
        "avg_ns_per_run": 35.66624685138539,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1449,
        "name": "vfs_write",
        "run_cnt_delta": 794,
        "run_time_ns_delta": 28319,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 79.1244560284689
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
        "avg_ns_per_run": 105.3023872679045,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1447,
        "name": "vfs_open",
        "run_cnt_delta": 754,
        "run_time_ns_delta": 79398,
        "type": "tracing"
      },
      "1448": {
        "avg_ns_per_run": 42.208248816768084,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1448,
        "name": "vfs_read",
        "run_cnt_delta": 1479,
        "run_time_ns_delta": 62426,
        "type": "tracing"
      },
      "1449": {
        "avg_ns_per_run": 40.3137789904502,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1449,
        "name": "vfs_write",
        "run_cnt_delta": 733,
        "run_time_ns_delta": 29550,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 72.64845571725225
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
  "output_chars": 19749,
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-t9qaerzr/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-t9qaerzr/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "TIME         READ/s  WRITE/s  FSYNC/s   OPEN/s CREATE/s\n08:39:29:      1487        5        0      132        0\n08:39:30:       100        5        0      130        0\n08:39:31:       164       65        0      114        0\n08:39:32:       160       80        0       80        0\n08:39:33:       156       78        0       78        0\n08:39:34:       158       79        0       79        0\n08:39:35:       160       80        0       80        0\n08:39:36:       162       80        0       81        0\n08:39:37:       155       79        0       77        0\n08:39:38:       158       79        0       79        0\n08:39:39:       164       82        0       82        0\n08:39:40:       158       79        0       79        0\n08:39:41:       152       47        0      119        0\n08:39:42:       145       73        0       73        0\n08:39:43:       149       75        0       74        0\n08:39:44:       144       72        0       72        0\n08:39:45:       153       77        0       76        0\n08:39:46:       153       77        0       76        0\n08:39:47:       151       76        0       75        0\n08:39:48:       143       72        0       71        0\n08:39:49:       141       71        0       70        0\n08:39:50:       132       66        0       66        0\n08:39:51:       106       43        0       70        0"
}
```

## tcpconnect

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1452": {
        "avg_ns_per_run": 705.791266135677,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1452,
        "name": "trace_connect_entry",
        "run_cnt_delta": 3641,
        "run_time_ns_delta": 2569786,
        "type": "kprobe"
      },
      "1453": {
        "avg_ns_per_run": 3926.8758923668315,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1453,
        "name": "trace_connect_v4_return",
        "run_cnt_delta": 1821,
        "run_time_ns_delta": 7150841,
        "type": "kprobe"
      },
      "1454": {
        "avg_ns_per_run": 4048.5967032967033,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1454,
        "name": "trace_connect_v6_return",
        "run_cnt_delta": 1820,
        "run_time_ns_delta": 7368446,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 364.0848270196948
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
        "avg_ns_per_run": 727.1517931609675,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1452,
        "name": "trace_connect_e",
        "run_cnt_delta": 3597,
        "run_time_ns_delta": 2615565,
        "type": "kprobe"
      },
      "1453": {
        "avg_ns_per_run": 3919.1939966648138,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1453,
        "name": "trace_connect_v",
        "run_cnt_delta": 1799,
        "run_time_ns_delta": 7050630,
        "type": "kprobe"
      },
      "1454": {
        "avg_ns_per_run": 3843.0233592880977,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1454,
        "name": "trace_connect_v",
        "run_cnt_delta": 1798,
        "run_time_ns_delta": 6909756,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 359.6327543211718
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
  "output_chars": 12349,
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
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-6gmqv9wb/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:16:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "29588   curl         6  ::1              ::1              43977\n29590   curl         4  127.0.0.1        127.0.0.1        36953\n29592   curl         6  ::1              ::1              43977\n29594   curl         4  127.0.0.1        127.0.0.1        36953\n29596   curl         6  ::1              ::1              43977\n29598   curl         4  127.0.0.1        127.0.0.1        36953\n29600   curl         6  ::1              ::1              43977\n29602   curl         4  127.0.0.1        127.0.0.1        36953\n29604   curl         6  ::1              ::1              43977\n29606   curl         4  127.0.0.1        127.0.0.1        36953\n29608   curl         6  ::1              ::1              43977\n29610   curl         4  127.0.0.1        127.0.0.1        36953\n29612   curl         6  ::1              ::1              43977\n29614   curl         4  127.0.0.1        127.0.0.1        36953\n29616   curl         6  ::1              ::1              43977\n29618   curl         4  127.0.0.1        127.0.0.1        36953\n29620   curl         6  ::1              ::1              43977\n29622   curl         4  127.0.0.1        127.0.0.1        36953\n29624   curl         6  ::1              ::1              43977\n29626   curl         4  127.0.0.1        127.0.0.1        36953\n29628   curl         6  ::1              ::1              43977\n29630   curl         4  127.0.0.1        127.0.0.1        36953\n29632   curl         6  ::1              ::1              43977\n29634   curl         4  127.0.0.1        127.0.0.1        36953\n29636   curl         6  ::1              ::1              43977\n29638   curl         4  127.0.0.1        127.0.0.1        36953\n29640   curl         6  ::1              ::1              43977\n29642   curl         4  127.0.0.1        127.0.0.1        36953\n29644   curl         6  ::1              ::1              43977\n29646   curl         4  127.0.0.1        127.0.0.1        36953\n29648   curl         6  ::1              ::1              43977\n29650   curl         4  127.0.0.1        127.0.0.1        36953\n29652   curl         6  ::1              ::1              43977\n29654   curl         4  127.0.0.1        127.0.0.1        36953\n29656   curl         6  ::1              ::1              43977\n29658   curl         4  127.0.0.1        127.0.0.1        36953\n29660   curl         6  ::1              ::1              43977\n29662   curl         4  127.0.0.1        127.0.0.1        36953\n29664   curl         6  ::1              ::1              43977\n29666   curl         4  127.0.0.1        127.0.0.1        36953"
}
```

## bindsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1457": {
        "avg_ns_per_run": 56.307120257169615,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1457,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1975350,
        "run_time_ns_delta": 111226270,
        "type": "kprobe"
      },
      "1458": {
        "avg_ns_per_run": 835.7531019819272,
        "bytes_jited": 721,
        "bytes_xlated": 1160,
        "id": 1458,
        "name": "bindsnoop_v4_return",
        "run_cnt_delta": 987675,
        "run_time_ns_delta": 825452445,
        "type": "kprobe"
      },
      "1459": {
        "avg_ns_per_run": 786.0496256359633,
        "bytes_jited": 742,
        "bytes_xlated": 1184,
        "id": 1459,
        "name": "bindsnoop_v6_return",
        "run_cnt_delta": 987675,
        "run_time_ns_delta": 776361564,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 197534.92045268888
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
        "avg_ns_per_run": 57.375438362853465,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1457,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1982376,
        "run_time_ns_delta": 113739692,
        "type": "kprobe"
      },
      "1458": {
        "avg_ns_per_run": 842.6589607622368,
        "bytes_jited": 719,
        "bytes_xlated": 1160,
        "id": 1458,
        "name": "bindsnoop_v4_re",
        "run_cnt_delta": 991188,
        "run_time_ns_delta": 835233450,
        "type": "kprobe"
      },
      "1459": {
        "avg_ns_per_run": 788.3282919082959,
        "bytes_jited": 740,
        "bytes_xlated": 1184,
        "id": 1459,
        "name": "bindsnoop_v6_re",
        "run_cnt_delta": 991188,
        "run_time_ns_delta": 781381543,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 198237.50906845616
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
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ef191d28/bcc-python-hqtznp1k/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:18:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   127.0.0.1       10880 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0\n    1723 python3      IP   ::1             16000 ..NR.  0"
}
```

