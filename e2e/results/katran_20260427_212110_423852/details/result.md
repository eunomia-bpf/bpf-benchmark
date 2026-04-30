# Katran End-to-End Benchmark

```json
{
  "baseline": {
    "measurement": {
      "bpf": {
        "1450": {
          "avg_ns_per_run": 312.6060370249017,
          "bytes_jited": 176,
          "bytes_xlated": 136,
          "id": 1450,
          "name": "xdp_root",
          "run_cnt_delta": 219744,
          "run_time_ns_delta": 68693301,
          "type": "xdp"
        },
        "1456": {
          "avg_ns_per_run": null,
          "bytes_jited": 13629,
          "bytes_xlated": 23840,
          "id": 1456,
          "name": "balancer_ingress",
          "run_cnt_delta": 0,
          "run_time_ns_delta": 0,
          "type": "xdp"
        },
        "1458": {
          "avg_ns_per_run": null,
          "bytes_jited": 541,
          "bytes_xlated": 1000,
          "id": 1458,
          "name": "healthcheck_encap",
          "run_cnt_delta": 0,
          "run_time_ns_delta": 0,
          "type": "sched_cls"
        }
      },
      "duration_s": 5,
      "metric": "ops/s",
      "throughput": 7323.646943054424
    },
    "phase": "baseline",
    "reason": "",
    "status": "ok"
  },
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "duration_s": 5,
  "generated_at": "2026-04-27T21:21:41.771361+00:00",
  "host": {
    "git_sha": null,
    "git_sha_error": "[Errno 2] No such file or directory: 'git'",
    "hostname": "virtme-ng",
    "kernel": "7.0.0-rc2",
    "platform": "Linux-7.0.0-rc2-x86_64-with-glibc2.39",
    "python": "3.12.3"
  },
  "post_rejit": {
    "measurement": {
      "bpf": {
        "1450": {
          "avg_ns_per_run": 320.8570133831425,
          "bytes_jited": 176,
          "bytes_xlated": 136,
          "id": 1450,
          "name": "xdp_root",
          "run_cnt_delta": 217363,
          "run_time_ns_delta": 69742443,
          "type": "xdp"
        },
        "1456": {
          "avg_ns_per_run": null,
          "bytes_jited": 13629,
          "bytes_xlated": 23840,
          "id": 1456,
          "name": "balancer_ingress",
          "run_cnt_delta": 0,
          "run_time_ns_delta": 0,
          "type": "xdp"
        },
        "1458": {
          "avg_ns_per_run": null,
          "bytes_jited": 541,
          "bytes_xlated": 1000,
          "id": 1458,
          "name": "healthcheck_enc",
          "run_cnt_delta": 0,
          "run_time_ns_delta": 0,
          "type": "sched_cls"
        }
      },
      "duration_s": 5,
      "metric": "ops/s",
      "throughput": 7244.280332725076
    },
    "phase": "post_rejit",
    "reason": "",
    "status": "ok"
  },
  "process": {
    "returncode": 0,
    "stderr_tail": "I20260427 21:21:11.101923 28211 KatranGrpcService.cpp:69] Starting Katran\nE20260427 21:21:11.102084 28211 BaseBpfAdapter.cpp:144] libbpf: elf: skipping unrecognized data section(21) .eh_frame\nE20260427 21:21:11.102092 28211 BaseBpfAdapter.cpp:144] libbpf: elf: skipping relo section(22) .rel.eh_frame for section(21) .eh_frame\nE20260427 21:21:11.102221 28211 BaseBpfAdapter.cpp:144] libbpf: elf: skipping unrecognized data section(21) .eh_frame\nE20260427 21:21:11.102226 28211 BaseBpfAdapter.cpp:144] libbpf: elf: skipping relo section(22) .rel.eh_frame for section(21) .eh_frame\nE20260427 21:21:11.102409 28211 BaseBpfAdapter.cpp:144] libbpf: elf: skipping unrecognized data section(21) .eh_frame\nE20260427 21:21:11.102416 28211 BaseBpfAdapter.cpp:144] libbpf: elf: skipping relo section(22) .rel.eh_frame for section(21) .eh_frame\nE20260427 21:21:11.160562 28211 BaseBpfAdapter.cpp:144] libbpf: elf: skipping unrecognized data section(20) .eh_frame\nE20260427 21:21:11.160602 28211 BaseBpfAdapter.cpp:144] libbpf: elf: skipping relo section(21) .rel.eh_frame for section(20) .eh_frame",
    "stdout_tail": "Server listening on 0.0.0.0:50051"
  },
  "programs": [
    {
      "btf_id": 3638,
      "bytes_jited": 176,
      "bytes_memlock": 4096,
      "bytes_xlated": 136,
      "gpl_compatible": true,
      "id": 1450,
      "jited": true,
      "loaded_at": 1777324871,
      "map_ids": [
        3829
      ],
      "name": "xdp_root",
      "orphaned": false,
      "run_cnt": 5,
      "run_time_ns": 6768,
      "tag": "379b2b6068914ad4",
      "type": "xdp",
      "uid": 0
    },
    {
      "btf_id": 3649,
      "bytes_jited": 13629,
      "bytes_memlock": 24576,
      "bytes_xlated": 23840,
      "gpl_compatible": true,
      "id": 1456,
      "jited": true,
      "loaded_at": 1777324871,
      "map_ids": [
        3831,
        3833,
        3835,
        3834,
        3841,
        3846,
        3837,
        3848,
        3832,
        3838,
        3836,
        3840,
        3839,
        3844
      ],
      "name": "balancer_ingress",
      "orphaned": false,
      "tag": "90e1a12c30a4bce5",
      "type": "xdp",
      "uid": 0
    },
    {
      "btf_id": 3650,
      "bytes_jited": 541,
      "bytes_memlock": 4096,
      "bytes_xlated": 1000,
      "gpl_compatible": true,
      "id": 1458,
      "jited": true,
      "loaded_at": 1777324871,
      "map_ids": [
        3849,
        3850,
        3851
      ],
      "name": "healthcheck_encap",
      "orphaned": false,
      "run_cnt": 4,
      "run_time_ns": 6376,
      "tag": "3c65776e77a1eec5",
      "type": "sched_cls",
      "uid": 0
    }
  ],
  "rejit_result": {
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
    "output_chars": 89606,
    "output_stripped": true,
    "program_counts": {
      "applied": 3,
      "not_applied": 0,
      "requested": 3
    }
  },
  "status": "ok",
  "workload_spec": {
    "kind": "network"
  }
}
```
