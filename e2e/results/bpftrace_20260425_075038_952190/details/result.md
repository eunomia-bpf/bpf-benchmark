# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-25T07:53:24.208239+00:00`
- Duration per phase: `5s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## tcplife

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1348": {
        "avg_ns_per_run": 618.0057082452431,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 18920,
        "run_time_ns_delta": 11692668,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 378.3771379846373
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
        "avg_ns_per_run": 651.1563991206906,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 18651,
        "run_time_ns_delta": 12144718,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 373.12576804632573
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
  "stdout_tail": "31131 curl       127.0.0.1       44041 127.0.0.1       49170      0     0 0\n31131 curl       127.0.0.1       49170 127.0.0.1       44041      0     0 0\n31133 curl       0.0.0.0         34631 0.0.0.0         57202      0     0 0\n31133 curl       0.0.0.0         57202 0.0.0.0         34631      0     0 0\n31135 curl       127.0.0.1       44041 127.0.0.1       49178      0     0 0\n31135 curl       127.0.0.1       49178 127.0.0.1       44041      0     0 0\n31137 curl       0.0.0.0         34631 0.0.0.0         57214      0     0 0\n31137 curl       0.0.0.0         57214 0.0.0.0         34631      0     0 0\n31139 curl       127.0.0.1       44041 127.0.0.1       49192      0     0 0\n31139 curl       127.0.0.1       49192 127.0.0.1       44041      0     0 0\n31141 curl       0.0.0.0         34631 0.0.0.0         57218      0     0 0\n31141 curl       0.0.0.0         57218 0.0.0.0         34631      0     0 0\n31143 curl       127.0.0.1       44041 127.0.0.1       49200      0     0 0\n31143 curl       127.0.0.1       49200 127.0.0.1       44041      0     0 0\n31145 curl       0.0.0.0         34631 0.0.0.0         57230      0     0 0\n31145 curl       0.0.0.0         57230 0.0.0.0         34631      0     0 0\n31147 curl       127.0.0.1       44041 127.0.0.1       49210      0     0 0\n31147 curl       127.0.0.1       49210 127.0.0.1       44041      0     0 0\n31149 curl       0.0.0.0         34631 0.0.0.0         57246      0     0 0\n31149 curl       0.0.0.0         57246 0.0.0.0         34631      0     0 0\n31151 curl       127.0.0.1       44041 127.0.0.1       49214      0     0 0\n31151 curl       127.0.0.1       49214 127.0.0.1       44041      0     0 0\n31153 curl       0.0.0.0         34631 0.0.0.0         57256      0     0 0\n31153 curl       0.0.0.0         57256 0.0.0.0         34631      0     0 0\n31155 curl       127.0.0.1       44041 127.0.0.1       49226      0     0 0\n31155 curl       127.0.0.1       49226 127.0.0.1       44041      0     0 0\n31157 curl       0.0.0.0         34631 0.0.0.0         57266      0     0 0\n31157 curl       0.0.0.0         57266 0.0.0.0         34631      0     0 0\n31159 curl       127.0.0.1       44041 127.0.0.1       49228      0     0 0\n31159 curl       127.0.0.1       49228 127.0.0.1       44041      0     0 0\n31161 curl       0.0.0.0         34631 0.0.0.0         57282      0     0 0\n31161 curl       0.0.0.0         57282 0.0.0.0         34631      0     0 0\n31163 curl       127.0.0.1       44041 127.0.0.1       49236      0     0 0\n31163 curl       127.0.0.1       49236 127.0.0.1       44041      0     0 0\n31165 curl       0.0.0.0         34631 0.0.0.0         57286      0     0 0\n31165 curl       0.0.0.0         57286 0.0.0.0         34631      0     0 0\n31167 curl       127.0.0.1       44041 127.0.0.1       49240      0     0 0\n31167 curl       127.0.0.1       49240 127.0.0.1       44041      0     0 0\n31169 curl       0.0.0.0         34631 0.0.0.0         57290      0     0 0\n31169 curl       0.0.0.0         57290 0.0.0.0         34631      0     0 0"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1355": {
        "avg_ns_per_run": 119.61838304042327,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 4833281,
        "run_time_ns_delta": 578149258,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 339.72465743249774,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 4833281,
        "run_time_ns_delta": 1641984732,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 966105.3941222571
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
        "avg_ns_per_run": 119.41670908575598,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 4964353,
        "run_time_ns_delta": 592826698,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 328.1965353793334,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 4964353,
        "run_time_ns_delta": 1629283455,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 991716.9631566308
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
  "output_chars": 12598,
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
  "stdout_tail": "12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0\n12302        252   0        dd               1208         0"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1363": {
        "avg_ns_per_run": 101.29043913151888,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 417096,
        "run_time_ns_delta": 42247837,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 190.36644877044273,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "tracepoint_sched_sched_wakeup_new",
        "run_cnt_delta": 83526,
        "run_time_ns_delta": 15900548,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 152.83054077032983,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 795088,
        "run_time_ns_delta": 121513729,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 64.98553729971107
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
        "avg_ns_per_run": 100.79705564178543,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 425220,
        "run_time_ns_delta": 42860924,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 189.4253963282417,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 83012,
        "run_time_ns_delta": 15724581,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 151.2630249604419,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 804513,
        "run_time_ns_delta": 121693070,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 64.51356636243214
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
  "stdout_tail": "Tracing CPU scheduler... Hit Ctrl-C to end.\n@usecs:\n[0]               442665 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n[1]               185689 |@@@@@@@@@@@@@@@@@@@@@                               |\n[2, 4)            240257 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@                        |\n[4, 8)             72455 |@@@@@@@@                                            |\n[8, 16)            52662 |@@@@@@                                              |\n[16, 32)           24506 |@@                                                  |\n[32, 64)           28337 |@@@                                                 |\n[64, 128)          17915 |@@                                                  |\n[128, 256)         15648 |@                                                   |\n[256, 512)         20017 |@@                                                  |\n[512, 1K)          21378 |@@                                                  |\n[1K, 2K)           26773 |@@@                                                 |\n[2K, 4K)           43578 |@@@@@                                               |\n[4K, 8K)           53491 |@@@@@@                                              |\n[8K, 16K)           6915 |                                                    |"
}
```

## tcpretrans

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1372": {
        "avg_ns_per_run": 17482.0,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "kprobe_tcp_retransmit_skb",
        "run_cnt_delta": 16,
        "run_time_ns_delta": 279712,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 0.486912731898858
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
        "avg_ns_per_run": 14800.947368421053,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "tcp_retransmit_",
        "run_cnt_delta": 19,
        "run_time_ns_delta": 281218,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 0.48883617065079893
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
  "stdout_tail": "Tracing tcp retransmits. Hit Ctrl-C to end.\nTIME     PID               LADDR:LPORT           RADDR:RPORT  STATE\n07:52:14 0             127.0.0.1:46665       127.0.0.1:45510  ESTABLISHED\n07:52:14 0             127.0.0.1:46665       127.0.0.1:45510  FIN_WAIT1\n07:52:15 0             127.0.0.1:46665       127.0.0.1:45510  FIN_WAIT1\n07:52:17 0             127.0.0.1:38937       127.0.0.1:58754  ESTABLISHED\n07:52:17 0             127.0.0.1:38937       127.0.0.1:58754  FIN_WAIT1\n07:52:17 0             127.0.0.1:46665       127.0.0.1:45510  CLOSING\n07:52:18 0             127.0.0.1:38937       127.0.0.1:58754  FIN_WAIT1\n07:52:19 0             127.0.0.1:41479       127.0.0.1:54510  ESTABLISHED\n07:52:19 0             127.0.0.1:41479       127.0.0.1:54510  FIN_WAIT1\n07:52:20 0             127.0.0.1:38937       127.0.0.1:58754  CLOSING\n07:52:20 0             127.0.0.1:41479       127.0.0.1:54510  FIN_WAIT1\n07:52:21 0             127.0.0.1:46665       127.0.0.1:45510  CLOSING\n07:52:22 0             127.0.0.1:41223       127.0.0.1:59286  ESTABLISHED\n07:52:22 0             127.0.0.1:41479       127.0.0.1:54510  CLOSING\n07:52:22 0             127.0.0.1:41223       127.0.0.1:59286  FIN_WAIT1\n07:52:22 14            127.0.0.1:41223       127.0.0.1:59286  FIN_WAIT1\n07:52:22 0             127.0.0.1:39957       127.0.0.1:58804  ESTABLISHED\n07:52:23 0             127.0.0.1:39957       127.0.0.1:58804  FIN_WAIT1\n07:52:23 0             127.0.0.1:38937       127.0.0.1:58754  CLOSING\n07:52:24 0             127.0.0.1:39957       127.0.0.1:58804  FIN_WAIT1\n07:52:25 0             127.0.0.1:34841       127.0.0.1:35818  ESTABLISHED\n07:52:25 0             127.0.0.1:34841       127.0.0.1:35818  FIN_WAIT1\n07:52:25 0             127.0.0.1:39957       127.0.0.1:58804  CLOSING\n07:52:26 0             127.0.0.1:34841       127.0.0.1:35818  FIN_WAIT1\n07:52:27 0             127.0.0.1:42301       127.0.0.1:44670  ESTABLISHED\n07:52:28 0             127.0.0.1:46665       127.0.0.1:45510  CLOSING\n07:52:28 0             127.0.0.1:42301       127.0.0.1:44670  FIN_WAIT1\n07:52:28 0             127.0.0.1:34841       127.0.0.1:35818  CLOSING\n07:52:29 0             127.0.0.1:39957       127.0.0.1:58804  CLOSING\n07:52:29 0             127.0.0.1:42301       127.0.0.1:44670  FIN_WAIT1\n07:52:29 0             127.0.0.1:38937       127.0.0.1:58754  CLOSING\n07:52:30 0             127.0.0.1:45339       127.0.0.1:36736  ESTABLISHED\n07:52:30 0             127.0.0.1:42301       127.0.0.1:44670  CLOSING\n07:52:30 0             127.0.0.1:45339       127.0.0.1:36736  FIN_WAIT1\n07:52:30 14            127.0.0.1:45339       127.0.0.1:36736  FIN_WAIT1"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1379": {
        "avg_ns_per_run": 123.55089480107108,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 1358626,
        "run_time_ns_delta": 167859458,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2359.84100234367
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
        "avg_ns_per_run": 122.00746077622703,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 1371171,
        "run_time_ns_delta": 167293092,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2393.125380944467
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
  "stdout_tail": "07:52:56  65534  9898   stress-ng        21   CAP_SYS_ADMIN        2\n07:52:56  65534  9896   stress-ng        21   CAP_SYS_ADMIN        2\n07:52:56  65534  9898   stress-ng        21   CAP_SYS_ADMIN        2\n07:52:56  65534  9898   stress-ng        21   CAP_SYS_ADMIN        2\n07:52:56  65534  9898   stress-ng        21   CAP_SYS_ADMIN        2\n07:52:56  65534  9898   stress-ng        21   CAP_SYS_ADMIN        2\n07:52:56  65534  9898   stress-ng        21   CAP_SYS_ADMIN        2\n07:52:56  65534  9905   stress-ng        21   CAP_SYS_ADMIN        2\n07:52:56  65534  9896   stress-ng        21   CAP_SYS_ADMIN        2\n07:52:56  65534  9898   stress-ng        21   CAP_SYS_ADMIN        2\n07:52:56  65534  9898   stress-ng        21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   python3          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        2\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        0\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        0\n07:52:56  0      9920   bpftool          39   CAP_BPF              0\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        0\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        0\n07:52:56  0      9920   bpftool          39   CAP_BPF              0\n07:52:56  0      9920   bpftool          39   CAP_BPF              0\n07:52:56  0      9920   bpftool          39   CAP_BPF              0\n07:52:56  0      9920   bpftool          39   CAP_BPF              0\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        0\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        0\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        0\n07:52:56  0      9920   bpftool          21   CAP_SYS_ADMIN        0"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1386": {
        "avg_ns_per_run": 1784.2,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 8921,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 257.6675531914894,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 1504,
        "run_time_ns_delta": 387532,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 71.75810461903507
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
        "avg_ns_per_run": 1770.4,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 8852,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 316.4670824670825,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 1443,
        "run_time_ns_delta": 456662,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 68.77684290577113
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
  "output_chars": 8220,
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
  "stdout_tail": "07:53:13\n@[vfs_write]: 65\n@[vfs_open]: 107\n@[vfs_read]: 157\n07:53:14\n@[vfs_open]: 72\n@[vfs_write]: 74\n@[vfs_read]: 146\n07:53:15\n@[vfs_open]: 74\n@[vfs_write]: 75\n@[vfs_read]: 150\n07:53:16\n@[vfs_open]: 70\n@[vfs_write]: 71\n@[vfs_read]: 141\n07:53:17\n@[vfs_open]: 72\n@[vfs_write]: 73\n@[vfs_read]: 146\n07:53:18\n@[vfs_write]: 59\n@[vfs_open]: 110\n@[vfs_read]: 152\n07:53:19\n@[vfs_open]: 67\n@[vfs_write]: 68\n@[vfs_read]: 136\n07:53:20\n@[vfs_open]: 67\n@[vfs_write]: 68\n@[vfs_read]: 136\n07:53:21\n@[vfs_open]: 71\n@[vfs_write]: 71\n@[vfs_read]: 142\n07:53:22\n@[vfs_open]: 70\n@[vfs_write]: 73\n@[vfs_read]: 143"
}
```

