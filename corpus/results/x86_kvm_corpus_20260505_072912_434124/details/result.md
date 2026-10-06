# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T07:34:14.378490+00:00",
  "kinsn_modules": {
    "captured_at": "2026-05-05T07:29:12.466742+00:00",
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
      "invoked_at": "2026-05-05T07:29:12.466686+00:00",
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
        "captured_at": "2026-05-05T07:29:12.466679+00:00",
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
      "captured_at": "2026-05-05T07:29:12.450777+00:00",
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
            "run_cnt_delta": 87517744,
            "run_time_ns_delta": 9432415900,
            "type": "tracepoint"
          },
          "7": {
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 7,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 87518201,
            "run_time_ns_delta": 2343013948,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.045260555999988,
            "ops_per_sec": 2972624.1264197542,
            "ops_total": 9052415.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [18788] setting to a 3 secs run per stressor\nstress-ng: info:  [18788] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 dup, 4 kill, 4 sigfd, 4 signal, 4 pty, 4 itimer, 4 timerfd\nstress-ng: info:  [18788] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18788] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18788]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18788] cap             2732687      3.00      0.63      6.18    910335.39      401430.12\nstress-ng: metrc: [18788] eventfd          546193      3.00      0.45      3.40    182011.41      141813.35\nstress-ng: metrc: [18788] get                7130      3.00      0.18      1.39      2376.06        4542.57\nstress-ng: metrc: [18788] prctl              7992      3.00      1.76      0.78      2663.36        3152.49\nstress-ng: metrc: [18788] set               76326      3.00      0.34      3.00     25441.24       22891.70\nstress-ng: metrc: [18788] dup                3346      3.00      0.52      0.41      1115.18        3608.50\nstress-ng: metrc: [18788] kill             307679      3.00      0.25      4.32    102471.30       67291.79\nstress-ng: metrc: [18788] sigfd           4466912      3.00      0.70      6.04   1487837.02      662665.08\nstress-ng: metrc: [18788] signal                0      3.00      0.04      0.19         0.00           0.00\nstress-ng: metrc: [18788] pty                 286      3.01      0.22      5.36        95.17          51.20\nstress-ng: metrc: [18788] itimer              696      3.00      0.63      5.53       231.99         113.03\nstress-ng: metrc: [18788] timerfd          903168      3.00      0.67      4.44    300673.02      176700.91\nstress-ng: info:  [18788] skipped: 0\nstress-ng: info:  [18788] passed: 48: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4)\nstress-ng: info:  [18788] failed: 0\nstress-ng: info:  [18788] metrics untrustworthy: 0\nstress-ng: info:  [18788] successful run completed in 3.03 secs"
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
            "run_cnt_delta": 86489313,
            "run_time_ns_delta": 9124664947,
            "type": "tracepoint"
          },
          "7": {
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 7,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 86489749,
            "run_time_ns_delta": 2357973485,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0922506009999893,
            "ops_per_sec": 2756885.2269745357,
            "ops_total": 8524980.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [18062] setting to a 3 secs run per stressor\nstress-ng: info:  [18062] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 dup, 4 kill, 4 sigfd, 4 signal, 4 pty, 4 itimer, 4 timerfd\nstress-ng: info:  [18062] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18062] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18062]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18062] cap             2698379      3.00      0.74      6.46    898828.08      374608.52\nstress-ng: metrc: [18062] eventfd         1022038      3.00      0.56      4.51    340538.77      201594.75\nstress-ng: metrc: [18062] get                5816      3.00      0.15      0.97      1937.59        5197.01\nstress-ng: metrc: [18062] prctl             10804      3.00      2.51      1.19      3600.17        2915.78\nstress-ng: metrc: [18062] set               82064      3.00      0.18      2.80     27338.95       27544.74\nstress-ng: metrc: [18062] dup                4672      3.00      0.78      0.61      1557.24        3346.68\nstress-ng: metrc: [18062] kill             353535      3.00      0.34      5.30    117670.08       62731.59\nstress-ng: metrc: [18062] sigfd           3601547      3.00      0.64      4.32   1199045.51      726218.93\nstress-ng: metrc: [18062] signal                0      3.00      0.10      1.72         0.00           0.00\nstress-ng: metrc: [18062] pty                 203      3.01      0.25      4.98        67.49          38.83\nstress-ng: metrc: [18062] itimer              450      3.00      0.40      3.60       149.98         112.65\nstress-ng: metrc: [18062] timerfd          745472      3.00      0.35      4.04    248096.67      169811.82\nstress-ng: info:  [18062] skipped: 0\nstress-ng: info:  [18062] passed: 48: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4)\nstress-ng: info:  [18062] failed: 0\nstress-ng: info:  [18062] metrics untrustworthy: 0\nstress-ng: info:  [18062] successful run completed in 3.08 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "noop",
          "map_inline"
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
            "run_cnt_delta": 35693882,
            "run_time_ns_delta": 5369508188,
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
            "run_cnt_delta": 35694155,
            "run_time_ns_delta": 10339197141,
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
            "run_cnt_delta": 35693720,
            "run_time_ns_delta": 9437570101,
            "type": "raw_tracepoint"
          },
          "29": {
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 29,
            "name": "trace_sys_exit",
            "run_cnt_delta": 35693993,
            "run_time_ns_delta": 10001050454,
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
            "run_cnt_delta": 1069886,
            "run_time_ns_delta": 74766430,
            "type": "kprobe"
          },
          "35": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 35,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 1069886,
            "run_time_ns_delta": 286605664,
            "type": "kprobe"
          },
          "36": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 36,
            "name": "trace_dup",
            "run_cnt_delta": 3869,
            "run_time_ns_delta": 855227,
            "type": "kprobe"
          },
          "37": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 37,
            "name": "trace_ret_dup",
            "run_cnt_delta": 3869,
            "run_time_ns_delta": 3664768,
            "type": "kprobe"
          },
          "38": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 38,
            "name": "trace_dup2",
            "run_cnt_delta": 5385,
            "run_time_ns_delta": 688043,
            "type": "kprobe"
          },
          "39": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 39,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 5385,
            "run_time_ns_delta": 3241684,
            "type": "kprobe"
          },
          "40": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 40,
            "name": "trace_dup3",
            "run_cnt_delta": 5673,
            "run_time_ns_delta": 666574,
            "type": "kprobe"
          },
          "41": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 41,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 5673,
            "run_time_ns_delta": 2992851,
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
            "run_cnt_delta": 7834,
            "run_time_ns_delta": 20255058,
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
            "run_time_ns_delta": 22193,
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
            "run_cnt_delta": 7576,
            "run_time_ns_delta": 7651529,
            "type": "raw_tracepoint"
          },
          "58": {
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 58,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 7576,
            "run_time_ns_delta": 6181592,
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
            "run_cnt_delta": 1098171,
            "run_time_ns_delta": 441545441,
            "type": "raw_tracepoint"
          },
          "61": {
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 61,
            "name": "trace_filldir64",
            "run_cnt_delta": 297355,
            "run_time_ns_delta": 5112095,
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
            "run_cnt_delta": 7576,
            "run_time_ns_delta": 5187784,
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
            "run_cnt_delta": 2151208,
            "run_time_ns_delta": 213491326,
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
            "run_time_ns_delta": 21855,
            "type": "kprobe"
          },
          "73": {
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 73,
            "name": "trace_security_file_open",
            "run_cnt_delta": 511283,
            "run_time_ns_delta": 310292586,
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
            "run_cnt_delta": 2814,
            "run_time_ns_delta": 3389257,
            "type": "kprobe"
          },
          "76": {
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 76,
            "name": "trace_commit_creds",
            "run_cnt_delta": 130038,
            "run_time_ns_delta": 34093699,
            "type": "kprobe"
          },
          "77": {
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 77,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 7576,
            "run_time_ns_delta": 4285489,
            "type": "kprobe"
          },
          "78": {
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 78,
            "name": "trace_cap_capable",
            "run_cnt_delta": 2489432,
            "run_time_ns_delta": 277927315,
            "type": "kprobe"
          },
          "79": {
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 79,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 274331,
            "run_time_ns_delta": 95586298,
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
            "run_time_ns_delta": 25916,
            "type": "kprobe"
          },
          "85": {
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 85,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 68318,
            "run_time_ns_delta": 25200623,
            "type": "kprobe"
          },
          "86": {
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 86,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 67877,
            "run_time_ns_delta": 30432179,
            "type": "kprobe"
          },
          "87": {
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 87,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 24,
            "run_time_ns_delta": 23409,
            "type": "kprobe"
          },
          "88": {
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 88,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 260460,
            "run_time_ns_delta": 88272257,
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
            "run_cnt_delta": 446919,
            "run_time_ns_delta": 33414891,
            "type": "kprobe"
          },
          "92": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 92,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 446919,
            "run_time_ns_delta": 29236332,
            "type": "kprobe"
          },
          "93": {
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 93,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 446919,
            "run_time_ns_delta": 265470411,
            "type": "kprobe"
          },
          "94": {
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 94,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 446919,
            "run_time_ns_delta": 21288248,
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
            "run_cnt_delta": 110,
            "run_time_ns_delta": 41018,
            "type": "kprobe"
          },
          "97": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 97,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 110,
            "run_time_ns_delta": 59484,
            "type": "kprobe"
          },
          "98": {
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 98,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 110,
            "run_time_ns_delta": 399180,
            "type": "kprobe"
          },
          "99": {
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 99,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 110,
            "run_time_ns_delta": 324356,
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
            "run_cnt_delta": 2146958,
            "run_time_ns_delta": 128166781,
            "type": "kprobe"
          },
          "107": {
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 107,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 2146958,
            "run_time_ns_delta": 1485836126,
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
            "run_cnt_delta": 110,
            "run_time_ns_delta": 47419,
            "type": "kprobe"
          },
          "110": {
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 110,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 110,
            "run_time_ns_delta": 232057,
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
            "run_cnt_delta": 1047634,
            "run_time_ns_delta": 110931974,
            "type": "kprobe"
          },
          "113": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 113,
            "name": "trace_do_mmap",
            "run_cnt_delta": 1016924,
            "run_time_ns_delta": 45653395,
            "type": "kprobe"
          },
          "114": {
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 114,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 1016924,
            "run_time_ns_delta": 308620297,
            "type": "kprobe"
          },
          "115": {
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 115,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 1016920,
            "run_time_ns_delta": 97429681,
            "type": "kprobe"
          },
          "116": {
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 116,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 2269838,
            "run_time_ns_delta": 901588969,
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
            "run_time_ns_delta": 1955934,
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
            "run_time_ns_delta": 620997,
            "type": "kprobe"
          },
          "122": {
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 122,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 159,
            "run_time_ns_delta": 101364,
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
            "run_cnt_delta": 2538,
            "run_time_ns_delta": 2926802,
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
            "run_time_ns_delta": 14889,
            "type": "kprobe"
          },
          "137": {
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 137,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 3155387,
            "run_time_ns_delta": 133162223,
            "type": "kprobe"
          },
          "138": {
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 138,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 5018,
            "run_time_ns_delta": 4081090,
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
            "run_cnt_delta": 10127,
            "run_time_ns_delta": 8772669,
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
            "run_cnt_delta": 401,
            "run_time_ns_delta": 801958,
            "type": "kprobe"
          },
          "146": {
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 146,
            "name": "trace_fd_install",
            "run_cnt_delta": 983661,
            "run_time_ns_delta": 251912894,
            "type": "kprobe"
          },
          "147": {
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 147,
            "name": "trace_filp_close",
            "run_cnt_delta": 377241,
            "run_time_ns_delta": 118772893,
            "type": "kprobe"
          },
          "148": {
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 148,
            "name": "trace_file_update_time",
            "run_cnt_delta": 15978,
            "run_time_ns_delta": 3334131,
            "type": "kprobe"
          },
          "149": {
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 149,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 15978,
            "run_time_ns_delta": 13946307,
            "type": "kprobe"
          },
          "150": {
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 150,
            "name": "trace_file_modified",
            "run_cnt_delta": 193497,
            "run_time_ns_delta": 18947146,
            "type": "kprobe"
          },
          "151": {
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 151,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 193497,
            "run_time_ns_delta": 85641131,
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
            "run_time_ns_delta": 469,
            "type": "kprobe"
          },
          "156": {
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 156,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 15926,
            "type": "kprobe"
          },
          "157": {
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 157,
            "name": "trace_execute_finished",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 19942,
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
            "run_time_ns_delta": 15980,
            "type": "kprobe"
          },
          "160": {
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 160,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 267280,
            "run_time_ns_delta": 75145651,
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
            "run_cnt_delta": 377578,
            "run_time_ns_delta": 121186176,
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
            "run_cnt_delta": 342187,
            "run_time_ns_delta": 18625778,
            "type": "kprobe"
          },
          "167": {
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 167,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 342187,
            "run_time_ns_delta": 92353033,
            "type": "kprobe"
          },
          "168": {
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 168,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 66008,
            "run_time_ns_delta": 52045362,
            "type": "kprobe"
          },
          "169": {
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 169,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 934857,
            "run_time_ns_delta": 298700706,
            "type": "kprobe"
          },
          "170": {
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 170,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 2409017,
            "run_time_ns_delta": 709662858,
            "type": "kprobe"
          },
          "171": {
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 171,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 3446134,
            "run_time_ns_delta": 812085298,
            "type": "kprobe"
          },
          "173": {
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 173,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 1325213,
            "run_time_ns_delta": 353915208,
            "type": "cgroup_skb"
          },
          "174": {
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 174,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 2052554,
            "run_time_ns_delta": 797044695,
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
            "run_time_ns_delta": 232,
            "type": "kprobe"
          },
          "178": {
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 178,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 3874,
            "type": "raw_tracepoint"
          },
          "179": {
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 179,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 511283,
            "run_time_ns_delta": 143579089,
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
            "duration_s": 5.262873028000001,
            "ops_per_sec": 6565186.698629202,
            "ops_total": 34551744.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [13776] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13776]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13776] cap              281387      5.03      0.17      2.85     55966.04       93368.01\nstress-ng: metrc: [13776] eventfd          124198      5.01      0.12      3.00     24809.60       39734.03\nstress-ng: metrc: [13776] get                3161      5.03      0.07      1.58       628.34        1913.29\nstress-ng: metrc: [13776] prctl              4068      5.00      2.67      0.79       813.39        1172.85\nstress-ng: metrc: [13776] set               12609      5.04      0.05      1.60      2502.52        7652.55\nstress-ng: metrc: [13776] dup                1261      5.00      0.35      0.33       252.14        1836.78\nstress-ng: metrc: [13776] kill              41406      5.08      0.01      2.28      8155.32       18065.24\nstress-ng: metrc: [13776] sigfd           1139983      5.07      0.11      7.21    224794.68      155825.98\nstress-ng: metrc: [13776] signal                0      5.02      0.01      0.00         0.00           0.00\nstress-ng: metrc: [13776] pty                  55      5.02      0.05      3.28        10.95          16.55\nstress-ng: metrc: [13776] itimer              296      5.02      0.05      2.46        58.91         117.99\nstress-ng: metrc: [13776] timerfd          295936      5.10      0.03      2.34     58022.52      125326.46\nstress-ng: metrc: [13776] aio               23231      5.03      0.01      0.27      4617.36       82305.59\nstress-ng: metrc: [13776] aiol               5442      5.21      0.08      0.40      1045.24       11306.29\nstress-ng: metrc: [13776] hdd               55647      5.08      0.72      0.92     10957.73       33812.90\nstress-ng: metrc: [13776] io                  108      5.13      0.02      0.02        21.04        2411.09\nstress-ng: metrc: [13776] iomix              4030      5.13      0.10      2.47       785.01        1567.76\nstress-ng: metrc: [13776] io-uring          26788      5.14      0.01      1.49      5215.28       17874.21\nstress-ng: metrc: [13776] sync-file            95      5.04      0.05      1.12        18.87          80.99\nstress-ng: metrc: [13776] epoll               926      5.12      0.04      0.04       180.84       10392.23\nstress-ng: metrc: [13776] netdev           128296      5.04      0.04      0.80     25463.42      151841.81\nstress-ng: metrc: [13776] sctp              15546      5.00      0.04      1.26      3106.28       11972.03\nstress-ng: metrc: [13776] sock               1269      5.02      0.08      2.51       252.60         490.44\nstress-ng: metrc: [13776] sockdiag       29788678      5.05      0.08      3.07   5894970.66     9453788.00\nstress-ng: metrc: [13776] sockfd           134429      5.07      0.03      1.65     26507.87       79917.60\nstress-ng: metrc: [13776] sockpair         122649      5.09      0.10      2.38     24089.32       49484.61\nstress-ng: metrc: [13776] sockmany          56788      5.04      0.07      2.72     11277.25       20357.14\nstress-ng: metrc: [13776] udp              227339      5.02      0.18      4.18     45307.36       52150.36\nstress-ng: metrc: [13776] udp-flood        373622      5.03      0.05      1.35     74279.77      267040.71\nstress-ng: metrc: [13776] mmap                941      5.00      0.03      2.73       188.17         341.33\nstress-ng: metrc: [13776] mprotect        1680387      5.03      0.47     11.08    333767.99      145501.92\nstress-ng: metrc: [13776] mremap             1095      5.02      0.02      0.94       218.18        1138.04\nstress-ng: metrc: [13776] madvise              78      5.02      0.17      4.61        15.53          16.32\nstress-ng: info:  [13776] skipped: 0\nstress-ng: info:  [13776] passed: 132: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp (4) udp-flood (4) mmap (4) mprotect (4) mremap (4) madvise (4)\nstress-ng: info:  [13776] failed: 0\nstress-ng: info:  [13776] metrics untrustworthy: 0\nstress-ng: info:  [13776] successful run completed in 5.24 secs"
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
            "run_cnt_delta": 36479710,
            "run_time_ns_delta": 5485269045,
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
            "run_cnt_delta": 36479989,
            "run_time_ns_delta": 10548739426,
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
            "run_cnt_delta": 36479710,
            "run_time_ns_delta": 10049532804,
            "type": "raw_tracepoint"
          },
          "29": {
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 29,
            "name": "trace_sys_exit",
            "run_cnt_delta": 36479989,
            "run_time_ns_delta": 9936067195,
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
            "run_cnt_delta": 845021,
            "run_time_ns_delta": 58786104,
            "type": "kprobe"
          },
          "35": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 35,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 845021,
            "run_time_ns_delta": 221946096,
            "type": "kprobe"
          },
          "36": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 36,
            "name": "trace_dup",
            "run_cnt_delta": 3729,
            "run_time_ns_delta": 816870,
            "type": "kprobe"
          },
          "37": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 37,
            "name": "trace_ret_dup",
            "run_cnt_delta": 3729,
            "run_time_ns_delta": 3632100,
            "type": "kprobe"
          },
          "38": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 38,
            "name": "trace_dup2",
            "run_cnt_delta": 5123,
            "run_time_ns_delta": 718154,
            "type": "kprobe"
          },
          "39": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 39,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 5123,
            "run_time_ns_delta": 3247774,
            "type": "kprobe"
          },
          "40": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 40,
            "name": "trace_dup3",
            "run_cnt_delta": 5386,
            "run_time_ns_delta": 634718,
            "type": "kprobe"
          },
          "41": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 41,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 5386,
            "run_time_ns_delta": 2990303,
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
            "run_cnt_delta": 6724,
            "run_time_ns_delta": 18097176,
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
            "run_time_ns_delta": 23725,
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
            "run_cnt_delta": 6579,
            "run_time_ns_delta": 6878977,
            "type": "raw_tracepoint"
          },
          "58": {
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 58,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 6576,
            "run_time_ns_delta": 5681344,
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
            "run_cnt_delta": 697786,
            "run_time_ns_delta": 294107332,
            "type": "raw_tracepoint"
          },
          "61": {
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 61,
            "name": "trace_filldir64",
            "run_cnt_delta": 206477,
            "run_time_ns_delta": 3557025,
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
            "run_cnt_delta": 6579,
            "run_time_ns_delta": 4646282,
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
            "run_cnt_delta": 2143548,
            "run_time_ns_delta": 206075939,
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
            "run_time_ns_delta": 15251,
            "type": "kprobe"
          },
          "73": {
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 73,
            "name": "trace_security_file_open",
            "run_cnt_delta": 489551,
            "run_time_ns_delta": 287507809,
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
            "run_cnt_delta": 2682,
            "run_time_ns_delta": 3256886,
            "type": "kprobe"
          },
          "76": {
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 76,
            "name": "trace_commit_creds",
            "run_cnt_delta": 342257,
            "run_time_ns_delta": 78564694,
            "type": "kprobe"
          },
          "77": {
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 77,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 6579,
            "run_time_ns_delta": 3973475,
            "type": "kprobe"
          },
          "78": {
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 78,
            "name": "trace_cap_capable",
            "run_cnt_delta": 2412461,
            "run_time_ns_delta": 312360692,
            "type": "kprobe"
          },
          "79": {
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 79,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 64056,
            "run_time_ns_delta": 22993717,
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
            "run_time_ns_delta": 32238,
            "type": "kprobe"
          },
          "85": {
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 85,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 42582,
            "run_time_ns_delta": 16648190,
            "type": "kprobe"
          },
          "86": {
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 86,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 41867,
            "run_time_ns_delta": 20960868,
            "type": "kprobe"
          },
          "87": {
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 87,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 24,
            "run_time_ns_delta": 24395,
            "type": "kprobe"
          },
          "88": {
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 88,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 228927,
            "run_time_ns_delta": 74350424,
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
            "run_cnt_delta": 325266,
            "run_time_ns_delta": 25149411,
            "type": "kprobe"
          },
          "92": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 92,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 325266,
            "run_time_ns_delta": 10867802,
            "type": "kprobe"
          },
          "93": {
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 93,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 325266,
            "run_time_ns_delta": 186783606,
            "type": "kprobe"
          },
          "94": {
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 94,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 325266,
            "run_time_ns_delta": 18236297,
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
            "run_cnt_delta": 107,
            "run_time_ns_delta": 31632,
            "type": "kprobe"
          },
          "97": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 97,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 107,
            "run_time_ns_delta": 50304,
            "type": "kprobe"
          },
          "98": {
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 98,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 107,
            "run_time_ns_delta": 425693,
            "type": "kprobe"
          },
          "99": {
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 99,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 107,
            "run_time_ns_delta": 324633,
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
            "run_cnt_delta": 1342154,
            "run_time_ns_delta": 102333339,
            "type": "kprobe"
          },
          "107": {
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 107,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 1342154,
            "run_time_ns_delta": 840757528,
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
            "run_cnt_delta": 107,
            "run_time_ns_delta": 36807,
            "type": "kprobe"
          },
          "110": {
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 110,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 107,
            "run_time_ns_delta": 241000,
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
            "run_cnt_delta": 788421,
            "run_time_ns_delta": 90011445,
            "type": "kprobe"
          },
          "113": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 113,
            "name": "trace_do_mmap",
            "run_cnt_delta": 730643,
            "run_time_ns_delta": 38436294,
            "type": "kprobe"
          },
          "114": {
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 114,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 730643,
            "run_time_ns_delta": 231575149,
            "type": "kprobe"
          },
          "115": {
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 115,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 730639,
            "run_time_ns_delta": 77749629,
            "type": "kprobe"
          },
          "116": {
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 116,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 3059307,
            "run_time_ns_delta": 1274825004,
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
            "run_time_ns_delta": 2037773,
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
            "run_time_ns_delta": 654425,
            "type": "kprobe"
          },
          "122": {
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 122,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 159,
            "run_time_ns_delta": 115717,
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
            "run_cnt_delta": 2412,
            "run_time_ns_delta": 2695509,
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
            "run_time_ns_delta": 16983,
            "type": "kprobe"
          },
          "137": {
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 137,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 2199606,
            "run_time_ns_delta": 100273681,
            "type": "kprobe"
          },
          "138": {
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 138,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 4163,
            "run_time_ns_delta": 3524393,
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
            "run_cnt_delta": 8354,
            "run_time_ns_delta": 7513963,
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
            "run_cnt_delta": 384,
            "run_time_ns_delta": 749899,
            "type": "kprobe"
          },
          "146": {
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 146,
            "name": "trace_fd_install",
            "run_cnt_delta": 734765,
            "run_time_ns_delta": 202541349,
            "type": "kprobe"
          },
          "147": {
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 147,
            "name": "trace_filp_close",
            "run_cnt_delta": 362080,
            "run_time_ns_delta": 107744884,
            "type": "kprobe"
          },
          "148": {
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 148,
            "name": "trace_file_update_time",
            "run_cnt_delta": 15406,
            "run_time_ns_delta": 3341043,
            "type": "kprobe"
          },
          "149": {
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 149,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 15406,
            "run_time_ns_delta": 14124933,
            "type": "kprobe"
          },
          "150": {
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 150,
            "name": "trace_file_modified",
            "run_cnt_delta": 182961,
            "run_time_ns_delta": 18455594,
            "type": "kprobe"
          },
          "151": {
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 151,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 182961,
            "run_time_ns_delta": 82220172,
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
            "run_time_ns_delta": 598,
            "type": "kprobe"
          },
          "156": {
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 156,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 16757,
            "type": "kprobe"
          },
          "157": {
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 157,
            "name": "trace_execute_finished",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 22287,
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
            "run_time_ns_delta": 16314,
            "type": "kprobe"
          },
          "160": {
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 160,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 636824,
            "run_time_ns_delta": 175702318,
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
            "run_cnt_delta": 298225,
            "run_time_ns_delta": 98170989,
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
            "run_cnt_delta": 105908,
            "run_time_ns_delta": 7345786,
            "type": "kprobe"
          },
          "167": {
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 167,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 105908,
            "run_time_ns_delta": 55392004,
            "type": "kprobe"
          },
          "168": {
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 168,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 40756,
            "run_time_ns_delta": 35416987,
            "type": "kprobe"
          },
          "169": {
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 169,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 641120,
            "run_time_ns_delta": 166899166,
            "type": "kprobe"
          },
          "170": {
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 170,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 2227138,
            "run_time_ns_delta": 690014514,
            "type": "kprobe"
          },
          "171": {
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 171,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 3447438,
            "run_time_ns_delta": 764033518,
            "type": "kprobe"
          },
          "173": {
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 173,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 1057183,
            "run_time_ns_delta": 249404770,
            "type": "cgroup_skb"
          },
          "174": {
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 174,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 2342615,
            "run_time_ns_delta": 516458438,
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
            "run_time_ns_delta": 227,
            "type": "kprobe"
          },
          "178": {
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 178,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 4979,
            "type": "raw_tracepoint"
          },
          "179": {
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 179,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 489551,
            "run_time_ns_delta": 195021513,
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
            "duration_s": 5.375094025999999,
            "ops_per_sec": 4583455.448561488,
            "ops_total": 24636504.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [29065] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [29065]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29065] cap              195754      5.04      0.08      2.00     38852.86       93970.60\nstress-ng: metrc: [29065] eventfd          125375      5.00      0.12      3.12     25071.93       38730.93\nstress-ng: metrc: [29065] get                4372      5.01      0.08      2.20       873.51        1917.64\nstress-ng: metrc: [29065] prctl              3213      5.01      2.18      0.64       641.58        1140.89\nstress-ng: metrc: [29065] set               36583      5.03      0.09      4.54      7271.42        7900.81\nstress-ng: metrc: [29065] dup                1198      5.01      0.35      0.33       239.01        1758.58\nstress-ng: metrc: [29065] kill              13849      5.04      0.03      1.31      2745.29       10318.53\nstress-ng: metrc: [29065] sigfd            372024      5.05      0.07      2.24     73684.55      161400.87\nstress-ng: metrc: [29065] signal                0      5.03      0.01      0.00         0.00           0.00\nstress-ng: metrc: [29065] pty                  29      5.05      0.08      1.64         5.74          16.86\nstress-ng: metrc: [29065] itimer              578      5.03      0.13      4.83       115.01         116.48\nstress-ng: metrc: [29065] timerfd          376832      5.08      0.10      3.57     74111.54      102850.17\nstress-ng: metrc: [29065] aio               19517      5.07      0.04      0.19      3851.80       85893.22\nstress-ng: metrc: [29065] aiol               5192      5.18      0.06      0.40      1002.75       11185.89\nstress-ng: metrc: [29065] hdd               54494      5.07      0.83      0.77     10738.02       33910.22\nstress-ng: metrc: [29065] io                  154      5.06      0.02      0.01        30.42        4210.99\nstress-ng: metrc: [29065] iomix              4737      5.15      0.11      2.51       920.50        1804.28\nstress-ng: metrc: [29065] io-uring          26508      5.08      0.00      1.70      5216.46       15609.00\nstress-ng: metrc: [29065] sync-file            92      5.07      0.02      1.08        18.16          83.62\nstress-ng: metrc: [29065] epoll               484      5.10      0.04      0.02        94.82        7752.31\nstress-ng: metrc: [29065] netdev           262021      5.02      0.08      1.77     52166.29      141712.56\nstress-ng: metrc: [29065] sctp               9788      5.01      0.01      1.21      1955.48        8048.42\nstress-ng: metrc: [29065] sock               1141      5.03      0.14      2.03       226.61         527.23\nstress-ng: metrc: [29065] sockdiag       19934689      5.04      0.04      1.72   3958205.89    11334249.30\nstress-ng: metrc: [29065] sockfd           145395      5.06      0.00      1.69     28718.82       86184.67\nstress-ng: metrc: [29065] sockpair           1818      5.06      0.02      0.17       359.50        9311.04\nstress-ng: metrc: [29065] sockmany          31364      5.04      0.04      1.66      6228.14       18399.16\nstress-ng: metrc: [29065] udp               92219      5.02      0.05      2.38     18355.30       37965.13\nstress-ng: metrc: [29065] udp-flood        650563      5.02      0.12      3.30    129478.35      189967.31\nstress-ng: metrc: [29065] mmap                648      5.02      0.06      1.95       128.99         323.19\nstress-ng: metrc: [29065] mprotect        2263870      5.03      0.58     16.21    450351.76      134833.60\nstress-ng: metrc: [29065] mremap             1927      5.01      0.01      1.73       384.62        1108.46\nstress-ng: metrc: [29065] madvise              76      5.03      0.15      4.69        15.12          15.72\nstress-ng: info:  [29065] skipped: 0\nstress-ng: info:  [29065] passed: 132: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp (4) udp-flood (4) mmap (4) mprotect (4) mremap (4) madvise (4)\nstress-ng: info:  [29065] failed: 0\nstress-ng: info:  [29065] metrics untrustworthy: 0\nstress-ng: info:  [29065] successful run completed in 5.35 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "noop",
          "map_inline"
        ],
        "error": "prog 46: prog 46 pass noop failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nfunc#1 @2329\nLive regs before insn:\n      0: .1........ (bf) r8 = r1\n      1: ........8. (b7) r1 = 0\n      2: .1......8. (63) *(u32 *)(r10 -176) = r1\n      3: ........8. (bf) r2 = r10\n      4: ..2.....8. (07) r2 += -176\n      5: ..2.....8. (18) r1 = 0xffff8aa78668f000\n      7: .12.....8. (85) call bpf_map_lookup_elem#1\n      8: 0.......8. (bf) r7 = r0\n      9: .......78. (15) if r7 == 0x0 goto pc+23\n     10: .......78. (bf) r2 = r10\n     11: ..2....78. (07) r2 += -176\n     12: ..2....78. (18) r1 = 0xffff8aa7c360c800\n     14: .12....78. (85) call bpf_map_lookup_elem#1\n     15: 0......78. (7b) *(u64 *)(r10 -208) = r0\n     16: 0......78. (15) if r0 == 0x0 goto pc+16\n     17: .......78. (bf) r6 = r7\n     18: ......678. (07) r6 += 40\n     19: ......678. (18) r1 = 0xffff8aa8075f0c00\n     21: .1....678. (bf) r2 = r6\n     22: .12...678. (85) call bpf_map_lookup_elem#1\n     23: 0.....678. (7b) *(u64 *)(r10 -184) = r0\n     24: 0.....678. (15) if r0 == 0x0 goto pc+8\n     25: ......678. (bf) r9 = r7\n     26: ......6789 (07) r9 += 36\n     27: ......6789 (18) r1 = 0xffff8aa7d25dac00\n     29: .1....6789 (bf) r2 = r9\n     30: .12...6789 (85) call bpf_map_lookup_elem#1\n     31: 0.....6789 (7b) *(u64 *)(r10 -216) = r0\n     32: 0.....6789 (55) if r0 != 0x0 goto pc+1\n     33: .......... (05) goto pc+38\n     34: ......6789 (7b) *(u64 *)(r10 -192) = r7\n     35: ......6.89 (79) r1 = *(u64 *)(r10 -184)\n     36: .1....6.89 (79) r1 = *(u64 *)(r1 +168)\n     37: .1....6.89 (15) if r1 == 0xffffffff goto pc+34\n     38: ......6.89 (79) r7 = *(u64 *)(r10 -192)\n     39: ......6789 (b7) r1 = 0\n     40: .1....6789 (6b) *(u16 *)(r7 +32146) = r1\n     41: .1....6789 (73) *(u8 *)(r7 +144) = r1\n     42: ......6789 (b7) r1 = -1\n     43: .1....6789 (63) *(u32 *)(r7 +32148) = r1\n     44: .1....6789 (63) *(u32 *)(r7 +32156) = r1\n     45: .1....6789 (63) *(u32 *)(r7 +32164) = r1\n     46: .1....6789 (63) *(u32 *)(r7 +32172) = r1\n     47: .1....6789 (63) *(u32 *)(r7 +32180) = r1\n     48: .1....6789 (63) *(u32 *)(r7 +32188) = r1\n     49: .1....6789 (63) *(u32 *)(r7 +32196) = r1\n     50: .1....6789 (63) *(u32 *)(r7 +32204) = r1\n     51: .1....6789 (7b) *(u64 *)(r7 +32224) = r1\n     52: .1....6789 (77) r1 >>= 32\n     53: .1....6789 (63) *(u32 *)(r7 +32152) = r1\n     54: .1....6789 (63) *(u32 *)(r7 +32160) = r1\n     55: .1....6789 (63) *(u32 *)(r7 +32168) = r1\n     56: .1....6789 (63) *(u32 *)(r7 +32176) = r1\n     57: .1....6789 (63) *(u32 *)(r7 +32184) = r1\n     58: .1....6789 (63) *(u32 *)(r7 +32192) = r1\n     59: .1....6789 (63) *(u32 *)(r7 +32200) = r1\n     60: .1....6789 (63) *(u32 *)(r7 +32208) = r1\n     61: ......6789 (b7) r1 = 749\n     62: .1....6789 (63) *(u32 *)(r7 +112) = r1\n     63: .1....6789 (69) r2 = *(u16 *)(r7 +134)\n     64: .12...6789 (63) *(u32 *)(r10 -176) = r1\n     65: ..2...6789 (6b) *(u16 *)(r10 -64) = r2\n     66: ......6789 (bf) r2 = r10\n     67: ..2...6789 (07) r2 += -64\n     68: ..2...6789 (18) r1 = 0xffff8aaa88237000\n     70: .12...6789 (85) call bpf_map_lookup_elem#1\n     71: 0.....6789 (55) if r0 != 0x0 goto pc+2\n     72: .......... (b7) r0 = 0\n     73: 0......... (95) exit\n     74: 0.....6789 (bf) r2 = r10\n     75: 0.2...6789 (07) r2 += -176\n     76: 0.2...6789 (bf) r1 = r0\n     77: .12...6789 (85) call bpf_map_lookup_elem#1\n     78: 0....56789 (15) if r0 == 0x0 goto pc-7\n     79: 0....56789 (79) r1 = *(u64 *)(r0 +8)\n     80: 01...56789 (7b) *(u64 *)(r7 +32232) = r1\n     81: 0....56789 (79) r1 = *(u64 *)(r0 +0)\n     82: 01...56789 (7b) *(u64 *)(r7 +136) = r1\n     83: 01...56789 (7b) *(u64 *)(r7 +32224) = r1\n     84: 01...56789 (79) r2 = *(u64 *)(r0 +56)\n     85: 012..56789 (7b) *(u64 *)(r7 +32280) = r2\n     86: 01...56789 (79) r2 = *(u64 *)(r0 +48)\n     87: 012..56789 (7b) *(u64 *)(r7 +32272) = r2\n     88: 01...56789 (79) r2 = *(u64 *)(r0 +40)\n     89: 012..56789 (7b) *(u64 *)(r7 +32264) = r2\n     90: 01...56789 (79) r2 = *(u64 *)(r0 +32)\n     91: 012..56789 (7b) *(u64 *)(r7 +32256) = r2\n     92: 01...56789 (79) r2 = *(u64 *)(r0 +24)\n     93: 012..56789 (7b) *(u64 *)(r7 +32248) = r2\n     94: 01...56789 (79) r2 = *(u64 *)(r0 +16)\n  \n... verifier log truncated ...; prog 47: prog 47 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-21/pass-01-map_inline.report.json\" \"--prog-type\" \"raw_tracepoint\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-21/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-21/map-values.json\" \"--map-ids\" \"172,133,130,142,175,132,149,217,174,218,187,184,190,233,193,196,208,211,145,214,168,219,231,232\": error: map_values snapshot missing map 233 key 00000000; prog 48: prog 48 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-34/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-34/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-34/map-values.json\" \"--map-ids\" \"172,133,132,142,146,147,228,152,233,168,219,175,174,218,148,231,232\": error: map_values snapshot missing map 233 key 00000000; prog 50: prog 50 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-89/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-89/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-89/map-values.json\" \"--map-ids\" \"175,172,133,130,142,174,218,132,149,217,233,158,228,148,231,232\": error: map_values snapshot missing map 233 key 00000000; prog 51: prog 51 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-7/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-7/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-7/map-values.json\" \"--map-ids\" \"175,172,133,132,142,158,228,152,233,168,219,148,174,218,231,232\": error: map_values snapshot missing map 233 key 00000000; prog 53: prog 53 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-13/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-13/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-13/map-values.json\" \"--map-ids\" \"175,172,133,132,142,158,228,233,168,219,148,174,218,231,232\": error: map_values snapshot missing map 233 key 00000000; prog 155: prog 155 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-90/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-90/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-90/map-values.json\" \"--map-ids\" \"233,172,133,130,142,175,132,149,217,187,184,190,193,196,208,211,145,214,164,232,148,231\": error: map_values snapshot missing map 233 key 00000000; prog 164: prog 164 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-124/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-124/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-124/map-values.json\" \"--map-ids\" \"156,130,229,172,133,142,175,132,149,217,187,184,190,193,196,208,211,145,214,233,174,218,230,167,232,168,219,231\": error: map_values snapshot missing map 233 key 00000000",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 46 pass noop failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nfunc#1 @2329\nLive regs before insn:\n      0: .1........ (bf) r8 = r1\n      1: ........8. (b7) r1 = 0\n      2: .1......8. (63) *(u32 *)(r10 -176) = r1\n      3: ........8. (bf) r2 = r10\n      4: ..2.....8. (07) r2 += -176\n      5: ..2.....8. (18) r1 = 0xffff8aa78668f000\n      7: .12.....8. (85) call bpf_map_lookup_elem#1\n      8: 0.......8. (bf) r7 = r0\n      9: .......78. (15) if r7 == 0x0 goto pc+23\n     10: .......78. (bf) r2 = r10\n     11: ..2....78. (07) r2 += -176\n     12: ..2....78. (18) r1 = 0xffff8aa7c360c800\n     14: .12....78. (85) call bpf_map_lookup_elem#1\n     15: 0......78. (7b) *(u64 *)(r10 -208) = r0\n     16: 0......78. (15) if r0 == 0x0 goto pc+16\n     17: .......78. (bf) r6 = r7\n     18: ......678. (07) r6 += 40\n     19: ......678. (18) r1 = 0xffff8aa8075f0c00\n     21: .1....678. (bf) r2 = r6\n     22: .12...678. (85) call bpf_map_lookup_elem#1\n     23: 0.....678. (7b) *(u64 *)(r10 -184) = r0\n     24: 0.....678. (15) if r0 == 0x0 goto pc+8\n     25: ......678. (bf) r9 = r7\n     26: ......6789 (07) r9 += 36\n     27: ......6789 (18) r1 = 0xffff8aa7d25dac00\n     29: .1....6789 (bf) r2 = r9\n     30: .12...6789 (85) call bpf_map_lookup_elem#1\n     31: 0.....6789 (7b) *(u64 *)(r10 -216) = r0\n     32: 0.....6789 (55) if r0 != 0x0 goto pc+1\n     33: .......... (05) goto pc+38\n     34: ......6789 (7b) *(u64 *)(r10 -192) = r7\n     35: ......6.89 (79) r1 = *(u64 *)(r10 -184)\n     36: .1....6.89 (79) r1 = *(u64 *)(r1 +168)\n     37: .1....6.89 (15) if r1 == 0xffffffff goto pc+34\n     38: ......6.89 (79) r7 = *(u64 *)(r10 -192)\n     39: ......6789 (b7) r1 = 0\n     40: .1....6789 (6b) *(u16 *)(r7 +32146) = r1\n     41: .1....6789 (73) *(u8 *)(r7 +144) = r1\n     42: ......6789 (b7) r1 = -1\n     43: .1....6789 (63) *(u32 *)(r7 +32148) = r1\n     44: .1....6789 (63) *(u32 *)(r7 +32156) = r1\n     45: .1....6789 (63) *(u32 *)(r7 +32164) = r1\n     46: .1....6789 (63) *(u32 *)(r7 +32172) = r1\n     47: .1....6789 (63) *(u32 *)(r7 +32180) = r1\n     48: .1....6789 (63) *(u32 *)(r7 +32188) = r1\n     49: .1....6789 (63) *(u32 *)(r7 +32196) = r1\n     50: .1....6789 (63) *(u32 *)(r7 +32204) = r1\n     51: .1....6789 (7b) *(u64 *)(r7 +32224) = r1\n     52: .1....6789 (77) r1 >>= 32\n     53: .1....6789 (63) *(u32 *)(r7 +32152) = r1\n     54: .1....6789 (63) *(u32 *)(r7 +32160) = r1\n     55: .1....6789 (63) *(u32 *)(r7 +32168) = r1\n     56: .1....6789 (63) *(u32 *)(r7 +32176) = r1\n     57: .1....6789 (63) *(u32 *)(r7 +32184) = r1\n     58: .1....6789 (63) *(u32 *)(r7 +32192) = r1\n     59: .1....6789 (63) *(u32 *)(r7 +32200) = r1\n     60: .1....6789 (63) *(u32 *)(r7 +32208) = r1\n     61: ......6789 (b7) r1 = 749\n     62: .1....6789 (63) *(u32 *)(r7 +112) = r1\n     63: .1....6789 (69) r2 = *(u16 *)(r7 +134)\n     64: .12...6789 (63) *(u32 *)(r10 -176) = r1\n     65: ..2...6789 (6b) *(u16 *)(r10 -64) = r2\n     66: ......6789 (bf) r2 = r10\n     67: ..2...6789 (07) r2 += -64\n     68: ..2...6789 (18) r1 = 0xffff8aaa88237000\n     70: .12...6789 (85) call bpf_map_lookup_elem#1\n     71: 0.....6789 (55) if r0 != 0x0 goto pc+2\n     72: .......... (b7) r0 = 0\n     73: 0......... (95) exit\n     74: 0.....6789 (bf) r2 = r10\n     75: 0.2...6789 (07) r2 += -176\n     76: 0.2...6789 (bf) r1 = r0\n     77: .12...6789 (85) call bpf_map_lookup_elem#1\n     78: 0....56789 (15) if r0 == 0x0 goto pc-7\n     79: 0....56789 (79) r1 = *(u64 *)(r0 +8)\n     80: 01...56789 (7b) *(u64 *)(r7 +32232) = r1\n     81: 0....56789 (79) r1 = *(u64 *)(r0 +0)\n     82: 01...56789 (7b) *(u64 *)(r7 +136) = r1\n     83: 01...56789 (7b) *(u64 *)(r7 +32224) = r1\n     84: 01...56789 (79) r2 = *(u64 *)(r0 +56)\n     85: 012..56789 (7b) *(u64 *)(r7 +32280) = r2\n     86: 01...56789 (79) r2 = *(u64 *)(r0 +48)\n     87: 012..56789 (7b) *(u64 *)(r7 +32272) = r2\n     88: 01...56789 (79) r2 = *(u64 *)(r0 +40)\n     89: 012..56789 (7b) *(u64 *)(r7 +32264) = r2\n     90: 01...56789 (79) r2 = *(u64 *)(r0 +32)\n     91: 012..56789 (7b) *(u64 *)(r7 +32256) = r2\n     92: 01...56789 (79) r2 = *(u64 *)(r0 +24)\n     93: 012..56789 (7b) *(u64 *)(r7 +32248) = r2\n     94: 01...56789 (79) r2 = *(u64 *)(r0 +16)\n  \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 46
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 47 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-21/pass-01-map_inline.report.json\" \"--prog-type\" \"raw_tracepoint\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-21/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-21/map-values.json\" \"--map-ids\" \"172,133,130,142,175,132,149,217,174,218,187,184,190,233,193,196,208,211,145,214,168,219,231,232\": error: map_values snapshot missing map 233 key 00000000",
            "exit_code": 1,
            "prog_id": 47
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 48 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-34/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-34/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-34/map-values.json\" \"--map-ids\" \"172,133,132,142,146,147,228,152,233,168,219,175,174,218,148,231,232\": error: map_values snapshot missing map 233 key 00000000",
            "exit_code": 1,
            "prog_id": 48
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 50 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-89/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-89/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-89/map-values.json\" \"--map-ids\" \"175,172,133,130,142,174,218,132,149,217,233,158,228,148,231,232\": error: map_values snapshot missing map 233 key 00000000",
            "exit_code": 1,
            "prog_id": 50
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 51 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-7/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-7/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-7/map-values.json\" \"--map-ids\" \"175,172,133,132,142,158,228,152,233,168,219,148,174,218,231,232\": error: map_values snapshot missing map 233 key 00000000",
            "exit_code": 1,
            "prog_id": 51
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 53 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-13/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-13/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-13/map-values.json\" \"--map-ids\" \"175,172,133,132,142,158,228,233,168,219,148,174,218,231,232\": error: map_values snapshot missing map 233 key 00000000",
            "exit_code": 1,
            "prog_id": 53
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 155 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-90/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-90/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-90/map-values.json\" \"--map-ids\" \"233,172,133,130,142,175,132,149,217,187,184,190,193,196,208,211,145,214,164,232,148,231\": error: map_values snapshot missing map 233 key 00000000",
            "exit_code": 1,
            "prog_id": 155
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 164 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-124/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-124/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.f2ebb89e/bpfrejit-daemon-optimize-1850-124/map-values.json\" \"--map-ids\" \"156,130,229,172,133,142,175,132,149,217,187,184,190,193,196,208,211,145,214,233,174,218,230,167,232,168,219,231\": error: map_values snapshot missing map 233 key 00000000",
            "exit_code": 1,
            "prog_id": 164
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 150,
          "not_applied": 8,
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
            "run_cnt_delta": 1438341,
            "run_time_ns_delta": 548808548,
            "type": "tracepoint"
          },
          "187": {
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 187,
            "name": "block_io_done",
            "run_cnt_delta": 1438356,
            "run_time_ns_delta": 1096086430,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.332098643999984,
            "ops_per_sec": 361185.3659472557,
            "ops_total": 1925876.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.103413,\n        \"1000\" : 12.382912\n      },\n      \"latency_us\" : {\n        \"2\" : 35.183068,\n        \"4\" : 1.710130,\n        \"10\" : 10.978273,\n        \"20\" : 35.156647,\n        \"50\" : 2.545277,\n        \"100\" : 1.540253,\n        \"250\" : 0.383309,\n        \"500\" : 0.016513,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
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
            "run_cnt_delta": 1439569,
            "run_time_ns_delta": 557065054,
            "type": "tracepoint"
          },
          "187": {
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 187,
            "name": "block_io_done",
            "run_cnt_delta": 1439584,
            "run_time_ns_delta": 1113783937,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.3412632710000025,
            "ops_per_sec": 361030.5094807597,
            "ops_total": 1928359.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.093844,\n        \"1000\" : 13.457291\n      },\n      \"latency_us\" : {\n        \"2\" : 34.106820,\n        \"4\" : 1.716519,\n        \"10\" : 11.211698,\n        \"20\" : 34.904915,\n        \"50\" : 2.517950,\n        \"100\" : 1.646031,\n        \"250\" : 0.323868,\n        \"500\" : 0.020854,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "noop",
          "map_inline"
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
