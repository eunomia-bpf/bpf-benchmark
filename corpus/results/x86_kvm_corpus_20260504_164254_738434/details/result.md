# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-04T16:43:23.271417+00:00",
  "kop_modules": {
    "captured_at": "2026-05-04T16:42:54.771817+00:00",
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
      "invoked_at": "2026-05-04T16:42:54.771752+00:00",
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
        "captured_at": "2026-05-04T16:42:54.771745+00:00",
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
      "captured_at": "2026-05-04T16:42:54.755218+00:00",
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
      "baseline_avg_ns_per_run": 1279.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1279,
      "post_rejit_avg_ns_per_run": 861.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 861,
      "program": "cil_to_host",
      "program_id": 211,
      "ratio": 0.673182173573104,
      "runner": "cilium",
      "type": "sched_cls",
      "workload": "network"
    },
    {
      "app": "cilium/agent",
      "baseline_avg_ns_per_run": 1602.112359550562,
      "baseline_run_cnt_delta": 267,
      "baseline_run_time_ns_delta": 427764,
      "post_rejit_avg_ns_per_run": 1733.9405940594058,
      "post_rejit_run_cnt_delta": 303,
      "post_rejit_run_time_ns_delta": 525384,
      "program": "cil_from_netdev",
      "program_id": 230,
      "ratio": 1.0822840131798406,
      "runner": "cilium",
      "type": "sched_cls",
      "workload": "network"
    }
  ],
  "results": [
    {
      "app": "calico/felix",
      "baseline": null,
      "error": "network wrk load failed via /usr/bin/wrk -t2 -c10 -d1s http://198.18.0.2:18080/: unable to connect to 198.18.0.2:18080 Connection timed out",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "calico",
      "selected_workload": "network",
      "status": "error"
    },
    {
      "app": "cilium/agent",
      "baseline": {
        "bpf": {
          "138": {
            "avg_ns_per_run": null,
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 138,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "139": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 139,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "163": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 163,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "165": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 165,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "166": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 166,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "167": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 167,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "169": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 169,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "171": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 171,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "172": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 172,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "173": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 173,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "175": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 175,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "176": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 176,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "177": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 177,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "178": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 178,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "181": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 181,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "182": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 182,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "183": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 183,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "184": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 184,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "185": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 185,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 186,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "187": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 187,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "188": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 188,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 189,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "191": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 191,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "193": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 193,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "195": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 195,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "196": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 196,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "197": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 197,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "198": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 198,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "199": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 199,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 200,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 201,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "203": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 203,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "204": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 204,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "205": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 205,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "207": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 207,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "209": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 209,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "210": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 210,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "211": {
            "avg_ns_per_run": 1279.0,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 211,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1279,
            "type": "sched_cls"
          },
          "212": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 212,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 213,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 214,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 215,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "216": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 216,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 217,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 218,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 219,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 220,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 221,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 222,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "223": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 223,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "224": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 224,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 225,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "226": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 226,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 227,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "228": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 228,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 229,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "230": {
            "avg_ns_per_run": 1602.112359550562,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 230,
            "name": "cil_from_netdev",
            "run_cnt_delta": 267,
            "run_time_ns_delta": 427764,
            "type": "sched_cls"
          },
          "232": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 232,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "233": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 233,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "234": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 234,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0066742180000006,
            "ops_per_sec": 119.20440382232967,
            "ops_total": 120.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    48.41ms   11.19ms  60.11ms   86.67%\n    Req/Sec    60.00     22.64   111.00     90.00%\n  120 requests in 1.00s, 18.97KB read\nRequests/sec:    119.49\nTransfer/sec:     18.89KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "138": {
            "avg_ns_per_run": null,
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 138,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "139": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 139,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "163": {
            "avg_ns_per_run": null,
            "bytes_jited": 1192,
            "bytes_xlated": 2024,
            "id": 163,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "165": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 165,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "166": {
            "avg_ns_per_run": null,
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 166,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "167": {
            "avg_ns_per_run": null,
            "bytes_jited": 1242,
            "bytes_xlated": 2088,
            "id": 167,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "169": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 169,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "171": {
            "avg_ns_per_run": null,
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 171,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "172": {
            "avg_ns_per_run": null,
            "bytes_jited": 1242,
            "bytes_xlated": 2088,
            "id": 172,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "173": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 173,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "175": {
            "avg_ns_per_run": null,
            "bytes_jited": 1192,
            "bytes_xlated": 2024,
            "id": 175,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "176": {
            "avg_ns_per_run": null,
            "bytes_jited": 385,
            "bytes_xlated": 608,
            "id": 176,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "177": {
            "avg_ns_per_run": null,
            "bytes_jited": 3361,
            "bytes_xlated": 6064,
            "id": 177,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "178": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 178,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "181": {
            "avg_ns_per_run": null,
            "bytes_jited": 535,
            "bytes_xlated": 976,
            "id": 181,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "182": {
            "avg_ns_per_run": null,
            "bytes_jited": 3361,
            "bytes_xlated": 6064,
            "id": 182,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "183": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 183,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "184": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 184,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "185": {
            "avg_ns_per_run": null,
            "bytes_jited": 385,
            "bytes_xlated": 608,
            "id": 185,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 1192,
            "bytes_xlated": 2024,
            "id": 186,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "187": {
            "avg_ns_per_run": null,
            "bytes_jited": 385,
            "bytes_xlated": 608,
            "id": 187,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "188": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 188,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 189,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "191": {
            "avg_ns_per_run": null,
            "bytes_jited": 1242,
            "bytes_xlated": 2088,
            "id": 191,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "193": {
            "avg_ns_per_run": null,
            "bytes_jited": 1192,
            "bytes_xlated": 2024,
            "id": 193,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "195": {
            "avg_ns_per_run": null,
            "bytes_jited": 1242,
            "bytes_xlated": 2088,
            "id": 195,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "196": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 196,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "197": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 197,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "198": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 198,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "199": {
            "avg_ns_per_run": null,
            "bytes_jited": 3361,
            "bytes_xlated": 6064,
            "id": 199,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 200,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 201,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "203": {
            "avg_ns_per_run": null,
            "bytes_jited": 385,
            "bytes_xlated": 608,
            "id": 203,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "204": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 204,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "205": {
            "avg_ns_per_run": null,
            "bytes_jited": 1192,
            "bytes_xlated": 2024,
            "id": 205,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "207": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 207,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "209": {
            "avg_ns_per_run": null,
            "bytes_jited": 3361,
            "bytes_xlated": 6064,
            "id": 209,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "210": {
            "avg_ns_per_run": null,
            "bytes_jited": 535,
            "bytes_xlated": 976,
            "id": 210,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "211": {
            "avg_ns_per_run": 861.0,
            "bytes_jited": 535,
            "bytes_xlated": 976,
            "id": 211,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 861,
            "type": "sched_cls"
          },
          "212": {
            "avg_ns_per_run": null,
            "bytes_jited": 1242,
            "bytes_xlated": 2088,
            "id": 212,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 213,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 3361,
            "bytes_xlated": 6064,
            "id": 214,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 215,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "216": {
            "avg_ns_per_run": null,
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 216,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 217,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 1192,
            "bytes_xlated": 2024,
            "id": 218,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 219,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 3361,
            "bytes_xlated": 6064,
            "id": 220,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 535,
            "bytes_xlated": 976,
            "id": 221,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 222,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "223": {
            "avg_ns_per_run": null,
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 223,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "224": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 224,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 1192,
            "bytes_xlated": 2024,
            "id": 225,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "226": {
            "avg_ns_per_run": null,
            "bytes_jited": 1242,
            "bytes_xlated": 2088,
            "id": 226,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 3361,
            "bytes_xlated": 6064,
            "id": 227,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "228": {
            "avg_ns_per_run": null,
            "bytes_jited": 1192,
            "bytes_xlated": 2024,
            "id": 228,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 229,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "230": {
            "avg_ns_per_run": 1733.9405940594058,
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 230,
            "name": "cil_from_netdev",
            "run_cnt_delta": 303,
            "run_time_ns_delta": 525384,
            "type": "sched_cls"
          },
          "232": {
            "avg_ns_per_run": null,
            "bytes_jited": 385,
            "bytes_xlated": 608,
            "id": 232,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "233": {
            "avg_ns_per_run": null,
            "bytes_jited": 535,
            "bytes_xlated": 976,
            "id": 233,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "234": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 234,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0045318550000104,
            "ops_per_sec": 135.38644824757557,
            "ops_total": 136.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    50.83ms   17.96ms 202.73ms   94.16%\n    Req/Sec    68.10     29.42   101.00     60.00%\n  136 requests in 1.00s, 21.53KB read\nRequests/sec:    135.77\nTransfer/sec:     21.49KB"
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
        "error": "prog 139: prog 139 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8b6b34e48d7a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8b6b34e48d9a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 165: prog 165 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c04b2049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c04b2004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c04b203c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c04b205c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...; prog 169: prog 169 pass cond_select failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd275c04b2004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd275c04b203c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd275c04b2004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+44\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8b6a120c5800\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+7\n     45: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     46: 01....67.. (07) r1 += 1\n     47: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     48: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     49: 01....67.. (0f) r1 += r7\n     50: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     51: ......6... (05) goto pc+11\n     52: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     53: ......6... (b7) r1 = 1\n     54: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     55: ......6... (bf) r2 = r10\n     56: ..2...6... (07) r2 += -24\n     57: ..2...6... (bf) r3 = r10\n     58: ..23..6... (07) r3 += -16\n     59: ..23..6... (18) r1 = 0xffff8b6a120c5800\n     61: .123..6... (b4) w4 = 0\n     62: .1234.6... (85) call bpf_map_update_elem#2\n     63: ......6... (bf) r1 = r6\n     64: .1........ (18) r2 = 0xffff8b69c3e6b000\n     66: .12....... (b7) r3 = 1\n     67: .123...... (85) call bpf_tail_call#12\n     68: .......... (b4) w0 = 2\n     69: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd275c04b2004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd275c04b203c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd275c04b2004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt(r=0)\n20: (0f) r5 += r3\nmark_precis\n... verifier log truncated ...; prog 178: prog 178 pass cond_select failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c0652049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c0652004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c065203c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c065205c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...; prog 183: prog 183 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c07f3049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c07f3004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c07f303c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c07f305c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...; prog 188: prog 188 pass cond_select failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c0ab6049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c0ab6004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c0ab603c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c0ab605c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...; prog 196: prog 196 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd275c0c13004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd275c0c1303c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd275c0c13004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+44\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8b6a120c5800\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+7\n     45: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     46: 01....67.. (07) r1 += 1\n     47: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     48: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     49: 01....67.. (0f) r1 += r7\n     50: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     51: ......6... (05) goto pc+11\n     52: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     53: ......6... (b7) r1 = 1\n     54: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     55: ......6... (bf) r2 = r10\n     56: ..2...6... (07) r2 += -24\n     57: ..2...6... (bf) r3 = r10\n     58: ..23..6... (07) r3 += -16\n     59: ..23..6... (18) r1 = 0xffff8b6a120c5800\n     61: .123..6... (b4) w4 = 0\n     62: .1234.6... (85) call bpf_map_update_elem#2\n     63: ......6... (bf) r1 = r6\n     64: .1........ (18) r2 = 0xffff8b6bb26eb800\n     66: .12....... (b7) r3 = 1\n     67: .123...... (85) call bpf_tail_call#12\n     68: .......... (b4) w0 = 2\n     69: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd275c0c13004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd275c0c1303c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd275c0c13004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt(r=0)\n20: (0f) r5 += r3\nmark_precis\n... verifier log truncated ...; prog 197: prog 197 pass cond_select failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c0c13049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c0c13004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c0c1303c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c0c1305c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...; prog 198: prog 198 pass endian_fusion failed after 3 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (61) r7 = *(u32 *)(r6 +48)\n      2: ......67.. (b4) w1 = 0\n      3: .1....67.. (63) *(u32 *)(r6 +48) = r1\n      4: ......67.. (18) r1 = 0xffffd275c0c13004\n      6: .1....67.. (71) r1 = *(u8 *)(r1 +0)\n      7: .1....67.. (61) r2 = *(u32 *)(r6 +80)\n      8: .12...67.. (61) r3 = *(u32 *)(r6 +76)\n      9: .123..67.. (0f) r3 += r1\n     10: ..23..67.. (b4) w0 = -134\n     11: 0.23..67.. (07) r3 += 20\n     12: 0.23..67.. (2d) if r3 > r2 goto pc+118\n     13: 0.....67.. (18) r1 = 0xffffd275c0c1303c\n     15: 01....67.. (61) r1 = *(u32 *)(r1 +0)\n     16: 0.....67.. (61) r1 = *(u32 *)(r6 +44)\n     17: 01....67.. (63) *(u32 *)(r10 -32) = r1\n     18: 01....67.. (61) r2 = *(u32 *)(r10 -32)\n     19: 012...67.. (63) *(u32 *)(r10 -32) = r1\n     20: 0.2...67.. (54) w2 &= 1\n     21: 0.2...67.. (61) r1 = *(u32 *)(r10 -32)\n     22: 012...67.. (54) w1 &= 2\n     23: 012...67.. (4c) w1 |= w2\n     24: 01....67.. (b4) w8 = 1\n     25: 01....678. (56) if w1 != 0x0 goto pc+1\n     26: 0.....67.. (b4) w8 = 0\n     27: 0.....678. (18) r1 = 0xffffd275c0c13004\n     29: 01....678. (71) r1 = *(u8 *)(r1 +0)\n     30: 01....678. (61) r2 = *(u32 *)(r6 +80)\n     31: 012...678. (61) r9 = *(u32 *)(r6 +76)\n     32: 012...6789 (0f) r9 += r1\n     33: 0.2...6789 (bf) r1 = r9\n     34: 012...6789 (07) r1 += 20\n     35: 012...6789 (2d) if r1 > r2 goto pc+95\n     36: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     37: .1....6789 (b7) r2 = 0\n     38: .12...6789 (63) *(u32 *)(r10 -16) = r2\n     39: .12...6789 (63) *(u32 *)(r10 -20) = r2\n     40: .12...6789 (63) *(u32 *)(r10 -24) = r2\n     41: .12...6789 (63) *(u32 *)(r10 -28) = r2\n     42: .1....6789 (63) *(u32 *)(r10 -32) = r1\n     43: ......6789 (b4) w1 = 1\n     44: .1....6789 (73) *(u8 *)(r10 -16) = r1\n     45: ......6789 (bf) r2 = r10\n     46: ..2...6789 (07) r2 += -32\n     47: ..2...6789 (18) r1 = 0xffff8b69c8d8e000\n     49: .12...6789 (85) call bpf_map_lookup_elem#1\n     50: 0.....6789 (15) if r0 == 0x0 goto pc+43\n     51: 0.....67.9 (18) r1 = 0xffffd275c0c13004\n     53: 01....67.9 (71) r2 = *(u8 *)(r1 +0)\n     54: 0.2...67.9 (61) r1 = *(u32 *)(r0 +8)\n     55: 012...67.9 (54) w1 &= 3\n     56: 012...67.9 (56) if w1 != 0x0 goto pc+62\n     57: 0.2...67.9 (79) r1 = *(u64 *)(r0 +24)\n     58: 012...67.9 (7b) *(u64 *)(r10 -40) = r1\n     59: 0.2...67.9 (79) r1 = *(u64 *)(r0 +16)\n     60: 012...67.9 (7b) *(u64 *)(r10 -48) = r1\n     61: 0.2...67.9 (71) r3 = *(u8 *)(r9 +8)\n     62: 0.23..67.9 (a6) if w3 < 0x2 goto pc+95\n     63: 0.23..67.9 (bf) r8 = r0\n     64: ..23..6789 (bc) w4 = w3\n     65: ..234.6789 (04) w4 += -1\n     66: ..234.6789 (73) *(u8 *)(r9 +8) = r4\n     67: ..234.678. (04) w2 += 10\n     68: ..234.678. (54) w4 &= 255\n     69: ..234.678. (bf) r1 = r6\n     70: .1234.678. (b4) w5 = 2\n     71: .12345678. (85) call bpf_l3_csum_replace#10\n     72: 0.....678. (c6) if w0 s< 0x0 goto pc+105\n     73: ......678. (bf) r3 = r10\n     74: ...3..678. (07) r3 += -40\n     75: ...3..678. (bf) r1 = r6\n     76: .1.3..678. (b4) w2 = 6\n     77: .123..678. (b4) w4 = 6\n     78: .1234.678. (b4) w5 = 0\n     79: .12345678. (85) call bpf_skb_store_bytes#9\n     80: 0.....678. (bc) w1 = w0\n     81: .1....678. (b4) w0 = -141\n     82: 01....678. (c6) if w1 s< 0x0 goto pc+48\n     83: ......678. (bf) r3 = r10\n     84: ...3..678. (07) r3 += -48\n     85: ...3..678. (bf) r1 = r6\n     86: .1.3..678. (b4) w2 = 0\n     87: .123..678. (b4) w4 = 6\n     88: .1234.678. (b4) w5 = 0\n     89: .12345678. (85) call bpf_skb_store_bytes#9\n     90: 0.....678. (bc) w1 = w0\n     91: .1....678. (b4) w0 = -141\n     92: 01....678. (c6) if w1 s< 0x0 goto pc+38\n     93: ......678. (05) goto pc+88\n     94: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     95: .1....678. (b4) w2 = 0\n     96: .12...678. (63) *(u32 *)(r10 -12) = r2\n     97: .12...678. (63) *(u32 *)(r10 -16) = r2\n     98: .12...678. (63) *(u32 *)(r10 -20) = r2\n     99: .1....678. (63) *(u32 *)(r10 -24) = r1\n    100: ......678. (b4) w1 = 64\n    101: .1....678. (63) *(u32 *)(r10 -32) = r1\n    102: ......678. (b4) w1 = 16777216\n    103: .1....678\n... verifier log truncated ...; prog 204: prog 204 pass bulk_memory failed after 4 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c0fda049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c0fda004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c0fda03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c0fda05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...; prog 215: prog 215 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c1e6e049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c1e6e004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c1e6e03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c1e6e05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...; prog 217: prog 217 pass endian_fusion failed after 3 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd275c1e6e004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd275c1e6e03c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd275c1e6e004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+44\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8b6a120c5800\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+7\n     45: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     46: 01....67.. (07) r1 += 1\n     47: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     48: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     49: 01....67.. (0f) r1 += r7\n     50: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     51: ......6... (05) goto pc+11\n     52: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     53: ......6... (b7) r1 = 1\n     54: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     55: ......6... (bf) r2 = r10\n     56: ..2...6... (07) r2 += -24\n     57: ..2...6... (bf) r3 = r10\n     58: ..23..6... (07) r3 += -16\n     59: ..23..6... (18) r1 = 0xffff8b6a120c5800\n     61: .123..6... (b4) w4 = 0\n     62: .1234.6... (85) call bpf_map_update_elem#2\n     63: ......6... (bf) r1 = r6\n     64: .1........ (18) r2 = 0xffff8b6a120c0000\n     66: .12....... (b7) r3 = 1\n     67: .123...... (85) call bpf_tail_call#12\n     68: .......... (b4) w0 = 2\n     69: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd275c1e6e004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd275c1e6e03c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd275c1e6e004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt(r=0)\n20: (0f) r5 += r3\nmark_precis\n... verifier log truncated ...; prog 219: prog 219 pass bulk_memory failed after 4 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd275c24fa004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd275c24fa03c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd275c24fa004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+44\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8b6a120c5800\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+7\n     45: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     46: 01....67.. (07) r1 += 1\n     47: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     48: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     49: 01....67.. (0f) r1 += r7\n     50: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     51: ......6... (05) goto pc+11\n     52: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     53: ......6... (b7) r1 = 1\n     54: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     55: ......6... (bf) r2 = r10\n     56: ..2...6... (07) r2 += -24\n     57: ..2...6... (bf) r3 = r10\n     58: ..23..6... (07) r3 += -16\n     59: ..23..6... (18) r1 = 0xffff8b6a120c5800\n     61: .123..6... (b4) w4 = 0\n     62: .1234.6... (85) call bpf_map_update_elem#2\n     63: ......6... (bf) r1 = r6\n     64: .1........ (18) r2 = 0xffff8b6a0e6aa800\n     66: .12....... (b7) r3 = 1\n     67: .123...... (85) call bpf_tail_call#12\n     68: .......... (b4) w0 = 2\n     69: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd275c24fa004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd275c24fa03c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd275c24fa004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt(r=0)\n20: (0f) r5 += r3\nmark_precis\n... verifier log truncated ...; prog 222: prog 222 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c24fa049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c24fa004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c24fa03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c24fa05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 139 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8b6b34e48d7a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8b6b34e48d9a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
            "exit_code": 1,
            "prog_id": 139
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 165 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c04b2049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c04b2004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c04b203c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c04b205c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 165
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 169 pass cond_select failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd275c04b2004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd275c04b203c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd275c04b2004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+44\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8b6a120c5800\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+7\n     45: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     46: 01....67.. (07) r1 += 1\n     47: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     48: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     49: 01....67.. (0f) r1 += r7\n     50: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     51: ......6... (05) goto pc+11\n     52: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     53: ......6... (b7) r1 = 1\n     54: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     55: ......6... (bf) r2 = r10\n     56: ..2...6... (07) r2 += -24\n     57: ..2...6... (bf) r3 = r10\n     58: ..23..6... (07) r3 += -16\n     59: ..23..6... (18) r1 = 0xffff8b6a120c5800\n     61: .123..6... (b4) w4 = 0\n     62: .1234.6... (85) call bpf_map_update_elem#2\n     63: ......6... (bf) r1 = r6\n     64: .1........ (18) r2 = 0xffff8b69c3e6b000\n     66: .12....... (b7) r3 = 1\n     67: .123...... (85) call bpf_tail_call#12\n     68: .......... (b4) w0 = 2\n     69: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd275c04b2004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd275c04b203c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd275c04b2004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt(r=0)\n20: (0f) r5 += r3\nmark_precis\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 169
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 178 pass cond_select failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c0652049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c0652004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c065203c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c065205c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 178
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 183 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c07f3049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c07f3004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c07f303c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c07f305c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 183
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 188 pass cond_select failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c0ab6049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c0ab6004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c0ab603c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c0ab605c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 188
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 196 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd275c0c13004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd275c0c1303c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd275c0c13004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+44\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8b6a120c5800\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+7\n     45: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     46: 01....67.. (07) r1 += 1\n     47: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     48: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     49: 01....67.. (0f) r1 += r7\n     50: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     51: ......6... (05) goto pc+11\n     52: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     53: ......6... (b7) r1 = 1\n     54: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     55: ......6... (bf) r2 = r10\n     56: ..2...6... (07) r2 += -24\n     57: ..2...6... (bf) r3 = r10\n     58: ..23..6... (07) r3 += -16\n     59: ..23..6... (18) r1 = 0xffff8b6a120c5800\n     61: .123..6... (b4) w4 = 0\n     62: .1234.6... (85) call bpf_map_update_elem#2\n     63: ......6... (bf) r1 = r6\n     64: .1........ (18) r2 = 0xffff8b6bb26eb800\n     66: .12....... (b7) r3 = 1\n     67: .123...... (85) call bpf_tail_call#12\n     68: .......... (b4) w0 = 2\n     69: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd275c0c13004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd275c0c1303c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd275c0c13004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt(r=0)\n20: (0f) r5 += r3\nmark_precis\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 196
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 197 pass cond_select failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c0c13049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c0c13004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c0c1303c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c0c1305c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 197
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 198 pass endian_fusion failed after 3 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (61) r7 = *(u32 *)(r6 +48)\n      2: ......67.. (b4) w1 = 0\n      3: .1....67.. (63) *(u32 *)(r6 +48) = r1\n      4: ......67.. (18) r1 = 0xffffd275c0c13004\n      6: .1....67.. (71) r1 = *(u8 *)(r1 +0)\n      7: .1....67.. (61) r2 = *(u32 *)(r6 +80)\n      8: .12...67.. (61) r3 = *(u32 *)(r6 +76)\n      9: .123..67.. (0f) r3 += r1\n     10: ..23..67.. (b4) w0 = -134\n     11: 0.23..67.. (07) r3 += 20\n     12: 0.23..67.. (2d) if r3 > r2 goto pc+118\n     13: 0.....67.. (18) r1 = 0xffffd275c0c1303c\n     15: 01....67.. (61) r1 = *(u32 *)(r1 +0)\n     16: 0.....67.. (61) r1 = *(u32 *)(r6 +44)\n     17: 01....67.. (63) *(u32 *)(r10 -32) = r1\n     18: 01....67.. (61) r2 = *(u32 *)(r10 -32)\n     19: 012...67.. (63) *(u32 *)(r10 -32) = r1\n     20: 0.2...67.. (54) w2 &= 1\n     21: 0.2...67.. (61) r1 = *(u32 *)(r10 -32)\n     22: 012...67.. (54) w1 &= 2\n     23: 012...67.. (4c) w1 |= w2\n     24: 01....67.. (b4) w8 = 1\n     25: 01....678. (56) if w1 != 0x0 goto pc+1\n     26: 0.....67.. (b4) w8 = 0\n     27: 0.....678. (18) r1 = 0xffffd275c0c13004\n     29: 01....678. (71) r1 = *(u8 *)(r1 +0)\n     30: 01....678. (61) r2 = *(u32 *)(r6 +80)\n     31: 012...678. (61) r9 = *(u32 *)(r6 +76)\n     32: 012...6789 (0f) r9 += r1\n     33: 0.2...6789 (bf) r1 = r9\n     34: 012...6789 (07) r1 += 20\n     35: 012...6789 (2d) if r1 > r2 goto pc+95\n     36: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     37: .1....6789 (b7) r2 = 0\n     38: .12...6789 (63) *(u32 *)(r10 -16) = r2\n     39: .12...6789 (63) *(u32 *)(r10 -20) = r2\n     40: .12...6789 (63) *(u32 *)(r10 -24) = r2\n     41: .12...6789 (63) *(u32 *)(r10 -28) = r2\n     42: .1....6789 (63) *(u32 *)(r10 -32) = r1\n     43: ......6789 (b4) w1 = 1\n     44: .1....6789 (73) *(u8 *)(r10 -16) = r1\n     45: ......6789 (bf) r2 = r10\n     46: ..2...6789 (07) r2 += -32\n     47: ..2...6789 (18) r1 = 0xffff8b69c8d8e000\n     49: .12...6789 (85) call bpf_map_lookup_elem#1\n     50: 0.....6789 (15) if r0 == 0x0 goto pc+43\n     51: 0.....67.9 (18) r1 = 0xffffd275c0c13004\n     53: 01....67.9 (71) r2 = *(u8 *)(r1 +0)\n     54: 0.2...67.9 (61) r1 = *(u32 *)(r0 +8)\n     55: 012...67.9 (54) w1 &= 3\n     56: 012...67.9 (56) if w1 != 0x0 goto pc+62\n     57: 0.2...67.9 (79) r1 = *(u64 *)(r0 +24)\n     58: 012...67.9 (7b) *(u64 *)(r10 -40) = r1\n     59: 0.2...67.9 (79) r1 = *(u64 *)(r0 +16)\n     60: 012...67.9 (7b) *(u64 *)(r10 -48) = r1\n     61: 0.2...67.9 (71) r3 = *(u8 *)(r9 +8)\n     62: 0.23..67.9 (a6) if w3 < 0x2 goto pc+95\n     63: 0.23..67.9 (bf) r8 = r0\n     64: ..23..6789 (bc) w4 = w3\n     65: ..234.6789 (04) w4 += -1\n     66: ..234.6789 (73) *(u8 *)(r9 +8) = r4\n     67: ..234.678. (04) w2 += 10\n     68: ..234.678. (54) w4 &= 255\n     69: ..234.678. (bf) r1 = r6\n     70: .1234.678. (b4) w5 = 2\n     71: .12345678. (85) call bpf_l3_csum_replace#10\n     72: 0.....678. (c6) if w0 s< 0x0 goto pc+105\n     73: ......678. (bf) r3 = r10\n     74: ...3..678. (07) r3 += -40\n     75: ...3..678. (bf) r1 = r6\n     76: .1.3..678. (b4) w2 = 6\n     77: .123..678. (b4) w4 = 6\n     78: .1234.678. (b4) w5 = 0\n     79: .12345678. (85) call bpf_skb_store_bytes#9\n     80: 0.....678. (bc) w1 = w0\n     81: .1....678. (b4) w0 = -141\n     82: 01....678. (c6) if w1 s< 0x0 goto pc+48\n     83: ......678. (bf) r3 = r10\n     84: ...3..678. (07) r3 += -48\n     85: ...3..678. (bf) r1 = r6\n     86: .1.3..678. (b4) w2 = 0\n     87: .123..678. (b4) w4 = 6\n     88: .1234.678. (b4) w5 = 0\n     89: .12345678. (85) call bpf_skb_store_bytes#9\n     90: 0.....678. (bc) w1 = w0\n     91: .1....678. (b4) w0 = -141\n     92: 01....678. (c6) if w1 s< 0x0 goto pc+38\n     93: ......678. (05) goto pc+88\n     94: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     95: .1....678. (b4) w2 = 0\n     96: .12...678. (63) *(u32 *)(r10 -12) = r2\n     97: .12...678. (63) *(u32 *)(r10 -16) = r2\n     98: .12...678. (63) *(u32 *)(r10 -20) = r2\n     99: .1....678. (63) *(u32 *)(r10 -24) = r1\n    100: ......678. (b4) w1 = 64\n    101: .1....678. (63) *(u32 *)(r10 -32) = r1\n    102: ......678. (b4) w1 = 16777216\n    103: .1....678\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 198
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 204 pass bulk_memory failed after 4 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c0fda049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c0fda004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c0fda03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c0fda05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 204
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 215 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c1e6e049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c1e6e004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c1e6e03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c1e6e05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 215
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 217 pass endian_fusion failed after 3 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd275c1e6e004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd275c1e6e03c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd275c1e6e004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+44\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8b6a120c5800\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+7\n     45: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     46: 01....67.. (07) r1 += 1\n     47: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     48: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     49: 01....67.. (0f) r1 += r7\n     50: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     51: ......6... (05) goto pc+11\n     52: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     53: ......6... (b7) r1 = 1\n     54: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     55: ......6... (bf) r2 = r10\n     56: ..2...6... (07) r2 += -24\n     57: ..2...6... (bf) r3 = r10\n     58: ..23..6... (07) r3 += -16\n     59: ..23..6... (18) r1 = 0xffff8b6a120c5800\n     61: .123..6... (b4) w4 = 0\n     62: .1234.6... (85) call bpf_map_update_elem#2\n     63: ......6... (bf) r1 = r6\n     64: .1........ (18) r2 = 0xffff8b6a120c0000\n     66: .12....... (b7) r3 = 1\n     67: .123...... (85) call bpf_tail_call#12\n     68: .......... (b4) w0 = 2\n     69: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd275c1e6e004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd275c1e6e03c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd275c1e6e004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt(r=0)\n20: (0f) r5 += r3\nmark_precis\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 217
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 219 pass bulk_memory failed after 4 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd275c24fa004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd275c24fa03c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd275c24fa004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+44\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8b6a120c5800\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+7\n     45: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     46: 01....67.. (07) r1 += 1\n     47: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     48: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     49: 01....67.. (0f) r1 += r7\n     50: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     51: ......6... (05) goto pc+11\n     52: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     53: ......6... (b7) r1 = 1\n     54: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     55: ......6... (bf) r2 = r10\n     56: ..2...6... (07) r2 += -24\n     57: ..2...6... (bf) r3 = r10\n     58: ..23..6... (07) r3 += -16\n     59: ..23..6... (18) r1 = 0xffff8b6a120c5800\n     61: .123..6... (b4) w4 = 0\n     62: .1234.6... (85) call bpf_map_update_elem#2\n     63: ......6... (bf) r1 = r6\n     64: .1........ (18) r2 = 0xffff8b6a0e6aa800\n     66: .12....... (b7) r3 = 1\n     67: .123...... (85) call bpf_tail_call#12\n     68: .......... (b4) w0 = 2\n     69: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd275c24fa004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd275c24fa03c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd275c24fa004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt(r=0)\n20: (0f) r5 += r3\nmark_precis\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 219
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 222 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd275c24fa049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd275c24fa004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd275c24fa03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd275c24fa05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b69c657aa00\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 222
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 47,
          "not_applied": 14,
          "requested": 61
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
    "per_program_geomean": 0.8535656415389662,
    "program_count": 2,
    "wins": 1
  },
  "workload_seconds": 1.0
}
```
