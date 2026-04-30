# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-27T21:21:08.381233+00:00`
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
        "avg_ns_per_run": 1013.1570286120491,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1391,
        "name": "tracepoint__sock__inet_sock_set_state",
        "run_cnt_delta": 28135,
        "run_time_ns_delta": 28505173,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 255.82031470924608
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
        "avg_ns_per_run": 1082.2909552292913,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1391,
        "name": "sock__inet_sock",
        "run_cnt_delta": 27585,
        "run_time_ns_delta": 29854996,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 250.85410626634408
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
  "stderr_tail": "In file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-e62dyha3/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-e62dyha3/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/tcp.h:7:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "14336 curl       ::1             37069 ::1             39034     0     0 0.32\n14336 curl       ::1             39034 ::1             37069     0     0 0.34\n14338 curl       127.0.0.1       43411 127.0.0.1       60744     0     0 0.35\n14338 curl       127.0.0.1       60744 127.0.0.1       43411     0     0 0.37\n14340 curl       ::1             37069 ::1             39050     0     0 0.44\n14340 curl       ::1             39050 ::1             37069     0     0 0.45\n14342 curl       127.0.0.1       43411 127.0.0.1       60758     0     0 0.67\n14342 curl       127.0.0.1       60758 127.0.0.1       43411     0     0 0.69\n14344 curl       ::1             37069 ::1             39058     0     0 0.44\n14344 curl       ::1             39058 ::1             37069     0     0 0.46\n14346 curl       127.0.0.1       43411 127.0.0.1       60768     0     0 0.63\n14346 curl       127.0.0.1       60768 127.0.0.1       43411     0     0 0.65\n14348 curl       ::1             37069 ::1             39064     0     0 0.33\n14348 curl       ::1             39064 ::1             37069     0     0 0.35\n14350 curl       127.0.0.1       43411 127.0.0.1       60770     0     0 0.48\n14350 curl       127.0.0.1       60770 127.0.0.1       43411     0     0 0.49\n14352 curl       ::1             37069 ::1             39072     0     0 0.62\n14352 curl       ::1             39072 ::1             37069     0     0 0.64\n14354 curl       127.0.0.1       43411 127.0.0.1       60782     0     0 0.59\n14354 curl       127.0.0.1       60782 127.0.0.1       43411     0     0 0.61\n14356 curl       ::1             37069 ::1             39074     0     0 0.56\n14356 curl       ::1             39074 ::1             37069     0     0 0.58\n14358 curl       127.0.0.1       43411 127.0.0.1       60784     0     0 0.47\n14358 curl       127.0.0.1       60784 127.0.0.1       43411     0     0 0.49\n14360 curl       ::1             37069 ::1             39078     0     0 0.63\n14360 curl       ::1             39078 ::1             37069     0     0 0.65\n14362 curl       127.0.0.1       43411 127.0.0.1       60796     0     0 0.67\n14362 curl       127.0.0.1       60796 127.0.0.1       43411     0     0 0.69\n14364 curl       ::1             37069 ::1             39088     0     0 0.62\n14364 curl       ::1             39088 ::1             37069     0     0 0.64\n14366 curl       127.0.0.1       43411 127.0.0.1       60798     0     0 0.64\n14366 curl       127.0.0.1       60798 127.0.0.1       43411     0     0 0.66\n14368 curl       ::1             37069 ::1             39098     0     0 0.63\n14368 curl       ::1             39098 ::1             37069     0     0 0.65\n14370 curl       127.0.0.1       43411 127.0.0.1       60800     0     0 0.57\n14370 curl       127.0.0.1       60800 127.0.0.1       43411     0     0 0.58\n14372 curl       ::1             37069 ::1             39104     0     0 0.39\n14372 curl       ::1             39104 ::1             37069     0     0 0.41\n14374 curl       127.0.0.1       43411 127.0.0.1       60804     0     0 0.58\n14374 curl       127.0.0.1       60804 127.0.0.1       43411     0     0 0.60"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1394": {
        "avg_ns_per_run": 123.88559673071254,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1394,
        "name": "trace_pid_start_tp",
        "run_cnt_delta": 5644288,
        "run_time_ns_delta": 699245987,
        "type": "tracepoint"
      },
      "1395": {
        "avg_ns_per_run": 146.95226306666137,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1395,
        "name": "trace_req_start",
        "run_cnt_delta": 5644288,
        "run_time_ns_delta": 829440895,
        "type": "kprobe"
      },
      "1396": {
        "avg_ns_per_run": 342.58222206237525,
        "bytes_jited": 550,
        "bytes_xlated": 856,
        "id": 1396,
        "name": "trace_req_completion_tp",
        "run_cnt_delta": 5644288,
        "run_time_ns_delta": 1933632725,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 564337.923761197
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
        "avg_ns_per_run": 124.97579508135804,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1394,
        "name": "trace_pid_start",
        "run_cnt_delta": 5570562,
        "run_time_ns_delta": 696185415,
        "type": "tracepoint"
      },
      "1395": {
        "avg_ns_per_run": 152.11969183012707,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1395,
        "name": "trace_req_start",
        "run_cnt_delta": 5570564,
        "run_time_ns_delta": 847392479,
        "type": "kprobe"
      },
      "1396": {
        "avg_ns_per_run": 347.8333619659765,
        "bytes_jited": 548,
        "bytes_xlated": 848,
        "id": 1396,
        "name": "trace_req_compl",
        "run_cnt_delta": 5570565,
        "run_time_ns_delta": 1937628352,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 556232.9140117493
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
  "stderr_tail": "      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/blk-mq.h:5:\nIn file included from include/linux/blkdev.h:7:\nIn file included from include/linux/blk_types.h:7:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.\nPossibly lost 5 samples\nPossibly lost 7 samples\nPossibly lost 8 samples\nPossibly lost 19 samples\nPossibly lost 7 samples\nPossibly lost 8 samples\nPossibly lost 17 samples\nPossibly lost 9 samples\nPossibly lost 8 samples\nPossibly lost 8 samples\nPossibly lost 17 samples\nPossibly lost 9 samples\nPossibly lost 8 samples\nPossibly lost 8 samples\nPossibly lost 17 samples\nPossibly lost 9 samples\nPossibly lost 8 samples\nPossibly lost 18 samples\nPossibly lost 8 samples\nPossibly lost 8 samples\nPossibly lost 8 samples\nPossibly lost 18 samples\nPossibly lost 8 samples\nPossibly lost 6 samples\nException ignored on calling ctypes callback function: <function PerfEventArray._open_perf_buffer.<locals>.raw_cb_ at 0x7fc94c24f880>\nTraceback (most recent call last):\n  File \"/usr/lib/python3/dist-packages/bcc/table.py\", line 989, in raw_cb_\n    def raw_cb_(_, data, size):\nKeyboardInterrupt:",
  "stdout_tail": "20.236053                  17152   nullb0    R 32408      4096      0.00\n20.236055                  17152   nullb0    R 32416      4096      0.00\n20.236057                  17152   nullb0    R 32424      4096      0.00\n20.236059                  17152   nullb0    R 32432      4096      0.00\n20.236061                  17152   nullb0    R 32440      4096      0.00\n20.236062                  17152   nullb0    R 32448      4096      0.00\n20.236064                  17152   nullb0    R 32456      4096      0.00\n20.236066                  17152   nullb0    R 32464      4096      0.00\n20.236068                  17152   nullb0    R 32472      4096      0.00\n20.236069                  17152   nullb0    R 32480      4096      0.00\n20.236071                  17152   nullb0    R 32488      4096      0.00\n20.236073                  17152   nullb0    R 32496      4096      0.00\n20.236075                  17152   nullb0    R 32504      4096      0.00\n20.236076                  17152   nullb0    R 32512      4096      0.00\n20.236078                  17152   nullb0    R 32520      4096      0.00\n20.236080                  17152   nullb0    R 32528      4096      0.00\n20.236082                  17152   nullb0    R 32536      4096      0.00\n20.236083                  17152   nullb0    R 32544      4096      0.00\n20.236085                  17152   nullb0    R 32552      4096      0.00\n20.236087                  17152   nullb0    R 32560      4096      0.00\n20.236089                  17152   nullb0    R 32568      4096      0.00\n20.236090                  17152   nullb0    R 32576      4096      0.00\n20.236092                  17152   nullb0    R 32584      4096      0.00\n20.236094                  17152   nullb0    R 32592      4096      0.00\n20.236096                  17152   nullb0    R 32600      4096      0.00\n20.236097                  17152   nullb0    R 32608      4096      0.00\n20.236099                  17152   nullb0    R 32616      4096      0.00\n20.236101                  17152   nullb0    R 32624      4096      0.00\n20.236103                  17152   nullb0    R 32632      4096      0.00\n20.236104                  17152   nullb0    R 32640      4096      0.00\n20.236106                  17152   nullb0    R 32648      4096      0.00\n20.236108                  17152   nullb0    R 32656      4096      0.00\n20.236109                  17152   nullb0    R 32664      4096      0.00\n20.236151                  17152   nullb0    R 32672      4096      0.04\n20.236170                  17152   nullb0    R 32680      4096      0.00\n20.236172                  17152   nullb0    R 32688      4096      0.00\n20.236174                  17152   nullb0    R 32696      4096      0.00\n20.236176                  17152   nullb0    R 32704      4096      0.00\n20.236177                  17152   nullb0    R 32712      4096      0.00\n20.236179                  17152   nullb0    R 32720      4096"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1401": {
        "avg_ns_per_run": 227.4179911816103,
        "bytes_jited": 662,
        "bytes_xlated": 1168,
        "id": 1401,
        "name": "sched_switch",
        "run_cnt_delta": 1224033,
        "run_time_ns_delta": 278367126,
        "type": "raw_tracepoint"
      },
      "1402": {
        "avg_ns_per_run": 163.59674834666762,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1402,
        "name": "sched_wakeup",
        "run_cnt_delta": 668952,
        "run_time_ns_delta": 109438372,
        "type": "raw_tracepoint"
      },
      "1403": {
        "avg_ns_per_run": 358.2968705925299,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1403,
        "name": "raw_tracepoint__sched_wakeup_new",
        "run_cnt_delta": 120534,
        "run_time_ns_delta": 43186955,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 46.85984160308832
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
        "avg_ns_per_run": 229.17852781435877,
        "bytes_jited": 645,
        "bytes_xlated": 1136,
        "id": 1401,
        "name": "sched_switch",
        "run_cnt_delta": 1253687,
        "run_time_ns_delta": 287318141,
        "type": "raw_tracepoint"
      },
      "1402": {
        "avg_ns_per_run": 170.42515256236499,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1402,
        "name": "sched_wakeup",
        "run_cnt_delta": 688407,
        "run_time_ns_delta": 117321868,
        "type": "raw_tracepoint"
      },
      "1403": {
        "avg_ns_per_run": 368.01033420916104,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1403,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 119506,
        "run_time_ns_delta": 43979443,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 46.39713099075925
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
  "stderr_tail": "In file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-xhdzk3ht/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-xhdzk3ht/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:6:\nIn file included from include/linux/pid_namespace.h:7:\nIn file included from include/linux/mm.h:1118:\nIn file included from include/linux/huge_mm.h:7:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "             8388608 -> 16777215             : 4111     |                    |\n            16777216 -> 33554431             : 0        |                    |\n            33554432 -> 67108863             : 0        |                    |\n            67108864 -> 134217727            : 0        |                    |\n           134217728 -> 268435455            : 0        |                    |\n           268435456 -> 536870911            : 3478     |                    |\n           536870912 -> 1073741823           : 3237     |                    |\n          1073741824 -> 2147483647           : 3142     |                    |\n          2147483648 -> 4294967295           : 3042     |                    |\n          4294967296 -> 8589934591           : 0        |                    |\n          8589934592 -> 17179869183          : 0        |                    |\n         17179869184 -> 34359738367          : 0        |                    |\n         34359738368 -> 68719476735          : 0        |                    |\n         68719476736 -> 137438953471         : 2717     |                    |\n        137438953472 -> 274877906943         : 2765     |                    |\n        274877906944 -> 549755813887         : 2659     |                    |\n        549755813888 -> 1099511627775        : 2650     |                    |\n       1099511627776 -> 2199023255551        : 0        |                    |\n       2199023255552 -> 4398046511103        : 0        |                    |\n       4398046511104 -> 8796093022207        : 0        |                    |\n       8796093022208 -> 17592186044415       : 0        |                    |\n      17592186044416 -> 35184372088831       : 2444     |                    |\n      35184372088832 -> 70368744177663       : 2312     |                    |\n      70368744177664 -> 140737488355327      : 2314     |                    |\n     140737488355328 -> 281474976710655      : 2263     |                    |\n     281474976710656 -> 562949953421311      : 0        |                    |\n     562949953421312 -> 1125899906842623     : 0        |                    |\n    1125899906842624 -> 2251799813685247     : 0        |                    |\n    2251799813685248 -> 4503599627370495     : 0        |                    |\n    4503599627370496 -> 9007199254740991     : 1980     |                    |\n    9007199254740992 -> 18014398509481983    : 1902     |                    |\n   18014398509481984 -> 36028797018963967    : 1874     |                    |\n   36028797018963968 -> 72057594037927935    : 1923     |                    |\n   72057594037927936 -> 144115188075855871   : 0        |                    |\n  144115188075855872 -> 288230376151711743   : 0        |                    |\n  288230376151711744 -> 576460752303423487   : 0        |                    |\n  576460752303423488 -> 1152921504606846975  : 0        |                    |\n 1152921504606846976 -> 2305843009213693951  : 1652     |                    |\n 2305843009213693952 -> 4611686018427387903  : 1665     |                    |\n 4611686018427387904 -> 9223372036854775807  : 1572     |                    |"
}
```

## syscount

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1408": {
        "avg_ns_per_run": 113.6305941481529,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1408,
        "name": "tracepoint__raw_syscalls__sys_enter",
        "run_cnt_delta": 62476,
        "run_time_ns_delta": 7099185,
        "type": "tracepoint"
      },
      "1409": {
        "avg_ns_per_run": 136.08132722965618,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1409,
        "name": "tracepoint__raw_syscalls__sys_exit",
        "run_cnt_delta": 62476,
        "run_time_ns_delta": 8501817,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1107.5537431286689
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
        "avg_ns_per_run": 106.4413510182903,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1408,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 61672,
        "run_time_ns_delta": 6564451,
        "type": "tracepoint"
      },
      "1409": {
        "avg_ns_per_run": 149.2011771954858,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1409,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 61672,
        "run_time_ns_delta": 9201535,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1083.7900260971558
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-p6pl_udf/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-p6pl_udf/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "nanosleep                     1        10064.644\nioctl                      1137          448.155\nlseek                      1137          291.991\nfutex                         6      3569685.223\n[21:18:30]\nSYSCALL                   COUNT        TIME (us)\nclock_nanosleep              11      2000678.309\nepoll_pwait                   6      1795043.402\nread                          2      1000392.771\nopenat                     1082       739778.175\nclose                      1083       148404.853\nfstat                      1082       104405.384\nnanosleep                     2        20118.632\nioctl                      1082          434.480\nlseek                      1082          286.661\nfutex                         6     11781876.244\n[21:18:31]\nSYSCALL                   COUNT        TIME (us)\nepoll_pwait                   5      5901932.817\nclock_nanosleep              11      2000671.670\nread                          1      1000233.111\nopenat                     1010       746175.253\nclose                      1009       142255.900\nfstat                      1009       104787.953\nnanosleep                     2        20147.471\nioctl                      1009          411.273\nlseek                      1009          271.367\nclock_nanosleep              10      1872435.703\n[21:18:32]\nSYSCALL                   COUNT        TIME (us)\nfutex                         3      1785166.712\nread                         17      1000135.605\nepoll_pwait                   3       897274.481\nopenat                      945       669639.456\nclose                       962       129087.270\nfstat                       951        95622.780\nunlinkat                    256        66128.279\nnanosleep                     1        10056.382\ngetdents64                    2         1958.211\nDetaching..."
}
```

## execsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1412": {
        "avg_ns_per_run": 2249.2532656943563,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1412,
        "name": "syscall__execve",
        "run_cnt_delta": 23655,
        "run_time_ns_delta": 53206086,
        "type": "kprobe"
      },
      "1413": {
        "avg_ns_per_run": 1087.3169308814204,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1413,
        "name": "do_ret_sys_execve",
        "run_cnt_delta": 23655,
        "run_time_ns_delta": 25720482,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1182.6336868908522
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
        "avg_ns_per_run": 2097.1464327866183,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1412,
        "name": "syscall__execve",
        "run_cnt_delta": 24571,
        "run_time_ns_delta": 51528985,
        "type": "kprobe"
      },
      "1413": {
        "avg_ns_per_run": 1070.4074722233527,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1413,
        "name": "do_ret_sys_exec",
        "run_cnt_delta": 24571,
        "run_time_ns_delta": 26300982,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1228.4236620683791
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
  "stderr_tail": "<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-oo11l8qq/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-oo11l8qq/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "21:18:57 65534 true             22731   1735      0 /bin/true\n21:18:57 65534 true             22732   1735      0 /bin/true\n21:18:57 65534 true             22733   1735      0 /bin/true\n21:18:57 65534 true             22734   1735      0 /bin/true\n21:18:57 65534 true             22735   1735      0 /bin/true\n21:18:57 65534 true             22736   1735      0 /bin/true\n21:18:57 65534 true             22737   1735      0 /bin/true\n21:18:57 65534 true             22738   1735      0 /bin/true\n21:18:57 65534 true             22739   1735      0 /bin/true\n21:18:57 65534 true             22740   1735      0 /bin/true\n21:18:57 65534 true             22741   1735      0 /bin/true\n21:18:57 65534 true             22742   1735      0 /bin/true\n21:18:57 65534 true             22743   1735      0 /bin/true\n21:18:57 65534 true             22744   1735      0 /bin/true\n21:18:57 65534 true             22745   1735      0 /bin/true\n21:18:57 65534 true             22746   1735      0 /bin/true\n21:18:57 65534 true             22747   1735      0 /bin/true\n21:18:57 65534 true             22748   1735      0 /bin/true\n21:18:57 65534 true             22749   1735      0 /bin/true\n21:18:57 65534 true             22750   1735      0 /bin/true\n21:18:57 65534 true             22751   1735      0 /bin/true\n21:18:57 65534 true             22752   1735      0 /bin/true\n21:18:57 65534 true             22753   1735      0 /bin/true\n21:18:57 65534 true             22754   1735      0 /bin/true\n21:18:57 65534 true             22755   1735      0 /bin/true\n21:18:57 65534 true             22756   1735      0 /bin/true\n21:18:57 65534 true             22757   1735      0 /bin/true\n21:18:57 65534 true             22758   1735      0 /bin/true\n21:18:57 65534 true             22759   1735      0 /bin/true\n21:18:57 65534 true             22760   1735      0 /bin/true\n21:18:57 65534 true             22761   1735      0 /bin/true\n21:18:57 65534 true             22762   1735      0 /bin/true\n21:18:57 65534 true             22763   1735      0 /bin/true\n21:18:57 65534 true             22764   1735      0 /bin/true\n21:18:57 65534 true             22765   1735      0 /bin/true\n21:18:57 65534 true             22766   1735      0 /bin/true\n21:18:57 65534 true             22767   1735      0 /bin/true\n21:18:57 65534 true             22768   1735      0\n21:18:57 65534 true             22769   1735      0 /bin/true\n21:18:57 65534 true             22770   1735      0 /bin/true"
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
        "avg_ns_per_run": 1846.2267712227592,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1417,
        "name": "kretfunc__vmlinux____x64_sys_openat",
        "run_cnt_delta": 10967,
        "run_time_ns_delta": 20247569,
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
    "throughput": 1069.7831882502248
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
        "avg_ns_per_run": 1815.683692637982,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1417,
        "name": "__x64_sys_opena",
        "run_cnt_delta": 11179,
        "run_time_ns_delta": 20297528,
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
    "throughput": 1090.9431602249372
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-ieb1i1m_/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-ieb1i1m_/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-131.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-132.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-133.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-134.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-135.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-136.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-137.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-138.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-139.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-140.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-141.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-142.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-143.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-144.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-145.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-146.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-147.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-148.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-149.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-150.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-151.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-152.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-153.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-154.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-155.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-156.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h/open-157.dat\n1735   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/loopback-open-storm-83xryv2h\n22804  bpftool             3   0 /etc/ld.so.cache\n22804  bpftool             3   0 /lib/x86_64-linux-gnu/libelf.so.1\n22804  bpftool             3   0 /lib/x86_64-linux-gnu/libcrypto.so.3\n22804  bpftool             3   0 /lib/x86_64-linux-gnu/libz.so.1\n22804  bpftool             3   0 /lib/x86_64-linux-gnu/libcap.so.2\n22804  bpftool             3   0 /lib/x86_64-linux-gnu/libc.so.6\n22804  bpftool             3   0 /lib/x86_64-linux-gnu/libzstd.so.1\n22804  bpftool             4   0 /etc/localtime\n22804  bpftool             4   0 /proc/self/fdinfo/3\n22804  bpftool             4   0 /proc/self/fdinfo/3\n22804  bpftool             4   0 /proc/self/fdinfo/3\n22804  bpftool             4   0 /proc/self/fdinfo/3"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1421": {
        "avg_ns_per_run": 45.04731723996321,
        "bytes_jited": 203,
        "bytes_xlated": 344,
        "id": 1421,
        "name": "cap_capable",
        "run_cnt_delta": 2225637,
        "run_time_ns_delta": 100258976,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1947.4013034744153
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
        "avg_ns_per_run": 44.27233483383734,
        "bytes_jited": 206,
        "bytes_xlated": 344,
        "id": 1421,
        "name": "cap_capable",
        "run_cnt_delta": 2257908,
        "run_time_ns_delta": 99962859,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1980.7201672877616
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
  "stderr_tail": "  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-21dstyl4/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-21dstyl4/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\nIn file included from include/linux/security.h:9:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "21:19:49  65534  17492  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17493  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17530  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17545  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17546  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17551  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17552  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17553  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17547  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17554  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17555  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17556  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17557  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17558  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17548  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17559  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17560  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17561  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17564  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17565  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17562  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17563  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17549  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17567  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17566  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17569  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17568  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17570  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  65534  17550  stress-ng-exec   8    CAP_SETPCAP          1\n21:19:49  0      17589  bpftool          21   CAP_SYS_ADMIN        1\n21:19:49  0      17589  bpftool          21   CAP_SYS_ADMIN        1\n21:19:49  0      17589  bpftool          39   CAP_BPF              1\n21:19:49  0      17589  bpftool          21   CAP_SYS_ADMIN        1\n21:19:49  0      17589  bpftool          21   CAP_SYS_ADMIN        1\n21:19:49  0      17589  bpftool          39   CAP_BPF              1\n21:19:49  0      17589  bpftool          39   CAP_BPF              1\n21:19:49  0      17589  bpftool          39   CAP_BPF              1\n21:19:49  0      17589  bpftool          39   CAP_BPF              1\n21:19:49  0      17589  bpftool          21   CAP_SYS_ADMIN        1\n21:19:49  0      17589  bpftool          21   CAP_SYS_ADMIN        1"
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
        "avg_ns_per_run": 289.51362683438157,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1427,
        "name": "vfs_open",
        "run_cnt_delta": 954,
        "run_time_ns_delta": 276196,
        "type": "tracing"
      },
      "1428": {
        "avg_ns_per_run": 99.84291799787007,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1428,
        "name": "vfs_read",
        "run_cnt_delta": 1878,
        "run_time_ns_delta": 187505,
        "type": "tracing"
      },
      "1429": {
        "avg_ns_per_run": 86.22317596566523,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1429,
        "name": "vfs_write",
        "run_cnt_delta": 932,
        "run_time_ns_delta": 80360,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 92.63859323932306
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
        "avg_ns_per_run": 271.6666666666667,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1427,
        "name": "vfs_open",
        "run_cnt_delta": 984,
        "run_time_ns_delta": 267320,
        "type": "tracing"
      },
      "1428": {
        "avg_ns_per_run": 99.5792462570986,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1428,
        "name": "vfs_read",
        "run_cnt_delta": 1937,
        "run_time_ns_delta": 192885,
        "type": "tracing"
      },
      "1429": {
        "avg_ns_per_run": 103.44432882414152,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1429,
        "name": "vfs_write",
        "run_cnt_delta": 961,
        "run_time_ns_delta": 99410,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 95.69500323755847
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-en6l9ojb/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-en6l9ojb/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "TIME         READ/s  WRITE/s  FSYNC/s   OPEN/s CREATE/s\n21:19:52:      1488        6        0      132        0\n21:19:53:       100        5        0      130        0\n21:19:54:       208       88        0      135        0\n21:19:55:       185       93        0       92        0\n21:19:56:       197       98        0       98        0\n21:19:57:       177       89        0       89        0\n21:19:58:       181       91        0       90        0\n21:19:59:       182       91        0       91        0\n21:20:00:       188       93        0       94        0\n21:20:01:       178       89        0       89        0\n21:20:02:       194       98        0       97        0\n21:20:03:       182       90        0       91        0\n21:20:04:       160       53        0      123        0\n21:20:05:       189       95        0       94        0\n21:20:06:       198       99        0       99        0\n21:20:07:       203      102        0      101        0\n21:20:08:       202      101        0      101        0\n21:20:09:       194       97        0       97        0\n21:20:10:       182       91        0       91        0\n21:20:11:       188       94        0       94        0\n21:20:12:       183       92        0       91        0\n21:20:13:       186       93        0       93        0\n21:20:13:       138       59        0       86        0"
}
```

## tcpconnect

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1432": {
        "avg_ns_per_run": 1950.7270955165693,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1432,
        "name": "trace_connect_entry",
        "run_cnt_delta": 2565,
        "run_time_ns_delta": 5003615,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 7425.26890101325,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1433,
        "name": "trace_connect_v4_return",
        "run_cnt_delta": 1283,
        "run_time_ns_delta": 9526620,
        "type": "kprobe"
      },
      "1434": {
        "avg_ns_per_run": 7175.36271450858,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1434,
        "name": "trace_connect_v6_return",
        "run_cnt_delta": 1282,
        "run_time_ns_delta": 9198815,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 256.4115734432417
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
        "avg_ns_per_run": 2124.529503712388,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1432,
        "name": "trace_connect_e",
        "run_cnt_delta": 2559,
        "run_time_ns_delta": 5436671,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 7878.240625,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1433,
        "name": "trace_connect_v",
        "run_cnt_delta": 1280,
        "run_time_ns_delta": 10084148,
        "type": "kprobe"
      },
      "1434": {
        "avg_ns_per_run": 7772.877247849883,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1434,
        "name": "trace_connect_v",
        "run_cnt_delta": 1279,
        "run_time_ns_delta": 9941510,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 255.82070213134645
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
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.05d33542/bcc-python-xyhyrq6l/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:16:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "27825   curl         6  ::1              ::1              35087\n27827   curl         4  127.0.0.1        127.0.0.1        40431\n27829   curl         6  ::1              ::1              35087\n27831   curl         4  127.0.0.1        127.0.0.1        40431\n27833   curl         6  ::1              ::1              35087\n27835   curl         4  127.0.0.1        127.0.0.1        40431\n27837   curl         6  ::1              ::1              35087\n27839   curl         4  127.0.0.1        127.0.0.1        40431\n27841   curl         6  ::1              ::1              35087\n27843   curl         4  127.0.0.1        127.0.0.1        40431\n27845   curl         6  ::1              ::1              35087\n27847   curl         4  127.0.0.1        127.0.0.1        40431\n27849   curl         6  ::1              ::1              35087\n27851   curl         4  127.0.0.1        127.0.0.1        40431\n27853   curl         6  ::1              ::1              35087\n27855   curl         4  127.0.0.1        127.0.0.1        40431\n27857   curl         6  ::1              ::1              35087\n27859   curl         4  127.0.0.1        127.0.0.1        40431\n27861   curl         6  ::1              ::1              35087\n27863   curl         4  127.0.0.1        127.0.0.1        40431\n27865   curl         6  ::1              ::1              35087\n27867   curl         4  127.0.0.1        127.0.0.1        40431\n27869   curl         6  ::1              ::1              35087\n27871   curl         4  127.0.0.1        127.0.0.1        40431\n27873   curl         6  ::1              ::1              35087\n27875   curl         4  127.0.0.1        127.0.0.1        40431\n27877   curl         6  ::1              ::1              35087\n27879   curl         4  127.0.0.1        127.0.0.1        40431\n27881   curl         6  ::1              ::1              35087\n27883   curl         4  127.0.0.1        127.0.0.1        40431\n27885   curl         6  ::1              ::1              35087\n27887   curl         4  127.0.0.1        127.0.0.1        40431\n27889   curl         6  ::1              ::1              35087\n27891   curl         4  127.0.0.1        127.0.0.1        40431\n27893   curl         6  ::1              ::1              35087\n27895   curl         4  127.0.0.1        127.0.0.1        40431\n27897   curl         6  ::1              ::1              35087\n27899   curl         4  127.0.0.1        127.0.0.1        40431\n27901   curl         6  ::1              ::1              35087\n27903   curl         4  127.0.0.1        127.0.0.1        40431"
}
```

## bindsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1437": {
        "avg_ns_per_run": 73.2427541055745,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1437,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1599837,
        "run_time_ns_delta": 117176468,
        "type": "kprobe"
      },
      "1438": {
        "avg_ns_per_run": 796.0926943853065,
        "bytes_jited": 721,
        "bytes_xlated": 1160,
        "id": 1438,
        "name": "bindsnoop_v4_return",
        "run_cnt_delta": 799919,
        "run_time_ns_delta": 636809672,
        "type": "kprobe"
      },
      "1439": {
        "avg_ns_per_run": 774.6612940326384,
        "bytes_jited": 742,
        "bytes_xlated": 1184,
        "id": 1439,
        "name": "bindsnoop_v6_return",
        "run_cnt_delta": 799918,
        "run_time_ns_delta": 619665513,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 159983.61373683834
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
        "avg_ns_per_run": 83.99633888541065,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1437,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1467859,
        "run_time_ns_delta": 123294782,
        "type": "kprobe"
      },
      "1438": {
        "avg_ns_per_run": 822.8877372501464,
        "bytes_jited": 719,
        "bytes_xlated": 1160,
        "id": 1438,
        "name": "bindsnoop_v4_re",
        "run_cnt_delta": 733930,
        "run_time_ns_delta": 603941997,
        "type": "kprobe"
      },
      "1439": {
        "avg_ns_per_run": 791.3210147030571,
        "bytes_jited": 740,
        "bytes_xlated": 1184,
        "id": 1439,
        "name": "bindsnoop_v6_re",
        "run_cnt_delta": 733929,
        "run_time_ns_delta": 580773441,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 146785.8513404909
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
  "stderr_tail": "Possibly lost 4 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 4 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 5 samples\nPossibly lost 3 samples\nPossibly lost 2 samples\nPossibly lost 4 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 5 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 5 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 5 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 4 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 4 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 5 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 4 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 4 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 4 samples\nPossibly lost 870 samples\nPossibly lost 278 samples\nPossibly lost 57 samples",
  "stdout_tail": "    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0\n    1735 python3      IP   ::1             10880 ..NR.  0\n    1735 python3      IP   127.0.0.1       10112 ..NR.  0"
}
```

