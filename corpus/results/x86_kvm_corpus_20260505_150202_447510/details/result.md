# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T15:02:27.634712+00:00",
  "kop_modules": {
    "captured_at": "2026-05-05T15:02:02.465867+00:00",
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
      "invoked_at": "2026-05-05T15:02:02.465801+00:00",
      "loaded_count": 6,
      "loaded_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "loader": "runner.libs.kop.load_kop_modules",
      "module_dir": "/artifacts/kop",
      "newly_loaded_modules": [],
      "snapshot_after": {
        "captured_at": "2026-05-05T15:02:02.465793+00:00",
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
      "captured_at": "2026-05-05T15:02:02.455207+00:00",
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
          "52": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 52,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "53": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 53,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "54": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 54,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "55": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 55,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "57": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 57,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "58": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 58,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "61": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 61,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "62": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 62,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "63": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 63,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "65": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 65,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "66": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 66,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "67": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 67,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "68": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 68,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "69": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 69,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "70": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 70,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "71": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 71,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "72": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 72,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "74": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 74,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "76": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 76,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "77": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 77,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "78": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 78,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "79": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 79,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "81": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 81,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "82": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 82,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "84": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 84,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "85": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 85,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "86": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 86,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "87": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 87,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "88": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 88,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "91": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 91,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "92": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 92,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "93": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 93,
            "name": "cil_from_netdev",
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
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 95,
            "name": "tail_handle_ipv4_from_netdev",
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
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 97,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "99": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 99,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "100": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 100,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "101": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 101,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "102": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 102,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "104": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 104,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "105": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 105,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
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
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 108,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "109": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 109,
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
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 111,
            "name": "cil_from_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1887,
            "type": "sched_cls"
          },
          "112": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 112,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "113": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 113,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "114": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 114,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 968,
            "type": "sched_cls"
          },
          "115": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 115,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "116": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 116,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 582,
            "type": "sched_cls"
          },
          "117": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 117,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "118": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 118,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "119": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 119,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "120": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 120,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "121": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 121,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "122": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 122,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "123": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 123,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "124": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 124,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "125": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 125,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "126": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 126,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "128": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 128,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "129": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 129,
            "name": "cil_from_netdev",
            "run_cnt_delta": 1449,
            "run_time_ns_delta": 882755,
            "type": "sched_cls"
          },
          "130": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 130,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 5.068079025999992,
            "ops_per_sec": 118.97999161152009,
            "ops_total": 603.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   350.72ms  317.66ms   1.67s    84.93%\n    Req/Sec    32.94     16.16    80.00     63.07%\n  603 requests in 5.01s, 95.45KB read\n  Socket errors: connect 0, read 0, write 0, timeout 6\nRequests/sec:    120.32\nTransfer/sec:     19.05KB"
          }
        ]
      },
      "error": "BPF stats missing requested program IDs: 52, 53, 54, 55, 57, 58, 61, 62, 63, 65, 66, 67, 68, 69, 70, 71, 72, 74, 76, 77, 78, 79, 81, 82, 84, 85, 86, 87, 88, 91, 92, 93, 94, 95, 96, 97, 99, 100, 101, 102, 104, 105, 108, 112, 115, 118, 120, 122, 123, 125, 128",
      "post_rejit": null,
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "endian_fusion"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 10
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 11
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 52
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 53
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 54
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 55
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 58
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 61
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 62
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 63
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 65
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 66
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 67
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 68
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 69
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 70
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 71
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 72
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 74
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 76
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 77
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 79
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 81
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 82
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 84
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 85
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 86
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 87
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 88
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 91
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 92
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 93
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 94
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 95
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 96
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 97
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 99
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 101
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 102
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 104
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 105
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 107
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 108
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 109
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 110
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 111
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 112
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 113
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 115
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 117
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 118
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 119
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 120
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 121
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 122
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 124
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 125
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 126
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 128
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 129
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "endian_fusion",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 130
          }
        ],
        "program_counts": {
          "applied": 6,
          "not_applied": 61,
          "requested": 67
        }
      },
      "runner": "cilium",
      "selected_workload": "network_lossy_multi",
      "status": "error"
    }
  ],
  "samples": 1,
  "status": "error",
  "suite_name": "macro_apps",
  "workload_seconds": 3.0
}
```
