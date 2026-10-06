# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T12:41:01.566899+00:00",
  "kinsn_modules": {
    "captured_at": "2026-05-05T12:40:32.672706+00:00",
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
      "invoked_at": "2026-05-05T12:40:32.672648+00:00",
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
        "captured_at": "2026-05-05T12:40:32.672641+00:00",
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
      "captured_at": "2026-05-05T12:40:32.655995+00:00",
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
          "83": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 83,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "84": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 84,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "85": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 85,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "86": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 86,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "87": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 87,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "88": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 88,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "89": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 89,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 951,
            "type": "sched_cls"
          },
          "90": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 90,
            "name": "cil_from_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1042,
            "type": "sched_cls"
          },
          "91": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 91,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "92": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 92,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "93": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 93,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 584,
            "type": "sched_cls"
          },
          "94": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 94,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "95": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 95,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "96": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 96,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "97": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 97,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "98": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 98,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "99": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 99,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "100": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 100,
            "name": "cil_from_netdev",
            "run_cnt_delta": 1177,
            "run_time_ns_delta": 1311418,
            "type": "sched_cls"
          },
          "101": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 101,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "102": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 102,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "103": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 103,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "105": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 105,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "106": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 106,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 5.067740203,
            "ops_per_sec": 93.33548703226609,
            "ops_total": 473.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   348.28ms  309.65ms   1.76s    84.30%\n    Req/Sec    26.44     15.40    80.00     61.08%\n  473 requests in 5.01s, 75.64KB read\n  Socket errors: connect 0, read 0, write 0, timeout 10\nRequests/sec:     94.41\nTransfer/sec:     15.10KB"
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
          "83": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 83,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "84": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 84,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "85": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 85,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "86": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 86,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "87": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 87,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "88": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 88,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "89": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 89,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "90": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 90,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "91": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 91,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "92": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 92,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "93": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 93,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "94": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 94,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "95": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 95,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "96": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 96,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "97": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 97,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "98": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 98,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "99": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 99,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "100": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 100,
            "name": "cil_from_netdev",
            "run_cnt_delta": 1226,
            "run_time_ns_delta": 1427202,
            "type": "sched_cls"
          },
          "101": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 101,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "102": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 102,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "103": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 103,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "105": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 105,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "106": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 106,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 5.068383854000004,
            "ops_per_sec": 97.07236353294554,
            "ops_total": 492.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   390.06ms  359.54ms   1.83s    85.58%\n    Req/Sec    28.92     17.78    90.00     56.25%\n  492 requests in 5.01s, 77.98KB read\n  Socket errors: connect 0, read 0, write 0, timeout 12\nRequests/sec:     98.19\nTransfer/sec:     15.56KB"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "map_inline"
        ],
        "error": "prog 10: prog 10 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 11: prog 11 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 83: prog 83 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 84: prog 84 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 85: prog 85 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 86: prog 86 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 87: prog 87 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 88: prog 88 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 89: prog 89 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 90: prog 90 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 91: prog 91 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 92: prog 92 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 93: prog 93 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 94: prog 94 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 95: prog 95 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 96: prog 96 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 97: prog 97 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 98: prog 98 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 99: prog 99 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 100: prog 100 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 101: prog 101 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 102: prog 102 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 103: prog 103 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 105: prog 105 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 106: prog 106 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
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
            "error": "prog 83 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 83
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 84 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 84
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 85 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 85
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 86 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 86
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 87 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 87
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 88 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 88
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 89 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 89
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 90 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 90
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 91 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 91
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 92 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 92
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 93 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 93
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 94 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 94
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 95 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 95
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 96 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 96
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 97 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 97
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 98 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 98
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 99 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 99
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 100 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 100
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 101 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 101
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 102 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 102
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 103 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 103
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 105 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 105
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 106 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 106
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 0,
          "not_applied": 25,
          "requested": 25
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
