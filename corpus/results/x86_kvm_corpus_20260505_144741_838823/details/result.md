# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T14:48:12.448410+00:00",
  "kinsn_modules": {
    "captured_at": "2026-05-05T14:47:41.867859+00:00",
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
      "invoked_at": "2026-05-05T14:47:41.867795+00:00",
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
        "captured_at": "2026-05-05T14:47:41.867787+00:00",
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
      "captured_at": "2026-05-05T14:47:41.855821+00:00",
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
  "results": [
    {
      "app": "cilium/agent",
      "baseline": {
        "bpf": {
          "10": {
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 10,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "11": {
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 11,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "107": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 107,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "108": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 108,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "110": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 110,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "111": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 111,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "112": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 112,
            "name": "cil_from_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1488,
            "type": "sched_cls"
          },
          "114": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 114,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 736,
            "type": "sched_cls"
          },
          "115": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 115,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 697,
            "type": "sched_cls"
          },
          "116": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 116,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "117": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 117,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "118": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 118,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "123": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 123,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "124": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 124,
            "name": "cil_from_netdev",
            "run_cnt_delta": 1300,
            "run_time_ns_delta": 1234919,
            "type": "sched_cls"
          },
          "125": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 125,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "126": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 126,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "127": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 127,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "128": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 128,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "129": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 129,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 5.080218419999994,
            "ops_per_sec": 104.52306497483244,
            "ops_total": 531.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   308.36ms  270.58ms   1.83s    86.16%\n    Req/Sec    30.30     16.93    70.00     60.25%\n  531 requests in 5.01s, 84.96KB read\n  Socket errors: connect 0, read 0, write 0, timeout 12\nRequests/sec:    106.02\nTransfer/sec:     16.96KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "10": {
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 10,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "11": {
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 11,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "107": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 107,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "108": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 108,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "110": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 110,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "111": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 111,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "112": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 112,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "114": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 114,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "115": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 115,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "116": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 116,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "117": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 117,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "118": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 118,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "123": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 123,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "124": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 124,
            "name": "cil_from_netdev",
            "run_cnt_delta": 1461,
            "run_time_ns_delta": 1379311,
            "type": "sched_cls"
          },
          "125": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 125,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "126": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 126,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "127": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 127,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "128": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 128,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "129": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 129,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 5.0822543499999995,
            "ops_per_sec": 119.43518726094456,
            "ops_total": 607.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   364.08ms  307.94ms   2.00s    83.64%\n    Req/Sec    32.44     17.76   101.00     74.59%\n  607 requests in 5.01s, 95.65KB read\n  Socket errors: connect 0, read 0, write 0, timeout 2\nRequests/sec:    121.23\nTransfer/sec:     19.10KB"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 10: prog 10 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 11: prog 11 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 107: prog 107 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 108: prog 108 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 110: prog 110 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 111: prog 111 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 112: prog 112 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 114: prog 114 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 115: prog 115 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 116: prog 116 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 117: prog 117 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 118: prog 118 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 123: prog 123 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 124: prog 124 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 125: prog 125 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 126: prog 126 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 127: prog 127 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 128: prog 128 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 129: prog 129 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 10 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 10
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 11 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 11
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 107 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 107
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 108 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 108
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 110 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 110
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 111 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 111
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 112 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 112
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 114 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 114
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 115 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 115
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 116 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 116
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 117 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 117
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 118 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 118
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 123 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 123
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 124 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 124
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 125 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 125
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 126 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 126
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 127 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 127
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 128 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 128
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 129 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 129
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 0,
          "not_applied": 19,
          "requested": 19
        }
      },
      "runner": "cilium",
      "selected_workload": "network_lossy_multi",
      "status": "ok"
    }
  ],
  "samples": 1,
  "status": "ok",
  "suite_name": "macro_apps",
  "workload_seconds": 3.0
}
```
