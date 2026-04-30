# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-24T20:58:38.167714+00:00`
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
      "1413": {
        "avg_ns_per_run": 521.6228636618021,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1413,
        "name": "tracepoint__sock__inet_sock_set_state",
        "run_cnt_delta": 46458,
        "run_time_ns_delta": 24233555,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 422.6870785405402
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
      "1413": {
        "avg_ns_per_run": 525.0539933480195,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 1413,
        "name": "sock__inet_sock",
        "run_cnt_delta": 46302,
        "run_time_ns_delta": 24311050,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 421.11407887325623
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
  "stderr_tail": "In file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-70zpvs57/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-70zpvs57/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/tcp.h:7:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "3932  curl       127.0.0.1       42371 127.0.0.1       40160     0     0 0.32\n3932  curl       127.0.0.1       40160 127.0.0.1       42371     0     0 0.33\n3934  curl       ::1             45979 ::1             43932     0     0 0.23\n3934  curl       ::1             43932 ::1             45979     0     0 0.24\n3936  curl       127.0.0.1       42371 127.0.0.1       40166     0     0 0.26\n3936  curl       127.0.0.1       40166 127.0.0.1       42371     0     0 0.27\n3938  curl       ::1             45979 ::1             43946     0     0 0.26\n3938  curl       ::1             43946 ::1             45979     0     0 0.27\n3940  curl       127.0.0.1       42371 127.0.0.1       40178     0     0 0.26\n3940  curl       127.0.0.1       40178 127.0.0.1       42371     0     0 0.27\n3942  curl       ::1             45979 ::1             43958     0     0 0.23\n3942  curl       ::1             43958 ::1             45979     0     0 0.24\n3944  curl       127.0.0.1       42371 127.0.0.1       40182     0     0 0.24\n3944  curl       127.0.0.1       40182 127.0.0.1       42371     0     0 0.25\n3946  curl       ::1             45979 ::1             43960     0     0 0.23\n3946  curl       ::1             43960 ::1             45979     0     0 0.24\n3948  curl       127.0.0.1       42371 127.0.0.1       40194     0     0 0.26\n3948  curl       127.0.0.1       40194 127.0.0.1       42371     0     0 0.27\n3950  curl       ::1             45979 ::1             43974     0     0 0.26\n3950  curl       ::1             43974 ::1             45979     0     0 0.27\n3952  curl       127.0.0.1       42371 127.0.0.1       40200     0     0 0.27\n3952  curl       127.0.0.1       40200 127.0.0.1       42371     0     0 0.28\n3954  curl       ::1             45979 ::1             43982     0     0 0.21\n3954  curl       ::1             43982 ::1             45979     0     0 0.22\n3956  curl       127.0.0.1       42371 127.0.0.1       40212     0     0 0.20\n3956  curl       127.0.0.1       40212 127.0.0.1       42371     0     0 0.21\n3958  curl       ::1             45979 ::1             43990     0     0 0.33\n3958  curl       ::1             43990 ::1             45979     0     0 0.34\n3960  curl       127.0.0.1       42371 127.0.0.1       40224     0     0 0.23\n3960  curl       127.0.0.1       40224 127.0.0.1       42371     0     0 0.24\n3963  curl       ::1             45979 ::1             44004     0     0 0.30\n3963  curl       ::1             44004 ::1             45979     0     0 0.31\n3965  curl       127.0.0.1       42371 127.0.0.1       40230     0     0 0.28\n3965  curl       127.0.0.1       40230 127.0.0.1       42371     0     0 0.28\n3967  curl       ::1             45979 ::1             44012     0     0 0.21\n3967  curl       ::1             44012 ::1             45979     0     0 0.21\n3969  curl       127.0.0.1       42371 127.0.0.1       40242     0     0 0.25\n3969  curl       127.0.0.1       40242 127.0.0.1       42371     0     0 0.26\n3971  curl       ::1             45979 ::1             44016     0     0 0.24\n3971  curl       ::1             44016 ::1             45979     0     0 0.25"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1416": {
        "avg_ns_per_run": 62.0994709718991,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1416,
        "name": "trace_pid_start_tp",
        "run_cnt_delta": 9379842,
        "run_time_ns_delta": 582483226,
        "type": "tracepoint"
      },
      "1417": {
        "avg_ns_per_run": 94.99061231721977,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1417,
        "name": "trace_req_start",
        "run_cnt_delta": 9379844,
        "run_time_ns_delta": 890997125,
        "type": "kprobe"
      },
      "1418": {
        "avg_ns_per_run": 283.15848204314676,
        "bytes_jited": 550,
        "bytes_xlated": 856,
        "id": 1418,
        "name": "trace_req_completion_tp",
        "run_cnt_delta": 9379845,
        "run_time_ns_delta": 2655982672,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 937807.4088954963
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
        "avg_ns_per_run": 61.88743444324105,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 1416,
        "name": "trace_pid_start",
        "run_cnt_delta": 9371650,
        "run_time_ns_delta": 579987375,
        "type": "tracepoint"
      },
      "1417": {
        "avg_ns_per_run": 95.2477799004914,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 1417,
        "name": "trace_req_start",
        "run_cnt_delta": 9371652,
        "run_time_ns_delta": 892629047,
        "type": "kprobe"
      },
      "1418": {
        "avg_ns_per_run": 282.46394120652997,
        "bytes_jited": 548,
        "bytes_xlated": 848,
        "id": 1418,
        "name": "trace_req_compl",
        "run_cnt_delta": 9371653,
        "run_time_ns_delta": 2647154042,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 936640.026070003
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
  "stderr_tail": "      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-u5xlc6yb/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/blk-mq.h:5:\nIn file included from include/linux/blkdev.h:7:\nIn file included from include/linux/blk_types.h:7:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.\nException ignored on calling ctypes callback function: <function PerfEventArray._open_perf_buffer.<locals>.raw_cb_ at 0x7f1cdf2e7920>\nTraceback (most recent call last):\n  File \"/usr/lib/python3/dist-packages/bcc/table.py\", line 991, in raw_cb_\n    callback(cpu, data, size)\n  File \"/usr/sbin/biosnoop-bpfcc\", line 393, in print_event\n    event = b[\"events\"].event(data)\n            ^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/usr/lib/python3/dist-packages/bcc/table.py\", line 970, in event\n    return ct.cast(data, ct.POINTER(self._event_class)).contents\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/usr/lib/python3.12/ctypes/__init__.py\", line 518, in cast\n    return _cast(obj, obj, typ)\n           ^^^^^^^^^^^^^^^^^^^^\nKeyboardInterrupt:",
  "stdout_tail": "20.240469                  8612    nullb0    R 32280      4096      0.00\n20.240470                  8612    nullb0    R 32288      4096      0.00\n20.240471                  8612    nullb0    R 32296      4096      0.00\n20.240472                  8612    nullb0    R 32304      4096      0.00\n20.240474                  8612    nullb0    R 32312      4096      0.00\n20.240475                  8612    nullb0    R 32320      4096      0.00\n20.240476                  8612    nullb0    R 32328      4096      0.00\n20.240477                  8612    nullb0    R 32336      4096      0.00\n20.240478                  8612    nullb0    R 32344      4096      0.00\n20.240479                  8612    nullb0    R 32352      4096      0.00\n20.240481                  8612    nullb0    R 32360      4096      0.00\n20.240482                  8612    nullb0    R 32368      4096      0.00\n20.240483                  8612    nullb0    R 32376      4096      0.00\n20.240484                  8612    nullb0    R 32384      4096      0.00\n20.240485                  8612    nullb0    R 32392      4096      0.00\n20.240486                  8612    nullb0    R 32400      4096      0.00\n20.240488                  8612    nullb0    R 32408      4096      0.00\n20.240489                  8612    nullb0    R 32416      4096      0.00\n20.240490                  8612    nullb0    R 32424      4096      0.00\n20.240491                  8612    nullb0    R 32432      4096      0.00\n20.240492                  8612    nullb0    R 32440      4096      0.00\n20.240494                  8612    nullb0    R 32448      4096      0.00\n20.240495                  8612    nullb0    R 32456      4096      0.00\n20.240496                  8612    nullb0    R 32464      4096      0.00\n20.240497                  8612    nullb0    R 32472      4096      0.00\n20.240498                  8612    nullb0    R 32480      4096      0.00\n20.240499                  8612    nullb0    R 32488      4096      0.00\n20.240500                  8612    nullb0    R 32496      4096      0.00\n20.240502                  8612    nullb0    R 32504      4096      0.00\n20.240503                  8612    nullb0    R 32512      4096      0.00\n20.240504                  8612    nullb0    R 32520      4096      0.00\n20.240505                  8612    nullb0    R 32528      4096      0.00\n20.240506                  8612    nullb0    R 32536      4096      0.00\n20.240507                  8612    nullb0    R 32544      4096      0.00\n20.240508                  8612    nullb0    R 32552      4096      0.00\n20.240509                  8612    nullb0    R 32560      4096      0.00\n20.240511                  8612    nullb0    R 32568      4096      0.00\n20.240512                  8612    nullb0    R 32576      4096      0.00\n20.240513                  8612    nullb0    R 32584      4096      0.00\n20.240514                  8612    nullb0    R 32592      4096"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1423": {
        "avg_ns_per_run": 173.18833934201635,
        "bytes_jited": 662,
        "bytes_xlated": 1168,
        "id": 1423,
        "name": "sched_switch",
        "run_cnt_delta": 1521132,
        "run_time_ns_delta": 263442325,
        "type": "raw_tracepoint"
      },
      "1424": {
        "avg_ns_per_run": 109.75159166142036,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1424,
        "name": "sched_wakeup",
        "run_cnt_delta": 787856,
        "run_time_ns_delta": 86468450,
        "type": "raw_tracepoint"
      },
      "1425": {
        "avg_ns_per_run": 241.61041087115123,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1425,
        "name": "raw_tracepoint__sched_wakeup_new",
        "run_cnt_delta": 168593,
        "run_time_ns_delta": 40733824,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 65.5276988601758
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
      "1423": {
        "avg_ns_per_run": 170.3749820583701,
        "bytes_jited": 645,
        "bytes_xlated": 1136,
        "id": 1423,
        "name": "sched_switch",
        "run_cnt_delta": 1504880,
        "run_time_ns_delta": 256393903,
        "type": "raw_tracepoint"
      },
      "1424": {
        "avg_ns_per_run": 113.71121753365749,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1424,
        "name": "sched_wakeup",
        "run_cnt_delta": 777613,
        "run_time_ns_delta": 88423321,
        "type": "raw_tracepoint"
      },
      "1425": {
        "avg_ns_per_run": 245.15834419224825,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 1425,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 164995,
        "run_time_ns_delta": 40449901,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 64.17565624831616
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
  "stderr_tail": "In file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-rv3192lk/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-rv3192lk/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:6:\nIn file included from include/linux/pid_namespace.h:7:\nIn file included from include/linux/mm.h:1118:\nIn file included from include/linux/huge_mm.h:7:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "             8388608 -> 16777215             : 5087     |                    |\n            16777216 -> 33554431             : 0        |                    |\n            33554432 -> 67108863             : 0        |                    |\n            67108864 -> 134217727            : 0        |                    |\n           134217728 -> 268435455            : 0        |                    |\n           268435456 -> 536870911            : 4360     |                    |\n           536870912 -> 1073741823           : 4185     |                    |\n          1073741824 -> 2147483647           : 4208     |                    |\n          2147483648 -> 4294967295           : 4029     |                    |\n          4294967296 -> 8589934591           : 0        |                    |\n          8589934592 -> 17179869183          : 0        |                    |\n         17179869184 -> 34359738367          : 0        |                    |\n         34359738368 -> 68719476735          : 0        |                    |\n         68719476736 -> 137438953471         : 3517     |                    |\n        137438953472 -> 274877906943         : 3446     |                    |\n        274877906944 -> 549755813887         : 3338     |                    |\n        549755813888 -> 1099511627775        : 3284     |                    |\n       1099511627776 -> 2199023255551        : 0        |                    |\n       2199023255552 -> 4398046511103        : 0        |                    |\n       4398046511104 -> 8796093022207        : 0        |                    |\n       8796093022208 -> 17592186044415       : 0        |                    |\n      17592186044416 -> 35184372088831       : 2927     |                    |\n      35184372088832 -> 70368744177663       : 2846     |                    |\n      70368744177664 -> 140737488355327      : 2789     |                    |\n     140737488355328 -> 281474976710655      : 2758     |                    |\n     281474976710656 -> 562949953421311      : 0        |                    |\n     562949953421312 -> 1125899906842623     : 0        |                    |\n    1125899906842624 -> 2251799813685247     : 0        |                    |\n    2251799813685248 -> 4503599627370495     : 0        |                    |\n    4503599627370496 -> 9007199254740991     : 2622     |                    |\n    9007199254740992 -> 18014398509481983    : 2621     |                    |\n   18014398509481984 -> 36028797018963967    : 2637     |                    |\n   36028797018963968 -> 72057594037927935    : 2612     |                    |\n   72057594037927936 -> 144115188075855871   : 0        |                    |\n  144115188075855872 -> 288230376151711743   : 0        |                    |\n  288230376151711744 -> 576460752303423487   : 0        |                    |\n  576460752303423488 -> 1152921504606846975  : 0        |                    |\n 1152921504606846976 -> 2305843009213693951  : 2469     |                    |\n 2305843009213693952 -> 4611686018427387903  : 2424     |                    |\n 4611686018427387904 -> 9223372036854775807  : 2454     |                    |"
}
```

## syscount

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1430": {
        "avg_ns_per_run": 70.79208479678876,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1430,
        "name": "tracepoint__raw_syscalls__sys_enter",
        "run_cnt_delta": 63776,
        "run_time_ns_delta": 4514836,
        "type": "tracepoint"
      },
      "1431": {
        "avg_ns_per_run": 72.5903161063723,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1431,
        "name": "tracepoint__raw_syscalls__sys_exit",
        "run_cnt_delta": 63776,
        "run_time_ns_delta": 4629520,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1132.779617329955
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
      "1430": {
        "avg_ns_per_run": 80.48357403070519,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 1430,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 61488,
        "run_time_ns_delta": 4948774,
        "type": "tracepoint"
      },
      "1431": {
        "avg_ns_per_run": 81.9032494145199,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 1431,
        "name": "raw_syscalls__s",
        "run_cnt_delta": 61488,
        "run_time_ns_delta": 5036067,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1078.6723569713838
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-k7_cr2f1/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-k7_cr2f1/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "nanosleep                     2        20302.543\nbpf                         453          698.460\nlseek                      1109          174.897\nfutex                         9      2069769.354\n[20:55:54]\nSYSCALL                   COUNT        TIME (us)\nclock_nanosleep              11      2000609.812\nepoll_pwait                   6      1045053.195\nread                          1      1000039.401\nopenat                     1074       743989.148\nclose                      1075       145371.873\nfstat                      1074       107354.654\nnanosleep                     2        20323.502\nioctl                      1074          158.787\nlseek                      1074          143.899\nfutex                         6      2069748.353\n[20:55:55]\nSYSCALL                   COUNT        TIME (us)\nclock_nanosleep              11      2000595.849\nepoll_pwait                   6      1045053.647\nread                          1      1000066.719\nopenat                     1074       744558.483\nclose                      1074       145321.223\nfstat                      1074       107701.647\nnanosleep                     2        20388.637\nioctl                      1074          156.890\nlseek                      1074          139.836\nclock_nanosleep              10      1753194.715\n[20:55:55]\nSYSCALL                   COUNT        TIME (us)\nfutex                         3      1034826.787\nread                         16      1000084.204\nopenat                      847       580095.926\nepoll_pwait                   4       522527.764\nclose                       863       114006.017\nfstat                       852        84175.211\nunlinkat                    256        66248.109\nnanosleep                     1        10154.001\npoll                          2         2577.687\nDetaching..."
}
```

## execsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1434": {
        "avg_ns_per_run": 1155.4462237393639,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1434,
        "name": "syscall__execve",
        "run_cnt_delta": 39841,
        "run_time_ns_delta": 46034133,
        "type": "kprobe"
      },
      "1435": {
        "avg_ns_per_run": 817.5426319620492,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1435,
        "name": "do_ret_sys_execve",
        "run_cnt_delta": 39841,
        "run_time_ns_delta": 32571716,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1991.919947526004
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
      "1434": {
        "avg_ns_per_run": 1153.0461741096947,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 1434,
        "name": "syscall__execve",
        "run_cnt_delta": 40239,
        "run_time_ns_delta": 46397425,
        "type": "kprobe"
      },
      "1435": {
        "avg_ns_per_run": 801.1255001366833,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 1435,
        "name": "do_ret_sys_exec",
        "run_cnt_delta": 40239,
        "run_time_ns_delta": 32236489,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 2011.809901697089
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
  "stderr_tail": "<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-gr4_1qvw/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-gr4_1qvw/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "20:56:20 65534 true             26689   1721      0 /bin/true\n20:56:20 65534 true             26690   1721      0 /bin/true\n20:56:20 65534 true             26691   1721      0 /bin/true\n20:56:20 65534 true             26692   1721      0 /bin/true\n20:56:20 65534 true             26693   1721      0 /bin/true\n20:56:20 65534 true             26694   1721      0 /bin/true\n20:56:20 65534 true             26695   1721      0 /bin/true\n20:56:20 65534 true             26696   1721      0 /bin/true\n20:56:20 65534 true             26697   1721      0 /bin/true\n20:56:20 65534 true             26698   1721      0 /bin/true\n20:56:20 65534 true             26699   1721      0 /bin/true\n20:56:20 65534 true             26700   1721      0 /bin/true\n20:56:20 65534 true             26701   1721      0 /bin/true\n20:56:20 65534 true             26702   1721      0 /bin/true\n20:56:20 65534 true             26703   1721      0 /bin/true\n20:56:20 65534 true             26704   1721      0 /bin/true\n20:56:20 65534 true             26705   1721      0 /bin/true\n20:56:20 65534 true             26706   1721      0 /bin/true\n20:56:20 65534 true             26707   1721      0 /bin/true\n20:56:20 65534 true             26708   1721      0 /bin/true\n20:56:20 65534 true             26709   1721      0 /bin/true\n20:56:20 65534 true             26710   1721      0 /bin/true\n20:56:20 65534 true             26711   1721      0 /bin/true\n20:56:20 65534 true             26712   1721      0 /bin/true\n20:56:20 65534 true             26713   1721      0 /bin/true\n20:56:20 65534 true             26714   1721      0 /bin/true\n20:56:20 65534 true             26715   1721      0 /bin/true\n20:56:20 65534 true             26716   1721      0 /bin/true\n20:56:20 65534 true             26717   1721      0 /bin/true\n20:56:20 65534 true             26718   1721      0 /bin/true\n20:56:20 65534 true             26719   1721      0 /bin/true\n20:56:20 65534 true             26720   1721      0 /bin/true\n20:56:20 65534 true             26721   1721      0 /bin/true\n20:56:20 65534 true             26722   1721      0 /bin/true\n20:56:20 65534 true             26723   1721      0 /bin/true\n20:56:20 65534 true             26724   1721      0 /bin/true\n20:56:20 65534 true             26725   1721      0 /bin/true\n20:56:20 65534 true             26726   1721      0 /bin/true\n20:56:20 65534 true             26727   1721      0 /bin/true\n20:56:20 65534 true             26728   1721      0 /bin/true"
}
```

## opensnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1438": {
        "avg_ns_per_run": null,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1438,
        "name": "__x64_sys_open",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1439": {
        "avg_ns_per_run": 2883.2879700620665,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1439,
        "name": "kretfunc__vmlinux____x64_sys_openat",
        "run_cnt_delta": 10956,
        "run_time_ns_delta": 31589303,
        "type": "tracing"
      },
      "1440": {
        "avg_ns_per_run": null,
        "bytes_jited": 590,
        "bytes_xlated": 640,
        "id": 1440,
        "name": "kretfunc__vmlinux____x64_sys_openat2",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1068.6862157645867
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
      "1438": {
        "avg_ns_per_run": null,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1438,
        "name": "__x64_sys_open",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1439": {
        "avg_ns_per_run": 2888.1731506849314,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 1439,
        "name": "__x64_sys_opena",
        "run_cnt_delta": 10950,
        "run_time_ns_delta": 31625496,
        "type": "tracing"
      },
      "1440": {
        "avg_ns_per_run": null,
        "bytes_jited": 590,
        "bytes_xlated": 640,
        "id": 1440,
        "name": "__x64_sys_opena",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 1068.0372908312843
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
  "stderr_tail": "In file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-u2m7qh3n/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-u2m7qh3n/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.\nException ignored on calling ctypes callback function: <function PerfEventArray._open_perf_buffer.<locals>.raw_cb_ at 0x7fee073ffe20>\nTraceback (most recent call last):\n  File \"/usr/lib/python3/dist-packages/bcc/table.py\", line 991, in raw_cb_\n    callback(cpu, data, size)\n  File \"/usr/sbin/opensnoop-bpfcc\", line 451, in print_event\n    printb(b\"%-6d %-16s %4d %3d \" %\n           ^^^^^^^^^^^^^^^^^^^^^^^^\nKeyboardInterrupt:",
  "stdout_tail": "1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-159.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-160.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-161.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-162.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-163.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-164.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-165.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-166.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-167.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-168.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-169.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-170.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-171.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-172.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-173.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-174.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-175.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-176.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-177.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-178.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-179.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-180.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-181.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-182.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-183.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577/open-184.dat\n1721   python3             3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/loopback-open-storm-673me577\n26761  bpftool             3   0 /etc/ld.so.cache\n26761  bpftool             3   0 /lib/x86_64-linux-gnu/libelf.so.1\n26761  bpftool             3   0 /lib/x86_64-linux-gnu/libcrypto.so.3\n26761  bpftool             3   0 /lib/x86_64-linux-gnu/libz.so.1\n26761  bpftool             3   0 /lib/x86_64-linux-gnu/libcap.so.2\n26761  bpftool             3   0 /lib/x86_64-linux-gnu/libc.so.6\n26761  bpftool             3   0 /lib/x86_64-linux-gnu/libzstd.so.1\n26761  bpftool             4   0 /proc/self/fdinfo/3\n26761  bpftool             4   0 /proc/self/fdinfo/3\n26761  bpftool             4   0 /proc/self/fdinfo/3\n26761  bpftool             4   0 /proc/self/fdinfo/3\n26731  opensnoop-bpfcc    15   0 /usr/lib/python3/dist-packages/bcc/table.py\n26731  opensnoop-bpfcc    15   0 /usr/sbin/opensnoop-bpfcc"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1443": {
        "avg_ns_per_run": 40.68552756174421,
        "bytes_jited": 203,
        "bytes_xlated": 344,
        "id": 1443,
        "name": "cap_capable",
        "run_cnt_delta": 2770017,
        "run_time_ns_delta": 112699603,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 2425.3428319254135
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
      "1443": {
        "avg_ns_per_run": 39.89207575047503,
        "bytes_jited": 206,
        "bytes_xlated": 344,
        "id": 1443,
        "name": "cap_capable",
        "run_cnt_delta": 2780339,
        "run_time_ns_delta": 110913494,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 2429.992413649864
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
  "stderr_tail": "  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-nfa25f6i/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-nfa25f6i/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\nIn file included from include/linux/security.h:9:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "20:57:19  65534  2786   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2818   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2819   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2820   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2834   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2835   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2836   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2837   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2838   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2839   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2840   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2841   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2842   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2843   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2844   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2845   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2846   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2847   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2787   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2788   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2789   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2790   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2791   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2793   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2821   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2823   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2826   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2851   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  65534  2852   stress-ng-exec   8    CAP_SETPCAP          1\n20:57:19  0      2895   bpftool          21   CAP_SYS_ADMIN        1\n20:57:19  0      2895   bpftool          21   CAP_SYS_ADMIN        1\n20:57:19  0      2895   bpftool          39   CAP_BPF              1\n20:57:19  0      2895   bpftool          21   CAP_SYS_ADMIN        1\n20:57:19  0      2895   bpftool          21   CAP_SYS_ADMIN        1\n20:57:19  0      2895   bpftool          39   CAP_BPF              1\n20:57:19  0      2895   bpftool          39   CAP_BPF              1\n20:57:19  0      2895   bpftool          39   CAP_BPF              1\n20:57:19  0      2895   bpftool          39   CAP_BPF              1\n20:57:19  0      2895   bpftool          21   CAP_SYS_ADMIN        1\n20:57:19  0      2895   bpftool          21   CAP_SYS_ADMIN        1"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1447": {
        "avg_ns_per_run": null,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1447,
        "name": "vfs_create",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1448": {
        "avg_ns_per_run": null,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1448,
        "name": "kfunc__vmlinux__vfs_fsync_range",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1449": {
        "avg_ns_per_run": 50.09383033419023,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1449,
        "name": "vfs_open",
        "run_cnt_delta": 778,
        "run_time_ns_delta": 38973,
        "type": "tracing"
      },
      "1450": {
        "avg_ns_per_run": 28.704918032786885,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1450,
        "name": "vfs_read",
        "run_cnt_delta": 1525,
        "run_time_ns_delta": 43775,
        "type": "tracing"
      },
      "1451": {
        "avg_ns_per_run": 30.320529801324504,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1451,
        "name": "vfs_write",
        "run_cnt_delta": 755,
        "run_time_ns_delta": 22892,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 75.08686778737984
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
      "1447": {
        "avg_ns_per_run": null,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1447,
        "name": "vfs_create",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1448": {
        "avg_ns_per_run": null,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1448,
        "name": "vfs_fsync_range",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "tracing"
      },
      "1449": {
        "avg_ns_per_run": 72.82142857142857,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1449,
        "name": "vfs_open",
        "run_cnt_delta": 728,
        "run_time_ns_delta": 53014,
        "type": "tracing"
      },
      "1450": {
        "avg_ns_per_run": 35.1493370551291,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 1450,
        "name": "vfs_read",
        "run_cnt_delta": 1433,
        "run_time_ns_delta": 50369,
        "type": "tracing"
      },
      "1451": {
        "avg_ns_per_run": 41.46984572230014,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 1451,
        "name": "vfs_write",
        "run_cnt_delta": 713,
        "run_time_ns_delta": 29568,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 70.05253481221882
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
  "output_chars": 19745,
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
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-b3pxq7me/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-b3pxq7me/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "TIME         READ/s  WRITE/s  FSYNC/s   OPEN/s CREATE/s\n20:57:22:      1487        5        0      132        0\n20:57:23:       100        5        0      130        0\n20:57:24:       162       64        0      113        0\n20:57:25:       154       77        0       77        0\n20:57:26:       154       77        0       77        0\n20:57:27:       151       76        0       75        0\n20:57:28:       148       74        0       74        0\n20:57:29:       149       74        0       75        0\n20:57:30:       149       75        0       74        0\n20:57:31:       149       75        0       74        0\n20:57:32:       152       76        0       77        0\n20:57:33:       155       77        0       76        0\n20:57:34:       128       37        0      107        0\n20:57:35:       140       69        0       70        0\n20:57:36:       143       73        0       71        0\n20:57:37:       137       69        0       68        0\n20:57:38:       147       74        0       73        0\n20:57:39:       140       70        0       70        0\n20:57:40:       138       70        0       68        0\n20:57:41:       141       71        0       70        0\n20:57:42:       143       73        0       70        0\n20:57:43:       141       71        0       70        0\n20:57:43:       117       49        0       75        0"
}
```

## tcpconnect

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1454": {
        "avg_ns_per_run": 682.5728260869565,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1454,
        "name": "trace_connect_entry",
        "run_cnt_delta": 3680,
        "run_time_ns_delta": 2511868,
        "type": "kprobe"
      },
      "1455": {
        "avg_ns_per_run": 4318.808152173913,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1455,
        "name": "trace_connect_v4_return",
        "run_cnt_delta": 1840,
        "run_time_ns_delta": 7946607,
        "type": "kprobe"
      },
      "1456": {
        "avg_ns_per_run": 4238.233152173913,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1456,
        "name": "trace_connect_v6_return",
        "run_cnt_delta": 1840,
        "run_time_ns_delta": 7798349,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 367.9952218764409
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
      "1454": {
        "avg_ns_per_run": 676.609865470852,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1454,
        "name": "trace_connect_e",
        "run_cnt_delta": 3791,
        "run_time_ns_delta": 2565028,
        "type": "kprobe"
      },
      "1455": {
        "avg_ns_per_run": 3737.60970464135,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 1455,
        "name": "trace_connect_v",
        "run_cnt_delta": 1896,
        "run_time_ns_delta": 7086508,
        "type": "kprobe"
      },
      "1456": {
        "avg_ns_per_run": 3738.4891820580474,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 1456,
        "name": "trace_connect_v",
        "run_cnt_delta": 1895,
        "run_time_ns_delta": 7084437,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 379.0896689725258
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
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-0shs0cff/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:16:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "17829   curl         6  ::1              ::1              41549\n17831   curl         4  127.0.0.1        127.0.0.1        33495\n17833   curl         6  ::1              ::1              41549\n17835   curl         4  127.0.0.1        127.0.0.1        33495\n17837   curl         6  ::1              ::1              41549\n17839   curl         4  127.0.0.1        127.0.0.1        33495\n17841   curl         6  ::1              ::1              41549\n17843   curl         4  127.0.0.1        127.0.0.1        33495\n17845   curl         6  ::1              ::1              41549\n17847   curl         4  127.0.0.1        127.0.0.1        33495\n17849   curl         6  ::1              ::1              41549\n17851   curl         4  127.0.0.1        127.0.0.1        33495\n17853   curl         6  ::1              ::1              41549\n17855   curl         4  127.0.0.1        127.0.0.1        33495\n17857   curl         6  ::1              ::1              41549\n17859   curl         4  127.0.0.1        127.0.0.1        33495\n17861   curl         6  ::1              ::1              41549\n17863   curl         4  127.0.0.1        127.0.0.1        33495\n17865   curl         6  ::1              ::1              41549\n17867   curl         4  127.0.0.1        127.0.0.1        33495\n17869   curl         6  ::1              ::1              41549\n17871   curl         4  127.0.0.1        127.0.0.1        33495\n17873   curl         6  ::1              ::1              41549\n17875   curl         4  127.0.0.1        127.0.0.1        33495\n17877   curl         6  ::1              ::1              41549\n17879   curl         4  127.0.0.1        127.0.0.1        33495\n17881   curl         6  ::1              ::1              41549\n17883   curl         4  127.0.0.1        127.0.0.1        33495\n17885   curl         6  ::1              ::1              41549\n17887   curl         4  127.0.0.1        127.0.0.1        33495\n17889   curl         6  ::1              ::1              41549\n17891   curl         4  127.0.0.1        127.0.0.1        33495\n17893   curl         6  ::1              ::1              41549\n17895   curl         4  127.0.0.1        127.0.0.1        33495\n17897   curl         6  ::1              ::1              41549\n17899   curl         4  127.0.0.1        127.0.0.1        33495\n17901   curl         6  ::1              ::1              41549\n17903   curl         4  127.0.0.1        127.0.0.1        33495\n17905   curl         6  ::1              ::1              41549\n17907   curl         4  127.0.0.1        127.0.0.1        33495"
}
```

## bindsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1459": {
        "avg_ns_per_run": 55.617885890429505,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1459,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 2001287,
        "run_time_ns_delta": 111307352,
        "type": "kprobe"
      },
      "1460": {
        "avg_ns_per_run": 816.7165705285796,
        "bytes_jited": 721,
        "bytes_xlated": 1160,
        "id": 1460,
        "name": "bindsnoop_v4_return",
        "run_cnt_delta": 1000644,
        "run_time_ns_delta": 817242536,
        "type": "kprobe"
      },
      "1461": {
        "avg_ns_per_run": 787.2666215623354,
        "bytes_jited": 742,
        "bytes_xlated": 1184,
        "id": 1461,
        "name": "bindsnoop_v6_return",
        "run_cnt_delta": 1000643,
        "run_time_ns_delta": 787772834,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 200128.5392967806
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
      "1459": {
        "avg_ns_per_run": 53.48420219031151,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 1459,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 1995150,
        "run_time_ns_delta": 106709006,
        "type": "kprobe"
      },
      "1460": {
        "avg_ns_per_run": 817.7359576974162,
        "bytes_jited": 719,
        "bytes_xlated": 1160,
        "id": 1460,
        "name": "bindsnoop_v4_re",
        "run_cnt_delta": 997575,
        "run_time_ns_delta": 815752948,
        "type": "kprobe"
      },
      "1461": {
        "avg_ns_per_run": 793.8158785053755,
        "bytes_jited": 740,
        "bytes_xlated": 1184,
        "id": 1461,
        "name": "bindsnoop_v6_re",
        "run_cnt_delta": 997575,
        "run_time_ns_delta": 791890875,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 199514.9519368483
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
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.eaedd1c2/bcc-python-7nc74m8y/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:18:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0\n    1721 python3      IP   127.0.0.1       16000 ..NR.  0\n    1721 python3      IP   ::1             19328 ..NR.  0"
}
```

