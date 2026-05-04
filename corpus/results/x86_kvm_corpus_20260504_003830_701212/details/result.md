# Corpus Benchmark

```json
{
  "generated_at": "2026-05-04T00:48:22.366666+00:00",
  "partial": true,
  "per_program": [
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 4860.333333333333,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 14581,
      "post_rejit_avg_ns_per_run": 1436.6666666666667,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 4310,
      "program": "tracepoint__sched_process_free",
      "program_id": 17,
      "ratio": 0.29559015156710794,
      "runner": "otelcol-ebpf-profiler",
      "type": "tracepoint",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 1211.4419642857142,
      "baseline_run_cnt_delta": 224,
      "baseline_run_time_ns_delta": 271363,
      "post_rejit_avg_ns_per_run": 1054.6651785714287,
      "post_rejit_run_cnt_delta": 224,
      "post_rejit_run_time_ns_delta": 236245,
      "program": "native_tracer_entry",
      "program_id": 18,
      "ratio": 0.8705866311914301,
      "runner": "otelcol-ebpf-profiler",
      "type": "perf_event",
      "workload": "stress_ng_cpu"
    }
  ],
  "results": [
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline": {
        "bpf": {
          "6": {
            "avg_ns_per_run": null,
            "bytes_jited": 3721,
            "bytes_xlated": 6232,
            "id": 6,
            "name": "perf_unwind_stop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "7": {
            "avg_ns_per_run": null,
            "bytes_jited": 22575,
            "bytes_xlated": 37232,
            "id": 7,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "8": {
            "avg_ns_per_run": null,
            "bytes_jited": 18290,
            "bytes_xlated": 28048,
            "id": 8,
            "name": "perf_unwind_hotspot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "9": {
            "avg_ns_per_run": null,
            "bytes_jited": 17737,
            "bytes_xlated": 29144,
            "id": 9,
            "name": "perf_unwind_perl",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "10": {
            "avg_ns_per_run": null,
            "bytes_jited": 15178,
            "bytes_xlated": 25032,
            "id": 10,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "11": {
            "avg_ns_per_run": null,
            "bytes_jited": 19909,
            "bytes_xlated": 33264,
            "id": 11,
            "name": "perf_unwind_python",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "12": {
            "avg_ns_per_run": null,
            "bytes_jited": 16540,
            "bytes_xlated": 28000,
            "id": 12,
            "name": "perf_unwind_ruby",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "13": {
            "avg_ns_per_run": null,
            "bytes_jited": 20050,
            "bytes_xlated": 33712,
            "id": 13,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "14": {
            "avg_ns_per_run": null,
            "bytes_jited": 22565,
            "bytes_xlated": 34248,
            "id": 14,
            "name": "perf_unwind_dotnet",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "15": {
            "avg_ns_per_run": null,
            "bytes_jited": 1580,
            "bytes_xlated": 2496,
            "id": 15,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "16": {
            "avg_ns_per_run": null,
            "bytes_jited": 696,
            "bytes_xlated": 1088,
            "id": 16,
            "name": "perf_unwind_beam",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "17": {
            "avg_ns_per_run": 4860.333333333333,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 17,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 14581,
            "type": "tracepoint"
          },
          "18": {
            "avg_ns_per_run": 1211.4419642857142,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 18,
            "name": "native_tracer_entry",
            "run_cnt_delta": 224,
            "run_time_ns_delta": 271363,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 0.6866375900000037,
            "ops_per_sec": 2920.0265601537913,
            "ops_total": 2005.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [1902] setting to a 5 secs run per stressor\nstress-ng: info:  [1902] dispatching hogs: 1 cpu\nstress-ng: info:  [1902] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [1902] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1902]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1902] cpu                2005      0.67      0.67      0.00      2987.99        2984.36\nstress-ng: info:  [1902] skipped: 0\nstress-ng: info:  [1902] passed: 1: cpu (1)\nstress-ng: info:  [1902] failed: 0\nstress-ng: info:  [1902] metrics untrustworthy: 0\nstress-ng: info:  [1902] successful run completed in 0.67 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": null,
            "bytes_jited": 3766,
            "bytes_xlated": 6472,
            "id": 6,
            "name": "perf_unwind_stop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "7": {
            "avg_ns_per_run": null,
            "bytes_jited": 22819,
            "bytes_xlated": 38720,
            "id": 7,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "8": {
            "avg_ns_per_run": null,
            "bytes_jited": 18395,
            "bytes_xlated": 28608,
            "id": 8,
            "name": "perf_unwind_hotspot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "9": {
            "avg_ns_per_run": null,
            "bytes_jited": 17885,
            "bytes_xlated": 29912,
            "id": 9,
            "name": "perf_unwind_perl",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "10": {
            "avg_ns_per_run": null,
            "bytes_jited": 15261,
            "bytes_xlated": 25464,
            "id": 10,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "11": {
            "avg_ns_per_run": null,
            "bytes_jited": 18452,
            "bytes_xlated": 30736,
            "id": 11,
            "name": "perf_unwind_python",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "12": {
            "avg_ns_per_run": null,
            "bytes_jited": 16671,
            "bytes_xlated": 28656,
            "id": 12,
            "name": "perf_unwind_ruby",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "13": {
            "avg_ns_per_run": null,
            "bytes_jited": 20089,
            "bytes_xlated": 34480,
            "id": 13,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "14": {
            "avg_ns_per_run": null,
            "bytes_jited": 22698,
            "bytes_xlated": 34952,
            "id": 14,
            "name": "perf_unwind_dotnet",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "15": {
            "avg_ns_per_run": null,
            "bytes_jited": 1389,
            "bytes_xlated": 2192,
            "id": 15,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "16": {
            "avg_ns_per_run": null,
            "bytes_jited": 707,
            "bytes_xlated": 1136,
            "id": 16,
            "name": "perf_unwind_beam",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "17": {
            "avg_ns_per_run": 1436.6666666666667,
            "bytes_jited": 722,
            "bytes_xlated": 1232,
            "id": 17,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 4310,
            "type": "tracepoint"
          },
          "18": {
            "avg_ns_per_run": 1054.6651785714287,
            "bytes_jited": 3569,
            "bytes_xlated": 5656,
            "id": 18,
            "name": "native_tracer_entry",
            "run_cnt_delta": 224,
            "run_time_ns_delta": 236245,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 0.6889903670000024,
            "ops_per_sec": 2910.0551996541817,
            "ops_total": 2005.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [2090] setting to a 5 secs run per stressor\nstress-ng: info:  [2090] dispatching hogs: 1 cpu\nstress-ng: info:  [2090] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2090] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2090]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2090] cpu                2005      0.68      0.68      0.00      2958.92        2959.06\nstress-ng: info:  [2090] skipped: 0\nstress-ng: info:  [2090] passed: 1: cpu (1)\nstress-ng: info:  [2090] failed: 0\nstress-ng: info:  [2090] metrics untrustworthy: 0\nstress-ng: info:  [2090] successful run completed in 0.68 secs"
          }
        ]
      },
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
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 13,
          "not_applied": 0,
          "requested": 13
        }
      },
      "runner": "otelcol-ebpf-profiler",
      "selected_workload": "stress_ng_cpu",
      "status": "ok"
    },
    {
      "app": "tetragon/observer",
      "baseline": {
        "bpf": {
          "34": {
            "avg_ns_per_run": 1003.581308411215,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 34,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1070,
            "run_time_ns_delta": 1073832,
            "type": "kprobe"
          },
          "36": {
            "avg_ns_per_run": 1511.2574074074073,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 36,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1080,
            "run_time_ns_delta": 1632158,
            "type": "kprobe"
          },
          "37": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 37,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "38": {
            "avg_ns_per_run": 6944.857142857143,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 38,
            "name": "event_execve",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 145842,
            "type": "tracepoint"
          },
          "39": {
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 39,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "40": {
            "avg_ns_per_run": 718.047619047619,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 40,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 15079,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 41,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "44": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 44,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "45": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 45,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "46": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 46,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "47": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 47,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "48": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 48,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "49": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 49,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "50": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 50,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "51": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 51,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "52": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 52,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "53": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 53,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "54": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 54,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "55": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 55,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "56": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 56,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "57": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 57,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "58": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 58,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "59": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 59,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "60": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 60,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "61": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 61,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "62": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 62,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "63": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 63,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "64": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 64,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "65": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 65,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "66": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 66,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "67": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 67,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "68": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 68,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "69": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 69,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "70": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 70,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "71": {
            "avg_ns_per_run": 668.8997521964407,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 71,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8878,
            "run_time_ns_delta": 5938492,
            "type": "kprobe"
          },
          "72": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 72,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "73": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 73,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "74": {
            "avg_ns_per_run": 306.4827663888263,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 74,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 8878,
            "run_time_ns_delta": 2720954,
            "type": "kprobe"
          },
          "75": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 75,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "76": {
            "avg_ns_per_run": 982.670327707831,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 76,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 11199,
            "run_time_ns_delta": 11004925,
            "type": "kprobe"
          },
          "77": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 77,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "78": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 78,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "79": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 79,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "80": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 80,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "81": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 81,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "82": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 82,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "83": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 83,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "84": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 84,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "85": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 85,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "86": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 86,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "87": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 87,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "88": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 88,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "89": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 89,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "90": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 90,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "91": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 91,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "92": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 92,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "93": {
            "avg_ns_per_run": 632.2298941202973,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 93,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8878,
            "run_time_ns_delta": 5612937,
            "type": "kprobe"
          },
          "94": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 94,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "95": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 95,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "96": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 96,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "97": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 97,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "98": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 98,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "99": {
            "avg_ns_per_run": 316.211872043253,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 99,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 8878,
            "run_time_ns_delta": 2807329,
            "type": "kprobe"
          },
          "100": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 100,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "101": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 101,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "102": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 102,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "103": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 103,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "104": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 104,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "105": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 105,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "106": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 106,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "107": {
            "avg_ns_per_run": 1005.3426198767747,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 107,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 11199,
            "run_time_ns_delta": 11258832,
            "type": "kprobe"
          },
          "108": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 108,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "109": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 109,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "110": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 110,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "111": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 111,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "112": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 112,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "113": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 113,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "114": {
            "avg_ns_per_run": 440.4306235987711,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 114,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 72258,
            "run_time_ns_delta": 31824636,
            "type": "kprobe"
          },
          "115": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 115,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "116": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 116,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "117": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 117,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "118": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 118,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "119": {
            "avg_ns_per_run": 456.2841151242144,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 119,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 74146,
            "run_time_ns_delta": 33831642,
            "type": "kprobe"
          },
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 120,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "121": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 121,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "122": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 122,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "123": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 123,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "124": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 124,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 125,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "126": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 126,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "127": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 127,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 128,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 129,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "130": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 130,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "131": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 131,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "132": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 132,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "133": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 133,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "134": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 134,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "135": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 135,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "136": {
            "avg_ns_per_run": 217.71482673364468,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 136,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 50962,
            "run_time_ns_delta": 11095183,
            "type": "kprobe"
          },
          "137": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 137,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "138": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 138,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "139": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 139,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "140": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 140,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "141": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 141,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "142": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 142,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "143": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 143,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "144": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 144,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "145": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 145,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "146": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 146,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "147": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 147,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "148": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 148,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "149": {
            "avg_ns_per_run": 648.3015771119246,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 149,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 57637,
            "run_time_ns_delta": 37366158,
            "type": "kprobe"
          },
          "150": {
            "avg_ns_per_run": 46.3041622568836,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 150,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 57637,
            "run_time_ns_delta": 2668833,
            "type": "kprobe"
          },
          "151": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 151,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "152": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 152,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "153": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 153,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "154": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 154,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "155": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 155,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "156": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 156,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "157": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 157,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "158": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 158,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "159": {
            "avg_ns_per_run": 3217.7519217330537,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 159,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4293,
            "run_time_ns_delta": 13813809,
            "type": "kprobe"
          },
          "160": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 160,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "161": {
            "avg_ns_per_run": 70.93920335429769,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 161,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 4293,
            "run_time_ns_delta": 304542,
            "type": "kprobe"
          },
          "162": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 162,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "163": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 163,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "164": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 164,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "165": {
            "avg_ns_per_run": 7187.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 165,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 7187,
            "type": "kprobe"
          },
          "166": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 166,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "167": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 167,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "168": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 168,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "169": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 169,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "170": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 170,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "171": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 171,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "172": {
            "avg_ns_per_run": 523.0,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 172,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 523,
            "type": "kprobe"
          },
          "173": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 173,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "174": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 174,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "175": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 175,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "176": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 176,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "177": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 177,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "178": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 178,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "179": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 179,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "180": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 180,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "181": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 181,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "182": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 182,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "183": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 183,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "184": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 184,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "185": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 185,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 186,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "187": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 187,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "188": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 188,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 189,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "190": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 190,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "191": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 191,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "192": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 192,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "193": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 193,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "194": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 194,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "195": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 195,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "196": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 196,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "197": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 197,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "198": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 198,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "199": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 199,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 200,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 201,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "202": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 202,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "203": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 203,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "204": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 204,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "205": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 205,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "206": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 206,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "207": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 207,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "208": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 208,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "209": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 209,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "210": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 210,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "211": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 211,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "212": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 212,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 213,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 214,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 215,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "216": {
            "avg_ns_per_run": 5715.619047619048,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 216,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 120028,
            "type": "kprobe"
          },
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 217,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 218,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 219,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 220,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 221,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 222,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "223": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 223,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "224": {
            "avg_ns_per_run": 592.2146881174024,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 224,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 7361488,
            "run_time_ns_delta": 4359581320,
            "type": "tracepoint"
          },
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 225,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "226": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 226,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "227": {
            "avg_ns_per_run": 5042.619047619048,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 227,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 105895,
            "type": "raw_tracepoint"
          },
          "228": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 228,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 229,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "230": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 230,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "231": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 231,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "232": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 232,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "233": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 233,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "234": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 234,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "235": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 235,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "236": {
            "avg_ns_per_run": 868.0204894706886,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 236,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3514,
            "run_time_ns_delta": 3050224,
            "type": "kprobe"
          },
          "237": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 237,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "238": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 238,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "239": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 239,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "240": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 240,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "241": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 241,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "242": {
            "avg_ns_per_run": 3949.008869179601,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 242,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1804,
            "run_time_ns_delta": 7124012,
            "type": "kprobe"
          },
          "243": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 243,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "244": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 244,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "245": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 245,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "246": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 246,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "247": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 247,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "248": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 248,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "249": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 249,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "250": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 250,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "251": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 251,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "252": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 252,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "253": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 253,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "254": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 254,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "255": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 255,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "256": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 256,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "257": {
            "avg_ns_per_run": 666.0972065780581,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 257,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8878,
            "run_time_ns_delta": 5913611,
            "type": "kprobe"
          },
          "258": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 258,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "259": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 259,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "260": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 260,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "261": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 261,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "avg_ns_per_run": 323.4749943681009,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 262,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 8878,
            "run_time_ns_delta": 2871811,
            "type": "kprobe"
          },
          "263": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 263,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "264": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 264,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "265": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 265,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 266,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "267": {
            "avg_ns_per_run": 1045.8222162693098,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 267,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 11199,
            "run_time_ns_delta": 11712163,
            "type": "kprobe"
          },
          "268": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 268,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 269,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 270,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 271,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "avg_ns_per_run": 4469.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 272,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 35752,
            "type": "kprobe"
          },
          "273": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 273,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "274": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 274,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "275": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 275,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 276,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "277": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 277,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 278,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 279,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 280,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 281,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "282": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 282,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 283,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "avg_ns_per_run": 3388.6666666666665,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 284,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 10166,
            "type": "kprobe"
          },
          "285": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 285,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 286,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": 13307.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 287,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 13307,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 288,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 289,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 290,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 291,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 292,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 293,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "avg_ns_per_run": 9428.0,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 294,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 9428,
            "type": "kprobe"
          },
          "295": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 295,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 296,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "297": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 297,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 298,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 299,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 300,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 301,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": 16927.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 302,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 16927,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 303,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 304,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": 3753.3333333333335,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 305,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 11260,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 306,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 307,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "308": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 308,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "309": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 309,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "310": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 310,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "311": {
            "avg_ns_per_run": 616.2482387475538,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 311,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 102200,
            "run_time_ns_delta": 62980570,
            "type": "kprobe"
          },
          "312": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 312,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 313,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "314": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 314,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "315": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 315,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "316": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 316,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 317,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 318,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 319,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "320": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 320,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "321": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 321,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 322,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "323": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 323,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 4.586187034000005,
            "ops_per_sec": 2413.3337602558813,
            "ops_total": 11068.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [4351]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4351] sockdiag           1025      0.00      0.00      0.00   2531897.29     1229016.79\nstress-ng: info:  [4351] skipped: 0\nstress-ng: info:  [4351] passed: 1: sockdiag (1)\nstress-ng: info:  [4351] failed: 0\nstress-ng: info:  [4351] metrics untrustworthy: 0\nstress-ng: info:  [4351] successful run completed in 0.00 secs\nstress-ng: info:  [4353] setting to a 1 secs run per stressor\nstress-ng: info:  [4353] dispatching hogs: 1 sockfd\nstress-ng: info:  [4353] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4353] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4353]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4353] sockfd              200      0.00      0.00      0.00    108985.42       71839.08\nstress-ng: info:  [4353] skipped: 0\nstress-ng: info:  [4353] passed: 1: sockfd (1)\nstress-ng: info:  [4353] failed: 0\nstress-ng: info:  [4353] metrics untrustworthy: 0\nstress-ng: info:  [4353] successful run completed in 0.00 secs\nstress-ng: info:  [4356] setting to a 1 secs run per stressor\nstress-ng: info:  [4356] dispatching hogs: 1 sockpair\nstress-ng: info:  [4356] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4356] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4356]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4356] sockpair            500      0.04      0.00      0.05     12106.03       10375.81\nstress-ng: info:  [4356] skipped: 0\nstress-ng: info:  [4356] passed: 1: sockpair (1)\nstress-ng: info:  [4356] failed: 0\nstress-ng: info:  [4356] metrics untrustworthy: 0\nstress-ng: info:  [4356] successful run completed in 0.04 secs\nstress-ng: info:  [4360] setting to a 1 secs run per stressor\nstress-ng: info:  [4360] dispatching hogs: 1 udp-flood\nstress-ng: info:  [4360] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4360] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4360]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4360] udp-flood          1000      0.00      0.00      0.00    210610.29      207900.21\nstress-ng: info:  [4360] skipped: 0\nstress-ng: info:  [4360] passed: 1: udp-flood (1)\nstress-ng: info:  [4360] failed: 0\nstress-ng: info:  [4360] metrics untrustworthy: 0\nstress-ng: info:  [4360] successful run completed in 0.01 secs"
          }
        ]
      },
      "error": "stress_ng_os_io_network workload stressor aio failed: stress-ng: info:  [6296] setting to a 1 secs run per stressor\nstress-ng: info:  [6296] dispatching hogs: 1 aio\nstress-ng: info:  [6296] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: fail:  [6297] aio: mkdir '/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/tmp-stress-ng-aio-6297-0' failed, errno=30 (Read-only file system)\nstress-ng: error: [6296] aio: [6297] terminated with an error, exit status=2 (stressor failed)\nstress-ng: metrc: [6296] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6296]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: info:  [6296] skipped: 0\nstress-ng: info:  [6296] passed: 0\nstress-ng: info:  [6296] failed: 1: aio (1)\nstress-ng: info:  [6296] metrics untrustworthy: 0\nstress-ng: info:  [6296] unsuccessful run completed in 0.00 secs",
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
        "error": "prog 37: prog 37 pass prefetch failed after 11 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @844\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 0\n      2: ......67.. (63) *(u32 *)(r10 -88) = r7\n      3: ......67.. (bf) r2 = r10\n      4: ..2...67.. (07) r2 += -88\n      5: ..2...67.. (18) r1 = 0xffff8ed249f1a400\n      7: .12...67.. (85) call bpf_map_lookup_elem#1\n      8: 0.....67.. (15) if r0 == 0x0 goto pc+821\n      9: 0.....67.. (7b) *(u64 *)(r10 -120) = r6\n     10: 0......7.. (bf) r8 = r0\n     11: 0......78. (bf) r6 = r0\n     12: ......678. (85) call bpf_get_current_task#35\n     13: 0.....678. (b7) r1 = 2680\n     14: 01....678. (0f) r0 += r1\n     15: 0.....678. (bf) r1 = r10\n     16: 01....678. (07) r1 += -72\n     17: 01....678. (b7) r2 = 8\n     18: 012...678. (bf) r3 = r0\n     19: .123..678. (85) call bpf_probe_read#4\n     20: ......678. (b7) r1 = 1448\n     21: .1....678. (79) r3 = *(u64 *)(r10 -72)\n     22: .1.3..678. (0f) r3 += r1\n     23: ...3..678. (bf) r1 = r10\n     24: .1.3..678. (07) r1 += -64\n     25: .1.3..678. (b7) r2 = 8\n     26: .123..678. (85) call bpf_probe_read#4\n     27: ......678. (79) r9 = *(u64 *)(r10 -64)\n     28: ......6789 (63) *(u32 *)(r10 -84) = r7\n     29: ......6.89 (bf) r2 = r10\n     30: ..2...6.89 (07) r2 += -84\n     31: ..2...6.89 (18) r1 = 0xffff8ed257092000\n     33: .12...6.89 (85) call bpf_map_lookup_elem#1\n     34: 0.....6.89 (7b) *(u64 *)(r10 -104) = r6\n     35: 0.....6.89 (07) r6 += 5808\n     36: 0.....6.89 (7b) *(u64 *)(r10 -112) = r6\n     37: 0.......89 (bf) r2 = r8\n     38: 0.2.....89 (7b) *(u64 *)(r10 -96) = r8\n     39: 0.2......9 (bf) r8 = r0\n     40: ..2.....89 (55) if r8 != 0x0 goto pc+1\n     41: .......... (05) goto pc+254\n     42: ..2.....89 (b7) r1 = 64\n     43: .12.....89 (0f) r9 += r1\n     44: ..2.....89 (b7) r1 = 4096\n     45: .12.....89 (63) *(u32 *)(r2 +6192) = r1\n     46: ........89 (85) call bpf_get_current_task#35\n     47: 0.......89 (b7) r1 = 3408\n     48: 01......89 (0f) r0 += r1\n     49: 0.......89 (bf) r1 = r10\n     50: 01......89 (07) r1 += -80\n     51: 01......89 (b7) r2 = 8\n     52: 012.....89 (bf) r3 = r0\n     53: .123....89 (85) call bpf_probe_read#4\n     54: ........89 (b7) r1 = 8\n     55: .1......89 (7b) *(u64 *)(r10 -128) = r9\n     56: .1......89 (0f) r9 += r1\n     57: ........89 (79) r7 = *(u64 *)(r10 -80)\n     58: .......789 (bf) r1 = r10\n     59: .1.....789 (07) r1 += -72\n     60: .1.....789 (b7) r2 = 8\n     61: .12....789 (7b) *(u64 *)(r10 -136) = r9\n     62: .12....789 (bf) r3 = r9\n     63: .123...78. (85) call bpf_probe_read#4\n     64: .......78. (b7) r1 = 8\n     65: .1.....78. (79) r6 = *(u64 *)(r10 -72)\n     66: .1....678. (bf) r3 = r6\n     67: .1.3..678. (0f) r3 += r1\n     68: ...3..678. (b7) r1 = 8\n     69: .1.3..678. (0f) r3 += r1\n     70: ...3..678. (bf) r1 = r10\n     71: .1.3..678. (07) r1 += -64\n     72: .1.3..678. (b7) r2 = 8\n     73: .123..678. (85) call bpf_probe_read#4\n     74: ......678. (79) r3 = *(u64 *)(r10 -96)\n     75: ...3..678. (bf) r9 = r8\n     76: ...3..6789 (07) r9 += 4096\n     77: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     78: .1.3..6789 (55) if r1 != 0x0 goto pc+41\n     79: ......6789 (b7) r1 = 24\n     80: .1....6789 (bf) r3 = r6\n     81: .1.3..6789 (0f) r3 += r1\n     82: ...3..6789 (bf) r1 = r10\n     83: .1.3..6789 (07) r1 += -64\n     84: .1.3..6789 (b7) r2 = 8\n     85: .123..6789 (85) call bpf_probe_read#4\n     86: ......6789 (79) r3 = *(u64 *)(r10 -96)\n     87: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     88: .1.3..6789 (1d) if r1 == r6 goto pc+31\n     89: ...3...789 (61) r1 = *(u32 *)(r3 +6192)\n     90: .1.3...789 (bf) r2 = r1\n     91: .123...789 (07) r2 += -10\n     92: .123...789 (63) *(u32 *)(r3 +6192) = r2\n     93: .123...789 (67) r1 <<= 32\n     94: .123...789 (c7) r1 s>>= 32\n     95: .123...789 (65) if r1 s> 0x9 goto pc+5\n     96: ..23.....9 (18) r1 = 0xffffffdc\n     98: .123.....9 (63) *(u32 *)(r3 +6196) = r1\n     99: ..2......9 (bf) r7 = r9\n    100: ..2....7.. (05) goto pc+93\n    101: ...3...78. (b7) r1 = 41\n    102: .1.3...78. (73) *(u8 *)(r8 +4095) = r1\n    103: ...3...78. (b7) r1 = 116\n    104: .1.3...78. (73) *(u8 *)(r8 +4092) = r1\n    105: ...3\n... verifier log truncated ...; prog 38: prog 38 pass prefetch failed after 11 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @1724\nfunc#2 @1840\nfunc#3 @2033\nfunc#4 @2208\nfunc#5 @2277\nfunc#6 @2300\nfunc#7 @2370\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (85) call bpf_get_current_task#35\n      2: 0.....6... (bf) r9 = r0\n      3: ......6..9 (7b) *(u64 *)(r10 -128) = r6\n      4: ......6..9 (61) r6 = *(u32 *)(r6 +8)\n      5: ......6..9 (b7) r1 = 0\n      6: .1....6..9 (63) *(u32 *)(r10 -120) = r1\n      7: ......6..9 (bf) r2 = r10\n      8: ..2...6..9 (07) r2 += -120\n      9: ..2...6..9 (18) r1 = 0xffff8ed249f1a400\n     11: .12...6..9 (85) call bpf_map_lookup_elem#1\n     12: 0.....6..9 (bf) r7 = r0\n     13: ......67.9 (15) if r7 == 0x0 goto pc+1689\n     14: ......67.9 (7b) *(u64 *)(r10 -144) = r6\n     15: .......7.9 (85) call bpf_get_current_pid_tgid#14\n     16: 0......7.9 (bf) r6 = r0\n     17: ......67.9 (85) call bpf_get_current_task#35\n     18: 0.....67.9 (7b) *(u64 *)(r10 -96) = r0\n     19: 0.....67.9 (b7) r8 = 2816\n     20: 0.....6789 (0f) r0 += r8\n     21: 0.....6789 (bf) r1 = r10\n     22: 01....6789 (07) r1 += -96\n     23: 01....6789 (b7) r2 = 8\n     24: 012...6789 (bf) r3 = r0\n     25: .123..6789 (85) call bpf_probe_read_kernel#113\n     26: ......6789 (7b) *(u64 *)(r10 -160) = r6\n     27: ......6789 (7b) *(u64 *)(r10 -152) = r6\n     28: .......789 (79) r3 = *(u64 *)(r10 -96)\n     29: ...3...789 (7b) *(u64 *)(r10 -136) = r9\n     30: ...3...789 (15) if r3 == 0x0 goto pc+162\n     31: ...3...789 (b7) r1 = 2804\n     32: .1.3...789 (0f) r3 += r1\n     33: ...3...789 (bf) r1 = r10\n     34: .1.3...789 (07) r1 += -8\n     35: .1.3...789 (b7) r2 = 4\n     36: .123...789 (85) call bpf_probe_read_kernel#113\n     37: .......789 (61) r1 = *(u32 *)(r10 -8)\n     38: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     39: .......789 (bf) r2 = r10\n     40: ..2....789 (07) r2 += -112\n     41: ..2....789 (18) r1 = 0xffff8ed1c5826000\n     43: .12....789 (85) call bpf_map_lookup_elem#1\n     44: 0......789 (bf) r6 = r0\n     45: ......6789 (15) if r6 == 0x0 goto pc+3\n     46: ......6789 (05) goto pc+0\n     47: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     48: .1....6789 (55) if r1 != 0x0 goto pc+81\n     49: .......789 (b7) r1 = 2816\n     50: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     51: .1.3...789 (0f) r3 += r1\n     52: ...3...789 (bf) r1 = r10\n     53: .1.3...789 (07) r1 += -96\n     54: .1.3...789 (b7) r2 = 8\n     55: .123...789 (85) call bpf_probe_read_kernel#113\n     56: .......789 (79) r3 = *(u64 *)(r10 -96)\n     57: ...3...789 (15) if r3 == 0x0 goto pc+135\n     58: ...3...789 (b7) r1 = 2804\n     59: .1.3...789 (0f) r3 += r1\n     60: ...3...789 (bf) r1 = r10\n     61: .1.3...789 (07) r1 += -8\n     62: .1.3...789 (b7) r2 = 4\n     63: .123...789 (85) call bpf_probe_read_kernel#113\n     64: .......789 (61) r1 = *(u32 *)(r10 -8)\n     65: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     66: .......789 (bf) r2 = r10\n     67: ..2....789 (07) r2 += -112\n     68: ..2....789 (18) r1 = 0xffff8ed1c5826000\n     70: .12....789 (85) call bpf_map_lookup_elem#1\n     71: 0......789 (bf) r6 = r0\n     72: ......6789 (15) if r6 == 0x0 goto pc+3\n     73: ......6789 (05) goto pc+0\n     74: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     75: .1....6789 (55) if r1 != 0x0 goto pc+54\n     76: .......789 (b7) r1 = 2816\n     77: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     78: .1.3...789 (0f) r3 += r1\n     79: ...3...789 (bf) r1 = r10\n     80: .1.3...789 (07) r1 += -96\n     81: .1.3...789 (b7) r2 = 8\n     82: .123...789 (85) call bpf_probe_read_kernel#113\n     83: .......789 (79) r3 = *(u64 *)(r10 -96)\n     84: ...3...789 (15) if r3 == 0x0 goto pc+108\n     85: ...3...789 (b7) r1 = 2804\n     86: .1.3...789 (0f) r3 += r1\n     87: ...3...789 (bf) r1 = r10\n     88: .1.3...789 (07) r1 += -8\n     89: .1.3...789 (b7) r2 = 4\n     90: .123...789 (85) call bpf_probe_read_kernel#113\n     91: .......789 (61) r1 = *(u32 *)(r10 -8)\n     92: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     93: .......789 (bf) r2 = r10\n     94: ..2....789 (07) r2 += -112\n     95: ..2....789 (18) r1 = 0xffff8ed1c5826000\n     97: .12....789 (85) call bpf_map_lookup_elem#1\n     98: 0......789 (bf) r6 = r0\n\n... verifier log truncated ...; prog 45: prog 45 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 49: write /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-88/opt.bin: Read-only file system (os error 30); prog 50: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-235: Read-only file system (os error 30); prog 51: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-218: Read-only file system (os error 30); prog 52: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-219: Read-only file system (os error 30); prog 53: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-220: Read-only file system (os error 30); prog 59: prog 59 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 64: write verifier states after pass bulk_memory: Read-only file system (os error 30); prog 66: prog 66 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 69: write verifier states after pass skb_load_bytes_spec: Read-only file system (os error 30); prog 70: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-189: Read-only file system (os error 30); prog 71: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-190: Read-only file system (os error 30); prog 72: prog 72 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 77: prog 77 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 78: write verifier states after pass map_inline: Read-only file system (os error 30); prog 79: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-251: Read-only file system (os error 30); prog 80: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-252: Read-only file system (os error 30); prog 81: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-242: Read-only file system (os error 30); prog 82: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-243: Read-only file system (os error 30); prog 83: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-244: Read-only file system (os error 30); prog 84: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-245: Read-only file system (os error 30); prog 85: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-246: Read-only file system (os error 30); prog 86: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-247: Read-only file system (os error 30); prog 87: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-248: Read-only file system (os error 30); prog 88: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-249: Read-only file system (os error 30); prog 89: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-250: Read-only file system (os error 30); prog 92: prog 92 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 96: write verifier states after pass cond_select: Read-only file system (os error 30); prog 97: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-178: Read-only file system (os error 30); prog 98: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-179: Read-only file system (os error 30); prog 100: prog 100 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 102: write verifier states after pass skb_load_bytes_spec: Read-only file system (os error 30); prog 104: prog 104 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 110: write verifier states after pass bulk_memory: Read-only file system (os error 30); prog 111: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-236: Read-only file system (os error 30); prog 112: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-191: Read-only file system (os error 30); prog 113: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-192: Read-only file system (os error 30); prog 114: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-193: Read-only file system (os error 30); prog 115: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-194: Read-only file system (os error 30); prog 116: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-195: Read-only file system (os error 30); prog 117: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-180: Read-only file system (os error 30); prog 118: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-181: Read-only file system (os error 30); prog 119: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-182: Read-only file system (os error 30); prog 120: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-183: Read-only file system (os error 30); prog 121: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-184: Read-only file system (os error 30); prog 122: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-185: Read-only file system (os error 30); prog 123: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-186: Read-only file system (os error 30); prog 124: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-187: Read-only file system (os error 30); prog 125: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-188: Read-only file system (os error 30); prog 126: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-151: Read-only file system (os error 30); prog 127: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-152: Read-only file system (os error 30); prog 128: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-153: Read-only file system (os error 30); prog 129: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-154: Read-only file system (os error 30); prog 130: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-155: Read-only file system (os error 30); prog 131: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-156: Read-only file system (os error 30); prog 132: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-157: Read-only file system (os error 30); prog 133: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-158: Read-only file system (os error 30); prog 134: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-159: Read-only file system (os error 30); prog 135: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-160: Read-only file system (os error 30); prog 136: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-161: Read-only file system (os error 30); prog 137: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-162: Read-only file system (os error 30); prog 138: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-163: Read-only file system (os error 30); prog 139: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-164: Read-only file system (os error 30); prog 140: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-165: Read-only file system (os error 30); prog 141: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-166: Read-only file system (os error 30); prog 142: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-167: Read-only file system (os error 30); prog 143: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-168: Read-only file system (os error 30); prog 145: write verifier states after pass bulk_memory: Read-only file system (os error 30); prog 146: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-286: Read-only file system (os error 30); prog 147: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-287: Read-only file system (os error 30); prog 148: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-237: Read-only file system (os error 30); prog 149: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-238: Read-only file system (os error 30); prog 150: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-239: Read-only file system (os error 30); prog 151: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-240: Read-only file system (os error 30); prog 152: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-241: Read-only file system (os error 30); prog 153: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-226: Read-only file system (os error 30); prog 154: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-227: Read-only file system (os error 30); prog 155: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-228: Read-only file system (os error 30); prog 156: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-229: Read-only file system (os error 30); prog 157: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-230: Read-only file system (os error 30); prog 158: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-231: Read-only file system (os error 30); prog 159: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-232: Read-only file system (os error 30); prog 160: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-233: Read-only file system (os error 30); prog 161: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-234: Read-only file system (os error 30); prog 162: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-110: Read-only file system (os error 30); prog 163: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-111: Read-only file system (os error 30); prog 164: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-112: Read-only file system (os error 30); prog 165: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-113: Read-only file system (os error 30); prog 166: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-114: Read-only file system (os error 30); prog 167: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-115: Read-only file system (os error 30); prog 168: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-116: Read-only file system (os error 30); prog 169: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-117: Read-only file system (os error 30); prog 170: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-118: Read-only file system (os error 30); prog 171: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-119: Read-only file system (os error 30); prog 172: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-120: Read-only file system (os error 30); prog 173: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-121: Read-only file system (os error 30); prog 174: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-122: Read-only file system (os error 30); prog 175: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-123: Read-only file system (os error 30); prog 176: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-124: Read-only file system (os error 30); prog 177: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-125: Read-only file system (os error 30); prog 178: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-126: Read-only file system (os error 30); prog 179: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-127: Read-only file system (os error 30); prog 181: prog 181 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 186: prog 186 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 188: prog 188 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 192: write verifier states after pass extract: Read-only file system (os error 30); prog 193: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-221: Read-only file system (os error 30); prog 194: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-222: Read-only file system (os error 30); prog 195: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-223: Read-only file system (os error 30); prog 196: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-224: Read-only file system (os error 30); prog 197: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-225: Read-only file system (os error 30); prog 200: prog 200 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 202: write verifier states after pass skb_load_bytes_spec: Read-only file system (os error 30); prog 203: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-299: Read-only file system (os error 30); prog 204: write verifier states after pass rotate: Read-only file system (os error 30); prog 205: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-108: Read-only file system (os error 30); prog 206: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-109: Read-only file system (os error 30); prog 208: prog 208 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 210: write verifier states after pass dce: Read-only file system (os error 30); prog 211: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-128: Read-only file system (os error 30); prog 212: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-129: Read-only file system (os error 30); prog 213: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-130: Read-only file system (os error 30); prog 214: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-131: Read-only file system (os error 30); prog 215: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-132: Read-only file system (os error 30); prog 219: write verifier states after pass skb_load_bytes_spec: Read-only file system (os error 30); prog 220: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-294: Read-only file system (os error 30); prog 221: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-295: Read-only file system (os error 30); prog 222: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-296: Read-only file system (os error 30); prog 223: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-297: Read-only file system (os error 30); prog 224: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-298: Read-only file system (os error 30); prog 225: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-262: Read-only file system (os error 30); prog 226: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-263: Read-only file system (os error 30); prog 227: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-264: Read-only file system (os error 30); prog 228: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-265: Read-only file system (os error 30); prog 229: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-266: Read-only file system (os error 30); prog 230: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-267: Read-only file system (os error 30); prog 231: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-268: Read-only file system (os error 30); prog 232: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-269: Read-only file system (os error 30); prog 233: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-270: Read-only file system (os error 30); prog 237: prog 237 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 238: write /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-102/opt.bin: Read-only file system (os error 30); prog 239: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-217: Read-only file system (os error 30); prog 240: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-196: Read-only file system (os error 30); prog 241: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-197: Read-only file system (os error 30); prog 242: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-198: Read-only file system (os error 30); prog 243: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-169: Read-only file system (os error 30); prog 244: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-170: Read-only file system (os error 30); prog 245: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-171: Read-only file system (os error 30); prog 246: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-172: Read-only file system (os error 30); prog 247: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-173: Read-only file system (os error 30); prog 248: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-174: Read-only file system (os error 30); prog 249: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-175: Read-only file system (os error 30); prog 250: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-176: Read-only file system (os error 30); prog 251: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-177: Read-only file system (os error 30); prog 254: write /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-52/opt.bin: Read-only file system (os error 30); prog 255: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-293: Read-only file system (os error 30); prog 256: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-288: Read-only file system (os error 30); prog 257: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-289: Read-only file system (os error 30); prog 258: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-290: Read-only file system (os error 30); prog 259: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-291: Read-only file system (os error 30); prog 260: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-292: Read-only file system (os error 30); prog 261: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-253: Read-only file system (os error 30); prog 262: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-254: Read-only file system (os error 30); prog 263: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-255: Read-only file system (os error 30); prog 264: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-256: Read-only file system (os error 30); prog 265: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-257: Read-only file system (os error 30); prog 266: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-258: Read-only file system (os error 30); prog 267: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-259: Read-only file system (os error 30); prog 268: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-260: Read-only file system (os error 30); prog 269: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-261: Read-only file system (os error 30); prog 270: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-133: Read-only file system (os error 30); prog 271: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-134: Read-only file system (os error 30); prog 272: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-135: Read-only file system (os error 30); prog 273: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-136: Read-only file system (os error 30); prog 274: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-137: Read-only file system (os error 30); prog 275: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-138: Read-only file system (os error 30); prog 276: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-139: Read-only file system (os error 30); prog 277: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-140: Read-only file system (os error 30); prog 278: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-141: Read-only file system (os error 30); prog 279: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-142: Read-only file system (os error 30); prog 280: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-143: Read-only file system (os error 30); prog 281: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-144: Read-only file system (os error 30); prog 282: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-145: Read-only file system (os error 30); prog 283: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-146: Read-only file system (os error 30); prog 284: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-147: Read-only file system (os error 30); prog 285: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-148: Read-only file system (os error 30); prog 286: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-149: Read-only file system (os error 30); prog 287: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-150: Read-only file system (os error 30); prog 289: prog 289 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 290: write verifier states after pass rotate: Read-only file system (os error 30); prog 291: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-285: Read-only file system (os error 30); prog 292: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-280: Read-only file system (os error 30); prog 293: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-281: Read-only file system (os error 30); prog 294: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-282: Read-only file system (os error 30); prog 295: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-283: Read-only file system (os error 30); prog 296: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-284: Read-only file system (os error 30); prog 297: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-271: Read-only file system (os error 30); prog 298: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-272: Read-only file system (os error 30); prog 299: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-273: Read-only file system (os error 30); prog 300: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-274: Read-only file system (os error 30); prog 301: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-275: Read-only file system (os error 30); prog 302: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-276: Read-only file system (os error 30); prog 303: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-277: Read-only file system (os error 30); prog 304: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-278: Read-only file system (os error 30); prog 305: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-279: Read-only file system (os error 30); prog 306: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-199: Read-only file system (os error 30); prog 307: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-200: Read-only file system (os error 30); prog 308: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-201: Read-only file system (os error 30); prog 309: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-202: Read-only file system (os error 30); prog 310: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-203: Read-only file system (os error 30); prog 311: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-204: Read-only file system (os error 30); prog 312: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-205: Read-only file system (os error 30); prog 313: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-206: Read-only file system (os error 30); prog 314: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-207: Read-only file system (os error 30); prog 315: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-208: Read-only file system (os error 30); prog 316: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-209: Read-only file system (os error 30); prog 317: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-210: Read-only file system (os error 30); prog 318: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-211: Read-only file system (os error 30); prog 319: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-212: Read-only file system (os error 30); prog 320: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-213: Read-only file system (os error 30); prog 321: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-214: Read-only file system (os error 30); prog 322: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-215: Read-only file system (os error 30); prog 323: create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-216: Read-only file system (os error 30)",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 37 pass prefetch failed after 11 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @844\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 0\n      2: ......67.. (63) *(u32 *)(r10 -88) = r7\n      3: ......67.. (bf) r2 = r10\n      4: ..2...67.. (07) r2 += -88\n      5: ..2...67.. (18) r1 = 0xffff8ed249f1a400\n      7: .12...67.. (85) call bpf_map_lookup_elem#1\n      8: 0.....67.. (15) if r0 == 0x0 goto pc+821\n      9: 0.....67.. (7b) *(u64 *)(r10 -120) = r6\n     10: 0......7.. (bf) r8 = r0\n     11: 0......78. (bf) r6 = r0\n     12: ......678. (85) call bpf_get_current_task#35\n     13: 0.....678. (b7) r1 = 2680\n     14: 01....678. (0f) r0 += r1\n     15: 0.....678. (bf) r1 = r10\n     16: 01....678. (07) r1 += -72\n     17: 01....678. (b7) r2 = 8\n     18: 012...678. (bf) r3 = r0\n     19: .123..678. (85) call bpf_probe_read#4\n     20: ......678. (b7) r1 = 1448\n     21: .1....678. (79) r3 = *(u64 *)(r10 -72)\n     22: .1.3..678. (0f) r3 += r1\n     23: ...3..678. (bf) r1 = r10\n     24: .1.3..678. (07) r1 += -64\n     25: .1.3..678. (b7) r2 = 8\n     26: .123..678. (85) call bpf_probe_read#4\n     27: ......678. (79) r9 = *(u64 *)(r10 -64)\n     28: ......6789 (63) *(u32 *)(r10 -84) = r7\n     29: ......6.89 (bf) r2 = r10\n     30: ..2...6.89 (07) r2 += -84\n     31: ..2...6.89 (18) r1 = 0xffff8ed257092000\n     33: .12...6.89 (85) call bpf_map_lookup_elem#1\n     34: 0.....6.89 (7b) *(u64 *)(r10 -104) = r6\n     35: 0.....6.89 (07) r6 += 5808\n     36: 0.....6.89 (7b) *(u64 *)(r10 -112) = r6\n     37: 0.......89 (bf) r2 = r8\n     38: 0.2.....89 (7b) *(u64 *)(r10 -96) = r8\n     39: 0.2......9 (bf) r8 = r0\n     40: ..2.....89 (55) if r8 != 0x0 goto pc+1\n     41: .......... (05) goto pc+254\n     42: ..2.....89 (b7) r1 = 64\n     43: .12.....89 (0f) r9 += r1\n     44: ..2.....89 (b7) r1 = 4096\n     45: .12.....89 (63) *(u32 *)(r2 +6192) = r1\n     46: ........89 (85) call bpf_get_current_task#35\n     47: 0.......89 (b7) r1 = 3408\n     48: 01......89 (0f) r0 += r1\n     49: 0.......89 (bf) r1 = r10\n     50: 01......89 (07) r1 += -80\n     51: 01......89 (b7) r2 = 8\n     52: 012.....89 (bf) r3 = r0\n     53: .123....89 (85) call bpf_probe_read#4\n     54: ........89 (b7) r1 = 8\n     55: .1......89 (7b) *(u64 *)(r10 -128) = r9\n     56: .1......89 (0f) r9 += r1\n     57: ........89 (79) r7 = *(u64 *)(r10 -80)\n     58: .......789 (bf) r1 = r10\n     59: .1.....789 (07) r1 += -72\n     60: .1.....789 (b7) r2 = 8\n     61: .12....789 (7b) *(u64 *)(r10 -136) = r9\n     62: .12....789 (bf) r3 = r9\n     63: .123...78. (85) call bpf_probe_read#4\n     64: .......78. (b7) r1 = 8\n     65: .1.....78. (79) r6 = *(u64 *)(r10 -72)\n     66: .1....678. (bf) r3 = r6\n     67: .1.3..678. (0f) r3 += r1\n     68: ...3..678. (b7) r1 = 8\n     69: .1.3..678. (0f) r3 += r1\n     70: ...3..678. (bf) r1 = r10\n     71: .1.3..678. (07) r1 += -64\n     72: .1.3..678. (b7) r2 = 8\n     73: .123..678. (85) call bpf_probe_read#4\n     74: ......678. (79) r3 = *(u64 *)(r10 -96)\n     75: ...3..678. (bf) r9 = r8\n     76: ...3..6789 (07) r9 += 4096\n     77: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     78: .1.3..6789 (55) if r1 != 0x0 goto pc+41\n     79: ......6789 (b7) r1 = 24\n     80: .1....6789 (bf) r3 = r6\n     81: .1.3..6789 (0f) r3 += r1\n     82: ...3..6789 (bf) r1 = r10\n     83: .1.3..6789 (07) r1 += -64\n     84: .1.3..6789 (b7) r2 = 8\n     85: .123..6789 (85) call bpf_probe_read#4\n     86: ......6789 (79) r3 = *(u64 *)(r10 -96)\n     87: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     88: .1.3..6789 (1d) if r1 == r6 goto pc+31\n     89: ...3...789 (61) r1 = *(u32 *)(r3 +6192)\n     90: .1.3...789 (bf) r2 = r1\n     91: .123...789 (07) r2 += -10\n     92: .123...789 (63) *(u32 *)(r3 +6192) = r2\n     93: .123...789 (67) r1 <<= 32\n     94: .123...789 (c7) r1 s>>= 32\n     95: .123...789 (65) if r1 s> 0x9 goto pc+5\n     96: ..23.....9 (18) r1 = 0xffffffdc\n     98: .123.....9 (63) *(u32 *)(r3 +6196) = r1\n     99: ..2......9 (bf) r7 = r9\n    100: ..2....7.. (05) goto pc+93\n    101: ...3...78. (b7) r1 = 41\n    102: .1.3...78. (73) *(u8 *)(r8 +4095) = r1\n    103: ...3...78. (b7) r1 = 116\n    104: .1.3...78. (73) *(u8 *)(r8 +4092) = r1\n    105: ...3\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 37
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 38 pass prefetch failed after 11 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @1724\nfunc#2 @1840\nfunc#3 @2033\nfunc#4 @2208\nfunc#5 @2277\nfunc#6 @2300\nfunc#7 @2370\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (85) call bpf_get_current_task#35\n      2: 0.....6... (bf) r9 = r0\n      3: ......6..9 (7b) *(u64 *)(r10 -128) = r6\n      4: ......6..9 (61) r6 = *(u32 *)(r6 +8)\n      5: ......6..9 (b7) r1 = 0\n      6: .1....6..9 (63) *(u32 *)(r10 -120) = r1\n      7: ......6..9 (bf) r2 = r10\n      8: ..2...6..9 (07) r2 += -120\n      9: ..2...6..9 (18) r1 = 0xffff8ed249f1a400\n     11: .12...6..9 (85) call bpf_map_lookup_elem#1\n     12: 0.....6..9 (bf) r7 = r0\n     13: ......67.9 (15) if r7 == 0x0 goto pc+1689\n     14: ......67.9 (7b) *(u64 *)(r10 -144) = r6\n     15: .......7.9 (85) call bpf_get_current_pid_tgid#14\n     16: 0......7.9 (bf) r6 = r0\n     17: ......67.9 (85) call bpf_get_current_task#35\n     18: 0.....67.9 (7b) *(u64 *)(r10 -96) = r0\n     19: 0.....67.9 (b7) r8 = 2816\n     20: 0.....6789 (0f) r0 += r8\n     21: 0.....6789 (bf) r1 = r10\n     22: 01....6789 (07) r1 += -96\n     23: 01....6789 (b7) r2 = 8\n     24: 012...6789 (bf) r3 = r0\n     25: .123..6789 (85) call bpf_probe_read_kernel#113\n     26: ......6789 (7b) *(u64 *)(r10 -160) = r6\n     27: ......6789 (7b) *(u64 *)(r10 -152) = r6\n     28: .......789 (79) r3 = *(u64 *)(r10 -96)\n     29: ...3...789 (7b) *(u64 *)(r10 -136) = r9\n     30: ...3...789 (15) if r3 == 0x0 goto pc+162\n     31: ...3...789 (b7) r1 = 2804\n     32: .1.3...789 (0f) r3 += r1\n     33: ...3...789 (bf) r1 = r10\n     34: .1.3...789 (07) r1 += -8\n     35: .1.3...789 (b7) r2 = 4\n     36: .123...789 (85) call bpf_probe_read_kernel#113\n     37: .......789 (61) r1 = *(u32 *)(r10 -8)\n     38: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     39: .......789 (bf) r2 = r10\n     40: ..2....789 (07) r2 += -112\n     41: ..2....789 (18) r1 = 0xffff8ed1c5826000\n     43: .12....789 (85) call bpf_map_lookup_elem#1\n     44: 0......789 (bf) r6 = r0\n     45: ......6789 (15) if r6 == 0x0 goto pc+3\n     46: ......6789 (05) goto pc+0\n     47: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     48: .1....6789 (55) if r1 != 0x0 goto pc+81\n     49: .......789 (b7) r1 = 2816\n     50: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     51: .1.3...789 (0f) r3 += r1\n     52: ...3...789 (bf) r1 = r10\n     53: .1.3...789 (07) r1 += -96\n     54: .1.3...789 (b7) r2 = 8\n     55: .123...789 (85) call bpf_probe_read_kernel#113\n     56: .......789 (79) r3 = *(u64 *)(r10 -96)\n     57: ...3...789 (15) if r3 == 0x0 goto pc+135\n     58: ...3...789 (b7) r1 = 2804\n     59: .1.3...789 (0f) r3 += r1\n     60: ...3...789 (bf) r1 = r10\n     61: .1.3...789 (07) r1 += -8\n     62: .1.3...789 (b7) r2 = 4\n     63: .123...789 (85) call bpf_probe_read_kernel#113\n     64: .......789 (61) r1 = *(u32 *)(r10 -8)\n     65: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     66: .......789 (bf) r2 = r10\n     67: ..2....789 (07) r2 += -112\n     68: ..2....789 (18) r1 = 0xffff8ed1c5826000\n     70: .12....789 (85) call bpf_map_lookup_elem#1\n     71: 0......789 (bf) r6 = r0\n     72: ......6789 (15) if r6 == 0x0 goto pc+3\n     73: ......6789 (05) goto pc+0\n     74: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     75: .1....6789 (55) if r1 != 0x0 goto pc+54\n     76: .......789 (b7) r1 = 2816\n     77: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     78: .1.3...789 (0f) r3 += r1\n     79: ...3...789 (bf) r1 = r10\n     80: .1.3...789 (07) r1 += -96\n     81: .1.3...789 (b7) r2 = 8\n     82: .123...789 (85) call bpf_probe_read_kernel#113\n     83: .......789 (79) r3 = *(u64 *)(r10 -96)\n     84: ...3...789 (15) if r3 == 0x0 goto pc+108\n     85: ...3...789 (b7) r1 = 2804\n     86: .1.3...789 (0f) r3 += r1\n     87: ...3...789 (bf) r1 = r10\n     88: .1.3...789 (07) r1 += -8\n     89: .1.3...789 (b7) r2 = 4\n     90: .123...789 (85) call bpf_probe_read_kernel#113\n     91: .......789 (61) r1 = *(u32 *)(r10 -8)\n     92: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     93: .......789 (bf) r2 = r10\n     94: ..2....789 (07) r2 += -112\n     95: ..2....789 (18) r1 = 0xffff8ed1c5826000\n     97: .12....789 (85) call bpf_map_lookup_elem#1\n     98: 0......789 (bf) r6 = r0\n\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 38
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 45 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 45
          },
          {
            "applied": false,
            "changed": false,
            "error": "write /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-88/opt.bin: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 49
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-235: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 50
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-218: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 51
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-219: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 52
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-220: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 53
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 59 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 59
          },
          {
            "applied": false,
            "changed": false,
            "error": "write verifier states after pass bulk_memory: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 64
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 66 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 66
          },
          {
            "applied": false,
            "changed": false,
            "error": "write verifier states after pass skb_load_bytes_spec: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 69
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-189: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 70
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-190: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 71
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 72 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 72
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 77 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 77
          },
          {
            "applied": false,
            "changed": false,
            "error": "write verifier states after pass map_inline: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 78
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-251: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 79
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-252: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 80
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-242: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 81
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-243: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 82
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-244: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 83
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-245: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 84
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-246: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 85
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-247: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 86
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-248: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 87
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-249: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 88
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-250: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 89
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 92 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 92
          },
          {
            "applied": false,
            "changed": false,
            "error": "write verifier states after pass cond_select: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 96
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-178: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 97
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-179: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 98
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 100 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 100
          },
          {
            "applied": false,
            "changed": false,
            "error": "write verifier states after pass skb_load_bytes_spec: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 102
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 104 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 104
          },
          {
            "applied": false,
            "changed": false,
            "error": "write verifier states after pass bulk_memory: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 110
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-236: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 111
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-191: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 112
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-192: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 113
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-193: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 114
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-194: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 115
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-195: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 116
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-180: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 117
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-181: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 118
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-182: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 119
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-183: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 120
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-184: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 121
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-185: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 122
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-186: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 123
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-187: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 124
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-188: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 125
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-151: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 126
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-152: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 127
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-153: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 128
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-154: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 129
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-155: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 130
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-156: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 131
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-157: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 132
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-158: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 133
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-159: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 134
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-160: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 135
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-161: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 136
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-162: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 137
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-163: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 138
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-164: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 139
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-165: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 140
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-166: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 141
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-167: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 142
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-168: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 143
          },
          {
            "applied": false,
            "changed": false,
            "error": "write verifier states after pass bulk_memory: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 145
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-286: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 146
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-287: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 147
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-237: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 148
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-238: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 149
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-239: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 150
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-240: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 151
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-241: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 152
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-226: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 153
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-227: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 154
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-228: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 155
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-229: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 156
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-230: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 157
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-231: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 158
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-232: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 159
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-233: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 160
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-234: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 161
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-110: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 162
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-111: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 163
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-112: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 164
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-113: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 165
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-114: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 166
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-115: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 167
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-116: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 168
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-117: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 169
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-118: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 170
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-119: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 171
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-120: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 172
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-121: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 173
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-122: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 174
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-123: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 175
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-124: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 176
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-125: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 177
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-126: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 178
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-127: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 179
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 181 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 181
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 186 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 186
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 188 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 188
          },
          {
            "applied": false,
            "changed": false,
            "error": "write verifier states after pass extract: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 192
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-221: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 193
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-222: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 194
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-223: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 195
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-224: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 196
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-225: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 197
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 200 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 200
          },
          {
            "applied": false,
            "changed": false,
            "error": "write verifier states after pass skb_load_bytes_spec: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 202
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-299: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 203
          },
          {
            "applied": false,
            "changed": false,
            "error": "write verifier states after pass rotate: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 204
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-108: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 205
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-109: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 206
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 208 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 208
          },
          {
            "applied": false,
            "changed": false,
            "error": "write verifier states after pass dce: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 210
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-128: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 211
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-129: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 212
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-130: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 213
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-131: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 214
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-132: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 215
          },
          {
            "applied": false,
            "changed": false,
            "error": "write verifier states after pass skb_load_bytes_spec: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 219
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-294: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 220
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-295: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 221
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-296: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 222
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-297: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 223
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-298: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 224
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-262: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 225
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-263: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 226
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-264: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 227
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-265: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 228
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-266: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 229
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-267: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 230
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-268: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 231
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-269: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 232
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-270: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 233
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 237 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 237
          },
          {
            "applied": false,
            "changed": false,
            "error": "write /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-102/opt.bin: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 238
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-217: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 239
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-196: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 240
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-197: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 241
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-198: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 242
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-169: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 243
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-170: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 244
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-171: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 245
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-172: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 246
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-173: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 247
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-174: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 248
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-175: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 249
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-176: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 250
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-177: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 251
          },
          {
            "applied": false,
            "changed": false,
            "error": "write /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-52/opt.bin: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 254
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-293: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 255
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-288: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 256
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-289: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 257
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-290: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 258
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-291: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 259
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-292: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 260
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-253: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 261
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-254: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 262
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-255: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 263
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-256: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 264
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-257: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 265
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-258: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 266
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-259: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 267
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-260: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 268
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-261: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 269
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-133: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 270
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-134: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 271
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-135: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 272
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-136: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 273
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-137: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 274
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-138: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 275
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-139: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 276
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-140: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 277
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-141: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 278
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-142: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 279
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-143: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 280
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-144: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 281
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-145: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 282
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-146: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 283
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-147: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 284
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-148: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 285
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-149: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 286
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-150: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 287
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 289 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 289
          },
          {
            "applied": false,
            "changed": false,
            "error": "write verifier states after pass rotate: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 290
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-285: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 291
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-280: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 292
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-281: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 293
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-282: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 294
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-283: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 295
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-284: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 296
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-271: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 297
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-272: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 298
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-273: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 299
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-274: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 300
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-275: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 301
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-276: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 302
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-277: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 303
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-278: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 304
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-279: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 305
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-199: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 306
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-200: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 307
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-201: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 308
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-202: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 309
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-203: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 310
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-204: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 311
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-205: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 312
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-206: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 313
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-207: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 314
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-208: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 315
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-209: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 316
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-210: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 317
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-211: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 318
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-212: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 319
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-213: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 320
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-214: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 321
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-215: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 322
          },
          {
            "applied": false,
            "changed": false,
            "error": "create /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/bpfrejit-daemon-optimize-1862-216: Read-only file system (os error 30)",
            "exit_code": 1,
            "prog_id": 323
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 62,
          "not_applied": 225,
          "requested": 287
        }
      },
      "runner": "tetragon",
      "selected_workload": "stress_ng_os_io_network",
      "status": "error"
    },
    {
      "app": "tracee/monitor",
      "baseline": null,
      "error": "[Errno 30] Read-only file system: '/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.57d57086/tracee'",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "tracee",
      "selected_workload": "stress_ng_os",
      "status": "error"
    }
  ],
  "samples": 0,
  "status": "error",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 0,
    "per_program_geomean": 0.507283780803381,
    "program_count": 2,
    "wins": 2
  },
  "workload_seconds": 0.0
}
```
