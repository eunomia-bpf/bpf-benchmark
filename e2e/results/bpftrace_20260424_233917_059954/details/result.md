# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-24T23:42:02.764365+00:00`
- Duration per phase: `5s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## tcplife

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1348": {
        "avg_ns_per_run": 524.9008862697787,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 21551,
        "run_time_ns_delta": 11312139,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 431.021191117478
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
      "1348": {
        "avg_ns_per_run": 550.4453532647017,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 21273,
        "run_time_ns_delta": 11709624,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 425.5096723812395
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
  "output_chars": 7027,
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
  "stderr_tail": "tar: ./include/xen/interface/io/netif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/pciif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/protocols.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/pvcalls.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/ring.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/sndif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/tpmif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/usbif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/vscsiif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/xenbus.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/xs_wire.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/memory.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/nmi.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/physdev.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/platform.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/sched.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/vcpu.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/version.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xen-mca.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xenpmu.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/mem-reservation.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/page.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/pci.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/platform_pci.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/swiotlb-xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen-front-pgdir-shbuf.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen-ops.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xenbus.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xenbus_dev.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings/input/linux-event-codes.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings/input: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: .: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: Exiting with failure status due to previous errors",
  "stdout_tail": "32761 curl       127.0.0.1       43261 127.0.0.1       54990      0     0 0\n32761 curl       127.0.0.1       54990 127.0.0.1       43261      0     0 0\n32763 curl       0.0.0.0         38441 0.0.0.0         44652      0     0 0\n32763 curl       0.0.0.0         44652 0.0.0.0         38441      0     0 0\n32765 curl       127.0.0.1       43261 127.0.0.1       55000      0     0 0\n32765 curl       127.0.0.1       55000 127.0.0.1       43261      0     0 0\n32767 curl       0.0.0.0         38441 0.0.0.0         44666      0     0 0\n32767 curl       0.0.0.0         44666 0.0.0.0         38441      0     0 0\n301   curl       127.0.0.1       43261 127.0.0.1       55010      0     0 0\n301   curl       127.0.0.1       55010 127.0.0.1       43261      0     0 0\n303   curl       0.0.0.0         38441 0.0.0.0         44678      0     0 0\n303   curl       0.0.0.0         44678 0.0.0.0         38441      0     0 0\n305   curl       127.0.0.1       43261 127.0.0.1       55024      0     0 0\n305   curl       127.0.0.1       55024 127.0.0.1       43261      0     0 0\n307   curl       0.0.0.0         38441 0.0.0.0         44684      0     0 0\n307   curl       0.0.0.0         44684 0.0.0.0         38441      0     0 0\n309   curl       127.0.0.1       43261 127.0.0.1       55036      0     0 0\n309   curl       127.0.0.1       55036 127.0.0.1       43261      0     0 0\n311   curl       0.0.0.0         38441 0.0.0.0         44694      0     0 0\n311   curl       0.0.0.0         44694 0.0.0.0         38441      0     0 0\n313   curl       127.0.0.1       43261 127.0.0.1       55046      0     0 0\n313   curl       127.0.0.1       55046 127.0.0.1       43261      0     0 0\n315   curl       0.0.0.0         38441 0.0.0.0         44710      0     0 0\n315   curl       0.0.0.0         44710 0.0.0.0         38441      0     0 0\n317   curl       127.0.0.1       43261 127.0.0.1       55052      0     0 0\n317   curl       127.0.0.1       55052 127.0.0.1       43261      0     0 0\n319   curl       0.0.0.0         38441 0.0.0.0         44722      0     0 0\n319   curl       0.0.0.0         44722 0.0.0.0         38441      0     0 0\n321   curl       127.0.0.1       43261 127.0.0.1       55066      0     0 0\n321   curl       127.0.0.1       55066 127.0.0.1       43261      0     0 0\n323   curl       0.0.0.0         38441 0.0.0.0         44726      0     0 0\n323   curl       0.0.0.0         44726 0.0.0.0         38441      0     0 0\n325   curl       127.0.0.1       43261 127.0.0.1       55078      0     0 0\n325   curl       127.0.0.1       55078 127.0.0.1       43261      0     0 0\n327   curl       0.0.0.0         38441 0.0.0.0         44740      0     0 0\n327   curl       0.0.0.0         44740 0.0.0.0         38441      0     0 0\n329   curl       127.0.0.1       43261 127.0.0.1       55094      0     0 0\n329   curl       127.0.0.1       55094 127.0.0.1       43261      0     0 0\n331   curl       0.0.0.0         38441 0.0.0.0         44746      0     0 0\n331   curl       0.0.0.0         44746 0.0.0.0         38441      0     0 0"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1355": {
        "avg_ns_per_run": 121.23310466340011,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 4759553,
        "run_time_ns_delta": 577015387,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 389.15241221181907,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 4759553,
        "run_time_ns_delta": 1852191531,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 951152.545810787
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
      "1355": {
        "avg_ns_per_run": 121.45460529861737,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 4694017,
        "run_time_ns_delta": 570109982,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 402.8192888947782,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 4694017,
        "run_time_ns_delta": 1890840590,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 937906.3043990792
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
  "output_chars": 12597,
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
  "stderr_tail": "tar: ./include/xen/interface/io/netif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/pciif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/protocols.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/pvcalls.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/ring.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/sndif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/tpmif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/usbif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/vscsiif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/xenbus.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/xs_wire.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/memory.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/nmi.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/physdev.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/platform.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/sched.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/vcpu.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/version.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xen-mca.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xenpmu.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/mem-reservation.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/page.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/pci.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/platform_pci.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/swiotlb-xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen-front-pgdir-shbuf.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen-ops.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xenbus.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xenbus_dev.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings/input/linux-event-codes.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings/input: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: .: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: Exiting with failure status due to previous errors",
  "stdout_tail": "12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0\n12264        252   0        dd               2805         0"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1363": {
        "avg_ns_per_run": 98.2584185007368,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 420740,
        "run_time_ns_delta": 41341247,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 174.94745380166455,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "tracepoint_sched_sched_wakeup_new",
        "run_cnt_delta": 85068,
        "run_time_ns_delta": 14882430,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 150.97038419292028,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 801160,
        "run_time_ns_delta": 120951433,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 66.15638619070326
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
      "1363": {
        "avg_ns_per_run": 99.40173467811348,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 407799,
        "run_time_ns_delta": 40535928,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 175.5274036173251,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 84040,
        "run_time_ns_delta": 14751323,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 150.6729885292808,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 781468,
        "run_time_ns_delta": 117746119,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 65.31154024729089
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
  "output_chars": 13109,
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
  "stderr_tail": "tar: ./include/xen/interface/io/netif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/pciif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/protocols.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/pvcalls.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/ring.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/sndif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/tpmif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/usbif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/vscsiif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/xenbus.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/xs_wire.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/memory.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/nmi.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/physdev.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/platform.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/sched.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/vcpu.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/version.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xen-mca.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xenpmu.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/mem-reservation.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/page.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/pci.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/platform_pci.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/swiotlb-xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen-front-pgdir-shbuf.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen-ops.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xenbus.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xenbus_dev.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings/input/linux-event-codes.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings/input: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: .: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: Exiting with failure status due to previous errors",
  "stdout_tail": "Tracing CPU scheduler... Hit Ctrl-C to end.\n@usecs:\n[0]               441720 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n[1]               168879 |@@@@@@@@@@@@@@@@@@@                                 |\n[2, 4)            240623 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@                        |\n[4, 8)             70529 |@@@@@@@@                                            |\n[8, 16)            50251 |@@@@@                                               |\n[16, 32)           24195 |@@                                                  |\n[32, 64)           28193 |@@@                                                 |\n[64, 128)          18485 |@@                                                  |\n[128, 256)         15797 |@                                                   |\n[256, 512)         19651 |@@                                                  |\n[512, 1K)          21722 |@@                                                  |\n[1K, 2K)           27468 |@@@                                                 |\n[2K, 4K)           45933 |@@@@@                                               |\n[4K, 8K)           52466 |@@@@@@                                              |\n[8K, 16K)           7076 |                                                    |"
}
```

## tcpretrans

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1372": {
        "avg_ns_per_run": 12795.333333333334,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "kprobe_tcp_retransmit_skb",
        "run_cnt_delta": 15,
        "run_time_ns_delta": 191930,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 0.4892688346633737
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
      "1372": {
        "avg_ns_per_run": 10072.166666666666,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "tcp_retransmit_",
        "run_cnt_delta": 18,
        "run_time_ns_delta": 181299,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 0.489088338357902
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
  "output_chars": 5744,
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
  "stderr_tail": "tar: ./include/xen/interface/io/netif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/pciif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/protocols.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/pvcalls.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/ring.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/sndif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/tpmif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/usbif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/vscsiif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/xenbus.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/xs_wire.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/memory.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/nmi.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/physdev.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/platform.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/sched.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/vcpu.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/version.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xen-mca.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xenpmu.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/mem-reservation.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/page.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/pci.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/platform_pci.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/swiotlb-xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen-front-pgdir-shbuf.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen-ops.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xenbus.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xenbus_dev.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings/input/linux-event-codes.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings/input: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: .: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: Exiting with failure status due to previous errors",
  "stdout_tail": "Tracing tcp retransmits. Hit Ctrl-C to end.\nTIME     PID               LADDR:LPORT           RADDR:RPORT  STATE\n23:40:52 0             127.0.0.1:44569       127.0.0.1:57804  ESTABLISHED\n23:40:53 0             127.0.0.1:44569       127.0.0.1:57804  FIN_WAIT1\n23:40:54 0             127.0.0.1:44569       127.0.0.1:57804  FIN_WAIT1\n23:40:55 0             127.0.0.1:39189       127.0.0.1:60778  ESTABLISHED\n23:40:55 0             127.0.0.1:39189       127.0.0.1:60778  FIN_WAIT1\n23:40:56 0             127.0.0.1:44569       127.0.0.1:57804  CLOSING\n23:40:56 0             127.0.0.1:39189       127.0.0.1:60778  FIN_WAIT1\n23:40:57 0             127.0.0.1:41707       127.0.0.1:53618  ESTABLISHED\n23:40:58 0             127.0.0.1:41707       127.0.0.1:53618  FIN_WAIT1\n23:40:58 0             127.0.0.1:39189       127.0.0.1:60778  CLOSING\n23:40:59 0             127.0.0.1:41707       127.0.0.1:53618  FIN_WAIT1\n23:40:59 0             127.0.0.1:44569       127.0.0.1:57804  CLOSING\n23:41:00 0             127.0.0.1:41737       127.0.0.1:54100  ESTABLISHED\n23:41:00 0             127.0.0.1:41737       127.0.0.1:54100  FIN_WAIT1\n23:41:00 23            127.0.0.1:41737       127.0.0.1:54100  FIN_WAIT1\n23:41:00 0             127.0.0.1:41707       127.0.0.1:53618  CLOSING\n23:41:01 0             127.0.0.1:37169       127.0.0.1:58586  ESTABLISHED\n23:41:01 0             127.0.0.1:37169       127.0.0.1:58586  FIN_WAIT1\n23:41:01 0             127.0.0.1:39189       127.0.0.1:60778  CLOSING\n23:41:02 0             127.0.0.1:37169       127.0.0.1:58586  FIN_WAIT1\n23:41:03 0             127.0.0.1:37075       127.0.0.1:55854  ESTABLISHED\n23:41:04 0             127.0.0.1:37075       127.0.0.1:55854  FIN_WAIT1\n23:41:04 0             127.0.0.1:37169       127.0.0.1:58586  CLOSING\n23:41:04 0             127.0.0.1:37075       127.0.0.1:55854  FIN_WAIT1\n23:41:06 0             127.0.0.1:43777       127.0.0.1:55326  ESTABLISHED\n23:41:06 0             127.0.0.1:44569       127.0.0.1:57804  CLOSING\n23:41:06 0             127.0.0.1:37075       127.0.0.1:55854  CLOSING\n23:41:06 0             127.0.0.1:43777       127.0.0.1:55326  FIN_WAIT1\n23:41:07 0             127.0.0.1:37169       127.0.0.1:58586  CLOSING\n23:41:07 0             127.0.0.1:43777       127.0.0.1:55326  FIN_WAIT1\n23:41:08 0             127.0.0.1:33503       127.0.0.1:45742  ESTABLISHED\n23:41:09 0             127.0.0.1:39189       127.0.0.1:60778  CLOSING\n23:41:09 0             127.0.0.1:33503       127.0.0.1:45742  FIN_WAIT1\n23:41:09 23            127.0.0.1:33503       127.0.0.1:45742  FIN_WAIT1"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1379": {
        "avg_ns_per_run": 116.9858425146909,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 1368534,
        "run_time_ns_delta": 160099103,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2387.105377055494
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
      "1379": {
        "avg_ns_per_run": 118.37820209918952,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 1365003,
        "run_time_ns_delta": 161586601,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2390.1647076556965
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
  "output_chars": 5259,
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
  "stderr_tail": "tar: ./include/xen/interface/io/netif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/pciif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/protocols.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/pvcalls.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/ring.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/sndif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/tpmif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/usbif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/vscsiif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/xenbus.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/xs_wire.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/memory.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/nmi.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/physdev.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/platform.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/sched.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/vcpu.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/version.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xen-mca.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xenpmu.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/mem-reservation.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/page.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/pci.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/platform_pci.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/swiotlb-xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen-front-pgdir-shbuf.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen-ops.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xenbus.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xenbus_dev.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings/input/linux-event-codes.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings/input: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: .: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: Exiting with failure status due to previous errors",
  "stdout_tail": "23:41:34  65534  14184  stress-ng        21   CAP_SYS_ADMIN        2\n23:41:34  65534  14184  stress-ng        21   CAP_SYS_ADMIN        2\n23:41:34  65534  14184  stress-ng        21   CAP_SYS_ADMIN        2\n23:41:34  65534  14184  stress-ng        21   CAP_SYS_ADMIN        2\n23:41:34  65534  14184  stress-ng        21   CAP_SYS_ADMIN        2\n23:41:34  65534  14184  stress-ng        21   CAP_SYS_ADMIN        2\n23:41:34  65534  14162  stress-ng        21   CAP_SYS_ADMIN        2\n23:41:34  65534  14156  stress-ng        21   CAP_SYS_ADMIN        2\n23:41:34  65534  14184  stress-ng        21   CAP_SYS_ADMIN        2\nLost 43335 events\n23:41:34  65534  14184  stress-ng        21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  python3          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        2\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        0\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        0\n23:41:34  0      14197  bpftool          39   CAP_BPF              0\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        0\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        0\n23:41:34  0      14197  bpftool          39   CAP_BPF              0\n23:41:34  0      14197  bpftool          39   CAP_BPF              0\n23:41:34  0      14197  bpftool          39   CAP_BPF              0\n23:41:34  0      14197  bpftool          39   CAP_BPF              0\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        0\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        0\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        0\n23:41:34  0      14197  bpftool          21   CAP_SYS_ADMIN        0"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1386": {
        "avg_ns_per_run": 1676.8,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 8384,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 151.24607703281026,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 1402,
        "run_time_ns_delta": 212047,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 66.4976460783827
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
      "1386": {
        "avg_ns_per_run": 1572.2,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 7861,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 309.56973293768544,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 1348,
        "run_time_ns_delta": 417300,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 63.94490986152979
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
  "output_chars": 8219,
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
  "stderr_tail": "tar: ./include/xen/interface/io/netif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/pciif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/protocols.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/pvcalls.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/ring.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/sndif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/tpmif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/usbif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/vscsiif.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/xenbus.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io/xs_wire.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/io: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/memory.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/nmi.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/physdev.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/platform.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/sched.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/vcpu.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/version.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xen-mca.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface/xenpmu.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/interface: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/mem-reservation.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/page.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/pci.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/platform_pci.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/swiotlb-xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen-front-pgdir-shbuf.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen-ops.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xen.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xenbus.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen/xenbus_dev.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/xen: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings/input/linux-event-codes.h: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings/input: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include/dt-bindings: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: ./include: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: .: Cannot change ownership to uid 0, gid 0: Operation not permitted\ntar: Exiting with failure status due to previous errors",
  "stdout_tail": "23:41:51\n@[vfs_write]: 62\n@[vfs_open]: 103\n@[vfs_read]: 150\n23:41:52\n@[vfs_open]: 66\n@[vfs_write]: 67\n@[vfs_read]: 133\n23:41:53\n@[vfs_open]: 67\n@[vfs_write]: 68\n@[vfs_read]: 135\n23:41:54\n@[vfs_open]: 66\n@[vfs_write]: 70\n@[vfs_read]: 136\n23:41:55\n@[vfs_open]: 70\n@[vfs_write]: 70\n@[vfs_read]: 139\n23:41:56\n@[vfs_write]: 56\n@[vfs_open]: 107\n@[vfs_read]: 150\n23:41:57\n@[vfs_open]: 63\n@[vfs_write]: 65\n@[vfs_read]: 127\n23:41:58\n@[vfs_open]: 64\n@[vfs_write]: 64\n@[vfs_read]: 128\n23:41:59\n@[vfs_open]: 63\n@[vfs_write]: 65\n@[vfs_read]: 128\n23:42:00\n@[vfs_open]: 65\n@[vfs_write]: 66\n@[vfs_read]: 132"
}
```

