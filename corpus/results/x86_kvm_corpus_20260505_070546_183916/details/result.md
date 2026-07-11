# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T07:09:16.768540+00:00",
  "kop_modules": {
    "captured_at": "2026-05-05T07:05:46.216752+00:00",
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
      "invoked_at": "2026-05-05T07:05:46.216688+00:00",
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
        "captured_at": "2026-05-05T07:05:46.216681+00:00",
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
      "captured_at": "2026-05-05T07:05:46.202605+00:00",
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
      "app": "bcc/syscount",
      "baseline": {
        "bpf": {
          "6": {
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 6,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 89920068,
            "run_time_ns_delta": 9804287715,
            "type": "tracepoint"
          },
          "7": {
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 7,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 89920574,
            "run_time_ns_delta": 2370147065,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0393599680000136,
            "ops_per_sec": 3080570.2840657923,
            "ops_total": 9362962.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [20827] setting to a 3 secs run per stressor\nstress-ng: info:  [20827] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 dup, 4 kill, 4 sigfd, 4 signal, 4 pty, 4 itimer, 4 timerfd\nstress-ng: info:  [20827] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [20827] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [20827]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [20827] cap             2138174      3.00      0.76      5.52    712693.77      340425.65\nstress-ng: metrc: [20827] eventfd          988329      3.00      0.72      4.33    329414.79      195892.77\nstress-ng: metrc: [20827] get                6604      3.00      0.21      1.17      2200.72        4786.62\nstress-ng: metrc: [20827] prctl              7687      3.00      1.81      0.85      2561.00        2892.30\nstress-ng: metrc: [20827] set               86834      3.00      0.31      3.36     28942.28       23681.05\nstress-ng: metrc: [20827] dup                3588      3.00      0.58      0.46      1195.88        3437.38\nstress-ng: metrc: [20827] kill             338696      3.00      0.33      5.28    112813.42       60450.11\nstress-ng: metrc: [20827] sigfd           5114149      3.00      0.69      6.32   1702589.74      729157.32\nstress-ng: metrc: [20827] signal                0      3.00      0.01      0.22         0.00           0.00\nstress-ng: metrc: [20827] pty                 347      3.01      0.18      4.86       115.41          68.83\nstress-ng: metrc: [20827] itimer              666      3.00      0.45      5.20       222.00         117.75\nstress-ng: metrc: [20827] timerfd          677888      3.01      0.52      3.27    225565.34      178884.97\nstress-ng: info:  [20827] skipped: 0\nstress-ng: info:  [20827] passed: 48: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4)\nstress-ng: info:  [20827] failed: 0\nstress-ng: info:  [20827] metrics untrustworthy: 0\nstress-ng: info:  [20827] successful run completed in 3.03 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 6,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 85760533,
            "run_time_ns_delta": 9390603353,
            "type": "tracepoint"
          },
          "7": {
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 7,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 85760944,
            "run_time_ns_delta": 2318705242,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.048242860000016,
            "ops_per_sec": 2802131.0611714036,
            "ops_total": 8541576.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [19170] setting to a 3 secs run per stressor\nstress-ng: info:  [19170] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 dup, 4 kill, 4 sigfd, 4 signal, 4 pty, 4 itimer, 4 timerfd\nstress-ng: info:  [19170] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19170] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19170]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19170] cap             2514798      3.00      0.63      5.82    837286.86      389899.57\nstress-ng: metrc: [19170] eventfd         1053791      3.00      0.51      4.73    350734.02      201129.49\nstress-ng: metrc: [19170] get                7579      3.00      0.10      1.17      2525.46        6011.22\nstress-ng: metrc: [19170] prctl              9392      3.00      2.22      1.05      3129.11        2878.70\nstress-ng: metrc: [19170] set               71345      3.00      0.25      2.79     23777.27       23494.21\nstress-ng: metrc: [19170] dup                4062      3.00      0.67      0.56      1353.93        3307.43\nstress-ng: metrc: [19170] kill             394692      3.00      0.37      5.66    131478.07       65538.12\nstress-ng: metrc: [19170] sigfd           3724312      3.00      0.70      5.32   1239636.56      618827.43\nstress-ng: metrc: [19170] signal                0      3.00      0.10      0.84         0.00           0.00\nstress-ng: metrc: [19170] pty                 207      3.01      0.19      4.28        68.87          46.27\nstress-ng: metrc: [19170] itimer              566      3.00      0.48      4.53       188.67         112.99\nstress-ng: metrc: [19170] timerfd          760832      3.01      0.50      3.96    253056.45      170396.55\nstress-ng: info:  [19170] skipped: 0\nstress-ng: info:  [19170] passed: 48: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4)\nstress-ng: info:  [19170] failed: 0\nstress-ng: info:  [19170] metrics untrustworthy: 0\nstress-ng: info:  [19170] successful run completed in 3.04 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "noop"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 2,
          "not_applied": 0,
          "requested": 2
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_os",
      "status": "ok"
    },
    {
      "app": "tracee/monitor",
      "baseline": {
        "bpf": {
          "22": {
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 22,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 35965078,
            "run_time_ns_delta": 5682355100,
            "type": "raw_tracepoint"
          },
          "23": {
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 23,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "24": {
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 24,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "25": {
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 25,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 35965377,
            "run_time_ns_delta": 10944065211,
            "type": "raw_tracepoint"
          },
          "26": {
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 26,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "27": {
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 27,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "28": {
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 28,
            "name": "trace_sys_enter",
            "run_cnt_delta": 35965078,
            "run_time_ns_delta": 9098607727,
            "type": "raw_tracepoint"
          },
          "29": {
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 29,
            "name": "trace_sys_exit",
            "run_cnt_delta": 35965377,
            "run_time_ns_delta": 9202150016,
            "type": "raw_tracepoint"
          },
          "30": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 30,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "31": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 31,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "32": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 32,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "33": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 33,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "34": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 34,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 1065152,
            "run_time_ns_delta": 71553356,
            "type": "kprobe"
          },
          "35": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 35,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 1065152,
            "run_time_ns_delta": 277994448,
            "type": "kprobe"
          },
          "36": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 36,
            "name": "trace_dup",
            "run_cnt_delta": 3383,
            "run_time_ns_delta": 838377,
            "type": "kprobe"
          },
          "37": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 37,
            "name": "trace_ret_dup",
            "run_cnt_delta": 3383,
            "run_time_ns_delta": 3177493,
            "type": "kprobe"
          },
          "38": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 38,
            "name": "trace_dup2",
            "run_cnt_delta": 4846,
            "run_time_ns_delta": 677753,
            "type": "kprobe"
          },
          "39": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 39,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 4846,
            "run_time_ns_delta": 3082793,
            "type": "kprobe"
          },
          "40": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 40,
            "name": "trace_dup3",
            "run_cnt_delta": 5148,
            "run_time_ns_delta": 597829,
            "type": "kprobe"
          },
          "41": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 41,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 5148,
            "run_time_ns_delta": 2838820,
            "type": "kprobe"
          },
          "42": {
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 42,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "43": {
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 43,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "44": {
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 44,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "45": {
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 45,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "46": {
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 46,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "47": {
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 47,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 7507,
            "run_time_ns_delta": 19244249,
            "type": "raw_tracepoint"
          },
          "48": {
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 48,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "49": {
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 49,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "50": {
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 50,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "51": {
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 51,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "52": {
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 52,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "53": {
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 53,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "54": {
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 54,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "55": {
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 55,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 25261,
            "type": "raw_tracepoint"
          },
          "56": {
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 56,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "57": {
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 57,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 7270,
            "run_time_ns_delta": 7792247,
            "type": "raw_tracepoint"
          },
          "58": {
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 58,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 7244,
            "run_time_ns_delta": 6165678,
            "type": "raw_tracepoint"
          },
          "59": {
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 59,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "60": {
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 60,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 703526,
            "run_time_ns_delta": 303601501,
            "type": "raw_tracepoint"
          },
          "61": {
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 61,
            "name": "trace_filldir64",
            "run_cnt_delta": 518986,
            "run_time_ns_delta": 8800305,
            "type": "kprobe"
          },
          "62": {
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 62,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "63": {
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 63,
            "name": "trace_do_exit",
            "run_cnt_delta": 7270,
            "run_time_ns_delta": 5352710,
            "type": "kprobe"
          },
          "64": {
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 64,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "65": {
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 65,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "66": {
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 66,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "67": {
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 67,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 3636540,
            "run_time_ns_delta": 334900645,
            "type": "kprobe"
          },
          "68": {
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 68,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "69": {
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 69,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "70": {
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 70,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "71": {
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 71,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "72": {
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 72,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 25471,
            "type": "kprobe"
          },
          "73": {
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 73,
            "name": "trace_security_file_open",
            "run_cnt_delta": 478397,
            "run_time_ns_delta": 274185982,
            "type": "kprobe"
          },
          "74": {
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 74,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "75": {
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 75,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 2590,
            "run_time_ns_delta": 3216226,
            "type": "kprobe"
          },
          "76": {
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 76,
            "name": "trace_commit_creds",
            "run_cnt_delta": 123377,
            "run_time_ns_delta": 32499026,
            "type": "kprobe"
          },
          "77": {
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 77,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 7270,
            "run_time_ns_delta": 3815765,
            "type": "kprobe"
          },
          "78": {
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 78,
            "name": "trace_cap_capable",
            "run_cnt_delta": 2625397,
            "run_time_ns_delta": 295700890,
            "type": "kprobe"
          },
          "79": {
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 79,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 73816,
            "run_time_ns_delta": 35102174,
            "type": "kprobe"
          },
          "80": {
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 80,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "81": {
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 81,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "82": {
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 82,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "83": {
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 83,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "84": {
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 84,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 27680,
            "type": "kprobe"
          },
          "85": {
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 85,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 54345,
            "run_time_ns_delta": 26838148,
            "type": "kprobe"
          },
          "86": {
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 86,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 57974,
            "run_time_ns_delta": 39396245,
            "type": "kprobe"
          },
          "87": {
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 87,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 24,
            "run_time_ns_delta": 29043,
            "type": "kprobe"
          },
          "88": {
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 88,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 50271,
            "run_time_ns_delta": 24080531,
            "type": "kprobe"
          },
          "89": {
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 89,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "90": {
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 90,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "91": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 91,
            "name": "trace_vfs_write",
            "run_cnt_delta": 244228,
            "run_time_ns_delta": 15849763,
            "type": "kprobe"
          },
          "92": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 92,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 244228,
            "run_time_ns_delta": 6688417,
            "type": "kprobe"
          },
          "93": {
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 93,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 244228,
            "run_time_ns_delta": 121560671,
            "type": "kprobe"
          },
          "94": {
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 94,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 244228,
            "run_time_ns_delta": 12714838,
            "type": "kprobe"
          },
          "95": {
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 95,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "96": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 96,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 113,
            "run_time_ns_delta": 42687,
            "type": "kprobe"
          },
          "97": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 97,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 113,
            "run_time_ns_delta": 70616,
            "type": "kprobe"
          },
          "98": {
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 98,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 113,
            "run_time_ns_delta": 220777,
            "type": "kprobe"
          },
          "99": {
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 99,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 113,
            "run_time_ns_delta": 571511,
            "type": "kprobe"
          },
          "100": {
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 100,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "101": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 101,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "102": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 102,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "103": {
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 103,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "104": {
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 104,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "105": {
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 105,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "106": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 106,
            "name": "trace_vfs_read",
            "run_cnt_delta": 1074069,
            "run_time_ns_delta": 63090633,
            "type": "kprobe"
          },
          "107": {
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 107,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 1074069,
            "run_time_ns_delta": 803548168,
            "type": "kprobe"
          },
          "108": {
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 108,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "109": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 109,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 113,
            "run_time_ns_delta": 48643,
            "type": "kprobe"
          },
          "110": {
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 110,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 113,
            "run_time_ns_delta": 249094,
            "type": "kprobe"
          },
          "111": {
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 111,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "112": {
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 112,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 1207746,
            "run_time_ns_delta": 140053444,
            "type": "kprobe"
          },
          "113": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 113,
            "name": "trace_do_mmap",
            "run_cnt_delta": 1098646,
            "run_time_ns_delta": 61858726,
            "type": "kprobe"
          },
          "114": {
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 114,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 1098646,
            "run_time_ns_delta": 353509777,
            "type": "kprobe"
          },
          "115": {
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 115,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 1098642,
            "run_time_ns_delta": 125613087,
            "type": "kprobe"
          },
          "116": {
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 116,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 3396387,
            "run_time_ns_delta": 1411058487,
            "type": "kprobe"
          },
          "117": {
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 117,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "118": {
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 118,
            "name": "trace_security_bpf",
            "run_cnt_delta": 8164,
            "run_time_ns_delta": 1971043,
            "type": "kprobe"
          },
          "119": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 119,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "120": {
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 120,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "121": {
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 121,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2606,
            "run_time_ns_delta": 611208,
            "type": "kprobe"
          },
          "122": {
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 122,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 159,
            "run_time_ns_delta": 103607,
            "type": "kprobe"
          },
          "123": {
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 123,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "124": {
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 124,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "125": {
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 125,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "126": {
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 126,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "127": {
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 127,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "128": {
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 128,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 2306,
            "run_time_ns_delta": 2615850,
            "type": "kprobe"
          },
          "129": {
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 129,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "130": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 130,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "131": {
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 131,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "132": {
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 132,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "133": {
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 133,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "134": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 134,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "135": {
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 135,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "136": {
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 136,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 15212,
            "type": "kprobe"
          },
          "137": {
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 137,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 1796018,
            "run_time_ns_delta": 76019655,
            "type": "kprobe"
          },
          "138": {
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 138,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 5000,
            "run_time_ns_delta": 4148583,
            "type": "raw_tracepoint"
          },
          "139": {
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 139,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "140": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 140,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "141": {
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 141,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "142": {
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 142,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 9975,
            "run_time_ns_delta": 8899021,
            "type": "kprobe"
          },
          "143": {
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 143,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "144": {
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 144,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "145": {
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 145,
            "name": "trace_do_truncate",
            "run_cnt_delta": 386,
            "run_time_ns_delta": 751111,
            "type": "kprobe"
          },
          "146": {
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 146,
            "name": "trace_fd_install",
            "run_cnt_delta": 720717,
            "run_time_ns_delta": 200062019,
            "type": "kprobe"
          },
          "147": {
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 147,
            "name": "trace_filp_close",
            "run_cnt_delta": 318766,
            "run_time_ns_delta": 97027403,
            "type": "kprobe"
          },
          "148": {
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 148,
            "name": "trace_file_update_time",
            "run_cnt_delta": 15616,
            "run_time_ns_delta": 3647263,
            "type": "kprobe"
          },
          "149": {
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 149,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 15616,
            "run_time_ns_delta": 14896411,
            "type": "kprobe"
          },
          "150": {
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 150,
            "name": "trace_file_modified",
            "run_cnt_delta": 171262,
            "run_time_ns_delta": 16766714,
            "type": "kprobe"
          },
          "151": {
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 151,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 171262,
            "run_time_ns_delta": 75871496,
            "type": "kprobe"
          },
          "152": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 152,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "153": {
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 153,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "154": {
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 154,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "155": {
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 155,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 370,
            "type": "kprobe"
          },
          "156": {
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 156,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 16366,
            "type": "kprobe"
          },
          "157": {
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 157,
            "name": "trace_execute_finished",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 22209,
            "type": "kprobe"
          },
          "158": {
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 158,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "159": {
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 159,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 13721,
            "type": "kprobe"
          },
          "160": {
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 160,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 255590,
            "run_time_ns_delta": 73674148,
            "type": "kprobe"
          },
          "161": {
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 161,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "162": {
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 162,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "163": {
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 163,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 375999,
            "run_time_ns_delta": 127090489,
            "type": "kprobe"
          },
          "164": {
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 164,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "165": {
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 165,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "166": {
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 166,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 131770,
            "run_time_ns_delta": 13601292,
            "type": "kprobe"
          },
          "167": {
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 167,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 131770,
            "run_time_ns_delta": 76596342,
            "type": "kprobe"
          },
          "168": {
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 168,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 49684,
            "run_time_ns_delta": 46766313,
            "type": "kprobe"
          },
          "169": {
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 169,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 626425,
            "run_time_ns_delta": 209525456,
            "type": "kprobe"
          },
          "170": {
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 170,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 1876909,
            "run_time_ns_delta": 606691801,
            "type": "kprobe"
          },
          "171": {
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 171,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 2926151,
            "run_time_ns_delta": 718325607,
            "type": "kprobe"
          },
          "173": {
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 173,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 1011711,
            "run_time_ns_delta": 299808911,
            "type": "cgroup_skb"
          },
          "174": {
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 174,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 1865746,
            "run_time_ns_delta": 473341013,
            "type": "cgroup_skb"
          },
          "175": {
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 175,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "176": {
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 176,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "177": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 177,
            "name": "empty_kprobe",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 645,
            "type": "kprobe"
          },
          "178": {
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 178,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 4277,
            "type": "raw_tracepoint"
          },
          "179": {
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 179,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 478397,
            "run_time_ns_delta": 131236903,
            "type": "lsm"
          },
          "180": {
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 180,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.197893967999988,
            "ops_per_sec": 5566890.009326959,
            "ops_total": 28936104.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [11506] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11506]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11506] cap              490728      5.02      0.16      4.68     97804.85      101572.18\nstress-ng: metrc: [11506] eventfd           84789      5.01      0.03      1.73     16935.69       48194.82\nstress-ng: metrc: [11506] get                3119      5.04      0.11      1.71       619.33        1713.80\nstress-ng: metrc: [11506] prctl              4050      5.01      2.65      0.81       808.02        1169.41\nstress-ng: metrc: [11506] set               11856      5.07      0.06      1.43      2338.41        7946.41\nstress-ng: metrc: [11506] dup                1145      5.03      0.32      0.32       227.77        1786.63\nstress-ng: metrc: [11506] kill              40774      5.04      0.08      2.49      8087.67       15843.58\nstress-ng: metrc: [11506] sigfd            293369      5.06      0.05      1.75     58025.30      163171.33\nstress-ng: metrc: [11506] signal                0      5.02      0.00      0.00         0.00           0.00\nstress-ng: metrc: [11506] pty                  62      5.05      0.04      3.91        12.27          15.71\nstress-ng: metrc: [11506] itimer              175      5.04      0.04      1.58        34.74         108.03\nstress-ng: metrc: [11506] timerfd          318464      5.07      0.04      2.74     62778.27      114504.45\nstress-ng: metrc: [11506] aio               19173      5.06      0.01      0.23      3789.51       81890.40\nstress-ng: metrc: [11506] aiol               4515      5.15      0.08      0.32       876.73       11321.81\nstress-ng: metrc: [11506] hdd               57143      5.05      0.76      0.97     11308.75       33098.17\nstress-ng: metrc: [11506] io                  143      5.05      0.03      0.01        28.31        3116.22\nstress-ng: metrc: [11506] iomix              3916      5.07      0.09      2.41       772.82        1565.81\nstress-ng: metrc: [11506] io-uring          21708      5.08      0.00      1.27      4276.06       17028.22\nstress-ng: metrc: [11506] sync-file            89      5.05      0.09      1.00        17.61          81.68\nstress-ng: metrc: [11506] epoll              4478      5.08      0.06      0.43       881.28        9166.29\nstress-ng: metrc: [11506] netdev           409422      5.04      0.08      2.59     81245.37      153272.57\nstress-ng: metrc: [11506] sctp               5934      5.00      0.04      0.00      1186.10      134777.87\nstress-ng: metrc: [11506] sock               1184      5.03      0.18      2.11       235.42         515.12\nstress-ng: metrc: [11506] sockdiag       23954323      5.02      0.05      1.81   4769323.69    12900647.93\nstress-ng: metrc: [11506] sockfd           115803      5.02      0.00      1.21     23063.82       95902.07\nstress-ng: metrc: [11506] sockpair            527      5.05      0.04      0.12       104.41        3300.08\nstress-ng: metrc: [11506] sockmany          49670      5.04      0.04      3.31      9864.89       14852.18\nstress-ng: metrc: [11506] udp               81225      5.03      0.05      2.31     16149.44       34379.00\nstress-ng: metrc: [11506] udp-flood        436389      5.03      0.06      1.62     86763.52      259456.67\nstress-ng: metrc: [11506] mmap                973      5.00      0.09      3.12       194.47         303.36\nstress-ng: metrc: [11506] mprotect        2517260      5.06      0.65     17.73    497704.23      136967.22\nstress-ng: metrc: [11506] mremap             3627      5.02      0.02      2.87       722.38        1255.18\nstress-ng: metrc: [11506] madvise              71      5.06      0.13      4.11        14.03          16.77\nstress-ng: info:  [11506] skipped: 0\nstress-ng: info:  [11506] passed: 132: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp (4) udp-flood (4) mmap (4) mprotect (4) mremap (4) madvise (4)\nstress-ng: info:  [11506] failed: 0\nstress-ng: info:  [11506] metrics untrustworthy: 0\nstress-ng: info:  [11506] successful run completed in 5.17 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "22": {
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 22,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 36587098,
            "run_time_ns_delta": 5702822067,
            "type": "raw_tracepoint"
          },
          "23": {
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 23,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "24": {
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 24,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "25": {
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 25,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 36587443,
            "run_time_ns_delta": 11048599103,
            "type": "raw_tracepoint"
          },
          "26": {
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 26,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "27": {
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 27,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "28": {
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 28,
            "name": "trace_sys_enter",
            "run_cnt_delta": 36587098,
            "run_time_ns_delta": 9235443211,
            "type": "raw_tracepoint"
          },
          "29": {
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 29,
            "name": "trace_sys_exit",
            "run_cnt_delta": 36587443,
            "run_time_ns_delta": 9249856905,
            "type": "raw_tracepoint"
          },
          "30": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 30,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "31": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 31,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "32": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 32,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "33": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 33,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "34": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 34,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 872110,
            "run_time_ns_delta": 59877037,
            "type": "kprobe"
          },
          "35": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 35,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 872110,
            "run_time_ns_delta": 224907147,
            "type": "kprobe"
          },
          "36": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 36,
            "name": "trace_dup",
            "run_cnt_delta": 4074,
            "run_time_ns_delta": 924305,
            "type": "kprobe"
          },
          "37": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 37,
            "name": "trace_ret_dup",
            "run_cnt_delta": 4074,
            "run_time_ns_delta": 3963943,
            "type": "kprobe"
          },
          "38": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 38,
            "name": "trace_dup2",
            "run_cnt_delta": 5452,
            "run_time_ns_delta": 800213,
            "type": "kprobe"
          },
          "39": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 39,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 5452,
            "run_time_ns_delta": 3531695,
            "type": "kprobe"
          },
          "40": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 40,
            "name": "trace_dup3",
            "run_cnt_delta": 5815,
            "run_time_ns_delta": 665669,
            "type": "kprobe"
          },
          "41": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 41,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 5815,
            "run_time_ns_delta": 3163745,
            "type": "kprobe"
          },
          "42": {
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 42,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "43": {
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 43,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "44": {
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 44,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "45": {
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 45,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "46": {
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 46,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "47": {
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 47,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 6848,
            "run_time_ns_delta": 19250036,
            "type": "raw_tracepoint"
          },
          "48": {
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 48,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "49": {
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 49,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "50": {
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 50,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "51": {
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 51,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "52": {
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 52,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "53": {
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 53,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "54": {
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 54,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "55": {
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 55,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 9272,
            "type": "raw_tracepoint"
          },
          "56": {
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 56,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "57": {
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 57,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 6834,
            "run_time_ns_delta": 8311196,
            "type": "raw_tracepoint"
          },
          "58": {
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 58,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 6837,
            "run_time_ns_delta": 5881327,
            "type": "raw_tracepoint"
          },
          "59": {
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 59,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "60": {
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 60,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 688359,
            "run_time_ns_delta": 291992318,
            "type": "raw_tracepoint"
          },
          "61": {
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 61,
            "name": "trace_filldir64",
            "run_cnt_delta": 353332,
            "run_time_ns_delta": 6265423,
            "type": "kprobe"
          },
          "62": {
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 62,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "63": {
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 63,
            "name": "trace_do_exit",
            "run_cnt_delta": 6836,
            "run_time_ns_delta": 4779784,
            "type": "kprobe"
          },
          "64": {
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 64,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "65": {
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 65,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "66": {
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 66,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "67": {
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 67,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 5451616,
            "run_time_ns_delta": 525262442,
            "type": "kprobe"
          },
          "68": {
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 68,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "69": {
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 69,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "70": {
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 70,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "71": {
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 71,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "72": {
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 72,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 7098,
            "type": "kprobe"
          },
          "73": {
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 73,
            "name": "trace_security_file_open",
            "run_cnt_delta": 569735,
            "run_time_ns_delta": 352370372,
            "type": "kprobe"
          },
          "74": {
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 74,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "75": {
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 75,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 2894,
            "run_time_ns_delta": 3648013,
            "type": "kprobe"
          },
          "76": {
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 76,
            "name": "trace_commit_creds",
            "run_cnt_delta": 159939,
            "run_time_ns_delta": 43350893,
            "type": "kprobe"
          },
          "77": {
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 77,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 6836,
            "run_time_ns_delta": 4104590,
            "type": "kprobe"
          },
          "78": {
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 78,
            "name": "trace_cap_capable",
            "run_cnt_delta": 2129811,
            "run_time_ns_delta": 252258168,
            "type": "kprobe"
          },
          "79": {
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 79,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 45360,
            "run_time_ns_delta": 17487503,
            "type": "kprobe"
          },
          "80": {
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 80,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "81": {
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 81,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "82": {
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 82,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "83": {
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 83,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "84": {
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 84,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 26317,
            "type": "kprobe"
          },
          "85": {
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 85,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 25195,
            "run_time_ns_delta": 11543846,
            "type": "kprobe"
          },
          "86": {
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 86,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 25697,
            "run_time_ns_delta": 14666610,
            "type": "kprobe"
          },
          "87": {
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 87,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 24,
            "run_time_ns_delta": 27725,
            "type": "kprobe"
          },
          "88": {
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 88,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 25024,
            "run_time_ns_delta": 11963191,
            "type": "kprobe"
          },
          "89": {
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 89,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "90": {
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 90,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "91": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 91,
            "name": "trace_vfs_write",
            "run_cnt_delta": 236474,
            "run_time_ns_delta": 16920901,
            "type": "kprobe"
          },
          "92": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 92,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 236474,
            "run_time_ns_delta": 7904206,
            "type": "kprobe"
          },
          "93": {
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 93,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 236474,
            "run_time_ns_delta": 126643183,
            "type": "kprobe"
          },
          "94": {
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 94,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 236474,
            "run_time_ns_delta": 13681697,
            "type": "kprobe"
          },
          "95": {
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 95,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "96": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 96,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 120,
            "run_time_ns_delta": 39355,
            "type": "kprobe"
          },
          "97": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 97,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 120,
            "run_time_ns_delta": 50983,
            "type": "kprobe"
          },
          "98": {
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 98,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 120,
            "run_time_ns_delta": 255659,
            "type": "kprobe"
          },
          "99": {
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 99,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 120,
            "run_time_ns_delta": 595478,
            "type": "kprobe"
          },
          "100": {
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 100,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "101": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 101,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "102": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 102,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "103": {
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 103,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "104": {
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 104,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "105": {
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 105,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "106": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 106,
            "name": "trace_vfs_read",
            "run_cnt_delta": 1566118,
            "run_time_ns_delta": 88429140,
            "type": "kprobe"
          },
          "107": {
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 107,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 1566118,
            "run_time_ns_delta": 1231078180,
            "type": "kprobe"
          },
          "108": {
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 108,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "109": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 109,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 120,
            "run_time_ns_delta": 36434,
            "type": "kprobe"
          },
          "110": {
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 110,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 120,
            "run_time_ns_delta": 299147,
            "type": "kprobe"
          },
          "111": {
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 111,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "112": {
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 112,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 596453,
            "run_time_ns_delta": 71040767,
            "type": "kprobe"
          },
          "113": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 113,
            "name": "trace_do_mmap",
            "run_cnt_delta": 552505,
            "run_time_ns_delta": 33508815,
            "type": "kprobe"
          },
          "114": {
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 114,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 552505,
            "run_time_ns_delta": 180262463,
            "type": "kprobe"
          },
          "115": {
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 115,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 552501,
            "run_time_ns_delta": 66629304,
            "type": "kprobe"
          },
          "116": {
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 116,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 2823675,
            "run_time_ns_delta": 1102606777,
            "type": "kprobe"
          },
          "117": {
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 117,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "118": {
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 118,
            "name": "trace_security_bpf",
            "run_cnt_delta": 8164,
            "run_time_ns_delta": 2207911,
            "type": "kprobe"
          },
          "119": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 119,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "120": {
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 120,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "121": {
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 121,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2606,
            "run_time_ns_delta": 735123,
            "type": "kprobe"
          },
          "122": {
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 122,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 159,
            "run_time_ns_delta": 145218,
            "type": "kprobe"
          },
          "123": {
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 123,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "124": {
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 124,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "125": {
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 125,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "126": {
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 126,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "127": {
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 127,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "128": {
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 128,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 2598,
            "run_time_ns_delta": 2915974,
            "type": "kprobe"
          },
          "129": {
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 129,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "130": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 130,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "131": {
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 131,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "132": {
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 132,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "133": {
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 133,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "134": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 134,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "135": {
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 135,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "136": {
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 136,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5323,
            "type": "kprobe"
          },
          "137": {
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 137,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 2558384,
            "run_time_ns_delta": 101357827,
            "type": "kprobe"
          },
          "138": {
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 138,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 4266,
            "run_time_ns_delta": 3609711,
            "type": "raw_tracepoint"
          },
          "139": {
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 139,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "140": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 140,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "141": {
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 141,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "142": {
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 142,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 8653,
            "run_time_ns_delta": 7089702,
            "type": "kprobe"
          },
          "143": {
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 143,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "144": {
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 144,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "145": {
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 145,
            "name": "trace_do_truncate",
            "run_cnt_delta": 453,
            "run_time_ns_delta": 814392,
            "type": "kprobe"
          },
          "146": {
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 146,
            "name": "trace_fd_install",
            "run_cnt_delta": 770371,
            "run_time_ns_delta": 267235126,
            "type": "kprobe"
          },
          "147": {
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 147,
            "name": "trace_filp_close",
            "run_cnt_delta": 376937,
            "run_time_ns_delta": 118055653,
            "type": "kprobe"
          },
          "148": {
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 148,
            "name": "trace_file_update_time",
            "run_cnt_delta": 17350,
            "run_time_ns_delta": 3609133,
            "type": "kprobe"
          },
          "149": {
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 149,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 17350,
            "run_time_ns_delta": 14585280,
            "type": "kprobe"
          },
          "150": {
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 150,
            "name": "trace_file_modified",
            "run_cnt_delta": 244289,
            "run_time_ns_delta": 23736102,
            "type": "kprobe"
          },
          "151": {
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 151,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 244289,
            "run_time_ns_delta": 107828419,
            "type": "kprobe"
          },
          "152": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 152,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "153": {
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 153,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "154": {
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 154,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "155": {
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 155,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 958,
            "type": "kprobe"
          },
          "156": {
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 156,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 6460,
            "type": "kprobe"
          },
          "157": {
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 157,
            "name": "trace_execute_finished",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 9723,
            "type": "kprobe"
          },
          "158": {
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 158,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "159": {
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 159,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 5221,
            "type": "kprobe"
          },
          "160": {
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 160,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 284066,
            "run_time_ns_delta": 82753249,
            "type": "kprobe"
          },
          "161": {
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 161,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "162": {
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 162,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "163": {
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 163,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 307307,
            "run_time_ns_delta": 99753637,
            "type": "kprobe"
          },
          "164": {
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 164,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "165": {
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 165,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "166": {
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 166,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 71045,
            "run_time_ns_delta": 6530081,
            "type": "kprobe"
          },
          "167": {
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 167,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 71045,
            "run_time_ns_delta": 47899373,
            "type": "kprobe"
          },
          "168": {
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 168,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 24456,
            "run_time_ns_delta": 26638912,
            "type": "kprobe"
          },
          "169": {
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 169,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 512722,
            "run_time_ns_delta": 140450117,
            "type": "kprobe"
          },
          "170": {
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 170,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 1769315,
            "run_time_ns_delta": 544465626,
            "type": "kprobe"
          },
          "171": {
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 171,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 2469243,
            "run_time_ns_delta": 564087240,
            "type": "kprobe"
          },
          "173": {
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 173,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 550980,
            "run_time_ns_delta": 171810632,
            "type": "cgroup_skb"
          },
          "174": {
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 174,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 1869287,
            "run_time_ns_delta": 403749569,
            "type": "cgroup_skb"
          },
          "175": {
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 175,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "176": {
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 176,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "177": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 177,
            "name": "empty_kprobe",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 91,
            "type": "kprobe"
          },
          "178": {
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 178,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2138,
            "type": "raw_tracepoint"
          },
          "179": {
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 179,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 569735,
            "run_time_ns_delta": 155535747,
            "type": "lsm"
          },
          "180": {
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 180,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.238322322999977,
            "ops_per_sec": 4889426.121707576,
            "ops_total": 25612390.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [26992] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [26992]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [26992] cap              337654      5.08      0.13      3.38     66493.45       96169.31\nstress-ng: metrc: [26992] eventfd           78829      5.03      0.10      1.74     15674.83       42884.94\nstress-ng: metrc: [26992] get                1930      5.00      0.12      1.23       385.62        1436.86\nstress-ng: metrc: [26992] prctl              3316      5.01      2.25      0.68       661.74        1131.66\nstress-ng: metrc: [26992] set               16270      5.01      0.07      2.20      3250.62        7155.94\nstress-ng: metrc: [26992] dup                1291      5.07      0.39      0.39       254.61        1649.95\nstress-ng: metrc: [26992] kill              35293      5.03      0.08      3.21      7010.89       10715.33\nstress-ng: metrc: [26992] sigfd            718643      5.07      0.12      4.45    141630.26      157392.54\nstress-ng: metrc: [26992] signal                0      5.05      0.01      0.00         0.00           0.00\nstress-ng: metrc: [26992] pty                 127      5.08      0.12      6.61        25.01          18.86\nstress-ng: metrc: [26992] itimer              288      5.04      0.05      2.41        57.10         117.01\nstress-ng: metrc: [26992] timerfd          351232      5.11      0.04      2.75     68795.47      125783.21\nstress-ng: metrc: [26992] aio               20436      5.10      0.01      0.24      4006.71       81369.70\nstress-ng: metrc: [26992] aiol               7712      5.19      0.06      0.59      1486.70       11877.21\nstress-ng: metrc: [26992] hdd               60933      5.10      0.81      0.88     11949.86       35900.45\nstress-ng: metrc: [26992] io                  153      5.09      0.04      0.01        30.04        3256.64\nstress-ng: metrc: [26992] iomix              4007      5.10      0.08      2.62       785.81        1484.86\nstress-ng: metrc: [26992] io-uring          29688      5.09      0.01      1.58      5833.92       18618.86\nstress-ng: metrc: [26992] sync-file           110      5.09      0.02      1.27        21.63          85.15\nstress-ng: metrc: [26992] epoll               569      5.09      0.05      0.03       111.71        7395.47\nstress-ng: metrc: [26992] netdev           603657      5.01      0.14      4.25    120509.49      137573.91\nstress-ng: metrc: [26992] sctp               5335      5.00      0.04      0.01      1066.85      112962.65\nstress-ng: metrc: [26992] sock               1011      5.02      0.03      1.84       201.36         542.02\nstress-ng: metrc: [26992] sockdiag       20384503      5.06      0.03      2.83   4026483.73     7121504.88\nstress-ng: metrc: [26992] sockfd           130673      5.06      0.03      1.62     25820.96       79288.84\nstress-ng: metrc: [26992] sockpair            580      5.07      0.03      0.14       114.46        3497.14\nstress-ng: metrc: [26992] sockmany          24442      5.05      0.05      1.48      4836.44       15946.47\nstress-ng: metrc: [26992] udp               32815      5.04      0.07      1.33      6515.25       23452.70\nstress-ng: metrc: [26992] udp-flood        666929      5.00      0.05      2.67    133371.23      245049.98\nstress-ng: metrc: [26992] mmap                483      5.01      0.07      1.51        96.45         305.51\nstress-ng: metrc: [26992] mprotect        2091945      5.04      0.44     13.77    414989.88      147229.48\nstress-ng: metrc: [26992] mremap             1464      5.01      0.02      1.42       292.03        1014.22\nstress-ng: metrc: [26992] madvise              72      5.04      0.16      4.30        14.27          16.15\nstress-ng: info:  [26992] skipped: 0\nstress-ng: info:  [26992] passed: 132: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp (4) udp-flood (4) mmap (4) mprotect (4) mremap (4) madvise (4)\nstress-ng: info:  [26992] failed: 0\nstress-ng: info:  [26992] metrics untrustworthy: 0\nstress-ng: info:  [26992] successful run completed in 5.22 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "noop"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 158,
          "not_applied": 0,
          "requested": 158
        }
      },
      "runner": "tracee",
      "selected_workload": "stress_ng_os_io_network",
      "status": "ok"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline": {
        "bpf": {
          "186": {
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 186,
            "name": "block_io_start",
            "run_cnt_delta": 1360668,
            "run_time_ns_delta": 569021896,
            "type": "tracepoint"
          },
          "187": {
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 187,
            "name": "block_io_done",
            "run_cnt_delta": 1360683,
            "run_time_ns_delta": 1109357798,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.360557414000027,
            "ops_per_sec": 340985.62123897637,
            "ops_total": 1827873.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.075422,\n        \"1000\" : 11.218455\n      },\n      \"latency_us\" : {\n        \"2\" : 36.301670,\n        \"4\" : 1.795520,\n        \"10\" : 8.643431,\n        \"20\" : 36.979813,\n        \"50\" : 2.733279,\n        \"100\" : 1.765438,\n        \"250\" : 0.458417,\n        \"500\" : 0.028120,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.010000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "186": {
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 186,
            "name": "block_io_start",
            "run_cnt_delta": 1415378,
            "run_time_ns_delta": 612051315,
            "type": "tracepoint"
          },
          "187": {
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 187,
            "name": "block_io_done",
            "run_cnt_delta": 1415393,
            "run_time_ns_delta": 1109166995,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.37921182499997,
            "ops_per_sec": 352481.0068248261,
            "ops_total": 1896070.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.163742,\n        \"1000\" : 14.444676\n      },\n      \"latency_us\" : {\n        \"2\" : 33.121605,\n        \"4\" : 1.625426,\n        \"10\" : 9.622698,\n        \"20\" : 36.860527,\n        \"50\" : 2.343324,\n        \"100\" : 1.458737,\n        \"250\" : 0.331694,\n        \"500\" : 0.027150,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "noop"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 2,
          "not_applied": 0,
          "requested": 2
        }
      },
      "runner": "bpftrace",
      "selected_workload": "fio_randrw",
      "status": "ok"
    }
  ],
  "samples": 1,
  "status": "ok",
  "suite_name": "macro_apps",
  "workload_seconds": 3.0
}
```
