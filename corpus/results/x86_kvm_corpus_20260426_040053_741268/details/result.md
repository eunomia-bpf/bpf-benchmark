# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-04-26T04:03:33.250580+00:00",
  "kinsn_modules": {
    "captured_at": "2026-04-26T04:00:53.772952+00:00",
    "daemon_binary": "daemon/target/release/bpfrejit-daemon",
    "expected_modules": [
      "bpf_bulk_memory",
      "bpf_endian",
      "bpf_extract",
      "bpf_rotate",
      "bpf_select"
    ],
    "module_load": {
      "expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_rotate",
        "bpf_select"
      ],
      "failed_modules": [],
      "invoked_at": "2026-04-26T04:00:53.772896+00:00",
      "loaded_count": 5,
      "loaded_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_rotate",
        "bpf_select"
      ],
      "loader": "runner.libs.kinsn.load_kinsn_modules",
      "module_dir": "/artifacts/kinsn",
      "newly_loaded_modules": [],
      "snapshot_after": {
        "captured_at": "2026-04-26T04:00:53.772890+00:00",
        "expected_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_rotate",
          "bpf_select"
        ],
        "loaded_bpf_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_rotate",
          "bpf_select"
        ],
        "missing_expected_modules": [],
        "raw_output": "bpf_select             12288  0\nbpf_rotate             12288  0\nbpf_extract            12288  0\nbpf_endian             12288  0\nbpf_bulk_memory        12288  0",
        "resident_expected_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_rotate",
          "bpf_select"
        ],
        "source": "lsmod"
      },
      "status": "ok",
      "total_count": 5
    },
    "module_snapshot_before_daemon": {
      "captured_at": "2026-04-26T04:00:53.764681+00:00",
      "expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_rotate",
        "bpf_select"
      ],
      "loaded_bpf_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_rotate",
        "bpf_select"
      ],
      "missing_expected_modules": [],
      "raw_output": "bpf_select             12288  0\nbpf_rotate             12288  0\nbpf_extract            12288  0\nbpf_endian             12288  0\nbpf_bulk_memory        12288  0",
      "resident_expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_rotate",
        "bpf_select"
      ],
      "source": "lsmod"
    }
  },
  "manifest": "/home/yunwei37/workspace/bpf-benchmark/docs/tmp/new-app-integration-review-20260425/tracee-only.yaml",
  "results": [
    {
      "app": "tracee/default",
      "baseline": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 151.43763877022278,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 18,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 723318,
            "run_time_ns_delta": 109537570,
            "type": "raw_tracepoint"
          },
          "19": {
            "avg_ns_per_run": null,
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 19,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "20": {
            "avg_ns_per_run": null,
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 20,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "21": {
            "avg_ns_per_run": 152.83272056790915,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 21,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 723496,
            "run_time_ns_delta": 110573862,
            "type": "raw_tracepoint"
          },
          "22": {
            "avg_ns_per_run": null,
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 22,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "23": {
            "avg_ns_per_run": null,
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 23,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "24": {
            "avg_ns_per_run": 157.9324404622073,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 24,
            "name": "trace_sys_enter",
            "run_cnt_delta": 723658,
            "run_time_ns_delta": 114289074,
            "type": "raw_tracepoint"
          },
          "25": {
            "avg_ns_per_run": 150.29379369421648,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 25,
            "name": "trace_sys_exit",
            "run_cnt_delta": 723780,
            "run_time_ns_delta": 108779642,
            "type": "raw_tracepoint"
          },
          "26": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 26,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "27": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 27,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "28": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 28,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "29": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 29,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "30": {
            "avg_ns_per_run": 357.7253086419753,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 30,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 324,
            "run_time_ns_delta": 115903,
            "type": "kprobe"
          },
          "31": {
            "avg_ns_per_run": 1467.858024691358,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 31,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 324,
            "run_time_ns_delta": 475586,
            "type": "kprobe"
          },
          "32": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 32,
            "name": "trace_dup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "33": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 33,
            "name": "trace_ret_dup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "34": {
            "avg_ns_per_run": 384.6646153846154,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 34,
            "name": "trace_dup2",
            "run_cnt_delta": 325,
            "run_time_ns_delta": 125016,
            "type": "kprobe"
          },
          "35": {
            "avg_ns_per_run": 2076.803076923077,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 35,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 325,
            "run_time_ns_delta": 674961,
            "type": "kprobe"
          },
          "36": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 36,
            "name": "trace_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "37": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 37,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "38": {
            "avg_ns_per_run": null,
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 38,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "39": {
            "avg_ns_per_run": null,
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 39,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "40": {
            "avg_ns_per_run": null,
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 40,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "41": {
            "avg_ns_per_run": null,
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 41,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "42": {
            "avg_ns_per_run": null,
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 42,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "43": {
            "avg_ns_per_run": 3018.181443298969,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 43,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 970,
            "run_time_ns_delta": 2927636,
            "type": "raw_tracepoint"
          },
          "44": {
            "avg_ns_per_run": null,
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 44,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "45": {
            "avg_ns_per_run": null,
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 45,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "46": {
            "avg_ns_per_run": null,
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 46,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "47": {
            "avg_ns_per_run": null,
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 47,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "48": {
            "avg_ns_per_run": null,
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 48,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "49": {
            "avg_ns_per_run": null,
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 49,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "50": {
            "avg_ns_per_run": null,
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 50,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "51": {
            "avg_ns_per_run": 4261.731481481482,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 51,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 324,
            "run_time_ns_delta": 1380801,
            "type": "raw_tracepoint"
          },
          "52": {
            "avg_ns_per_run": null,
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 52,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "53": {
            "avg_ns_per_run": 1837.0742268041238,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 53,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 970,
            "run_time_ns_delta": 1781962,
            "type": "raw_tracepoint"
          },
          "54": {
            "avg_ns_per_run": 568.1663223140496,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 54,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 968,
            "run_time_ns_delta": 549985,
            "type": "raw_tracepoint"
          },
          "55": {
            "avg_ns_per_run": null,
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 55,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "56": {
            "avg_ns_per_run": 290.8058581104299,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 56,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 884688,
            "run_time_ns_delta": 257272453,
            "type": "raw_tracepoint"
          },
          "57": {
            "avg_ns_per_run": 18.269430051813472,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 57,
            "name": "trace_filldir64",
            "run_cnt_delta": 193,
            "run_time_ns_delta": 3526,
            "type": "kprobe"
          },
          "58": {
            "avg_ns_per_run": null,
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 58,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "59": {
            "avg_ns_per_run": 1294.656701030928,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 59,
            "name": "trace_do_exit",
            "run_cnt_delta": 970,
            "run_time_ns_delta": 1255817,
            "type": "kprobe"
          },
          "60": {
            "avg_ns_per_run": null,
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 60,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "61": {
            "avg_ns_per_run": null,
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 61,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "62": {
            "avg_ns_per_run": null,
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 62,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "63": {
            "avg_ns_per_run": 517.2962962962963,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 63,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 648,
            "run_time_ns_delta": 335208,
            "type": "kprobe"
          },
          "64": {
            "avg_ns_per_run": null,
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 64,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "65": {
            "avg_ns_per_run": null,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 65,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "66": {
            "avg_ns_per_run": 1817.0,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 66,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1817,
            "type": "raw_tracepoint"
          },
          "67": {
            "avg_ns_per_run": 1103.0,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 67,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1103,
            "type": "raw_tracepoint"
          },
          "68": {
            "avg_ns_per_run": 2618.614197530864,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 68,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 324,
            "run_time_ns_delta": 848431,
            "type": "kprobe"
          },
          "69": {
            "avg_ns_per_run": 1759.847965738758,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 69,
            "name": "trace_security_file_open",
            "run_cnt_delta": 3736,
            "run_time_ns_delta": 6574792,
            "type": "kprobe"
          },
          "70": {
            "avg_ns_per_run": null,
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 70,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "71": {
            "avg_ns_per_run": 3175.0,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 71,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3175,
            "type": "kprobe"
          },
          "72": {
            "avg_ns_per_run": 946.7716049382716,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 72,
            "name": "trace_commit_creds",
            "run_cnt_delta": 324,
            "run_time_ns_delta": 306754,
            "type": "kprobe"
          },
          "73": {
            "avg_ns_per_run": 569.5494845360824,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 73,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 970,
            "run_time_ns_delta": 552463,
            "type": "kprobe"
          },
          "74": {
            "avg_ns_per_run": 168.66498865723236,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 74,
            "name": "trace_cap_capable",
            "run_cnt_delta": 46285,
            "run_time_ns_delta": 7806659,
            "type": "kprobe"
          },
          "75": {
            "avg_ns_per_run": 1144.1044891640868,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 75,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 1292,
            "run_time_ns_delta": 1478183,
            "type": "kprobe"
          },
          "76": {
            "avg_ns_per_run": null,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 76,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "77": {
            "avg_ns_per_run": null,
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 77,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "78": {
            "avg_ns_per_run": null,
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 78,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "79": {
            "avg_ns_per_run": null,
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 79,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "80": {
            "avg_ns_per_run": 1728.9907120743035,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 80,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 323,
            "run_time_ns_delta": 558464,
            "type": "kprobe"
          },
          "81": {
            "avg_ns_per_run": 1641.7739938080495,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 81,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 323,
            "run_time_ns_delta": 530293,
            "type": "kprobe"
          },
          "82": {
            "avg_ns_per_run": 1977.2503863987636,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 82,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 647,
            "run_time_ns_delta": 1279281,
            "type": "kprobe"
          },
          "83": {
            "avg_ns_per_run": 1494.390092879257,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 83,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 323,
            "run_time_ns_delta": 482688,
            "type": "kprobe"
          },
          "84": {
            "avg_ns_per_run": 1627.8482972136223,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 84,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 323,
            "run_time_ns_delta": 525795,
            "type": "kprobe"
          },
          "85": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 85,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "86": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 86,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "87": {
            "avg_ns_per_run": 395.7723342939481,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 87,
            "name": "trace_vfs_write",
            "run_cnt_delta": 347,
            "run_time_ns_delta": 137333,
            "type": "kprobe"
          },
          "88": {
            "avg_ns_per_run": 180.10662824207492,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 88,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 347,
            "run_time_ns_delta": 62497,
            "type": "kprobe"
          },
          "89": {
            "avg_ns_per_run": 2098.4668587896253,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 89,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 347,
            "run_time_ns_delta": 728168,
            "type": "kprobe"
          },
          "90": {
            "avg_ns_per_run": 1806.3314121037463,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 90,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 347,
            "run_time_ns_delta": 626797,
            "type": "kprobe"
          },
          "91": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 91,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "92": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 92,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "93": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 93,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "94": {
            "avg_ns_per_run": null,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 94,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "95": {
            "avg_ns_per_run": null,
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 95,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "96": {
            "avg_ns_per_run": null,
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 96,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "97": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 97,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "98": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 98,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "99": {
            "avg_ns_per_run": null,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 99,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "100": {
            "avg_ns_per_run": null,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 100,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "101": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 101,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "102": {
            "avg_ns_per_run": 198.68543046357615,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 102,
            "name": "trace_vfs_read",
            "run_cnt_delta": 1812,
            "run_time_ns_delta": 360018,
            "type": "kprobe"
          },
          "103": {
            "avg_ns_per_run": 1653.9469906129211,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 103,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 1811,
            "run_time_ns_delta": 2995298,
            "type": "kprobe"
          },
          "104": {
            "avg_ns_per_run": null,
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 104,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "105": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 105,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "106": {
            "avg_ns_per_run": null,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 106,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "107": {
            "avg_ns_per_run": null,
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 107,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "108": {
            "avg_ns_per_run": 148.36241090796406,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 108,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 6454,
            "run_time_ns_delta": 957531,
            "type": "kprobe"
          },
          "109": {
            "avg_ns_per_run": 95.8026387131755,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 109,
            "name": "trace_do_mmap",
            "run_cnt_delta": 5533,
            "run_time_ns_delta": 530076,
            "type": "kprobe"
          },
          "110": {
            "avg_ns_per_run": 1360.7625158142057,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 110,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 5533,
            "run_time_ns_delta": 7529099,
            "type": "kprobe"
          },
          "111": {
            "avg_ns_per_run": 1126.3273088740286,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 111,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 5533,
            "run_time_ns_delta": 6231969,
            "type": "kprobe"
          },
          "112": {
            "avg_ns_per_run": 1496.1746680286005,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 112,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 979,
            "run_time_ns_delta": 1464755,
            "type": "kprobe"
          },
          "113": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 113,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "114": {
            "avg_ns_per_run": 517.7785171102662,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 114,
            "name": "trace_security_bpf",
            "run_cnt_delta": 7364,
            "run_time_ns_delta": 3812921,
            "type": "kprobe"
          },
          "115": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 115,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "116": {
            "avg_ns_per_run": null,
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 116,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "117": {
            "avg_ns_per_run": 522.7778204144282,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 117,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2606,
            "run_time_ns_delta": 1362359,
            "type": "kprobe"
          },
          "118": {
            "avg_ns_per_run": 1140.8364779874214,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 118,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 159,
            "run_time_ns_delta": 181393,
            "type": "kprobe"
          },
          "119": {
            "avg_ns_per_run": null,
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 119,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 120,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "121": {
            "avg_ns_per_run": null,
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 121,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "122": {
            "avg_ns_per_run": null,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 122,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "123": {
            "avg_ns_per_run": null,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 123,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "124": {
            "avg_ns_per_run": null,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 124,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 125,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "126": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 126,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "127": {
            "avg_ns_per_run": null,
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 127,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 128,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 129,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "130": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 130,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "131": {
            "avg_ns_per_run": null,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 131,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "132": {
            "avg_ns_per_run": 1941.66512345679,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 132,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 648,
            "run_time_ns_delta": 1258199,
            "type": "kprobe"
          },
          "133": {
            "avg_ns_per_run": 84.8822239624119,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 133,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 6385,
            "run_time_ns_delta": 541973,
            "type": "kprobe"
          },
          "134": {
            "avg_ns_per_run": 2020.3364197530864,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 134,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 324,
            "run_time_ns_delta": 654589,
            "type": "raw_tracepoint"
          },
          "135": {
            "avg_ns_per_run": null,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 135,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "136": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 136,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "137": {
            "avg_ns_per_run": null,
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 137,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "138": {
            "avg_ns_per_run": 926.5079365079365,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 138,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 58370,
            "type": "kprobe"
          },
          "139": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 139,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "140": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 140,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "141": {
            "avg_ns_per_run": 2173.0745341614906,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 141,
            "name": "trace_do_truncate",
            "run_cnt_delta": 322,
            "run_time_ns_delta": 699730,
            "type": "kprobe"
          },
          "142": {
            "avg_ns_per_run": 405.31407384520315,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 142,
            "name": "trace_fd_install",
            "run_cnt_delta": 6473,
            "run_time_ns_delta": 2623598,
            "type": "kprobe"
          },
          "143": {
            "avg_ns_per_run": 663.8577160493827,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 143,
            "name": "trace_filp_close",
            "run_cnt_delta": 3240,
            "run_time_ns_delta": 2150899,
            "type": "kprobe"
          },
          "144": {
            "avg_ns_per_run": 231.44020356234097,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 144,
            "name": "trace_file_update_time",
            "run_cnt_delta": 393,
            "run_time_ns_delta": 90956,
            "type": "kprobe"
          },
          "145": {
            "avg_ns_per_run": 2741.8066157760813,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 145,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 393,
            "run_time_ns_delta": 1077530,
            "type": "kprobe"
          },
          "146": {
            "avg_ns_per_run": null,
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 146,
            "name": "trace_file_modified",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "147": {
            "avg_ns_per_run": null,
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 147,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "148": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 148,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "149": {
            "avg_ns_per_run": null,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 149,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "150": {
            "avg_ns_per_run": null,
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 150,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "151": {
            "avg_ns_per_run": 62.75925925925926,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 151,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 324,
            "run_time_ns_delta": 20334,
            "type": "kprobe"
          },
          "152": {
            "avg_ns_per_run": 3263.4104938271603,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 152,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 324,
            "run_time_ns_delta": 1057345,
            "type": "kprobe"
          },
          "153": {
            "avg_ns_per_run": 2918.5409582689335,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 153,
            "name": "trace_execute_finished",
            "run_cnt_delta": 647,
            "run_time_ns_delta": 1888296,
            "type": "kprobe"
          },
          "154": {
            "avg_ns_per_run": null,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 154,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "155": {
            "avg_ns_per_run": 3513.0,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 155,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3513,
            "type": "kprobe"
          },
          "156": {
            "avg_ns_per_run": null,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 156,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "157": {
            "avg_ns_per_run": null,
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 157,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "158": {
            "avg_ns_per_run": null,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 158,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "159": {
            "avg_ns_per_run": 1030.5,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 159,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 6183,
            "type": "kprobe"
          },
          "160": {
            "avg_ns_per_run": null,
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 160,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "161": {
            "avg_ns_per_run": null,
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 161,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "162": {
            "avg_ns_per_run": 241.00206291903044,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 162,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 1939,
            "run_time_ns_delta": 467303,
            "type": "kprobe"
          },
          "163": {
            "avg_ns_per_run": 547.7694687983496,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 163,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 1939,
            "run_time_ns_delta": 1062125,
            "type": "kprobe"
          },
          "164": {
            "avg_ns_per_run": 874.0030959752322,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 164,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 323,
            "run_time_ns_delta": 282303,
            "type": "kprobe"
          },
          "165": {
            "avg_ns_per_run": 120.46439628482972,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 165,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 323,
            "run_time_ns_delta": 38910,
            "type": "kprobe"
          },
          "166": {
            "avg_ns_per_run": 166.77708978328172,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 166,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 323,
            "run_time_ns_delta": 53869,
            "type": "kprobe"
          },
          "167": {
            "avg_ns_per_run": 738.8559712967709,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 167,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 3902,
            "run_time_ns_delta": 2883016,
            "type": "kprobe"
          },
          "169": {
            "avg_ns_per_run": 2090.216299333675,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 169,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 1951,
            "run_time_ns_delta": 4078012,
            "type": "cgroup_skb"
          },
          "170": {
            "avg_ns_per_run": 2423.94566888775,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 170,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 1951,
            "run_time_ns_delta": 4729118,
            "type": "cgroup_skb"
          },
          "171": {
            "avg_ns_per_run": 2262.0,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 171,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2262,
            "type": "raw_tracepoint"
          },
          "172": {
            "avg_ns_per_run": 615.0,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 172,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 615,
            "type": "raw_tracepoint"
          },
          "173": {
            "avg_ns_per_run": 73.46604938271605,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 173,
            "name": "empty_kprobe",
            "run_cnt_delta": 324,
            "run_time_ns_delta": 23803,
            "type": "kprobe"
          },
          "174": {
            "avg_ns_per_run": 516.3333333333334,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 174,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 324,
            "run_time_ns_delta": 167292,
            "type": "raw_tracepoint"
          },
          "175": {
            "avg_ns_per_run": 927.0165952890792,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 175,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 3736,
            "run_time_ns_delta": 3463334,
            "type": "lsm"
          },
          "176": {
            "avg_ns_per_run": null,
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 176,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.00789462299997,
            "ops_per_sec": 64.49816226494548,
            "ops_total": 323.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 158.14385392892078,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 18,
            "name": "tracepoint__raw",
            "run_cnt_delta": 720745,
            "run_time_ns_delta": 113981392,
            "type": "raw_tracepoint"
          },
          "19": {
            "avg_ns_per_run": null,
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 19,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "20": {
            "avg_ns_per_run": null,
            "bytes_jited": 17415,
            "bytes_xlated": 30288,
            "id": 20,
            "name": "sys_enter_submi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "21": {
            "avg_ns_per_run": 162.49570482502887,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 21,
            "name": "tracepoint__raw",
            "run_cnt_delta": 720576,
            "run_time_ns_delta": 117090505,
            "type": "raw_tracepoint"
          },
          "22": {
            "avg_ns_per_run": null,
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 22,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "23": {
            "avg_ns_per_run": null,
            "bytes_jited": 11545,
            "bytes_xlated": 19792,
            "id": 23,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "24": {
            "avg_ns_per_run": 168.98923324137854,
            "bytes_jited": 8131,
            "bytes_xlated": 13608,
            "id": 24,
            "name": "trace_sys_enter",
            "run_cnt_delta": 720644,
            "run_time_ns_delta": 121781077,
            "type": "raw_tracepoint"
          },
          "25": {
            "avg_ns_per_run": 157.79561289212484,
            "bytes_jited": 8164,
            "bytes_xlated": 13664,
            "id": 25,
            "name": "trace_sys_exit",
            "run_cnt_delta": 720657,
            "run_time_ns_delta": 113716513,
            "type": "raw_tracepoint"
          },
          "26": {
            "avg_ns_per_run": null,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 26,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "27": {
            "avg_ns_per_run": null,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 27,
            "name": "trace_ret_ptrac",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "28": {
            "avg_ns_per_run": null,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 28,
            "name": "trace_process_v",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "29": {
            "avg_ns_per_run": null,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 29,
            "name": "trace_ret_proce",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "30": {
            "avg_ns_per_run": 391.9230769230769,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 30,
            "name": "trace_arch_prct",
            "run_cnt_delta": 351,
            "run_time_ns_delta": 137565,
            "type": "kprobe"
          },
          "31": {
            "avg_ns_per_run": 1662.4102564102564,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 31,
            "name": "trace_ret_arch_",
            "run_cnt_delta": 351,
            "run_time_ns_delta": 583506,
            "type": "kprobe"
          },
          "32": {
            "avg_ns_per_run": null,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 32,
            "name": "trace_dup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "33": {
            "avg_ns_per_run": null,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 33,
            "name": "trace_ret_dup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "34": {
            "avg_ns_per_run": 339.5681818181818,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 34,
            "name": "trace_dup2",
            "run_cnt_delta": 352,
            "run_time_ns_delta": 119528,
            "type": "kprobe"
          },
          "35": {
            "avg_ns_per_run": 2397.7926136363635,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 35,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 352,
            "run_time_ns_delta": 844023,
            "type": "kprobe"
          },
          "36": {
            "avg_ns_per_run": null,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 36,
            "name": "trace_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "37": {
            "avg_ns_per_run": null,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 37,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "38": {
            "avg_ns_per_run": null,
            "bytes_jited": 20725,
            "bytes_xlated": 31976,
            "id": 38,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "39": {
            "avg_ns_per_run": null,
            "bytes_jited": 20696,
            "bytes_xlated": 31992,
            "id": 39,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "40": {
            "avg_ns_per_run": null,
            "bytes_jited": 21000,
            "bytes_xlated": 32400,
            "id": 40,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "41": {
            "avg_ns_per_run": null,
            "bytes_jited": 20968,
            "bytes_xlated": 32408,
            "id": 41,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "42": {
            "avg_ns_per_run": null,
            "bytes_jited": 12211,
            "bytes_xlated": 18576,
            "id": 42,
            "name": "sys_dup_exit_ta",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "43": {
            "avg_ns_per_run": 3264.9153187440534,
            "bytes_jited": 19847,
            "bytes_xlated": 32320,
            "id": 43,
            "name": "tracepoint__sch",
            "run_cnt_delta": 1051,
            "run_time_ns_delta": 3431426,
            "type": "raw_tracepoint"
          },
          "44": {
            "avg_ns_per_run": null,
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 44,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "45": {
            "avg_ns_per_run": null,
            "bytes_jited": 6021,
            "bytes_xlated": 9904,
            "id": 45,
            "name": "uprobe_lkm_seek",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "46": {
            "avg_ns_per_run": null,
            "bytes_jited": 4308,
            "bytes_xlated": 7696,
            "id": 46,
            "name": "uprobe_lkm_seek",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "47": {
            "avg_ns_per_run": null,
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 47,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "48": {
            "avg_ns_per_run": null,
            "bytes_jited": 648,
            "bytes_xlated": 1040,
            "id": 48,
            "name": "lkm_seeker_mod_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "49": {
            "avg_ns_per_run": null,
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 49,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "50": {
            "avg_ns_per_run": null,
            "bytes_jited": 3772,
            "bytes_xlated": 6224,
            "id": 50,
            "name": "lkm_seeker_new_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "51": {
            "avg_ns_per_run": 4498.54415954416,
            "bytes_jited": 20525,
            "bytes_xlated": 35336,
            "id": 51,
            "name": "tracepoint__sch",
            "run_cnt_delta": 351,
            "run_time_ns_delta": 1578989,
            "type": "raw_tracepoint"
          },
          "52": {
            "avg_ns_per_run": null,
            "bytes_jited": 23905,
            "bytes_xlated": 37632,
            "id": 52,
            "name": "sched_process_e",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "53": {
            "avg_ns_per_run": 1894.371075166508,
            "bytes_jited": 8680,
            "bytes_xlated": 14464,
            "id": 53,
            "name": "tracepoint__sch",
            "run_cnt_delta": 1051,
            "run_time_ns_delta": 1990984,
            "type": "raw_tracepoint"
          },
          "54": {
            "avg_ns_per_run": 626.7395038167939,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 54,
            "name": "tracepoint__sch",
            "run_cnt_delta": 1048,
            "run_time_ns_delta": 656823,
            "type": "raw_tracepoint"
          },
          "55": {
            "avg_ns_per_run": null,
            "bytes_jited": 9084,
            "bytes_xlated": 13696,
            "id": 55,
            "name": "syscall__accept",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "56": {
            "avg_ns_per_run": 294.459107392334,
            "bytes_jited": 8925,
            "bytes_xlated": 14840,
            "id": 56,
            "name": "tracepoint__sch",
            "run_cnt_delta": 856793,
            "run_time_ns_delta": 252290502,
            "type": "raw_tracepoint"
          },
          "57": {
            "avg_ns_per_run": 20.052219321148826,
            "bytes_jited": 8163,
            "bytes_xlated": 13680,
            "id": 57,
            "name": "trace_filldir64",
            "run_cnt_delta": 383,
            "run_time_ns_delta": 7680,
            "type": "kprobe"
          },
          "58": {
            "avg_ns_per_run": null,
            "bytes_jited": 23491,
            "bytes_xlated": 36696,
            "id": 58,
            "name": "trace_call_user",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "59": {
            "avg_ns_per_run": 1303.475737392959,
            "bytes_jited": 7921,
            "bytes_xlated": 13312,
            "id": 59,
            "name": "trace_do_exit",
            "run_cnt_delta": 1051,
            "run_time_ns_delta": 1369953,
            "type": "kprobe"
          },
          "60": {
            "avg_ns_per_run": null,
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 60,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "61": {
            "avg_ns_per_run": null,
            "bytes_jited": 6749,
            "bytes_xlated": 11160,
            "id": 61,
            "name": "uprobe_seq_ops_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "62": {
            "avg_ns_per_run": null,
            "bytes_jited": 6533,
            "bytes_xlated": 10904,
            "id": 62,
            "name": "uprobe_mem_dump",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "63": {
            "avg_ns_per_run": 546.2008547008547,
            "bytes_jited": 11470,
            "bytes_xlated": 18264,
            "id": 63,
            "name": "trace_security_",
            "run_cnt_delta": 702,
            "run_time_ns_delta": 383433,
            "type": "kprobe"
          },
          "64": {
            "avg_ns_per_run": null,
            "bytes_jited": 9740,
            "bytes_xlated": 15632,
            "id": 64,
            "name": "trace_tracepoin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "65": {
            "avg_ns_per_run": null,
            "bytes_jited": 8620,
            "bytes_xlated": 14352,
            "id": 65,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "66": {
            "avg_ns_per_run": 1710.0,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 66,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1710,
            "type": "raw_tracepoint"
          },
          "67": {
            "avg_ns_per_run": 1310.0,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 67,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1310,
            "type": "raw_tracepoint"
          },
          "68": {
            "avg_ns_per_run": 3006.672364672365,
            "bytes_jited": 33373,
            "bytes_xlated": 52824,
            "id": 68,
            "name": "trace_security_",
            "run_cnt_delta": 351,
            "run_time_ns_delta": 1055342,
            "type": "kprobe"
          },
          "69": {
            "avg_ns_per_run": 1765.4732408325074,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 69,
            "name": "trace_security_file_open",
            "run_cnt_delta": 4036,
            "run_time_ns_delta": 7125450,
            "type": "kprobe"
          },
          "70": {
            "avg_ns_per_run": null,
            "bytes_jited": 18607,
            "bytes_xlated": 30576,
            "id": 70,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "71": {
            "avg_ns_per_run": 3100.0,
            "bytes_jited": 9984,
            "bytes_xlated": 16352,
            "id": 71,
            "name": "trace_security_",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3100,
            "type": "kprobe"
          },
          "72": {
            "avg_ns_per_run": 907.2250712250712,
            "bytes_jited": 10723,
            "bytes_xlated": 16880,
            "id": 72,
            "name": "trace_commit_cr",
            "run_cnt_delta": 351,
            "run_time_ns_delta": 318436,
            "type": "kprobe"
          },
          "73": {
            "avg_ns_per_run": 580.7021883920077,
            "bytes_jited": 10045,
            "bytes_xlated": 16520,
            "id": 73,
            "name": "trace_switch_ta",
            "run_cnt_delta": 1051,
            "run_time_ns_delta": 610318,
            "type": "kprobe"
          },
          "74": {
            "avg_ns_per_run": 180.9587929324617,
            "bytes_jited": 8174,
            "bytes_xlated": 13680,
            "id": 74,
            "name": "trace_cap_capab",
            "run_cnt_delta": 49409,
            "run_time_ns_delta": 8940993,
            "type": "kprobe"
          },
          "75": {
            "avg_ns_per_run": 1171.6957142857143,
            "bytes_jited": 8471,
            "bytes_xlated": 14120,
            "id": 75,
            "name": "trace_security_",
            "run_cnt_delta": 1400,
            "run_time_ns_delta": 1640374,
            "type": "kprobe"
          },
          "76": {
            "avg_ns_per_run": null,
            "bytes_jited": 9144,
            "bytes_xlated": 15208,
            "id": 76,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "77": {
            "avg_ns_per_run": null,
            "bytes_jited": 8276,
            "bytes_xlated": 13824,
            "id": 77,
            "name": "trace_proc_crea",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "78": {
            "avg_ns_per_run": null,
            "bytes_jited": 9497,
            "bytes_xlated": 15760,
            "id": 78,
            "name": "trace_debugfs_c",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "79": {
            "avg_ns_per_run": null,
            "bytes_jited": 9197,
            "bytes_xlated": 15328,
            "id": 79,
            "name": "trace_debugfs_c",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "80": {
            "avg_ns_per_run": 1812.9685714285715,
            "bytes_jited": 10780,
            "bytes_xlated": 16456,
            "id": 80,
            "name": "trace_security_",
            "run_cnt_delta": 350,
            "run_time_ns_delta": 634539,
            "type": "kprobe"
          },
          "81": {
            "avg_ns_per_run": 1623.4085714285713,
            "bytes_jited": 10075,
            "bytes_xlated": 15400,
            "id": 81,
            "name": "trace_security_",
            "run_cnt_delta": 350,
            "run_time_ns_delta": 568193,
            "type": "kprobe"
          },
          "82": {
            "avg_ns_per_run": 2094.149779735683,
            "bytes_jited": 11260,
            "bytes_xlated": 17192,
            "id": 82,
            "name": "trace_security_",
            "run_cnt_delta": 681,
            "run_time_ns_delta": 1426116,
            "type": "kprobe"
          },
          "83": {
            "avg_ns_per_run": 1711.642857142857,
            "bytes_jited": 10589,
            "bytes_xlated": 16080,
            "id": 83,
            "name": "trace_security_",
            "run_cnt_delta": 350,
            "run_time_ns_delta": 599075,
            "type": "kprobe"
          },
          "84": {
            "avg_ns_per_run": 1837.4714285714285,
            "bytes_jited": 11025,
            "bytes_xlated": 16864,
            "id": 84,
            "name": "trace_security_",
            "run_cnt_delta": 350,
            "run_time_ns_delta": 643115,
            "type": "kprobe"
          },
          "85": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 85,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "86": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 86,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "87": {
            "avg_ns_per_run": 321.61517615176155,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 87,
            "name": "trace_vfs_write",
            "run_cnt_delta": 369,
            "run_time_ns_delta": 118676,
            "type": "kprobe"
          },
          "88": {
            "avg_ns_per_run": 182.8319783197832,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 88,
            "name": "vfs_write_magic",
            "run_cnt_delta": 369,
            "run_time_ns_delta": 67465,
            "type": "kprobe"
          },
          "89": {
            "avg_ns_per_run": 2268.3658536585367,
            "bytes_jited": 19108,
            "bytes_xlated": 31720,
            "id": 89,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 369,
            "run_time_ns_delta": 837027,
            "type": "kprobe"
          },
          "90": {
            "avg_ns_per_run": 2153.837398373984,
            "bytes_jited": 23757,
            "bytes_xlated": 36648,
            "id": 90,
            "name": "vfs_write_magic",
            "run_cnt_delta": 369,
            "run_time_ns_delta": 794766,
            "type": "kprobe"
          },
          "91": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 91,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "92": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 92,
            "name": "trace_vfs_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "93": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 93,
            "name": "vfs_writev_magi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "94": {
            "avg_ns_per_run": null,
            "bytes_jited": 19107,
            "bytes_xlated": 31712,
            "id": 94,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "95": {
            "avg_ns_per_run": null,
            "bytes_jited": 23786,
            "bytes_xlated": 36696,
            "id": 95,
            "name": "vfs_writev_magi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "96": {
            "avg_ns_per_run": null,
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 96,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "97": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 97,
            "name": "trace_kernel_wr",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "98": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 98,
            "name": "kernel_write_ma",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "99": {
            "avg_ns_per_run": null,
            "bytes_jited": 19111,
            "bytes_xlated": 31720,
            "id": 99,
            "name": "trace_ret_kerne",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "100": {
            "avg_ns_per_run": null,
            "bytes_jited": 23757,
            "bytes_xlated": 36648,
            "id": 100,
            "name": "kernel_write_ma",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "101": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 101,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "102": {
            "avg_ns_per_run": 187.0875837197321,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 102,
            "name": "trace_vfs_read",
            "run_cnt_delta": 1941,
            "run_time_ns_delta": 363137,
            "type": "kprobe"
          },
          "103": {
            "avg_ns_per_run": 1720.9319938176197,
            "bytes_jited": 19111,
            "bytes_xlated": 31720,
            "id": 103,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 1941,
            "run_time_ns_delta": 3340329,
            "type": "kprobe"
          },
          "104": {
            "avg_ns_per_run": null,
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 104,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "105": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 105,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "106": {
            "avg_ns_per_run": null,
            "bytes_jited": 19107,
            "bytes_xlated": 31712,
            "id": 106,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "107": {
            "avg_ns_per_run": null,
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 107,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "108": {
            "avg_ns_per_run": 151.93401965372016,
            "bytes_jited": 20715,
            "bytes_xlated": 32736,
            "id": 108,
            "name": "trace_mmap_aler",
            "run_cnt_delta": 6411,
            "run_time_ns_delta": 974049,
            "type": "kprobe"
          },
          "109": {
            "avg_ns_per_run": 97.9866466366216,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 109,
            "name": "trace_do_mmap",
            "run_cnt_delta": 5991,
            "run_time_ns_delta": 587038,
            "type": "kprobe"
          },
          "110": {
            "avg_ns_per_run": 1352.8112168252378,
            "bytes_jited": 19426,
            "bytes_xlated": 31584,
            "id": 110,
            "name": "trace_ret_do_mm",
            "run_cnt_delta": 5991,
            "run_time_ns_delta": 8104692,
            "type": "kprobe"
          },
          "111": {
            "avg_ns_per_run": 1137.0874645301285,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 111,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 5991,
            "run_time_ns_delta": 6812291,
            "type": "kprobe"
          },
          "112": {
            "avg_ns_per_run": 1496.0888468809073,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 112,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 1058,
            "run_time_ns_delta": 1582862,
            "type": "kprobe"
          },
          "113": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 113,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "114": {
            "avg_ns_per_run": 696.1617461872114,
            "bytes_jited": 15585,
            "bytes_xlated": 26904,
            "id": 114,
            "name": "trace_security_",
            "run_cnt_delta": 7147,
            "run_time_ns_delta": 4975468,
            "type": "kprobe"
          },
          "115": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 115,
            "name": "trace_register_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "116": {
            "avg_ns_per_run": null,
            "bytes_jited": 8807,
            "bytes_xlated": 14640,
            "id": 116,
            "name": "trace_ret_regis",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "117": {
            "avg_ns_per_run": 664.2798703928717,
            "bytes_jited": 8333,
            "bytes_xlated": 13904,
            "id": 117,
            "name": "trace_security_",
            "run_cnt_delta": 2469,
            "run_time_ns_delta": 1640107,
            "type": "kprobe"
          },
          "118": {
            "avg_ns_per_run": 1247.0125786163521,
            "bytes_jited": 9581,
            "bytes_xlated": 15448,
            "id": 118,
            "name": "trace_security_",
            "run_cnt_delta": 159,
            "run_time_ns_delta": 198275,
            "type": "kprobe"
          },
          "119": {
            "avg_ns_per_run": null,
            "bytes_jited": 6345,
            "bytes_xlated": 10528,
            "id": 119,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 6581,
            "bytes_xlated": 11008,
            "id": 120,
            "name": "trace_check_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "121": {
            "avg_ns_per_run": null,
            "bytes_jited": 6587,
            "bytes_xlated": 11016,
            "id": 121,
            "name": "trace_check_hel",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "122": {
            "avg_ns_per_run": null,
            "bytes_jited": 18641,
            "bytes_xlated": 30648,
            "id": 122,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "123": {
            "avg_ns_per_run": null,
            "bytes_jited": 17247,
            "bytes_xlated": 30448,
            "id": 123,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "124": {
            "avg_ns_per_run": null,
            "bytes_jited": 9225,
            "bytes_xlated": 15352,
            "id": 124,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 8647,
            "bytes_xlated": 14344,
            "id": 125,
            "name": "trace_device_ad",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "126": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 126,
            "name": "trace___registe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "127": {
            "avg_ns_per_run": null,
            "bytes_jited": 8814,
            "bytes_xlated": 14632,
            "id": 127,
            "name": "trace_ret__regi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 19868,
            "bytes_xlated": 32648,
            "id": 128,
            "name": "tracepoint__mod",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 8959,
            "bytes_xlated": 14920,
            "id": 129,
            "name": "tracepoint__mod",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "130": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 130,
            "name": "trace_do_init_m",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "131": {
            "avg_ns_per_run": null,
            "bytes_jited": 14542,
            "bytes_xlated": 23904,
            "id": 131,
            "name": "trace_ret_do_in",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "132": {
            "avg_ns_per_run": 1958.97150997151,
            "bytes_jited": 18482,
            "bytes_xlated": 30352,
            "id": 132,
            "name": "trace_load_elf_",
            "run_cnt_delta": 702,
            "run_time_ns_delta": 1375198,
            "type": "kprobe"
          },
          "133": {
            "avg_ns_per_run": 86.32883666956774,
            "bytes_jited": 8681,
            "bytes_xlated": 14496,
            "id": 133,
            "name": "trace_security_",
            "run_cnt_delta": 6894,
            "run_time_ns_delta": 595151,
            "type": "kprobe"
          },
          "134": {
            "avg_ns_per_run": 2339.6011396011395,
            "bytes_jited": 8474,
            "bytes_xlated": 14112,
            "id": 134,
            "name": "tracepoint__tas",
            "run_cnt_delta": 351,
            "run_time_ns_delta": 821200,
            "type": "raw_tracepoint"
          },
          "135": {
            "avg_ns_per_run": null,
            "bytes_jited": 9792,
            "bytes_xlated": 16344,
            "id": 135,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "136": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 136,
            "name": "trace_kallsyms_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "137": {
            "avg_ns_per_run": null,
            "bytes_jited": 8406,
            "bytes_xlated": 14024,
            "id": 137,
            "name": "trace_ret_kalls",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "138": {
            "avg_ns_per_run": 873.3015873015873,
            "bytes_jited": 10109,
            "bytes_xlated": 16296,
            "id": 138,
            "name": "trace_do_sigact",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 55018,
            "type": "kprobe"
          },
          "139": {
            "avg_ns_per_run": null,
            "bytes_jited": 18560,
            "bytes_xlated": 30528,
            "id": 139,
            "name": "trace_vfs_utime",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "140": {
            "avg_ns_per_run": null,
            "bytes_jited": 18560,
            "bytes_xlated": 30528,
            "id": 140,
            "name": "trace_utimes_co",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "141": {
            "avg_ns_per_run": 2294.464183381089,
            "bytes_jited": 9530,
            "bytes_xlated": 15824,
            "id": 141,
            "name": "trace_do_trunca",
            "run_cnt_delta": 349,
            "run_time_ns_delta": 800768,
            "type": "kprobe"
          },
          "142": {
            "avg_ns_per_run": 460.2676544766709,
            "bytes_jited": 16708,
            "bytes_xlated": 27176,
            "id": 142,
            "name": "trace_fd_instal",
            "run_cnt_delta": 6344,
            "run_time_ns_delta": 2919938,
            "type": "kprobe"
          },
          "143": {
            "avg_ns_per_run": 700.7672364672364,
            "bytes_jited": 16636,
            "bytes_xlated": 27024,
            "id": 143,
            "name": "trace_filp_clos",
            "run_cnt_delta": 3510,
            "run_time_ns_delta": 2459693,
            "type": "kprobe"
          },
          "144": {
            "avg_ns_per_run": 207.7869318181818,
            "bytes_jited": 459,
            "bytes_xlated": 768,
            "id": 144,
            "name": "trace_file_upda",
            "run_cnt_delta": 352,
            "run_time_ns_delta": 73141,
            "type": "kprobe"
          },
          "145": {
            "avg_ns_per_run": 2957.3352272727275,
            "bytes_jited": 20054,
            "bytes_xlated": 31168,
            "id": 145,
            "name": "trace_ret_file_",
            "run_cnt_delta": 352,
            "run_time_ns_delta": 1040982,
            "type": "kprobe"
          },
          "146": {
            "avg_ns_per_run": null,
            "bytes_jited": 459,
            "bytes_xlated": 768,
            "id": 146,
            "name": "trace_file_modi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "147": {
            "avg_ns_per_run": null,
            "bytes_jited": 20140,
            "bytes_xlated": 31288,
            "id": 147,
            "name": "trace_ret_file_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "148": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 148,
            "name": "trace_inotify_f",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "149": {
            "avg_ns_per_run": null,
            "bytes_jited": 18025,
            "bytes_xlated": 29936,
            "id": 149,
            "name": "trace_ret_inoti",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "150": {
            "avg_ns_per_run": null,
            "bytes_jited": 12830,
            "bytes_xlated": 20080,
            "id": 150,
            "name": "process_execute",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "151": {
            "avg_ns_per_run": 74.21937321937322,
            "bytes_jited": 16472,
            "bytes_xlated": 28872,
            "id": 151,
            "name": "trace_exec_binp",
            "run_cnt_delta": 351,
            "run_time_ns_delta": 26051,
            "type": "kprobe"
          },
          "152": {
            "avg_ns_per_run": 3687.045584045584,
            "bytes_jited": 16702,
            "bytes_xlated": 29144,
            "id": 152,
            "name": "trace_security_",
            "run_cnt_delta": 351,
            "run_time_ns_delta": 1294153,
            "type": "kprobe"
          },
          "153": {
            "avg_ns_per_run": 3079.67332382311,
            "bytes_jited": 24469,
            "bytes_xlated": 38320,
            "id": 153,
            "name": "trace_execute_f",
            "run_cnt_delta": 701,
            "run_time_ns_delta": 2158851,
            "type": "kprobe"
          },
          "154": {
            "avg_ns_per_run": null,
            "bytes_jited": 18391,
            "bytes_xlated": 30200,
            "id": 154,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "155": {
            "avg_ns_per_run": 3406.0,
            "bytes_jited": 18194,
            "bytes_xlated": 29912,
            "id": 155,
            "name": "trace_set_fs_pw",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3406,
            "type": "kprobe"
          },
          "156": {
            "avg_ns_per_run": null,
            "bytes_jited": 8631,
            "bytes_xlated": 14360,
            "id": 156,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "157": {
            "avg_ns_per_run": null,
            "bytes_jited": 8656,
            "bytes_xlated": 14416,
            "id": 157,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "158": {
            "avg_ns_per_run": null,
            "bytes_jited": 17561,
            "bytes_xlated": 29176,
            "id": 158,
            "name": "trace_chmod_com",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "159": {
            "avg_ns_per_run": 1176.0,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 159,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 7056,
            "type": "kprobe"
          },
          "160": {
            "avg_ns_per_run": null,
            "bytes_jited": 14861,
            "bytes_xlated": 23928,
            "id": 160,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "161": {
            "avg_ns_per_run": null,
            "bytes_jited": 9482,
            "bytes_xlated": 15760,
            "id": 161,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "162": {
            "avg_ns_per_run": 247.604997597309,
            "bytes_jited": 329,
            "bytes_xlated": 520,
            "id": 162,
            "name": "trace_sock_allo",
            "run_cnt_delta": 2081,
            "run_time_ns_delta": 515266,
            "type": "kprobe"
          },
          "163": {
            "avg_ns_per_run": 630.0442095146564,
            "bytes_jited": 8439,
            "bytes_xlated": 12928,
            "id": 163,
            "name": "trace_ret_sock_",
            "run_cnt_delta": 2081,
            "run_time_ns_delta": 1311122,
            "type": "kprobe"
          },
          "164": {
            "avg_ns_per_run": 967.3085714285714,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 164,
            "name": "trace_security_",
            "run_cnt_delta": 350,
            "run_time_ns_delta": 338558,
            "type": "kprobe"
          },
          "165": {
            "avg_ns_per_run": 110.40571428571428,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 165,
            "name": "trace_security_",
            "run_cnt_delta": 350,
            "run_time_ns_delta": 38642,
            "type": "kprobe"
          },
          "166": {
            "avg_ns_per_run": 210.96857142857144,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 166,
            "name": "trace_security_",
            "run_cnt_delta": 350,
            "run_time_ns_delta": 73839,
            "type": "kprobe"
          },
          "167": {
            "avg_ns_per_run": 771.2197828139755,
            "bytes_jited": 5282,
            "bytes_xlated": 8136,
            "id": 167,
            "name": "cgroup_bpf_run_",
            "run_cnt_delta": 4236,
            "run_time_ns_delta": 3266887,
            "type": "kprobe"
          },
          "169": {
            "avg_ns_per_run": 2127.369513921661,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 169,
            "name": "cgroup_skb_ingr",
            "run_cnt_delta": 2119,
            "run_time_ns_delta": 4507896,
            "type": "cgroup_skb"
          },
          "170": {
            "avg_ns_per_run": 2454.1647003303447,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 170,
            "name": "cgroup_skb_egre",
            "run_cnt_delta": 2119,
            "run_time_ns_delta": 5200375,
            "type": "cgroup_skb"
          },
          "171": {
            "avg_ns_per_run": 2812.0,
            "bytes_jited": 916,
            "bytes_xlated": 1560,
            "id": 171,
            "name": "cgroup_mkdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2812,
            "type": "raw_tracepoint"
          },
          "172": {
            "avg_ns_per_run": 624.0,
            "bytes_jited": 898,
            "bytes_xlated": 1520,
            "id": 172,
            "name": "cgroup_rmdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 624,
            "type": "raw_tracepoint"
          },
          "173": {
            "avg_ns_per_run": 105.03133903133903,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 173,
            "name": "empty_kprobe",
            "run_cnt_delta": 351,
            "run_time_ns_delta": 36866,
            "type": "kprobe"
          },
          "174": {
            "avg_ns_per_run": 578.2905982905983,
            "bytes_jited": 58660,
            "bytes_xlated": 95944,
            "id": 174,
            "name": "tracepoint__exe",
            "run_cnt_delta": 351,
            "run_time_ns_delta": 202980,
            "type": "raw_tracepoint"
          },
          "175": {
            "avg_ns_per_run": 933.0991080277503,
            "bytes_jited": 7290,
            "bytes_xlated": 13264,
            "id": 175,
            "name": "lsm_file_open_t",
            "run_cnt_delta": 4036,
            "run_time_ns_delta": 3765988,
            "type": "lsm"
          },
          "176": {
            "avg_ns_per_run": null,
            "bytes_jited": 5359,
            "bytes_xlated": 9080,
            "id": 176,
            "name": "uprobe__feature",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.006222603999959,
            "ops_per_sec": 69.91299182748105,
            "ops_total": 350.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "applied_site_totals": {
          "bitfield_sites": 37,
          "bounds_check_merge_sites": 0,
          "branch_flip_sites": 0,
          "bulk_memory_sites": 109,
          "cmov_sites": 1,
          "const_prop_sites": 298,
          "dce_sites": 1299,
          "endian_sites": 4,
          "extract_sites": 37,
          "lea_sites": 0,
          "map_inline_sites": 140,
          "other_sites": 0,
          "rotate_sites": 0,
          "skb_load_bytes_spec_sites": 0,
          "total_sites": 2069,
          "wide_sites": 181
        },
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
        "output_chars": 2246694,
        "output_stripped": true,
        "program_counts": {
          "applied": 157,
          "not_applied": 0,
          "requested": 157
        }
      },
      "runner": "tracee",
      "selected_workload": "tracee_system_edge_mix",
      "status": "ok"
    }
  ],
  "samples": 1,
  "status": "ok",
  "suite_name": "tracee_only",
  "workload_seconds": 1.0
}
```
