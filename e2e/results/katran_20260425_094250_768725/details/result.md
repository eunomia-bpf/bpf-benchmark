# Katran End-to-End Benchmark

```json
{
  "baseline": {
    "measurement": {
      "bpf": {
        "1464": {
          "avg_ns_per_run": 216.02062321351875,
          "bytes_jited": 176,
          "bytes_xlated": 136,
          "id": 1464,
          "name": "xdp_root",
          "run_cnt_delta": 270084,
          "run_time_ns_delta": 58343714,
          "type": "xdp"
        },
        "1470": {
          "avg_ns_per_run": null,
          "bytes_jited": 13629,
          "bytes_xlated": 23840,
          "id": 1470,
          "name": "balancer_ingress",
          "run_cnt_delta": 0,
          "run_time_ns_delta": 0,
          "type": "xdp"
        },
        "1472": {
          "avg_ns_per_run": null,
          "bytes_jited": 541,
          "bytes_xlated": 1000,
          "id": 1472,
          "name": "healthcheck_encap",
          "run_cnt_delta": 0,
          "run_time_ns_delta": 0,
          "type": "sched_cls"
        }
      },
      "duration_s": 5,
      "metric": "ops/s",
      "throughput": 9001.699886053877
    },
    "phase": "baseline",
    "reason": "",
    "status": "ok"
  },
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "duration_s": 5,
  "generated_at": "2026-04-25T09:43:21.781044+00:00",
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
        "1464": {
          "avg_ns_per_run": 216.73250201721854,
          "bytes_jited": 176,
          "bytes_xlated": 136,
          "id": 1464,
          "name": "xdp_root",
          "run_cnt_delta": 270174,
          "run_time_ns_delta": 58555487,
          "type": "xdp"
        },
        "1470": {
          "avg_ns_per_run": null,
          "bytes_jited": 13629,
          "bytes_xlated": 23840,
          "id": 1470,
          "name": "balancer_ingress",
          "run_cnt_delta": 0,
          "run_time_ns_delta": 0,
          "type": "xdp"
        },
        "1472": {
          "avg_ns_per_run": null,
          "bytes_jited": 541,
          "bytes_xlated": 1000,
          "id": 1472,
          "name": "healthcheck_enc",
          "run_cnt_delta": 0,
          "run_time_ns_delta": 0,
          "type": "sched_cls"
        }
      },
      "duration_s": 5,
      "metric": "ops/s",
      "throughput": 9004.517310111161
    },
    "phase": "post_rejit",
    "reason": "",
    "status": "ok"
  },
  "process": {
    "returncode": 0,
    "stderr_tail": "I20260425 09:42:51.330926 13484 KatranGrpcService.cpp:69] Starting Katran\nE20260425 09:42:51.331029 13484 BaseBpfAdapter.cpp:144] libbpf: elf: skipping unrecognized data section(21) .eh_frame\nE20260425 09:42:51.331036 13484 BaseBpfAdapter.cpp:144] libbpf: elf: skipping relo section(22) .rel.eh_frame for section(21) .eh_frame\nE20260425 09:42:51.331131 13484 BaseBpfAdapter.cpp:144] libbpf: elf: skipping unrecognized data section(21) .eh_frame\nE20260425 09:42:51.331136 13484 BaseBpfAdapter.cpp:144] libbpf: elf: skipping relo section(22) .rel.eh_frame for section(21) .eh_frame\nE20260425 09:42:51.331282 13484 BaseBpfAdapter.cpp:144] libbpf: elf: skipping unrecognized data section(21) .eh_frame\nE20260425 09:42:51.331287 13484 BaseBpfAdapter.cpp:144] libbpf: elf: skipping relo section(22) .rel.eh_frame for section(21) .eh_frame\nE20260425 09:42:51.378232 13484 BaseBpfAdapter.cpp:144] libbpf: elf: skipping unrecognized data section(20) .eh_frame\nE20260425 09:42:51.378253 13484 BaseBpfAdapter.cpp:144] libbpf: elf: skipping relo section(21) .rel.eh_frame for section(20) .eh_frame",
    "stdout_tail": "Server listening on 0.0.0.0:50051"
  },
  "programs": [
    {
      "btf_id": 3650,
      "bytes_jited": 176,
      "bytes_memlock": 4096,
      "bytes_xlated": 136,
      "gpl_compatible": true,
      "id": 1464,
      "jited": true,
      "loaded_at": 1777110171,
      "map_ids": [
        3849
      ],
      "name": "xdp_root",
      "orphaned": false,
      "run_cnt": 5,
      "run_time_ns": 4280,
      "tag": "379b2b6068914ad4",
      "type": "xdp",
      "uid": 0
    },
    {
      "btf_id": 3661,
      "bytes_jited": 13629,
      "bytes_memlock": 24576,
      "bytes_xlated": 23840,
      "gpl_compatible": true,
      "id": 1470,
      "jited": true,
      "loaded_at": 1777110171,
      "map_ids": [
        3851,
        3853,
        3855,
        3854,
        3861,
        3866,
        3857,
        3868,
        3852,
        3858,
        3856,
        3860,
        3859,
        3864
      ],
      "name": "balancer_ingress",
      "orphaned": false,
      "tag": "90e1a12c30a4bce5",
      "type": "xdp",
      "uid": 0
    },
    {
      "btf_id": 3662,
      "bytes_jited": 541,
      "bytes_memlock": 4096,
      "bytes_xlated": 1000,
      "gpl_compatible": true,
      "id": 1472,
      "jited": true,
      "loaded_at": 1777110171,
      "map_ids": [
        3869,
        3870,
        3871
      ],
      "name": "healthcheck_encap",
      "orphaned": false,
      "run_cnt": 4,
      "run_time_ns": 6548,
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
    "output_chars": 89605,
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
