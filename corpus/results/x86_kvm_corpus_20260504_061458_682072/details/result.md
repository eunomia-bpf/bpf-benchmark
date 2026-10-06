# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-04T06:15:21.666113+00:00",
  "kinsn_modules": {
    "captured_at": "2026-05-04T06:14:58.713329+00:00",
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
      "invoked_at": "2026-05-04T06:14:58.713259+00:00",
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
        "captured_at": "2026-05-04T06:14:58.713250+00:00",
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
      "captured_at": "2026-05-04T06:14:58.699476+00:00",
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
      "app": "katran",
      "baseline_avg_ns_per_run": 33.439797794117645,
      "baseline_run_cnt_delta": 2176,
      "baseline_run_time_ns_delta": 72765,
      "post_rejit_avg_ns_per_run": 32.137867647058826,
      "post_rejit_run_cnt_delta": 2176,
      "post_rejit_run_time_ns_delta": 69932,
      "program": "balancer_ingress",
      "program_id": 16,
      "ratio": 0.9610664467807326,
      "runner": "katran",
      "type": "xdp",
      "workload": "test_run"
    }
  ],
  "results": [
    {
      "app": "katran",
      "baseline": {
        "bpf": {
          "10": {
            "avg_ns_per_run": null,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 10,
            "name": "xdp_root",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "16": {
            "avg_ns_per_run": 33.439797794117645,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 16,
            "name": "balancer_ingress",
            "run_cnt_delta": 2176,
            "run_time_ns_delta": 72765,
            "type": "xdp"
          },
          "18": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 18,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0567156390000036,
            "ops_per_sec": 2059.2105574014245,
            "ops_total": 2176.0,
            "stderr": "{'retval': 2, 'duration_ns': 63, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "10": {
            "avg_ns_per_run": null,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 10,
            "name": "xdp_root",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "16": {
            "avg_ns_per_run": 32.137867647058826,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 16,
            "name": "balancer_ingress",
            "run_cnt_delta": 2176,
            "run_time_ns_delta": 69932,
            "type": "xdp"
          },
          "18": {
            "avg_ns_per_run": null,
            "bytes_jited": 544,
            "bytes_xlated": 1016,
            "id": 18,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0386364739999863,
            "ops_per_sec": 2095.0544819784836,
            "ops_total": 2176.0,
            "stderr": "{'retval': 2, 'duration_ns': 49, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
            "stdout": ""
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
        "error": "prog 16: prog 16 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @2406\nfunc#2 @2554\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 1\n      2: ......67.. (61) r8 = *(u32 *)(r6 +0)\n      3: ......678. (61) r9 = *(u32 *)(r6 +4)\n      4: ......6789 (bf) r1 = r8\n      5: .1....6789 (07) r1 += 14\n      6: .1....6789 (2d) if r1 > r9 goto pc+1581\n      7: ......6789 (b7) r1 = 528\n      8: .1....6789 (63) *(u32 *)(r10 -132) = r1\n      9: ......6789 (bf) r2 = r10\n     10: ..2...6789 (07) r2 += -132\n     11: ..2...6789 (18) r1 = 0xffff896eca714000\n     13: .12...6789 (85) call bpf_map_lookup_elem#1\n     14: 0.....6789 (15) if r0 == 0x0 goto pc+1573\n     15: 0.....6.89 (05) goto pc+0\n     16: 0.....6.89 (05) goto pc+0\n     17: 0.....6.89 (1f) r9 -= r8\n     18: 0.....6.89 (79) r1 = *(u64 *)(r0 +8)\n     19: 01....6.89 (0f) r1 += r9\n     20: 01....6.89 (7b) *(u64 *)(r0 +8) = r1\n     21: 0.....6.89 (79) r1 = *(u64 *)(r0 +0)\n     22: 01....6.89 (07) r1 += 1\n     23: 01....6.89 (7b) *(u64 *)(r0 +0) = r1\n     24: ......6.89 (71) r2 = *(u8 *)(r8 +12)\n     25: ..2...6.89 (71) r1 = *(u8 *)(r8 +13)\n     26: .12...6..9 (67) r1 <<= 8\n     27: .12...6..9 (4f) r1 |= r2\n     28: .1....6..9 (b7) r8 = 1\n     29: .1....6.89 (15) if r1 == 0xdd86 goto pc+129\n     30: .1....6.89 (55) if r1 != 0x8 goto pc+1530\n     31: ......6.89 (61) r2 = *(u32 *)(r6 +4)\n     32: ..2...6.89 (61) r7 = *(u32 *)(r6 +0)\n     33: ..2...6789 (b7) r1 = 0\n     34: .12...6789 (7b) *(u64 *)(r10 -48) = r1\n     35: .12...6789 (7b) *(u64 *)(r10 -56) = r1\n     36: .12...6789 (7b) *(u64 *)(r10 -64) = r1\n     37: .12...6789 (7b) *(u64 *)(r10 -72) = r1\n     38: .12...6789 (7b) *(u64 *)(r10 -80) = r1\n     39: .12...6789 (7b) *(u64 *)(r10 -88) = r1\n     40: .12...6789 (63) *(u32 *)(r10 -96) = r1\n     41: .12...6789 (7b) *(u64 *)(r10 -104) = r1\n     42: .12...6789 (7b) *(u64 *)(r10 -112) = r1\n     43: .12...6789 (63) *(u32 *)(r10 -120) = r1\n     44: ..2...6789 (bf) r3 = r7\n     45: ..23..6789 (07) r3 += 34\n     46: ..23..6789 (7b) *(u64 *)(r10 -144) = r2\n     47: ..23..6789 (2d) if r3 > r2 goto pc+1510\n     48: ...3..6789 (05) goto pc+0\n     49: ...3..6789 (71) r1 = *(u8 *)(r7 +14)\n     50: .1.3..6789 (57) r1 &= 15\n     51: .1.3..6789 (55) if r1 != 0x5 goto pc+1506\n     52: ...3..6789 (05) goto pc+0\n     53: ...3..6789 (71) r1 = *(u8 *)(r7 +15)\n     54: .1.3..6789 (73) *(u8 *)(r10 -43) = r1\n     55: ...3..6789 (71) r1 = *(u8 *)(r7 +23)\n     56: .1.3..6789 (73) *(u8 *)(r10 -52) = r1\n     57: .1.3..6789 (69) r2 = *(u16 *)(r7 +20)\n     58: .123..6789 (bf) r4 = r2\n     59: .1234.6789 (57) r4 &= 65343\n     60: .1234.6789 (55) if r4 != 0x0 goto pc+1497\n     61: .123..6789 (05) goto pc+0\n     62: .123..6789 (69) r0 = *(u16 *)(r7 +16)\n     63: 0123..6789 (15) if r1 == 0x1 goto pc+259\n     64: 01.3..6789 (05) goto pc+0\n     65: 01.3..6789 (61) r2 = *(u32 *)(r7 +26)\n     66: 0123..6789 (63) *(u32 *)(r10 -88) = r2\n     67: 01.3..6789 (61) r2 = *(u32 *)(r7 +30)\n     68: 0123..6789 (63) *(u32 *)(r10 -72) = r2\n     69: 01.3..6789 (b7) r2 = 0\n     70: 0123..6789 (55) if r1 != 0x3a goto pc+640\n     71: 0..3..6789 (bf) r1 = r7\n     72: 01.3..6789 (07) r1 += 42\n     73: 01.3..6789 (79) r2 = *(u64 *)(r10 -144)\n     74: 0123..6789 (2d) if r1 > r2 goto pc+1483\n     75: 0..3..67.9 (05) goto pc+0\n     76: 0..3..67.9 (71) r1 = *(u8 *)(r3 +0)\n     77: 01....67.9 (15) if r1 == 0x1 goto pc+603\n     78: 01....67.9 (15) if r1 == 0x2 goto pc+582\n     79: .1.....7.9 (b7) r8 = 2\n     80: .1.....789 (55) if r1 != 0x80 goto pc+1477\n     81: .......7.9 (b7) r8 = 1\n     82: .......789 (bf) r1 = r7\n     83: .1.....789 (07) r1 += 62\n     84: .1.....789 (79) r2 = *(u64 *)(r10 -144)\n     85: .12....789 (2d) if r1 > r2 goto pc+1472\n     86: .......7.9 (b7) r1 = 129\n     87: .1.....7.9 (73) *(u8 *)(r7 +54) = r1\n     88: .......7.9 (b7) r1 = 64\n     89: .1.....7.9 (73) *(u8 *)(r7 +21) = r1\n     90: .......7.9 (69) r1 = *(u16 *)(r7 +56)\n     91: .1.....7.9 (07) r1 += -1\n     92: .1.....7.9 (6b) *(u16 *)(r7 +56) = r1\n     93: .......7.9 (61) r1 = *(u32 *)(r7 +34)\n     94: .1.....7.9 (67) r1 <<= 32\n     95: .1.....7.9 (61) r2 = *(u32 *)(r7 +30)\n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 16 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @2406\nfunc#2 @2554\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 1\n      2: ......67.. (61) r8 = *(u32 *)(r6 +0)\n      3: ......678. (61) r9 = *(u32 *)(r6 +4)\n      4: ......6789 (bf) r1 = r8\n      5: .1....6789 (07) r1 += 14\n      6: .1....6789 (2d) if r1 > r9 goto pc+1581\n      7: ......6789 (b7) r1 = 528\n      8: .1....6789 (63) *(u32 *)(r10 -132) = r1\n      9: ......6789 (bf) r2 = r10\n     10: ..2...6789 (07) r2 += -132\n     11: ..2...6789 (18) r1 = 0xffff896eca714000\n     13: .12...6789 (85) call bpf_map_lookup_elem#1\n     14: 0.....6789 (15) if r0 == 0x0 goto pc+1573\n     15: 0.....6.89 (05) goto pc+0\n     16: 0.....6.89 (05) goto pc+0\n     17: 0.....6.89 (1f) r9 -= r8\n     18: 0.....6.89 (79) r1 = *(u64 *)(r0 +8)\n     19: 01....6.89 (0f) r1 += r9\n     20: 01....6.89 (7b) *(u64 *)(r0 +8) = r1\n     21: 0.....6.89 (79) r1 = *(u64 *)(r0 +0)\n     22: 01....6.89 (07) r1 += 1\n     23: 01....6.89 (7b) *(u64 *)(r0 +0) = r1\n     24: ......6.89 (71) r2 = *(u8 *)(r8 +12)\n     25: ..2...6.89 (71) r1 = *(u8 *)(r8 +13)\n     26: .12...6..9 (67) r1 <<= 8\n     27: .12...6..9 (4f) r1 |= r2\n     28: .1....6..9 (b7) r8 = 1\n     29: .1....6.89 (15) if r1 == 0xdd86 goto pc+129\n     30: .1....6.89 (55) if r1 != 0x8 goto pc+1530\n     31: ......6.89 (61) r2 = *(u32 *)(r6 +4)\n     32: ..2...6.89 (61) r7 = *(u32 *)(r6 +0)\n     33: ..2...6789 (b7) r1 = 0\n     34: .12...6789 (7b) *(u64 *)(r10 -48) = r1\n     35: .12...6789 (7b) *(u64 *)(r10 -56) = r1\n     36: .12...6789 (7b) *(u64 *)(r10 -64) = r1\n     37: .12...6789 (7b) *(u64 *)(r10 -72) = r1\n     38: .12...6789 (7b) *(u64 *)(r10 -80) = r1\n     39: .12...6789 (7b) *(u64 *)(r10 -88) = r1\n     40: .12...6789 (63) *(u32 *)(r10 -96) = r1\n     41: .12...6789 (7b) *(u64 *)(r10 -104) = r1\n     42: .12...6789 (7b) *(u64 *)(r10 -112) = r1\n     43: .12...6789 (63) *(u32 *)(r10 -120) = r1\n     44: ..2...6789 (bf) r3 = r7\n     45: ..23..6789 (07) r3 += 34\n     46: ..23..6789 (7b) *(u64 *)(r10 -144) = r2\n     47: ..23..6789 (2d) if r3 > r2 goto pc+1510\n     48: ...3..6789 (05) goto pc+0\n     49: ...3..6789 (71) r1 = *(u8 *)(r7 +14)\n     50: .1.3..6789 (57) r1 &= 15\n     51: .1.3..6789 (55) if r1 != 0x5 goto pc+1506\n     52: ...3..6789 (05) goto pc+0\n     53: ...3..6789 (71) r1 = *(u8 *)(r7 +15)\n     54: .1.3..6789 (73) *(u8 *)(r10 -43) = r1\n     55: ...3..6789 (71) r1 = *(u8 *)(r7 +23)\n     56: .1.3..6789 (73) *(u8 *)(r10 -52) = r1\n     57: .1.3..6789 (69) r2 = *(u16 *)(r7 +20)\n     58: .123..6789 (bf) r4 = r2\n     59: .1234.6789 (57) r4 &= 65343\n     60: .1234.6789 (55) if r4 != 0x0 goto pc+1497\n     61: .123..6789 (05) goto pc+0\n     62: .123..6789 (69) r0 = *(u16 *)(r7 +16)\n     63: 0123..6789 (15) if r1 == 0x1 goto pc+259\n     64: 01.3..6789 (05) goto pc+0\n     65: 01.3..6789 (61) r2 = *(u32 *)(r7 +26)\n     66: 0123..6789 (63) *(u32 *)(r10 -88) = r2\n     67: 01.3..6789 (61) r2 = *(u32 *)(r7 +30)\n     68: 0123..6789 (63) *(u32 *)(r10 -72) = r2\n     69: 01.3..6789 (b7) r2 = 0\n     70: 0123..6789 (55) if r1 != 0x3a goto pc+640\n     71: 0..3..6789 (bf) r1 = r7\n     72: 01.3..6789 (07) r1 += 42\n     73: 01.3..6789 (79) r2 = *(u64 *)(r10 -144)\n     74: 0123..6789 (2d) if r1 > r2 goto pc+1483\n     75: 0..3..67.9 (05) goto pc+0\n     76: 0..3..67.9 (71) r1 = *(u8 *)(r3 +0)\n     77: 01....67.9 (15) if r1 == 0x1 goto pc+603\n     78: 01....67.9 (15) if r1 == 0x2 goto pc+582\n     79: .1.....7.9 (b7) r8 = 2\n     80: .1.....789 (55) if r1 != 0x80 goto pc+1477\n     81: .......7.9 (b7) r8 = 1\n     82: .......789 (bf) r1 = r7\n     83: .1.....789 (07) r1 += 62\n     84: .1.....789 (79) r2 = *(u64 *)(r10 -144)\n     85: .12....789 (2d) if r1 > r2 goto pc+1472\n     86: .......7.9 (b7) r1 = 129\n     87: .1.....7.9 (73) *(u8 *)(r7 +54) = r1\n     88: .......7.9 (b7) r1 = 64\n     89: .1.....7.9 (73) *(u8 *)(r7 +21) = r1\n     90: .......7.9 (69) r1 = *(u16 *)(r7 +56)\n     91: .1.....7.9 (07) r1 += -1\n     92: .1.....7.9 (6b) *(u16 *)(r7 +56) = r1\n     93: .......7.9 (61) r1 = *(u32 *)(r7 +34)\n     94: .1.....7.9 (67) r1 <<= 32\n     95: .1.....7.9 (61) r2 = *(u32 *)(r7 +30)\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 16
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 2,
          "not_applied": 1,
          "requested": 3
        }
      },
      "runner": "katran",
      "selected_workload": "test_run",
      "status": "ok"
    }
  ],
  "samples": 1,
  "status": "ok",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 0,
    "per_program_geomean": 0.9610664467807326,
    "program_count": 1,
    "wins": 1
  },
  "workload_seconds": 1.0
}
```
