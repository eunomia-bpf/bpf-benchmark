# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-04T14:56:50.355737+00:00",
  "kinsn_modules": {
    "captured_at": "2026-05-04T14:56:34.112137+00:00",
    "daemon_binary": "daemon/target/release/bpfrejit-daemon",
    "expected_modules": [
      "bpf_bulk_memory",
      "bpf_endian",
      "bpf_extract",
      "bpf_prefetch",
      "bpf_rotate",
      "bpf_select"
    ],
    "module_load": {
      "expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "failed_modules": [],
      "invoked_at": "2026-05-04T14:56:34.112050+00:00",
      "loaded_count": 6,
      "loaded_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "loader": "runner.libs.kinsn.load_kinsn_modules",
      "module_dir": "/artifacts/kinsn",
      "newly_loaded_modules": [],
      "snapshot_after": {
        "captured_at": "2026-05-04T14:56:34.112043+00:00",
        "expected_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_prefetch",
          "bpf_rotate",
          "bpf_select"
        ],
        "loaded_bpf_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_prefetch",
          "bpf_rotate",
          "bpf_select"
        ],
        "missing_expected_modules": [],
        "raw_output": "bpf_select             12288  0\nbpf_rotate             12288  0\nbpf_prefetch           12288  0\nbpf_extract            12288  0\nbpf_endian             12288  0\nbpf_bulk_memory        12288  0",
        "resident_expected_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_prefetch",
          "bpf_rotate",
          "bpf_select"
        ],
        "source": "lsmod"
      },
      "status": "ok",
      "total_count": 6
    },
    "module_snapshot_before_daemon": {
      "captured_at": "2026-05-04T14:56:34.099525+00:00",
      "expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "loaded_bpf_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "missing_expected_modules": [],
      "raw_output": "bpf_select             12288  0\nbpf_rotate             12288  0\nbpf_prefetch           12288  0\nbpf_extract            12288  0\nbpf_endian             12288  0\nbpf_bulk_memory        12288  0",
      "resident_expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "source": "lsmod"
    }
  },
  "manifest": "/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml",
  "per_program": [
    {
      "app": "cilium/agent",
      "baseline_avg_ns_per_run": 1130.921052631579,
      "baseline_run_cnt_delta": 266,
      "baseline_run_time_ns_delta": 300825,
      "post_rejit_avg_ns_per_run": 1724.2218543046358,
      "post_rejit_run_cnt_delta": 302,
      "post_rejit_run_time_ns_delta": 520715,
      "program": "cil_from_netdev",
      "program_id": 99,
      "ratio": 1.5246173464473802,
      "runner": "cilium",
      "type": "sched_cls",
      "workload": "network"
    }
  ],
  "results": [
    {
      "app": "calico/felix",
      "baseline": null,
      "error": "command failed (1): /usr/local/bin/calicoctl patch --allow-version-mismatch node virtme-ng --patch '{\"spec\":{\"bgp\":{\"ipv4Address\":\"198.18.0.1/30\"}}}'\nhit error: resource does not exist: Node(virtme-ng) with error: <nil>",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "calico",
      "selected_workload": "network",
      "status": "error"
    },
    {
      "app": "cilium/agent",
      "baseline": {
        "bpf": {
          "10": {
            "avg_ns_per_run": null,
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 10,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "11": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 11,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "83": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 83,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "84": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 84,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "85": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 85,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "86": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 86,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "87": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 87,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "88": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 88,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "89": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 89,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "90": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 90,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "91": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 91,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "92": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 92,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "93": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 93,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "94": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 94,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "95": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 95,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "96": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 96,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "97": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 97,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "98": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 98,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "99": {
            "avg_ns_per_run": 1130.921052631579,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 99,
            "name": "cil_from_netdev",
            "run_cnt_delta": 266,
            "run_time_ns_delta": 300825,
            "type": "sched_cls"
          },
          "100": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 100,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "101": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 101,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "102": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 102,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "103": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 103,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "104": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 104,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "106": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 106,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.006758471000012,
            "ops_per_sec": 119.1944279155696,
            "ops_total": 120.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    49.00ms   11.33ms  60.31ms   95.00%\n    Req/Sec    60.00     20.52    80.00    100.00%\n  120 requests in 1.00s, 18.97KB read\nRequests/sec:    119.61\nTransfer/sec:     18.91KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "10": {
            "avg_ns_per_run": null,
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 10,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "11": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 11,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "83": {
            "avg_ns_per_run": null,
            "bytes_jited": 3361,
            "bytes_xlated": 6064,
            "id": 83,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "84": {
            "avg_ns_per_run": null,
            "bytes_jited": 1192,
            "bytes_xlated": 2024,
            "id": 84,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "85": {
            "avg_ns_per_run": null,
            "bytes_jited": 1242,
            "bytes_xlated": 2088,
            "id": 85,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "86": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 86,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "87": {
            "avg_ns_per_run": null,
            "bytes_jited": 529,
            "bytes_xlated": 968,
            "id": 87,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "88": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 88,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "89": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 89,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "90": {
            "avg_ns_per_run": null,
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 90,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "91": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 91,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "92": {
            "avg_ns_per_run": null,
            "bytes_jited": 3361,
            "bytes_xlated": 6064,
            "id": 92,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "93": {
            "avg_ns_per_run": null,
            "bytes_jited": 529,
            "bytes_xlated": 968,
            "id": 93,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "94": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 94,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "95": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 95,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "96": {
            "avg_ns_per_run": null,
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 96,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "97": {
            "avg_ns_per_run": null,
            "bytes_jited": 1192,
            "bytes_xlated": 2024,
            "id": 97,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "98": {
            "avg_ns_per_run": null,
            "bytes_jited": 1242,
            "bytes_xlated": 2088,
            "id": 98,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "99": {
            "avg_ns_per_run": 1724.2218543046358,
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 99,
            "name": "cil_from_netdev",
            "run_cnt_delta": 302,
            "run_time_ns_delta": 520715,
            "type": "sched_cls"
          },
          "100": {
            "avg_ns_per_run": null,
            "bytes_jited": 3361,
            "bytes_xlated": 6064,
            "id": 100,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "101": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 101,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "102": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 102,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "103": {
            "avg_ns_per_run": null,
            "bytes_jited": 529,
            "bytes_xlated": 968,
            "id": 103,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "104": {
            "avg_ns_per_run": null,
            "bytes_jited": 1192,
            "bytes_xlated": 2024,
            "id": 104,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "106": {
            "avg_ns_per_run": null,
            "bytes_jited": 385,
            "bytes_xlated": 608,
            "id": 106,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.006744647000005,
            "ops_per_sec": 135.08887323639212,
            "ops_total": 136.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    49.74ms   11.90ms  60.39ms   94.85%\n    Req/Sec    68.10     31.66   110.00     55.00%\n  136 requests in 1.00s, 21.53KB read\nRequests/sec:    135.40\nTransfer/sec:     21.43KB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "bulk_memory",
          "prefetch"
        ],
        "error": "prog 11: prog 11 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8e8fb00d4d7a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8e8fb00d4d9a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 86: prog 86 pass cond_select failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd2d64021a049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd2d64021a004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd2d64021a03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd2d64021a05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8e8d07810a00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...; prog 88: prog 88 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd2d64021a004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd2d64021a03c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd2d64021a004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+44\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8e8d06536000\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+7\n     45: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     46: 01....67.. (07) r1 += 1\n     47: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     48: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     49: 01....67.. (0f) r1 += r7\n     50: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     51: ......6... (05) goto pc+11\n     52: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     53: ......6... (b7) r1 = 1\n     54: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     55: ......6... (bf) r2 = r10\n     56: ..2...6... (07) r2 += -24\n     57: ..2...6... (bf) r3 = r10\n     58: ..23..6... (07) r3 += -16\n     59: ..23..6... (18) r1 = 0xffff8e8d06536000\n     61: .123..6... (b4) w4 = 0\n     62: .1234.6... (85) call bpf_map_update_elem#2\n     63: ......6... (bf) r1 = r6\n     64: .1........ (18) r2 = 0xffff8e9387403800\n     66: .12....... (b7) r3 = 1\n     67: .123...... (85) call bpf_tail_call#12\n     68: .......... (b4) w0 = 2\n     69: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd2d64021a004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd2d64021a03c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd2d64021a004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt(r=0)\n20: (0f) r5 += r3\nmark_precis\n... verifier log truncated ...; prog 91: prog 91 pass cond_select failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd2d6405da049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd2d6405da004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd2d6405da03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd2d6405da05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8e8d07810a00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...; prog 94: prog 94 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd2d6405da004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd2d6405da03c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd2d6405da004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+44\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8e8d06536000\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+7\n     45: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     46: 01....67.. (07) r1 += 1\n     47: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     48: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     49: 01....67.. (0f) r1 += r7\n     50: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     51: ......6... (05) goto pc+11\n     52: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     53: ......6... (b7) r1 = 1\n     54: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     55: ......6... (bf) r2 = r10\n     56: ..2...6... (07) r2 += -24\n     57: ..2...6... (bf) r3 = r10\n     58: ..23..6... (07) r3 += -16\n     59: ..23..6... (18) r1 = 0xffff8e8d06536000\n     61: .123..6... (b4) w4 = 0\n     62: .1234.6... (85) call bpf_map_update_elem#2\n     63: ......6... (bf) r1 = r6\n     64: .1........ (18) r2 = 0xffff8e8d06531400\n     66: .12....... (b7) r3 = 1\n     67: .123...... (85) call bpf_tail_call#12\n     68: .......... (b4) w0 = 2\n     69: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd2d6405da004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd2d6405da03c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd2d6405da004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt(r=0)\n20: (0f) r5 += r3\nmark_precis\n... verifier log truncated ...; prog 97: prog 97 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (61) r7 = *(u32 *)(r6 +48)\n      2: ......67.. (b4) w1 = 0\n      3: .1....67.. (63) *(u32 *)(r6 +48) = r1\n      4: ......67.. (18) r1 = 0xffffd2d6405da004\n      6: .1....67.. (71) r1 = *(u8 *)(r1 +0)\n      7: .1....67.. (61) r2 = *(u32 *)(r6 +80)\n      8: .12...67.. (61) r3 = *(u32 *)(r6 +76)\n      9: .123..67.. (0f) r3 += r1\n     10: ..23..67.. (b4) w0 = -134\n     11: 0.23..67.. (07) r3 += 20\n     12: 0.23..67.. (2d) if r3 > r2 goto pc+119\n     13: 0.....67.. (18) r1 = 0xffffd2d6405da03c\n     15: 01....67.. (61) r1 = *(u32 *)(r1 +0)\n     16: 0.....67.. (61) r1 = *(u32 *)(r6 +44)\n     17: 01....67.. (63) *(u32 *)(r10 -32) = r1\n     18: 01....67.. (61) r2 = *(u32 *)(r10 -32)\n     19: 012...67.. (63) *(u32 *)(r10 -32) = r1\n     20: 0.2...67.. (54) w2 &= 1\n     21: 0.2...67.. (61) r1 = *(u32 *)(r10 -32)\n     22: 012...67.. (54) w1 &= 2\n     23: 012...67.. (4c) w1 |= w2\n     24: 01....67.. (b4) w8 = 1\n     25: 01....678. (56) if w1 != 0x0 goto pc+1\n     26: 0.....67.. (b4) w8 = 0\n     27: 0.....678. (18) r1 = 0xffffd2d6405da004\n     29: 01....678. (71) r1 = *(u8 *)(r1 +0)\n     30: 01....678. (61) r2 = *(u32 *)(r6 +80)\n     31: 012...678. (61) r9 = *(u32 *)(r6 +76)\n     32: 012...6789 (0f) r9 += r1\n     33: 0.2...6789 (bf) r1 = r9\n     34: 012...6789 (07) r1 += 20\n     35: 012...6789 (2d) if r1 > r2 goto pc+96\n     36: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     37: .1....6789 (b7) r2 = 0\n     38: .12...6789 (63) *(u32 *)(r10 -16) = r2\n     39: .12...6789 (63) *(u32 *)(r10 -20) = r2\n     40: .12...6789 (63) *(u32 *)(r10 -24) = r2\n     41: .12...6789 (63) *(u32 *)(r10 -28) = r2\n     42: .1....6789 (63) *(u32 *)(r10 -32) = r1\n     43: ......6789 (b4) w1 = 1\n     44: .1....6789 (73) *(u8 *)(r10 -16) = r1\n     45: ......6789 (bf) r2 = r10\n     46: ..2...6789 (07) r2 += -32\n     47: ..2...6789 (18) r1 = 0xffff8e8d20ee9c00\n     49: .12...6789 (85) call bpf_map_lookup_elem#1\n     50: 0.....6789 (15) if r0 == 0x0 goto pc+44\n     51: 0.....67.9 (05) goto pc+0\n     52: 0.....67.9 (18) r1 = 0xffffd2d6405da004\n     54: 01....67.9 (71) r2 = *(u8 *)(r1 +0)\n     55: 0.2...67.9 (61) r1 = *(u32 *)(r0 +8)\n     56: 012...67.9 (54) w1 &= 3\n     57: 012...67.9 (56) if w1 != 0x0 goto pc+62\n     58: 0.2...67.9 (79) r1 = *(u64 *)(r0 +24)\n     59: 012...67.9 (7b) *(u64 *)(r10 -40) = r1\n     60: 0.2...67.9 (79) r1 = *(u64 *)(r0 +16)\n     61: 012...67.9 (7b) *(u64 *)(r10 -48) = r1\n     62: 0.2...67.9 (71) r3 = *(u8 *)(r9 +8)\n     63: 0.23..67.9 (a6) if w3 < 0x2 goto pc+96\n     64: 0.23..67.9 (bf) r8 = r0\n     65: ..23..6789 (bc) w4 = w3\n     66: ..234.6789 (04) w4 += -1\n     67: ..234.6789 (73) *(u8 *)(r9 +8) = r4\n     68: ..234.678. (04) w2 += 10\n     69: ..234.678. (54) w4 &= 255\n     70: ..234.678. (bf) r1 = r6\n     71: .1234.678. (b4) w5 = 2\n     72: .12345678. (85) call bpf_l3_csum_replace#10\n     73: 0.....678. (c6) if w0 s< 0x0 goto pc+106\n     74: ......678. (bf) r3 = r10\n     75: ...3..678. (07) r3 += -40\n     76: ...3..678. (bf) r1 = r6\n     77: .1.3..678. (b4) w2 = 6\n     78: .123..678. (b4) w4 = 6\n     79: .1234.678. (b4) w5 = 0\n     80: .12345678. (85) call bpf_skb_store_bytes#9\n     81: 0.....678. (bc) w1 = w0\n     82: .1....678. (b4) w0 = -141\n     83: 01....678. (c6) if w1 s< 0x0 goto pc+48\n     84: ......678. (bf) r3 = r10\n     85: ...3..678. (07) r3 += -48\n     86: ...3..678. (bf) r1 = r6\n     87: .1.3..678. (b4) w2 = 0\n     88: .123..678. (b4) w4 = 6\n     89: .1234.678. (b4) w5 = 0\n     90: .12345678. (85) call bpf_skb_store_bytes#9\n     91: 0.....678. (bc) w1 = w0\n     92: .1....678. (b4) w0 = -141\n     93: 01....678. (c6) if w1 s< 0x0 goto pc+38\n     94: ......678. (05) goto pc+89\n     95: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     96: .1....678. (b4) w2 = 0\n     97: .12...678. (63) *(u32 *)(r10 -12) = r2\n     98: .12...678. (63) *(u32 *)(r10 -16) = r2\n     99: .12...678. (63) *(u32 *)(r10 -20) = r2\n    100: .1....678. (63) *(u32 *)(r10 -24) = r1\n    101: ......678. (b4) w1 = 64\n    102: .1....678. (63) *(u32 *)(r10 -32) = r1\n    103: ......678. (b\n... verifier log truncated ...; prog 102: prog 102 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd2d640662049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd2d640662004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd2d64066203c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd2d64066205c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8e8d07810a00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...; prog 106: prog 106 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd2d640662004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd2d64066203c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd2d640662004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+45\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8e8d06536000\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+8\n     45: 0.....67.. (05) goto pc+0\n     46: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     47: 01....67.. (07) r1 += 1\n     48: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     49: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     50: 01....67.. (0f) r1 += r7\n     51: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     52: ......6... (05) goto pc+11\n     53: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     54: ......6... (b7) r1 = 1\n     55: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     56: ......6... (bf) r2 = r10\n     57: ..2...6... (07) r2 += -24\n     58: ..2...6... (bf) r3 = r10\n     59: ..23..6... (07) r3 += -16\n     60: ..23..6... (18) r1 = 0xffff8e8d06536000\n     62: .123..6... (b4) w4 = 0\n     63: .1234.6... (85) call bpf_map_update_elem#2\n     64: ......6... (bf) r1 = r6\n     65: .1........ (18) r2 = 0xffff8e8d408da400\n     67: .12....... (b7) r3 = 1\n     68: .123...... (85) call bpf_tail_call#12\n     69: .......... (b4) w0 = 2\n     70: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd2d640662004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd2d64066203c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd2d640662004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt\n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 11 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8e8fb00d4d7a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8e8fb00d4d9a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
            "exit_code": 1,
            "prog_id": 11
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 86 pass cond_select failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd2d64021a049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd2d64021a004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd2d64021a03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd2d64021a05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8e8d07810a00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 86
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 88 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd2d64021a004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd2d64021a03c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd2d64021a004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+44\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8e8d06536000\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+7\n     45: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     46: 01....67.. (07) r1 += 1\n     47: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     48: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     49: 01....67.. (0f) r1 += r7\n     50: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     51: ......6... (05) goto pc+11\n     52: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     53: ......6... (b7) r1 = 1\n     54: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     55: ......6... (bf) r2 = r10\n     56: ..2...6... (07) r2 += -24\n     57: ..2...6... (bf) r3 = r10\n     58: ..23..6... (07) r3 += -16\n     59: ..23..6... (18) r1 = 0xffff8e8d06536000\n     61: .123..6... (b4) w4 = 0\n     62: .1234.6... (85) call bpf_map_update_elem#2\n     63: ......6... (bf) r1 = r6\n     64: .1........ (18) r2 = 0xffff8e9387403800\n     66: .12....... (b7) r3 = 1\n     67: .123...... (85) call bpf_tail_call#12\n     68: .......... (b4) w0 = 2\n     69: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd2d64021a004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd2d64021a03c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd2d64021a004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt(r=0)\n20: (0f) r5 += r3\nmark_precis\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 88
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 91 pass cond_select failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd2d6405da049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd2d6405da004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd2d6405da03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd2d6405da05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8e8d07810a00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 91
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 94 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd2d6405da004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd2d6405da03c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd2d6405da004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+44\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8e8d06536000\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+7\n     45: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     46: 01....67.. (07) r1 += 1\n     47: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     48: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     49: 01....67.. (0f) r1 += r7\n     50: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     51: ......6... (05) goto pc+11\n     52: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     53: ......6... (b7) r1 = 1\n     54: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     55: ......6... (bf) r2 = r10\n     56: ..2...6... (07) r2 += -24\n     57: ..2...6... (bf) r3 = r10\n     58: ..23..6... (07) r3 += -16\n     59: ..23..6... (18) r1 = 0xffff8e8d06536000\n     61: .123..6... (b4) w4 = 0\n     62: .1234.6... (85) call bpf_map_update_elem#2\n     63: ......6... (bf) r1 = r6\n     64: .1........ (18) r2 = 0xffff8e8d06531400\n     66: .12....... (b7) r3 = 1\n     67: .123...... (85) call bpf_tail_call#12\n     68: .......... (b4) w0 = 2\n     69: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd2d6405da004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd2d6405da03c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd2d6405da004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt(r=0)\n20: (0f) r5 += r3\nmark_precis\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 94
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 97 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (61) r7 = *(u32 *)(r6 +48)\n      2: ......67.. (b4) w1 = 0\n      3: .1....67.. (63) *(u32 *)(r6 +48) = r1\n      4: ......67.. (18) r1 = 0xffffd2d6405da004\n      6: .1....67.. (71) r1 = *(u8 *)(r1 +0)\n      7: .1....67.. (61) r2 = *(u32 *)(r6 +80)\n      8: .12...67.. (61) r3 = *(u32 *)(r6 +76)\n      9: .123..67.. (0f) r3 += r1\n     10: ..23..67.. (b4) w0 = -134\n     11: 0.23..67.. (07) r3 += 20\n     12: 0.23..67.. (2d) if r3 > r2 goto pc+119\n     13: 0.....67.. (18) r1 = 0xffffd2d6405da03c\n     15: 01....67.. (61) r1 = *(u32 *)(r1 +0)\n     16: 0.....67.. (61) r1 = *(u32 *)(r6 +44)\n     17: 01....67.. (63) *(u32 *)(r10 -32) = r1\n     18: 01....67.. (61) r2 = *(u32 *)(r10 -32)\n     19: 012...67.. (63) *(u32 *)(r10 -32) = r1\n     20: 0.2...67.. (54) w2 &= 1\n     21: 0.2...67.. (61) r1 = *(u32 *)(r10 -32)\n     22: 012...67.. (54) w1 &= 2\n     23: 012...67.. (4c) w1 |= w2\n     24: 01....67.. (b4) w8 = 1\n     25: 01....678. (56) if w1 != 0x0 goto pc+1\n     26: 0.....67.. (b4) w8 = 0\n     27: 0.....678. (18) r1 = 0xffffd2d6405da004\n     29: 01....678. (71) r1 = *(u8 *)(r1 +0)\n     30: 01....678. (61) r2 = *(u32 *)(r6 +80)\n     31: 012...678. (61) r9 = *(u32 *)(r6 +76)\n     32: 012...6789 (0f) r9 += r1\n     33: 0.2...6789 (bf) r1 = r9\n     34: 012...6789 (07) r1 += 20\n     35: 012...6789 (2d) if r1 > r2 goto pc+96\n     36: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     37: .1....6789 (b7) r2 = 0\n     38: .12...6789 (63) *(u32 *)(r10 -16) = r2\n     39: .12...6789 (63) *(u32 *)(r10 -20) = r2\n     40: .12...6789 (63) *(u32 *)(r10 -24) = r2\n     41: .12...6789 (63) *(u32 *)(r10 -28) = r2\n     42: .1....6789 (63) *(u32 *)(r10 -32) = r1\n     43: ......6789 (b4) w1 = 1\n     44: .1....6789 (73) *(u8 *)(r10 -16) = r1\n     45: ......6789 (bf) r2 = r10\n     46: ..2...6789 (07) r2 += -32\n     47: ..2...6789 (18) r1 = 0xffff8e8d20ee9c00\n     49: .12...6789 (85) call bpf_map_lookup_elem#1\n     50: 0.....6789 (15) if r0 == 0x0 goto pc+44\n     51: 0.....67.9 (05) goto pc+0\n     52: 0.....67.9 (18) r1 = 0xffffd2d6405da004\n     54: 01....67.9 (71) r2 = *(u8 *)(r1 +0)\n     55: 0.2...67.9 (61) r1 = *(u32 *)(r0 +8)\n     56: 012...67.9 (54) w1 &= 3\n     57: 012...67.9 (56) if w1 != 0x0 goto pc+62\n     58: 0.2...67.9 (79) r1 = *(u64 *)(r0 +24)\n     59: 012...67.9 (7b) *(u64 *)(r10 -40) = r1\n     60: 0.2...67.9 (79) r1 = *(u64 *)(r0 +16)\n     61: 012...67.9 (7b) *(u64 *)(r10 -48) = r1\n     62: 0.2...67.9 (71) r3 = *(u8 *)(r9 +8)\n     63: 0.23..67.9 (a6) if w3 < 0x2 goto pc+96\n     64: 0.23..67.9 (bf) r8 = r0\n     65: ..23..6789 (bc) w4 = w3\n     66: ..234.6789 (04) w4 += -1\n     67: ..234.6789 (73) *(u8 *)(r9 +8) = r4\n     68: ..234.678. (04) w2 += 10\n     69: ..234.678. (54) w4 &= 255\n     70: ..234.678. (bf) r1 = r6\n     71: .1234.678. (b4) w5 = 2\n     72: .12345678. (85) call bpf_l3_csum_replace#10\n     73: 0.....678. (c6) if w0 s< 0x0 goto pc+106\n     74: ......678. (bf) r3 = r10\n     75: ...3..678. (07) r3 += -40\n     76: ...3..678. (bf) r1 = r6\n     77: .1.3..678. (b4) w2 = 6\n     78: .123..678. (b4) w4 = 6\n     79: .1234.678. (b4) w5 = 0\n     80: .12345678. (85) call bpf_skb_store_bytes#9\n     81: 0.....678. (bc) w1 = w0\n     82: .1....678. (b4) w0 = -141\n     83: 01....678. (c6) if w1 s< 0x0 goto pc+48\n     84: ......678. (bf) r3 = r10\n     85: ...3..678. (07) r3 += -48\n     86: ...3..678. (bf) r1 = r6\n     87: .1.3..678. (b4) w2 = 0\n     88: .123..678. (b4) w4 = 6\n     89: .1234.678. (b4) w5 = 0\n     90: .12345678. (85) call bpf_skb_store_bytes#9\n     91: 0.....678. (bc) w1 = w0\n     92: .1....678. (b4) w0 = -141\n     93: 01....678. (c6) if w1 s< 0x0 goto pc+38\n     94: ......678. (05) goto pc+89\n     95: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     96: .1....678. (b4) w2 = 0\n     97: .12...678. (63) *(u32 *)(r10 -12) = r2\n     98: .12...678. (63) *(u32 *)(r10 -16) = r2\n     99: .12...678. (63) *(u32 *)(r10 -20) = r2\n    100: .1....678. (63) *(u32 *)(r10 -24) = r1\n    101: ......678. (b4) w1 = 64\n    102: .1....678. (63) *(u32 *)(r10 -32) = r1\n    103: ......678. (b\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 97
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 102 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd2d640662049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd2d640662004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd2d64066203c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd2d64066205c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8e8d07810a00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 102
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 106 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd2d640662004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd2d64066203c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd2d640662004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+45\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8e8d06536000\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+8\n     45: 0.....67.. (05) goto pc+0\n     46: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     47: 01....67.. (07) r1 += 1\n     48: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     49: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     50: 01....67.. (0f) r1 += r7\n     51: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     52: ......6... (05) goto pc+11\n     53: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     54: ......6... (b7) r1 = 1\n     55: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     56: ......6... (bf) r2 = r10\n     57: ..2...6... (07) r2 += -24\n     58: ..2...6... (bf) r3 = r10\n     59: ..23..6... (07) r3 += -16\n     60: ..23..6... (18) r1 = 0xffff8e8d06536000\n     62: .123..6... (b4) w4 = 0\n     63: .1234.6... (85) call bpf_map_update_elem#2\n     64: ......6... (bf) r1 = r6\n     65: .1........ (18) r2 = 0xffff8e8d408da400\n     67: .12....... (b7) r3 = 1\n     68: .123...... (85) call bpf_tail_call#12\n     69: .......... (b4) w0 = 2\n     70: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd2d640662004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd2d64066203c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd2d640662004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 106
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 17,
          "not_applied": 8,
          "requested": 25
        }
      },
      "runner": "cilium",
      "selected_workload": "network",
      "status": "ok"
    }
  ],
  "samples": 1,
  "status": "error",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 1,
    "per_program_geomean": 1.5246173464473802,
    "program_count": 1,
    "wins": 0
  },
  "workload_seconds": 1.0
}
```
