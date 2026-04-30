# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-26T02:44:45.857764+00:00`
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
        "avg_ns_per_run": 594.9701110574601,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1391,
        "name": "tracepoint__sock__inet_sock_set_state",
        "run_cnt_delta": 41420,
        "run_time_ns_delta": 24643662,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 376.8882093915735
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
        "avg_ns_per_run": 673.8555948443025,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1391,
        "name": "sock__inet_sock",
        "run_cnt_delta": 35068,
        "run_time_ns_delta": 23630768,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 318.85501829354934
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
  "stderr_tail": "In file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-mb1463pk/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-mb1463pk/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/tcp.h:7:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "19916 curl       ::1             34725 ::1             36916     0     0 0.31\n19916 curl       ::1             36916 ::1             34725     0     0 0.33\n19918 curl       127.0.0.1       33959 127.0.0.1       41568     0     0 0.28\n19918 curl       127.0.0.1       41568 127.0.0.1       33959     0     0 0.29\n19920 curl       ::1             34725 ::1             36924     0     0 0.31\n19920 curl       ::1             36924 ::1             34725     0     0 0.33\n19922 curl       127.0.0.1       33959 127.0.0.1       41574     0     0 0.36\n19922 curl       127.0.0.1       41574 127.0.0.1       33959     0     0 0.37\n19924 curl       ::1             34725 ::1             36940     0     0 0.22\n19924 curl       ::1             36940 ::1             34725     0     0 0.23\n19926 curl       127.0.0.1       33959 127.0.0.1       41590     0     0 0.37\n19926 curl       127.0.0.1       41590 127.0.0.1       33959     0     0 0.38\n19928 curl       ::1             34725 ::1             36956     0     0 0.26\n19928 curl       ::1             36956 ::1             34725     0     0 0.27\n19930 curl       127.0.0.1       33959 127.0.0.1       41604     0     0 0.23\n19930 curl       127.0.0.1       41604 127.0.0.1       33959     0     0 0.24\n19932 curl       ::1             34725 ::1             36958     0     0 0.26\n19932 curl       ::1             36958 ::1             34725     0     0 0.27\n19934 curl       127.0.0.1       33959 127.0.0.1       41606     0     0 0.20\n19934 curl       127.0.0.1       41606 127.0.0.1       33959     0     0 0.21\n19936 curl       ::1             34725 ::1             36974     0     0 0.32\n19936 curl       ::1             36974 ::1             34725     0     0 0.33\n19938 curl       127.0.0.1       33959 127.0.0.1       41614     0     0 0.25\n19938 curl       127.0.0.1       41614 127.0.0.1       33959     0     0 0.27\n19940 curl       ::1             34725 ::1             36990     0     0 0.20\n19940 curl       ::1             36990 ::1             34725     0     0 0.21\n19942 curl       127.0.0.1       33959 127.0.0.1       41618     0     0 0.31\n19942 curl       127.0.0.1       41618 127.0.0.1       33959     0     0 0.32\n19944 curl       ::1             34725 ::1             37000     0     0 0.28\n19944 curl       ::1             37000 ::1             34725     0     0 0.29\n19946 curl       127.0.0.1       33959 127.0.0.1       41634     0     0 0.20\n19946 curl       127.0.0.1       41634 127.0.0.1       33959     0     0 0.22\n19948 curl       ::1             34725 ::1             37002     0     0 0.40\n19948 curl       ::1             37002 ::1             34725     0     0 0.41\n19950 curl       127.0.0.1       33959 127.0.0.1       41646     0     0 0.22\n19950 curl       127.0.0.1       41646 127.0.0.1       33959     0     0 0.23\n19952 curl       ::1             34725 ::1             37006     0     0 0.19\n19952 curl       ::1             37006 ::1             34725     0     0 0.20\n19954 curl       127.0.0.1       33959 127.0.0.1       41662     0     0 0.38\n19954 curl       127.0.0.1       41662 127.0.0.1       33959     0     0 0.39"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1394": {
        "avg_ns_per_run": 68.3376360799678,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1394,
        "name": "trace_pid_start_tp",
        "run_cnt_delta": 8265728,
        "run_time_ns_delta": 564860312,
        "type": "tracepoint"
      },
      "1395": {
        "avg_ns_per_run": 99.04285091403928,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1395,
        "name": "trace_req_start",
        "run_cnt_delta": 8265728,
        "run_time_ns_delta": 818661266,
        "type": "kprobe"
      },
      "1396": {
        "avg_ns_per_run": 286.2536295653571,
        "bytes_jited": 550,
        "bytes_xlated": 856,
        "id": 1396,
        "name": "trace_req_completion_tp",
        "run_cnt_delta": 8265728,
        "run_time_ns_delta": 2366094641,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 826119.946985234
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
        "avg_ns_per_run": 66.22948382410738,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1394,
        "name": "trace_pid_start",
        "run_cnt_delta": 8544258,
        "run_time_ns_delta": 565881797,
        "type": "tracepoint"
      },
      "1395": {
        "avg_ns_per_run": 97.22475322614247,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1395,
        "name": "trace_req_start",
        "run_cnt_delta": 8544260,
        "run_time_ns_delta": 830713570,
        "type": "kprobe"
      },
      "1396": {
        "avg_ns_per_run": 283.78414598992237,
        "bytes_jited": 548,
        "bytes_xlated": 848,
        "id": 1396,
        "name": "trace_req_compl",
        "run_cnt_delta": 8544261,
        "run_time_ns_delta": 2424725811,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 853682.6901513188
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
  "stderr_tail": "Possibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 4 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples",
  "stdout_tail": "20.294452                  24161   nullb0    R 32448      4096      0.00\n20.294453                  24161   nullb0    R 32456      4096      0.00\n20.294454                  24161   nullb0    R 32464      4096      0.00\n20.294455                  24161   nullb0    R 32472      4096      0.00\n20.294456                  24161   nullb0    R 32480      4096      0.00\n20.294457                  24161   nullb0    R 32488      4096      0.00\n20.294459                  24161   nullb0    R 32496      4096      0.00\n20.294460                  24161   nullb0    R 32504      4096      0.00\n20.294461                  24161   nullb0    R 32512      4096      0.00\n20.294462                  24161   nullb0    R 32520      4096      0.00\n20.294463                  24161   nullb0    R 32528      4096      0.00\n20.294464                  24161   nullb0    R 32536      4096      0.00\n20.294465                  24161   nullb0    R 32544      4096      0.00\n20.294467                  24161   nullb0    R 32552      4096      0.00\n20.294468                  24161   nullb0    R 32560      4096      0.00\n20.294469                  24161   nullb0    R 32568      4096      0.00\n20.294470                  24161   nullb0    R 32576      4096      0.00\n20.294471                  24161   nullb0    R 32584      4096      0.00\n20.294472                  24161   nullb0    R 32592      4096      0.00\n20.294473                  24161   nullb0    R 32600      4096      0.00\n20.294474                  24161   nullb0    R 32608      4096      0.00\n20.294476                  24161   nullb0    R 32616      4096      0.00\n20.294477                  24161   nullb0    R 32624      4096      0.00\n20.294478                  24161   nullb0    R 32632      4096      0.00\n20.294479                  24161   nullb0    R 32640      4096      0.00\n20.294480                  24161   nullb0    R 32648      4096      0.00\n20.294481                  24161   nullb0    R 32656      4096      0.00\n20.294482                  24161   nullb0    R 32664      4096      0.00\n20.294484                  24161   nullb0    R 32672      4096      0.00\n20.294485                  24161   nullb0    R 32680      4096      0.00\n20.294486                  24161   nullb0    R 32688      4096      0.00\n20.294487                  24161   nullb0    R 32696      4096      0.00\n20.294488                  24161   nullb0    R 32704      4096      0.00\n20.294489                  24161   nullb0    R 32712      4096      0.00\n20.294490                  24161   nullb0    R 32720      4096      0.00\n20.294492                  24161   nullb0    R 32728      4096      0.00\n20.294493                  24161   nullb0    R 32736      4096      0.00\n20.294494                  24161   nullb0    R 32744      4096      0.00\n20.294495                  24161   nullb0    R 32752      4096      0.00\n20.294496                  24161   nullb0    R 32760      4096      0.00"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1401": {
        "avg_ns_per_run": 167.7471138731941,
        "bytes_jited": 662,
        "bytes_xlated": 1168,
        "id": 1401,
        "name": "sched_switch",
        "run_cnt_delta": 1551647,
        "run_time_ns_delta": 260284306,
        "type": "raw_tracepoint"
      },
      "1402": {
        "avg_ns_per_run": 110.35789541157516,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1402,
        "name": "sched_wakeup",
        "run_cnt_delta": 811237,
        "run_time_ns_delta": 89526408,
        "type": "raw_tracepoint"
      },
      "1403": {
        "avg_ns_per_run": 231.90521977209696,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1403,
        "name": "raw_tracepoint__sched_wakeup_new",
        "run_cnt_delta": 169107,
        "run_time_ns_delta": 39216796,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 65.72082809658788
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
        "avg_ns_per_run": 166.8751278699611,
        "bytes_jited": 645,
        "bytes_xlated": 1136,
        "id": 1401,
        "name": "sched_switch",
        "run_cnt_delta": 1520099,
        "run_time_ns_delta": 253666715,
        "type": "raw_tracepoint"
      },
      "1402": {
        "avg_ns_per_run": 115.78666314848576,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1402,
        "name": "sched_wakeup",
        "run_cnt_delta": 792076,
        "run_time_ns_delta": 91711837,
        "type": "raw_tracepoint"
      },
      "1403": {
        "avg_ns_per_run": 241.73193915175622,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1403,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 161911,
        "run_time_ns_delta": 39139060,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 62.89330131934153
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
  "stderr_tail": "In file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-47842j0c/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-47842j0c/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:6:\nIn file included from include/linux/pid_namespace.h:7:\nIn file included from include/linux/mm.h:1118:\nIn file included from include/linux/huge_mm.h:7:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "             8388608 -> 16777215             : 5041     |                    |\n            16777216 -> 33554431             : 0        |                    |\n            33554432 -> 67108863             : 0        |                    |\n            67108864 -> 134217727            : 0        |                    |\n           134217728 -> 268435455            : 0        |                    |\n           268435456 -> 536870911            : 4193     |                    |\n           536870912 -> 1073741823           : 4246     |                    |\n          1073741824 -> 2147483647           : 4193     |                    |\n          2147483648 -> 4294967295           : 3998     |                    |\n          4294967296 -> 8589934591           : 0        |                    |\n          8589934592 -> 17179869183          : 0        |                    |\n         17179869184 -> 34359738367          : 0        |                    |\n         34359738368 -> 68719476735          : 0        |                    |\n         68719476736 -> 137438953471         : 3417     |                    |\n        137438953472 -> 274877906943         : 3382     |                    |\n        274877906944 -> 549755813887         : 3292     |                    |\n        549755813888 -> 1099511627775        : 3172     |                    |\n       1099511627776 -> 2199023255551        : 0        |                    |\n       2199023255552 -> 4398046511103        : 0        |                    |\n       4398046511104 -> 8796093022207        : 0        |                    |\n       8796093022208 -> 17592186044415       : 0        |                    |\n      17592186044416 -> 35184372088831       : 2918     |                    |\n      35184372088832 -> 70368744177663       : 2782     |                    |\n      70368744177664 -> 140737488355327      : 2729     |                    |\n     140737488355328 -> 281474976710655      : 2783     |                    |\n     281474976710656 -> 562949953421311      : 0        |                    |\n     562949953421312 -> 1125899906842623     : 0        |                    |\n    1125899906842624 -> 2251799813685247     : 0        |                    |\n    2251799813685248 -> 4503599627370495     : 0        |                    |\n    4503599627370496 -> 9007199254740991     : 2590     |                    |\n    9007199254740992 -> 18014398509481983    : 2516     |                    |\n   18014398509481984 -> 36028797018963967    : 2474     |                    |\n   36028797018963968 -> 72057594037927935    : 2483     |                    |\n   72057594037927936 -> 144115188075855871   : 0        |                    |\n  144115188075855872 -> 288230376151711743   : 0        |                    |\n  288230376151711744 -> 576460752303423487   : 0        |                    |\n  576460752303423488 -> 1152921504606846975  : 0        |                    |\n 1152921504606846976 -> 2305843009213693951  : 2353     |                    |\n 2305843009213693952 -> 4611686018427387903  : 2477     |                    |\n 4611686018427387904 -> 9223372036854775807  : 2467     |                    |"
}
```

## syscount

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1408": {
        "avg_ns_per_run": 71.12787538489404,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1408,
        "name": "tracepoint__raw_syscalls__sys_enter",
        "run_cnt_delta": 66252,
        "run_time_ns_delta": 4712364,
        "type": "tracepoint"
      },
      "1409": {
        "avg_ns_per_run": 79.67854555334179,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1409,
        "name": "tracepoint__raw_syscalls__sys_exit",
        "run_cnt_delta": 66252,
        "run_time_ns_delta": 5278863,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1173.135208094396
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
        "avg_ns_per_run": 68.35943309634561,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1408,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 64279,
        "run_time_ns_delta": 4394076,
        "type": "tracepoint"
      },
      "1409": {
        "avg_ns_per_run": 76.24641018061887,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1409,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 64279,
        "run_time_ns_delta": 4901043,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1143.9170111086748
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-x5hi_t93/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-x5hi_t93/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "nanosleep                     2        20109.002\nioctl                      1082          204.358\nlseek                      1082          166.152\nclock_nanosleep              11      2000646.506\n[02:42:09]\nSYSCALL                   COUNT        TIME (us)\nfutex                         3      1078931.026\nread                          8      1000370.721\nopenat                     1174       745554.324\nepoll_pwait                   3       544528.621\nclose                      1174       148781.405\nfstat                      1174       101398.739\nnanosleep                     1        10054.008\nioctl                      1174          221.620\nlseek                      1174          180.993\nfutex                         9     12155064.077\n[02:42:10]\nSYSCALL                   COUNT        TIME (us)\nepoll_pwait                   8      6093278.031\nclock_nanosleep              11      2000734.228\nread                          1      1000502.196\nopenat                     1217       747230.846\nclose                      1217       150563.149\nfstat                      1217        98527.180\nnanosleep                     3        30143.212\nioctl                      1217          216.985\nlseek                      1217          178.278\nfutex                         9      4870566.909\n[02:42:11]\nSYSCALL                   COUNT        TIME (us)\nepoll_pwait                   9      2448591.024\nclock_nanosleep              10      1766384.568\nread                         16      1000394.031\nopenat                      982       598885.936\nclose                       998       120592.798\nfstat                       987        79269.120\nunlinkat                    256        60465.548\nnanosleep                     3        30176.400\ngetdents64                    2         1045.916\nDetaching..."
}
```

## execsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1412": {
        "avg_ns_per_run": 1305.8741819599543,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1412,
        "name": "syscall__execve",
        "run_cnt_delta": 35909,
        "run_time_ns_delta": 46892636,
        "type": "kprobe"
      },
      "1413": {
        "avg_ns_per_run": 876.4506391155421,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1413,
        "name": "do_ret_sys_execve",
        "run_cnt_delta": 35909,
        "run_time_ns_delta": 31472466,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1795.3022989307929
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
        "avg_ns_per_run": 1310.045465770339,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1412,
        "name": "syscall__execve",
        "run_cnt_delta": 36445,
        "run_time_ns_delta": 47744607,
        "type": "kprobe"
      },
      "1413": {
        "avg_ns_per_run": 877.9536287556592,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1413,
        "name": "do_ret_sys_exec",
        "run_cnt_delta": 36445,
        "run_time_ns_delta": 31997020,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1822.126046827842
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
  "stderr_tail": "<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-wr48lw_5/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-wr48lw_5/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "02:42:35 65534 true             3494    1735      0 /bin/true\n02:42:35 65534 true             3495    1735      0 /bin/true\n02:42:35 65534 true             3496    1735      0 /bin/true\n02:42:35 65534 true             3497    1735      0 /bin/true\n02:42:35 65534 true             3498    1735      0 /bin/true\n02:42:35 65534 true             3499    1735      0 /bin/true\n02:42:35 65534 true             3500    1735      0 /bin/true\n02:42:35 65534 true             3501    1735      0 /bin/true\n02:42:35 65534 true             3502    1735      0 /bin/true\n02:42:35 65534 true             3503    1735      0 /bin/true\n02:42:35 65534 true             3504    1735      0 /bin/true\n02:42:35 65534 true             3505    1735      0 /bin/true\n02:42:35 65534 true             3506    1735      0 /bin/true\n02:42:35 65534 true             3507    1735      0 /bin/true\n02:42:35 65534 true             3508    1735      0 /bin/true\n02:42:35 65534 true             3509    1735      0 /bin/true\n02:42:35 65534 true             3510    1735      0 /bin/true\n02:42:35 65534 true             3511    1735      0 /bin/true\n02:42:35 65534 true             3512    1735      0 /bin/true\n02:42:35 65534 true             3513    1735      0 /bin/true\n02:42:35 65534 true             3514    1735      0 /bin/true\n02:42:35 65534 true             3515    1735      0 /bin/true\n02:42:35 65534 true             3516    1735      0 /bin/true\n02:42:35 65534 true             3517    1735      0 /bin/true\n02:42:35 65534 true             3518    1735      0 /bin/true\n02:42:35 65534 true             3519    1735      0 /bin/true\n02:42:35 65534 true             3520    1735      0 /bin/true\n02:42:35 65534 true             3521    1735      0 /bin/true\n02:42:35 65534 true             3522    1735      0 /bin/true\n02:42:35 65534 true             3523    1735      0 /bin/true\n02:42:35 65534 true             3524    1735      0 /bin/true\n02:42:35 65534 true             3525    1735      0 /bin/true\n02:42:35 65534 true             3526    1735      0 /bin/true\n02:42:35 65534 true             3527    1735      0 /bin/true\n02:42:35 65534 true             3528    1735      0 /bin/true\n02:42:35 65534 true             3529    1735      0 /bin/true\n02:42:35 65534 true             3530    1735      0 /bin/true\n02:42:35 65534 true             3531    1735      0 /bin/true\n02:42:35 65534 true             3532    1735      0 /bin/true\n02:42:35 65534 true             3533    1735      0 /bin/true"
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
        "avg_ns_per_run": 2027.7270265390864,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1417,
        "name": "kretfunc__vmlinux____x64_sys_openat",
        "run_cnt_delta": 11078,
        "run_time_ns_delta": 22463160,
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
    "throughput": 1080.8779505221626
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
        "avg_ns_per_run": 1282.544997796386,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1417,
        "name": "__x64_sys_opena",
        "run_cnt_delta": 11345,
        "run_time_ns_delta": 14550473,
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
    "throughput": 1107.5485488321574
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-poxhsd95/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-poxhsd95/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-41.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-42.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-43.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-44.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-45.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-46.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-47.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-48.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-49.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-50.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-51.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-52.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-53.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-54.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-55.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-56.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-57.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-58.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-59.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-60.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-61.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-62.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-63.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-64.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-65.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-66.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk/open-67.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/loopback-open-storm-m1yvmwtk\n3567   bpftool             3   0 /etc/ld.so.cache\n3567   bpftool             3   0 /lib/x86_64-linux-gnu/libelf.so.1\n3567   bpftool             3   0 /lib/x86_64-linux-gnu/libcrypto.so.3\n3567   bpftool             3   0 /lib/x86_64-linux-gnu/libz.so.1\n3567   bpftool             3   0 /lib/x86_64-linux-gnu/libcap.so.2\n3567   bpftool             3   0 /lib/x86_64-linux-gnu/libc.so.6\n3567   bpftool             3   0 /lib/x86_64-linux-gnu/libzstd.so.1\n3567   bpftool             4   0 /etc/localtime\n3567   bpftool             4   0 /proc/self/fdinfo/3\n3567   bpftool             4   0 /proc/self/fdinfo/3\n3567   bpftool             4   0 /proc/self/fdinfo/3\n3567   bpftool             4   0 /proc/self/fdinfo/3"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1421": {
        "avg_ns_per_run": 40.41227454657932,
        "bytes_jited": 203,
        "bytes_xlated": 344,
        "id": 1421,
        "name": "cap_capable",
        "run_cnt_delta": 2744802,
        "run_time_ns_delta": 110923692,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 2396.9444216219144
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
        "avg_ns_per_run": 40.06419401577169,
        "bytes_jited": 206,
        "bytes_xlated": 344,
        "id": 1421,
        "name": "cap_capable",
        "run_cnt_delta": 2769012,
        "run_time_ns_delta": 110938234,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 2422.224350920977
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
  "stderr_tail": "  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-os_xfywe/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-os_xfywe/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\nIn file included from include/linux/security.h:9:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "02:43:26  65534  10813  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10814  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10815  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10816  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10817  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10818  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10819  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10810  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10807  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10808  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10839  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10809  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10842  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10822  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10833  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10843  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10844  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10827  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10828  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10834  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10835  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10836  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10837  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10838  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10829  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10830  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10831  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10832  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  65534  10845  stress-ng-exec   8    CAP_SETPCAP          1\n02:43:26  0      10854  bpftool          21   CAP_SYS_ADMIN        1\n02:43:26  0      10854  bpftool          21   CAP_SYS_ADMIN        1\n02:43:26  0      10854  bpftool          39   CAP_BPF              1\n02:43:26  0      10854  bpftool          21   CAP_SYS_ADMIN        1\n02:43:26  0      10854  bpftool          21   CAP_SYS_ADMIN        1\n02:43:26  0      10854  bpftool          39   CAP_BPF              1\n02:43:26  0      10854  bpftool          39   CAP_BPF              1\n02:43:26  0      10854  bpftool          39   CAP_BPF              1\n02:43:26  0      10854  bpftool          39   CAP_BPF              1\n02:43:26  0      10854  bpftool          21   CAP_SYS_ADMIN        1\n02:43:26  0      10854  bpftool          21   CAP_SYS_ADMIN        1"
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
        "avg_ns_per_run": 59.87898089171974,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1427,
        "name": "vfs_open",
        "run_cnt_delta": 785,
        "run_time_ns_delta": 47005,
        "type": "tracing"
      },
      "1428": {
        "avg_ns_per_run": 30.533810143042913,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1428,
        "name": "vfs_read",
        "run_cnt_delta": 1538,
        "run_time_ns_delta": 46961,
        "type": "tracing"
      },
      "1429": {
        "avg_ns_per_run": 38.79106438896189,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1429,
        "name": "vfs_write",
        "run_cnt_delta": 761,
        "run_time_ns_delta": 29520,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 75.74853737541368
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
        "avg_ns_per_run": 106.95731707317073,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1427,
        "name": "vfs_open",
        "run_cnt_delta": 820,
        "run_time_ns_delta": 87705,
        "type": "tracing"
      },
      "1428": {
        "avg_ns_per_run": 36.72129112352576,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1428,
        "name": "vfs_read",
        "run_cnt_delta": 1611,
        "run_time_ns_delta": 59158,
        "type": "tracing"
      },
      "1429": {
        "avg_ns_per_run": 45.431789737171464,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1429,
        "name": "vfs_write",
        "run_cnt_delta": 799,
        "run_time_ns_delta": 36300,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 79.21062327146855
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-zb8bb_bt/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-zb8bb_bt/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "TIME         READ/s  WRITE/s  FSYNC/s   OPEN/s CREATE/s\n02:43:29:      1487        5        0      132        0\n02:43:30:       101        6        0      130        0\n02:43:31:       160       63        0      112        0\n02:43:32:       149       75        0       74        0\n02:43:33:       146       73        0       73        0\n02:43:34:       156       78        0       78        0\n02:43:35:       150       74        0       75        0\n02:43:36:       152       76        0       76        0\n02:43:37:       156       79        0       78        0\n02:43:38:       154       77        0       77        0\n02:43:39:       154       77        0       77        0\n02:43:40:       156       78        0       78        0\n02:43:41:       146       46        0      115        0\n02:43:42:       158       79        0       79        0\n02:43:43:       153       77        0       76        0\n02:43:44:       160       79        0       80        0\n02:43:45:       174       88        0       87        0\n02:43:46:       162       81        0       81        0\n02:43:47:       162       80        0       81        0\n02:43:48:       150       76        0       75        0\n02:43:49:       165       83        0       82        0\n02:43:50:       151       76        0       75        0\n02:43:50:       116       49        0       74        0"
}
```

## tcpconnect

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1432": {
        "avg_ns_per_run": 719.4107241569928,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1432,
        "name": "trace_connect_entry",
        "run_cnt_delta": 3618,
        "run_time_ns_delta": 2602828,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 3772.6965174129355,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1433,
        "name": "trace_connect_v4_return",
        "run_cnt_delta": 1809,
        "run_time_ns_delta": 6824808,
        "type": "kprobe"
      },
      "1434": {
        "avg_ns_per_run": 3798.974018794914,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1434,
        "name": "trace_connect_v6_return",
        "run_cnt_delta": 1809,
        "run_time_ns_delta": 6872344,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 361.72880146260223
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
        "avg_ns_per_run": 717.4091922005571,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1432,
        "name": "trace_connect_e",
        "run_cnt_delta": 3590,
        "run_time_ns_delta": 2575499,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 4069.699721448468,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1433,
        "name": "trace_connect_v",
        "run_cnt_delta": 1795,
        "run_time_ns_delta": 7305111,
        "type": "kprobe"
      },
      "1434": {
        "avg_ns_per_run": 3966.0116991643454,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1434,
        "name": "trace_connect_v",
        "run_cnt_delta": 1795,
        "run_time_ns_delta": 7118991,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 358.96453886241056
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
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-iwwe6qi8/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:16:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "25264   curl         4  127.0.0.1        127.0.0.1        39637\n25266   curl         6  ::1              ::1              46803\n25268   curl         4  127.0.0.1        127.0.0.1        39637\n25270   curl         6  ::1              ::1              46803\n25272   curl         4  127.0.0.1        127.0.0.1        39637\n25274   curl         6  ::1              ::1              46803\n25276   curl         4  127.0.0.1        127.0.0.1        39637\n25278   curl         6  ::1              ::1              46803\n25280   curl         4  127.0.0.1        127.0.0.1        39637\n25282   curl         6  ::1              ::1              46803\n25284   curl         4  127.0.0.1        127.0.0.1        39637\n25286   curl         6  ::1              ::1              46803\n25288   curl         4  127.0.0.1        127.0.0.1        39637\n25290   curl         6  ::1              ::1              46803\n25292   curl         4  127.0.0.1        127.0.0.1        39637\n25294   curl         6  ::1              ::1              46803\n25296   curl         4  127.0.0.1        127.0.0.1        39637\n25298   curl         6  ::1              ::1              46803\n25300   curl         4  127.0.0.1        127.0.0.1        39637\n25302   curl         6  ::1              ::1              46803\n25304   curl         4  127.0.0.1        127.0.0.1        39637\n25306   curl         6  ::1              ::1              46803\n25308   curl         4  127.0.0.1        127.0.0.1        39637\n25310   curl         6  ::1              ::1              46803\n25312   curl         4  127.0.0.1        127.0.0.1        39637\n25314   curl         6  ::1              ::1              46803\n25316   curl         4  127.0.0.1        127.0.0.1        39637\n25318   curl         6  ::1              ::1              46803\n25320   curl         4  127.0.0.1        127.0.0.1        39637\n25322   curl         6  ::1              ::1              46803\n25324   curl         4  127.0.0.1        127.0.0.1        39637\n25326   curl         6  ::1              ::1              46803\n25328   curl         4  127.0.0.1        127.0.0.1        39637\n25330   curl         6  ::1              ::1              46803\n25332   curl         4  127.0.0.1        127.0.0.1        39637\n25334   curl         6  ::1              ::1              46803\n25336   curl         4  127.0.0.1        127.0.0.1        39637\n25338   curl         6  ::1              ::1              46803\n25340   curl         4  127.0.0.1        127.0.0.1        39637\n25342   curl         6  ::1              ::1              46803"
}
```

## bindsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1437": {
        "avg_ns_per_run": 60.578070812790855,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1437,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1988765,
        "run_time_ns_delta": 120475547,
        "type": "kprobe"
      },
      "1438": {
        "avg_ns_per_run": 832.2996813099178,
        "bytes_jited": 721,
        "bytes_xlated": 1160,
        "id": 1438,
        "name": "bindsnoop_v4_return",
        "run_cnt_delta": 994383,
        "run_time_ns_delta": 827624654,
        "type": "kprobe"
      },
      "1439": {
        "avg_ns_per_run": 777.7023296881882,
        "bytes_jited": 742,
        "bytes_xlated": 1184,
        "id": 1439,
        "name": "bindsnoop_v6_return",
        "run_cnt_delta": 994382,
        "run_time_ns_delta": 773333198,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 198876.4498234733
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
        "avg_ns_per_run": 57.48566821873634,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1437,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1990890,
        "run_time_ns_delta": 114447642,
        "type": "kprobe"
      },
      "1438": {
        "avg_ns_per_run": 833.589239988146,
        "bytes_jited": 719,
        "bytes_xlated": 1160,
        "id": 1438,
        "name": "bindsnoop_v4_re",
        "run_cnt_delta": 995445,
        "run_time_ns_delta": 829792241,
        "type": "kprobe"
      },
      "1439": {
        "avg_ns_per_run": 773.8407837700727,
        "bytes_jited": 740,
        "bytes_xlated": 1184,
        "id": 1439,
        "name": "bindsnoop_v6_re",
        "run_cnt_delta": 995445,
        "run_time_ns_delta": 770315939,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 199088.93292693712
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
  "stderr_tail": "In file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.8a2cedc0/bcc-python-ww7rvpcc/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:18:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.\nPossibly lost 219 samples\nPossibly lost 81 samples\nPossibly lost 30 samples",
  "stdout_tail": "    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0\n    1735 python3      IP   127.0.0.1       15296 ..NR.  0\n    1735 python3      IP   ::1             16064 ..NR.  0"
}
```

