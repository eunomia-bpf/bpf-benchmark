# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-27T02:15:15.281665+00:00`
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
        "avg_ns_per_run": 1197.9258748227358,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1391,
        "name": "tracepoint__sock__inet_sock_set_state",
        "run_cnt_delta": 26091,
        "run_time_ns_delta": 31255084,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 237.15183377482217,
    "workload_miss": false
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
        "avg_ns_per_run": 1200.7622916267485,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1391,
        "name": "sock__inet_sock",
        "run_cnt_delta": 26095,
        "run_time_ns_delta": 31333892,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 237.21702075077013,
    "workload_miss": false
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
  "stderr_tail": "In file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-64em8704/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-64em8704/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/tcp.h:7:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "10441 curl       ::1             41875 ::1             35424     0     0 0.65\n10441 curl       ::1             35424 ::1             41875     0     0 0.67\n10443 curl       127.0.0.1       43211 127.0.0.1       54282     0     0 0.75\n10443 curl       127.0.0.1       54282 127.0.0.1       43211     0     0 0.79\n10445 curl       ::1             41875 ::1             35426     0     0 0.73\n10445 curl       ::1             35426 ::1             41875     0     0 0.75\n10447 curl       127.0.0.1       43211 127.0.0.1       54298     0     0 0.58\n10447 curl       127.0.0.1       54298 127.0.0.1       43211     0     0 0.60\n10449 curl       ::1             41875 ::1             35430     0     0 0.37\n10449 curl       ::1             35430 ::1             41875     0     0 0.39\n10451 curl       127.0.0.1       43211 127.0.0.1       54306     0     0 0.38\n10451 curl       127.0.0.1       54306 127.0.0.1       43211     0     0 0.40\n10453 curl       ::1             41875 ::1             35434     0     0 0.68\n10453 curl       ::1             35434 ::1             41875     0     0 0.70\n10455 curl       127.0.0.1       43211 127.0.0.1       54318     0     0 0.65\n10455 curl       127.0.0.1       54318 127.0.0.1       43211     0     0 0.67\n10457 curl       ::1             41875 ::1             35448     0     0 0.57\n10457 curl       ::1             35448 ::1             41875     0     0 0.59\n10459 curl       127.0.0.1       43211 127.0.0.1       54334     0     0 0.47\n10459 curl       127.0.0.1       54334 127.0.0.1       43211     0     0 0.49\n10461 curl       ::1             41875 ::1             35458     0     0 0.63\n10461 curl       ::1             35458 ::1             41875     0     0 0.65\n10463 curl       127.0.0.1       43211 127.0.0.1       54348     0     0 0.52\n10463 curl       127.0.0.1       54348 127.0.0.1       43211     0     0 0.54\n10465 curl       ::1             41875 ::1             35466     0     0 0.68\n10465 curl       ::1             35466 ::1             41875     0     0 0.70\n10467 curl       127.0.0.1       43211 127.0.0.1       54362     0     0 0.64\n10467 curl       127.0.0.1       54362 127.0.0.1       43211     0     0 0.66\n10469 curl       ::1             41875 ::1             35474     0     0 0.62\n10469 curl       ::1             35474 ::1             41875     0     0 0.64\n10471 curl       127.0.0.1       43211 127.0.0.1       54368     0     0 0.51\n10471 curl       127.0.0.1       54368 127.0.0.1       43211     0     0 0.53\n10473 curl       ::1             41875 ::1             35484     0     0 0.76\n10473 curl       ::1             35484 ::1             41875     0     0 0.78\n10475 curl       127.0.0.1       43211 127.0.0.1       54374     0     0 0.67\n10475 curl       127.0.0.1       54374 127.0.0.1       43211     0     0 0.69\n10477 curl       ::1             41875 ::1             35496     0     0 0.74\n10477 curl       ::1             35496 ::1             41875     0     0 0.76\n10479 curl       127.0.0.1       43211 127.0.0.1       54390     0     0 0.58\n10479 curl       127.0.0.1       54390 127.0.0.1       43211     0     0 0.60"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1394": {
        "avg_ns_per_run": 133.4383237045423,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1394,
        "name": "trace_pid_start_tp",
        "run_cnt_delta": 5554176,
        "run_time_ns_delta": 741139935,
        "type": "tracepoint"
      },
      "1395": {
        "avg_ns_per_run": 154.77923800038025,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1395,
        "name": "trace_req_start",
        "run_cnt_delta": 5554176,
        "run_time_ns_delta": 859671129,
        "type": "kprobe"
      },
      "1396": {
        "avg_ns_per_run": 343.8823575270211,
        "bytes_jited": 550,
        "bytes_xlated": 856,
        "id": 1396,
        "name": "trace_req_completion_tp",
        "run_cnt_delta": 5554176,
        "run_time_ns_delta": 1909983137,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 555044.6467413433,
    "workload_miss": false
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
        "avg_ns_per_run": 130.8732790336056,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1394,
        "name": "trace_pid_start",
        "run_cnt_delta": 5570562,
        "run_time_ns_delta": 729037715,
        "type": "tracepoint"
      },
      "1395": {
        "avg_ns_per_run": 154.58810292817748,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1395,
        "name": "trace_req_start",
        "run_cnt_delta": 5570564,
        "run_time_ns_delta": 861142921,
        "type": "kprobe"
      },
      "1396": {
        "avg_ns_per_run": 351.25931498869505,
        "bytes_jited": 548,
        "bytes_xlated": 848,
        "id": 1396,
        "name": "trace_req_compl",
        "run_cnt_delta": 5570565,
        "run_time_ns_delta": 1956712846,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 556476.2274517679,
    "workload_miss": false
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
  "stderr_tail": "Possibly lost 4 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nException ignored on calling ctypes callback function: <function PerfEventArray._open_perf_buffer.<locals>.raw_cb_ at 0x7f7fabd47880>\nTraceback (most recent call last):\n  File \"/usr/lib/python3/dist-packages/bcc/table.py\", line 991, in raw_cb_\n    callback(cpu, data, size)\n  File \"/usr/sbin/biosnoop-bpfcc\", line 393, in print_event\n    event = b[\"events\"].event(data)\n            ^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/usr/lib/python3/dist-packages/bcc/table.py\", line 970, in event\n    return ct.cast(data, ct.POINTER(self._event_class)).contents\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/usr/lib/python3.12/ctypes/__init__.py\", line 518, in cast\n    return _cast(obj, obj, typ)\n           ^^^^^^^^^^^^^^^^^^^^\nKeyboardInterrupt:",
  "stdout_tail": "20.309085                  13267   nullb0    R 32352      4096      0.00\n20.309087                  13267   nullb0    R 32360      4096      0.00\n20.309089                  13267   nullb0    R 32368      4096      0.00\n20.309090                  13267   nullb0    R 32376      4096      0.00\n20.309092                  13267   nullb0    R 32384      4096      0.00\n20.309094                  13267   nullb0    R 32392      4096      0.00\n20.309096                  13267   nullb0    R 32400      4096      0.00\n20.309098                  13267   nullb0    R 32408      4096      0.00\n20.309100                  13267   nullb0    R 32416      4096      0.00\n20.309102                  13267   nullb0    R 32424      4096      0.00\n20.309103                  13267   nullb0    R 32432      4096      0.00\n20.309105                  13267   nullb0    R 32440      4096      0.00\n20.309107                  13267   nullb0    R 32448      4096      0.00\n20.309108                  13267   nullb0    R 32456      4096      0.00\n20.309110                  13267   nullb0    R 32464      4096      0.00\n20.309112                  13267   nullb0    R 32472      4096      0.00\n20.309114                  13267   nullb0    R 32480      4096      0.00\n20.309115                  13267   nullb0    R 32488      4096      0.00\n20.309117                  13267   nullb0    R 32496      4096      0.00\n20.309119                  13267   nullb0    R 32504      4096      0.00\n20.309121                  13267   nullb0    R 32512      4096      0.00\n20.309122                  13267   nullb0    R 32520      4096      0.00\n20.309124                  13267   nullb0    R 32528      4096      0.00\n20.309126                  13267   nullb0    R 32536      4096      0.00\n20.309128                  13267   nullb0    R 32544      4096      0.00\n20.309129                  13267   nullb0    R 32552      4096      0.00\n20.309131                  13267   nullb0    R 32560      4096      0.00\n20.309133                  13267   nullb0    R 32568      4096      0.00\n20.309135                  13267   nullb0    R 32576      4096      0.00\n20.309137                  13267   nullb0    R 32584      4096      0.00\n20.309138                  13267   nullb0    R 32592      4096      0.00\n20.309140                  13267   nullb0    R 32600      4096      0.00\n20.309142                  13267   nullb0    R 32608      4096      0.00\n20.309144                  13267   nullb0    R 32616      4096      0.00\n20.309146                  13267   nullb0    R 32624      4096      0.00\n20.309147                  13267   nullb0    R 32632      4096      0.00\n20.309149                  13267   nullb0    R 32640      4096      0.00\n20.309151                  13267   nullb0    R 32648      4096      0.00\n20.309153                  13267   nullb0    R 32656      4096      0.00\n20.309154                  13267   nullb0    R 32664      4096"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1401": {
        "avg_ns_per_run": 241.69442177835097,
        "bytes_jited": 662,
        "bytes_xlated": 1168,
        "id": 1401,
        "name": "sched_switch",
        "run_cnt_delta": 1156892,
        "run_time_ns_delta": 279614343,
        "type": "raw_tracepoint"
      },
      "1402": {
        "avg_ns_per_run": 171.19902037761676,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1402,
        "name": "sched_wakeup",
        "run_cnt_delta": 625343,
        "run_time_ns_delta": 107058109,
        "type": "raw_tracepoint"
      },
      "1403": {
        "avg_ns_per_run": 374.9200541657025,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1403,
        "name": "raw_tracepoint__sched_wakeup_new",
        "run_cnt_delta": 116679,
        "run_time_ns_delta": 43745297,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 45.30599942500458,
    "workload_miss": false
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
        "avg_ns_per_run": 236.39247496321235,
        "bytes_jited": 645,
        "bytes_xlated": 1136,
        "id": 1401,
        "name": "sched_switch",
        "run_cnt_delta": 1203529,
        "run_time_ns_delta": 284505199,
        "type": "raw_tracepoint"
      },
      "1402": {
        "avg_ns_per_run": 173.46178392640618,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1402,
        "name": "sched_wakeup",
        "run_cnt_delta": 660599,
        "run_time_ns_delta": 114588681,
        "type": "raw_tracepoint"
      },
      "1403": {
        "avg_ns_per_run": 378.0869138504564,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1403,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 115137,
        "run_time_ns_delta": 43531793,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 44.75395107097706,
    "workload_miss": false
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
  "stderr_tail": "In file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-erwt8iu3/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-erwt8iu3/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:6:\nIn file included from include/linux/pid_namespace.h:7:\nIn file included from include/linux/mm.h:1118:\nIn file included from include/linux/huge_mm.h:7:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "             8388608 -> 16777215             : 3967     |                    |\n            16777216 -> 33554431             : 0        |                    |\n            33554432 -> 67108863             : 0        |                    |\n            67108864 -> 134217727            : 0        |                    |\n           134217728 -> 268435455            : 0        |                    |\n           268435456 -> 536870911            : 3180     |                    |\n           536870912 -> 1073741823           : 3047     |                    |\n          1073741824 -> 2147483647           : 3006     |                    |\n          2147483648 -> 4294967295           : 2870     |                    |\n          4294967296 -> 8589934591           : 0        |                    |\n          8589934592 -> 17179869183          : 0        |                    |\n         17179869184 -> 34359738367          : 0        |                    |\n         34359738368 -> 68719476735          : 0        |                    |\n         68719476736 -> 137438953471         : 2693     |                    |\n        137438953472 -> 274877906943         : 2654     |                    |\n        274877906944 -> 549755813887         : 2610     |                    |\n        549755813888 -> 1099511627775        : 2541     |                    |\n       1099511627776 -> 2199023255551        : 0        |                    |\n       2199023255552 -> 4398046511103        : 0        |                    |\n       4398046511104 -> 8796093022207        : 0        |                    |\n       8796093022208 -> 17592186044415       : 0        |                    |\n      17592186044416 -> 35184372088831       : 2346     |                    |\n      35184372088832 -> 70368744177663       : 2312     |                    |\n      70368744177664 -> 140737488355327      : 2283     |                    |\n     140737488355328 -> 281474976710655      : 2322     |                    |\n     281474976710656 -> 562949953421311      : 0        |                    |\n     562949953421312 -> 1125899906842623     : 0        |                    |\n    1125899906842624 -> 2251799813685247     : 0        |                    |\n    2251799813685248 -> 4503599627370495     : 0        |                    |\n    4503599627370496 -> 9007199254740991     : 2061     |                    |\n    9007199254740992 -> 18014398509481983    : 2002     |                    |\n   18014398509481984 -> 36028797018963967    : 1899     |                    |\n   36028797018963968 -> 72057594037927935    : 1883     |                    |\n   72057594037927936 -> 144115188075855871   : 0        |                    |\n  144115188075855872 -> 288230376151711743   : 0        |                    |\n  288230376151711744 -> 576460752303423487   : 0        |                    |\n  576460752303423488 -> 1152921504606846975  : 0        |                    |\n 1152921504606846976 -> 2305843009213693951  : 1720     |                    |\n 2305843009213693952 -> 4611686018427387903  : 1613     |                    |\n 4611686018427387904 -> 9223372036854775807  : 1597     |                    |"
}
```

## syscount

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1408": {
        "avg_ns_per_run": 108.30482291483618,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1408,
        "name": "tracepoint__raw_syscalls__sys_enter",
        "run_cnt_delta": 62597,
        "run_time_ns_delta": 6779557,
        "type": "tracepoint"
      },
      "1409": {
        "avg_ns_per_run": 145.93891081042221,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1409,
        "name": "tracepoint__raw_syscalls__sys_exit",
        "run_cnt_delta": 62597,
        "run_time_ns_delta": 9135338,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 1108.9149953447766,
    "workload_miss": false
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
        "avg_ns_per_run": 115.11121662109727,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1408,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 61079,
        "run_time_ns_delta": 7030878,
        "type": "tracepoint"
      },
      "1409": {
        "avg_ns_per_run": 146.64947035806088,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1409,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 61079,
        "run_time_ns_delta": 8957203,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 1070.318241065377,
    "workload_miss": false
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-ny6p1_vr/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-ny6p1_vr/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "nanosleep                     2        20120.992\nioctl                      1049          407.741\nlseek                      1049          267.505\nclock_nanosleep              11      2000658.003\n[02:12:35]\nSYSCALL                   COUNT        TIME (us)\nfutex                         6      1974795.683\nread                          1      1000393.422\nepoll_pwait                  11       997487.052\nopenat                     1063       740587.085\nclose                      1063       146316.858\nfstat                      1063       104218.279\nnanosleep                     2        20122.434\nioctl                      1063          466.139\nlseek                      1063          305.205\nfutex                         9     11971557.712\n[02:12:36]\nSYSCALL                   COUNT        TIME (us)\nepoll_pwait                  14      6002019.506\nclock_nanosleep              11      2000651.553\nread                          1      1000171.538\nopenat                     1025       742830.398\nclose                      1024       144610.714\nfstat                      1024       106072.947\nnanosleep                     3        30245.112\nioctl                      1024          427.096\nlseek                      1024          291.240\nfutex                         9      5698867.641\n[02:12:37]\nSYSCALL                   COUNT        TIME (us)\nepoll_pwait                  13      2862596.255\nclock_nanosleep              10      1825232.527\nread                         16      1000227.603\nopenat                      902       637999.623\nclose                       919       121950.821\nfstat                       908        91569.624\nunlinkat                    256        62427.863\nnanosleep                     3        30345.306\ngetdents64                    2         1582.794\nDetaching..."
}
```

## execsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1412": {
        "avg_ns_per_run": 2029.1401339304055,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1412,
        "name": "syscall__execve",
        "run_cnt_delta": 24341,
        "run_time_ns_delta": 49391300,
        "type": "kprobe"
      },
      "1413": {
        "avg_ns_per_run": 1046.315927858346,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1413,
        "name": "do_ret_sys_execve",
        "run_cnt_delta": 24341,
        "run_time_ns_delta": 25468376,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 1216.9857091802062,
    "workload_miss": false
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
        "avg_ns_per_run": 2096.5224902082045,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1412,
        "name": "syscall__execve",
        "run_cnt_delta": 24255,
        "run_time_ns_delta": 50851153,
        "type": "kprobe"
      },
      "1413": {
        "avg_ns_per_run": 1051.2784992784993,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1413,
        "name": "do_ret_sys_exec",
        "run_cnt_delta": 24255,
        "run_time_ns_delta": 25498760,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 1212.633009665789,
    "workload_miss": false
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
  "stderr_tail": "<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-9v0ktmfx/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-9v0ktmfx/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "02:13:02 65534 true             10575   1732      0 /bin/true\n02:13:02 65534 true             10576   1732      0 /bin/true\n02:13:02 65534 true             10577   1732      0 /bin/true\n02:13:02 65534 true             10578   1732      0 /bin/true\n02:13:02 65534 true             10579   1732      0 /bin/true\n02:13:02 65534 true             10580   1732      0 /bin/true\n02:13:02 65534 true             10581   1732      0 /bin/true\n02:13:02 65534 true             10582   1732      0 /bin/true\n02:13:03 65534 true             10583   1732      0 /bin/true\n02:13:03 65534 true             10584   1732      0 /bin/true\n02:13:03 65534 true             10585   1732      0 /bin/true\n02:13:03 65534 true             10586   1732      0 /bin/true\n02:13:03 65534 true             10587   1732      0 /bin/true\n02:13:03 65534 true             10588   1732      0 /bin/true\n02:13:03 65534 true             10589   1732      0 /bin/true\n02:13:03 65534 true             10590   1732      0 /bin/true\n02:13:03 65534 true             10591   1732      0 /bin/true\n02:13:03 65534 true             10592   1732      0 /bin/true\n02:13:03 65534 true             10593   1732      0 /bin/true\n02:13:03 65534 true             10594   1732      0 /bin/true\n02:13:03 65534 true             10595   1732      0 /bin/true\n02:13:03 65534 true             10596   1732      0 /bin/true\n02:13:03 65534 true             10597   1732      0 /bin/true\n02:13:03 65534 true             10598   1732      0 /bin/true\n02:13:03 65534 true             10599   1732      0 /bin/true\n02:13:03 65534 true             10600   1732      0 /bin/true\n02:13:03 65534 true             10601   1732      0 /bin/true\n02:13:03 65534 true             10602   1732      0 /bin/true\n02:13:03 65534 true             10603   1732      0 /bin/true\n02:13:03 65534 true             10604   1732      0 /bin/true\n02:13:03 65534 true             10605   1732      0 /bin/true\n02:13:03 65534 true             10606   1732      0 /bin/true\n02:13:03 65534 true             10607   1732      0 /bin/true\n02:13:03 65534 true             10608   1732      0 /bin/true\n02:13:03 65534 true             10609   1732      0 /bin/true\n02:13:03 65534 true             10610   1732      0 /bin/true\n02:13:03 65534 true             10611   1732      0 /bin/true\n02:13:03 65534 true             10612   1732      0 /bin/true\n02:13:03 65534 true             10613   1732      0 /bin/true\n02:13:03 65534 true             10614   1732      0 /bin/true"
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
        "avg_ns_per_run": 1904.7025976320904,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1417,
        "name": "kretfunc__vmlinux____x64_sys_openat",
        "run_cnt_delta": 11318,
        "run_time_ns_delta": 21557424,
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
    "limitations": [],
    "metric": "ops/s",
    "throughput": 1104.8368635450145,
    "workload_miss": false
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
        "avg_ns_per_run": 1719.2121709106602,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1417,
        "name": "__x64_sys_opena",
        "run_cnt_delta": 11585,
        "run_time_ns_delta": 19917073,
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
    "limitations": [],
    "metric": "ops/s",
    "throughput": 1131.5203488880695,
    "workload_miss": false
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-rsmmd4rd/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-rsmmd4rd/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-25.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-26.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-27.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-28.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-29.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-30.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-31.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-32.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-33.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-34.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-35.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-36.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-37.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-38.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-39.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-40.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-41.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-42.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-43.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-44.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-45.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-46.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-47.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-48.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-49.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-50.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix/open-51.dat\n1732   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/loopback-open-storm-lvvwi9ix\n10650  bpftool             3   0 /etc/ld.so.cache\n10650  bpftool             3   0 /lib/x86_64-linux-gnu/libelf.so.1\n10650  bpftool             3   0 /lib/x86_64-linux-gnu/libcrypto.so.3\n10650  bpftool             3   0 /lib/x86_64-linux-gnu/libz.so.1\n10650  bpftool             3   0 /lib/x86_64-linux-gnu/libcap.so.2\n10650  bpftool             3   0 /lib/x86_64-linux-gnu/libc.so.6\n10650  bpftool             3   0 /lib/x86_64-linux-gnu/libzstd.so.1\n10650  bpftool             4   0 /etc/localtime\n10650  bpftool             4   0 /proc/self/fdinfo/3\n10650  bpftool             4   0 /proc/self/fdinfo/3\n10650  bpftool             4   0 /proc/self/fdinfo/3\n10650  bpftool             4   0 /proc/self/fdinfo/3"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1421": {
        "avg_ns_per_run": 44.769649183529324,
        "bytes_jited": 203,
        "bytes_xlated": 344,
        "id": 1421,
        "name": "cap_capable",
        "run_cnt_delta": 2132226,
        "run_time_ns_delta": 95459010,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 1873.3881631780866,
    "workload_miss": false
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
        "avg_ns_per_run": 44.98997727206438,
        "bytes_jited": 206,
        "bytes_xlated": 344,
        "id": 1421,
        "name": "cap_capable",
        "run_cnt_delta": 2228535,
        "run_time_ns_delta": 100261739,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 1946.8986920032228,
    "workload_miss": false
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
  "stderr_tail": "  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-aq4r7pai/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-aq4r7pai/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\nIn file included from include/linux/security.h:9:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "02:13:55  65534  3147   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3173   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3145   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3164   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3176   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3174   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3148   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3177   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3165   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3149   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3150   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3166   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3167   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3168   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3151   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3178   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3175   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3152   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3161   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3179   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3180   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3185   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3186   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3187   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3188   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3181   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3183   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3153   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  65534  3189   stress-ng-exec   8    CAP_SETPCAP          1\n02:13:55  0      3214   bpftool          21   CAP_SYS_ADMIN        1\n02:13:55  0      3214   bpftool          21   CAP_SYS_ADMIN        1\n02:13:55  0      3214   bpftool          39   CAP_BPF              1\n02:13:55  0      3214   bpftool          21   CAP_SYS_ADMIN        1\n02:13:55  0      3214   bpftool          21   CAP_SYS_ADMIN        1\n02:13:55  0      3214   bpftool          39   CAP_BPF              1\n02:13:55  0      3214   bpftool          39   CAP_BPF              1\n02:13:55  0      3214   bpftool          39   CAP_BPF              1\n02:13:55  0      3214   bpftool          39   CAP_BPF              1\n02:13:55  0      3214   bpftool          21   CAP_SYS_ADMIN        1\n02:13:55  0      3214   bpftool          21   CAP_SYS_ADMIN        1"
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
        "avg_ns_per_run": 300.88726790450926,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1427,
        "name": "vfs_open",
        "run_cnt_delta": 754,
        "run_time_ns_delta": 226869,
        "type": "tracing"
      },
      "1428": {
        "avg_ns_per_run": 104.95881161377447,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1428,
        "name": "vfs_read",
        "run_cnt_delta": 1481,
        "run_time_ns_delta": 155444,
        "type": "tracing"
      },
      "1429": {
        "avg_ns_per_run": 80.41632653061224,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1429,
        "name": "vfs_write",
        "run_cnt_delta": 735,
        "run_time_ns_delta": 59106,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 72.61357394463319,
    "workload_miss": false
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
        "avg_ns_per_run": 200.15039577836413,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1427,
        "name": "vfs_open",
        "run_cnt_delta": 758,
        "run_time_ns_delta": 151714,
        "type": "tracing"
      },
      "1428": {
        "avg_ns_per_run": 86.00943396226415,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1428,
        "name": "vfs_read",
        "run_cnt_delta": 1484,
        "run_time_ns_delta": 127638,
        "type": "tracing"
      },
      "1429": {
        "avg_ns_per_run": 89.566757493188,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1429,
        "name": "vfs_write",
        "run_cnt_delta": 734,
        "run_time_ns_delta": 65742,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 73.0911840629806,
    "workload_miss": false
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-h_qptqgq/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-h_qptqgq/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "TIME         READ/s  WRITE/s  FSYNC/s   OPEN/s CREATE/s\n02:13:57:      1487        5        0      132        0\n02:13:58:        81        5        0      104        0\n02:13:59:       172       60        0      134        0\n02:14:00:       149       75        0       74        0\n02:14:01:       145       73        0       72        0\n02:14:02:       152       75        0       76        0\n02:14:03:       144       73        0       72        0\n02:14:04:       157       79        0       78        0\n02:14:05:       144       72        0       72        0\n02:14:06:       139       70        0       69        0\n02:14:07:       140       71        0       69        0\n02:14:08:       143       72        0       71        0\n02:14:09:       134       39        0      110        0\n02:14:10:       150       75        0       75        0\n02:14:11:       160       80        0       80        0\n02:14:12:       148       74        0       74        0\n02:14:13:       150       75        0       75        0\n02:14:14:       146       73        0       73        0\n02:14:15:       131       65        0       64        0\n02:14:16:       140       71        0       70        0\n02:14:17:       145       73        0       72        0\n02:14:18:       144       72        0       72        0\n02:14:19:       132       56        0       83        0"
}
```

## tcpconnect

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1432": {
        "avg_ns_per_run": 2030.5391444713478,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1432,
        "name": "trace_connect_entry",
        "run_cnt_delta": 2478,
        "run_time_ns_delta": 5031676,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 7858.181598062954,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1433,
        "name": "trace_connect_v4_return",
        "run_cnt_delta": 1239,
        "run_time_ns_delta": 9736287,
        "type": "kprobe"
      },
      "1434": {
        "avg_ns_per_run": 8323.929782082325,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1434,
        "name": "trace_connect_v6_return",
        "run_cnt_delta": 1239,
        "run_time_ns_delta": 10313349,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 247.73236230199814,
    "workload_miss": false
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
        "avg_ns_per_run": 2101.63850528026,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1432,
        "name": "trace_connect_e",
        "run_cnt_delta": 2462,
        "run_time_ns_delta": 5174234,
        "type": "kprobe"
      },
      "1433": {
        "avg_ns_per_run": 8312.560519902518,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1433,
        "name": "trace_connect_v",
        "run_cnt_delta": 1231,
        "run_time_ns_delta": 10232762,
        "type": "kprobe"
      },
      "1434": {
        "avg_ns_per_run": 8210.155158407799,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1434,
        "name": "trace_connect_v",
        "run_cnt_delta": 1231,
        "run_time_ns_delta": 10106701,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 246.18077882024002,
    "workload_miss": false
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
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-cjzj29jq/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:16:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "13096   curl         4  127.0.0.1        127.0.0.1        42921\n13098   curl         6  ::1              ::1              43289\n13100   curl         4  127.0.0.1        127.0.0.1        42921\n13102   curl         6  ::1              ::1              43289\n13104   curl         4  127.0.0.1        127.0.0.1        42921\n13106   curl         6  ::1              ::1              43289\n13108   curl         4  127.0.0.1        127.0.0.1        42921\n13110   curl         6  ::1              ::1              43289\n13112   curl         4  127.0.0.1        127.0.0.1        42921\n13114   curl         6  ::1              ::1              43289\n13116   curl         4  127.0.0.1        127.0.0.1        42921\n13118   curl         6  ::1              ::1              43289\n13120   curl         4  127.0.0.1        127.0.0.1        42921\n13122   curl         6  ::1              ::1              43289\n13124   curl         4  127.0.0.1        127.0.0.1        42921\n13126   curl         6  ::1              ::1              43289\n13128   curl         4  127.0.0.1        127.0.0.1        42921\n13130   curl         6  ::1              ::1              43289\n13132   curl         4  127.0.0.1        127.0.0.1        42921\n13134   curl         6  ::1              ::1              43289\n13136   curl         4  127.0.0.1        127.0.0.1        42921\n13138   curl         6  ::1              ::1              43289\n13140   curl         4  127.0.0.1        127.0.0.1        42921\n13142   curl         6  ::1              ::1              43289\n13144   curl         4  127.0.0.1        127.0.0.1        42921\n13146   curl         6  ::1              ::1              43289\n13148   curl         4  127.0.0.1        127.0.0.1        42921\n13150   curl         6  ::1              ::1              43289\n13152   curl         4  127.0.0.1        127.0.0.1        42921\n13154   curl         6  ::1              ::1              43289\n13156   curl         4  127.0.0.1        127.0.0.1        42921\n13158   curl         6  ::1              ::1              43289\n13160   curl         4  127.0.0.1        127.0.0.1        42921\n13162   curl         6  ::1              ::1              43289\n13164   curl         4  127.0.0.1        127.0.0.1        42921\n13166   curl         6  ::1              ::1              43289\n13168   curl         4  127.0.0.1        127.0.0.1        42921\n13170   curl         6  ::1              ::1              43289\n13172   curl         4  127.0.0.1        127.0.0.1        42921\n13174   curl         6  ::1              ::1              43289"
}
```

## bindsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1437": {
        "avg_ns_per_run": 79.84593056040033,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1437,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1525124,
        "run_time_ns_delta": 121774945,
        "type": "kprobe"
      },
      "1438": {
        "avg_ns_per_run": 794.7470015552834,
        "bytes_jited": 721,
        "bytes_xlated": 1160,
        "id": 1438,
        "name": "bindsnoop_v4_return",
        "run_cnt_delta": 762562,
        "run_time_ns_delta": 606043863,
        "type": "kprobe"
      },
      "1439": {
        "avg_ns_per_run": 769.0105722551084,
        "bytes_jited": 742,
        "bytes_xlated": 1184,
        "id": 1439,
        "name": "bindsnoop_v6_return",
        "run_cnt_delta": 762562,
        "run_time_ns_delta": 586418240,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 152512.25869739207,
    "workload_miss": false
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
        "avg_ns_per_run": 90.11683640530848,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1437,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1466863,
        "run_time_ns_delta": 132189053,
        "type": "kprobe"
      },
      "1438": {
        "avg_ns_per_run": 830.6691745110658,
        "bytes_jited": 719,
        "bytes_xlated": 1160,
        "id": 1438,
        "name": "bindsnoop_v4_re",
        "run_cnt_delta": 733432,
        "run_time_ns_delta": 609239354,
        "type": "kprobe"
      },
      "1439": {
        "avg_ns_per_run": 799.7751608535772,
        "bytes_jited": 740,
        "bytes_xlated": 1184,
        "id": 1439,
        "name": "bindsnoop_v6_re",
        "run_cnt_delta": 733431,
        "run_time_ns_delta": 586579896,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 146686.15222837208,
    "workload_miss": false
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
  "stderr_tail": "In file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.e0fd9c6c/bcc-python-xdze_ob8/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:18:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.\nPossibly lost 489 samples",
  "stdout_tail": "    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0\n    1732 python3      IP   ::1             20160 ..NR.  0\n    1732 python3      IP   127.0.0.1       17088 ..NR.  0"
}
```

