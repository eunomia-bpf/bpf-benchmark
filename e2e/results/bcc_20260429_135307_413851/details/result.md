# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-29T13:57:04.499069+00:00`
- Duration per phase: `10s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Tools dir: `/usr/sbin`
- Setup rc: `0`
- Error: `opensnoop post_rejit failed: prog 3180: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3180_1777470945_001718071_1156: bpfverify --verifier-states-out failed for prog 3180: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess "bpfverify" "--prog-type" "tracing" "--map-fds" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/map_fds.json" "--input" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/prog.bin" "--output" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/verified_original.bin" "--report" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/original_bpfverify_report.json" "--verifier-states-out" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/verifier_states.json" "--prog-btf-id" "3619" "--attach-btf-id" "64477" "--attach-btf-obj-id" "1": func#0 @0
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3181: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3181_1777470945_123683506_1158: bpfverify --verifier-states-out failed for prog 3181: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess "bpfverify" "--prog-type" "tracing" "--map-fds" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/map_fds.json" "--input" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/prog.bin" "--output" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/verified_original.bin" "--report" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/original_bpfverify_report.json" "--verifier-states-out" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/verifier_states.json" "--prog-btf-id" "3619" "--attach-btf-id" "64481" "--attach-btf-obj-id" "1": func#0 @0
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3182: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3182_1777470945_246731122_1160: bpfverify --verifier-states-out failed for prog 3182: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess "bpfverify" "--prog-type" "tracing" "--map-fds" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/map_fds.json" "--input" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/prog.bin" "--output" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/verified_original.bin" "--report" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/original_bpfverify_report.json" "--verifier-states-out" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/verifier_states.json" "--prog-btf-id" "3619" "--attach-btf-id" "64482" "--attach-btf-obj-id" "1": func#0 @0
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; capable post_rejit failed: prog 3191: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3191_1777470972_954833225_1162: bpfverify final verification failed for prog 3191: bpfverify final verification rejected bytecode (returncode 0, verifier status fail, errno 22): verifier log summary:
kernel btf_id 129873 is not a function
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; vfsstat post_rejit failed: prog 3199: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3199_1777470995_129845292_1164: bpfverify --verifier-states-out failed for prog 3199: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess "bpfverify" "--prog-type" "tracing" "--map-fds" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/map_fds.json" "--input" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/prog.bin" "--output" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/verified_original.bin" "--report" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/original_bpfverify_report.json" "--verifier-states-out" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/verifier_states.json" "--prog-btf-id" "3621" "--attach-btf-id" "123739" "--attach-btf-obj-id" "1": func#0 @0
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3200: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3200_1777470995_251844154_1166: bpfverify --verifier-states-out failed for prog 3200: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess "bpfverify" "--prog-type" "tracing" "--map-fds" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/map_fds.json" "--input" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/prog.bin" "--output" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/verified_original.bin" "--report" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/original_bpfverify_report.json" "--verifier-states-out" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/verifier_states.json" "--prog-btf-id" "3621" "--attach-btf-id" "123755" "--attach-btf-obj-id" "1": func#0 @0
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3201: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3201_1777470995_375960463_1168: bpfverify --verifier-states-out failed for prog 3201: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess "bpfverify" "--prog-type" "tracing" "--map-fds" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/map_fds.json" "--input" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/prog.bin" "--output" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/verified_original.bin" "--report" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/original_bpfverify_report.json" "--verifier-states-out" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/verifier_states.json" "--prog-btf-id" "3621" "--attach-btf-id" "123778" "--attach-btf-obj-id" "1": func#0 @0
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3202: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3202_1777470995_498458533_1170: bpfverify --verifier-states-out failed for prog 3202: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess "bpfverify" "--prog-type" "tracing" "--map-fds" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/map_fds.json" "--input" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/prog.bin" "--output" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/verified_original.bin" "--report" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/original_bpfverify_report.json" "--verifier-states-out" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/verifier_states.json" "--prog-btf-id" "3621" "--attach-btf-id" "123788" "--attach-btf-obj-id" "1": func#0 @0
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3203: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3203_1777470995_620972474_1172: bpfverify --verifier-states-out failed for prog 3203: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess "bpfverify" "--prog-type" "tracing" "--map-fds" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/map_fds.json" "--input" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/prog.bin" "--output" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/verified_original.bin" "--report" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/original_bpfverify_report.json" "--verifier-states-out" "/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/verifier_states.json" "--prog-btf-id" "3621" "--attach-btf-id" "123808" "--attach-btf-obj-id" "1": func#0 @0
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; bindsnoop post_rejit failed: prog 3231: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3231_1777471023_308014315_1178: bpfverify final verification failed for prog 3231: bpfverify final verification rejected bytecode (returncode 0, verifier status fail, errno 22): verifier log summary:
kernel btf_id 129873 is not a function
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3232: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3232_1777471023_440428218_1180: bpfverify final verification failed for prog 3232: bpfverify final verification rejected bytecode (returncode 0, verifier status fail, errno 22): verifier log summary:
kernel btf_id 129873 is not a function
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0`

## tcplife

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3117": {
        "avg_ns_per_run": 1091.1,
        "bytes_jited": 1067,
        "bytes_xlated": 1672,
        "id": 3117,
        "name": "tracepoint__sock__inet_sock_set_state",
        "run_cnt_delta": 20,
        "run_time_ns_delta": 21822,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 8243.751524103462
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
      "3117": {
        "avg_ns_per_run": 23.87743823146944,
        "bytes_jited": 989,
        "bytes_xlated": 1568,
        "id": 3117,
        "name": "sock__inet_sock",
        "run_cnt_delta": 3076,
        "run_time_ns_delta": 73447,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 18853.038315005855
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
    "bulk_memory"
  ],
  "error": "",
  "exit_code": 0,
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
  "stderr_tail": "In file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bcc-python-6k_kzlze/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bcc-python-6k_kzlze/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/tcp.h:7:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "PID   COMM       LADDR           LPORT RADDR           RPORT TX_KB RX_KB MS\n20924 stress-ng- 127.0.0.1       34158 127.0.0.1       22083     0 406547 44.57\n20924 stress-ng- 127.0.0.1       22083 127.0.0.1       34158 406547     0 44.59\n20955 stress-ng- 127.0.0.1       34162 127.0.0.1       22083     0 407357 60.65\n20955 stress-ng- 127.0.0.1       22083 127.0.0.1       34162 407357     0 60.66"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3126": {
        "avg_ns_per_run": 284.52323897080373,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 3126,
        "name": "trace_pid_start_tp",
        "run_cnt_delta": 119433,
        "run_time_ns_delta": 33981464,
        "type": "tracepoint"
      },
      "3127": {
        "avg_ns_per_run": 277.73943656076017,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 3127,
        "name": "trace_req_start",
        "run_cnt_delta": 119445,
        "run_time_ns_delta": 33174587,
        "type": "kprobe"
      },
      "3128": {
        "avg_ns_per_run": 458.55680571950006,
        "bytes_jited": 550,
        "bytes_xlated": 856,
        "id": 3128,
        "name": "trace_req_completion_tp",
        "run_cnt_delta": 119451,
        "run_time_ns_delta": 54775069,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 12492.754977661285
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
      "3126": {
        "avg_ns_per_run": 305.00577733015933,
        "bytes_jited": 267,
        "bytes_xlated": 448,
        "id": 3126,
        "name": "trace_pid_start_tp",
        "run_cnt_delta": 109220,
        "run_time_ns_delta": 33312731,
        "type": "tracepoint"
      },
      "3127": {
        "avg_ns_per_run": 295.8717110683878,
        "bytes_jited": 335,
        "bytes_xlated": 616,
        "id": 3127,
        "name": "trace_req_start",
        "run_cnt_delta": 109230,
        "run_time_ns_delta": 32318067,
        "type": "kprobe"
      },
      "3128": {
        "avg_ns_per_run": 154.46280462127177,
        "bytes_jited": 548,
        "bytes_xlated": 848,
        "id": 3128,
        "name": "trace_req_compl",
        "run_cnt_delta": 109234,
        "run_time_ns_delta": 16872590,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 10527.833460762617
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
    "bulk_memory"
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
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3126
    },
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3127
    }
  ],
  "program_counts": {
    "applied": 1,
    "not_applied": 2,
    "requested": 3
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "In file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bcc-python-3y8g7zv4/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:4:\nIn file included from include/linux/blk-mq.h:5:\nIn file included from include/linux/blkdev.h:7:\nIn file included from include/linux/blk_types.h:7:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "2.096042    fio            20998   loop0     R 120670432  4096      0.43\n2.096792    fio            20995   loop0     R 115657888  4096      0.80\n2.096855    fio            20998   loop0     R 120643392  4096      0.81\n2.097295    fio            20995   loop0     R 115657896  4096      0.50\n2.097357    fio            20998   loop0     R 120643400  4096      0.50\n2.098215    fio            20995   loop0     R 115658184  4096      0.91\n2.098277    fio            20998   loop0     R 120643408  4096      0.92\n2.099065    fio            20995   loop0     R 115658224  4096      0.84\n2.099166    fio            20998   loop0     R 120643488  4096      0.88\n2.099670    fio            20995   loop0     R 115658232  4096      0.60\n2.099733    fio            20998   loop0     R 120646176  4096      0.56\n2.100236    fio            20995   loop0     R 115658352  4096      0.56\n2.100299    fio            20998   loop0     R 120646320  4096      0.56\n2.100926    fio            20995   loop0     R 115658376  4096      0.68\n2.100989    fio            20998   loop0     R 120646336  4096      0.69\n2.101429    fio            20998   loop0     R 120670488  4096      0.43\n2.101930    fio            20998   loop0     R 120670496  4096      0.49\n2.102306    fio            20998   loop0     R 120646424  4096      0.37\n2.102746    fio            20998   loop0     R 120646448  4096      0.44\n2.103249    fio            20998   loop0     R 120646592  4096      0.50\n2.103875    fio            20998   loop0     R 120646600  4096      0.62\n2.104190    fio            20998   loop0     R 120646616  4096      0.31\n2.105008    fio            20998   loop0     R 120646624  4096      0.81\n2.105260    fio            20998   loop0     R 120649272  4096      0.25\n2.105385    fio            20998   loop0     R 120673216  4096      0.12\n2.105824    fio            20998   loop0     R 120647848  4096      0.43\n2.106515    fio            20998   loop0     R 120647896  4096      0.68\n2.107331    fio            20998   loop0     R 120647904  4096      0.81\n2.107644    fio            20998   loop0     R 120648584  4096      0.31\n2.107894    fio            20998   loop0     R 120648672  4096      0.25\n2.108259    fio            20998   loop0     R 120648680  4096      0.36\n2.108384    fio            20998   loop0     R 120648688  4096      0.12\n2.108886    fio            20998   loop0     R 120649144  4096      0.50\n2.109201    fio            20998   loop0     R 120649152  4096      0.31\n2.109766    fio            20998   loop0     R 120649160  4096      0.56\n2.110520    fio            20998   loop0     R 120649216  4096      0.75\n2.111022    fio            20998   loop0     R 120649288  4096      0.50\n2.111463    fio            20998   loop0     R 120650208  4096      0.43\n2.111965    fio            20998   loop0     R 120650232  4096      0.49\n2.112781    fio            20998   loop0     R 120650248  4096      0.81"
}
```

## runqlat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3143": {
        "avg_ns_per_run": 239.26604789570638,
        "bytes_jited": 662,
        "bytes_xlated": 1168,
        "id": 3143,
        "name": "sched_switch",
        "run_cnt_delta": 14114,
        "run_time_ns_delta": 3377001,
        "type": "raw_tracepoint"
      },
      "3144": {
        "avg_ns_per_run": 588.9636302969636,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 3144,
        "name": "sched_wakeup",
        "run_cnt_delta": 5994,
        "run_time_ns_delta": 3530248,
        "type": "raw_tracepoint"
      },
      "3145": {
        "avg_ns_per_run": 274.8,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 3145,
        "name": "raw_tracepoint__sched_wakeup_new",
        "run_cnt_delta": 540,
        "run_time_ns_delta": 148392,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 567.3365401416054
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
      "3143": {
        "avg_ns_per_run": 294.2125819633184,
        "bytes_jited": 639,
        "bytes_xlated": 1120,
        "id": 3143,
        "name": "sched_switch",
        "run_cnt_delta": 10523,
        "run_time_ns_delta": 3095999,
        "type": "raw_tracepoint"
      },
      "3144": {
        "avg_ns_per_run": 739.8589693154996,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 3144,
        "name": "sched_wakeup",
        "run_cnt_delta": 5084,
        "run_time_ns_delta": 3761443,
        "type": "raw_tracepoint"
      },
      "3145": {
        "avg_ns_per_run": 280.8977695167286,
        "bytes_jited": 149,
        "bytes_xlated": 248,
        "id": 3145,
        "name": "raw_tracepoint__sched_wakeup_new",
        "run_cnt_delta": 538,
        "run_time_ns_delta": 151123,
        "type": "raw_tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 567.3201094809122
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
    "bulk_memory"
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
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3144
    },
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3145
    }
  ],
  "program_counts": {
    "applied": 1,
    "not_applied": 2,
    "requested": 3
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "In file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bcc-python-o1qxo55u/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bcc-python-o1qxo55u/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:6:\nIn file included from include/linux/pid_namespace.h:7:\nIn file included from include/linux/mm.h:1118:\nIn file included from include/linux/huge_mm.h:7:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "                 128 -> 255                  : 121      |                    |\n                 256 -> 511                  : 11       |                    |\n                 512 -> 1023                 : 1        |                    |\n                1024 -> 2047                 : 4        |                    |\n                2048 -> 4095                 : 0        |                    |\n                4096 -> 8191                 : 3        |                    |\n                8192 -> 16383                : 3        |                    |\n               16384 -> 32767                : 2        |                    |\n               32768 -> 65535                : 2        |                    |\n               65536 -> 131071               : 0        |                    |\n              131072 -> 262143               : 0        |                    |\n              262144 -> 524287               : 0        |                    |\n              524288 -> 1048575              : 0        |                    |\n             1048576 -> 2097151              : 1        |                    |\n             2097152 -> 4194303              : 2        |                    |\n             4194304 -> 8388607              : 1        |                    |\n             8388608 -> 16777215             : 1        |                    |\n            16777216 -> 33554431             : 0        |                    |\n            33554432 -> 67108863             : 0        |                    |\n            67108864 -> 134217727            : 0        |                    |\n           134217728 -> 268435455            : 0        |                    |\n           268435456 -> 536870911            : 0        |                    |\n           536870912 -> 1073741823           : 0        |                    |\n          1073741824 -> 2147483647           : 0        |                    |\n          2147483648 -> 4294967295           : 1        |                    |\n          4294967296 -> 8589934591           : 0        |                    |\n          8589934592 -> 17179869183          : 0        |                    |\n         17179869184 -> 34359738367          : 0        |                    |\n         34359738368 -> 68719476735          : 0        |                    |\n         68719476736 -> 137438953471         : 2        |                    |\n        137438953472 -> 274877906943         : 0        |                    |\n        274877906944 -> 549755813887         : 0        |                    |\n        549755813888 -> 1099511627775        : 0        |                    |\n       1099511627776 -> 2199023255551        : 0        |                    |\n       2199023255552 -> 4398046511103        : 0        |                    |\n       4398046511104 -> 8796093022207        : 0        |                    |\n       8796093022208 -> 17592186044415       : 0        |                    |\n      17592186044416 -> 35184372088831       : 0        |                    |\n      35184372088832 -> 70368744177663       : 0        |                    |\n      70368744177664 -> 140737488355327      : 1        |                    |"
}
```

## syscount

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3160": {
        "avg_ns_per_run": 57.80065301319464,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 3160,
        "name": "tracepoint__raw_syscalls__sys_enter",
        "run_cnt_delta": 550678,
        "run_time_ns_delta": 31829548,
        "type": "tracepoint"
      },
      "3161": {
        "avg_ns_per_run": 58.160104162315974,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 3161,
        "name": "tracepoint__raw_syscalls__sys_exit",
        "run_cnt_delta": 550679,
        "run_time_ns_delta": 32027548,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 10855.16234712394
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
      "3160": {
        "avg_ns_per_run": 55.599670600455056,
        "bytes_jited": 72,
        "bytes_xlated": 112,
        "id": 3160,
        "name": "tracepoint__raw_syscalls__sys_enter",
        "run_cnt_delta": 550699,
        "run_time_ns_delta": 30618683,
        "type": "tracepoint"
      },
      "3161": {
        "avg_ns_per_run": 57.70327219901943,
        "bytes_jited": 236,
        "bytes_xlated": 400,
        "id": 3161,
        "name": "tracepoint__raw_syscalls__sys_exit",
        "run_cnt_delta": 550700,
        "run_time_ns_delta": 31777192,
        "type": "tracepoint"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 10654.305791240098
  },
  "phase": "post_rejit",
  "reason": "",
  "status": "ok"
}
```

### ReJIT Result

```json
{
  "applied": false,
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
  "noop_programs": [
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3160
    },
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3161
    }
  ],
  "program_counts": {
    "applied": 0,
    "not_applied": 2,
    "requested": 2
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bcc-python-4eyughae/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bcc-python-4eyughae/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "mmap                        150         1153.603\nread                       1462         1113.133\nopenat                       56          593.766\nclock_nanosleep              16      3002455.162\n[13:54:32]\nSYSCALL                   COUNT        TIME (us)\nfutex                         4      1603765.643\nepoll_pwait                   7       807198.585\nnanosleep                     2        20308.821\npoll                         10         9647.306\nvfork                         5         2943.915\nexecve                        5         1530.854\nmmap                        150         1162.857\nopenat                       55          584.009\nmprotect                     40          302.092\nclock_nanosleep              30      2211945.469\n[13:54:33]\nSYSCALL                   COUNT        TIME (us)\nfutex                        17      1592667.965\nread                      13211      1028099.844\npoll                         65       857982.366\nepoll_pwait                   9       806122.090\nwait4                      1035       743412.273\nopenat                    12646       102892.682\nstatfs                    12462        68881.323\nclone                      1011        67894.906\nmmap                       1558        37454.521\nfutex                         6      1603003.903\n[13:54:33]\nSYSCALL                   COUNT        TIME (us)\nread                       2435      1001861.259\nclock_nanosleep              11       870909.874\nepoll_pwait                   5       806800.741\nwait4                      1013       706060.617\npoll                         18       542268.869\nclone                      1003        70314.739\nopenat                     4465        48692.008\nstatfs                     5970        34696.613\narch_prctl               263004        27189.427\nDetaching..."
}
```

## execsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3170": {
        "avg_ns_per_run": 1455.3333333333333,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 3170,
        "name": "syscall__execve",
        "run_cnt_delta": 9,
        "run_time_ns_delta": 13098,
        "type": "kprobe"
      },
      "3171": {
        "avg_ns_per_run": 191.33333333333334,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 3171,
        "name": "do_ret_sys_execve",
        "run_cnt_delta": 9,
        "run_time_ns_delta": 1722,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 567.0920180690409
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
      "3170": {
        "avg_ns_per_run": 1363.2222222222222,
        "bytes_jited": 2677,
        "bytes_xlated": 4144,
        "id": 3170,
        "name": "syscall__execve",
        "run_cnt_delta": 9,
        "run_time_ns_delta": 12269,
        "type": "kprobe"
      },
      "3171": {
        "avg_ns_per_run": 156.0,
        "bytes_jited": 492,
        "bytes_xlated": 704,
        "id": 3171,
        "name": "do_ret_sys_execve",
        "run_cnt_delta": 9,
        "run_time_ns_delta": 1404,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 566.8983287921675
  },
  "phase": "post_rejit",
  "reason": "",
  "status": "ok"
}
```

### ReJIT Result

```json
{
  "applied": false,
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
  "noop_programs": [
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3170
    },
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3171
    }
  ],
  "program_counts": {
    "applied": 0,
    "not_applied": 2,
    "requested": 2
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bcc-python-e2dvrrjx/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bcc-python-e2dvrrjx/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:17:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "TIME     UID   PCOMM            PID     PPID    RET ARGS"
}
```

## opensnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3180": {
        "avg_ns_per_run": 785.4024390243902,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 3180,
        "name": "__x64_sys_open",
        "run_cnt_delta": 82,
        "run_time_ns_delta": 64403,
        "type": "tracing"
      },
      "3181": {
        "avg_ns_per_run": 810.4810011789244,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 3181,
        "name": "kretfunc__vmlinux____x64_sys_openat",
        "run_cnt_delta": 33081,
        "run_time_ns_delta": 26811522,
        "type": "tracing"
      },
      "3182": {
        "avg_ns_per_run": 953.7,
        "bytes_jited": 590,
        "bytes_xlated": 640,
        "id": 3182,
        "name": "kretfunc__vmlinux____x64_sys_openat2",
        "run_cnt_delta": 10,
        "run_time_ns_delta": 9537,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 359.57471340173186
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
      "3180": {
        "avg_ns_per_run": 566.5274725274726,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 3180,
        "name": "__x64_sys_open",
        "run_cnt_delta": 91,
        "run_time_ns_delta": 51554,
        "type": "tracing"
      },
      "3181": {
        "avg_ns_per_run": 835.2930004594884,
        "bytes_jited": 517,
        "bytes_xlated": 600,
        "id": 3181,
        "name": "kretfunc__vmlinux____x64_sys_openat",
        "run_cnt_delta": 32645,
        "run_time_ns_delta": 27268140,
        "type": "tracing"
      },
      "3182": {
        "avg_ns_per_run": 594.7,
        "bytes_jited": 590,
        "bytes_xlated": 640,
        "id": 3182,
        "name": "kretfunc__vmlinux____x64_sys_openat2",
        "run_cnt_delta": 10,
        "run_time_ns_delta": 5947,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 346.4962704725152
  },
  "phase": "post_rejit",
  "reason": "prog 3180: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3180_1777470945_001718071_1156: bpfverify --verifier-states-out failed for prog 3180: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/verifier_states.json\" \"--prog-btf-id\" \"3619\" \"--attach-btf-id\" \"64477\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3181: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3181_1777470945_123683506_1158: bpfverify --verifier-states-out failed for prog 3181: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/verifier_states.json\" \"--prog-btf-id\" \"3619\" \"--attach-btf-id\" \"64481\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3182: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3182_1777470945_246731122_1160: bpfverify --verifier-states-out failed for prog 3182: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/verifier_states.json\" \"--prog-btf-id\" \"3619\" \"--attach-btf-id\" \"64482\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
  "status": "error"
}
```

### ReJIT Result

```json
{
  "applied": false,
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
  "error": "prog 3180: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3180_1777470945_001718071_1156: bpfverify --verifier-states-out failed for prog 3180: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/verifier_states.json\" \"--prog-btf-id\" \"3619\" \"--attach-btf-id\" \"64477\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3181: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3181_1777470945_123683506_1158: bpfverify --verifier-states-out failed for prog 3181: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/verifier_states.json\" \"--prog-btf-id\" \"3619\" \"--attach-btf-id\" \"64481\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3182: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3182_1777470945_246731122_1160: bpfverify --verifier-states-out failed for prog 3182: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/verifier_states.json\" \"--prog-btf-id\" \"3619\" \"--attach-btf-id\" \"64482\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
  "error_programs": [
    {
      "applied": false,
      "changed": false,
      "error": "preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3180_1777470945_001718071_1156: bpfverify --verifier-states-out failed for prog 3180: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1155/verifier_states.json\" \"--prog-btf-id\" \"3619\" \"--attach-btf-id\" \"64477\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
      "exit_code": 1,
      "prog_id": 3180
    },
    {
      "applied": false,
      "changed": false,
      "error": "preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3181_1777470945_123683506_1158: bpfverify --verifier-states-out failed for prog 3181: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1157/verifier_states.json\" \"--prog-btf-id\" \"3619\" \"--attach-btf-id\" \"64481\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
      "exit_code": 1,
      "prog_id": 3181
    },
    {
      "applied": false,
      "changed": false,
      "error": "preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3182_1777470945_246731122_1160: bpfverify --verifier-states-out failed for prog 3182: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1159/verifier_states.json\" \"--prog-btf-id\" \"3619\" \"--attach-btf-id\" \"64482\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
      "exit_code": 1,
      "prog_id": 3182
    }
  ],
  "exit_code": 1,
  "program_counts": {
    "applied": 0,
    "not_applied": 3,
    "requested": 3
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "Possibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 1 samples\nPossibly lost 139 samples",
  "stdout_tail": "27052  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index1/level\n27052  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index1/coherency_line_size\n27052  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index1/ways_of_associativity\n27052  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/type\n27052  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/size\n27052  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/level\n27052  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/coherency_line_size\n27052  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index2/ways_of_associativity\n27052  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/type\n27052  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/size\n27052  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/level\n27052  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/coherency_line_size\n27052  stress-ng           3   0 /sys/devices/system/cpu/cpu3/cache/index3/ways_of_associativity\n27052  stress-ng           3   0 /sys/kernel/debug/clear_warn_once\n27052  stress-ng           3   0 /sys/devices/system/clocksource\n27052  stress-ng           4   0 /sys/devices/system/clocksource/clocksource0/current_clocksource\n27052  stress-ng           3   0 /proc/sys/kernel/sched_autogroup_enabled\n27052  stress-ng           3   0 /sys/devices/system/cpu\n27052  stress-ng          -1   2 /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor\n27052  stress-ng          -1   2 /sys/devices/system/cpu/cpu1/cpufreq/scaling_governor\n27052  stress-ng          -1   2 /sys/devices/system/cpu/cpu2/cpufreq/scaling_governor\n27052  stress-ng          -1   2 /sys/devices/system/cpu/cpu3/cpufreq/scaling_governor\n27053  stress-ng-utime     3   0 /proc/self/coredump_filter\n27053  stress-ng-utime     3   0 /proc/self/oom_score_adj\n27053  stress-ng-utime     3   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/tmp-stress-ng-utime-27053-0\n27053  stress-ng-utime     4   0 /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/tmp-stress-ng-utime-27053-0/stress-ng-utime-27053-0-1910692499\n27052  stress-ng           3   0 /sys/devices/system/clocksource\n27052  stress-ng           4   0 /sys/devices/system/clocksource/clocksource0/current_clocksource\n27054  bpftool             3   0 /etc/ld.so.cache\n27054  bpftool             3   0 /lib/x86_64-linux-gnu/libelf.so.1\n27054  bpftool             3   0 /lib/x86_64-linux-gnu/libcrypto.so.3\n27054  bpftool             3   0 /lib/x86_64-linux-gnu/libz.so.1\n27054  bpftool             3   0 /lib/x86_64-linux-gnu/libcap.so.2\n27054  bpftool             3   0 /lib/x86_64-linux-gnu/libc.so.6\n27054  bpftool             3   0 /lib/x86_64-linux-gnu/libzstd.so.1\n27054  bpftool             4   0 /etc/localtime\n27054  bpftool             4   0 /proc/self/fdinfo/3\n27054  bpftool             4   0 /proc/self/fdinfo/3\n27054  bpftool             4   0 /proc/self/fdinfo/3\n27054  bpftool             4   0 /proc/self/fdinfo/3"
}
```

## capable

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3191": {
        "avg_ns_per_run": 102.34908446544596,
        "bytes_jited": 203,
        "bytes_xlated": 344,
        "id": 3191,
        "name": "cap_capable",
        "run_cnt_delta": 93115,
        "run_time_ns_delta": 9530235,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 12668.993642988506
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
      "3191": {
        "avg_ns_per_run": 132.57723245449176,
        "bytes_jited": 203,
        "bytes_xlated": 344,
        "id": 3191,
        "name": "cap_capable",
        "run_cnt_delta": 93115,
        "run_time_ns_delta": 12344929,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 12520.736615050255
  },
  "phase": "post_rejit",
  "reason": "prog 3191: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3191_1777470972_954833225_1162: bpfverify final verification failed for prog 3191: bpfverify final verification rejected bytecode (returncode 0, verifier status fail, errno 22): verifier log summary:\nkernel btf_id 129873 is not a function\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
  "status": "error"
}
```

### ReJIT Result

```json
{
  "applied": false,
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
  "error": "prog 3191: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3191_1777470972_954833225_1162: bpfverify final verification failed for prog 3191: bpfverify final verification rejected bytecode (returncode 0, verifier status fail, errno 22): verifier log summary:\nkernel btf_id 129873 is not a function\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
  "error_programs": [
    {
      "applied": false,
      "changed": false,
      "error": "preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3191_1777470972_954833225_1162: bpfverify final verification failed for prog 3191: bpfverify final verification rejected bytecode (returncode 0, verifier status fail, errno 22): verifier log summary:\nkernel btf_id 129873 is not a function\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
      "exit_code": 1,
      "prog_id": 3191
    }
  ],
  "exit_code": 1,
  "program_counts": {
    "applied": 0,
    "not_applied": 1,
    "requested": 1
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "Possibly lost 5 samples\nPossibly lost 1 samples\nPossibly lost 6 samples\nPossibly lost 2 samples\nPossibly lost 3 samples\nPossibly lost 3 samples\nPossibly lost 4 samples\nPossibly lost 5 samples\nPossibly lost 2 samples\nPossibly lost 4 samples\nPossibly lost 1 samples\nPossibly lost 7 samples\nPossibly lost 7 samples\nPossibly lost 1 samples\nPossibly lost 5 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 7 samples\nPossibly lost 4 samples\nPossibly lost 2 samples\nPossibly lost 2 samples\nPossibly lost 6 samples\nPossibly lost 2 samples\nPossibly lost 4 samples\nPossibly lost 2 samples\nPossibly lost 6 samples\nPossibly lost 1 samples\nPossibly lost 6 samples\nPossibly lost 2 samples\nPossibly lost 4 samples\nPossibly lost 1 samples\nPossibly lost 1 samples\nPossibly lost 2 samples\nPossibly lost 4 samples\nPossibly lost 1 samples\nPossibly lost 6 samples\nPossibly lost 1 samples\nPossibly lost 3 samples\nPossibly lost 3 samples\nPossibly lost 1 samples",
  "stdout_tail": "13:56:13  0      29106  stress-ng-set    21   CAP_SYS_ADMIN        1\n13:56:13  0      29106  stress-ng-set    21   CAP_SYS_ADMIN        1\n13:56:13  0      29106  stress-ng-set    6    CAP_SETGID           1\n13:56:13  0      29106  stress-ng-set    21   CAP_SYS_ADMIN        1\n13:56:13  0      29106  stress-ng-set    21   CAP_SYS_ADMIN        1\n13:56:13  0      29106  stress-ng-set    7    CAP_SETUID           1\n13:56:13  0      29106  stress-ng-set    6    CAP_SETGID           1\n13:56:13  0      29106  stress-ng-set    6    CAP_SETGID           1\n13:56:13  0      29106  stress-ng-set    6    CAP_SETGID           1\n13:56:13  0      29106  stress-ng-set    6    CAP_SETGID           1\n13:56:13  0      29106  stress-ng-set    21   CAP_SYS_ADMIN        1\n13:56:13  0      29106  stress-ng-set    21   CAP_SYS_ADMIN        1\n13:56:13  0      29106  stress-ng-set    21   CAP_SYS_ADMIN        1\n13:56:13  0      29106  stress-ng-set    6    CAP_SETGID           1\n13:56:13  0      29106  stress-ng-set    21   CAP_SYS_ADMIN        1\n13:56:13  0      29106  stress-ng-set    21   CAP_SYS_ADMIN        1\n13:56:13  0      29106  stress-ng-set    7    CAP_SETUID           1\n13:56:13  0      29106  stress-ng-set    6    CAP_SETGID           1\n13:56:13  0      29106  stress-ng-set    6    CAP_SETGID           1\n13:56:13  0      29106  stress-ng-set    6    CAP_SETGID           1\n13:56:13  0      29106  stress-ng-set    6    CAP_SETGID           1\n13:56:13  0      29106  stress-ng-set    21   CAP_SYS_ADMIN        1\n13:56:13  0      29106  stress-ng-set    21   CAP_SYS_ADMIN        1\n13:56:13  0      29106  stress-ng-set    21   CAP_SYS_ADMIN        1\n13:56:13  0      29107  stress-ng        24   CAP_SYS_RESOURCE     1\n13:56:13  0      29108  stress-ng-timer  21   CAP_SYS_ADMIN        1\n13:56:13  0      29108  stress-ng-timer  21   CAP_SYS_ADMIN        1\n13:56:13  0      29108  stress-ng-timer  21   CAP_SYS_ADMIN        1\n13:56:13  0      29108  stress-ng-timer  21   CAP_SYS_ADMIN        1\n13:56:13  0      29109  bpftool          21   CAP_SYS_ADMIN        1\n13:56:13  0      29109  bpftool          21   CAP_SYS_ADMIN        1\n13:56:13  0      29109  bpftool          39   CAP_BPF              1\n13:56:13  0      29109  bpftool          21   CAP_SYS_ADMIN        1\n13:56:13  0      29109  bpftool          21   CAP_SYS_ADMIN        1\n13:56:13  0      29109  bpftool          39   CAP_BPF              1\n13:56:13  0      29109  bpftool          39   CAP_BPF              1\n13:56:13  0      29109  bpftool          39   CAP_BPF              1\n13:56:13  0      29109  bpftool          39   CAP_BPF              1\n13:56:13  0      29109  bpftool          21   CAP_SYS_ADMIN        1\n13:56:13  0      29109  bpftool          21   CAP_SYS_ADMIN        1"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3199": {
        "avg_ns_per_run": 31.715483739005933,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 3199,
        "name": "vfs_create",
        "run_cnt_delta": 4889,
        "run_time_ns_delta": 155057,
        "type": "tracing"
      },
      "3200": {
        "avg_ns_per_run": 93.86435331230284,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 3200,
        "name": "kfunc__vmlinux__vfs_fsync_range",
        "run_cnt_delta": 317,
        "run_time_ns_delta": 29755,
        "type": "tracing"
      },
      "3201": {
        "avg_ns_per_run": 25.884137340576288,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 3201,
        "name": "vfs_open",
        "run_cnt_delta": 67744,
        "run_time_ns_delta": 1753495,
        "type": "tracing"
      },
      "3202": {
        "avg_ns_per_run": 26.1823535384303,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 3202,
        "name": "vfs_read",
        "run_cnt_delta": 9849,
        "run_time_ns_delta": 257870,
        "type": "tracing"
      },
      "3203": {
        "avg_ns_per_run": 27.89260490236809,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 3203,
        "name": "vfs_write",
        "run_cnt_delta": 4814,
        "run_time_ns_delta": 134275,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 445.5391077615944
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
      "3199": {
        "avg_ns_per_run": 31.94935674903002,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 3199,
        "name": "vfs_create",
        "run_cnt_delta": 4897,
        "run_time_ns_delta": 156456,
        "type": "tracing"
      },
      "3200": {
        "avg_ns_per_run": 114.41640378548895,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 3200,
        "name": "kfunc__vmlinux__vfs_fsync_range",
        "run_cnt_delta": 317,
        "run_time_ns_delta": 36270,
        "type": "tracing"
      },
      "3201": {
        "avg_ns_per_run": 25.327136459190204,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 3201,
        "name": "vfs_open",
        "run_cnt_delta": 54705,
        "run_time_ns_delta": 1385521,
        "type": "tracing"
      },
      "3202": {
        "avg_ns_per_run": 26.55989847715736,
        "bytes_jited": 87,
        "bytes_xlated": 136,
        "id": 3202,
        "name": "vfs_read",
        "run_cnt_delta": 9850,
        "run_time_ns_delta": 261615,
        "type": "tracing"
      },
      "3203": {
        "avg_ns_per_run": 26.52565967172242,
        "bytes_jited": 90,
        "bytes_xlated": 144,
        "id": 3203,
        "name": "vfs_write",
        "run_cnt_delta": 4813,
        "run_time_ns_delta": 127668,
        "type": "tracing"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 446.23495337411094
  },
  "phase": "post_rejit",
  "reason": "prog 3199: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3199_1777470995_129845292_1164: bpfverify --verifier-states-out failed for prog 3199: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123739\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3200: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3200_1777470995_251844154_1166: bpfverify --verifier-states-out failed for prog 3200: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123755\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3201: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3201_1777470995_375960463_1168: bpfverify --verifier-states-out failed for prog 3201: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123778\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3202: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3202_1777470995_498458533_1170: bpfverify --verifier-states-out failed for prog 3202: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123788\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3203: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3203_1777470995_620972474_1172: bpfverify --verifier-states-out failed for prog 3203: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123808\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
  "status": "error"
}
```

### ReJIT Result

```json
{
  "applied": false,
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
  "error": "prog 3199: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3199_1777470995_129845292_1164: bpfverify --verifier-states-out failed for prog 3199: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123739\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3200: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3200_1777470995_251844154_1166: bpfverify --verifier-states-out failed for prog 3200: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123755\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3201: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3201_1777470995_375960463_1168: bpfverify --verifier-states-out failed for prog 3201: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123778\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3202: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3202_1777470995_498458533_1170: bpfverify --verifier-states-out failed for prog 3202: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123788\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3203: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3203_1777470995_620972474_1172: bpfverify --verifier-states-out failed for prog 3203: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123808\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
  "error_programs": [
    {
      "applied": false,
      "changed": false,
      "error": "preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3199_1777470995_129845292_1164: bpfverify --verifier-states-out failed for prog 3199: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1163/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123739\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
      "exit_code": 1,
      "prog_id": 3199
    },
    {
      "applied": false,
      "changed": false,
      "error": "preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3200_1777470995_251844154_1166: bpfverify --verifier-states-out failed for prog 3200: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1165/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123755\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
      "exit_code": 1,
      "prog_id": 3200
    },
    {
      "applied": false,
      "changed": false,
      "error": "preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3201_1777470995_375960463_1168: bpfverify --verifier-states-out failed for prog 3201: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1167/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123778\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
      "exit_code": 1,
      "prog_id": 3201
    },
    {
      "applied": false,
      "changed": false,
      "error": "preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3202_1777470995_498458533_1170: bpfverify --verifier-states-out failed for prog 3202: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1169/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123788\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
      "exit_code": 1,
      "prog_id": 3202
    },
    {
      "applied": false,
      "changed": false,
      "error": "preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3203_1777470995_620972474_1172: bpfverify --verifier-states-out failed for prog 3203: bpfverify original verifier-states failed (returncode 1, status exit status: 1): subprocess \"bpfverify\" \"--prog-type\" \"tracing\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/verified_original.bin\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/original_bpfverify_report.json\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bpfrejit-daemon-optimize-1797-1171/verifier_states.json\" \"--prog-btf-id\" \"3621\" \"--attach-btf-id\" \"123808\" \"--attach-btf-obj-id\" \"1\": func#0 @0\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
      "exit_code": 1,
      "prog_id": 3203
    }
  ],
  "exit_code": 1,
  "program_counts": {
    "applied": 0,
    "not_applied": 5,
    "requested": 5
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "      |                        ^\n<scratch space>:5:1: note: expanded from here\n    5 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bcc-python-rwczmxx3/bpfrejit_bcc_compat.h:43:\nIn file included from include/linux/ns/ns_common_types.h:6:\nIn file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bcc-python-rwczmxx3/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\n5 warnings generated.",
  "stdout_tail": "13:56:16:       100        5        0      130        0\n13:56:17:      1173       38       11     9545        3\n13:56:18:         0        0       66        0        0\n13:56:19:       379       14       63      435        1\n13:56:20:       763       30       60    37508     1000\n13:56:21:       758       28       58     2879     1001\n13:56:22:      3524     4355       26    11781     2513\n13:56:23:         1        1        0        0        0\n13:56:24:         0        0        0        0        0\n13:56:25:         0        0        0        0        0\n13:56:26:         0        0        0        0        0\n13:56:27:         0        0        0        0        0\n13:56:28:         0        0        0        0        0\n13:56:29:         0        0        0        0        0\n13:56:30:         0        0        0        0        0\n13:56:31:         0        0        0        0        0\n13:56:32:      1534      199        0     2781       13\n13:56:33:        46       36        0      138       37\n13:56:34:        39       30        0      114       30\n13:56:35:      1672       85       33     2615      291\n13:56:36:      1059     1078        0     9607       62\n13:56:37:       379       14       49      437        1\n13:56:38:       380       14       68      435        1\n13:56:39:         0        0       72        0        0\n13:56:40:      1523       58       58    27321     2001\n13:56:41:      3521     4351       37    11781     2513\n13:56:42:         2        2        0        0        0\n13:56:43:         1        1        0        0        0\n13:56:44:         0        0        0        0        0\n13:56:45:         0        0        0        0        0\n13:56:46:         0        0        0        0        0\n13:56:47:         0        0        0        0        0\n13:56:48:         0        0        0        0        0\n13:56:49:         0        0        0        0        0\n13:56:50:         1        1        0        0        0\n13:56:51:      1526      194        0     2769       11\n13:56:52:        54       41        0      152       40\n13:56:53:        41       31        0      116       30\n13:56:54:       886       49       15     1263       77\n13:56:54:       782       35       18     1375      221"
}
```

## tcpconnect

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3216": {
        "avg_ns_per_run": 2381.0,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 3216,
        "name": "trace_connect_entry",
        "run_cnt_delta": 1,
        "run_time_ns_delta": 2381,
        "type": "kprobe"
      },
      "3217": {
        "avg_ns_per_run": 6643.0,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 3217,
        "name": "trace_connect_v4_return",
        "run_cnt_delta": 1,
        "run_time_ns_delta": 6643,
        "type": "kprobe"
      },
      "3218": {
        "avg_ns_per_run": null,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 3218,
        "name": "trace_connect_v6_return",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 11448.496015586572
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
      "3216": {
        "avg_ns_per_run": 2123.0,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 3216,
        "name": "trace_connect_entry",
        "run_cnt_delta": 1,
        "run_time_ns_delta": 2123,
        "type": "kprobe"
      },
      "3217": {
        "avg_ns_per_run": 6819.0,
        "bytes_jited": 480,
        "bytes_xlated": 720,
        "id": 3217,
        "name": "trace_connect_v4_return",
        "run_cnt_delta": 1,
        "run_time_ns_delta": 6819,
        "type": "kprobe"
      },
      "3218": {
        "avg_ns_per_run": null,
        "bytes_jited": 477,
        "bytes_xlated": 712,
        "id": 3218,
        "name": "trace_connect_v6_return",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 17666.793965057965
  },
  "phase": "post_rejit",
  "reason": "",
  "status": "ok"
}
```

### ReJIT Result

```json
{
  "applied": false,
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
  "noop_programs": [
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3216
    },
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3217
    },
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3218
    }
  ],
  "program_counts": {
    "applied": 0,
    "not_applied": 3,
    "requested": 3
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bcc-python-whf3yr4e/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:16:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "30889   stress-ng-so 4  127.0.0.1        127.0.0.1        22083\nTracing connect ... Hit Ctrl-C to end\nPID     COMM         IP SADDR            DADDR            DPORT\n30928   stress-ng-so 4  127.0.0.1        127.0.0.1        22083"
}
```

## bindsnoop

### Baseline

```json
{
  "measurement": {
    "bpf": {
      "3230": {
        "avg_ns_per_run": 2047.0,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 3230,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 2,
        "run_time_ns_delta": 4094,
        "type": "kprobe"
      },
      "3231": {
        "avg_ns_per_run": 6710.0,
        "bytes_jited": 721,
        "bytes_xlated": 1160,
        "id": 3231,
        "name": "bindsnoop_v4_return",
        "run_cnt_delta": 2,
        "run_time_ns_delta": 13420,
        "type": "kprobe"
      },
      "3232": {
        "avg_ns_per_run": null,
        "bytes_jited": 742,
        "bytes_xlated": 1184,
        "id": 3232,
        "name": "bindsnoop_v6_return",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 20733.621722298678
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
      "3230": {
        "avg_ns_per_run": 1977.5,
        "bytes_jited": 75,
        "bytes_xlated": 120,
        "id": 3230,
        "name": "bindsnoop_entry",
        "run_cnt_delta": 2,
        "run_time_ns_delta": 3955,
        "type": "kprobe"
      },
      "3231": {
        "avg_ns_per_run": 6198.0,
        "bytes_jited": 721,
        "bytes_xlated": 1160,
        "id": 3231,
        "name": "bindsnoop_v4_return",
        "run_cnt_delta": 2,
        "run_time_ns_delta": 12396,
        "type": "kprobe"
      },
      "3232": {
        "avg_ns_per_run": null,
        "bytes_jited": 742,
        "bytes_xlated": 1184,
        "id": 3232,
        "name": "bindsnoop_v6_return",
        "run_cnt_delta": 0,
        "run_time_ns_delta": 0,
        "type": "kprobe"
      }
    },
    "duration_s": 10,
    "metric": "ops/s",
    "throughput": 21768.99315344106
  },
  "phase": "post_rejit",
  "reason": "prog 3231: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3231_1777471023_308014315_1178: bpfverify final verification failed for prog 3231: bpfverify final verification rejected bytecode (returncode 0, verifier status fail, errno 22): verifier log summary:\nkernel btf_id 129873 is not a function\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3232: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3232_1777471023_440428218_1180: bpfverify final verification failed for prog 3232: bpfverify final verification rejected bytecode (returncode 0, verifier status fail, errno 22): verifier log summary:\nkernel btf_id 129873 is not a function\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
  "status": "error"
}
```

### ReJIT Result

```json
{
  "applied": false,
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
  "error": "prog 3231: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3231_1777471023_308014315_1178: bpfverify final verification failed for prog 3231: bpfverify final verification rejected bytecode (returncode 0, verifier status fail, errno 22): verifier log summary:\nkernel btf_id 129873 is not a function\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 3232: preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3232_1777471023_440428218_1180: bpfverify final verification failed for prog 3232: bpfverify final verification rejected bytecode (returncode 0, verifier status fail, errno 22): verifier log summary:\nkernel btf_id 129873 is not a function\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
  "error_programs": [
    {
      "applied": false,
      "changed": false,
      "error": "preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3231_1777471023_308014315_1178: bpfverify final verification failed for prog 3231: bpfverify final verification rejected bytecode (returncode 0, verifier status fail, errno 22): verifier log summary:\nkernel btf_id 129873 is not a function\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
      "exit_code": 1,
      "prog_id": 3231
    },
    {
      "applied": false,
      "changed": false,
      "error": "preserved failure workdir: /var/lib/bpfrejit-daemon/failures/3232_1777471023_440428218_1180: bpfverify final verification failed for prog 3232: bpfverify final verification rejected bytecode (returncode 0, verifier status fail, errno 22): verifier log summary:\nkernel btf_id 129873 is not a function\nprocessed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
      "exit_code": 1,
      "prog_id": 3232
    }
  ],
  "exit_code": 1,
  "noop_programs": [
    {
      "applied": false,
      "changed": false,
      "exit_code": 0,
      "passes": [
        {
          "pass_name": "wide_mem",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "rotate",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "cond_select",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "extract",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "endian_fusion",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "map_inline",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "const_prop",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "dce",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bounds_check_merge",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "skb_load_bytes_spec",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        },
        {
          "pass_name": "bulk_memory",
          "sites_applied": 0,
          "sites_matched": 0,
          "sites_skipped": 0,
          "skip_reasons": {},
          "verify": {
            "status": "not_needed"
          }
        }
      ],
      "prog_id": 3230
    }
  ],
  "program_counts": {
    "applied": 0,
    "not_applied": 3,
    "requested": 3
  }
}
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "In file included from include/linux/ns/nstree_types.h:6:\nIn file included from include/linux/rbtree.h:11:\nIn file included from include/linux/rcupdate.h:11:\nIn file included from include/linux/sched.h:10:\narch/x86/include/asm/processor.h:469:10: warning: multiple identical address spaces specified for type [-Wduplicate-decl-specifier]\narch/x86/include/asm/percpu.h:529:36: note: expanded from macro 'this_cpu_read_const'\n  529 | #define this_cpu_read_const(pcp)                        __raw_cpu_read_const(pcp)\n      |                                                         ^\narch/x86/include/asm/percpu.h:138:35: note: expanded from macro '__raw_cpu_read_const'\n  138 | #define __raw_cpu_read_const(pcp)       __raw_cpu_read(, , pcp)\n      |                                         ^\narch/x86/include/asm/percpu.h:130:9: note: expanded from macro '__raw_cpu_read'\n  130 |         *(qual __my_cpu_type(pcp) * __force)__my_cpu_ptr(&(pcp));       \\\n      |                ^\nnote: (skipping 3 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)\ninclude/linux/args.h:13:24: note: expanded from macro '__CONCAT'\n   13 | #define __CONCAT(a, b) a ## b\n      |                        ^\n<scratch space>:4:1: note: expanded from here\n    4 | __seg_gs\n      | ^\n<built-in>:358:33: note: expanded from macro '__seg_gs'\n  358 | #define __seg_gs __attribute__((address_space(256)))\n      |                                 ^\nIn file included from <built-in>:5:\nIn file included from /var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.ea8850ef/bcc-python-wf5sc123/bpfrejit_bcc_compat.h:43:\ninclude/linux/ns/ns_common_types.h:52:3: warning: declaration does not declare anything [-Wmissing-declarations]\n   52 |                 struct ns_tree;\n      |                 ^\nIn file included from /virtual/main.c:18:\nIn file included from include/net/sock.h:14:\nIn file included from include/linux/netdevice.h:20:\nIn file included from include/net/net_namespace.h:42:\nIn file included from include/linux/skbuff.h:11:\nIn file included from include/linux/bvec.h:6:\nIn file included from include/linux/highmem.h:5:\ninclude/linux/fs.h:1916:2: warning: declaration does not declare anything [-Wmissing-declarations]\n 1916 |         struct __filename_head;\n      |         ^\n6 warnings generated.",
  "stdout_tail": "   30969 stress-ng-sc IP   0.0.0.0         21983 ..NR.  0\nTracing binds ... Hit Ctrl-C to end\n     PID COMM         PROT ADDR            PORT   OPTS IF\n   30972 stress-ng-so IP   0.0.0.0         22083 ..NR.  0\n   31010 stress-ng-sc IP   0.0.0.0         21983 ..NR.  0\n   31013 stress-ng-so IP   0.0.0.0         22083 ..NR.  0"
}
```

