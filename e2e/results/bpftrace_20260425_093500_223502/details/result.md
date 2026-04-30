# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-25T09:37:45.703785+00:00`
- Duration per phase: `5s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## tcplife

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1342": {
        "avg_ns_per_run": 535.2018777149797,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1342,
        "name": "tcp_set_state",
        "run_cnt_delta": 21409,
        "run_time_ns_delta": 11458137,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 428.3298704069751
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
      "1342": {
        "avg_ns_per_run": 560.1759412394201,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1342,
        "name": "tcp_set_state",
        "run_cnt_delta": 20558,
        "run_time_ns_delta": 11516097,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 411.1469243856953
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
  "stdout_tail": "32294 curl       127.0.0.1       36155 127.0.0.1       49434      0     0 0\n32294 curl       127.0.0.1       49434 127.0.0.1       36155      0     0 0\n32296 curl       0.0.0.0         45951 0.0.0.0         60176      0     0 0\n32296 curl       0.0.0.0         60176 0.0.0.0         45951      0     0 0\n32298 curl       127.0.0.1       36155 127.0.0.1       49442      0     0 0\n32298 curl       127.0.0.1       49442 127.0.0.1       36155      0     0 0\n32300 curl       0.0.0.0         45951 0.0.0.0         60182      0     0 0\n32300 curl       0.0.0.0         60182 0.0.0.0         45951      0     0 0\n32302 curl       127.0.0.1       36155 127.0.0.1       49446      0     0 0\n32302 curl       127.0.0.1       49446 127.0.0.1       36155      0     0 0\n32304 curl       0.0.0.0         45951 0.0.0.0         60196      0     0 0\n32304 curl       0.0.0.0         60196 0.0.0.0         45951      0     0 0\n32306 curl       127.0.0.1       36155 127.0.0.1       49458      0     0 0\n32306 curl       127.0.0.1       49458 127.0.0.1       36155      0     0 0\n32308 curl       0.0.0.0         45951 0.0.0.0         60198      0     0 0\n32308 curl       0.0.0.0         60198 0.0.0.0         45951      0     0 0\n32310 curl       127.0.0.1       36155 127.0.0.1       49470      0     0 0\n32310 curl       127.0.0.1       49470 127.0.0.1       36155      0     0 0\n32312 curl       0.0.0.0         45951 0.0.0.0         60210      0     0 0\n32312 curl       0.0.0.0         60210 0.0.0.0         45951      0     0 0\n32314 curl       127.0.0.1       36155 127.0.0.1       49482      0     0 0\n32314 curl       127.0.0.1       49482 127.0.0.1       36155      0     0 0\n32316 curl       0.0.0.0         45951 0.0.0.0         60220      0     0 0\n32316 curl       0.0.0.0         60220 0.0.0.0         45951      0     0 0\n32318 curl       127.0.0.1       36155 127.0.0.1       49496      0     0 0\n32318 curl       127.0.0.1       49496 127.0.0.1       36155      0     0 0\n32320 curl       0.0.0.0         45951 0.0.0.0         60234      0     0 0\n32320 curl       0.0.0.0         60234 0.0.0.0         45951      0     0 0\n32322 curl       127.0.0.1       36155 127.0.0.1       49500      0     0 0\n32322 curl       127.0.0.1       49500 127.0.0.1       36155      0     0 0\n32324 curl       0.0.0.0         45951 0.0.0.0         60240      0     0 0\n32324 curl       0.0.0.0         60240 0.0.0.0         45951      0     0 0\n32326 curl       127.0.0.1       36155 127.0.0.1       49512      0     0 0\n32326 curl       127.0.0.1       49512 127.0.0.1       36155      0     0 0\n32328 curl       0.0.0.0         45951 0.0.0.0         60256      0     0 0\n32328 curl       0.0.0.0         60256 0.0.0.0         45951      0     0 0\n32330 curl       127.0.0.1       36155 127.0.0.1       49514      0     0 0\n32330 curl       127.0.0.1       49514 127.0.0.1       36155      0     0 0\n32332 curl       0.0.0.0         45951 0.0.0.0         60270      0     0 0\n32332 curl       0.0.0.0         60270 0.0.0.0         45951      0     0 0"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1349": {
        "avg_ns_per_run": 120.83792983512504,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1349,
        "name": "block_io_start",
        "run_cnt_delta": 4620289,
        "run_time_ns_delta": 558306158,
        "type": "tracepoint"
      },
      "1350": {
        "avg_ns_per_run": 382.42647851682005,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1350,
        "name": "block_io_done",
        "run_cnt_delta": 4620289,
        "run_time_ns_delta": 1766920852,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 923927.652901763
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
      "1349": {
        "avg_ns_per_run": 119.3392008312445,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1349,
        "name": "block_io_start",
        "run_cnt_delta": 4800513,
        "run_time_ns_delta": 572889385,
        "type": "tracepoint"
      },
      "1350": {
        "avg_ns_per_run": 368.0663335356034,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1350,
        "name": "block_io_done",
        "run_cnt_delta": 4800513,
        "run_time_ns_delta": 1766907219,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 958867.468642166
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
  "stdout_tail": "12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0\n12385        252   0        dd               2333         0"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1357": {
        "avg_ns_per_run": 97.16711594937208,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1357,
        "name": "sched_wakeup",
        "run_cnt_delta": 406574,
        "run_time_ns_delta": 39505623,
        "type": "tracepoint"
      },
      "1358": {
        "avg_ns_per_run": 177.35289054485858,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1358,
        "name": "tracepoint_sched_sched_wakeup_new",
        "run_cnt_delta": 84811,
        "run_time_ns_delta": 15041476,
        "type": "tracepoint"
      },
      "1359": {
        "avg_ns_per_run": 145.27500713688545,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1359,
        "name": "sched_switch",
        "run_cnt_delta": 784656,
        "run_time_ns_delta": 113990906,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 65.95570265949513
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
      "1357": {
        "avg_ns_per_run": 99.07732272488552,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1357,
        "name": "sched_wakeup",
        "run_cnt_delta": 407474,
        "run_time_ns_delta": 40371433,
        "type": "tracepoint"
      },
      "1358": {
        "avg_ns_per_run": 180.11736078058067,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1358,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 84040,
        "run_time_ns_delta": 15137063,
        "type": "tracepoint"
      },
      "1359": {
        "avg_ns_per_run": 146.3902869976522,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1359,
        "name": "sched_switch",
        "run_cnt_delta": 784989,
        "run_time_ns_delta": 114914765,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 65.27571038673737
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
  "stdout_tail": "Tracing CPU scheduler... Hit Ctrl-C to end.\n@usecs:\n[0]               432882 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n[1]               168244 |@@@@@@@@@@@@@@@@@@@@                                |\n[2, 4)            239874 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@                        |\n[4, 8)             67703 |@@@@@@@@                                            |\n[8, 16)            49487 |@@@@@                                               |\n[16, 32)           23358 |@@                                                  |\n[32, 64)           27640 |@@@                                                 |\n[64, 128)          18091 |@@                                                  |\n[128, 256)         16041 |@                                                   |\n[256, 512)         19425 |@@                                                  |\n[512, 1K)          21157 |@@                                                  |\n[1K, 2K)           27250 |@@@                                                 |\n[2K, 4K)           46609 |@@@@@                                               |\n[4K, 8K)           51679 |@@@@@@                                              |\n[8K, 16K)           7637 |                                                    |"
}
```

## tcpretrans

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1366": {
        "avg_ns_per_run": 20287.5,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1366,
        "name": "kprobe_tcp_retransmit_skb",
        "run_cnt_delta": 16,
        "run_time_ns_delta": 324600,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 0.48804565078772355
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
      "1366": {
        "avg_ns_per_run": 16008.368421052632,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1366,
        "name": "tcp_retransmit_",
        "run_cnt_delta": 19,
        "run_time_ns_delta": 304159,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 0.487932019982826
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
  "stdout_tail": "Tracing tcp retransmits. Hit Ctrl-C to end.\nTIME     PID               LADDR:LPORT           RADDR:RPORT  STATE\n09:36:36 0             127.0.0.1:35407       127.0.0.1:55846  ESTABLISHED\n09:36:36 0             127.0.0.1:35407       127.0.0.1:55846  FIN_WAIT1\n09:36:37 0             127.0.0.1:35407       127.0.0.1:55846  FIN_WAIT1\n09:36:38 0             127.0.0.1:35845       127.0.0.1:34842  ESTABLISHED\n09:36:39 0             127.0.0.1:35845       127.0.0.1:34842  FIN_WAIT1\n09:36:39 0             127.0.0.1:35407       127.0.0.1:55846  CLOSING\n09:36:39 0             127.0.0.1:35845       127.0.0.1:34842  FIN_WAIT1\n09:36:41 0             127.0.0.1:45745       127.0.0.1:43558  ESTABLISHED\n09:36:41 0             127.0.0.1:45745       127.0.0.1:43558  FIN_WAIT1\n09:36:41 0             127.0.0.1:35845       127.0.0.1:34842  CLOSING\n09:36:42 0             127.0.0.1:45745       127.0.0.1:43558  FIN_WAIT1\n09:36:42 0             127.0.0.1:35407       127.0.0.1:55846  CLOSING\n09:36:43 0             127.0.0.1:37935       127.0.0.1:38230  ESTABLISHED\n09:36:44 0             127.0.0.1:45745       127.0.0.1:43558  CLOSING\n09:36:44 0             127.0.0.1:37935       127.0.0.1:38230  FIN_WAIT1\n09:36:44 0             127.0.0.1:37935       127.0.0.1:38230  FIN_WAIT1\n09:36:44 0             127.0.0.1:35499       127.0.0.1:47598  ESTABLISHED\n09:36:44 0             127.0.0.1:35499       127.0.0.1:47598  FIN_WAIT1\n09:36:45 0             127.0.0.1:35845       127.0.0.1:34842  CLOSING\n09:36:45 0             127.0.0.1:35499       127.0.0.1:47598  FIN_WAIT1\n09:36:46 0             127.0.0.1:35047       127.0.0.1:42350  ESTABLISHED\n09:36:47 0             127.0.0.1:35499       127.0.0.1:47598  CLOSING\n09:36:47 0             127.0.0.1:35047       127.0.0.1:42350  FIN_WAIT1\n09:36:48 0             127.0.0.1:35047       127.0.0.1:42350  FIN_WAIT1\n09:36:49 0             127.0.0.1:35221       127.0.0.1:49924  ESTABLISHED\n09:36:49 0             127.0.0.1:35407       127.0.0.1:55846  CLOSING\n09:36:49 0             127.0.0.1:35221       127.0.0.1:49924  FIN_WAIT1\n09:36:49 0             127.0.0.1:35047       127.0.0.1:42350  CLOSING\n09:36:50 0             127.0.0.1:35499       127.0.0.1:47598  CLOSING\n09:36:50 0             127.0.0.1:35221       127.0.0.1:49924  FIN_WAIT1\n09:36:51 0             127.0.0.1:42125       127.0.0.1:49606  ESTABLISHED\n09:36:51 0             127.0.0.1:35845       127.0.0.1:34842  CLOSING\n09:36:52 0             127.0.0.1:35221       127.0.0.1:49924  CLOSING\n09:36:52 0             127.0.0.1:42125       127.0.0.1:49606  FIN_WAIT1\n09:36:52 33            127.0.0.1:42125       127.0.0.1:49606  FIN_WAIT1"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1373": {
        "avg_ns_per_run": 124.40471744795963,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1373,
        "name": "cap_capable",
        "run_cnt_delta": 1364085,
        "run_time_ns_delta": 169698609,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2383.7496323442706
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
      "1373": {
        "avg_ns_per_run": 124.20121234712792,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1373,
        "name": "cap_capable",
        "run_cnt_delta": 1373534,
        "run_time_ns_delta": 170594588,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 2398.6104321096977
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
  "stdout_tail": "09:37:17  65534  13863  stress-ng        21   CAP_SYS_ADMIN        2\n09:37:17  65534  13863  stress-ng        21   CAP_SYS_ADMIN        2\n09:37:17  65534  13863  stress-ng        21   CAP_SYS_ADMIN        2\n09:37:17  65534  13863  stress-ng        21   CAP_SYS_ADMIN        2\n09:37:17  65534  13863  stress-ng        21   CAP_SYS_ADMIN        2\n09:37:17  65534  13863  stress-ng        21   CAP_SYS_ADMIN        2\n09:37:17  65534  13863  stress-ng        21   CAP_SYS_ADMIN        2\n09:37:17  65534  13863  stress-ng        21   CAP_SYS_ADMIN        2\n09:37:17  65534  13863  stress-ng        21   CAP_SYS_ADMIN        2\n09:37:17  65534  13863  stress-ng        21   CAP_SYS_ADMIN        2\n09:37:17  65534  13863  stress-ng        21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  python3          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        2\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        0\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        0\n09:37:17  0      13916  bpftool          39   CAP_BPF              0\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        0\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        0\n09:37:17  0      13916  bpftool          39   CAP_BPF              0\n09:37:17  0      13916  bpftool          39   CAP_BPF              0\n09:37:17  0      13916  bpftool          39   CAP_BPF              0\n09:37:17  0      13916  bpftool          39   CAP_BPF              0\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        0\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        0\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        0\n09:37:17  0      13916  bpftool          21   CAP_SYS_ADMIN        0"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1380": {
        "avg_ns_per_run": 1666.6,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1380,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 8333,
        "type": "perf_event"
      },
      "1381": {
        "avg_ns_per_run": 156.3495544893763,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1381,
        "name": "vfs_create",
        "run_cnt_delta": 1459,
        "run_time_ns_delta": 228114,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 69.39992814331688
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
      "1380": {
        "avg_ns_per_run": 1914.2,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1380,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 9571,
        "type": "perf_event"
      },
      "1381": {
        "avg_ns_per_run": 114.22328114363512,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1381,
        "name": "vfs_create",
        "run_cnt_delta": 1469,
        "run_time_ns_delta": 167794,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "metric": "ops/s",
    "throughput": 69.51931047965505
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
  "stdout_tail": "09:37:34\n@[vfs_write]: 54\n@[vfs_open]: 97\n@[vfs_read]: 135\n09:37:35\n@[vfs_open]: 70\n@[vfs_write]: 71\n@[vfs_read]: 141\n09:37:36\n@[vfs_open]: 70\n@[vfs_write]: 72\n@[vfs_read]: 140\n09:37:37\n@[vfs_open]: 69\n@[vfs_write]: 71\n@[vfs_read]: 139\n09:37:38\n@[vfs_open]: 72\n@[vfs_write]: 74\n@[vfs_read]: 146\n09:37:39\n@[vfs_write]: 57\n@[vfs_open]: 109\n@[vfs_read]: 150\n09:37:40\n@[vfs_open]: 69\n@[vfs_write]: 72\n@[vfs_read]: 141\n09:37:41\n@[vfs_open]: 72\n@[vfs_write]: 73\n@[vfs_read]: 146\n09:37:42\n@[vfs_open]: 71\n@[vfs_write]: 73\n@[vfs_read]: 143\n09:37:43\n@[vfs_open]: 69\n@[vfs_write]: 71\n@[vfs_read]: 139"
}
```

