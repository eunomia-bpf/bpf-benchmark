# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-04T21:19:32.380249+00:00",
  "kinsn_modules": {
    "captured_at": "2026-05-04T21:04:38.427300+00:00",
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
      "invoked_at": "2026-05-04T21:04:38.426290+00:00",
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
        "captured_at": "2026-05-04T21:04:38.426160+00:00",
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
      "captured_at": "2026-05-04T21:04:38.358280+00:00",
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
  "per_program": [],
  "results": [
    {
      "app": "calico/felix",
      "baseline": {
        "bpf": {
          "56": {
            "avg_ns_per_run": null,
            "bytes_jited": 865,
            "bytes_xlated": 1544,
            "id": 56,
            "name": "conntrack_cleanup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "59": {
            "avg_ns_per_run": null,
            "bytes_jited": 19,
            "bytes_xlated": 24,
            "id": 59,
            "name": "cali_tcx_test",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "67": {
            "avg_ns_per_run": null,
            "bytes_jited": 278,
            "bytes_xlated": 344,
            "id": 67,
            "name": "calico_tc_allow",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "68": {
            "avg_ns_per_run": null,
            "bytes_jited": 278,
            "bytes_xlated": 344,
            "id": 68,
            "name": "calico_tc_deny",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "70": {
            "avg_ns_per_run": null,
            "bytes_jited": 278,
            "bytes_xlated": 344,
            "id": 70,
            "name": "calico_tc_allow",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "71": {
            "avg_ns_per_run": null,
            "bytes_jited": 278,
            "bytes_xlated": 344,
            "id": 71,
            "name": "calico_tc_deny",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "78": {
            "avg_ns_per_run": null,
            "bytes_jited": 19,
            "bytes_xlated": 24,
            "id": 78,
            "name": "calico_tc_main",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "79": {
            "avg_ns_per_run": null,
            "bytes_jited": 6972,
            "bytes_xlated": 11168,
            "id": 79,
            "name": "calico_tc_skb_accepted_entrypoint",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "80": {
            "avg_ns_per_run": null,
            "bytes_jited": 8734,
            "bytes_xlated": 14560,
            "id": 80,
            "name": "calico_tc_main",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "81": {
            "avg_ns_per_run": null,
            "bytes_jited": 6906,
            "bytes_xlated": 11288,
            "id": 81,
            "name": "calico_tc_skb_accepted_entrypoint",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "82": {
            "avg_ns_per_run": null,
            "bytes_jited": 9211,
            "bytes_xlated": 15184,
            "id": 82,
            "name": "calico_tc_main",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "83": {
            "avg_ns_per_run": null,
            "bytes_jited": 9237,
            "bytes_xlated": 15200,
            "id": 83,
            "name": "calico_tc_main",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "84": {
            "avg_ns_per_run": null,
            "bytes_jited": 6103,
            "bytes_xlated": 10056,
            "id": 84,
            "name": "calico_tc_skb_accepted_entrypoint",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "85": {
            "avg_ns_per_run": null,
            "bytes_jited": 9597,
            "bytes_xlated": 15784,
            "id": 85,
            "name": "calico_tc_main",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "86": {
            "avg_ns_per_run": null,
            "bytes_jited": 5327,
            "bytes_xlated": 8408,
            "id": 86,
            "name": "calico_tc_skb_accepted_entrypoint",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "87": {
            "avg_ns_per_run": null,
            "bytes_jited": 6906,
            "bytes_xlated": 11288,
            "id": 87,
            "name": "calico_tc_skb_accepted_entrypoint",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "88": {
            "avg_ns_per_run": null,
            "bytes_jited": 10540,
            "bytes_xlated": 16216,
            "id": 88,
            "name": "calico_tc_skb_new_flow_entrypoint",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "89": {
            "avg_ns_per_run": null,
            "bytes_jited": 5125,
            "bytes_xlated": 8624,
            "id": 89,
            "name": "calico_tc_skb_icmp_inner_nat",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "90": {
            "avg_ns_per_run": null,
            "bytes_jited": 1980,
            "bytes_xlated": 3448,
            "id": 90,
            "name": "calico_tc_skb_send_icmp_replies",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "91": {
            "avg_ns_per_run": null,
            "bytes_jited": 1021,
            "bytes_xlated": 1648,
            "id": 91,
            "name": "calico_tc_skb_drop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "92": {
            "avg_ns_per_run": null,
            "bytes_jited": 8413,
            "bytes_xlated": 13336,
            "id": 92,
            "name": "calico_tc_skb_new_flow_entrypoint",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "93": {
            "avg_ns_per_run": null,
            "bytes_jited": 4013,
            "bytes_xlated": 6840,
            "id": 93,
            "name": "calico_tc_skb_icmp_inner_nat",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "94": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3016,
            "id": 94,
            "name": "calico_tc_skb_send_icmp_replies",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "95": {
            "avg_ns_per_run": null,
            "bytes_jited": 8435,
            "bytes_xlated": 13352,
            "id": 95,
            "name": "calico_tc_skb_new_flow_entrypoint",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "96": {
            "avg_ns_per_run": null,
            "bytes_jited": 3365,
            "bytes_xlated": 5736,
            "id": 96,
            "name": "calico_tc_skb_icmp_inner_nat",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "97": {
            "avg_ns_per_run": null,
            "bytes_jited": 1989,
            "bytes_xlated": 3464,
            "id": 97,
            "name": "calico_tc_skb_send_icmp_replies",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "98": {
            "avg_ns_per_run": null,
            "bytes_jited": 1021,
            "bytes_xlated": 1648,
            "id": 98,
            "name": "calico_tc_skb_drop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "99": {
            "avg_ns_per_run": null,
            "bytes_jited": 9467,
            "bytes_xlated": 14704,
            "id": 99,
            "name": "calico_tc_skb_new_flow_entrypoint",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "100": {
            "avg_ns_per_run": null,
            "bytes_jited": 4874,
            "bytes_xlated": 7992,
            "id": 100,
            "name": "calico_tc_skb_icmp_inner_nat",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "101": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3016,
            "id": 101,
            "name": "calico_tc_skb_send_icmp_replies",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "102": {
            "avg_ns_per_run": null,
            "bytes_jited": 5095,
            "bytes_xlated": 8800,
            "id": 102,
            "name": "calico_tc_host_ct_conflict",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "103": {
            "avg_ns_per_run": null,
            "bytes_jited": 1026,
            "bytes_xlated": 1656,
            "id": 103,
            "name": "calico_tc_skb_drop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "106": {
            "avg_ns_per_run": null,
            "bytes_jited": 1696,
            "bytes_xlated": 2616,
            "id": 106,
            "name": "cali_tc_preamble",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "107": {
            "avg_ns_per_run": null,
            "bytes_jited": 1696,
            "bytes_xlated": 2616,
            "id": 107,
            "name": "cali_tc_preamble",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "108": {
            "avg_ns_per_run": null,
            "bytes_jited": 13661,
            "bytes_xlated": 21648,
            "id": 108,
            "name": "calico_tc_main",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "109": {
            "avg_ns_per_run": null,
            "bytes_jited": 4895,
            "bytes_xlated": 8448,
            "id": 109,
            "name": "calico_tc_host_ct_conflict",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "110": {
            "avg_ns_per_run": null,
            "bytes_jited": 1026,
            "bytes_xlated": 1656,
            "id": 110,
            "name": "calico_tc_skb_drop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "113": {
            "avg_ns_per_run": null,
            "bytes_jited": 1696,
            "bytes_xlated": 2616,
            "id": 113,
            "name": "cali_tc_preamble",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "114": {
            "avg_ns_per_run": null,
            "bytes_jited": 1696,
            "bytes_xlated": 2616,
            "id": 114,
            "name": "cali_tc_preamble",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "115": {
            "avg_ns_per_run": null,
            "bytes_jited": 9467,
            "bytes_xlated": 14704,
            "id": 115,
            "name": "calico_tc_skb_new_flow_entrypoint",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "116": {
            "avg_ns_per_run": null,
            "bytes_jited": 4874,
            "bytes_xlated": 7992,
            "id": 116,
            "name": "calico_tc_skb_icmp_inner_nat",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "117": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3016,
            "id": 117,
            "name": "calico_tc_skb_send_icmp_replies",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "118": {
            "avg_ns_per_run": null,
            "bytes_jited": 6972,
            "bytes_xlated": 11168,
            "id": 118,
            "name": "calico_tc_skb_accepted_entrypoint",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "119": {
            "avg_ns_per_run": null,
            "bytes_jited": 5121,
            "bytes_xlated": 8856,
            "id": 119,
            "name": "calico_tc_host_ct_conflict",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 1026,
            "bytes_xlated": 1656,
            "id": 120,
            "name": "calico_tc_skb_drop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "121": {
            "avg_ns_per_run": null,
            "bytes_jited": 10540,
            "bytes_xlated": 16216,
            "id": 121,
            "name": "calico_tc_skb_new_flow_entrypoint",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "122": {
            "avg_ns_per_run": null,
            "bytes_jited": 5125,
            "bytes_xlated": 8624,
            "id": 122,
            "name": "calico_tc_skb_icmp_inner_nat",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "123": {
            "avg_ns_per_run": null,
            "bytes_jited": 1980,
            "bytes_xlated": 3448,
            "id": 123,
            "name": "calico_tc_skb_send_icmp_replies",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "124": {
            "avg_ns_per_run": null,
            "bytes_jited": 1021,
            "bytes_xlated": 1648,
            "id": 124,
            "name": "calico_tc_skb_drop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 16346,
            "bytes_xlated": 25192,
            "id": 125,
            "name": "calico_tc_skb_ipv4_frag",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "128": {
            "avg_ns_per_run": 8955.56356736243,
            "bytes_jited": 1696,
            "bytes_xlated": 2616,
            "id": 128,
            "name": "cali_tc_preamble",
            "run_cnt_delta": 527,
            "run_time_ns_delta": 4719582,
            "type": "sched_cls"
          },
          "129": {
            "avg_ns_per_run": 11177.092696629214,
            "bytes_jited": 1696,
            "bytes_xlated": 2616,
            "id": 129,
            "name": "cali_tc_preamble",
            "run_cnt_delta": 356,
            "run_time_ns_delta": 3979045,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0206023560000403,
            "ops_per_sec": 156.77016524542853,
            "ops_total": 160.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    49.18ms    9.75ms  61.81ms   82.50%\n    Req/Sec    80.30     20.83   101.00    100.00%\n  160 requests in 1.00s, 25.30KB read\nRequests/sec:    159.48\nTransfer/sec:     25.22KB"
          }
        ]
      },
      "error": "network wrk load failed via /usr/bin/wrk -t2 -c10 -d1s http://198.18.0.2:18080/: unable to connect to 198.18.0.2:18080 Connection timed out",
      "post_rejit": null,
      "rejit_result": {
        "applied": true,
        "changed": true,
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
          "bulk_memory",
          "prefetch"
        ],
        "error": "prog 88: prog 88 pass prefetch failed after 11 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r8 = r1\n      1: ........8. (b7) r6 = 0\n      2: ......6.8. (63) *(u32 *)(r10 -96) = r6\n      3: ......6.8. (bf) r2 = r10\n      4: ..2...6.8. (07) r2 += -96\n      5: ..2...6.8. (18) r1 = 0xffff8db8c2564200\n      7: .12...6.8. (85) call bpf_map_lookup_elem#1\n      8: 0.....6.8. (bf) r7 = r0\n      9: ......678. (55) if r7 != 0x0 goto pc+3\n     10: .......... (b7) r1 = 2\n     11: .......... (b7) r0 = 2\n     12: 0......... (95) exit\n     13: ......678. (61) r1 = *(u32 *)(r8 +40)\n     14: .1....678. (63) *(u32 *)(r10 -92) = r6\n     15: .1.....78. (63) *(u32 *)(r10 -96) = r1\n     16: .......78. (bf) r2 = r10\n     17: ..2....78. (07) r2 += -96\n     18: ..2....78. (18) r1 = 0xffff8db8c607ec00\n     20: .12....78. (85) call bpf_map_lookup_elem#1\n     21: 0......78. (bf) r6 = r0\n     22: ......678. (55) if r6 != 0x0 goto pc+3\n     23: .......... (b7) r1 = 2\n     24: .......... (b7) r0 = 2\n     25: 0......... (95) exit\n     26: ......678. (7b) *(u64 *)(r10 -136) = r8\n     27: ......67.. (b7) r1 = 1\n     28: .1....67.. (63) *(u32 *)(r10 -96) = r1\n     29: ......67.. (bf) r2 = r10\n     30: ..2...67.. (07) r2 += -96\n     31: ..2...67.. (18) r1 = 0xffff8db8c2564200\n     33: .12...67.. (85) call bpf_map_lookup_elem#1\n     34: 0.....67.. (bf) r8 = r0\n     35: ......678. (55) if r8 != 0x0 goto pc+3\n     36: .......... (b7) r1 = 2\n     37: .......... (b7) r0 = 2\n     38: 0......... (95) exit\n     39: ......678. (61) r1 = *(u32 *)(r7 +92)\n     40: .1....678. (47) r1 |= 2\n     41: .1....678. (15) if r1 == 0x2 goto pc+1601\n     42: ......678. (7b) *(u64 *)(r10 -144) = r6\n     43: .......78. (69) r5 = *(u16 *)(r7 +88)\n     44: .....5.78. (79) r3 = *(u64 *)(r7 +368)\n     45: ...3.5.78. (b7) r1 = 0\n     46: .1.3.5.78. (7b) *(u64 *)(r8 +328) = r1\n     47: .1.3.5.78. (7b) *(u64 *)(r8 +320) = r1\n     48: .1.3.5.78. (7b) *(u64 *)(r8 +312) = r1\n     49: .1.3.5.78. (7b) *(u64 *)(r8 +304) = r1\n     50: .1.3.5.78. (7b) *(u64 *)(r8 +296) = r1\n     51: .1.3.5.78. (7b) *(u64 *)(r8 +288) = r1\n     52: .1.3.5.78. (71) r2 = *(u8 *)(r7 +104)\n     53: .123.5.78. (73) *(u8 *)(r8 +326) = r2\n     54: .123.5.78. (61) r4 = *(u32 *)(r7 +8)\n     55: .12345.78. (63) *(u32 *)(r8 +292) = r4\n     56: .123.5.78. (69) r4 = *(u16 *)(r7 +96)\n     57: .12345.78. (6b) *(u16 *)(r8 +304) = r4\n     58: .123.5.78. (57) r3 &= 2\n     59: .123.5.78. (b7) r6 = 16777216\n     60: .123.5678. (15) if r3 == 0x0 goto pc+1\n     61: .123.5.78. (b7) r6 = 17825792\n     62: .123.5678. (b7) r4 = 1\n     63: .12345678. (7b) *(u64 *)(r10 -152) = r4\n     64: .123.5678. (15) if r3 == 0x0 goto pc+2\n     65: .12..5678. (b7) r3 = 0\n     66: .123.5678. (7b) *(u64 *)(r10 -152) = r3\n     67: .12..5678. (61) r3 = *(u32 *)(r7 +56)\n     68: .123.5678. (63) *(u32 *)(r8 +300) = r3\n     69: .12..5678. (69) r3 = *(u16 *)(r7 +102)\n     70: .123.5678. (6b) *(u16 *)(r8 +306) = r3\n     71: .12..5678. (61) r3 = *(u32 *)(r7 +72)\n     72: .123.5678. (63) *(u32 *)(r8 +320) = r3\n     73: .12..5678. (73) *(u8 *)(r8 +332) = r1\n     74: .12..5678. (63) *(u32 *)(r8 +328) = r1\n     75: .12..5678. (79) r3 = *(u64 *)(r7 +368)\n     76: .123.5678. (bf) r4 = r3\n     77: .12345678. (57) r4 &= 1\n     78: .12345678. (15) if r4 == 0x0 goto pc+2\n     79: ..23.5678. (b7) r1 = 1\n     80: .123.5678. (6b) *(u16 *)(r8 +324) = r1\n     81: .123.5678. (bf) r4 = r3\n     82: .12345678. (57) r4 &= 8192\n     83: .12345678. (79) r9 = *(u64 *)(r10 -136)\n     84: .123456789 (15) if r4 == 0x0 goto pc+2\n     85: ..23.56789 (b7) r1 = -32767\n     86: .123.56789 (6b) *(u16 *)(r8 +324) = r1\n     87: .123.56789 (bf) r4 = r3\n     88: .123456789 (57) r4 &= 2\n     89: .123456789 (15) if r4 == 0x0 goto pc+2\n     90: .123.56789 (47) r1 |= 8\n     91: .123.56789 (6b) *(u16 *)(r8 +324) = r1\n     92: .123.56789 (bf) r4 = r3\n     93: .123456789 (57) r4 &= 2048\n     94: .123456789 (15) if r4 == 0x0 goto pc+2\n     95: ..23.56789 (b7) r1 = -16375\n     96: .123.56789 (6b) *(u16 *)(r8 +324) = r1\n     97: .123.56789 (57) r3 &= 64\n     98: .123.56789 (15) if r3 == 0x0 goto pc+2\n     99: .12..56789 (47) r1 |= 512\n    100:\n... verifier log truncated ...; prog 95: prog 95 pass const_prop failed after 6 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r8 = r1\n      1: ........8. (b7) r6 = 0\n      2: ......6.8. (63) *(u32 *)(r10 -96) = r6\n      3: ......6.8. (bf) r2 = r10\n      4: ..2...6.8. (07) r2 += -96\n      5: ..2...6.8. (18) r1 = 0xffff8db8c2564200\n      7: .12...6.8. (85) call bpf_map_lookup_elem#1\n      8: 0.....6.8. (bf) r7 = r0\n      9: ......678. (55) if r7 != 0x0 goto pc+3\n     10: .......... (b7) r1 = 2\n     11: .......... (b7) r0 = 2\n     12: 0......... (95) exit\n     13: ......678. (7b) *(u64 *)(r10 -112) = r8\n     14: ......678. (61) r1 = *(u32 *)(r8 +40)\n     15: .1....67.. (63) *(u32 *)(r10 -92) = r6\n     16: .1.....7.. (63) *(u32 *)(r10 -96) = r1\n     17: .......7.. (bf) r2 = r10\n     18: ..2....7.. (07) r2 += -96\n     19: ..2....7.. (18) r1 = 0xffff8db8c607ec00\n     21: .12....7.. (85) call bpf_map_lookup_elem#1\n     22: 0......7.. (7b) *(u64 *)(r10 -120) = r0\n     23: 0......7.. (55) if r0 != 0x0 goto pc+3\n     24: .......... (b7) r1 = 2\n     25: .......... (b7) r0 = 2\n     26: 0......... (95) exit\n     27: .......7.. (b7) r1 = 1\n     28: .1.....7.. (63) *(u32 *)(r10 -96) = r1\n     29: .......7.. (bf) r2 = r10\n     30: ..2....7.. (07) r2 += -96\n     31: ..2....7.. (18) r1 = 0xffff8db8c2564200\n     33: .12....7.. (85) call bpf_map_lookup_elem#1\n     34: 0......7.. (bf) r8 = r0\n     35: .......78. (55) if r8 != 0x0 goto pc+3\n     36: .......... (b7) r1 = 2\n     37: .......... (b7) r0 = 2\n     38: 0......... (95) exit\n     39: .......78. (b7) r9 = 2\n     40: .......789 (61) r1 = *(u32 *)(r7 +92)\n     41: .1.....789 (47) r1 |= 2\n     42: .1.....789 (15) if r1 == 0x2 goto pc+1534\n     43: .......789 (79) r1 = *(u64 *)(r7 +368)\n     44: .1.....789 (57) r1 &= 2\n     45: .1.....789 (b7) r2 = 16777216\n     46: .12....789 (15) if r1 == 0x0 goto pc+1\n     47: .......789 (b7) r2 = 17825792\n     48: ..2....789 (7b) *(u64 *)(r10 -144) = r2\n     49: .......789 (69) r1 = *(u16 *)(r7 +88)\n     50: .1.....789 (7b) *(u64 *)(r10 -128) = r1\n     51: .......789 (b7) r2 = 0\n     52: ..2....789 (7b) *(u64 *)(r8 +328) = r2\n     53: ..2....789 (7b) *(u64 *)(r8 +320) = r2\n     54: ..2....789 (7b) *(u64 *)(r8 +312) = r2\n     55: ..2....789 (7b) *(u64 *)(r8 +304) = r2\n     56: ..2....789 (7b) *(u64 *)(r8 +296) = r2\n     57: ..2....789 (7b) *(u64 *)(r8 +288) = r2\n     58: ..2....789 (71) r1 = *(u8 *)(r7 +104)\n     59: .12....789 (73) *(u8 *)(r8 +326) = r1\n     60: .12....789 (61) r3 = *(u32 *)(r7 +8)\n     61: .123...789 (63) *(u32 *)(r8 +292) = r3\n     62: .12....789 (69) r3 = *(u16 *)(r7 +96)\n     63: .123...789 (6b) *(u16 *)(r8 +304) = r3\n     64: .12....789 (61) r3 = *(u32 *)(r7 +56)\n     65: .123...789 (63) *(u32 *)(r8 +300) = r3\n     66: .12....789 (69) r3 = *(u16 *)(r7 +102)\n     67: .123...789 (6b) *(u16 *)(r8 +306) = r3\n     68: .12....789 (61) r3 = *(u32 *)(r7 +72)\n     69: .123...789 (73) *(u8 *)(r8 +332) = r2\n     70: .123...789 (63) *(u32 *)(r8 +328) = r2\n     71: .1.3...789 (63) *(u32 *)(r8 +320) = r3\n     72: .1.....789 (79) r2 = *(u64 *)(r7 +368)\n     73: .12....789 (b7) r3 = 128\n     74: .123...789 (bf) r4 = r2\n     75: .1234..789 (57) r4 &= 64\n     76: .1234..789 (15) if r4 == 0x0 goto pc+1\n     77: .12....789 (b7) r3 = 640\n     78: .123...789 (bf) r4 = r8\n     79: .1234..789 (07) r4 += 264\n     80: .1234..789 (7b) *(u64 *)(r10 -136) = r4\n     81: .123...789 (bf) r4 = r2\n     82: .1234..789 (57) r4 &= 1\n     83: .1234..789 (bf) r5 = r2\n     84: .12345.789 (67) r5 <<= 2\n     85: .12345.789 (bf) r0 = r5\n     86: 012345.789 (57) r0 &= 32768\n     87: 012345.789 (4f) r4 |= r0\n     88: .12345.789 (57) r5 &= 8\n     89: .12345.789 (4f) r4 |= r5\n     90: .1234..789 (67) r2 <<= 3\n     91: .1234..789 (57) r2 &= 16384\n     92: .1234..789 (4f) r4 |= r2\n     93: .1.34..789 (4f) r4 |= r3\n     94: .1..4..789 (6b) *(u16 *)(r8 +324) = r4\n     95: .1.....789 (55) if r1 != 0x6 goto pc+24\n     96: .......789 (79) r6 = *(u64 *)(r10 -112)\n     97: ......6789 (61) r1 = *(u32 *)(r6 +76)\n     98: .1....6789 (61) r2 = *(u32 *)(r6 +80)\n     99: .12...6789 (07) r1 += 54\n    100: .12...6789 (3d) if r2 >= r1 goto pc+17\n    101: ......\n... verifier log truncated ...; prog 99: prog 99 pass const_prop failed after 6 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r1 = 0\n      2: .1....6... (63) *(u32 *)(r10 -96) = r1\n      3: ......6... (bf) r2 = r10\n      4: ..2...6... (07) r2 += -96\n      5: ..2...6... (18) r1 = 0xffff8db8c2564200\n      7: .12...6... (85) call bpf_map_lookup_elem#1\n      8: 0.....6... (bf) r7 = r0\n      9: ......67.. (55) if r7 != 0x0 goto pc+3\n     10: .......... (b7) r1 = 2\n     11: .......... (b7) r0 = 2\n     12: 0......... (95) exit\n     13: ......67.. (7b) *(u64 *)(r10 -128) = r6\n     14: ......67.. (61) r1 = *(u32 *)(r6 +40)\n     15: .1.....7.. (b7) r6 = 1\n     16: .1....67.. (63) *(u32 *)(r10 -92) = r6\n     17: .1....67.. (63) *(u32 *)(r10 -96) = r1\n     18: ......67.. (bf) r2 = r10\n     19: ..2...67.. (07) r2 += -96\n     20: ..2...67.. (18) r1 = 0xffff8db8c607ec00\n     22: .12...67.. (85) call bpf_map_lookup_elem#1\n     23: 0.....67.. (7b) *(u64 *)(r10 -136) = r0\n     24: 0.....67.. (55) if r0 != 0x0 goto pc+3\n     25: .......... (b7) r1 = 2\n     26: .......... (b7) r0 = 2\n     27: 0......... (95) exit\n     28: ......67.. (63) *(u32 *)(r10 -96) = r6\n     29: .......7.. (bf) r2 = r10\n     30: ..2....7.. (07) r2 += -96\n     31: ..2....7.. (18) r1 = 0xffff8db8c2564200\n     33: .12....7.. (85) call bpf_map_lookup_elem#1\n     34: 0......7.. (bf) r8 = r0\n     35: .......78. (55) if r8 != 0x0 goto pc+3\n     36: .......... (b7) r1 = 2\n     37: .......... (b7) r0 = 2\n     38: 0......... (95) exit\n     39: .......78. (61) r1 = *(u32 *)(r7 +92)\n     40: .1.....78. (47) r1 |= 2\n     41: .1.....78. (15) if r1 == 0x2 goto pc+1580\n     42: .......78. (69) r1 = *(u16 *)(r7 +88)\n     43: .1.....78. (7b) *(u64 *)(r10 -152) = r1\n     44: .......78. (79) r9 = *(u64 *)(r7 +368)\n     45: .......789 (b7) r1 = 0\n     46: .1.....789 (7b) *(u64 *)(r8 +328) = r1\n     47: .1.....789 (7b) *(u64 *)(r8 +320) = r1\n     48: .1.....789 (7b) *(u64 *)(r8 +312) = r1\n     49: .1.....789 (7b) *(u64 *)(r8 +304) = r1\n     50: .1.....789 (7b) *(u64 *)(r8 +296) = r1\n     51: .1.....789 (7b) *(u64 *)(r8 +288) = r1\n     52: .1.....789 (71) r2 = *(u8 *)(r7 +104)\n     53: .12....789 (73) *(u8 *)(r8 +326) = r2\n     54: .12....789 (61) r3 = *(u32 *)(r7 +8)\n     55: .123...789 (63) *(u32 *)(r8 +292) = r3\n     56: .12....789 (69) r3 = *(u16 *)(r7 +96)\n     57: .123...789 (6b) *(u16 *)(r8 +304) = r3\n     58: .12....789 (61) r3 = *(u32 *)(r7 +56)\n     59: .123...789 (63) *(u32 *)(r8 +300) = r3\n     60: .12....789 (69) r3 = *(u16 *)(r7 +102)\n     61: .123...789 (6b) *(u16 *)(r8 +306) = r3\n     62: .12....789 (61) r3 = *(u32 *)(r7 +72)\n     63: .123...789 (63) *(u32 *)(r8 +320) = r3\n     64: .12....789 (73) *(u8 *)(r8 +332) = r1\n     65: .12....789 (63) *(u32 *)(r8 +328) = r1\n     66: .12....789 (79) r3 = *(u64 *)(r7 +368)\n     67: .123...789 (bf) r4 = r3\n     68: .1234..789 (57) r4 &= 1\n     69: .1234..789 (15) if r4 == 0x0 goto pc+2\n     70: ..23...789 (b7) r1 = 1\n     71: .123...789 (6b) *(u16 *)(r8 +324) = r1\n     72: .123...789 (bf) r4 = r3\n     73: .1234..789 (57) r4 &= 8192\n     74: .1234..789 (15) if r4 == 0x0 goto pc+2\n     75: ..23...789 (b7) r1 = -32767\n     76: .123...789 (6b) *(u16 *)(r8 +324) = r1\n     77: .123...789 (bf) r4 = r3\n     78: .1234..789 (57) r4 &= 2048\n     79: .1234..789 (79) r6 = *(u64 *)(r10 -128)\n     80: .1234.6789 (15) if r4 == 0x0 goto pc+2\n     81: .123..6789 (47) r1 |= 16384\n     82: .123..6789 (6b) *(u16 *)(r8 +324) = r1\n     83: .123..6789 (bf) r4 = r3\n     84: .1234.6789 (57) r4 &= 128\n     85: .1234.6789 (15) if r4 == 0x0 goto pc+2\n     86: ..23..6789 (b7) r1 = -14335\n     87: .123..6789 (6b) *(u16 *)(r8 +324) = r1\n     88: .123..6789 (bf) r4 = r3\n     89: .1234.6789 (57) r4 &= 256\n     90: .1234.6789 (15) if r4 == 0x0 goto pc+2\n     91: .123..6789 (47) r1 |= 4096\n     92: .123..6789 (6b) *(u16 *)(r8 +324) = r1\n     93: .123..6789 (57) r3 &= 64\n     94: .123..6789 (15) if r3 == 0x0 goto pc+2\n     95: ..2...6789 (b7) r1 = -9727\n     96: .12...6789 (6b) *(u16 *)(r8 +324) = r1\n     97: .12...6789 (61) r3 = *(u32 *)(r6 +8)\n     98: .123..6789 (18) r4 = 0x81000000\n    100: .1234.6789\n... verifier log truncated ...; prog 115: prog 115 pass const_prop failed after 6 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r1 = 0\n      2: .1....6... (63) *(u32 *)(r10 -96) = r1\n      3: ......6... (bf) r2 = r10\n      4: ..2...6... (07) r2 += -96\n      5: ..2...6... (18) r1 = 0xffff8db8c2564200\n      7: .12...6... (85) call bpf_map_lookup_elem#1\n      8: 0.....6... (bf) r7 = r0\n      9: ......67.. (55) if r7 != 0x0 goto pc+3\n     10: .......... (b7) r1 = 2\n     11: .......... (b7) r0 = 2\n     12: 0......... (95) exit\n     13: ......67.. (7b) *(u64 *)(r10 -128) = r6\n     14: ......67.. (61) r1 = *(u32 *)(r6 +40)\n     15: .1.....7.. (b7) r6 = 1\n     16: .1....67.. (63) *(u32 *)(r10 -92) = r6\n     17: .1....67.. (63) *(u32 *)(r10 -96) = r1\n     18: ......67.. (bf) r2 = r10\n     19: ..2...67.. (07) r2 += -96\n     20: ..2...67.. (18) r1 = 0xffff8db8c607ec00\n     22: .12...67.. (85) call bpf_map_lookup_elem#1\n     23: 0.....67.. (7b) *(u64 *)(r10 -136) = r0\n     24: 0.....67.. (55) if r0 != 0x0 goto pc+3\n     25: .......... (b7) r1 = 2\n     26: .......... (b7) r0 = 2\n     27: 0......... (95) exit\n     28: ......67.. (63) *(u32 *)(r10 -96) = r6\n     29: .......7.. (bf) r2 = r10\n     30: ..2....7.. (07) r2 += -96\n     31: ..2....7.. (18) r1 = 0xffff8db8c2564200\n     33: .12....7.. (85) call bpf_map_lookup_elem#1\n     34: 0......7.. (bf) r8 = r0\n     35: .......78. (55) if r8 != 0x0 goto pc+3\n     36: .......... (b7) r1 = 2\n     37: .......... (b7) r0 = 2\n     38: 0......... (95) exit\n     39: .......78. (61) r1 = *(u32 *)(r7 +92)\n     40: .1.....78. (47) r1 |= 2\n     41: .1.....78. (15) if r1 == 0x2 goto pc+1580\n     42: .......78. (69) r1 = *(u16 *)(r7 +88)\n     43: .1.....78. (7b) *(u64 *)(r10 -152) = r1\n     44: .......78. (79) r9 = *(u64 *)(r7 +368)\n     45: .......789 (b7) r1 = 0\n     46: .1.....789 (7b) *(u64 *)(r8 +328) = r1\n     47: .1.....789 (7b) *(u64 *)(r8 +320) = r1\n     48: .1.....789 (7b) *(u64 *)(r8 +312) = r1\n     49: .1.....789 (7b) *(u64 *)(r8 +304) = r1\n     50: .1.....789 (7b) *(u64 *)(r8 +296) = r1\n     51: .1.....789 (7b) *(u64 *)(r8 +288) = r1\n     52: .1.....789 (71) r2 = *(u8 *)(r7 +104)\n     53: .12....789 (73) *(u8 *)(r8 +326) = r2\n     54: .12....789 (61) r3 = *(u32 *)(r7 +8)\n     55: .123...789 (63) *(u32 *)(r8 +292) = r3\n     56: .12....789 (69) r3 = *(u16 *)(r7 +96)\n     57: .123...789 (6b) *(u16 *)(r8 +304) = r3\n     58: .12....789 (61) r3 = *(u32 *)(r7 +56)\n     59: .123...789 (63) *(u32 *)(r8 +300) = r3\n     60: .12....789 (69) r3 = *(u16 *)(r7 +102)\n     61: .123...789 (6b) *(u16 *)(r8 +306) = r3\n     62: .12....789 (61) r3 = *(u32 *)(r7 +72)\n     63: .123...789 (63) *(u32 *)(r8 +320) = r3\n     64: .12....789 (73) *(u8 *)(r8 +332) = r1\n     65: .12....789 (63) *(u32 *)(r8 +328) = r1\n     66: .12....789 (79) r3 = *(u64 *)(r7 +368)\n     67: .123...789 (bf) r4 = r3\n     68: .1234..789 (57) r4 &= 1\n     69: .1234..789 (15) if r4 == 0x0 goto pc+2\n     70: ..23...789 (b7) r1 = 1\n     71: .123...789 (6b) *(u16 *)(r8 +324) = r1\n     72: .123...789 (bf) r4 = r3\n     73: .1234..789 (57) r4 &= 8192\n     74: .1234..789 (15) if r4 == 0x0 goto pc+2\n     75: ..23...789 (b7) r1 = -32767\n     76: .123...789 (6b) *(u16 *)(r8 +324) = r1\n     77: .123...789 (bf) r4 = r3\n     78: .1234..789 (57) r4 &= 2048\n     79: .1234..789 (79) r6 = *(u64 *)(r10 -128)\n     80: .1234.6789 (15) if r4 == 0x0 goto pc+2\n     81: .123..6789 (47) r1 |= 16384\n     82: .123..6789 (6b) *(u16 *)(r8 +324) = r1\n     83: .123..6789 (bf) r4 = r3\n     84: .1234.6789 (57) r4 &= 128\n     85: .1234.6789 (15) if r4 == 0x0 goto pc+2\n     86: ..23..6789 (b7) r1 = -14335\n     87: .123..6789 (6b) *(u16 *)(r8 +324) = r1\n     88: .123..6789 (bf) r4 = r3\n     89: .1234.6789 (57) r4 &= 256\n     90: .1234.6789 (15) if r4 == 0x0 goto pc+2\n     91: .123..6789 (47) r1 |= 4096\n     92: .123..6789 (6b) *(u16 *)(r8 +324) = r1\n     93: .123..6789 (57) r3 &= 64\n     94: .123..6789 (15) if r3 == 0x0 goto pc+2\n     95: ..2...6789 (b7) r1 = -9727\n     96: .12...6789 (6b) *(u16 *)(r8 +324) = r1\n     97: .12...6789 (61) r3 = *(u32 *)(r6 +8)\n     98: .123..6789 (18) r4 = 0x81000000\n    100: .1234.6789\n... verifier log truncated ...; prog 121: prog 121 pass prefetch failed after 11 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r8 = r1\n      1: ........8. (b7) r6 = 0\n      2: ......6.8. (63) *(u32 *)(r10 -96) = r6\n      3: ......6.8. (bf) r2 = r10\n      4: ..2...6.8. (07) r2 += -96\n      5: ..2...6.8. (18) r1 = 0xffff8db8c2564200\n      7: .12...6.8. (85) call bpf_map_lookup_elem#1\n      8: 0.....6.8. (bf) r7 = r0\n      9: ......678. (55) if r7 != 0x0 goto pc+3\n     10: .......... (b7) r1 = 2\n     11: .......... (b7) r0 = 2\n     12: 0......... (95) exit\n     13: ......678. (61) r1 = *(u32 *)(r8 +40)\n     14: .1....678. (63) *(u32 *)(r10 -92) = r6\n     15: .1.....78. (63) *(u32 *)(r10 -96) = r1\n     16: .......78. (bf) r2 = r10\n     17: ..2....78. (07) r2 += -96\n     18: ..2....78. (18) r1 = 0xffff8db8c607ec00\n     20: .12....78. (85) call bpf_map_lookup_elem#1\n     21: 0......78. (bf) r6 = r0\n     22: ......678. (55) if r6 != 0x0 goto pc+3\n     23: .......... (b7) r1 = 2\n     24: .......... (b7) r0 = 2\n     25: 0......... (95) exit\n     26: ......678. (7b) *(u64 *)(r10 -136) = r8\n     27: ......67.. (b7) r1 = 1\n     28: .1....67.. (63) *(u32 *)(r10 -96) = r1\n     29: ......67.. (bf) r2 = r10\n     30: ..2...67.. (07) r2 += -96\n     31: ..2...67.. (18) r1 = 0xffff8db8c2564200\n     33: .12...67.. (85) call bpf_map_lookup_elem#1\n     34: 0.....67.. (bf) r8 = r0\n     35: ......678. (55) if r8 != 0x0 goto pc+3\n     36: .......... (b7) r1 = 2\n     37: .......... (b7) r0 = 2\n     38: 0......... (95) exit\n     39: ......678. (61) r1 = *(u32 *)(r7 +92)\n     40: .1....678. (47) r1 |= 2\n     41: .1....678. (15) if r1 == 0x2 goto pc+1601\n     42: ......678. (7b) *(u64 *)(r10 -144) = r6\n     43: .......78. (69) r5 = *(u16 *)(r7 +88)\n     44: .....5.78. (79) r3 = *(u64 *)(r7 +368)\n     45: ...3.5.78. (b7) r1 = 0\n     46: .1.3.5.78. (7b) *(u64 *)(r8 +328) = r1\n     47: .1.3.5.78. (7b) *(u64 *)(r8 +320) = r1\n     48: .1.3.5.78. (7b) *(u64 *)(r8 +312) = r1\n     49: .1.3.5.78. (7b) *(u64 *)(r8 +304) = r1\n     50: .1.3.5.78. (7b) *(u64 *)(r8 +296) = r1\n     51: .1.3.5.78. (7b) *(u64 *)(r8 +288) = r1\n     52: .1.3.5.78. (71) r2 = *(u8 *)(r7 +104)\n     53: .123.5.78. (73) *(u8 *)(r8 +326) = r2\n     54: .123.5.78. (61) r4 = *(u32 *)(r7 +8)\n     55: .12345.78. (63) *(u32 *)(r8 +292) = r4\n     56: .123.5.78. (69) r4 = *(u16 *)(r7 +96)\n     57: .12345.78. (6b) *(u16 *)(r8 +304) = r4\n     58: .123.5.78. (57) r3 &= 2\n     59: .123.5.78. (b7) r6 = 16777216\n     60: .123.5678. (15) if r3 == 0x0 goto pc+1\n     61: .123.5.78. (b7) r6 = 17825792\n     62: .123.5678. (b7) r4 = 1\n     63: .12345678. (7b) *(u64 *)(r10 -152) = r4\n     64: .123.5678. (15) if r3 == 0x0 goto pc+2\n     65: .12..5678. (b7) r3 = 0\n     66: .123.5678. (7b) *(u64 *)(r10 -152) = r3\n     67: .12..5678. (61) r3 = *(u32 *)(r7 +56)\n     68: .123.5678. (63) *(u32 *)(r8 +300) = r3\n     69: .12..5678. (69) r3 = *(u16 *)(r7 +102)\n     70: .123.5678. (6b) *(u16 *)(r8 +306) = r3\n     71: .12..5678. (61) r3 = *(u32 *)(r7 +72)\n     72: .123.5678. (63) *(u32 *)(r8 +320) = r3\n     73: .12..5678. (73) *(u8 *)(r8 +332) = r1\n     74: .12..5678. (63) *(u32 *)(r8 +328) = r1\n     75: .12..5678. (79) r3 = *(u64 *)(r7 +368)\n     76: .123.5678. (bf) r4 = r3\n     77: .12345678. (57) r4 &= 1\n     78: .12345678. (15) if r4 == 0x0 goto pc+2\n     79: ..23.5678. (b7) r1 = 1\n     80: .123.5678. (6b) *(u16 *)(r8 +324) = r1\n     81: .123.5678. (bf) r4 = r3\n     82: .12345678. (57) r4 &= 8192\n     83: .12345678. (79) r9 = *(u64 *)(r10 -136)\n     84: .123456789 (15) if r4 == 0x0 goto pc+2\n     85: ..23.56789 (b7) r1 = -32767\n     86: .123.56789 (6b) *(u16 *)(r8 +324) = r1\n     87: .123.56789 (bf) r4 = r3\n     88: .123456789 (57) r4 &= 2\n     89: .123456789 (15) if r4 == 0x0 goto pc+2\n     90: .123.56789 (47) r1 |= 8\n     91: .123.56789 (6b) *(u16 *)(r8 +324) = r1\n     92: .123.56789 (bf) r4 = r3\n     93: .123456789 (57) r4 &= 2048\n     94: .123456789 (15) if r4 == 0x0 goto pc+2\n     95: ..23.56789 (b7) r1 = -16375\n     96: .123.56789 (6b) *(u16 *)(r8 +324) = r1\n     97: .123.56789 (57) r3 &= 64\n     98: .123.56789 (15) if r3 == 0x0 goto pc+2\n     99: .12..56789 (47) r1 |= 512\n    100:\n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 88 pass prefetch failed after 11 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r8 = r1\n      1: ........8. (b7) r6 = 0\n      2: ......6.8. (63) *(u32 *)(r10 -96) = r6\n      3: ......6.8. (bf) r2 = r10\n      4: ..2...6.8. (07) r2 += -96\n      5: ..2...6.8. (18) r1 = 0xffff8db8c2564200\n      7: .12...6.8. (85) call bpf_map_lookup_elem#1\n      8: 0.....6.8. (bf) r7 = r0\n      9: ......678. (55) if r7 != 0x0 goto pc+3\n     10: .......... (b7) r1 = 2\n     11: .......... (b7) r0 = 2\n     12: 0......... (95) exit\n     13: ......678. (61) r1 = *(u32 *)(r8 +40)\n     14: .1....678. (63) *(u32 *)(r10 -92) = r6\n     15: .1.....78. (63) *(u32 *)(r10 -96) = r1\n     16: .......78. (bf) r2 = r10\n     17: ..2....78. (07) r2 += -96\n     18: ..2....78. (18) r1 = 0xffff8db8c607ec00\n     20: .12....78. (85) call bpf_map_lookup_elem#1\n     21: 0......78. (bf) r6 = r0\n     22: ......678. (55) if r6 != 0x0 goto pc+3\n     23: .......... (b7) r1 = 2\n     24: .......... (b7) r0 = 2\n     25: 0......... (95) exit\n     26: ......678. (7b) *(u64 *)(r10 -136) = r8\n     27: ......67.. (b7) r1 = 1\n     28: .1....67.. (63) *(u32 *)(r10 -96) = r1\n     29: ......67.. (bf) r2 = r10\n     30: ..2...67.. (07) r2 += -96\n     31: ..2...67.. (18) r1 = 0xffff8db8c2564200\n     33: .12...67.. (85) call bpf_map_lookup_elem#1\n     34: 0.....67.. (bf) r8 = r0\n     35: ......678. (55) if r8 != 0x0 goto pc+3\n     36: .......... (b7) r1 = 2\n     37: .......... (b7) r0 = 2\n     38: 0......... (95) exit\n     39: ......678. (61) r1 = *(u32 *)(r7 +92)\n     40: .1....678. (47) r1 |= 2\n     41: .1....678. (15) if r1 == 0x2 goto pc+1601\n     42: ......678. (7b) *(u64 *)(r10 -144) = r6\n     43: .......78. (69) r5 = *(u16 *)(r7 +88)\n     44: .....5.78. (79) r3 = *(u64 *)(r7 +368)\n     45: ...3.5.78. (b7) r1 = 0\n     46: .1.3.5.78. (7b) *(u64 *)(r8 +328) = r1\n     47: .1.3.5.78. (7b) *(u64 *)(r8 +320) = r1\n     48: .1.3.5.78. (7b) *(u64 *)(r8 +312) = r1\n     49: .1.3.5.78. (7b) *(u64 *)(r8 +304) = r1\n     50: .1.3.5.78. (7b) *(u64 *)(r8 +296) = r1\n     51: .1.3.5.78. (7b) *(u64 *)(r8 +288) = r1\n     52: .1.3.5.78. (71) r2 = *(u8 *)(r7 +104)\n     53: .123.5.78. (73) *(u8 *)(r8 +326) = r2\n     54: .123.5.78. (61) r4 = *(u32 *)(r7 +8)\n     55: .12345.78. (63) *(u32 *)(r8 +292) = r4\n     56: .123.5.78. (69) r4 = *(u16 *)(r7 +96)\n     57: .12345.78. (6b) *(u16 *)(r8 +304) = r4\n     58: .123.5.78. (57) r3 &= 2\n     59: .123.5.78. (b7) r6 = 16777216\n     60: .123.5678. (15) if r3 == 0x0 goto pc+1\n     61: .123.5.78. (b7) r6 = 17825792\n     62: .123.5678. (b7) r4 = 1\n     63: .12345678. (7b) *(u64 *)(r10 -152) = r4\n     64: .123.5678. (15) if r3 == 0x0 goto pc+2\n     65: .12..5678. (b7) r3 = 0\n     66: .123.5678. (7b) *(u64 *)(r10 -152) = r3\n     67: .12..5678. (61) r3 = *(u32 *)(r7 +56)\n     68: .123.5678. (63) *(u32 *)(r8 +300) = r3\n     69: .12..5678. (69) r3 = *(u16 *)(r7 +102)\n     70: .123.5678. (6b) *(u16 *)(r8 +306) = r3\n     71: .12..5678. (61) r3 = *(u32 *)(r7 +72)\n     72: .123.5678. (63) *(u32 *)(r8 +320) = r3\n     73: .12..5678. (73) *(u8 *)(r8 +332) = r1\n     74: .12..5678. (63) *(u32 *)(r8 +328) = r1\n     75: .12..5678. (79) r3 = *(u64 *)(r7 +368)\n     76: .123.5678. (bf) r4 = r3\n     77: .12345678. (57) r4 &= 1\n     78: .12345678. (15) if r4 == 0x0 goto pc+2\n     79: ..23.5678. (b7) r1 = 1\n     80: .123.5678. (6b) *(u16 *)(r8 +324) = r1\n     81: .123.5678. (bf) r4 = r3\n     82: .12345678. (57) r4 &= 8192\n     83: .12345678. (79) r9 = *(u64 *)(r10 -136)\n     84: .123456789 (15) if r4 == 0x0 goto pc+2\n     85: ..23.56789 (b7) r1 = -32767\n     86: .123.56789 (6b) *(u16 *)(r8 +324) = r1\n     87: .123.56789 (bf) r4 = r3\n     88: .123456789 (57) r4 &= 2\n     89: .123456789 (15) if r4 == 0x0 goto pc+2\n     90: .123.56789 (47) r1 |= 8\n     91: .123.56789 (6b) *(u16 *)(r8 +324) = r1\n     92: .123.56789 (bf) r4 = r3\n     93: .123456789 (57) r4 &= 2048\n     94: .123456789 (15) if r4 == 0x0 goto pc+2\n     95: ..23.56789 (b7) r1 = -16375\n     96: .123.56789 (6b) *(u16 *)(r8 +324) = r1\n     97: .123.56789 (57) r3 &= 64\n     98: .123.56789 (15) if r3 == 0x0 goto pc+2\n     99: .12..56789 (47) r1 |= 512\n    100:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 88
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 95 pass const_prop failed after 6 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r8 = r1\n      1: ........8. (b7) r6 = 0\n      2: ......6.8. (63) *(u32 *)(r10 -96) = r6\n      3: ......6.8. (bf) r2 = r10\n      4: ..2...6.8. (07) r2 += -96\n      5: ..2...6.8. (18) r1 = 0xffff8db8c2564200\n      7: .12...6.8. (85) call bpf_map_lookup_elem#1\n      8: 0.....6.8. (bf) r7 = r0\n      9: ......678. (55) if r7 != 0x0 goto pc+3\n     10: .......... (b7) r1 = 2\n     11: .......... (b7) r0 = 2\n     12: 0......... (95) exit\n     13: ......678. (7b) *(u64 *)(r10 -112) = r8\n     14: ......678. (61) r1 = *(u32 *)(r8 +40)\n     15: .1....67.. (63) *(u32 *)(r10 -92) = r6\n     16: .1.....7.. (63) *(u32 *)(r10 -96) = r1\n     17: .......7.. (bf) r2 = r10\n     18: ..2....7.. (07) r2 += -96\n     19: ..2....7.. (18) r1 = 0xffff8db8c607ec00\n     21: .12....7.. (85) call bpf_map_lookup_elem#1\n     22: 0......7.. (7b) *(u64 *)(r10 -120) = r0\n     23: 0......7.. (55) if r0 != 0x0 goto pc+3\n     24: .......... (b7) r1 = 2\n     25: .......... (b7) r0 = 2\n     26: 0......... (95) exit\n     27: .......7.. (b7) r1 = 1\n     28: .1.....7.. (63) *(u32 *)(r10 -96) = r1\n     29: .......7.. (bf) r2 = r10\n     30: ..2....7.. (07) r2 += -96\n     31: ..2....7.. (18) r1 = 0xffff8db8c2564200\n     33: .12....7.. (85) call bpf_map_lookup_elem#1\n     34: 0......7.. (bf) r8 = r0\n     35: .......78. (55) if r8 != 0x0 goto pc+3\n     36: .......... (b7) r1 = 2\n     37: .......... (b7) r0 = 2\n     38: 0......... (95) exit\n     39: .......78. (b7) r9 = 2\n     40: .......789 (61) r1 = *(u32 *)(r7 +92)\n     41: .1.....789 (47) r1 |= 2\n     42: .1.....789 (15) if r1 == 0x2 goto pc+1534\n     43: .......789 (79) r1 = *(u64 *)(r7 +368)\n     44: .1.....789 (57) r1 &= 2\n     45: .1.....789 (b7) r2 = 16777216\n     46: .12....789 (15) if r1 == 0x0 goto pc+1\n     47: .......789 (b7) r2 = 17825792\n     48: ..2....789 (7b) *(u64 *)(r10 -144) = r2\n     49: .......789 (69) r1 = *(u16 *)(r7 +88)\n     50: .1.....789 (7b) *(u64 *)(r10 -128) = r1\n     51: .......789 (b7) r2 = 0\n     52: ..2....789 (7b) *(u64 *)(r8 +328) = r2\n     53: ..2....789 (7b) *(u64 *)(r8 +320) = r2\n     54: ..2....789 (7b) *(u64 *)(r8 +312) = r2\n     55: ..2....789 (7b) *(u64 *)(r8 +304) = r2\n     56: ..2....789 (7b) *(u64 *)(r8 +296) = r2\n     57: ..2....789 (7b) *(u64 *)(r8 +288) = r2\n     58: ..2....789 (71) r1 = *(u8 *)(r7 +104)\n     59: .12....789 (73) *(u8 *)(r8 +326) = r1\n     60: .12....789 (61) r3 = *(u32 *)(r7 +8)\n     61: .123...789 (63) *(u32 *)(r8 +292) = r3\n     62: .12....789 (69) r3 = *(u16 *)(r7 +96)\n     63: .123...789 (6b) *(u16 *)(r8 +304) = r3\n     64: .12....789 (61) r3 = *(u32 *)(r7 +56)\n     65: .123...789 (63) *(u32 *)(r8 +300) = r3\n     66: .12....789 (69) r3 = *(u16 *)(r7 +102)\n     67: .123...789 (6b) *(u16 *)(r8 +306) = r3\n     68: .12....789 (61) r3 = *(u32 *)(r7 +72)\n     69: .123...789 (73) *(u8 *)(r8 +332) = r2\n     70: .123...789 (63) *(u32 *)(r8 +328) = r2\n     71: .1.3...789 (63) *(u32 *)(r8 +320) = r3\n     72: .1.....789 (79) r2 = *(u64 *)(r7 +368)\n     73: .12....789 (b7) r3 = 128\n     74: .123...789 (bf) r4 = r2\n     75: .1234..789 (57) r4 &= 64\n     76: .1234..789 (15) if r4 == 0x0 goto pc+1\n     77: .12....789 (b7) r3 = 640\n     78: .123...789 (bf) r4 = r8\n     79: .1234..789 (07) r4 += 264\n     80: .1234..789 (7b) *(u64 *)(r10 -136) = r4\n     81: .123...789 (bf) r4 = r2\n     82: .1234..789 (57) r4 &= 1\n     83: .1234..789 (bf) r5 = r2\n     84: .12345.789 (67) r5 <<= 2\n     85: .12345.789 (bf) r0 = r5\n     86: 012345.789 (57) r0 &= 32768\n     87: 012345.789 (4f) r4 |= r0\n     88: .12345.789 (57) r5 &= 8\n     89: .12345.789 (4f) r4 |= r5\n     90: .1234..789 (67) r2 <<= 3\n     91: .1234..789 (57) r2 &= 16384\n     92: .1234..789 (4f) r4 |= r2\n     93: .1.34..789 (4f) r4 |= r3\n     94: .1..4..789 (6b) *(u16 *)(r8 +324) = r4\n     95: .1.....789 (55) if r1 != 0x6 goto pc+24\n     96: .......789 (79) r6 = *(u64 *)(r10 -112)\n     97: ......6789 (61) r1 = *(u32 *)(r6 +76)\n     98: .1....6789 (61) r2 = *(u32 *)(r6 +80)\n     99: .12...6789 (07) r1 += 54\n    100: .12...6789 (3d) if r2 >= r1 goto pc+17\n    101: ......\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 95
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 99 pass const_prop failed after 6 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r1 = 0\n      2: .1....6... (63) *(u32 *)(r10 -96) = r1\n      3: ......6... (bf) r2 = r10\n      4: ..2...6... (07) r2 += -96\n      5: ..2...6... (18) r1 = 0xffff8db8c2564200\n      7: .12...6... (85) call bpf_map_lookup_elem#1\n      8: 0.....6... (bf) r7 = r0\n      9: ......67.. (55) if r7 != 0x0 goto pc+3\n     10: .......... (b7) r1 = 2\n     11: .......... (b7) r0 = 2\n     12: 0......... (95) exit\n     13: ......67.. (7b) *(u64 *)(r10 -128) = r6\n     14: ......67.. (61) r1 = *(u32 *)(r6 +40)\n     15: .1.....7.. (b7) r6 = 1\n     16: .1....67.. (63) *(u32 *)(r10 -92) = r6\n     17: .1....67.. (63) *(u32 *)(r10 -96) = r1\n     18: ......67.. (bf) r2 = r10\n     19: ..2...67.. (07) r2 += -96\n     20: ..2...67.. (18) r1 = 0xffff8db8c607ec00\n     22: .12...67.. (85) call bpf_map_lookup_elem#1\n     23: 0.....67.. (7b) *(u64 *)(r10 -136) = r0\n     24: 0.....67.. (55) if r0 != 0x0 goto pc+3\n     25: .......... (b7) r1 = 2\n     26: .......... (b7) r0 = 2\n     27: 0......... (95) exit\n     28: ......67.. (63) *(u32 *)(r10 -96) = r6\n     29: .......7.. (bf) r2 = r10\n     30: ..2....7.. (07) r2 += -96\n     31: ..2....7.. (18) r1 = 0xffff8db8c2564200\n     33: .12....7.. (85) call bpf_map_lookup_elem#1\n     34: 0......7.. (bf) r8 = r0\n     35: .......78. (55) if r8 != 0x0 goto pc+3\n     36: .......... (b7) r1 = 2\n     37: .......... (b7) r0 = 2\n     38: 0......... (95) exit\n     39: .......78. (61) r1 = *(u32 *)(r7 +92)\n     40: .1.....78. (47) r1 |= 2\n     41: .1.....78. (15) if r1 == 0x2 goto pc+1580\n     42: .......78. (69) r1 = *(u16 *)(r7 +88)\n     43: .1.....78. (7b) *(u64 *)(r10 -152) = r1\n     44: .......78. (79) r9 = *(u64 *)(r7 +368)\n     45: .......789 (b7) r1 = 0\n     46: .1.....789 (7b) *(u64 *)(r8 +328) = r1\n     47: .1.....789 (7b) *(u64 *)(r8 +320) = r1\n     48: .1.....789 (7b) *(u64 *)(r8 +312) = r1\n     49: .1.....789 (7b) *(u64 *)(r8 +304) = r1\n     50: .1.....789 (7b) *(u64 *)(r8 +296) = r1\n     51: .1.....789 (7b) *(u64 *)(r8 +288) = r1\n     52: .1.....789 (71) r2 = *(u8 *)(r7 +104)\n     53: .12....789 (73) *(u8 *)(r8 +326) = r2\n     54: .12....789 (61) r3 = *(u32 *)(r7 +8)\n     55: .123...789 (63) *(u32 *)(r8 +292) = r3\n     56: .12....789 (69) r3 = *(u16 *)(r7 +96)\n     57: .123...789 (6b) *(u16 *)(r8 +304) = r3\n     58: .12....789 (61) r3 = *(u32 *)(r7 +56)\n     59: .123...789 (63) *(u32 *)(r8 +300) = r3\n     60: .12....789 (69) r3 = *(u16 *)(r7 +102)\n     61: .123...789 (6b) *(u16 *)(r8 +306) = r3\n     62: .12....789 (61) r3 = *(u32 *)(r7 +72)\n     63: .123...789 (63) *(u32 *)(r8 +320) = r3\n     64: .12....789 (73) *(u8 *)(r8 +332) = r1\n     65: .12....789 (63) *(u32 *)(r8 +328) = r1\n     66: .12....789 (79) r3 = *(u64 *)(r7 +368)\n     67: .123...789 (bf) r4 = r3\n     68: .1234..789 (57) r4 &= 1\n     69: .1234..789 (15) if r4 == 0x0 goto pc+2\n     70: ..23...789 (b7) r1 = 1\n     71: .123...789 (6b) *(u16 *)(r8 +324) = r1\n     72: .123...789 (bf) r4 = r3\n     73: .1234..789 (57) r4 &= 8192\n     74: .1234..789 (15) if r4 == 0x0 goto pc+2\n     75: ..23...789 (b7) r1 = -32767\n     76: .123...789 (6b) *(u16 *)(r8 +324) = r1\n     77: .123...789 (bf) r4 = r3\n     78: .1234..789 (57) r4 &= 2048\n     79: .1234..789 (79) r6 = *(u64 *)(r10 -128)\n     80: .1234.6789 (15) if r4 == 0x0 goto pc+2\n     81: .123..6789 (47) r1 |= 16384\n     82: .123..6789 (6b) *(u16 *)(r8 +324) = r1\n     83: .123..6789 (bf) r4 = r3\n     84: .1234.6789 (57) r4 &= 128\n     85: .1234.6789 (15) if r4 == 0x0 goto pc+2\n     86: ..23..6789 (b7) r1 = -14335\n     87: .123..6789 (6b) *(u16 *)(r8 +324) = r1\n     88: .123..6789 (bf) r4 = r3\n     89: .1234.6789 (57) r4 &= 256\n     90: .1234.6789 (15) if r4 == 0x0 goto pc+2\n     91: .123..6789 (47) r1 |= 4096\n     92: .123..6789 (6b) *(u16 *)(r8 +324) = r1\n     93: .123..6789 (57) r3 &= 64\n     94: .123..6789 (15) if r3 == 0x0 goto pc+2\n     95: ..2...6789 (b7) r1 = -9727\n     96: .12...6789 (6b) *(u16 *)(r8 +324) = r1\n     97: .12...6789 (61) r3 = *(u32 *)(r6 +8)\n     98: .123..6789 (18) r4 = 0x81000000\n    100: .1234.6789\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 99
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 115 pass const_prop failed after 6 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r1 = 0\n      2: .1....6... (63) *(u32 *)(r10 -96) = r1\n      3: ......6... (bf) r2 = r10\n      4: ..2...6... (07) r2 += -96\n      5: ..2...6... (18) r1 = 0xffff8db8c2564200\n      7: .12...6... (85) call bpf_map_lookup_elem#1\n      8: 0.....6... (bf) r7 = r0\n      9: ......67.. (55) if r7 != 0x0 goto pc+3\n     10: .......... (b7) r1 = 2\n     11: .......... (b7) r0 = 2\n     12: 0......... (95) exit\n     13: ......67.. (7b) *(u64 *)(r10 -128) = r6\n     14: ......67.. (61) r1 = *(u32 *)(r6 +40)\n     15: .1.....7.. (b7) r6 = 1\n     16: .1....67.. (63) *(u32 *)(r10 -92) = r6\n     17: .1....67.. (63) *(u32 *)(r10 -96) = r1\n     18: ......67.. (bf) r2 = r10\n     19: ..2...67.. (07) r2 += -96\n     20: ..2...67.. (18) r1 = 0xffff8db8c607ec00\n     22: .12...67.. (85) call bpf_map_lookup_elem#1\n     23: 0.....67.. (7b) *(u64 *)(r10 -136) = r0\n     24: 0.....67.. (55) if r0 != 0x0 goto pc+3\n     25: .......... (b7) r1 = 2\n     26: .......... (b7) r0 = 2\n     27: 0......... (95) exit\n     28: ......67.. (63) *(u32 *)(r10 -96) = r6\n     29: .......7.. (bf) r2 = r10\n     30: ..2....7.. (07) r2 += -96\n     31: ..2....7.. (18) r1 = 0xffff8db8c2564200\n     33: .12....7.. (85) call bpf_map_lookup_elem#1\n     34: 0......7.. (bf) r8 = r0\n     35: .......78. (55) if r8 != 0x0 goto pc+3\n     36: .......... (b7) r1 = 2\n     37: .......... (b7) r0 = 2\n     38: 0......... (95) exit\n     39: .......78. (61) r1 = *(u32 *)(r7 +92)\n     40: .1.....78. (47) r1 |= 2\n     41: .1.....78. (15) if r1 == 0x2 goto pc+1580\n     42: .......78. (69) r1 = *(u16 *)(r7 +88)\n     43: .1.....78. (7b) *(u64 *)(r10 -152) = r1\n     44: .......78. (79) r9 = *(u64 *)(r7 +368)\n     45: .......789 (b7) r1 = 0\n     46: .1.....789 (7b) *(u64 *)(r8 +328) = r1\n     47: .1.....789 (7b) *(u64 *)(r8 +320) = r1\n     48: .1.....789 (7b) *(u64 *)(r8 +312) = r1\n     49: .1.....789 (7b) *(u64 *)(r8 +304) = r1\n     50: .1.....789 (7b) *(u64 *)(r8 +296) = r1\n     51: .1.....789 (7b) *(u64 *)(r8 +288) = r1\n     52: .1.....789 (71) r2 = *(u8 *)(r7 +104)\n     53: .12....789 (73) *(u8 *)(r8 +326) = r2\n     54: .12....789 (61) r3 = *(u32 *)(r7 +8)\n     55: .123...789 (63) *(u32 *)(r8 +292) = r3\n     56: .12....789 (69) r3 = *(u16 *)(r7 +96)\n     57: .123...789 (6b) *(u16 *)(r8 +304) = r3\n     58: .12....789 (61) r3 = *(u32 *)(r7 +56)\n     59: .123...789 (63) *(u32 *)(r8 +300) = r3\n     60: .12....789 (69) r3 = *(u16 *)(r7 +102)\n     61: .123...789 (6b) *(u16 *)(r8 +306) = r3\n     62: .12....789 (61) r3 = *(u32 *)(r7 +72)\n     63: .123...789 (63) *(u32 *)(r8 +320) = r3\n     64: .12....789 (73) *(u8 *)(r8 +332) = r1\n     65: .12....789 (63) *(u32 *)(r8 +328) = r1\n     66: .12....789 (79) r3 = *(u64 *)(r7 +368)\n     67: .123...789 (bf) r4 = r3\n     68: .1234..789 (57) r4 &= 1\n     69: .1234..789 (15) if r4 == 0x0 goto pc+2\n     70: ..23...789 (b7) r1 = 1\n     71: .123...789 (6b) *(u16 *)(r8 +324) = r1\n     72: .123...789 (bf) r4 = r3\n     73: .1234..789 (57) r4 &= 8192\n     74: .1234..789 (15) if r4 == 0x0 goto pc+2\n     75: ..23...789 (b7) r1 = -32767\n     76: .123...789 (6b) *(u16 *)(r8 +324) = r1\n     77: .123...789 (bf) r4 = r3\n     78: .1234..789 (57) r4 &= 2048\n     79: .1234..789 (79) r6 = *(u64 *)(r10 -128)\n     80: .1234.6789 (15) if r4 == 0x0 goto pc+2\n     81: .123..6789 (47) r1 |= 16384\n     82: .123..6789 (6b) *(u16 *)(r8 +324) = r1\n     83: .123..6789 (bf) r4 = r3\n     84: .1234.6789 (57) r4 &= 128\n     85: .1234.6789 (15) if r4 == 0x0 goto pc+2\n     86: ..23..6789 (b7) r1 = -14335\n     87: .123..6789 (6b) *(u16 *)(r8 +324) = r1\n     88: .123..6789 (bf) r4 = r3\n     89: .1234.6789 (57) r4 &= 256\n     90: .1234.6789 (15) if r4 == 0x0 goto pc+2\n     91: .123..6789 (47) r1 |= 4096\n     92: .123..6789 (6b) *(u16 *)(r8 +324) = r1\n     93: .123..6789 (57) r3 &= 64\n     94: .123..6789 (15) if r3 == 0x0 goto pc+2\n     95: ..2...6789 (b7) r1 = -9727\n     96: .12...6789 (6b) *(u16 *)(r8 +324) = r1\n     97: .12...6789 (61) r3 = *(u32 *)(r6 +8)\n     98: .123..6789 (18) r4 = 0x81000000\n    100: .1234.6789\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 115
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 121 pass prefetch failed after 11 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r8 = r1\n      1: ........8. (b7) r6 = 0\n      2: ......6.8. (63) *(u32 *)(r10 -96) = r6\n      3: ......6.8. (bf) r2 = r10\n      4: ..2...6.8. (07) r2 += -96\n      5: ..2...6.8. (18) r1 = 0xffff8db8c2564200\n      7: .12...6.8. (85) call bpf_map_lookup_elem#1\n      8: 0.....6.8. (bf) r7 = r0\n      9: ......678. (55) if r7 != 0x0 goto pc+3\n     10: .......... (b7) r1 = 2\n     11: .......... (b7) r0 = 2\n     12: 0......... (95) exit\n     13: ......678. (61) r1 = *(u32 *)(r8 +40)\n     14: .1....678. (63) *(u32 *)(r10 -92) = r6\n     15: .1.....78. (63) *(u32 *)(r10 -96) = r1\n     16: .......78. (bf) r2 = r10\n     17: ..2....78. (07) r2 += -96\n     18: ..2....78. (18) r1 = 0xffff8db8c607ec00\n     20: .12....78. (85) call bpf_map_lookup_elem#1\n     21: 0......78. (bf) r6 = r0\n     22: ......678. (55) if r6 != 0x0 goto pc+3\n     23: .......... (b7) r1 = 2\n     24: .......... (b7) r0 = 2\n     25: 0......... (95) exit\n     26: ......678. (7b) *(u64 *)(r10 -136) = r8\n     27: ......67.. (b7) r1 = 1\n     28: .1....67.. (63) *(u32 *)(r10 -96) = r1\n     29: ......67.. (bf) r2 = r10\n     30: ..2...67.. (07) r2 += -96\n     31: ..2...67.. (18) r1 = 0xffff8db8c2564200\n     33: .12...67.. (85) call bpf_map_lookup_elem#1\n     34: 0.....67.. (bf) r8 = r0\n     35: ......678. (55) if r8 != 0x0 goto pc+3\n     36: .......... (b7) r1 = 2\n     37: .......... (b7) r0 = 2\n     38: 0......... (95) exit\n     39: ......678. (61) r1 = *(u32 *)(r7 +92)\n     40: .1....678. (47) r1 |= 2\n     41: .1....678. (15) if r1 == 0x2 goto pc+1601\n     42: ......678. (7b) *(u64 *)(r10 -144) = r6\n     43: .......78. (69) r5 = *(u16 *)(r7 +88)\n     44: .....5.78. (79) r3 = *(u64 *)(r7 +368)\n     45: ...3.5.78. (b7) r1 = 0\n     46: .1.3.5.78. (7b) *(u64 *)(r8 +328) = r1\n     47: .1.3.5.78. (7b) *(u64 *)(r8 +320) = r1\n     48: .1.3.5.78. (7b) *(u64 *)(r8 +312) = r1\n     49: .1.3.5.78. (7b) *(u64 *)(r8 +304) = r1\n     50: .1.3.5.78. (7b) *(u64 *)(r8 +296) = r1\n     51: .1.3.5.78. (7b) *(u64 *)(r8 +288) = r1\n     52: .1.3.5.78. (71) r2 = *(u8 *)(r7 +104)\n     53: .123.5.78. (73) *(u8 *)(r8 +326) = r2\n     54: .123.5.78. (61) r4 = *(u32 *)(r7 +8)\n     55: .12345.78. (63) *(u32 *)(r8 +292) = r4\n     56: .123.5.78. (69) r4 = *(u16 *)(r7 +96)\n     57: .12345.78. (6b) *(u16 *)(r8 +304) = r4\n     58: .123.5.78. (57) r3 &= 2\n     59: .123.5.78. (b7) r6 = 16777216\n     60: .123.5678. (15) if r3 == 0x0 goto pc+1\n     61: .123.5.78. (b7) r6 = 17825792\n     62: .123.5678. (b7) r4 = 1\n     63: .12345678. (7b) *(u64 *)(r10 -152) = r4\n     64: .123.5678. (15) if r3 == 0x0 goto pc+2\n     65: .12..5678. (b7) r3 = 0\n     66: .123.5678. (7b) *(u64 *)(r10 -152) = r3\n     67: .12..5678. (61) r3 = *(u32 *)(r7 +56)\n     68: .123.5678. (63) *(u32 *)(r8 +300) = r3\n     69: .12..5678. (69) r3 = *(u16 *)(r7 +102)\n     70: .123.5678. (6b) *(u16 *)(r8 +306) = r3\n     71: .12..5678. (61) r3 = *(u32 *)(r7 +72)\n     72: .123.5678. (63) *(u32 *)(r8 +320) = r3\n     73: .12..5678. (73) *(u8 *)(r8 +332) = r1\n     74: .12..5678. (63) *(u32 *)(r8 +328) = r1\n     75: .12..5678. (79) r3 = *(u64 *)(r7 +368)\n     76: .123.5678. (bf) r4 = r3\n     77: .12345678. (57) r4 &= 1\n     78: .12345678. (15) if r4 == 0x0 goto pc+2\n     79: ..23.5678. (b7) r1 = 1\n     80: .123.5678. (6b) *(u16 *)(r8 +324) = r1\n     81: .123.5678. (bf) r4 = r3\n     82: .12345678. (57) r4 &= 8192\n     83: .12345678. (79) r9 = *(u64 *)(r10 -136)\n     84: .123456789 (15) if r4 == 0x0 goto pc+2\n     85: ..23.56789 (b7) r1 = -32767\n     86: .123.56789 (6b) *(u16 *)(r8 +324) = r1\n     87: .123.56789 (bf) r4 = r3\n     88: .123456789 (57) r4 &= 2\n     89: .123456789 (15) if r4 == 0x0 goto pc+2\n     90: .123.56789 (47) r1 |= 8\n     91: .123.56789 (6b) *(u16 *)(r8 +324) = r1\n     92: .123.56789 (bf) r4 = r3\n     93: .123456789 (57) r4 &= 2048\n     94: .123456789 (15) if r4 == 0x0 goto pc+2\n     95: ..23.56789 (b7) r1 = -16375\n     96: .123.56789 (6b) *(u16 *)(r8 +324) = r1\n     97: .123.56789 (57) r3 &= 64\n     98: .123.56789 (15) if r3 == 0x0 goto pc+2\n     99: .12..56789 (47) r1 |= 512\n    100:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 121
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 47,
          "not_applied": 5,
          "requested": 52
        }
      },
      "runner": "calico",
      "selected_workload": "network",
      "status": "error"
    }
  ],
  "samples": 1,
  "status": "error",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 0,
    "per_program_geomean": null,
    "program_count": 0,
    "wins": 0
  },
  "workload_seconds": 1.0
}
```
