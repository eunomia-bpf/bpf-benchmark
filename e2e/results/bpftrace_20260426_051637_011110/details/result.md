# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-26T05:19:22.641171+00:00`
- Duration per phase: `5s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## tcplife

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1348": {
        "avg_ns_per_run": 621.7921229991575,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 18992,
        "run_time_ns_delta": 11809076,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 380.04467566504655
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
        "avg_ns_per_run": 581.1116069138842,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 19497,
        "run_time_ns_delta": 11329933,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 389.9115951880656
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
  "stdout_tail": "31587 curl       127.0.0.1       43291 127.0.0.1       38988      0     0 0\n31587 curl       127.0.0.1       38988 127.0.0.1       43291      0     0 0\n31589 curl       0.0.0.0         42727 0.0.0.0         44216      0     0 0\n31589 curl       0.0.0.0         44216 0.0.0.0         42727      0     0 0\n31591 curl       127.0.0.1       43291 127.0.0.1       38996      0     0 0\n31591 curl       127.0.0.1       38996 127.0.0.1       43291      0     0 0\n31593 curl       0.0.0.0         42727 0.0.0.0         44224      0     0 0\n31593 curl       0.0.0.0         44224 0.0.0.0         42727      0     0 0\n31595 curl       127.0.0.1       43291 127.0.0.1       39010      0     0 0\n31595 curl       127.0.0.1       39010 127.0.0.1       43291      0     0 0\n31597 curl       0.0.0.0         42727 0.0.0.0         44236      0     0 0\n31597 curl       0.0.0.0         44236 0.0.0.0         42727      0     0 0\n31599 curl       127.0.0.1       43291 127.0.0.1       39020      0     0 0\n31599 curl       127.0.0.1       39020 127.0.0.1       43291      0     0 0\n31601 curl       0.0.0.0         42727 0.0.0.0         44244      0     0 0\n31601 curl       0.0.0.0         44244 0.0.0.0         42727      0     0 0\n31603 curl       127.0.0.1       43291 127.0.0.1       39028      0     0 0\n31603 curl       127.0.0.1       39028 127.0.0.1       43291      0     0 0\n31605 curl       0.0.0.0         42727 0.0.0.0         44248      0     0 0\n31605 curl       0.0.0.0         44248 0.0.0.0         42727      0     0 0\n31607 curl       127.0.0.1       43291 127.0.0.1       39042      0     0 0\n31607 curl       127.0.0.1       39042 127.0.0.1       43291      0     0 0\n31609 curl       0.0.0.0         42727 0.0.0.0         44252      0     0 0\n31609 curl       0.0.0.0         44252 0.0.0.0         42727      0     0 0\n31611 curl       127.0.0.1       43291 127.0.0.1       39056      0     0 0\n31611 curl       127.0.0.1       39056 127.0.0.1       43291      0     0 0\n31613 curl       0.0.0.0         42727 0.0.0.0         44256      0     0 0\n31613 curl       0.0.0.0         44256 0.0.0.0         42727      0     0 0\n31615 curl       127.0.0.1       43291 127.0.0.1       39066      0     0 0\n31615 curl       127.0.0.1       39066 127.0.0.1       43291      0     0 0\n31617 curl       0.0.0.0         42727 0.0.0.0         44266      0     0 0\n31617 curl       0.0.0.0         44266 0.0.0.0         42727      0     0 0\n31619 curl       127.0.0.1       43291 127.0.0.1       39070      0     0 0\n31619 curl       127.0.0.1       39070 127.0.0.1       43291      0     0 0\n31621 curl       0.0.0.0         42727 0.0.0.0         44274      0     0 0\n31621 curl       0.0.0.0         44274 0.0.0.0         42727      0     0 0\n31623 curl       127.0.0.1       43291 127.0.0.1       39074      0     0 0\n31623 curl       127.0.0.1       39074 127.0.0.1       43291      0     0 0\n31625 curl       0.0.0.0         42727 0.0.0.0         44278      0     0 0\n31625 curl       0.0.0.0         44278 0.0.0.0         42727      0     0 0"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1355": {
        "avg_ns_per_run": 120.52729539955858,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 5595137,
        "run_time_ns_delta": 674366730,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 241.09079706180563,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 5595137,
        "run_time_ns_delta": 1348936039,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 1118222.646409828
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
        "avg_ns_per_run": 120.41165130630813,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 5447681,
        "run_time_ns_delta": 655964265,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 253.32452138809157,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 5447681,
        "run_time_ns_delta": 1380031182,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 1087810.0703170092
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
  "stdout_tail": "12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0\n12401        252   0        dd               2022         0"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1363": {
        "avg_ns_per_run": 101.42802927423676,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 408687,
        "run_time_ns_delta": 41452317,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 174.21002906093068,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "tracepoint_sched_sched_wakeup_new",
        "run_cnt_delta": 82241,
        "run_time_ns_delta": 14327207,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 152.94437805526448,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 774892,
        "run_time_ns_delta": 118515375,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 63.83722926278073
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
        "avg_ns_per_run": 101.35453392085596,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 396467,
        "run_time_ns_delta": 40183728,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 169.0949019418879,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 83012,
        "run_time_ns_delta": 14036906,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 150.2208456989906,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 759159,
        "run_time_ns_delta": 114041507,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 64.52570445863003
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
  "output_chars": 13111,
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
  "stdout_tail": "Tracing CPU scheduler... Hit Ctrl-C to end.\n@usecs:\n[0]               415223 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n[1]               170485 |@@@@@@@@@@@@@@@@@@@@@                               |\n[2, 4)            234302 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                       |\n[4, 8)             66764 |@@@@@@@@                                            |\n[8, 16)            50171 |@@@@@@                                              |\n[16, 32)           22768 |@@                                                  |\n[32, 64)           27312 |@@@                                                 |\n[64, 128)          17941 |@@                                                  |\n[128, 256)         15622 |@                                                   |\n[256, 512)         19459 |@@                                                  |\n[512, 1K)          21432 |@@                                                  |\n[1K, 2K)           27010 |@@@                                                 |\n[2K, 4K)           41814 |@@@@@                                               |\n[4K, 8K)           53001 |@@@@@@                                              |\n[8K, 16K)           8038 |@                                                   |"
}
```

## tcpretrans

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1372": {
        "avg_ns_per_run": 11964.5,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "kprobe_tcp_retransmit_skb",
        "run_cnt_delta": 16,
        "run_time_ns_delta": 191432,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 0.4887657088189921
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
        "avg_ns_per_run": 11305.333333333334,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "tcp_retransmit_",
        "run_cnt_delta": 18,
        "run_time_ns_delta": 203496,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 0.4889002953510596
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
  "stdout_tail": "Tracing tcp retransmits. Hit Ctrl-C to end.\nTIME     PID               LADDR:LPORT           RADDR:RPORT  STATE\n05:18:13 0             127.0.0.1:43863       127.0.0.1:58728  ESTABLISHED\n05:18:13 0             127.0.0.1:43863       127.0.0.1:58728  FIN_WAIT1\n05:18:14 0             127.0.0.1:43863       127.0.0.1:58728  FIN_WAIT1\n05:18:15 0             127.0.0.1:33011       127.0.0.1:60840  ESTABLISHED\n05:18:16 0             127.0.0.1:33011       127.0.0.1:60840  FIN_WAIT1\n05:18:16 0             127.0.0.1:43863       127.0.0.1:58728  CLOSING\n05:18:17 0             127.0.0.1:33011       127.0.0.1:60840  FIN_WAIT1\n05:18:18 0             127.0.0.1:42079       127.0.0.1:47852  ESTABLISHED\n05:18:18 0             127.0.0.1:42079       127.0.0.1:47852  FIN_WAIT1\n05:18:18 0             127.0.0.1:33011       127.0.0.1:60840  CLOSING\n05:18:19 0             127.0.0.1:42079       127.0.0.1:47852  FIN_WAIT1\n05:18:19 0             127.0.0.1:43863       127.0.0.1:58728  CLOSING\n05:18:20 0             127.0.0.1:43331       127.0.0.1:52316  ESTABLISHED\n05:18:21 0             127.0.0.1:42079       127.0.0.1:47852  CLOSING\n05:18:21 0             127.0.0.1:43331       127.0.0.1:52316  FIN_WAIT1\n05:18:21 0             127.0.0.1:43331       127.0.0.1:52316  FIN_WAIT1\n05:18:21 0             127.0.0.1:35837       127.0.0.1:33816  ESTABLISHED\n05:18:21 0             127.0.0.1:35837       127.0.0.1:33816  FIN_WAIT1\n05:18:22 0             127.0.0.1:33011       127.0.0.1:60840  CLOSING\n05:18:22 0             127.0.0.1:35837       127.0.0.1:33816  FIN_WAIT1\n05:18:24 0             127.0.0.1:40061       127.0.0.1:53542  ESTABLISHED\n05:18:24 0             127.0.0.1:40061       127.0.0.1:53542  FIN_WAIT1\n05:18:24 0             127.0.0.1:35837       127.0.0.1:33816  CLOSING\n05:18:25 0             127.0.0.1:40061       127.0.0.1:53542  FIN_WAIT1\n05:18:26 0             127.0.0.1:42463       127.0.0.1:47522  ESTABLISHED\n05:18:26 0             127.0.0.1:40061       127.0.0.1:53542  CLOSING\n05:18:26 0             127.0.0.1:42463       127.0.0.1:47522  FIN_WAIT1\n05:18:27 0             127.0.0.1:43863       127.0.0.1:58728  CLOSING\n05:18:27 0             127.0.0.1:35837       127.0.0.1:33816  CLOSING\n05:18:27 0             127.0.0.1:42463       127.0.0.1:47522  FIN_WAIT1\n05:18:29 0             127.0.0.1:38807       127.0.0.1:46124  ESTABLISHED\n05:18:29 0             127.0.0.1:33011       127.0.0.1:60840  CLOSING\n05:18:29 0             127.0.0.1:38807       127.0.0.1:46124  FIN_WAIT1\n05:18:29 23            127.0.0.1:38807       127.0.0.1:46124  FIN_WAIT1"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1379": {
        "avg_ns_per_run": 126.72346505180452,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 1340713,
        "run_time_ns_delta": 169899797,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2332.444341609538
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
        "avg_ns_per_run": 125.65330247010982,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 1362571,
        "run_time_ns_delta": 171211546,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2369.9313191049355
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
  "stdout_tail": "05:18:54  65534  8941   stress-ng        21   CAP_SYS_ADMIN        2\n05:18:54  65534  8941   stress-ng        21   CAP_SYS_ADMIN        2\n05:18:54  65534  8941   stress-ng        21   CAP_SYS_ADMIN        2\n05:18:54  65534  8941   stress-ng        21   CAP_SYS_ADMIN        2\n05:18:54  65534  8941   stress-ng        21   CAP_SYS_ADMIN        2\n05:18:54  65534  8941   stress-ng        21   CAP_SYS_ADMIN        2\n05:18:54  65534  8941   stress-ng        21   CAP_SYS_ADMIN        2\n05:18:54  65534  8941   stress-ng        21   CAP_SYS_ADMIN        2\n05:18:54  65534  8885   stress-ng        21   CAP_SYS_ADMIN        2\n05:18:54  65534  8941   stress-ng        21   CAP_SYS_ADMIN        2\n05:18:54  65534  8941   stress-ng        21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   python3          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        2\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        0\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        0\n05:18:54  0      8976   bpftool          39   CAP_BPF              0\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        0\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        0\n05:18:54  0      8976   bpftool          39   CAP_BPF              0\n05:18:54  0      8976   bpftool          39   CAP_BPF              0\n05:18:54  0      8976   bpftool          39   CAP_BPF              0\n05:18:54  0      8976   bpftool          39   CAP_BPF              0\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        0\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        0\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        0\n05:18:54  0      8976   bpftool          21   CAP_SYS_ADMIN        0"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1386": {
        "avg_ns_per_run": 1726.0,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 8630,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 294.3985649054142,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 1533,
        "run_time_ns_delta": 451313,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 73.03345353391207
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
        "avg_ns_per_run": 2114.8,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 10574,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 123.08415233415234,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 1628,
        "run_time_ns_delta": 200381,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 77.47387018413266
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
  "stdout_tail": "05:19:11\n@[vfs_write]: 58\n@[vfs_open]: 99\n@[vfs_read]: 143\n05:19:12\n@[vfs_open]: 69\n@[vfs_write]: 70\n@[vfs_read]: 138\n05:19:13\n@[vfs_open]: 70\n@[vfs_write]: 72\n@[vfs_read]: 143\n05:19:14\n@[vfs_open]: 72\n@[vfs_write]: 73\n@[vfs_read]: 145\n05:19:15\n@[vfs_open]: 84\n@[vfs_write]: 87\n@[vfs_read]: 170\n05:19:16\n@[vfs_write]: 66\n@[vfs_open]: 118\n@[vfs_read]: 170\n05:19:17\n@[vfs_open]: 80\n@[vfs_write]: 83\n@[vfs_read]: 162\n05:19:18\n@[vfs_open]: 80\n@[vfs_write]: 82\n@[vfs_read]: 162\n05:19:19\n@[vfs_open]: 73\n@[vfs_write]: 76\n@[vfs_read]: 149\n05:19:20\n@[vfs_open]: 76\n@[vfs_write]: 78\n@[vfs_read]: 154"
}
```

