# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-27T02:10:42.211150+00:00`
- Duration per phase: `5s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## tcplife

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1348": {
        "avg_ns_per_run": 1191.0046196997196,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 12122,
        "run_time_ns_delta": 14437358,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 242.38267720091926,
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
      "1348": {
        "avg_ns_per_run": 1121.708830164357,
        "bytes_jited": 2017,
        "bytes_xlated": 3384,
        "id": 1348,
        "name": "tcp_set_state",
        "run_cnt_delta": 12412,
        "run_time_ns_delta": 13922650,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 248.1354625467978,
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
  "stdout_tail": "17180 curl       0.0.0.0         43531 0.0.0.0         48084      0     0 0\n17180 curl       0.0.0.0         48084 0.0.0.0         43531      0     0 0\n17182 curl       127.0.0.1       39385 127.0.0.1       39208      0     0 0\n17182 curl       127.0.0.1       39208 127.0.0.1       39385      0     0 0\n17184 curl       0.0.0.0         43531 0.0.0.0         48100      0     0 0\n17184 curl       0.0.0.0         48100 0.0.0.0         43531      0     0 0\n17186 curl       127.0.0.1       39385 127.0.0.1       39216      0     0 0\n17186 curl       127.0.0.1       39216 127.0.0.1       39385      0     0 0\n17188 curl       0.0.0.0         43531 0.0.0.0         48112      0     0 0\n17188 curl       0.0.0.0         48112 0.0.0.0         43531      0     0 0\n17190 curl       127.0.0.1       39385 127.0.0.1       39228      0     0 0\n17190 curl       127.0.0.1       39228 127.0.0.1       39385      0     0 0\n17192 curl       0.0.0.0         43531 0.0.0.0         48118      0     0 0\n17192 curl       0.0.0.0         48118 0.0.0.0         43531      0     0 0\n17194 curl       127.0.0.1       39385 127.0.0.1       39230      0     0 0\n17194 curl       127.0.0.1       39230 127.0.0.1       39385      0     0 0\n17196 curl       0.0.0.0         43531 0.0.0.0         48120      0     0 0\n17196 curl       0.0.0.0         48120 0.0.0.0         43531      0     0 0\n17198 curl       127.0.0.1       39385 127.0.0.1       39236      0     0 0\n17198 curl       127.0.0.1       39236 127.0.0.1       39385      0     0 0\n17200 curl       0.0.0.0         43531 0.0.0.0         48132      0     0 0\n17200 curl       0.0.0.0         48132 0.0.0.0         43531      0     0 0\n17202 curl       127.0.0.1       39385 127.0.0.1       39248      0     0 0\n17202 curl       127.0.0.1       39248 127.0.0.1       39385      0     0 0\n17204 curl       0.0.0.0         43531 0.0.0.0         48138      0     0 0\n17204 curl       0.0.0.0         48138 0.0.0.0         43531      0     0 0\n17206 curl       127.0.0.1       39385 127.0.0.1       39258      0     0 0\n17206 curl       127.0.0.1       39258 127.0.0.1       39385      0     0 0\n17208 curl       0.0.0.0         43531 0.0.0.0         48152      0     0 0\n17208 curl       0.0.0.0         48152 0.0.0.0         43531      0     0 0\n17210 curl       127.0.0.1       39385 127.0.0.1       39266      0     0 0\n17210 curl       127.0.0.1       39266 127.0.0.1       39385      0     0 0\n17212 curl       0.0.0.0         43531 0.0.0.0         48154      0     0 0\n17212 curl       0.0.0.0         48154 0.0.0.0         43531      0     0 0\n17214 curl       127.0.0.1       39385 127.0.0.1       39276      0     0 0\n17214 curl       127.0.0.1       39276 127.0.0.1       39385      0     0 0\n17216 curl       0.0.0.0         43531 0.0.0.0         48166      0     0 0\n17216 curl       0.0.0.0         48166 0.0.0.0         43531      0     0 0\n17218 curl       127.0.0.1       39385 127.0.0.1       39278      0     0 0\n17218 curl       127.0.0.1       39278 127.0.0.1       39385      0     0 0"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1355": {
        "avg_ns_per_run": 244.4342537062547,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 2531329,
        "run_time_ns_delta": 618743515,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 599.2109188493475,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 2531329,
        "run_time_ns_delta": 1516799976,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 505711.7506603594,
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
      "1355": {
        "avg_ns_per_run": 232.6998223706502,
        "bytes_jited": 222,
        "bytes_xlated": 408,
        "id": 1355,
        "name": "block_io_start",
        "run_cnt_delta": 2629633,
        "run_time_ns_delta": 611915132,
        "type": "tracepoint"
      },
      "1356": {
        "avg_ns_per_run": 574.0568877862424,
        "bytes_jited": 931,
        "bytes_xlated": 1576,
        "id": 1356,
        "name": "block_io_done",
        "run_cnt_delta": 2629633,
        "run_time_ns_delta": 1509558936,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 524809.0413505924,
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
  "stdout_tail": "12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12376        252   0        dd               18589        0\n12377        252   0        dd               18589        0\n12377        252   0        dd               18589        0\n12377        252   0        dd               18589        0\n12377        252   0        dd               18589        0\n12377        252   0        dd               18589        0\n12377        252   0        dd               18589        0\n12377        252   0        dd               18589        0\n12377        252   0        dd               18589        0\n12377        252   0        dd               18589        0\n12377        252   0        dd               18589        0\n12377        252   0        dd               18589        0\n12377        252   0        dd               18589        0"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1363": {
        "avg_ns_per_run": 156.68147416525392,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 339175,
        "run_time_ns_delta": 53142439,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 312.6163456169738,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "tracepoint_sched_sched_wakeup_new",
        "run_cnt_delta": 57312,
        "run_time_ns_delta": 17916668,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 221.96257949668598,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 611189,
        "run_time_ns_delta": 135661087,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 44.429183571101525,
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
      "1363": {
        "avg_ns_per_run": 154.18141667930655,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1363,
        "name": "sched_wakeup",
        "run_cnt_delta": 336237,
        "run_time_ns_delta": 51841497,
        "type": "tracepoint"
      },
      "1364": {
        "avg_ns_per_run": 305.7604675948639,
        "bytes_jited": 86,
        "bytes_xlated": 136,
        "id": 1364,
        "name": "sched_wakeup_ne",
        "run_cnt_delta": 59111,
        "run_time_ns_delta": 18073807,
        "type": "tracepoint"
      },
      "1365": {
        "avg_ns_per_run": 213.43834291829808,
        "bytes_jited": 515,
        "bytes_xlated": 896,
        "id": 1365,
        "name": "sched_switch",
        "run_cnt_delta": 610157,
        "run_time_ns_delta": 130230899,
        "type": "tracepoint"
      }
    },
    "duration_s": 5,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 45.8886991170604,
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
  "output_chars": 13112,
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
  "stdout_tail": "Tracing CPU scheduler... Hit Ctrl-C to end.\n@usecs:\n[0]               233931 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n[1]               204579 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@       |\n[2, 4)            184524 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@           |\n[4, 8)             74427 |@@@@@@@@@@@@@@@@                                    |\n[8, 16)            54183 |@@@@@@@@@@@@                                        |\n[16, 32)           31255 |@@@@@@                                              |\n[32, 64)           21513 |@@@@                                                |\n[64, 128)          25898 |@@@@@                                               |\n[128, 256)         15936 |@@@                                                 |\n[256, 512)         15588 |@@@                                                 |\n[512, 1K)          16293 |@@@                                                 |\n[1K, 2K)           16294 |@@@                                                 |\n[2K, 4K)           24579 |@@@@@                                               |\n[4K, 8K)           44922 |@@@@@@@@@                                           |\n[8K, 16K)          17562 |@@@                                                 |"
}
```

## tcpretrans

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1372": {
        "avg_ns_per_run": 12496.533333333333,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "kprobe_tcp_retransmit_skb",
        "run_cnt_delta": 15,
        "run_time_ns_delta": 187448,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 0.4886984412167111,
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
      "1372": {
        "avg_ns_per_run": 16391.45,
        "bytes_jited": 968,
        "bytes_xlated": 1640,
        "id": 1372,
        "name": "tcp_retransmit_",
        "run_cnt_delta": 20,
        "run_time_ns_delta": 327829,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 0.48802924080293925,
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
  "stdout_tail": "Tracing tcp retransmits. Hit Ctrl-C to end.\nTIME     PID               LADDR:LPORT           RADDR:RPORT  STATE\n02:09:32 0             127.0.0.1:36299       127.0.0.1:58308  ESTABLISHED\n02:09:32 0             127.0.0.1:36299       127.0.0.1:58308  FIN_WAIT1\n02:09:33 0             127.0.0.1:36299       127.0.0.1:58308  FIN_WAIT1\n02:09:34 0             127.0.0.1:40845       127.0.0.1:48446  ESTABLISHED\n02:09:35 0             127.0.0.1:40845       127.0.0.1:48446  FIN_WAIT1\n02:09:35 0             127.0.0.1:36299       127.0.0.1:58308  CLOSING\n02:09:36 0             127.0.0.1:40845       127.0.0.1:48446  FIN_WAIT1\n02:09:37 0             127.0.0.1:45487       127.0.0.1:48584  ESTABLISHED\n02:09:37 0             127.0.0.1:40845       127.0.0.1:48446  CLOSING\n02:09:37 0             127.0.0.1:45487       127.0.0.1:48584  FIN_WAIT1\n02:09:38 0             127.0.0.1:36299       127.0.0.1:58308  CLOSING\n02:09:38 0             127.0.0.1:45487       127.0.0.1:48584  FIN_WAIT1\n02:09:39 0             127.0.0.1:42329       127.0.0.1:49176  ESTABLISHED\n02:09:40 0             127.0.0.1:42329       127.0.0.1:49176  FIN_WAIT1\n02:09:40 14            127.0.0.1:42329       127.0.0.1:49176  FIN_WAIT1\n02:09:40 0             127.0.0.1:45487       127.0.0.1:48584  CLOSING\n02:09:40 0             127.0.0.1:42019       127.0.0.1:43332  ESTABLISHED\n02:09:41 0             127.0.0.1:42019       127.0.0.1:43332  FIN_WAIT1\n02:09:41 0             127.0.0.1:40845       127.0.0.1:48446  CLOSING\n02:09:41 0             127.0.0.1:42019       127.0.0.1:43332  FIN_WAIT1\n02:09:43 0             127.0.0.1:33365       127.0.0.1:42714  ESTABLISHED\n02:09:43 0             127.0.0.1:33365       127.0.0.1:42714  FIN_WAIT1\n02:09:43 0             127.0.0.1:42019       127.0.0.1:43332  CLOSING\n02:09:43 0             127.0.0.1:45487       127.0.0.1:48584  CLOSING\n02:09:44 0             127.0.0.1:33365       127.0.0.1:42714  FIN_WAIT1\n02:09:45 0             127.0.0.1:36299       127.0.0.1:58308  CLOSING\n02:09:45 0             127.0.0.1:41161       127.0.0.1:57668  ESTABLISHED\n02:09:46 0             127.0.0.1:33365       127.0.0.1:42714  CLOSING\n02:09:46 0             127.0.0.1:41161       127.0.0.1:57668  FIN_WAIT1\n02:09:46 0             127.0.0.1:42019       127.0.0.1:43332  CLOSING\n02:09:47 0             127.0.0.1:41161       127.0.0.1:57668  FIN_WAIT1\n02:09:47 0             127.0.0.1:40845       127.0.0.1:48446  CLOSING\n02:09:48 0             127.0.0.1:45135       127.0.0.1:53084  ESTABLISHED\n02:09:48 0             127.0.0.1:45135       127.0.0.1:53084  FIN_WAIT1\n02:09:48 0             127.0.0.1:45135       127.0.0.1:53084  FIN_WAIT1"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1379": {
        "avg_ns_per_run": 214.2428285855518,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 964977,
        "run_time_ns_delta": 206739402,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 1691.816086947821,
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
      "1379": {
        "avg_ns_per_run": 165.15236921530084,
        "bytes_jited": 769,
        "bytes_xlated": 1360,
        "id": 1379,
        "name": "cap_capable",
        "run_cnt_delta": 1105978,
        "run_time_ns_delta": 182654887,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 1923.620543482433,
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
  "stdout_tail": "02:10:14  65534  730    stress-ng        21   CAP_SYS_ADMIN        2\n02:10:14  65534  730    stress-ng        21   CAP_SYS_ADMIN        2\n02:10:14  65534  730    stress-ng        21   CAP_SYS_ADMIN        2\n02:10:14  65534  730    stress-ng        21   CAP_SYS_ADMIN        2\n02:10:14  65534  730    stress-ng        21   CAP_SYS_ADMIN        2\n02:10:14  65534  730    stress-ng        21   CAP_SYS_ADMIN        2\n02:10:14  65534  736    stress-ng        21   CAP_SYS_ADMIN        2\n02:10:14  65534  730    stress-ng        21   CAP_SYS_ADMIN        2\n02:10:14  65534  730    stress-ng        21   CAP_SYS_ADMIN        2\n02:10:14  65534  707    stress-ng        21   CAP_SYS_ADMIN        2\n02:10:14  65534  702    stress-ng        21   CAP_SYS_ADMIN        2\n02:10:14  0      761    python3          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        2\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        0\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        0\n02:10:14  0      761    bpftool          39   CAP_BPF              0\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        0\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        0\n02:10:14  0      761    bpftool          39   CAP_BPF              0\n02:10:14  0      761    bpftool          39   CAP_BPF              0\n02:10:14  0      761    bpftool          39   CAP_BPF              0\n02:10:14  0      761    bpftool          39   CAP_BPF              0\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        0\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        0\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        0\n02:10:14  0      761    bpftool          21   CAP_SYS_ADMIN        0"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "1386": {
        "avg_ns_per_run": 3186.2,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 15931,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 860.2793807178043,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 1421,
        "run_time_ns_delta": 1222457,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 67.5428195188008,
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
      "1386": {
        "avg_ns_per_run": 4099.0,
        "bytes_jited": 362,
        "bytes_xlated": 680,
        "id": 1386,
        "name": "1",
        "run_cnt_delta": 5,
        "run_time_ns_delta": 20495,
        "type": "perf_event"
      },
      "1387": {
        "avg_ns_per_run": 771.109420289855,
        "bytes_jited": 140,
        "bytes_xlated": 224,
        "id": 1387,
        "name": "vfs_create",
        "run_cnt_delta": 1380,
        "run_time_ns_delta": 1064131,
        "type": "kprobe"
      }
    },
    "duration_s": 5,
    "limitations": [],
    "metric": "ops/s",
    "throughput": 65.17652926701217,
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
  "stdout_tail": "02:10:31\n@[vfs_write]: 61\n@[vfs_open]: 103\n@[vfs_read]: 149\n02:10:32\n@[vfs_open]: 68\n@[vfs_write]: 70\n@[vfs_read]: 139\n02:10:33\n@[vfs_open]: 71\n@[vfs_write]: 72\n@[vfs_read]: 143\n02:10:34\n@[vfs_open]: 69\n@[vfs_write]: 70\n@[vfs_read]: 139\n02:10:35\n@[vfs_open]: 66\n@[vfs_write]: 68\n@[vfs_read]: 134\n02:10:36\n@[vfs_write]: 59\n@[vfs_open]: 110\n@[vfs_read]: 154\n02:10:37\n@[vfs_write]: 69\n@[vfs_open]: 69\n@[vfs_read]: 139\n02:10:38\n@[vfs_open]: 63\n@[vfs_write]: 66\n@[vfs_read]: 127\n02:10:39\n@[vfs_open]: 67\n@[vfs_write]: 70\n@[vfs_read]: 137\n02:10:40\n@[vfs_open]: 66\n@[vfs_write]: 68\n@[vfs_read]: 133"
}
```

