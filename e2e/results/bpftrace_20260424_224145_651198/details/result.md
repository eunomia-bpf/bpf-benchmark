# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-24T22:44:30.555925+00:00`
- Duration per phase: `5s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## tcplife

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1348": {
        "avg_ns_per_run": 523.0830234287839,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 21512,
        "run_time_ns_delta": 11252562,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 430.382736831968
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
        "avg_ns_per_run": 533.9783133649113,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 21534,
        "run_time_ns_delta": 11498689,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 430.60836842472145
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
  "stdout_tail": "32131 curl       127.0.0.1       37733 127.0.0.1       41152      0     0 0\n32131 curl       127.0.0.1       41152 127.0.0.1       37733      0     0 0\n32133 curl       0.0.0.0         38023 0.0.0.0         35618      0     0 0\n32133 curl       0.0.0.0         35618 0.0.0.0         38023      0     0 0\n32135 curl       127.0.0.1       37733 127.0.0.1       41162      0     0 0\n32135 curl       127.0.0.1       41162 127.0.0.1       37733      0     0 0\n32137 curl       0.0.0.0         38023 0.0.0.0         35628      0     0 0\n32137 curl       0.0.0.0         35628 0.0.0.0         38023      0     0 0\n32139 curl       127.0.0.1       37733 127.0.0.1       41166      0     0 0\n32139 curl       127.0.0.1       41166 127.0.0.1       37733      0     0 0\n32141 curl       0.0.0.0         38023 0.0.0.0         35632      0     0 0\n32141 curl       0.0.0.0         35632 0.0.0.0         38023      0     0 0\n32143 curl       127.0.0.1       37733 127.0.0.1       41174      0     0 0\n32143 curl       127.0.0.1       41174 127.0.0.1       37733      0     0 0\n32145 curl       0.0.0.0         38023 0.0.0.0         35636      0     0 0\n32145 curl       0.0.0.0         35636 0.0.0.0         38023      0     0 0\n32147 curl       127.0.0.1       37733 127.0.0.1       41182      0     0 0\n32147 curl       127.0.0.1       41182 127.0.0.1       37733      0     0 0\n32149 curl       0.0.0.0         38023 0.0.0.0         35650      0     0 0\n32149 curl       0.0.0.0         35650 0.0.0.0         38023      0     0 0\n32151 curl       127.0.0.1       37733 127.0.0.1       41188      0     0 0\n32151 curl       127.0.0.1       41188 127.0.0.1       37733      0     0 0\n32153 curl       0.0.0.0         38023 0.0.0.0         35662      0     0 0\n32153 curl       0.0.0.0         35662 0.0.0.0         38023      0     0 0\n32155 curl       127.0.0.1       37733 127.0.0.1       41200      0     0 0\n32155 curl       127.0.0.1       41200 127.0.0.1       37733      0     0 0\n32157 curl       0.0.0.0         38023 0.0.0.0         35672      0     0 0\n32157 curl       0.0.0.0         35672 0.0.0.0         38023      0     0 0\n32159 curl       127.0.0.1       37733 127.0.0.1       41210      0     0 0\n32159 curl       127.0.0.1       41210 127.0.0.1       37733      0     0 0\n32161 curl       0.0.0.0         38023 0.0.0.0         35684      0     0 0\n32161 curl       0.0.0.0         35684 0.0.0.0         38023      0     0 0\n32163 curl       127.0.0.1       37733 127.0.0.1       41222      0     0 0\n32163 curl       127.0.0.1       41222 127.0.0.1       37733      0     0 0\n32165 curl       0.0.0.0         38023 0.0.0.0         35690      0     0 0\n32165 curl       0.0.0.0         35690 0.0.0.0         38023      0     0 0\n32167 curl       127.0.0.1       37733 127.0.0.1       41230      0     0 0\n32167 curl       127.0.0.1       41230 127.0.0.1       37733      0     0 0\n32169 curl       0.0.0.0         38023 0.0.0.0         35692      0     0 0\n32169 curl       0.0.0.0         35692 0.0.0.0         38023      0     0 0"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1355": {
        "avg_ns_per_run": 136.21292143461173,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 4407297,
        "run_time_ns_delta": 600330800,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 441.9696480632006,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 4407297,
        "run_time_ns_delta": 1947891504,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 880365.8563877916
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
        "avg_ns_per_run": 122.94323794914328,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 4743169,
        "run_time_ns_delta": 583140555,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 399.16463170509,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 4743169,
        "run_time_ns_delta": 1893305307,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 947082.1975325414
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
  "stdout_tail": "12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0\n12381        252   0        dd               2100         0"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1363": {
        "avg_ns_per_run": 99.38922187682145,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 411760,
        "run_time_ns_delta": 40924506,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 170.9962504863756,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "tracepoint_sched_sched_wakeup_new",
        "run_cnt_delta": 84811,
        "run_time_ns_delta": 14502363,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 146.04094540866552,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 786242,
        "run_time_ns_delta": 114823525,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 65.86887886718823
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
        "avg_ns_per_run": 99.96409013651547,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 424201,
        "run_time_ns_delta": 42404867,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 170.90652155970335,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 84811,
        "run_time_ns_delta": 14494753,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 147.8427816218232,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 793724,
        "run_time_ns_delta": 117346364,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 65.79550972701989
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
  "stdout_tail": "Tracing CPU scheduler... Hit Ctrl-C to end.\n@usecs:\n[0]               431429 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n[1]               165388 |@@@@@@@@@@@@@@@@@@@                                 |\n[2, 4)            241103 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                       |\n[4, 8)             72208 |@@@@@@@@                                            |\n[8, 16)            52851 |@@@@@@                                              |\n[16, 32)           26139 |@@@                                                 |\n[32, 64)           30009 |@@@                                                 |\n[64, 128)          19099 |@@                                                  |\n[128, 256)         15956 |@                                                   |\n[256, 512)         19957 |@@                                                  |\n[512, 1K)          22011 |@@                                                  |\n[1K, 2K)           27722 |@@@                                                 |\n[2K, 4K)           46006 |@@@@@                                               |\n[4K, 8K)           52473 |@@@@@@                                              |\n[8K, 16K)           6381 |                                                    |"
}
```

## tcpretrans

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1372": {
        "avg_ns_per_run": 8300.9375,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "kprobe_tcp_retransmit_skb",
        "run_cnt_delta": 16,
        "run_time_ns_delta": 132815,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 0.48920063708799333
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
        "avg_ns_per_run": 12591.588235294117,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "tcp_retransmit_",
        "run_cnt_delta": 17,
        "run_time_ns_delta": 214057,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 0.48926461633487783
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
  "stdout_tail": "Tracing tcp retransmits. Hit Ctrl-C to end.\nTIME     PID               LADDR:LPORT           RADDR:RPORT  STATE\n22:43:21 0             127.0.0.1:45885       127.0.0.1:60242  ESTABLISHED\n22:43:22 0             127.0.0.1:45885       127.0.0.1:60242  FIN_WAIT1\n22:43:23 0             127.0.0.1:45885       127.0.0.1:60242  FIN_WAIT1\n22:43:24 0             127.0.0.1:33897       127.0.0.1:35328  ESTABLISHED\n22:43:24 0             127.0.0.1:33897       127.0.0.1:35328  FIN_WAIT1\n22:43:24 0             127.0.0.1:45885       127.0.0.1:60242  CLOSING\n22:43:25 0             127.0.0.1:33897       127.0.0.1:35328  FIN_WAIT1\n22:43:26 0             127.0.0.1:34625       127.0.0.1:41978  ESTABLISHED\n22:43:27 0             127.0.0.1:34625       127.0.0.1:41978  FIN_WAIT1\n22:43:27 0             127.0.0.1:33897       127.0.0.1:35328  CLOSING\n22:43:27 0             127.0.0.1:34625       127.0.0.1:41978  FIN_WAIT1\n22:43:28 0             127.0.0.1:45885       127.0.0.1:60242  CLOSING\n22:43:29 0             127.0.0.1:41991       127.0.0.1:39352  ESTABLISHED\n22:43:29 0             127.0.0.1:34625       127.0.0.1:41978  CLOSING\n22:43:29 0             127.0.0.1:41991       127.0.0.1:39352  FIN_WAIT1\n22:43:29 0             127.0.0.1:41991       127.0.0.1:39352  FIN_WAIT1\n22:43:30 0             127.0.0.1:40819       127.0.0.1:42926  ESTABLISHED\n22:43:30 0             127.0.0.1:40819       127.0.0.1:42926  FIN_WAIT1\n22:43:30 0             127.0.0.1:33897       127.0.0.1:35328  CLOSING\n22:43:31 0             127.0.0.1:40819       127.0.0.1:42926  FIN_WAIT1\n22:43:32 0             127.0.0.1:38419       127.0.0.1:59552  ESTABLISHED\n22:43:32 0             127.0.0.1:40819       127.0.0.1:42926  CLOSING\n22:43:32 0             127.0.0.1:38419       127.0.0.1:59552  FIN_WAIT1\n22:43:33 0             127.0.0.1:38419       127.0.0.1:59552  FIN_WAIT1\n22:43:35 0             127.0.0.1:35947       127.0.0.1:53308  ESTABLISHED\n22:43:35 0             127.0.0.1:35947       127.0.0.1:53308  FIN_WAIT1\n22:43:35 0             127.0.0.1:38419       127.0.0.1:59552  CLOSING\n22:43:35 0             127.0.0.1:45885       127.0.0.1:60242  CLOSING\n22:43:36 0             127.0.0.1:40819       127.0.0.1:42926  CLOSING\n22:43:36 0             127.0.0.1:35947       127.0.0.1:53308  FIN_WAIT1\n22:43:37 0             127.0.0.1:45799       127.0.0.1:55714  ESTABLISHED\n22:43:37 0             127.0.0.1:45799       127.0.0.1:55714  FIN_WAIT1\n22:43:37 0             127.0.0.1:45799       127.0.0.1:55714  FIN_WAIT1"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1379": {
        "avg_ns_per_run": 123.02161892263494,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 1373889,
        "run_time_ns_delta": 169018049,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2392.0765088884714
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
        "avg_ns_per_run": 121.3628296891139,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 1374780,
        "run_time_ns_delta": 166847191,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2402.9139890522074
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
  "stdout_tail": "22:44:03  65534  14352  stress-ng        21   CAP_SYS_ADMIN        2\n22:44:03  65534  14352  stress-ng        21   CAP_SYS_ADMIN        2\n22:44:03  65534  14352  stress-ng        21   CAP_SYS_ADMIN        2\n22:44:03  65534  14352  stress-ng        21   CAP_SYS_ADMIN        2\n22:44:03  65534  14352  stress-ng        21   CAP_SYS_ADMIN        2\n22:44:03  65534  14352  stress-ng        21   CAP_SYS_ADMIN        2\n22:44:03  65534  14352  stress-ng        21   CAP_SYS_ADMIN        2\n22:44:03  65534  14352  stress-ng        21   CAP_SYS_ADMIN        2\n22:44:03  65534  14352  stress-ng        21   CAP_SYS_ADMIN        2\nLost 161199 events\n22:44:03  65534  14352  stress-ng        21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  python3          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        2\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        0\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        0\n22:44:03  0      14396  bpftool          39   CAP_BPF              0\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        0\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        0\n22:44:03  0      14396  bpftool          39   CAP_BPF              0\n22:44:03  0      14396  bpftool          39   CAP_BPF              0\n22:44:03  0      14396  bpftool          39   CAP_BPF              0\n22:44:03  0      14396  bpftool          39   CAP_BPF              0\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        0\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        0\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        0\n22:44:03  0      14396  bpftool          21   CAP_SYS_ADMIN        0"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1386": {
        "avg_ns_per_run": 1461.8,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 7309,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 211.1154107264087,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 1473,
        "run_time_ns_delta": 310973,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 70.16549286320554
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
        "avg_ns_per_run": 1499.0,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 7495,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 69.01552575864503,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 1417,
        "run_time_ns_delta": 97795,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 67.08771267886932
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
  "stdout_tail": "22:44:19\n@[vfs_write]: 65\n@[vfs_open]: 107\n@[vfs_read]: 157\n22:44:20\n@[vfs_open]: 74\n@[vfs_write]: 75\n@[vfs_read]: 150\n22:44:21\n@[vfs_open]: 71\n@[vfs_write]: 72\n@[vfs_read]: 143\n22:44:22\n@[vfs_open]: 69\n@[vfs_write]: 70\n@[vfs_read]: 139\n22:44:23\n@[vfs_open]: 69\n@[vfs_write]: 70\n@[vfs_read]: 140\n22:44:24\n@[vfs_write]: 58\n@[vfs_open]: 109\n@[vfs_read]: 151\n22:44:25\n@[vfs_open]: 69\n@[vfs_write]: 71\n@[vfs_read]: 139\n22:44:26\n@[vfs_open]: 71\n@[vfs_write]: 72\n@[vfs_read]: 142\n22:44:27\n@[vfs_write]: 61\n@[vfs_open]: 61\n@[vfs_read]: 122\n22:44:28\n@[vfs_open]: 67\n@[vfs_write]: 69\n@[vfs_read]: 134"
}
```

