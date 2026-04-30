# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-29T10:44:53.798865+00:00`
- Duration per phase: `10s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Tools dir: `/usr/sbin`
- Setup rc: `0`
- Error: `tcplife baseline failed: daemon session exited early (rc=1); biosnoop baseline failed: daemon session exited early (rc=1); runqlat baseline failed: daemon session exited early (rc=1); syscount baseline failed: daemon session exited early (rc=1); execsnoop baseline failed: daemon session exited early (rc=1); opensnoop baseline failed: daemon session exited early (rc=1); capable baseline failed: daemon session exited early (rc=1); vfsstat baseline failed: daemon session exited early (rc=1); tcpconnect baseline failed: daemon session exited early (rc=1); bindsnoop baseline failed: daemon session exited early (rc=1)`

## tcplife

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "In file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/bcc-python-euie5jw1/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/bcc-python-euie5jw1/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/tcp.h:7:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "PID   COMM       LADDR           LPORT RADDR           RPORT TX_KB RX_KB MS\n13113 stress-ng- 127.0.0.1       55210 127.0.0.1       22087     0 408800 35.55\n13113 stress-ng- 127.0.0.1       22087 127.0.0.1       55210 408800     0 35.55"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "In file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/bcc-python-mb3cq8y1/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/blk-mq.h:5:\nIn file included from include/linux/blkdev.h:7:\nIn file included from include/linux/blk_types.h:7:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "3.815885    fio            13152   loop0     R 93093376   4096      2.46\n3.817701    fio            13152   loop0     R 93154216   4096      1.79\n3.819528    fio            13152   loop0     R 93179376   4096      1.81\n3.821764    fio            13152   loop0     R 93139344   4096      2.22\n3.823653    fio            13152   loop0     R 93140608   4096      1.85\n3.825905    fio            13152   loop0     R 93176896   4096      2.24\n3.827626    fio            13152   loop0     R 93159048   4096      1.71\n3.829472    fio            13152   loop0     R 93122248   4096      1.81\n3.831757    fio            13152   loop0     R 93098456   4096      2.25\n3.833879    fio            13152   loop0     R 93120192   4096      2.11\n3.836514    fio            13152   loop0     R 93107296   4096      2.62\n3.838393    fio            13152   loop0     R 93132968   4096      1.86\n3.840204    fio            13152   loop0     R 93118840   4096      1.80\n3.842950    fio            13152   loop0     R 93159728   4096      2.73\n3.845529    fio            13152   loop0     R 93109040   4096      2.55\n3.848368    fio            13152   loop0     R 93114096   4096      2.82\n3.850878    fio            13152   loop0     R 93180104   4096      2.48\n3.852975    fio            13152   loop0     R 93179680   4096      2.07\n3.855426    fio            13152   loop0     R 93176344   4096      2.41\n3.858190    fio            13152   loop0     R 93135968   4096      2.74\n3.860345    fio            13152   loop0     R 93069896   4096      2.13\n3.862352    fio            13152   loop0     R 93065624   4096      1.98\n3.864415    fio            13152   loop0     R 93069752   4096      2.05\n3.866904    fio            13152   loop0     R 93098976   4096      2.45\n3.869208    fio            13152   loop0     R 93158704   4096      2.29\n3.871144    fio            13152   loop0     R 93159200   4096      1.90\n3.873841    fio            13152   loop0     R 93075584   4096      2.68\n3.876192    fio            13152   loop0     R 93168976   4096      2.33\n3.878542    fio            13152   loop0     R 93099376   4096      2.32\n3.880750    fio            13152   loop0     R 93117752   4096      2.19\n3.882918    fio            13152   loop0     R 93183784   4096      2.15\n3.885053    fio            13152   loop0     R 93092344   4096      2.11\n3.887053    fio            13152   loop0     R 93149704   4096      1.99\n3.889533    fio            13152   loop0     R 93157384   4096      2.44\n3.891755    fio            13152   loop0     R 93119752   4096      2.18\n3.893812    fio            13152   loop0     R 93179288   4096      2.03\n3.896041    fio            13152   loop0     R 93066424   4096      2.21\n3.898290    fio            13152   loop0     R 93106080   4096      2.23\n3.900137    fio            13152   loop0     R 93093168   4096      1.83\n3.903559    fio            13152   loop0     R 93111664   4096      3.40"
}
```

## runqlat

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "In file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/bcc-python-wp7q3_8t/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/bcc-python-wp7q3_8t/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:6:\nIn file included from include/linux/pid_namespace.h:7:\nIn file included from include/linux/mm.h:1118:\nIn file included from include/linux/huge_mm.h:7:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "Tracing run queue latency... Hit Ctrl-C to end.\n     usecs               : count     distribution\n         0 -> 1          : 17230    |****************************************|\n         2 -> 3          : 681      |*                                       |\n         4 -> 7          : 260      |                                        |\n         8 -> 15         : 416      |                                        |\n        16 -> 31         : 181      |                                        |\n        32 -> 63         : 102      |                                        |\n        64 -> 127        : 87       |                                        |\n       128 -> 255        : 28       |                                        |\n       256 -> 511        : 7        |                                        |\n       512 -> 1023       : 6        |                                        |\n      1024 -> 2047       : 2        |                                        |"
}
```

## syscount

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/bcc-python-acj6s08o/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/bcc-python-acj6s08o/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "clock_nanosleep               5      1801080.916\nTracing syscalls, printing top 10... Ctrl+C to quit.\n[10:43:24]\nSYSCALL                   COUNT        TIME (us)\nnanosleep                     1        10205.779\npoll                         10         7346.964\nvfork                         5         3172.286\nexecve                        5         1155.597\nread                       1462         1118.500\nmmap                        150          860.117\nopenat                       56          456.758\nclose                       141          362.621\nnewfstatat                   35          284.011\nclock_nanosleep               6      2001280.854\n[10:43:25]\nSYSCALL                   COUNT        TIME (us)\nfutex                         3      1637865.955\nepoll_pwait                   3       823991.067\nnanosleep                     1        10164.142\npoll                         10         4450.119\nvfork                         5         3063.803\nexecve                        5          943.375\nmmap                        150          514.542\nopenat                       55          283.685\nclose                       140          261.961\nfutex                        10      1637729.309\n[10:43:25]\nSYSCALL                   COUNT        TIME (us)\nread                       7744      1012923.123\nclock_nanosleep              14       893056.503\nepoll_pwait                   4       823936.706\nwait4                      1020       709038.752\npoll                         32       553758.718\nopenat                     8496        74807.008\nclone                      1007        63777.291\nstatfs                     9216        51428.796\nclose                      9401        27823.688\nDetaching..."
}
```

## execsnoop

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/bcc-python-7ua4fbb7/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/bcc-python-7ua4fbb7/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "TIME     UID   PCOMM            PID     PPID    RET ARGS"
}
```

## opensnoop

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "Possibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 141 samples",
  "stdout_tail": "16200  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index1/level\n16200  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index1/coherency_line_size\n16200  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index1/ways_of_associativity\n16200  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/type\n16200  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/size\n16200  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/level\n16200  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/coherency_line_size\n16200  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/ways_of_associativity\n16200  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/type\n16200  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/size\n16200  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/level\n16200  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/coherency_line_size\n16200  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/ways_of_associativity\n16200  stress-ng           3   0 /sys/kernel/debug/clear_warn_once\n16200  stress-ng           3   0 /sys/devices/system/clocksource\n16200  stress-ng           4   0 /sys/devices/system/clocksource/clocksource0/current_clocksource\n16200  stress-ng           3   0 /proc/sys/kernel/sched_autogroup_enabled\n16200  stress-ng           3   0 /sys/devices/system/cpu\n16200  stress-ng          -1   2 /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor\n16200  stress-ng          -1   2 /sys/devices/system/cpu/cpu1/cpufreq/scaling_governor\n16200  stress-ng          -1   2 /sys/devices/system/cpu/cpu2/cpufreq/scaling_governor\n16200  stress-ng          -1   2 /sys/devices/system/cpu/cpu3/cpufreq/scaling_governor\n16201  stress-ng-utime     3   0 /proc/self/coredump_filter\n16201  stress-ng-utime     3   0 /proc/self/oom_score_adj\n16201  stress-ng-utime     3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/tmp-stress-ng-utime-16201-0\n16201  stress-ng-utime     4   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/tmp-stress-ng-utime-16201-0/stress-ng-utime-16201-0-2003580583\n16200  stress-ng           3   0 /sys/devices/system/clocksource\n16200  stress-ng           4   0 /sys/devices/system/clocksource/clocksource0/current_clocksource\n16202  bpftool             3   0 /etc/ld.so.cache\n16202  bpftool             3   0 /lib/x86_64-linux-gnu/libelf.so.1\n16202  bpftool             3   0 /lib/x86_64-linux-gnu/libcrypto.so.3\n16202  bpftool             3   0 /lib/x86_64-linux-gnu/libz.so.1\n16202  bpftool             3   0 /lib/x86_64-linux-gnu/libcap.so.2\n16202  bpftool             3   0 /lib/x86_64-linux-gnu/libc.so.6\n16202  bpftool             3   0 /lib/x86_64-linux-gnu/libzstd.so.1\n16202  bpftool             4   0 /etc/localtime\n16202  bpftool             4   0 /proc/self/fdinfo/3\n16202  bpftool             4   0 /proc/self/fdinfo/3\n16202  bpftool             4   0 /proc/self/fdinfo/3\n16202  bpftool             4   0 /proc/self/fdinfo/3"
}
```

## capable

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "Possibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 4 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 4 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 3 samples\nPossibly lost 3 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 4 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 3 samples\nPossibly lost 2 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 3 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 2 samples",
  "stdout_tail": "10:44:18  0      17233  stress-ng-set    21   CAP_SYS_ADMIN        1\n10:44:18  0      17233  stress-ng-set    6    CAP_SETGID           1\n10:44:18  0      17233  stress-ng-set    21   CAP_SYS_ADMIN        1\n10:44:18  0      17233  stress-ng-set    21   CAP_SYS_ADMIN        1\n10:44:18  0      17233  stress-ng-set    6    CAP_SETGID           1\n10:44:18  0      17233  stress-ng-set    6    CAP_SETGID           1\n10:44:18  0      17233  stress-ng-set    6    CAP_SETGID           1\n10:44:18  0      17233  stress-ng-set    21   CAP_SYS_ADMIN        1\n10:44:18  0      17233  stress-ng-set    21   CAP_SYS_ADMIN        1\n10:44:18  0      17233  stress-ng-set    21   CAP_SYS_ADMIN        1\n10:44:18  0      17233  stress-ng-set    6    CAP_SETGID           1\n10:44:18  0      17233  stress-ng-set    21   CAP_SYS_ADMIN        1\n10:44:18  0      17233  stress-ng-set    7    CAP_SETUID           1\n10:44:18  0      17233  stress-ng-set    6    CAP_SETGID           1\n10:44:18  0      17233  stress-ng-set    21   CAP_SYS_ADMIN        1\n10:44:18  0      17233  stress-ng-set    21   CAP_SYS_ADMIN        1\n10:44:18  0      17233  stress-ng-set    21   CAP_SYS_ADMIN        1\n10:44:18  0      17233  stress-ng-set    6    CAP_SETGID           1\n10:44:18  0      17233  stress-ng-set    21   CAP_SYS_ADMIN        1\n10:44:18  0      17233  stress-ng-set    21   CAP_SYS_ADMIN        1\n10:44:18  0      17233  stress-ng-set    7    CAP_SETUID           1\n10:44:18  0      17233  stress-ng-set    6    CAP_SETGID           1\n10:44:18  0      17233  stress-ng-set    6    CAP_SETGID           1\n10:44:18  0      17233  stress-ng-set    21   CAP_SYS_ADMIN        1\n10:44:18  0      17234  stress-ng        24   CAP_SYS_RESOURCE     1\n10:44:18  0      17235  stress-ng-timer  21   CAP_SYS_ADMIN        1\n10:44:18  0      17235  stress-ng-timer  21   CAP_SYS_ADMIN        1\n10:44:18  0      17235  stress-ng-timer  21   CAP_SYS_ADMIN        1\n10:44:18  0      17235  stress-ng-timer  21   CAP_SYS_ADMIN        1\n10:44:18  0      17236  bpftool          21   CAP_SYS_ADMIN        1\n10:44:18  0      17236  bpftool          21   CAP_SYS_ADMIN        1\n10:44:18  0      17236  bpftool          39   CAP_BPF              1\n10:44:18  0      17236  bpftool          21   CAP_SYS_ADMIN        1\n10:44:18  0      17236  bpftool          21   CAP_SYS_ADMIN        1\n10:44:18  0      17236  bpftool          39   CAP_BPF              1\n10:44:18  0      17236  bpftool          39   CAP_BPF              1\n10:44:18  0      17236  bpftool          39   CAP_BPF              1\n10:44:18  0      17236  bpftool          39   CAP_BPF              1\n10:44:18  0      17236  bpftool          21   CAP_SYS_ADMIN        1\n10:44:18  0      17236  bpftool          21   CAP_SYS_ADMIN        1"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/bcc-python-qnd6ur_d/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/bcc-python-qnd6ur_d/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "TIME         READ/s  WRITE/s  FSYNC/s   OPEN/s CREATE/s\n10:44:20:      1489        7        0      132        0\n10:44:21:       100        5        0      130        0\n10:44:22:      1174       39       14     9545        3\n10:44:23:         0        0       58        0        0\n10:44:24:       380       14       63      435        1\n10:44:25:         0        0       62        0        0\n10:44:26:      1521       57       53    28637     2001\n10:44:27:      3521     4355       34    11781     2513\n10:44:28:         1        1        0        0        0\n10:44:29:         0        0        0        0        0\n10:44:30:         1        1        0        0        0\n10:44:31:         0        0        0        0        0\n10:44:32:         0        0        0        0        0\n10:44:33:         0        0        0        0        0\n10:44:34:         0        0        0        0        0\n10:44:35:         0        0        0        0        0\n10:44:36:         0        0        0        0        0\n10:44:37:      1519      188        0     2745        4\n10:44:38:        15       11        0       38       10\n10:44:39:        13       11        0       42       11\n10:44:40:        15       11        0       38       10\n10:44:41:        13       11        0       42       11\n10:44:42:        18       14        0       54       15\n10:44:43:        35       27        0      100       26\n10:44:44:       880       42       18     1246       73\n10:44:44:       784       35       15     1363      218"
}
```

## tcpconnect

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/bcc-python-nb0k3jik/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:16:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "18142   stress-ng-so 4  127.0.0.1        127.0.0.1        22087\nTracing connect ... Hit Ctrl-C to end\nPID     COMM         IP SADDR            DADDR            DPORT"
}
```

## bindsnoop

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.1d12911c/bcc-python-jd9o3xgu/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:18:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "   18182 stress-ng-sc IP   0.0.0.0         21987 ..NR.  0\nTracing binds ... Hit Ctrl-C to end\n     PID COMM         PROT ADDR            PORT   OPTS IF\n   18185 stress-ng-so IP   0.0.0.0         22087 ..NR.  0"
}
```

