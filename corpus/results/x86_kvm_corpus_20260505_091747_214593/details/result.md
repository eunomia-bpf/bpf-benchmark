# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T10:14:59.781832+00:00",
  "kinsn_modules": {
    "captured_at": "2026-05-05T09:17:47.245970+00:00",
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
      "invoked_at": "2026-05-05T09:17:47.245893+00:00",
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
        "captured_at": "2026-05-05T09:17:47.245883+00:00",
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
      "captured_at": "2026-05-05T09:17:47.232798+00:00",
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
      "app": "bcc/capable",
      "baseline": {
        "bpf": {
          "6": {
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 2341426,
            "run_time_ns_delta": 281774188,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0615897590000003,
            "ops_per_sec": 6016939.384464409,
            "ops_total": 18421400.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [17351] setting to a 3 secs run per stressor\nstress-ng: info:  [17351] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 dup, 4 kill, 4 sigfd, 4 signal, 4 pty, 4 itimer, 4 timerfd\nstress-ng: info:  [17351] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [17351] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [17351]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [17351] cap             5998318      3.00      1.98      5.76   1999404.69      774301.32\nstress-ng: metrc: [17351] eventfd         1108865      3.00      0.81      3.84    369540.05      238536.49\nstress-ng: metrc: [17351] get                6151      3.00      0.14      0.85      2048.32        6236.87\nstress-ng: metrc: [17351] prctl              8015      3.00      1.42      0.99      2668.87        3333.74\nstress-ng: metrc: [17351] set              128593      3.00      0.59      2.52     42857.65       41307.83\nstress-ng: metrc: [17351] dup                3355      3.00      0.56      0.54      1118.30        3037.32\nstress-ng: metrc: [17351] kill             362844      3.00      0.35      4.11    120845.77       81405.83\nstress-ng: metrc: [17351] sigfd           9585774      3.00      1.23      4.63   3191484.27     1635886.94\nstress-ng: metrc: [17351] signal                0      3.00      0.03      0.03         0.00           0.00\nstress-ng: metrc: [17351] pty                 273      3.01      0.17      4.85        90.66          54.31\nstress-ng: metrc: [17351] itimer              652      3.00      1.43      4.27       217.33         114.43\nstress-ng: metrc: [17351] timerfd         1218560      3.00      0.53      4.65    405986.49      235395.66\nstress-ng: info:  [17351] skipped: 0\nstress-ng: info:  [17351] passed: 48: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4)\nstress-ng: info:  [17351] failed: 0\nstress-ng: info:  [17351] metrics untrustworthy: 0\nstress-ng: info:  [17351] successful run completed in 3.05 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "bytes_jited": 206,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 2747905,
            "run_time_ns_delta": 346504516,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0455979889999867,
            "ops_per_sec": 4821428.846826069,
            "ops_total": 14684134.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [21771] setting to a 3 secs run per stressor\nstress-ng: info:  [21771] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 dup, 4 kill, 4 sigfd, 4 signal, 4 pty, 4 itimer, 4 timerfd\nstress-ng: info:  [21771] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21771] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21771]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21771] cap             5037884      3.00      1.62      4.23   1678693.55      862026.70\nstress-ng: metrc: [21771] eventfd         1103945      3.00      0.83      3.90    367817.44      233554.73\nstress-ng: metrc: [21771] get                6777      3.00      0.12      0.83      2258.00        7142.19\nstress-ng: metrc: [21771] prctl             12192      3.00      2.32      1.64      4062.12        3080.35\nstress-ng: metrc: [21771] set              124803      3.00      0.44      2.46     41576.40       43150.25\nstress-ng: metrc: [21771] dup                4894      3.00      0.90      0.81      1631.28        2863.83\nstress-ng: metrc: [21771] kill             316025      3.00      0.21      3.73    105270.00       80205.24\nstress-ng: metrc: [21771] sigfd           6956630      3.00      1.14      4.45   2315377.72     1244999.91\nstress-ng: metrc: [21771] signal                0      3.00      0.66      2.30         0.00           0.00\nstress-ng: metrc: [21771] pty                 225      3.01      0.26      4.43        74.83          48.03\nstress-ng: metrc: [21771] itimer              503      3.00      1.24      3.09       167.67         116.36\nstress-ng: metrc: [21771] timerfd         1120256      3.00      0.66      3.91    372949.46      244900.24\nstress-ng: info:  [21771] skipped: 0\nstress-ng: info:  [21771] passed: 48: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4)\nstress-ng: info:  [21771] failed: 0\nstress-ng: info:  [21771] metrics untrustworthy: 0\nstress-ng: info:  [21771] successful run completed in 3.04 secs"
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
          "prefetch",
          "map_inline"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_os",
      "status": "ok"
    },
    {
      "app": "bcc/biosnoop",
      "baseline": {
        "bpf": {
          "9": {
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 9,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1511683,
            "run_time_ns_delta": 364412494,
            "type": "tracepoint"
          },
          "10": {
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 10,
            "name": "trace_req_start",
            "run_cnt_delta": 1511693,
            "run_time_ns_delta": 333379892,
            "type": "kprobe"
          },
          "11": {
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 11,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1511698,
            "run_time_ns_delta": 155913802,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.360966810000008,
            "ops_per_sec": 377456.1700746655,
            "ops_total": 2023530.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.165582,\n        \"1000\" : 12.512970\n      },\n      \"latency_us\" : {\n        \"2\" : 34.914994,\n        \"4\" : 1.756431,\n        \"10\" : 8.377551,\n        \"20\" : 38.026206,\n        \"50\" : 2.916490,\n        \"100\" : 1.015741,\n        \"250\" : 0.304585,\n        \"500\" : 0.010000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 9,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1520674,
            "run_time_ns_delta": 369312933,
            "type": "tracepoint"
          },
          "10": {
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 10,
            "name": "trace_req_start",
            "run_cnt_delta": 1520684,
            "run_time_ns_delta": 338898664,
            "type": "kprobe"
          },
          "11": {
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 11,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1520689,
            "run_time_ns_delta": 156355522,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.374196623000017,
            "ops_per_sec": 378396.46418906125,
            "ops_total": 2033577.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.042921,\n        \"1000\" : 9.220819\n      },\n      \"latency_us\" : {\n        \"2\" : 38.205176,\n        \"4\" : 1.866097,\n        \"10\" : 8.503362,\n        \"20\" : 37.666099,\n        \"50\" : 2.934210,\n        \"100\" : 1.321901,\n        \"250\" : 0.226617,\n        \"500\" : 0.012798,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "bulk_memory",
          "prefetch",
          "map_inline"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "fio_randrw",
      "status": "ok"
    },
    {
      "app": "bcc/vfsstat",
      "baseline": {
        "bpf": {
          "14": {
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 14,
            "name": "vfs_create",
            "run_cnt_delta": 251265,
            "run_time_ns_delta": 25501065,
            "type": "tracing"
          },
          "15": {
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 15,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 1181,
            "run_time_ns_delta": 84245,
            "type": "tracing"
          },
          "16": {
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 16,
            "name": "vfs_open",
            "run_cnt_delta": 3488243,
            "run_time_ns_delta": 232295763,
            "type": "tracing"
          },
          "17": {
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 17,
            "name": "vfs_read",
            "run_cnt_delta": 108204,
            "run_time_ns_delta": 4856694,
            "type": "tracing"
          },
          "18": {
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 18,
            "name": "vfs_write",
            "run_cnt_delta": 90977,
            "run_time_ns_delta": 4692721,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 3.279703785999999,
            "ops_per_sec": 1694022.1930152085,
            "ops_total": 5555891.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [3181] setting to a 3 secs run per stressor\nstress-ng: info:  [3181] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime, 4 link, 4 symlink, 4 mknod, 4 fcntl\nstress-ng: info:  [3181] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [3274] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [3203] dentry: 420354 dentries allocated\nstress-ng: metrc: [3181] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [3181]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [3181] access            28812      3.04      0.34      3.08      9463.03        8430.10\nstress-ng: metrc: [3181] chdir               333      3.20      1.04      6.41       104.08          44.74\nstress-ng: metrc: [3181] chmod               334      3.05      0.03      0.12       109.69        2179.50\nstress-ng: metrc: [3181] chown               311      3.03      0.02      0.03       102.69        6688.32\nstress-ng: metrc: [3181] dentry            28270      3.08      0.08      0.97      9191.66       27042.82\nstress-ng: metrc: [3181] dir               30210      3.22      0.18      3.06      9382.62        9329.12\nstress-ng: metrc: [3181] dirmany           31704      3.05      0.03      0.77     10411.80       39719.07\nstress-ng: metrc: [3181] fallocate             4      3.04      0.01      0.00         1.32         227.49\nstress-ng: metrc: [3181] file-ioctl       158013      3.02      0.22      1.88     52236.11       75271.28\nstress-ng: metrc: [3181] filename           8349      3.02      0.14      1.80      2760.20        4314.78\nstress-ng: metrc: [3181] flock           4019427      3.02      0.74      1.14   1331199.23     2135556.51\nstress-ng: metrc: [3181] fpunch              998      3.04      0.00      1.86       328.19         537.09\nstress-ng: metrc: [3181] fstat              8891      3.00      0.60      1.90      2960.17        3556.62\nstress-ng: metrc: [3181] getdent          895275      3.00      0.35      7.06    297932.89      120956.04\nstress-ng: metrc: [3181] hdd               41938      3.04      0.97      0.54     13816.46       27828.36\nstress-ng: metrc: [3181] inotify               9      3.08      0.02      0.00         2.92         429.37\nstress-ng: metrc: [3181] open              20458      3.04      0.03      0.31      6724.64       61012.02\nstress-ng: metrc: [3181] rename            76078      3.04      0.07      0.55     25049.16      122020.38\nstress-ng: metrc: [3181] touch             96537      3.05      0.05      3.18     31693.18       29890.96\nstress-ng: metrc: [3181] utime             90131      3.03      0.18      1.50     29790.54       53637.27\nstress-ng: metrc: [3181] link                  9      3.06      0.04      1.15         2.94           7.58\nstress-ng: metrc: [3181] symlink               4      3.12      0.02      1.18         1.28           3.34\nstress-ng: metrc: [3181] mknod               115      3.03      0.02      0.02        38.00        3729.29\nstress-ng: metrc: [3181] fcntl             19681      3.02      0.04      0.26      6516.52       67227.78\nstress-ng: info:  [3181] skipped: 0\nstress-ng: info:  [3181] passed: 96: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4) link (4) symlink (4) mknod (4) fcntl (4)\nstress-ng: info:  [3181] failed: 0\nstress-ng: info:  [3181] metrics untrustworthy: 0\nstress-ng: info:  [3181] successful run completed in 3.27 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "14": {
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 14,
            "name": "vfs_create",
            "run_cnt_delta": 271382,
            "run_time_ns_delta": 16390046,
            "type": "tracing"
          },
          "15": {
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 15,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 890,
            "run_time_ns_delta": 63484,
            "type": "tracing"
          },
          "16": {
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 16,
            "name": "vfs_open",
            "run_cnt_delta": 3926502,
            "run_time_ns_delta": 195188842,
            "type": "tracing"
          },
          "17": {
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 17,
            "name": "vfs_read",
            "run_cnt_delta": 106168,
            "run_time_ns_delta": 4915462,
            "type": "tracing"
          },
          "18": {
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 18,
            "name": "vfs_write",
            "run_cnt_delta": 112189,
            "run_time_ns_delta": 5763096,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 3.2769971790000056,
            "ops_per_sec": 1686118.3266828777,
            "ops_total": 5525405.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [16118] setting to a 3 secs run per stressor\nstress-ng: info:  [16118] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime, 4 link, 4 symlink, 4 mknod, 4 fcntl\nstress-ng: info:  [16118] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [16217] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [16135] dentry: 395260 dentries allocated\nstress-ng: metrc: [16118] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16118]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16118] access            31091      3.05      0.42      3.23     10185.52        8533.82\nstress-ng: metrc: [16118] chdir               239      3.18      0.60      5.25        75.05          40.83\nstress-ng: metrc: [16118] chmod               233      3.07      0.03      0.04        76.00        3442.47\nstress-ng: metrc: [16118] chown               268      3.06      0.00      0.04        87.71        6596.27\nstress-ng: metrc: [16118] dentry            28074      3.09      0.07      0.94      9083.43       27931.83\nstress-ng: metrc: [16118] dir               32769      3.22      0.20      3.71     10189.41        8393.03\nstress-ng: metrc: [16118] dirmany           28887      3.03      0.05      0.70      9522.47       38958.36\nstress-ng: metrc: [16118] fallocate             0      3.06      0.01      0.00         0.00           0.00\nstress-ng: metrc: [16118] file-ioctl       190469      3.01      0.31      2.12     63226.64       78364.99\nstress-ng: metrc: [16118] filename           7614      3.02      0.08      1.65      2520.45        4391.84\nstress-ng: metrc: [16118] flock           3957276      3.01      0.74      1.18   1315420.81     2056000.15\nstress-ng: metrc: [16118] fpunch             1592      3.06      0.00      2.55       519.97         623.36\nstress-ng: metrc: [16118] fstat              7491      3.00      0.62      1.83      2496.74        3059.51\nstress-ng: metrc: [16118] getdent          802823      3.00      0.49      6.27    267251.22      118717.93\nstress-ng: metrc: [16118] hdd               44128      3.04      0.99      0.53     14508.89       29025.01\nstress-ng: metrc: [16118] inotify               8      3.04      0.01      0.01         2.63         429.65\nstress-ng: metrc: [16118] open              25830      3.06      0.05      0.34      8428.41       65668.21\nstress-ng: metrc: [16118] rename            90288      3.04      0.06      0.63     29701.29      131086.61\nstress-ng: metrc: [16118] touch            124572      3.05      0.13      3.19     40817.71       37514.68\nstress-ng: metrc: [16118] utime            119801      3.04      0.17      2.08     39458.45       53337.06\nstress-ng: metrc: [16118] link                 10      3.05      0.09      1.22         3.28           7.65\nstress-ng: metrc: [16118] symlink               4      3.10      0.09      1.11         1.29           3.32\nstress-ng: metrc: [16118] mknod               181      3.04      0.00      0.07        59.57        2440.97\nstress-ng: metrc: [16118] fcntl             31757      3.02      0.09      0.53     10501.30       51623.13\nstress-ng: info:  [16118] skipped: 0\nstress-ng: info:  [16118] passed: 96: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4) link (4) symlink (4) mknod (4) fcntl (4)\nstress-ng: info:  [16118] failed: 0\nstress-ng: info:  [16118] metrics untrustworthy: 0\nstress-ng: info:  [16118] successful run completed in 3.27 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "bulk_memory",
          "prefetch",
          "map_inline"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 5,
          "not_applied": 0,
          "requested": 5
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_filesystem",
      "status": "ok"
    },
    {
      "app": "bcc/opensnoop",
      "baseline": {
        "bpf": {
          "21": {
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 21,
            "name": "__x64_sys_open",
            "run_cnt_delta": 16574,
            "run_time_ns_delta": 4149364,
            "type": "tracing"
          },
          "22": {
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 22,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 1914300,
            "run_time_ns_delta": 524973291,
            "type": "tracing"
          },
          "23": {
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 23,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 2976,
            "run_time_ns_delta": 818473,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 3.3544133070000157,
            "ops_per_sec": 1093595.1131438743,
            "ops_total": 3668370.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [14692] setting to a 3 secs run per stressor\nstress-ng: info:  [14692] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime, 4 link, 4 symlink, 4 mknod, 4 fcntl\nstress-ng: info:  [14692] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [14765] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [14709] dentry: 314514 dentries allocated\nstress-ng: metrc: [14692] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [14692]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [14692] access            29139      3.06      0.42      2.91      9526.38        8749.08\nstress-ng: metrc: [14692] chdir               281      3.23      0.77      5.92        87.00          42.02\nstress-ng: metrc: [14692] chmod               247      3.04      0.02      0.08        81.25        2631.66\nstress-ng: metrc: [14692] chown               252      3.06      0.01      0.04        82.43        5378.98\nstress-ng: metrc: [14692] dentry            32514      3.11      0.09      1.01     10449.27       29640.34\nstress-ng: metrc: [14692] dir               32770      3.30      0.21      3.75      9929.32        8290.64\nstress-ng: metrc: [14692] dirmany           34800      3.04      0.00      0.86     11448.08       40551.08\nstress-ng: metrc: [14692] fallocate             1      3.06      0.00      0.01         0.33          56.57\nstress-ng: metrc: [14692] file-ioctl       210573      3.02      0.38      2.25     69664.74       79967.02\nstress-ng: metrc: [14692] filename           8943      3.04      0.08      1.98      2942.50        4332.05\nstress-ng: metrc: [14692] flock           2174256      3.04      0.47      0.61    715293.44     2015719.65\nstress-ng: metrc: [14692] fpunch             1253      3.04      0.02      2.20       411.75         563.09\nstress-ng: metrc: [14692] fstat              6469      3.00      0.36      1.42      2155.86        3634.62\nstress-ng: metrc: [14692] getdent          708619      3.00      0.36      5.70    236133.57      116938.96\nstress-ng: metrc: [14692] hdd               42406      3.05      1.00      0.49     13906.71       28554.90\nstress-ng: metrc: [14692] inotify               8      3.08      0.02      0.00         2.60         426.10\nstress-ng: metrc: [14692] open              18238      3.08      0.04      0.27      5915.73       59574.05\nstress-ng: metrc: [14692] rename           106585      3.05      0.05      0.80     34995.62      126374.34\nstress-ng: metrc: [14692] touch            139262      3.08      0.10      3.46     45208.73       39145.38\nstress-ng: metrc: [14692] utime             94738      3.02      0.11      1.72     31349.72       51780.29\nstress-ng: metrc: [14692] link                  9      3.08      0.15      1.00         2.92           7.82\nstress-ng: metrc: [14692] symlink               6      3.19      0.10      1.60         1.88           3.53\nstress-ng: metrc: [14692] mknod                60      3.07      0.01      0.02        19.52        1623.46\nstress-ng: metrc: [14692] fcntl             26941      3.03      0.03      0.35      8881.75       71082.74\nstress-ng: info:  [14692] skipped: 0\nstress-ng: info:  [14692] passed: 96: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4) link (4) symlink (4) mknod (4) fcntl (4)\nstress-ng: info:  [14692] failed: 0\nstress-ng: info:  [14692] metrics untrustworthy: 0\nstress-ng: info:  [14692] successful run completed in 3.34 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "21": {
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 21,
            "name": "__x64_sys_open",
            "run_cnt_delta": 16386,
            "run_time_ns_delta": 10790396,
            "type": "tracing"
          },
          "22": {
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 22,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 1947401,
            "run_time_ns_delta": 626292144,
            "type": "tracing"
          },
          "23": {
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 23,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 3130,
            "run_time_ns_delta": 1304390,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 3.293598437000014,
            "ops_per_sec": 1465566.9451910113,
            "ops_total": 4826989.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [2754] setting to a 3 secs run per stressor\nstress-ng: info:  [2754] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime, 4 link, 4 symlink, 4 mknod, 4 fcntl\nstress-ng: info:  [2754] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [2931] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [2771] dentry: 449170 dentries allocated\nstress-ng: metrc: [2754] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2754]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2754] access            35681      3.05      0.51      3.36     11679.72        9212.63\nstress-ng: metrc: [2754] chdir               253      3.16      0.58      5.08        79.99          44.66\nstress-ng: metrc: [2754] chmod               279      3.08      0.00      0.10        90.72        2806.28\nstress-ng: metrc: [2754] chown               252      3.07      0.01      0.03        82.12        5963.23\nstress-ng: metrc: [2754] dentry            25482      3.07      0.12      0.81      8298.38       27213.11\nstress-ng: metrc: [2754] dir               30073      3.24      0.15      3.19      9295.80        8997.49\nstress-ng: metrc: [2754] dirmany           16097      3.02      0.01      0.41      5334.81       38185.81\nstress-ng: metrc: [2754] fallocate             0      3.07      0.01      0.00         0.00           0.00\nstress-ng: metrc: [2754] file-ioctl       168132      3.04      0.20      1.83     55395.84       82789.67\nstress-ng: metrc: [2754] filename           6570      3.04      0.08      1.47      2157.71        4226.41\nstress-ng: metrc: [2754] flock           3212059      3.02      0.60      0.99   1062214.39     2016386.29\nstress-ng: metrc: [2754] fpunch             1432      3.08      0.00      2.43       465.38         588.10\nstress-ng: metrc: [2754] fstat              8489      3.00      0.42      2.06      2828.25        3416.48\nstress-ng: metrc: [2754] getdent          856194      3.00      0.43      6.48    285396.26      123816.35\nstress-ng: metrc: [2754] hdd               41472      3.03      0.83      0.60     13696.54       29038.34\nstress-ng: metrc: [2754] inotify               8      3.06      0.02      0.00         2.61         402.25\nstress-ng: metrc: [2754] open              18196      3.04      0.03      0.30      5982.49       54855.64\nstress-ng: metrc: [2754] rename           139475      3.02      0.05      0.88     46200.16      149965.54\nstress-ng: metrc: [2754] touch            106233      3.04      0.12      3.35     34944.13       30650.20\nstress-ng: metrc: [2754] utime            127799      3.03      0.17      2.29     42169.49       51990.29\nstress-ng: metrc: [2754] link                 12      3.08      0.13      1.44         3.89           7.66\nstress-ng: metrc: [2754] symlink               4      3.18      0.01      1.19         1.26           3.33\nstress-ng: metrc: [2754] mknod               103      3.06      0.03      0.02        33.63        2382.49\nstress-ng: metrc: [2754] fcntl             32694      3.02      0.04      0.48     10816.66       62270.61\nstress-ng: info:  [2754] skipped: 0\nstress-ng: info:  [2754] passed: 96: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4) link (4) symlink (4) mknod (4) fcntl (4)\nstress-ng: info:  [2754] failed: 0\nstress-ng: info:  [2754] metrics untrustworthy: 0\nstress-ng: info:  [2754] successful run completed in 3.28 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "bulk_memory",
          "prefetch",
          "map_inline"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_filesystem",
      "status": "ok"
    },
    {
      "app": "bcc/syscount",
      "baseline": {
        "bpf": {
          "26": {
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 26,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 70509280,
            "run_time_ns_delta": 5331006273,
            "type": "tracepoint"
          },
          "27": {
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 27,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 70509674,
            "run_time_ns_delta": 5984343314,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.056869259999985,
            "ops_per_sec": 1922972.001753202,
            "ops_total": 5878274.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [15171] setting to a 3 secs run per stressor\nstress-ng: info:  [15171] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 dup, 4 kill, 4 sigfd, 4 signal, 4 pty, 4 itimer, 4 timerfd\nstress-ng: info:  [15171] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [15171] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15171]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15171] cap             1399008      3.00      0.49      3.83    465965.99      323615.52\nstress-ng: metrc: [15171] eventfd          663676      3.00      0.60      4.23    221108.83      137338.60\nstress-ng: metrc: [15171] get                8060      3.00      0.26      1.59      2686.11        4375.38\nstress-ng: metrc: [15171] prctl             10949      3.00      2.86      1.44      3648.65        2547.38\nstress-ng: metrc: [15171] set               85172      3.00      0.20      2.94     28389.16       27087.27\nstress-ng: metrc: [15171] dup                4811      3.00      0.86      0.79      1603.61        2906.05\nstress-ng: metrc: [15171] kill             231980      3.00      0.29      3.63     77228.94       59280.60\nstress-ng: metrc: [15171] sigfd           2586953      3.01      0.40      4.13    860544.55      570453.50\nstress-ng: metrc: [15171] signal                0      3.00      0.37      2.75         0.00           0.00\nstress-ng: metrc: [15171] pty                 439      3.01      0.22      5.68       145.96          74.36\nstress-ng: metrc: [15171] itimer              442      3.00      0.24      3.81       147.28         109.34\nstress-ng: metrc: [15171] timerfd          886784      3.00      0.10      5.58    295234.48      156175.58\nstress-ng: info:  [15171] skipped: 0\nstress-ng: info:  [15171] passed: 48: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4)\nstress-ng: info:  [15171] failed: 0\nstress-ng: info:  [15171] metrics untrustworthy: 0\nstress-ng: info:  [15171] successful run completed in 3.04 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "26": {
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 26,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 75828911,
            "run_time_ns_delta": 9109061223,
            "type": "tracepoint"
          },
          "27": {
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 27,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 75829374,
            "run_time_ns_delta": 2069373806,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0585691850000103,
            "ops_per_sec": 2305703.9332592296,
            "ops_total": 7052155.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [24751] setting to a 3 secs run per stressor\nstress-ng: info:  [24751] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 dup, 4 kill, 4 sigfd, 4 signal, 4 pty, 4 itimer, 4 timerfd\nstress-ng: info:  [24751] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24751] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24751]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24751] cap             1159153      3.00      0.39      3.21    386334.92      322248.23\nstress-ng: metrc: [24751] eventfd          637109      3.00      0.40      3.69    212316.10      155754.70\nstress-ng: metrc: [24751] get                7197      3.01      0.11      1.32      2394.52        5034.51\nstress-ng: metrc: [24751] prctl              7899      3.00      2.08      1.05      2632.65        2521.51\nstress-ng: metrc: [24751] set               76304      3.01      0.40      3.43     25374.33       19933.92\nstress-ng: metrc: [24751] dup                3570      3.00      0.65      0.63      1189.93        2800.96\nstress-ng: metrc: [24751] kill             452433      3.00      0.42      5.41    150602.44       77643.70\nstress-ng: metrc: [24751] sigfd           4093197      3.01      0.73      7.00   1361877.49      529596.05\nstress-ng: metrc: [24751] signal                0      3.00      0.12      1.17         0.00           0.00\nstress-ng: metrc: [24751] pty                 154      3.01      0.23      4.68        51.12          31.39\nstress-ng: metrc: [24751] itimer              739      3.00      0.78      5.67       246.18         114.47\nstress-ng: metrc: [24751] timerfd          614400      3.01      0.14      3.78    204312.57      156907.17\nstress-ng: info:  [24751] skipped: 0\nstress-ng: info:  [24751] passed: 48: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4)\nstress-ng: info:  [24751] failed: 0\nstress-ng: info:  [24751] metrics untrustworthy: 0\nstress-ng: info:  [24751] successful run completed in 3.05 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "bulk_memory",
          "prefetch",
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
      "app": "bcc/tcpconnect",
      "baseline": {
        "bpf": {
          "30": {
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 30,
            "name": "trace_connect_entry",
            "run_cnt_delta": 16944,
            "run_time_ns_delta": 4963781,
            "type": "kprobe"
          },
          "31": {
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 31,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 16944,
            "run_time_ns_delta": 31943831,
            "type": "kprobe"
          },
          "32": {
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 32,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.1027522599999884,
            "ops_per_sec": 5457.412832566936,
            "ops_total": 16933.0,
            "stderr": "",
            "stdout": "Running 3s test @ http://127.0.0.1:38117/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     3.45ms   19.20ms 231.23ms   98.05%\n    Req/Sec     2.79k     1.38k    6.12k    68.85%\n  16933 requests in 3.10s, 2.50MB read\n  Socket errors: connect 0, read 16933, write 0, timeout 0\nRequests/sec:   5462.81\nTransfer/sec:    826.98KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "30": {
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 30,
            "name": "trace_connect_entry",
            "run_cnt_delta": 17225,
            "run_time_ns_delta": 4755914,
            "type": "kprobe"
          },
          "31": {
            "bytes_jited": 483,
            "bytes_xlated": 736,
            "id": 31,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 17225,
            "run_time_ns_delta": 32647926,
            "type": "kprobe"
          },
          "32": {
            "bytes_jited": 480,
            "bytes_xlated": 728,
            "id": 32,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.1040804490000085,
            "ops_per_sec": 5545.925849166016,
            "ops_total": 17215.0,
            "stderr": "",
            "stdout": "Running 3s test @ http://127.0.0.1:34657/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     2.68ms   16.05ms 230.94ms   98.65%\n    Req/Sec     2.79k     0.91k    4.18k    48.39%\n  17215 requests in 3.10s, 2.54MB read\n  Socket errors: connect 0, read 17214, write 0, timeout 0\nRequests/sec:   5553.42\nTransfer/sec:    840.69KB"
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
          "prefetch",
          "map_inline"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "tcp_connect",
      "status": "ok"
    },
    {
      "app": "bcc/tcplife",
      "baseline": {
        "bpf": {
          "35": {
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 35,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 161448,
            "run_time_ns_delta": 73120060,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.106121404000021,
            "ops_per_sec": 5332.051728136474,
            "ops_total": 16562.0,
            "stderr": "",
            "stdout": "Running 3s test @ http://127.0.0.1:40707/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     5.99ms   35.43ms 460.93ms   97.48%\n    Req/Sec     2.73k     1.20k    6.16k    63.93%\n  16562 requests in 3.10s, 2.45MB read\n  Socket errors: connect 0, read 16562, write 0, timeout 0\nRequests/sec:   5343.68\nTransfer/sec:    808.95KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "35": {
            "bytes_jited": 1070,
            "bytes_xlated": 1688,
            "id": 35,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 159577,
            "run_time_ns_delta": 72011733,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0045601399999953,
            "ops_per_sec": 5446.055075469391,
            "ops_total": 16363.0,
            "stderr": "",
            "stdout": "Running 3s test @ http://127.0.0.1:44363/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     1.71ms    9.88ms 207.23ms   99.35%\n    Req/Sec     2.74k   730.47     4.27k    50.00%\n  16363 requests in 3.00s, 2.42MB read\n  Socket errors: connect 0, read 16362, write 0, timeout 0\nRequests/sec:   5451.95\nTransfer/sec:    825.34KB"
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
          "prefetch",
          "map_inline"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bcc",
      "selected_workload": "tcp_connect",
      "status": "ok"
    },
    {
      "app": "bcc/runqlat",
      "baseline": {
        "bpf": {
          "38": {
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 38,
            "name": "sched_switch",
            "run_cnt_delta": 32392328,
            "run_time_ns_delta": 6408710946,
            "type": "raw_tracepoint"
          },
          "39": {
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 39,
            "name": "sched_wakeup",
            "run_cnt_delta": 9483538,
            "run_time_ns_delta": 691855320,
            "type": "raw_tracepoint"
          },
          "40": {
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 40,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 29329,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0169554189999985,
            "ops_per_sec": 9972651.50506356,
            "ops_total": 30087045.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [12667] setting to a 3 secs run per stressor\nstress-ng: info:  [12667] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [12667] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12667] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12667]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12667] futex           3508332      6.00      1.17     15.76    584643.31      207139.17\nstress-ng: metrc: [12667] sem             4081004      3.00      1.26      3.23   1360145.07      909332.65\nstress-ng: metrc: [12667] sem-sysv        2141917      3.00      0.39      2.58    713614.52      720630.72\nstress-ng: metrc: [12667] switch          3442216      3.00      0.93      7.44   1147489.76      410992.61\nstress-ng: metrc: [12667] yield          16913576      3.00      5.98     13.22   5635387.60      880871.51\nstress-ng: info:  [12667] skipped: 0\nstress-ng: info:  [12667] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [12667] failed: 0\nstress-ng: info:  [12667] metrics untrustworthy: 0\nstress-ng: info:  [12667] successful run completed in 3.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "38": {
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 38,
            "name": "sched_switch",
            "run_cnt_delta": 32598822,
            "run_time_ns_delta": 6211969103,
            "type": "raw_tracepoint"
          },
          "39": {
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 39,
            "name": "sched_wakeup",
            "run_cnt_delta": 9411893,
            "run_time_ns_delta": 833395894,
            "type": "raw_tracepoint"
          },
          "40": {
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 40,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 27912,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0156489350000015,
            "ops_per_sec": 12360945.78761038,
            "ops_total": 37276273.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [12861] setting to a 3 secs run per stressor\nstress-ng: info:  [12861] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [12861] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12861] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12861]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12861] futex           2459600      6.00      2.18     13.09    409915.22      161129.87\nstress-ng: metrc: [12861] sem            13105137      3.00      2.13      4.91   4367841.39     1860994.34\nstress-ng: metrc: [12861] sem-sysv        2021500      3.00      0.39      2.58    673688.41      681347.69\nstress-ng: metrc: [12861] switch          3836375      3.00      1.37     10.39   1278700.23      326193.54\nstress-ng: metrc: [12861] yield          15853661      3.00      4.00     10.25   5282088.18     1112231.42\nstress-ng: info:  [12861] skipped: 0\nstress-ng: info:  [12861] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [12861] failed: 0\nstress-ng: info:  [12861] metrics untrustworthy: 0\nstress-ng: info:  [12861] successful run completed in 3.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "bulk_memory",
          "prefetch",
          "map_inline"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_scheduler",
      "status": "ok"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline": {
        "bpf": {
          "43": {
            "bytes_jited": 3721,
            "bytes_xlated": 6232,
            "id": 43,
            "name": "perf_unwind_stop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "44": {
            "bytes_jited": 22575,
            "bytes_xlated": 37232,
            "id": 44,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "45": {
            "bytes_jited": 18290,
            "bytes_xlated": 28048,
            "id": 45,
            "name": "perf_unwind_hotspot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "46": {
            "bytes_jited": 17737,
            "bytes_xlated": 29144,
            "id": 46,
            "name": "perf_unwind_perl",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "47": {
            "bytes_jited": 15178,
            "bytes_xlated": 25032,
            "id": 47,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "48": {
            "bytes_jited": 19909,
            "bytes_xlated": 33264,
            "id": 48,
            "name": "perf_unwind_python",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "49": {
            "bytes_jited": 16540,
            "bytes_xlated": 28000,
            "id": 49,
            "name": "perf_unwind_ruby",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "50": {
            "bytes_jited": 20050,
            "bytes_xlated": 33712,
            "id": 50,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "51": {
            "bytes_jited": 22565,
            "bytes_xlated": 34248,
            "id": 51,
            "name": "perf_unwind_dotnet",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "52": {
            "bytes_jited": 1580,
            "bytes_xlated": 2496,
            "id": 52,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "53": {
            "bytes_jited": 696,
            "bytes_xlated": 1088,
            "id": 53,
            "name": "perf_unwind_beam",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "54": {
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 54,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 26380,
            "type": "tracepoint"
          },
          "55": {
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 55,
            "name": "native_tracer_entry",
            "run_cnt_delta": 7950,
            "run_time_ns_delta": 22071097,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.015426613999978,
            "ops_per_sec": 9368.69455308916,
            "ops_total": 46988.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [13006] setting to a 5 secs run per stressor\nstress-ng: info:  [13006] dispatching hogs: 4 cpu\nstress-ng: info:  [13006] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13006] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13006]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13006] cpu               46988      5.00     20.00      0.00      9397.11        2349.33\nstress-ng: info:  [13006] skipped: 0\nstress-ng: info:  [13006] passed: 4: cpu (4)\nstress-ng: info:  [13006] failed: 0\nstress-ng: info:  [13006] metrics untrustworthy: 0\nstress-ng: info:  [13006] successful run completed in 5.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "43": {
            "bytes_jited": 3745,
            "bytes_xlated": 6472,
            "id": 43,
            "name": "perf_unwind_stop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "44": {
            "bytes_jited": 22768,
            "bytes_xlated": 38720,
            "id": 44,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "45": {
            "bytes_jited": 18247,
            "bytes_xlated": 28608,
            "id": 45,
            "name": "perf_unwind_hotspot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "46": {
            "bytes_jited": 17733,
            "bytes_xlated": 29912,
            "id": 46,
            "name": "perf_unwind_perl",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "47": {
            "bytes_jited": 15133,
            "bytes_xlated": 25464,
            "id": 47,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "48": {
            "bytes_jited": 19994,
            "bytes_xlated": 33904,
            "id": 48,
            "name": "perf_unwind_python",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "49": {
            "bytes_jited": 16626,
            "bytes_xlated": 28656,
            "id": 49,
            "name": "perf_unwind_ruby",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "50": {
            "bytes_jited": 20078,
            "bytes_xlated": 34480,
            "id": 50,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "51": {
            "bytes_jited": 22566,
            "bytes_xlated": 34952,
            "id": 51,
            "name": "perf_unwind_dotnet",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "52": {
            "bytes_jited": 1574,
            "bytes_xlated": 2528,
            "id": 52,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "53": {
            "bytes_jited": 702,
            "bytes_xlated": 1136,
            "id": 53,
            "name": "perf_unwind_beam",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "54": {
            "bytes_jited": 789,
            "bytes_xlated": 1352,
            "id": 54,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 19694,
            "type": "tracepoint"
          },
          "55": {
            "bytes_jited": 3554,
            "bytes_xlated": 5656,
            "id": 55,
            "name": "native_tracer_entry",
            "run_cnt_delta": 7940,
            "run_time_ns_delta": 22665160,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.016241985000022,
            "ops_per_sec": 9337.866901171794,
            "ops_total": 46841.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [13132] setting to a 5 secs run per stressor\nstress-ng: info:  [13132] dispatching hogs: 4 cpu\nstress-ng: info:  [13132] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13132] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13132]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13132] cpu               46841      5.00     20.00      0.00      9367.31        2341.82\nstress-ng: info:  [13132] skipped: 0\nstress-ng: info:  [13132] passed: 4: cpu (4)\nstress-ng: info:  [13132] failed: 0\nstress-ng: info:  [13132] metrics untrustworthy: 0\nstress-ng: info:  [13132] successful run completed in 5.00 secs"
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
          "prefetch",
          "map_inline"
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
      "app": "cilium/agent",
      "baseline": {
        "bpf": {
          "63": {
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 63,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "64": {
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 64,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "112": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 112,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "113": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 113,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "114": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 114,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "116": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 116,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "118": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 118,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "120": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 120,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "121": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 121,
            "name": "cil_to_netdev",
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
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 123,
            "name": "cil_from_netdev",
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
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 125,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "126": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 126,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "128": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 128,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "130": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 130,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "132": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 132,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "133": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 133,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "134": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 134,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "135": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 135,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "136": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 136,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1903,
            "type": "sched_cls"
          },
          "137": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 137,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "138": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 138,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "139": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 139,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "140": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 140,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "141": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 141,
            "name": "cil_from_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2041,
            "type": "sched_cls"
          },
          "142": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 142,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "143": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 143,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "144": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 144,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "145": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 145,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "146": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 146,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "147": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 147,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "148": {
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 148,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "149": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 149,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "150": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 150,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 903,
            "type": "sched_cls"
          },
          "151": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 151,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "152": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 152,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "153": {
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 153,
            "name": "cil_from_netdev",
            "run_cnt_delta": 1305,
            "run_time_ns_delta": 1883909,
            "type": "sched_cls"
          },
          "154": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 154,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "155": {
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 155,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "156": {
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 156,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "157": {
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 157,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "158": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 158,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 6.077412200000026,
            "ops_per_sec": 88.03088919984688,
            "ops_total": 535.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   348.05ms  306.52ms   1.93s    83.85%\n    Req/Sec    29.92     16.32    80.00     61.27%\n  535 requests in 5.01s, 85.02KB read\n  Socket errors: connect 0, read 0, write 0, timeout 12\nRequests/sec:    106.86\nTransfer/sec:     16.98KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "63": {
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 63,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "64": {
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 64,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "112": {
            "bytes_jited": 1258,
            "bytes_xlated": 2088,
            "id": 112,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "113": {
            "bytes_jited": 1194,
            "bytes_xlated": 2024,
            "id": 113,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "114": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 114,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "116": {
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 116,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "118": {
            "bytes_jited": 387,
            "bytes_xlated": 608,
            "id": 118,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "120": {
            "bytes_jited": 3391,
            "bytes_xlated": 6064,
            "id": 120,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "121": {
            "bytes_jited": 1258,
            "bytes_xlated": 2088,
            "id": 121,
            "name": "cil_to_netdev",
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
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 123,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "124": {
            "bytes_jited": 387,
            "bytes_xlated": 608,
            "id": 124,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "125": {
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 125,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "126": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 126,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "128": {
            "bytes_jited": 526,
            "bytes_xlated": 968,
            "id": 128,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "130": {
            "bytes_jited": 3391,
            "bytes_xlated": 6064,
            "id": 130,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "132": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 132,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "133": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 133,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "134": {
            "bytes_jited": 387,
            "bytes_xlated": 608,
            "id": 134,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "135": {
            "bytes_jited": 1194,
            "bytes_xlated": 2024,
            "id": 135,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "136": {
            "bytes_jited": 526,
            "bytes_xlated": 968,
            "id": 136,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1277,
            "type": "sched_cls"
          },
          "137": {
            "bytes_jited": 1258,
            "bytes_xlated": 2088,
            "id": 137,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "138": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 138,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "139": {
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 139,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "140": {
            "bytes_jited": 1194,
            "bytes_xlated": 2024,
            "id": 140,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "141": {
            "bytes_jited": 3391,
            "bytes_xlated": 6064,
            "id": 141,
            "name": "cil_from_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2021,
            "type": "sched_cls"
          },
          "142": {
            "bytes_jited": 387,
            "bytes_xlated": 608,
            "id": 142,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "143": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 143,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "144": {
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 144,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "145": {
            "bytes_jited": 1194,
            "bytes_xlated": 2024,
            "id": 145,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "146": {
            "bytes_jited": 3391,
            "bytes_xlated": 6064,
            "id": 146,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "147": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 147,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "148": {
            "bytes_jited": 1258,
            "bytes_xlated": 2088,
            "id": 148,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "149": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 149,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "150": {
            "bytes_jited": 526,
            "bytes_xlated": 968,
            "id": 150,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 889,
            "type": "sched_cls"
          },
          "151": {
            "bytes_jited": 387,
            "bytes_xlated": 608,
            "id": 151,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "152": {
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 152,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "153": {
            "bytes_jited": 3118,
            "bytes_xlated": 5496,
            "id": 153,
            "name": "cil_from_netdev",
            "run_cnt_delta": 1339,
            "run_time_ns_delta": 2004793,
            "type": "sched_cls"
          },
          "154": {
            "bytes_jited": 1194,
            "bytes_xlated": 2024,
            "id": 154,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "155": {
            "bytes_jited": 3391,
            "bytes_xlated": 6064,
            "id": 155,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "156": {
            "bytes_jited": 387,
            "bytes_xlated": 608,
            "id": 156,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "157": {
            "bytes_jited": 526,
            "bytes_xlated": 968,
            "id": 157,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "158": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 158,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 5.065304217000005,
            "ops_per_sec": 108.77925123445739,
            "ops_total": 551.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   337.01ms  292.38ms   1.76s    84.40%\n    Req/Sec    29.07     16.12    80.00     65.57%\n  551 requests in 5.01s, 87.31KB read\n  Socket errors: connect 0, read 0, write 0, timeout 6\nRequests/sec:    110.04\nTransfer/sec:     17.44KB"
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
          "prefetch",
          "map_inline"
        ],
        "error": "prog 64: prog 64 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8d25412eb77a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8d25412eb79a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 125: prog 125 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (61) r7 = *(u32 *)(r6 +48)\n      2: ......67.. (b4) w1 = 0\n      3: .1....67.. (63) *(u32 *)(r6 +48) = r1\n      4: ......67.. (18) r1 = 0xffffd156405fa004\n      6: .1....67.. (71) r1 = *(u8 *)(r1 +0)\n      7: .1....67.. (61) r2 = *(u32 *)(r6 +80)\n      8: .12...67.. (61) r3 = *(u32 *)(r6 +76)\n      9: .123..67.. (0f) r3 += r1\n     10: ..23..67.. (b4) w0 = -134\n     11: 0.23..67.. (07) r3 += 20\n     12: 0.23..67.. (2d) if r3 > r2 goto pc+118\n     13: 0.....67.. (18) r1 = 0xffffd156405fa03c\n     15: 01....67.. (61) r1 = *(u32 *)(r1 +0)\n     16: 0.....67.. (61) r1 = *(u32 *)(r6 +44)\n     17: 01....67.. (63) *(u32 *)(r10 -32) = r1\n     18: 01....67.. (61) r2 = *(u32 *)(r10 -32)\n     19: 012...67.. (63) *(u32 *)(r10 -32) = r1\n     20: 0.2...67.. (54) w2 &= 1\n     21: 0.2...67.. (61) r1 = *(u32 *)(r10 -32)\n     22: 012...67.. (54) w1 &= 2\n     23: 012...67.. (4c) w1 |= w2\n     24: 01....67.. (b4) w8 = 1\n     25: 01....678. (56) if w1 != 0x0 goto pc+1\n     26: 0.....67.. (b4) w8 = 0\n     27: 0.....678. (18) r1 = 0xffffd156405fa004\n     29: 01....678. (71) r1 = *(u8 *)(r1 +0)\n     30: 01....678. (61) r2 = *(u32 *)(r6 +80)\n     31: 012...678. (61) r9 = *(u32 *)(r6 +76)\n     32: 012...6789 (0f) r9 += r1\n     33: 0.2...6789 (bf) r1 = r9\n     34: 012...6789 (07) r1 += 20\n     35: 012...6789 (2d) if r1 > r2 goto pc+95\n     36: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     37: .1....6789 (b7) r2 = 0\n     38: .12...6789 (63) *(u32 *)(r10 -16) = r2\n     39: .12...6789 (63) *(u32 *)(r10 -20) = r2\n     40: .12...6789 (63) *(u32 *)(r10 -24) = r2\n     41: .12...6789 (63) *(u32 *)(r10 -28) = r2\n     42: .1....6789 (63) *(u32 *)(r10 -32) = r1\n     43: ......6789 (b4) w1 = 1\n     44: .1....6789 (73) *(u8 *)(r10 -16) = r1\n     45: ......6789 (bf) r2 = r10\n     46: ..2...6789 (07) r2 += -32\n     47: ..2...6789 (18) r1 = 0xffff8d24c8101800\n     49: .12...6789 (85) call bpf_map_lookup_elem#1\n     50: 0.....6789 (15) if r0 == 0x0 goto pc+43\n     51: 0.....67.9 (18) r1 = 0xffffd156405fa004\n     53: 01....67.9 (71) r2 = *(u8 *)(r1 +0)\n     54: 0.2...67.9 (61) r1 = *(u32 *)(r0 +8)\n     55: 012...67.9 (54) w1 &= 3\n     56: 012...67.9 (56) if w1 != 0x0 goto pc+62\n     57: 0.2...67.9 (79) r1 = *(u64 *)(r0 +24)\n     58: 012...67.9 (7b) *(u64 *)(r10 -40) = r1\n     59: 0.2...67.9 (79) r1 = *(u64 *)(r0 +16)\n     60: 012...67.9 (7b) *(u64 *)(r10 -48) = r1\n     61: 0.2...67.9 (71) r3 = *(u8 *)(r9 +8)\n     62: 0.23..67.9 (a6) if w3 < 0x2 goto pc+95\n     63: 0.23..67.9 (bf) r8 = r0\n     64: ..23..6789 (bc) w4 = w3\n     65: ..234.6789 (04) w4 += -1\n     66: ..234.6789 (73) *(u8 *)(r9 +8) = r4\n     67: ..234.678. (04) w2 += 10\n     68: ..234.678. (54) w4 &= 255\n     69: ..234.678. (bf) r1 = r6\n     70: .1234.678. (b4) w5 = 2\n     71: .12345678. (85) call bpf_l3_csum_replace#10\n     72: 0.....678. (c6) if w0 s< 0x0 goto pc+105\n     73: ......678. (bf) r3 = r10\n     74: ...3..678. (07) r3 += -40\n     75: ...3..678. (bf) r1 = r6\n     76: .1.3..678. (b4) w2 = 6\n     77: .123..678. (b4) w4 = 6\n     78: .1234.678. (b4) w5 = 0\n     79: .12345678. (85) call bpf_skb_store_bytes#9\n     80: 0.....678. (bc) w1 = w0\n     81: .1....678. (b4) w0 = -141\n     82: 01....678. (c6) if w1 s< 0x0 goto pc+48\n     83: ......678. (bf) r3 = r10\n     84: ...3..678. (07) r3 += -48\n     85: ...3..678. (bf) r1 = r6\n     86: .1.3..678. (b4) w2 = 0\n     87: .123..678. (b4) w4 = 6\n     88: .1234.678. (b4) w5 = 0\n     89: .12345678. (85) call bpf_skb_store_bytes#9\n     90: 0.....678. (bc) w1 = w0\n     91: .1....678. (b4) w0 = -141\n     92: 01....678. (c6) if w1 s< 0x0 goto pc+38\n     93: ......678. (05) goto pc+88\n     94: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     95: .1....678. (b4) w2 = 0\n     96: .12...678. (63) *(u32 *)(r10 -12) = r2\n     97: .12...678. (63) *(u32 *)(r10 -16) = r2\n     98: .12...678. (63) *(u32 *)(r10 -20) = r2\n     99: .1....678. (63) *(u32 *)(r10 -24) = r1\n    100: ......678. (b4) w1 = 64\n    101: .1....678. (63) *(u32 *)(r10 -32) = r1\n    102: ......678. (b4) w1 = 16777216\n    103: .1....678\n... verifier log truncated ...; prog 126: prog 126 pass extract failed after 2 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd156405fa049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd156405fa004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd156405fa03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd156405fa05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8d2486542800\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 64 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8d25412eb77a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8d25412eb79a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
            "exit_code": 1,
            "prog_id": 64
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 125 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (61) r7 = *(u32 *)(r6 +48)\n      2: ......67.. (b4) w1 = 0\n      3: .1....67.. (63) *(u32 *)(r6 +48) = r1\n      4: ......67.. (18) r1 = 0xffffd156405fa004\n      6: .1....67.. (71) r1 = *(u8 *)(r1 +0)\n      7: .1....67.. (61) r2 = *(u32 *)(r6 +80)\n      8: .12...67.. (61) r3 = *(u32 *)(r6 +76)\n      9: .123..67.. (0f) r3 += r1\n     10: ..23..67.. (b4) w0 = -134\n     11: 0.23..67.. (07) r3 += 20\n     12: 0.23..67.. (2d) if r3 > r2 goto pc+118\n     13: 0.....67.. (18) r1 = 0xffffd156405fa03c\n     15: 01....67.. (61) r1 = *(u32 *)(r1 +0)\n     16: 0.....67.. (61) r1 = *(u32 *)(r6 +44)\n     17: 01....67.. (63) *(u32 *)(r10 -32) = r1\n     18: 01....67.. (61) r2 = *(u32 *)(r10 -32)\n     19: 012...67.. (63) *(u32 *)(r10 -32) = r1\n     20: 0.2...67.. (54) w2 &= 1\n     21: 0.2...67.. (61) r1 = *(u32 *)(r10 -32)\n     22: 012...67.. (54) w1 &= 2\n     23: 012...67.. (4c) w1 |= w2\n     24: 01....67.. (b4) w8 = 1\n     25: 01....678. (56) if w1 != 0x0 goto pc+1\n     26: 0.....67.. (b4) w8 = 0\n     27: 0.....678. (18) r1 = 0xffffd156405fa004\n     29: 01....678. (71) r1 = *(u8 *)(r1 +0)\n     30: 01....678. (61) r2 = *(u32 *)(r6 +80)\n     31: 012...678. (61) r9 = *(u32 *)(r6 +76)\n     32: 012...6789 (0f) r9 += r1\n     33: 0.2...6789 (bf) r1 = r9\n     34: 012...6789 (07) r1 += 20\n     35: 012...6789 (2d) if r1 > r2 goto pc+95\n     36: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     37: .1....6789 (b7) r2 = 0\n     38: .12...6789 (63) *(u32 *)(r10 -16) = r2\n     39: .12...6789 (63) *(u32 *)(r10 -20) = r2\n     40: .12...6789 (63) *(u32 *)(r10 -24) = r2\n     41: .12...6789 (63) *(u32 *)(r10 -28) = r2\n     42: .1....6789 (63) *(u32 *)(r10 -32) = r1\n     43: ......6789 (b4) w1 = 1\n     44: .1....6789 (73) *(u8 *)(r10 -16) = r1\n     45: ......6789 (bf) r2 = r10\n     46: ..2...6789 (07) r2 += -32\n     47: ..2...6789 (18) r1 = 0xffff8d24c8101800\n     49: .12...6789 (85) call bpf_map_lookup_elem#1\n     50: 0.....6789 (15) if r0 == 0x0 goto pc+43\n     51: 0.....67.9 (18) r1 = 0xffffd156405fa004\n     53: 01....67.9 (71) r2 = *(u8 *)(r1 +0)\n     54: 0.2...67.9 (61) r1 = *(u32 *)(r0 +8)\n     55: 012...67.9 (54) w1 &= 3\n     56: 012...67.9 (56) if w1 != 0x0 goto pc+62\n     57: 0.2...67.9 (79) r1 = *(u64 *)(r0 +24)\n     58: 012...67.9 (7b) *(u64 *)(r10 -40) = r1\n     59: 0.2...67.9 (79) r1 = *(u64 *)(r0 +16)\n     60: 012...67.9 (7b) *(u64 *)(r10 -48) = r1\n     61: 0.2...67.9 (71) r3 = *(u8 *)(r9 +8)\n     62: 0.23..67.9 (a6) if w3 < 0x2 goto pc+95\n     63: 0.23..67.9 (bf) r8 = r0\n     64: ..23..6789 (bc) w4 = w3\n     65: ..234.6789 (04) w4 += -1\n     66: ..234.6789 (73) *(u8 *)(r9 +8) = r4\n     67: ..234.678. (04) w2 += 10\n     68: ..234.678. (54) w4 &= 255\n     69: ..234.678. (bf) r1 = r6\n     70: .1234.678. (b4) w5 = 2\n     71: .12345678. (85) call bpf_l3_csum_replace#10\n     72: 0.....678. (c6) if w0 s< 0x0 goto pc+105\n     73: ......678. (bf) r3 = r10\n     74: ...3..678. (07) r3 += -40\n     75: ...3..678. (bf) r1 = r6\n     76: .1.3..678. (b4) w2 = 6\n     77: .123..678. (b4) w4 = 6\n     78: .1234.678. (b4) w5 = 0\n     79: .12345678. (85) call bpf_skb_store_bytes#9\n     80: 0.....678. (bc) w1 = w0\n     81: .1....678. (b4) w0 = -141\n     82: 01....678. (c6) if w1 s< 0x0 goto pc+48\n     83: ......678. (bf) r3 = r10\n     84: ...3..678. (07) r3 += -48\n     85: ...3..678. (bf) r1 = r6\n     86: .1.3..678. (b4) w2 = 0\n     87: .123..678. (b4) w4 = 6\n     88: .1234.678. (b4) w5 = 0\n     89: .12345678. (85) call bpf_skb_store_bytes#9\n     90: 0.....678. (bc) w1 = w0\n     91: .1....678. (b4) w0 = -141\n     92: 01....678. (c6) if w1 s< 0x0 goto pc+38\n     93: ......678. (05) goto pc+88\n     94: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     95: .1....678. (b4) w2 = 0\n     96: .12...678. (63) *(u32 *)(r10 -12) = r2\n     97: .12...678. (63) *(u32 *)(r10 -16) = r2\n     98: .12...678. (63) *(u32 *)(r10 -20) = r2\n     99: .1....678. (63) *(u32 *)(r10 -24) = r1\n    100: ......678. (b4) w1 = 64\n    101: .1....678. (63) *(u32 *)(r10 -32) = r1\n    102: ......678. (b4) w1 = 16777216\n    103: .1....678\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 125
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 126 pass extract failed after 2 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd156405fa049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd156405fa004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd156405fa03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd156405fa05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8d2486542800\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 126
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 40,
          "not_applied": 3,
          "requested": 43
        }
      },
      "runner": "cilium",
      "selected_workload": "network_lossy_multi",
      "status": "ok"
    },
    {
      "app": "tetragon/observer",
      "baseline": {
        "bpf": {
          "175": {
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 175,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 6853,
            "run_time_ns_delta": 8737196,
            "type": "kprobe"
          },
          "176": {
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 176,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 7707,
            "run_time_ns_delta": 16282078,
            "type": "kprobe"
          },
          "177": {
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 177,
            "name": "event_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 14396,
            "type": "tracepoint"
          },
          "178": {
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 178,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "179": {
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 179,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "180": {
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 180,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1101,
            "type": "kprobe"
          },
          "181": {
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 181,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "184": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 184,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "185": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 185,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "186": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 186,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "187": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 187,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "188": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 188,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "189": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 189,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "190": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 190,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "191": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 191,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "192": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 192,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "193": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 193,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "194": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 194,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "195": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 195,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "196": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 196,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "197": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 197,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "198": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 198,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "199": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 199,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "200": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 200,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "201": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 201,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "202": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 202,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "203": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 203,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "204": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 204,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "205": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 205,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "206": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 206,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "207": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 207,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 52555,
            "run_time_ns_delta": 43721216,
            "type": "kprobe"
          },
          "208": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 208,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "209": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 209,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "210": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 210,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "211": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 211,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "212": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 212,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "213": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 213,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 52555,
            "run_time_ns_delta": 29250052,
            "type": "kprobe"
          },
          "214": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 214,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "215": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 215,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "216": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 216,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "217": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 217,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "218": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 218,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "219": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 219,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "220": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 220,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "221": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 221,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 60867,
            "run_time_ns_delta": 72952467,
            "type": "kprobe"
          },
          "222": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 222,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "223": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 223,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "224": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 224,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "225": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 225,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "226": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 226,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "227": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 227,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "228": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 228,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "229": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 229,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "230": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 230,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "231": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 231,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "232": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 232,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "233": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 233,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "234": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 234,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "235": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 235,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "236": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 236,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 52555,
            "run_time_ns_delta": 42563530,
            "type": "kprobe"
          },
          "237": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 237,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "238": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 238,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 52555,
            "run_time_ns_delta": 33197089,
            "type": "kprobe"
          },
          "239": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 239,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "240": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 240,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "241": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 241,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "242": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 242,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "243": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 243,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "244": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 244,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "245": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 245,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "246": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 246,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "247": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 247,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 60867,
            "run_time_ns_delta": 69944555,
            "type": "kprobe"
          },
          "248": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 248,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "249": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 249,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "250": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 250,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "251": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 251,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "252": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 252,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "253": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 253,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "254": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 254,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 437495,
            "run_time_ns_delta": 423154701,
            "type": "kprobe"
          },
          "255": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 255,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "256": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 256,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "257": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 257,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "258": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 258,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "259": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 259,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "260": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 260,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "261": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 261,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 676283,
            "run_time_ns_delta": 673173025,
            "type": "kprobe"
          },
          "262": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 262,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 263,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "264": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 264,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "265": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 265,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 266,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "267": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 267,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "268": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 268,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 269,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 270,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 271,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 272,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 273,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "274": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 274,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "275": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 275,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 276,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 920722,
            "run_time_ns_delta": 216125070,
            "type": "kprobe"
          },
          "277": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 277,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 278,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "279": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 279,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 280,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 281,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "282": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 282,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 283,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 284,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 285,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 286,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2373116,
            "run_time_ns_delta": 1266028999,
            "type": "kprobe"
          },
          "287": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 287,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 288,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 289,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "290": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 290,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 291,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 292,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 293,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2373116,
            "run_time_ns_delta": 95713579,
            "type": "kprobe"
          },
          "294": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 294,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 295,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 296,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "297": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 297,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 299796,
            "run_time_ns_delta": 2004448790,
            "type": "kprobe"
          },
          "298": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 298,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 299,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 300,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 301,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 302,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 299796,
            "run_time_ns_delta": 19073921,
            "type": "kprobe"
          },
          "303": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 303,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 304,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 305,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 41,
            "run_time_ns_delta": 281991,
            "type": "kprobe"
          },
          "306": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 306,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 307,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "308": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 308,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "309": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 309,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "310": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 310,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "311": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 311,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "312": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 312,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 313,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "314": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 314,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 41,
            "run_time_ns_delta": 19947,
            "type": "kprobe"
          },
          "315": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 315,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "316": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 316,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "317": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 317,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "318": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 318,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 319,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "320": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 320,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "321": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 321,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 322,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "323": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 323,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "324": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 324,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 325,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "326": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 326,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "327": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 327,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 328,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "329": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 329,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 330,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "331": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 331,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "332": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 332,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "333": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 333,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "334": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 334,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 335,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 336,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 337,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 338,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "339": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 339,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "340": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 340,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "341": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 341,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "342": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 342,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "343": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 343,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "344": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 344,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "345": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 345,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "346": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 346,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "347": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 347,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "348": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 348,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "349": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 349,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "350": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 350,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "351": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 351,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 352,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "353": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 353,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "354": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 354,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "355": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 355,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "356": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 356,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "357": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 357,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 11612,
            "type": "kprobe"
          },
          "358": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 358,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "359": {
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 359,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "360": {
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 360,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "361": {
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 361,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "362": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 362,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "363": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 363,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "364": {
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 364,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 38313090,
            "run_time_ns_delta": 34986740339,
            "type": "tracepoint"
          },
          "365": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 365,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "366": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 366,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "367": {
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 367,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "368": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 368,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "369": {
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 369,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "370": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 370,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 10878,
            "type": "raw_tracepoint"
          },
          "371": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 371,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "372": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 372,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "373": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 373,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "374": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 374,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 17749,
            "run_time_ns_delta": 27653701,
            "type": "kprobe"
          },
          "375": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 375,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "376": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 376,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "377": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 377,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "378": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 378,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "379": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 379,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 380,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "381": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 381,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 75375,
            "run_time_ns_delta": 318867029,
            "type": "kprobe"
          },
          "382": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 382,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "383": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 383,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "384": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 384,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "385": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 385,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "386": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 386,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 387,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "388": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 388,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "389": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 389,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 390,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 391,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "392": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 392,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "393": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 393,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "394": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 394,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "395": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 395,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "396": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 396,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "397": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 397,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "398": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 398,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 52555,
            "run_time_ns_delta": 44630324,
            "type": "kprobe"
          },
          "399": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 399,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "400": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 400,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "401": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 401,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "402": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 402,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "403": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 403,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 52555,
            "run_time_ns_delta": 34434024,
            "type": "kprobe"
          },
          "404": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 404,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "405": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 405,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "406": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 406,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "407": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 407,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 60867,
            "run_time_ns_delta": 71218556,
            "type": "kprobe"
          },
          "408": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 408,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "409": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 409,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "410": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 410,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "411": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 411,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 412,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 413,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 414,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "415": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 415,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 416,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 417,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 134865,
            "run_time_ns_delta": 84011953,
            "type": "kprobe"
          },
          "418": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 418,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "419": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 419,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 33702,
            "run_time_ns_delta": 43428986,
            "type": "kprobe"
          },
          "420": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 420,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "421": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 421,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "422": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 422,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "423": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 423,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "424": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 424,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 425,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "426": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 426,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "427": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 427,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 16846,
            "run_time_ns_delta": 23320691,
            "type": "kprobe"
          },
          "428": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 428,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "429": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 429,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "430": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 430,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 431,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "432": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 432,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "433": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 433,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "434": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 434,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 435,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 16846,
            "run_time_ns_delta": 30251993,
            "type": "kprobe"
          },
          "436": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 436,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "437": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 437,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "438": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 438,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 16846,
            "run_time_ns_delta": 28571169,
            "type": "kprobe"
          },
          "439": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 439,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "440": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 440,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "441": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 441,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "442": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 442,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "443": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 443,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "444": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 444,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "445": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 445,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "446": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 446,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "447": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 447,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "448": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 448,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "449": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 449,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 33702,
            "run_time_ns_delta": 44804376,
            "type": "kprobe"
          },
          "450": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 450,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "451": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 451,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 439438,
            "run_time_ns_delta": 469350259,
            "type": "kprobe"
          },
          "452": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 452,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "453": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 453,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "454": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 454,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "455": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 455,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "456": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 456,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "457": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 457,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "458": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 458,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "459": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 459,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "460": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 460,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "461": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 461,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 462,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "463": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 463,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.287532303999967,
            "ops_per_sec": 3700207.748177593,
            "ops_total": 19564968.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [22817] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22817]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22817] cap              476107      5.05      0.28      4.39     94256.72      101828.48\nstress-ng: metrc: [22817] eventfd           73068      5.00      0.12      1.26     14601.38       52957.38\nstress-ng: metrc: [22817] get                2614      5.01      0.09      1.36       521.67        1798.39\nstress-ng: metrc: [22817] prctl              3661      5.01      1.98      0.68       730.12        1375.82\nstress-ng: metrc: [22817] set               21255      5.04      0.11      2.36      4221.29        8608.36\nstress-ng: metrc: [22817] dup                1449      5.02      0.35      0.36       288.84        2036.98\nstress-ng: metrc: [22817] kill              31576      5.03      0.06      1.82      6274.14       16801.07\nstress-ng: metrc: [22817] sigfd            705035      5.07      0.14      4.82    139139.35      142149.17\nstress-ng: metrc: [22817] signal                0      5.00      0.01      0.00         0.00           0.00\nstress-ng: metrc: [22817] pty                 125      5.04      0.18      6.76        24.79          18.01\nstress-ng: metrc: [22817] itimer              275      5.06      0.08      2.40        54.30         110.87\nstress-ng: metrc: [22817] timerfd          357376      5.06      0.11      2.96     70676.46      116414.51\nstress-ng: metrc: [22817] aio               24282      5.05      0.03      0.21      4809.90      102650.60\nstress-ng: metrc: [22817] aiol               6284      5.21      0.10      0.86      1205.05        6557.97\nstress-ng: metrc: [22817] hdd               44747      5.06      0.92      0.65      8848.15       28564.70\nstress-ng: metrc: [22817] io                  168      5.07      0.04      0.00        33.11        4141.81\nstress-ng: metrc: [22817] iomix              3728      5.10      0.09      3.16       730.54        1147.87\nstress-ng: metrc: [22817] io-uring          30808      5.11      0.01      1.54      6028.48       19899.28\nstress-ng: metrc: [22817] sync-file           114      5.04      0.05      1.18        22.64          92.51\nstress-ng: metrc: [22817] epoll               655      5.16      0.07      0.20       126.88        2446.65\nstress-ng: metrc: [22817] netdev            44767      5.05      0.07      0.96      8868.88       43732.98\nstress-ng: metrc: [22817] sctp               5921      5.00      0.04      0.01      1183.60      115540.73\nstress-ng: metrc: [22817] sock                827      5.05      0.00      1.67       163.92         493.71\nstress-ng: metrc: [22817] sockdiag       15004624      5.03      0.05      2.37   2985645.26     6190557.61\nstress-ng: metrc: [22817] sockfd           189101      5.02      0.02      1.71     37699.33      109427.62\nstress-ng: metrc: [22817] sockpair            462      5.07      0.04      0.18        91.07        2148.34\nstress-ng: metrc: [22817] sockmany          16844      5.08      0.01      1.64      3318.82       10200.30\nstress-ng: metrc: [22817] udp               35771      5.05      0.06      1.39      7084.06       24792.88\nstress-ng: metrc: [22817] udp-flood        137325      5.03      0.07      1.12     27285.41      115576.12\nstress-ng: metrc: [22817] mmap                170      5.03      0.03      1.87        33.81          89.35\nstress-ng: metrc: [22817] mprotect        2340490      5.08      0.82     13.80    461101.24      160048.97\nstress-ng: metrc: [22817] mremap             5268      5.01      0.08      4.89      1052.38        1060.91\nstress-ng: metrc: [22817] madvise              71      5.02      0.13      3.78        14.16          18.14\nstress-ng: info:  [22817] skipped: 0\nstress-ng: info:  [22817] passed: 132: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp (4) udp-flood (4) mmap (4) mprotect (4) mremap (4) madvise (4)\nstress-ng: info:  [22817] failed: 0\nstress-ng: info:  [22817] metrics untrustworthy: 0\nstress-ng: info:  [22817] successful run completed in 5.27 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "175": {
            "bytes_jited": 1029,
            "bytes_xlated": 1872,
            "id": 175,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 6136,
            "run_time_ns_delta": 8174499,
            "type": "kprobe"
          },
          "176": {
            "bytes_jited": 7128,
            "bytes_xlated": 11152,
            "id": 176,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 6941,
            "run_time_ns_delta": 15832726,
            "type": "kprobe"
          },
          "177": {
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 177,
            "name": "event_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 18520,
            "type": "tracepoint"
          },
          "178": {
            "bytes_jited": 1395,
            "bytes_xlated": 2416,
            "id": 178,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "179": {
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 179,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "180": {
            "bytes_jited": 1541,
            "bytes_xlated": 2592,
            "id": 180,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1987,
            "type": "kprobe"
          },
          "181": {
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 181,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "184": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 184,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "185": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 185,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "186": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 186,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "187": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 187,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "188": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 188,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "189": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 189,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "190": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 190,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "191": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 191,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "192": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 192,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "193": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 193,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "194": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 194,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "195": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 195,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "196": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 196,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "197": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 197,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "198": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 198,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "199": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 199,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "200": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 200,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "201": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 201,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "202": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 202,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "203": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 203,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "204": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 204,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "205": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 205,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "206": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 206,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "207": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 207,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 52539,
            "run_time_ns_delta": 59332465,
            "type": "kprobe"
          },
          "208": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 208,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "209": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 209,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "210": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 210,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "211": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 211,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "212": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 212,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "213": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 213,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 52539,
            "run_time_ns_delta": 57278620,
            "type": "kprobe"
          },
          "214": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 214,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "215": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 215,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "216": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 216,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "217": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 217,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "218": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 218,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "219": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 219,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "220": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 220,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "221": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 221,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 66261,
            "run_time_ns_delta": 84804602,
            "type": "kprobe"
          },
          "222": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 222,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "223": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 223,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "224": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 224,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "225": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 225,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "226": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 226,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "227": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 227,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "228": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 228,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "229": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 229,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "230": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 230,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "231": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 231,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "232": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 232,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "233": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 233,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "234": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 234,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "235": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 235,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "236": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 236,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 52539,
            "run_time_ns_delta": 59774847,
            "type": "kprobe"
          },
          "237": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 237,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "238": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 238,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 52539,
            "run_time_ns_delta": 66683290,
            "type": "kprobe"
          },
          "239": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 239,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "240": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 240,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "241": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 241,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "242": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 242,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "243": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 243,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "244": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 244,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "245": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 245,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "246": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 246,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "247": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 247,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 66261,
            "run_time_ns_delta": 82027590,
            "type": "kprobe"
          },
          "248": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 248,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "249": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 249,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "250": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 250,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "251": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 251,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "252": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 252,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "253": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 253,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "254": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 254,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 705562,
            "run_time_ns_delta": 704787072,
            "type": "kprobe"
          },
          "255": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 255,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "256": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 256,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "257": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 257,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "258": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 258,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "259": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 259,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "260": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 260,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "261": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 261,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 916552,
            "run_time_ns_delta": 947660955,
            "type": "kprobe"
          },
          "262": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 262,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 263,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "264": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 264,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "265": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 265,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 266,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "267": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 267,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "268": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 268,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 269,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 270,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 271,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 272,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 273,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "274": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 274,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "275": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 275,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 276,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 777612,
            "run_time_ns_delta": 177554740,
            "type": "kprobe"
          },
          "277": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 277,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 278,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "279": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 279,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 280,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 281,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "282": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 282,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 283,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 284,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 285,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 286,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1898307,
            "run_time_ns_delta": 1028046661,
            "type": "kprobe"
          },
          "287": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 287,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 288,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 289,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "290": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 290,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 291,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 292,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 293,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1898307,
            "run_time_ns_delta": 77624907,
            "type": "kprobe"
          },
          "294": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 294,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 295,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 296,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "297": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 297,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 314064,
            "run_time_ns_delta": 1547929358,
            "type": "kprobe"
          },
          "298": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 298,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 299,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 300,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 301,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 302,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 314064,
            "run_time_ns_delta": 15088971,
            "type": "kprobe"
          },
          "303": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 303,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 304,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 305,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 43,
            "run_time_ns_delta": 317325,
            "type": "kprobe"
          },
          "306": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 306,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 307,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "308": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 308,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "309": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 309,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "310": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 310,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "311": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 311,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "312": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 312,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 313,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "314": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 314,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 43,
            "run_time_ns_delta": 19757,
            "type": "kprobe"
          },
          "315": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 315,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "316": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 316,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "317": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 317,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "318": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 318,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 319,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "320": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 320,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "321": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 321,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 322,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "323": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 323,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "324": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 324,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 325,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "326": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 326,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "327": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 327,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 328,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "329": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 329,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 330,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "331": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 331,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "332": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 332,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "333": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 333,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "334": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 334,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 335,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 336,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 337,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 338,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "339": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 339,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "340": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 340,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "341": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 341,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "342": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 342,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "343": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 343,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "344": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 344,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "345": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 345,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "346": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 346,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "347": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 347,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "348": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 348,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "349": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 349,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "350": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 350,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "351": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 351,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 352,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "353": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 353,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "354": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 354,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "355": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 355,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "356": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 356,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "357": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 357,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 11355,
            "type": "kprobe"
          },
          "358": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 358,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "359": {
            "bytes_jited": 14893,
            "bytes_xlated": 25800,
            "id": 359,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "360": {
            "bytes_jited": 4781,
            "bytes_xlated": 8648,
            "id": 360,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "361": {
            "bytes_jited": 11118,
            "bytes_xlated": 18152,
            "id": 361,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "362": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 362,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "363": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 363,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "364": {
            "bytes_jited": 10963,
            "bytes_xlated": 19728,
            "id": 364,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 37856778,
            "run_time_ns_delta": 36984316994,
            "type": "tracepoint"
          },
          "365": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 365,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "366": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 366,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "367": {
            "bytes_jited": 17087,
            "bytes_xlated": 29584,
            "id": 367,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "368": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 368,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "369": {
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 369,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "370": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 370,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 10370,
            "type": "raw_tracepoint"
          },
          "371": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 371,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "372": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 372,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "373": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 373,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "374": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 374,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 30276,
            "run_time_ns_delta": 48976263,
            "type": "kprobe"
          },
          "375": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 375,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "376": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 376,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "377": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 377,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "378": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 378,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "379": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 379,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 380,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "381": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 381,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 27774,
            "run_time_ns_delta": 121026100,
            "type": "kprobe"
          },
          "382": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 382,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "383": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 383,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "384": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 384,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "385": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 385,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "386": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 386,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 387,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "388": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 388,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "389": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 389,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 390,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 391,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "392": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 392,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "393": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 393,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "394": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 394,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "395": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 395,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "396": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 396,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "397": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 397,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "398": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 398,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 52539,
            "run_time_ns_delta": 59955446,
            "type": "kprobe"
          },
          "399": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 399,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "400": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 400,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "401": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 401,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "402": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 402,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "403": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 403,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 52539,
            "run_time_ns_delta": 66136274,
            "type": "kprobe"
          },
          "404": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 404,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "405": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 405,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "406": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 406,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "407": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 407,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 66261,
            "run_time_ns_delta": 84441129,
            "type": "kprobe"
          },
          "408": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 408,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "409": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 409,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "410": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 410,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "411": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 411,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 412,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 413,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 414,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "415": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 415,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 416,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 417,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 161103,
            "run_time_ns_delta": 105244313,
            "type": "kprobe"
          },
          "418": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 418,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "419": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 419,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 40764,
            "run_time_ns_delta": 57654259,
            "type": "kprobe"
          },
          "420": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 420,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "421": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 421,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "422": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 422,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "423": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 423,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "424": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 424,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 425,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "426": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 426,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "427": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 427,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 20375,
            "run_time_ns_delta": 29982633,
            "type": "kprobe"
          },
          "428": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 428,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "429": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 429,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "430": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 430,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 431,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "432": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 432,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "433": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 433,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "434": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 434,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 435,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 20375,
            "run_time_ns_delta": 43942821,
            "type": "kprobe"
          },
          "436": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 436,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "437": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 437,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "438": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 438,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 20377,
            "run_time_ns_delta": 38372294,
            "type": "kprobe"
          },
          "439": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 439,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "440": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 440,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "441": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 441,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "442": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 442,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "443": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 443,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "444": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 444,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "445": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 445,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "446": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 446,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "447": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 447,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "448": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 448,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "449": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 449,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 40764,
            "run_time_ns_delta": 57967290,
            "type": "kprobe"
          },
          "450": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 450,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "451": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 451,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 439391,
            "run_time_ns_delta": 529863387,
            "type": "kprobe"
          },
          "452": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 452,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "453": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 453,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "454": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 454,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "455": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 455,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "456": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 456,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "457": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 457,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "458": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 458,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "459": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 459,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "460": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 460,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "461": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 461,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 462,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "463": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 463,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.308663326999977,
            "ops_per_sec": 4632019.490657014,
            "ops_total": 24589832.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [7487] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7487]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7487] cap              321848      5.06      0.12      3.10     63628.84      100060.90\nstress-ng: metrc: [7487] eventfd          115406      5.00      0.13      2.06     23066.32       52768.51\nstress-ng: metrc: [7487] get                3029      5.02      0.12      1.63       603.27        1724.64\nstress-ng: metrc: [7487] prctl              3454      5.02      1.92      0.65       687.86        1342.79\nstress-ng: metrc: [7487] set               13239      5.04      0.04      1.58      2624.76        8199.19\nstress-ng: metrc: [7487] dup                1194      5.00      0.29      0.31       238.62        1976.95\nstress-ng: metrc: [7487] kill              34653      5.06      0.04      2.32      6846.32       14644.20\nstress-ng: metrc: [7487] sigfd            512098      5.09      0.14      3.11    100579.46      157572.93\nstress-ng: metrc: [7487] signal                0      5.02      0.01      0.00         0.00           0.00\nstress-ng: metrc: [7487] pty                  40      5.10      0.06      2.43         7.84          16.07\nstress-ng: metrc: [7487] itimer              517      5.06      0.11      4.38       102.21         114.98\nstress-ng: metrc: [7487] timerfd          135168      5.14      0.07      1.10     26298.72      116066.08\nstress-ng: metrc: [7487] aio               26269      5.06      0.02      0.24      5188.29      102468.38\nstress-ng: metrc: [7487] aiol               3699      5.22      0.05      0.57       708.46        5921.20\nstress-ng: metrc: [7487] hdd               43676      5.12      0.83      0.76      8524.86       27452.97\nstress-ng: metrc: [7487] io                  137      5.13      0.02      0.01        26.70        4345.07\nstress-ng: metrc: [7487] iomix              3380      5.14      0.12      3.05       657.37        1067.65\nstress-ng: metrc: [7487] io-uring          26568      5.14      0.01      1.72      5169.59       15352.31\nstress-ng: metrc: [7487] sync-file            95      5.06      0.02      1.07        18.77          87.61\nstress-ng: metrc: [7487] epoll               791      5.10      0.02      0.09       155.00        7236.76\nstress-ng: metrc: [7487] netdev           118974      5.06      0.07      2.88     23522.30       40424.50\nstress-ng: metrc: [7487] sctp              21822      5.04      0.00      1.43      4333.62       15302.56\nstress-ng: metrc: [7487] sock                820      5.04      0.00      1.78       162.82         459.43\nstress-ng: metrc: [7487] sockdiag       20004224      5.04      0.06      3.59   3968929.22     5474904.91\nstress-ng: metrc: [7487] sockfd           179009      5.05      0.05      1.66     35433.17      104430.98\nstress-ng: metrc: [7487] sockpair            619      5.09      0.03      0.20       121.59        2739.29\nstress-ng: metrc: [7487] sockmany          20373      5.10      0.03      2.09      3994.97        9605.44\nstress-ng: metrc: [7487] udp               89686      5.06      0.05      2.31     17741.55       37948.26\nstress-ng: metrc: [7487] udp-flood        130148      5.04      0.01      1.05     25834.64      122220.65\nstress-ng: metrc: [7487] mmap                241      5.04      0.03      1.74        47.82         136.66\nstress-ng: metrc: [7487] mprotect        2776460      5.05      0.81     17.98    549632.01      147748.59\nstress-ng: metrc: [7487] mremap             2131      5.01      0.05      2.14       425.03         971.35\nstress-ng: metrc: [7487] madvise              64      5.03      0.21      3.57        12.72          16.94\nstress-ng: info:  [7487] skipped: 0\nstress-ng: info:  [7487] passed: 132: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp (4) udp-flood (4) mmap (4) mprotect (4) mremap (4) madvise (4)\nstress-ng: info:  [7487] failed: 0\nstress-ng: info:  [7487] metrics untrustworthy: 0\nstress-ng: info:  [7487] successful run completed in 5.28 secs"
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
          "prefetch",
          "map_inline"
        ],
        "error": "prog 177: prog 177 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @1724\nfunc#2 @1840\nfunc#3 @2033\nfunc#4 @2208\nfunc#5 @2277\nfunc#6 @2300\nfunc#7 @2370\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (85) call bpf_get_current_task#35\n      2: 0.....6... (bf) r9 = r0\n      3: ......6..9 (7b) *(u64 *)(r10 -128) = r6\n      4: ......6..9 (61) r6 = *(u32 *)(r6 +8)\n      5: ......6..9 (b7) r1 = 0\n      6: .1....6..9 (63) *(u32 *)(r10 -120) = r1\n      7: ......6..9 (bf) r2 = r10\n      8: ..2...6..9 (07) r2 += -120\n      9: ..2...6..9 (18) r1 = 0xffff8d25412c2600\n     11: .12...6..9 (85) call bpf_map_lookup_elem#1\n     12: 0.....6..9 (bf) r7 = r0\n     13: ......67.9 (15) if r7 == 0x0 goto pc+1689\n     14: ......67.9 (7b) *(u64 *)(r10 -144) = r6\n     15: .......7.9 (85) call bpf_get_current_pid_tgid#14\n     16: 0......7.9 (bf) r6 = r0\n     17: ......67.9 (85) call bpf_get_current_task#35\n     18: 0.....67.9 (7b) *(u64 *)(r10 -96) = r0\n     19: 0.....67.9 (b7) r8 = 2816\n     20: 0.....6789 (0f) r0 += r8\n     21: 0.....6789 (bf) r1 = r10\n     22: 01....6789 (07) r1 += -96\n     23: 01....6789 (b7) r2 = 8\n     24: 012...6789 (bf) r3 = r0\n     25: .123..6789 (85) call bpf_probe_read_kernel#113\n     26: ......6789 (7b) *(u64 *)(r10 -160) = r6\n     27: ......6789 (7b) *(u64 *)(r10 -152) = r6\n     28: .......789 (79) r3 = *(u64 *)(r10 -96)\n     29: ...3...789 (7b) *(u64 *)(r10 -136) = r9\n     30: ...3...789 (15) if r3 == 0x0 goto pc+162\n     31: ...3...789 (b7) r1 = 2804\n     32: .1.3...789 (0f) r3 += r1\n     33: ...3...789 (bf) r1 = r10\n     34: .1.3...789 (07) r1 += -8\n     35: .1.3...789 (b7) r2 = 4\n     36: .123...789 (85) call bpf_probe_read_kernel#113\n     37: .......789 (61) r1 = *(u32 *)(r10 -8)\n     38: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     39: .......789 (bf) r2 = r10\n     40: ..2....789 (07) r2 += -112\n     41: ..2....789 (18) r1 = 0xffff8d2a0c137000\n     43: .12....789 (85) call bpf_map_lookup_elem#1\n     44: 0......789 (bf) r6 = r0\n     45: ......6789 (15) if r6 == 0x0 goto pc+3\n     46: ......6789 (05) goto pc+0\n     47: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     48: .1....6789 (55) if r1 != 0x0 goto pc+81\n     49: .......789 (b7) r1 = 2816\n     50: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     51: .1.3...789 (0f) r3 += r1\n     52: ...3...789 (bf) r1 = r10\n     53: .1.3...789 (07) r1 += -96\n     54: .1.3...789 (b7) r2 = 8\n     55: .123...789 (85) call bpf_probe_read_kernel#113\n     56: .......789 (79) r3 = *(u64 *)(r10 -96)\n     57: ...3...789 (15) if r3 == 0x0 goto pc+135\n     58: ...3...789 (b7) r1 = 2804\n     59: .1.3...789 (0f) r3 += r1\n     60: ...3...789 (bf) r1 = r10\n     61: .1.3...789 (07) r1 += -8\n     62: .1.3...789 (b7) r2 = 4\n     63: .123...789 (85) call bpf_probe_read_kernel#113\n     64: .......789 (61) r1 = *(u32 *)(r10 -8)\n     65: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     66: .......789 (bf) r2 = r10\n     67: ..2....789 (07) r2 += -112\n     68: ..2....789 (18) r1 = 0xffff8d2a0c137000\n     70: .12....789 (85) call bpf_map_lookup_elem#1\n     71: 0......789 (bf) r6 = r0\n     72: ......6789 (15) if r6 == 0x0 goto pc+3\n     73: ......6789 (05) goto pc+0\n     74: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     75: .1....6789 (55) if r1 != 0x0 goto pc+54\n     76: .......789 (b7) r1 = 2816\n     77: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     78: .1.3...789 (0f) r3 += r1\n     79: ...3...789 (bf) r1 = r10\n     80: .1.3...789 (07) r1 += -96\n     81: .1.3...789 (b7) r2 = 8\n     82: .123...789 (85) call bpf_probe_read_kernel#113\n     83: .......789 (79) r3 = *(u64 *)(r10 -96)\n     84: ...3...789 (15) if r3 == 0x0 goto pc+108\n     85: ...3...789 (b7) r1 = 2804\n     86: .1.3...789 (0f) r3 += r1\n     87: ...3...789 (bf) r1 = r10\n     88: .1.3...789 (07) r1 += -8\n     89: .1.3...789 (b7) r2 = 4\n     90: .123...789 (85) call bpf_probe_read_kernel#113\n     91: .......789 (61) r1 = *(u32 *)(r10 -8)\n     92: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     93: .......789 (bf) r2 = r10\n     94: ..2....789 (07) r2 += -112\n     95: ..2....789 (18) r1 = 0xffff8d2a0c137000\n     97: .12....789 (85) call bpf_map_lookup_elem#1\n     98: 0......789 (bf) r6 = r0\n\n... verifier log truncated ...; prog 179: prog 179 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @844\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 0\n      2: ......67.. (63) *(u32 *)(r10 -88) = r7\n      3: ......67.. (bf) r2 = r10\n      4: ..2...67.. (07) r2 += -88\n      5: ..2...67.. (18) r1 = 0xffff8d25412c2600\n      7: .12...67.. (85) call bpf_map_lookup_elem#1\n      8: 0.....67.. (15) if r0 == 0x0 goto pc+821\n      9: 0.....67.. (7b) *(u64 *)(r10 -120) = r6\n     10: 0......7.. (bf) r8 = r0\n     11: 0......78. (bf) r6 = r0\n     12: ......678. (85) call bpf_get_current_task#35\n     13: 0.....678. (b7) r1 = 2680\n     14: 01....678. (0f) r0 += r1\n     15: 0.....678. (bf) r1 = r10\n     16: 01....678. (07) r1 += -72\n     17: 01....678. (b7) r2 = 8\n     18: 012...678. (bf) r3 = r0\n     19: .123..678. (85) call bpf_probe_read#4\n     20: ......678. (b7) r1 = 1448\n     21: .1....678. (79) r3 = *(u64 *)(r10 -72)\n     22: .1.3..678. (0f) r3 += r1\n     23: ...3..678. (bf) r1 = r10\n     24: .1.3..678. (07) r1 += -64\n     25: .1.3..678. (b7) r2 = 8\n     26: .123..678. (85) call bpf_probe_read#4\n     27: ......678. (79) r9 = *(u64 *)(r10 -64)\n     28: ......6789 (63) *(u32 *)(r10 -84) = r7\n     29: ......6.89 (bf) r2 = r10\n     30: ..2...6.89 (07) r2 += -84\n     31: ..2...6.89 (18) r1 = 0xffff8d2482249200\n     33: .12...6.89 (85) call bpf_map_lookup_elem#1\n     34: 0.....6.89 (7b) *(u64 *)(r10 -104) = r6\n     35: 0.....6.89 (07) r6 += 5808\n     36: 0.....6.89 (7b) *(u64 *)(r10 -112) = r6\n     37: 0.......89 (bf) r2 = r8\n     38: 0.2.....89 (7b) *(u64 *)(r10 -96) = r8\n     39: 0.2......9 (bf) r8 = r0\n     40: ..2.....89 (55) if r8 != 0x0 goto pc+1\n     41: .......... (05) goto pc+254\n     42: ..2.....89 (b7) r1 = 64\n     43: .12.....89 (0f) r9 += r1\n     44: ..2.....89 (b7) r1 = 4096\n     45: .12.....89 (63) *(u32 *)(r2 +6192) = r1\n     46: ........89 (85) call bpf_get_current_task#35\n     47: 0.......89 (b7) r1 = 3408\n     48: 01......89 (0f) r0 += r1\n     49: 0.......89 (bf) r1 = r10\n     50: 01......89 (07) r1 += -80\n     51: 01......89 (b7) r2 = 8\n     52: 012.....89 (bf) r3 = r0\n     53: .123....89 (85) call bpf_probe_read#4\n     54: ........89 (b7) r1 = 8\n     55: .1......89 (7b) *(u64 *)(r10 -128) = r9\n     56: .1......89 (0f) r9 += r1\n     57: ........89 (79) r7 = *(u64 *)(r10 -80)\n     58: .......789 (bf) r1 = r10\n     59: .1.....789 (07) r1 += -72\n     60: .1.....789 (b7) r2 = 8\n     61: .12....789 (7b) *(u64 *)(r10 -136) = r9\n     62: .12....789 (bf) r3 = r9\n     63: .123...78. (85) call bpf_probe_read#4\n     64: .......78. (b7) r1 = 8\n     65: .1.....78. (79) r6 = *(u64 *)(r10 -72)\n     66: .1....678. (bf) r3 = r6\n     67: .1.3..678. (0f) r3 += r1\n     68: ...3..678. (b7) r1 = 8\n     69: .1.3..678. (0f) r3 += r1\n     70: ...3..678. (bf) r1 = r10\n     71: .1.3..678. (07) r1 += -64\n     72: .1.3..678. (b7) r2 = 8\n     73: .123..678. (85) call bpf_probe_read#4\n     74: ......678. (79) r3 = *(u64 *)(r10 -96)\n     75: ...3..678. (bf) r9 = r8\n     76: ...3..6789 (07) r9 += 4096\n     77: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     78: .1.3..6789 (55) if r1 != 0x0 goto pc+41\n     79: ......6789 (b7) r1 = 24\n     80: .1....6789 (bf) r3 = r6\n     81: .1.3..6789 (0f) r3 += r1\n     82: ...3..6789 (bf) r1 = r10\n     83: .1.3..6789 (07) r1 += -64\n     84: .1.3..6789 (b7) r2 = 8\n     85: .123..6789 (85) call bpf_probe_read#4\n     86: ......6789 (79) r3 = *(u64 *)(r10 -96)\n     87: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     88: .1.3..6789 (1d) if r1 == r6 goto pc+31\n     89: ...3...789 (61) r1 = *(u32 *)(r3 +6192)\n     90: .1.3...789 (bf) r2 = r1\n     91: .123...789 (07) r2 += -10\n     92: .123...789 (63) *(u32 *)(r3 +6192) = r2\n     93: .123...789 (67) r1 <<= 32\n     94: .123...789 (c7) r1 s>>= 32\n     95: .123...789 (65) if r1 s> 0x9 goto pc+5\n     96: ..23.....9 (18) r1 = 0xffffffdc\n     98: .123.....9 (63) *(u32 *)(r3 +6196) = r1\n     99: ..2......9 (bf) r7 = r9\n    100: ..2....7.. (05) goto pc+93\n    101: ...3...78. (b7) r1 = 41\n    102: .1.3...78. (73) *(u8 *)(r8 +4095) = r1\n    103: ...3...78. (b7) r1 = 116\n    104: .1.3...78. (73) *(u8 *)(r8 +4092) = r1\n    105: ...3\n... verifier log truncated ...; prog 190: prog 190 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 196: prog 196 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 200: prog 200 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 203: prog 203 pass cond_select failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nfunc#1 @3102\nfunc#2 @3218\nfunc#3 @3409\nfunc#4 @3445\nfunc#5 @3514\nLive regs before insn:\n      0: .1........ (bf) r9 = r1\n      1: .........9 (b7) r1 = 0\n      2: .1.......9 (63) *(u32 *)(r10 -172) = r1\n      3: .........9 (bf) r2 = r10\n      4: ..2......9 (07) r2 += -172\n      5: ..2......9 (18) r1 = 0xffff8d2552457200\n      7: .12......9 (85) call bpf_map_lookup_elem#1\n      8: 0........9 (bf) r7 = r0\n      9: .......7.9 (15) if r7 == 0x0 goto pc+489\n     10: .......7.9 (61) r8 = *(u32 *)(r7 +24292)\n     11: .......789 (67) r8 <<= 32\n     12: .......789 (c7) r8 s>>= 32\n     13: .......789 (61) r1 = *(u32 *)(r7 +4)\n     14: .1.....789 (bf) r6 = r1\n     15: .1....6789 (25) if r1 > 0x2327 goto pc+433\n     16: .1.....789 (7b) *(u64 *)(r10 -184) = r1\n     17: .......789 (b7) r1 = 0\n     18: .1.....789 (63) *(u32 *)(r10 -156) = r1\n     19: .......789 (bf) r2 = r10\n     20: ..2....789 (07) r2 += -156\n     21: ..2....789 (18) r1 = 0xffff8d2552457200\n     23: .12....789 (85) call bpf_map_lookup_elem#1\n     24: 0......789 (bf) r6 = r0\n     25: ......6789 (15) if r6 == 0x0 goto pc+59\n     26: ......6789 (bf) r2 = r6\n     27: ..2...6789 (07) r2 += 24288\n     28: ..2...6789 (18) r1 = 0xffff8d2a0c136400\n     30: .12...6789 (85) call bpf_map_lookup_elem#1\n     31: 0.....6789 (15) if r0 == 0x0 goto pc+53\n     32: 0.....6789 (7b) *(u64 *)(r10 -208) = r6\n     33: 0......789 (7b) *(u64 *)(r10 -200) = r7\n     34: 0.......89 (bf) r7 = r8\n     35: 0......789 (57) r7 &= 7\n     36: 0......789 (67) r7 <<= 32\n     37: 0......789 (c7) r7 s>>= 32\n     38: 0......789 (bf) r1 = r7\n     39: 01.....789 (67) r1 <<= 2\n     40: 01.....789 (bf) r2 = r0\n     41: 012....789 (0f) r2 += r1\n     42: 0.2....789 (71) r3 = *(u8 *)(r2 +65)\n     43: 0.23...789 (67) r3 <<= 8\n     44: 0.23...789 (71) r1 = *(u8 *)(r2 +64)\n     45: 0123...789 (4f) r3 |= r1\n     46: 0.23...789 (71) r4 = *(u8 *)(r2 +66)\n     47: 0.234..789 (67) r4 <<= 16\n     48: 0.234..789 (71) r1 = *(u8 *)(r2 +67)\n     49: 01234..789 (67) r1 <<= 24\n     50: 01234..789 (4f) r1 |= r4\n     51: 0123...789 (4f) r1 |= r3\n     52: 012....789 (71) r3 = *(u8 *)(r2 +5)\n     53: 0123...789 (67) r3 <<= 8\n     54: 0123...789 (71) r4 = *(u8 *)(r2 +4)\n     55: 01234..789 (4f) r3 |= r4\n     56: 0123...789 (71) r4 = *(u8 *)(r2 +6)\n     57: 01234..789 (67) r4 <<= 16\n     58: 01234..789 (71) r6 = *(u8 *)(r2 +7)\n     59: 01234.6789 (67) r6 <<= 24\n     60: 01234.6789 (4f) r6 |= r4\n     61: 0123..6789 (4f) r6 |= r3\n     62: 012...6789 (71) r5 = *(u8 *)(r2 +27)\n     63: 012..56789 (71) r3 = *(u8 *)(r2 +26)\n     64: 0123.56789 (71) r4 = *(u8 *)(r2 +24)\n     65: 0123456789 (71) r2 = *(u8 *)(r2 +25)\n     66: 0123456789 (57) r1 &= 7\n     67: 0123456789 (67) r2 <<= 8\n     68: 0123456789 (4f) r2 |= r4\n     69: 0123.56789 (67) r3 <<= 16\n     70: 0123.56789 (67) r5 <<= 24\n     71: 0123.56789 (4f) r5 |= r3\n     72: 012..56789 (4f) r5 |= r2\n     73: 01...56789 (7b) *(u64 *)(r10 -216) = r5\n     74: 01...56789 (bf) r2 = r5\n     75: 012...6789 (57) r2 &= 64\n     76: 012...6789 (7b) *(u64 *)(r10 -192) = r8\n     77: 012...67.9 (15) if r2 == 0x0 goto pc+9\n     78: 0.....67.9 (bf) r8 = r9\n     79: 0.....678. (bf) r9 = r0\n     80: ......6789 (85) call bpf_get_current_task#35\n     81: 0.....6789 (bf) r1 = r0\n     82: .1....6789 (bf) r0 = r9\n     83: 01....678. (bf) r9 = r8\n     84: 01....67.9 (05) goto pc+8\n     85: .......789 (79) r6 = *(u64 *)(r10 -184)\n     86: ......6789 (05) goto pc+362\n     87: 01....67.9 (67) r1 <<= 32\n     88: 01....67.9 (c7) r1 s>>= 32\n     89: 01....67.9 (67) r1 <<= 3\n     90: 01....67.9 (79) r2 = *(u64 *)(r10 -208)\n     91: 012...67.9 (0f) r2 += r1\n     92: 0.2...67.9 (79) r1 = *(u64 *)(r2 +24144)\n     93: 01....67.9 (7b) *(u64 *)(r10 -168) = r1\n     94: 0.....67.9 (79) r4 = *(u64 *)(r10 -184)\n     95: 0...4.67.9 (65) if r7 s> 0x4 goto pc+24\n     96: 0...4.67.9 (bf) r1 = r7\n     97: 01..4.67.9 (57) r1 &= 7\n     98: 01..4.67.9 (67) r1 <<= 32\n     99: 01..4.67.9 (c7) r1 s>>= 32\n    100: 01..4.67.9 (27) r1 *= 80\n    101: 01..4.67.9 (0f) r0 += r1\n    102: 0...4.67.9 (71) r1 = *(u8 *)(r0 +119)\n    103: 01..4.67\n... verifier log truncated ...; prog 205: prog 205 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r1 = 0\n      2: .1....6... (63) *(u32 *)(r10 -116) = r1\n      3: ......6... (bf) r2 = r10\n      4: ..2...6... (07) r2 += -116\n      5: ..2...6... (18) r1 = 0xffff8d272840dc00\n      7: .12...6... (85) call bpf_map_lookup_elem#1\n      8: 0.....6... (bf) r7 = r0\n      9: ......67.. (15) if r7 == 0x0 goto pc+368\n     10: ......67.. (7b) *(u64 *)(r10 -128) = r6\n     11: .......7.. (79) r1 = *(u64 *)(r7 +24272)\n     12: .1.....7.. (15) if r1 == 0x0 goto pc+203\n     13: .......7.. (85) call bpf_get_current_pid_tgid#14\n     14: 0......7.. (bf) r6 = r0\n     15: ......67.. (85) call bpf_get_current_task#35\n     16: 0.....67.. (bf) r9 = r0\n     17: ......67.9 (77) r6 >>= 32\n     18: ......67.9 (63) *(u32 *)(r10 -80) = r6\n     19: .......7.9 (bf) r2 = r10\n     20: ..2....7.9 (07) r2 += -80\n     21: ..2....7.9 (18) r1 = 0xffff8d2a0c137000\n     23: .12....7.9 (85) call bpf_map_lookup_elem#1\n     24: 0......7.9 (bf) r8 = r0\n     25: .......789 (15) if r8 == 0x0 goto pc+190\n     26: .......789 (b7) r1 = 3440\n     27: .1.....789 (bf) r3 = r9\n     28: .1.3...789 (0f) r3 += r1\n     29: ...3...789 (bf) r1 = r10\n     30: .1.3...789 (07) r1 += -8\n     31: .1.3...789 (b7) r2 = 8\n     32: .123...789 (85) call bpf_probe_read#4\n     33: .......789 (79) r3 = *(u64 *)(r10 -8)\n     34: ...3...789 (bf) r6 = r10\n     35: ...3..6789 (07) r6 += -80\n     36: ...3..6789 (bf) r1 = r6\n     37: .1.3..6789 (b7) r2 = 72\n     38: .123..6789 (85) call bpf_probe_read#4\n     39: ...3456789 (bf) r1 = r8\n     40: .1.3456789 (07) r1 += 40\n     41: .1.3456789 (b7) r2 = 1\n     42: .123456789 (15) if r2 == 0x0 goto pc+2\n     43: .1....6789 (b7) r2 = 536\n     44: .12...6789 (05) goto pc+1\n     45: .123456789 (85) call unknown#195896080\n     46: .12...6789 (79) r3 = *(u64 *)(r6 +8)\n     47: .123...789 (0f) r3 += r2\n     48: .1.3...789 (b7) r2 = 4\n     49: .123...789 (85) call bpf_probe_read#4\n     50: ..2.45.789 (b7) r1 = 1\n     51: .12.45.789 (15) if r1 == 0x0 goto pc+5\n     52: .......789 (bf) r1 = r10\n     53: .1.....789 (07) r1 += -80\n     54: .1.....789 (79) r3 = *(u64 *)(r1 +16)\n     55: ...3...789 (b7) r1 = 1240\n     56: .1.3...789 (05) goto pc+4\n     57: ..2.45.789 (bf) r1 = r10\n     58: .12.45.789 (07) r1 += -80\n     59: .12.45.789 (79) r3 = *(u64 *)(r1 +16)\n     60: .12345.789 (85) call unknown#195896080\n     61: .1.3...789 (0f) r3 += r1\n     62: ...3...789 (bf) r1 = r8\n     63: .1.3...789 (07) r1 += 44\n     64: .1.3...789 (b7) r2 = 4\n     65: .123...789 (85) call bpf_probe_read#4\n     66: ..2.45.789 (b7) r1 = 1\n     67: .12.45.789 (15) if r1 == 0x0 goto pc+8\n     68: .......789 (bf) r1 = r10\n     69: .1.....789 (07) r1 += -80\n     70: .1.....789 (79) r3 = *(u64 *)(r1 +24)\n     71: ...3...789 (b7) r1 = 88\n     72: .1.3...789 (0f) r3 += r1\n     73: ...3...789 (bf) r1 = r8\n     74: .1.3...789 (07) r1 += 48\n     75: .1.3...789 (05) goto pc+7\n     76: ..2.45.789 (bf) r1 = r10\n     77: .12.45.789 (07) r1 += -80\n     78: .12.45.789 (79) r3 = *(u64 *)(r1 +24)\n     79: .12345.789 (85) call unknown#195896080\n     80: .1.3...789 (0f) r3 += r1\n     81: ...3...789 (bf) r1 = r8\n     82: .1.3...789 (07) r1 += 44\n     83: .1.3...789 (b7) r2 = 4\n     84: .123...789 (85) call bpf_probe_read#4\n     85: ....45.789 (b7) r1 = 1\n     86: .1..45.789 (15) if r1 == 0x0 goto pc+40\n     87: .......789 (b7) r6 = 0\n     88: ......6789 (7b) *(u64 *)(r10 -88) = r6\n     89: ......6789 (b7) r1 = 2904\n     90: .1....6789 (bf) r3 = r9\n     91: .1.3..6789 (0f) r3 += r1\n     92: ...3..6789 (bf) r1 = r10\n     93: .1.3..6789 (07) r1 += -88\n     94: .1.3..6789 (b7) r2 = 8\n     95: .123..6789 (85) call bpf_probe_read#4\n     96: ....456789 (79) r3 = *(u64 *)(r10 -88)\n     97: ...3456789 (15) if r3 == 0x0 goto pc+28\n     98: ...3..6789 (63) *(u32 *)(r10 -92) = r6\n     99: ...3...789 (b7) r1 = 4\n    100: .1.3...789 (0f) r3 += r1\n    101: ...3...789 (bf) r1 = r10\n    102: .1.3...789 (07) r1 += -92\n    103: .1.3...789 (b7) r2 = 4\n    104: .123...789 (85) call bpf_probe_read#4\n    105: .......789 (b7) r1 = 128\n    106:\n... verifier log truncated ...; prog 208: prog 208 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 214: prog 214 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 219: prog 219 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 225: prog 225 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 231: prog 231 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 237: prog 237 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 244: prog 244 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 249: prog 249 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 259: prog 259 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 262: prog 262 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 274: prog 274 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 281: prog 281 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 288: prog 288 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 290: prog 290 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 300: prog 300 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 301: prog 301 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 306: prog 306 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 312: prog 312 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 318: prog 318 pass extract failed after 2 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nfunc#1 @3102\nfunc#2 @3218\nfunc#3 @3409\nfunc#4 @3445\nfunc#5 @3514\nLive regs before insn:\n      0: .1........ (bf) r9 = r1\n      1: .........9 (b7) r1 = 0\n      2: .1.......9 (63) *(u32 *)(r10 -172) = r1\n      3: .........9 (bf) r2 = r10\n      4: ..2......9 (07) r2 += -172\n      5: ..2......9 (18) r1 = 0xffff8d2486043600\n      7: .12......9 (85) call bpf_map_lookup_elem#1\n      8: 0........9 (bf) r7 = r0\n      9: .......7.9 (15) if r7 == 0x0 goto pc+489\n     10: .......7.9 (61) r8 = *(u32 *)(r7 +24292)\n     11: .......789 (67) r8 <<= 32\n     12: .......789 (c7) r8 s>>= 32\n     13: .......789 (61) r1 = *(u32 *)(r7 +4)\n     14: .1.....789 (bf) r6 = r1\n     15: .1....6789 (25) if r1 > 0x2327 goto pc+433\n     16: .1.....789 (7b) *(u64 *)(r10 -184) = r1\n     17: .......789 (b7) r1 = 0\n     18: .1.....789 (63) *(u32 *)(r10 -156) = r1\n     19: .......789 (bf) r2 = r10\n     20: ..2....789 (07) r2 += -156\n     21: ..2....789 (18) r1 = 0xffff8d2486043600\n     23: .12....789 (85) call bpf_map_lookup_elem#1\n     24: 0......789 (bf) r6 = r0\n     25: ......6789 (15) if r6 == 0x0 goto pc+59\n     26: ......6789 (bf) r2 = r6\n     27: ..2...6789 (07) r2 += 24288\n     28: ..2...6789 (18) r1 = 0xffff8d28e3415000\n     30: .12...6789 (85) call bpf_map_lookup_elem#1\n     31: 0.....6789 (15) if r0 == 0x0 goto pc+53\n     32: 0.....6789 (7b) *(u64 *)(r10 -208) = r6\n     33: 0......789 (7b) *(u64 *)(r10 -200) = r7\n     34: 0.......89 (bf) r7 = r8\n     35: 0......789 (57) r7 &= 7\n     36: 0......789 (67) r7 <<= 32\n     37: 0......789 (c7) r7 s>>= 32\n     38: 0......789 (bf) r1 = r7\n     39: 01.....789 (67) r1 <<= 2\n     40: 01.....789 (bf) r2 = r0\n     41: 012....789 (0f) r2 += r1\n     42: 0.2....789 (71) r3 = *(u8 *)(r2 +65)\n     43: 0.23...789 (67) r3 <<= 8\n     44: 0.23...789 (71) r1 = *(u8 *)(r2 +64)\n     45: 0123...789 (4f) r3 |= r1\n     46: 0.23...789 (71) r4 = *(u8 *)(r2 +66)\n     47: 0.234..789 (67) r4 <<= 16\n     48: 0.234..789 (71) r1 = *(u8 *)(r2 +67)\n     49: 01234..789 (67) r1 <<= 24\n     50: 01234..789 (4f) r1 |= r4\n     51: 0123...789 (4f) r1 |= r3\n     52: 012....789 (71) r3 = *(u8 *)(r2 +5)\n     53: 0123...789 (67) r3 <<= 8\n     54: 0123...789 (71) r4 = *(u8 *)(r2 +4)\n     55: 01234..789 (4f) r3 |= r4\n     56: 0123...789 (71) r4 = *(u8 *)(r2 +6)\n     57: 01234..789 (67) r4 <<= 16\n     58: 01234..789 (71) r6 = *(u8 *)(r2 +7)\n     59: 01234.6789 (67) r6 <<= 24\n     60: 01234.6789 (4f) r6 |= r4\n     61: 0123..6789 (4f) r6 |= r3\n     62: 012...6789 (71) r5 = *(u8 *)(r2 +27)\n     63: 012..56789 (71) r3 = *(u8 *)(r2 +26)\n     64: 0123.56789 (71) r4 = *(u8 *)(r2 +24)\n     65: 0123456789 (71) r2 = *(u8 *)(r2 +25)\n     66: 0123456789 (57) r1 &= 7\n     67: 0123456789 (67) r2 <<= 8\n     68: 0123456789 (4f) r2 |= r4\n     69: 0123.56789 (67) r3 <<= 16\n     70: 0123.56789 (67) r5 <<= 24\n     71: 0123.56789 (4f) r5 |= r3\n     72: 012..56789 (4f) r5 |= r2\n     73: 01...56789 (7b) *(u64 *)(r10 -216) = r5\n     74: 01...56789 (bf) r2 = r5\n     75: 012...6789 (57) r2 &= 64\n     76: 012...6789 (7b) *(u64 *)(r10 -192) = r8\n     77: 012...67.9 (15) if r2 == 0x0 goto pc+9\n     78: 0.....67.9 (bf) r8 = r9\n     79: 0.....678. (bf) r9 = r0\n     80: ......6789 (85) call bpf_get_current_task#35\n     81: 0.....6789 (bf) r1 = r0\n     82: .1....6789 (bf) r0 = r9\n     83: 01....678. (bf) r9 = r8\n     84: 01....67.9 (05) goto pc+8\n     85: .......789 (79) r6 = *(u64 *)(r10 -184)\n     86: ......6789 (05) goto pc+362\n     87: 01....67.9 (67) r1 <<= 32\n     88: 01....67.9 (c7) r1 s>>= 32\n     89: 01....67.9 (67) r1 <<= 3\n     90: 01....67.9 (79) r2 = *(u64 *)(r10 -208)\n     91: 012...67.9 (0f) r2 += r1\n     92: 0.2...67.9 (79) r1 = *(u64 *)(r2 +24144)\n     93: 01....67.9 (7b) *(u64 *)(r10 -168) = r1\n     94: 0.....67.9 (79) r4 = *(u64 *)(r10 -184)\n     95: 0...4.67.9 (65) if r7 s> 0x4 goto pc+24\n     96: 0...4.67.9 (bf) r1 = r7\n     97: 01..4.67.9 (57) r1 &= 7\n     98: 01..4.67.9 (67) r1 <<= 32\n     99: 01..4.67.9 (c7) r1 s>>= 32\n    100: 01..4.67.9 (27) r1 *= 80\n    101: 01..4.67.9 (0f) r0 += r1\n    102: 0...4.67.9 (71) r1 = *(u8 *)(r0 +119)\n    103: 01..4.67\n... verifier log truncated ...; prog 320: prog 320 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 325: prog 325 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 328: prog 328 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 336: prog 336 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 339: prog 339 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 345: prog 345 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 355: prog 355 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 362: prog 362 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 368: prog 368 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 372: prog 372 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 380: prog 380 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 388: prog 388 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 395: prog 395 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 400: prog 400 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 410: prog 410 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 414: prog 414 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 423: prog 423 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 430: prog 430 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 432: prog 432 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 442: prog 442 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 448: prog 448 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 453: prog 453 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 458: prog 458 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 177 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @1724\nfunc#2 @1840\nfunc#3 @2033\nfunc#4 @2208\nfunc#5 @2277\nfunc#6 @2300\nfunc#7 @2370\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (85) call bpf_get_current_task#35\n      2: 0.....6... (bf) r9 = r0\n      3: ......6..9 (7b) *(u64 *)(r10 -128) = r6\n      4: ......6..9 (61) r6 = *(u32 *)(r6 +8)\n      5: ......6..9 (b7) r1 = 0\n      6: .1....6..9 (63) *(u32 *)(r10 -120) = r1\n      7: ......6..9 (bf) r2 = r10\n      8: ..2...6..9 (07) r2 += -120\n      9: ..2...6..9 (18) r1 = 0xffff8d25412c2600\n     11: .12...6..9 (85) call bpf_map_lookup_elem#1\n     12: 0.....6..9 (bf) r7 = r0\n     13: ......67.9 (15) if r7 == 0x0 goto pc+1689\n     14: ......67.9 (7b) *(u64 *)(r10 -144) = r6\n     15: .......7.9 (85) call bpf_get_current_pid_tgid#14\n     16: 0......7.9 (bf) r6 = r0\n     17: ......67.9 (85) call bpf_get_current_task#35\n     18: 0.....67.9 (7b) *(u64 *)(r10 -96) = r0\n     19: 0.....67.9 (b7) r8 = 2816\n     20: 0.....6789 (0f) r0 += r8\n     21: 0.....6789 (bf) r1 = r10\n     22: 01....6789 (07) r1 += -96\n     23: 01....6789 (b7) r2 = 8\n     24: 012...6789 (bf) r3 = r0\n     25: .123..6789 (85) call bpf_probe_read_kernel#113\n     26: ......6789 (7b) *(u64 *)(r10 -160) = r6\n     27: ......6789 (7b) *(u64 *)(r10 -152) = r6\n     28: .......789 (79) r3 = *(u64 *)(r10 -96)\n     29: ...3...789 (7b) *(u64 *)(r10 -136) = r9\n     30: ...3...789 (15) if r3 == 0x0 goto pc+162\n     31: ...3...789 (b7) r1 = 2804\n     32: .1.3...789 (0f) r3 += r1\n     33: ...3...789 (bf) r1 = r10\n     34: .1.3...789 (07) r1 += -8\n     35: .1.3...789 (b7) r2 = 4\n     36: .123...789 (85) call bpf_probe_read_kernel#113\n     37: .......789 (61) r1 = *(u32 *)(r10 -8)\n     38: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     39: .......789 (bf) r2 = r10\n     40: ..2....789 (07) r2 += -112\n     41: ..2....789 (18) r1 = 0xffff8d2a0c137000\n     43: .12....789 (85) call bpf_map_lookup_elem#1\n     44: 0......789 (bf) r6 = r0\n     45: ......6789 (15) if r6 == 0x0 goto pc+3\n     46: ......6789 (05) goto pc+0\n     47: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     48: .1....6789 (55) if r1 != 0x0 goto pc+81\n     49: .......789 (b7) r1 = 2816\n     50: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     51: .1.3...789 (0f) r3 += r1\n     52: ...3...789 (bf) r1 = r10\n     53: .1.3...789 (07) r1 += -96\n     54: .1.3...789 (b7) r2 = 8\n     55: .123...789 (85) call bpf_probe_read_kernel#113\n     56: .......789 (79) r3 = *(u64 *)(r10 -96)\n     57: ...3...789 (15) if r3 == 0x0 goto pc+135\n     58: ...3...789 (b7) r1 = 2804\n     59: .1.3...789 (0f) r3 += r1\n     60: ...3...789 (bf) r1 = r10\n     61: .1.3...789 (07) r1 += -8\n     62: .1.3...789 (b7) r2 = 4\n     63: .123...789 (85) call bpf_probe_read_kernel#113\n     64: .......789 (61) r1 = *(u32 *)(r10 -8)\n     65: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     66: .......789 (bf) r2 = r10\n     67: ..2....789 (07) r2 += -112\n     68: ..2....789 (18) r1 = 0xffff8d2a0c137000\n     70: .12....789 (85) call bpf_map_lookup_elem#1\n     71: 0......789 (bf) r6 = r0\n     72: ......6789 (15) if r6 == 0x0 goto pc+3\n     73: ......6789 (05) goto pc+0\n     74: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     75: .1....6789 (55) if r1 != 0x0 goto pc+54\n     76: .......789 (b7) r1 = 2816\n     77: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     78: .1.3...789 (0f) r3 += r1\n     79: ...3...789 (bf) r1 = r10\n     80: .1.3...789 (07) r1 += -96\n     81: .1.3...789 (b7) r2 = 8\n     82: .123...789 (85) call bpf_probe_read_kernel#113\n     83: .......789 (79) r3 = *(u64 *)(r10 -96)\n     84: ...3...789 (15) if r3 == 0x0 goto pc+108\n     85: ...3...789 (b7) r1 = 2804\n     86: .1.3...789 (0f) r3 += r1\n     87: ...3...789 (bf) r1 = r10\n     88: .1.3...789 (07) r1 += -8\n     89: .1.3...789 (b7) r2 = 4\n     90: .123...789 (85) call bpf_probe_read_kernel#113\n     91: .......789 (61) r1 = *(u32 *)(r10 -8)\n     92: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     93: .......789 (bf) r2 = r10\n     94: ..2....789 (07) r2 += -112\n     95: ..2....789 (18) r1 = 0xffff8d2a0c137000\n     97: .12....789 (85) call bpf_map_lookup_elem#1\n     98: 0......789 (bf) r6 = r0\n\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 177
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 179 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @844\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 0\n      2: ......67.. (63) *(u32 *)(r10 -88) = r7\n      3: ......67.. (bf) r2 = r10\n      4: ..2...67.. (07) r2 += -88\n      5: ..2...67.. (18) r1 = 0xffff8d25412c2600\n      7: .12...67.. (85) call bpf_map_lookup_elem#1\n      8: 0.....67.. (15) if r0 == 0x0 goto pc+821\n      9: 0.....67.. (7b) *(u64 *)(r10 -120) = r6\n     10: 0......7.. (bf) r8 = r0\n     11: 0......78. (bf) r6 = r0\n     12: ......678. (85) call bpf_get_current_task#35\n     13: 0.....678. (b7) r1 = 2680\n     14: 01....678. (0f) r0 += r1\n     15: 0.....678. (bf) r1 = r10\n     16: 01....678. (07) r1 += -72\n     17: 01....678. (b7) r2 = 8\n     18: 012...678. (bf) r3 = r0\n     19: .123..678. (85) call bpf_probe_read#4\n     20: ......678. (b7) r1 = 1448\n     21: .1....678. (79) r3 = *(u64 *)(r10 -72)\n     22: .1.3..678. (0f) r3 += r1\n     23: ...3..678. (bf) r1 = r10\n     24: .1.3..678. (07) r1 += -64\n     25: .1.3..678. (b7) r2 = 8\n     26: .123..678. (85) call bpf_probe_read#4\n     27: ......678. (79) r9 = *(u64 *)(r10 -64)\n     28: ......6789 (63) *(u32 *)(r10 -84) = r7\n     29: ......6.89 (bf) r2 = r10\n     30: ..2...6.89 (07) r2 += -84\n     31: ..2...6.89 (18) r1 = 0xffff8d2482249200\n     33: .12...6.89 (85) call bpf_map_lookup_elem#1\n     34: 0.....6.89 (7b) *(u64 *)(r10 -104) = r6\n     35: 0.....6.89 (07) r6 += 5808\n     36: 0.....6.89 (7b) *(u64 *)(r10 -112) = r6\n     37: 0.......89 (bf) r2 = r8\n     38: 0.2.....89 (7b) *(u64 *)(r10 -96) = r8\n     39: 0.2......9 (bf) r8 = r0\n     40: ..2.....89 (55) if r8 != 0x0 goto pc+1\n     41: .......... (05) goto pc+254\n     42: ..2.....89 (b7) r1 = 64\n     43: .12.....89 (0f) r9 += r1\n     44: ..2.....89 (b7) r1 = 4096\n     45: .12.....89 (63) *(u32 *)(r2 +6192) = r1\n     46: ........89 (85) call bpf_get_current_task#35\n     47: 0.......89 (b7) r1 = 3408\n     48: 01......89 (0f) r0 += r1\n     49: 0.......89 (bf) r1 = r10\n     50: 01......89 (07) r1 += -80\n     51: 01......89 (b7) r2 = 8\n     52: 012.....89 (bf) r3 = r0\n     53: .123....89 (85) call bpf_probe_read#4\n     54: ........89 (b7) r1 = 8\n     55: .1......89 (7b) *(u64 *)(r10 -128) = r9\n     56: .1......89 (0f) r9 += r1\n     57: ........89 (79) r7 = *(u64 *)(r10 -80)\n     58: .......789 (bf) r1 = r10\n     59: .1.....789 (07) r1 += -72\n     60: .1.....789 (b7) r2 = 8\n     61: .12....789 (7b) *(u64 *)(r10 -136) = r9\n     62: .12....789 (bf) r3 = r9\n     63: .123...78. (85) call bpf_probe_read#4\n     64: .......78. (b7) r1 = 8\n     65: .1.....78. (79) r6 = *(u64 *)(r10 -72)\n     66: .1....678. (bf) r3 = r6\n     67: .1.3..678. (0f) r3 += r1\n     68: ...3..678. (b7) r1 = 8\n     69: .1.3..678. (0f) r3 += r1\n     70: ...3..678. (bf) r1 = r10\n     71: .1.3..678. (07) r1 += -64\n     72: .1.3..678. (b7) r2 = 8\n     73: .123..678. (85) call bpf_probe_read#4\n     74: ......678. (79) r3 = *(u64 *)(r10 -96)\n     75: ...3..678. (bf) r9 = r8\n     76: ...3..6789 (07) r9 += 4096\n     77: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     78: .1.3..6789 (55) if r1 != 0x0 goto pc+41\n     79: ......6789 (b7) r1 = 24\n     80: .1....6789 (bf) r3 = r6\n     81: .1.3..6789 (0f) r3 += r1\n     82: ...3..6789 (bf) r1 = r10\n     83: .1.3..6789 (07) r1 += -64\n     84: .1.3..6789 (b7) r2 = 8\n     85: .123..6789 (85) call bpf_probe_read#4\n     86: ......6789 (79) r3 = *(u64 *)(r10 -96)\n     87: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     88: .1.3..6789 (1d) if r1 == r6 goto pc+31\n     89: ...3...789 (61) r1 = *(u32 *)(r3 +6192)\n     90: .1.3...789 (bf) r2 = r1\n     91: .123...789 (07) r2 += -10\n     92: .123...789 (63) *(u32 *)(r3 +6192) = r2\n     93: .123...789 (67) r1 <<= 32\n     94: .123...789 (c7) r1 s>>= 32\n     95: .123...789 (65) if r1 s> 0x9 goto pc+5\n     96: ..23.....9 (18) r1 = 0xffffffdc\n     98: .123.....9 (63) *(u32 *)(r3 +6196) = r1\n     99: ..2......9 (bf) r7 = r9\n    100: ..2....7.. (05) goto pc+93\n    101: ...3...78. (b7) r1 = 41\n    102: .1.3...78. (73) *(u8 *)(r8 +4095) = r1\n    103: ...3...78. (b7) r1 = 116\n    104: .1.3...78. (73) *(u8 *)(r8 +4092) = r1\n    105: ...3\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 179
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 190 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 190
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 196 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 196
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 200 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 200
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 203 pass cond_select failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nfunc#1 @3102\nfunc#2 @3218\nfunc#3 @3409\nfunc#4 @3445\nfunc#5 @3514\nLive regs before insn:\n      0: .1........ (bf) r9 = r1\n      1: .........9 (b7) r1 = 0\n      2: .1.......9 (63) *(u32 *)(r10 -172) = r1\n      3: .........9 (bf) r2 = r10\n      4: ..2......9 (07) r2 += -172\n      5: ..2......9 (18) r1 = 0xffff8d2552457200\n      7: .12......9 (85) call bpf_map_lookup_elem#1\n      8: 0........9 (bf) r7 = r0\n      9: .......7.9 (15) if r7 == 0x0 goto pc+489\n     10: .......7.9 (61) r8 = *(u32 *)(r7 +24292)\n     11: .......789 (67) r8 <<= 32\n     12: .......789 (c7) r8 s>>= 32\n     13: .......789 (61) r1 = *(u32 *)(r7 +4)\n     14: .1.....789 (bf) r6 = r1\n     15: .1....6789 (25) if r1 > 0x2327 goto pc+433\n     16: .1.....789 (7b) *(u64 *)(r10 -184) = r1\n     17: .......789 (b7) r1 = 0\n     18: .1.....789 (63) *(u32 *)(r10 -156) = r1\n     19: .......789 (bf) r2 = r10\n     20: ..2....789 (07) r2 += -156\n     21: ..2....789 (18) r1 = 0xffff8d2552457200\n     23: .12....789 (85) call bpf_map_lookup_elem#1\n     24: 0......789 (bf) r6 = r0\n     25: ......6789 (15) if r6 == 0x0 goto pc+59\n     26: ......6789 (bf) r2 = r6\n     27: ..2...6789 (07) r2 += 24288\n     28: ..2...6789 (18) r1 = 0xffff8d2a0c136400\n     30: .12...6789 (85) call bpf_map_lookup_elem#1\n     31: 0.....6789 (15) if r0 == 0x0 goto pc+53\n     32: 0.....6789 (7b) *(u64 *)(r10 -208) = r6\n     33: 0......789 (7b) *(u64 *)(r10 -200) = r7\n     34: 0.......89 (bf) r7 = r8\n     35: 0......789 (57) r7 &= 7\n     36: 0......789 (67) r7 <<= 32\n     37: 0......789 (c7) r7 s>>= 32\n     38: 0......789 (bf) r1 = r7\n     39: 01.....789 (67) r1 <<= 2\n     40: 01.....789 (bf) r2 = r0\n     41: 012....789 (0f) r2 += r1\n     42: 0.2....789 (71) r3 = *(u8 *)(r2 +65)\n     43: 0.23...789 (67) r3 <<= 8\n     44: 0.23...789 (71) r1 = *(u8 *)(r2 +64)\n     45: 0123...789 (4f) r3 |= r1\n     46: 0.23...789 (71) r4 = *(u8 *)(r2 +66)\n     47: 0.234..789 (67) r4 <<= 16\n     48: 0.234..789 (71) r1 = *(u8 *)(r2 +67)\n     49: 01234..789 (67) r1 <<= 24\n     50: 01234..789 (4f) r1 |= r4\n     51: 0123...789 (4f) r1 |= r3\n     52: 012....789 (71) r3 = *(u8 *)(r2 +5)\n     53: 0123...789 (67) r3 <<= 8\n     54: 0123...789 (71) r4 = *(u8 *)(r2 +4)\n     55: 01234..789 (4f) r3 |= r4\n     56: 0123...789 (71) r4 = *(u8 *)(r2 +6)\n     57: 01234..789 (67) r4 <<= 16\n     58: 01234..789 (71) r6 = *(u8 *)(r2 +7)\n     59: 01234.6789 (67) r6 <<= 24\n     60: 01234.6789 (4f) r6 |= r4\n     61: 0123..6789 (4f) r6 |= r3\n     62: 012...6789 (71) r5 = *(u8 *)(r2 +27)\n     63: 012..56789 (71) r3 = *(u8 *)(r2 +26)\n     64: 0123.56789 (71) r4 = *(u8 *)(r2 +24)\n     65: 0123456789 (71) r2 = *(u8 *)(r2 +25)\n     66: 0123456789 (57) r1 &= 7\n     67: 0123456789 (67) r2 <<= 8\n     68: 0123456789 (4f) r2 |= r4\n     69: 0123.56789 (67) r3 <<= 16\n     70: 0123.56789 (67) r5 <<= 24\n     71: 0123.56789 (4f) r5 |= r3\n     72: 012..56789 (4f) r5 |= r2\n     73: 01...56789 (7b) *(u64 *)(r10 -216) = r5\n     74: 01...56789 (bf) r2 = r5\n     75: 012...6789 (57) r2 &= 64\n     76: 012...6789 (7b) *(u64 *)(r10 -192) = r8\n     77: 012...67.9 (15) if r2 == 0x0 goto pc+9\n     78: 0.....67.9 (bf) r8 = r9\n     79: 0.....678. (bf) r9 = r0\n     80: ......6789 (85) call bpf_get_current_task#35\n     81: 0.....6789 (bf) r1 = r0\n     82: .1....6789 (bf) r0 = r9\n     83: 01....678. (bf) r9 = r8\n     84: 01....67.9 (05) goto pc+8\n     85: .......789 (79) r6 = *(u64 *)(r10 -184)\n     86: ......6789 (05) goto pc+362\n     87: 01....67.9 (67) r1 <<= 32\n     88: 01....67.9 (c7) r1 s>>= 32\n     89: 01....67.9 (67) r1 <<= 3\n     90: 01....67.9 (79) r2 = *(u64 *)(r10 -208)\n     91: 012...67.9 (0f) r2 += r1\n     92: 0.2...67.9 (79) r1 = *(u64 *)(r2 +24144)\n     93: 01....67.9 (7b) *(u64 *)(r10 -168) = r1\n     94: 0.....67.9 (79) r4 = *(u64 *)(r10 -184)\n     95: 0...4.67.9 (65) if r7 s> 0x4 goto pc+24\n     96: 0...4.67.9 (bf) r1 = r7\n     97: 01..4.67.9 (57) r1 &= 7\n     98: 01..4.67.9 (67) r1 <<= 32\n     99: 01..4.67.9 (c7) r1 s>>= 32\n    100: 01..4.67.9 (27) r1 *= 80\n    101: 01..4.67.9 (0f) r0 += r1\n    102: 0...4.67.9 (71) r1 = *(u8 *)(r0 +119)\n    103: 01..4.67\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 203
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 205 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r1 = 0\n      2: .1....6... (63) *(u32 *)(r10 -116) = r1\n      3: ......6... (bf) r2 = r10\n      4: ..2...6... (07) r2 += -116\n      5: ..2...6... (18) r1 = 0xffff8d272840dc00\n      7: .12...6... (85) call bpf_map_lookup_elem#1\n      8: 0.....6... (bf) r7 = r0\n      9: ......67.. (15) if r7 == 0x0 goto pc+368\n     10: ......67.. (7b) *(u64 *)(r10 -128) = r6\n     11: .......7.. (79) r1 = *(u64 *)(r7 +24272)\n     12: .1.....7.. (15) if r1 == 0x0 goto pc+203\n     13: .......7.. (85) call bpf_get_current_pid_tgid#14\n     14: 0......7.. (bf) r6 = r0\n     15: ......67.. (85) call bpf_get_current_task#35\n     16: 0.....67.. (bf) r9 = r0\n     17: ......67.9 (77) r6 >>= 32\n     18: ......67.9 (63) *(u32 *)(r10 -80) = r6\n     19: .......7.9 (bf) r2 = r10\n     20: ..2....7.9 (07) r2 += -80\n     21: ..2....7.9 (18) r1 = 0xffff8d2a0c137000\n     23: .12....7.9 (85) call bpf_map_lookup_elem#1\n     24: 0......7.9 (bf) r8 = r0\n     25: .......789 (15) if r8 == 0x0 goto pc+190\n     26: .......789 (b7) r1 = 3440\n     27: .1.....789 (bf) r3 = r9\n     28: .1.3...789 (0f) r3 += r1\n     29: ...3...789 (bf) r1 = r10\n     30: .1.3...789 (07) r1 += -8\n     31: .1.3...789 (b7) r2 = 8\n     32: .123...789 (85) call bpf_probe_read#4\n     33: .......789 (79) r3 = *(u64 *)(r10 -8)\n     34: ...3...789 (bf) r6 = r10\n     35: ...3..6789 (07) r6 += -80\n     36: ...3..6789 (bf) r1 = r6\n     37: .1.3..6789 (b7) r2 = 72\n     38: .123..6789 (85) call bpf_probe_read#4\n     39: ...3456789 (bf) r1 = r8\n     40: .1.3456789 (07) r1 += 40\n     41: .1.3456789 (b7) r2 = 1\n     42: .123456789 (15) if r2 == 0x0 goto pc+2\n     43: .1....6789 (b7) r2 = 536\n     44: .12...6789 (05) goto pc+1\n     45: .123456789 (85) call unknown#195896080\n     46: .12...6789 (79) r3 = *(u64 *)(r6 +8)\n     47: .123...789 (0f) r3 += r2\n     48: .1.3...789 (b7) r2 = 4\n     49: .123...789 (85) call bpf_probe_read#4\n     50: ..2.45.789 (b7) r1 = 1\n     51: .12.45.789 (15) if r1 == 0x0 goto pc+5\n     52: .......789 (bf) r1 = r10\n     53: .1.....789 (07) r1 += -80\n     54: .1.....789 (79) r3 = *(u64 *)(r1 +16)\n     55: ...3...789 (b7) r1 = 1240\n     56: .1.3...789 (05) goto pc+4\n     57: ..2.45.789 (bf) r1 = r10\n     58: .12.45.789 (07) r1 += -80\n     59: .12.45.789 (79) r3 = *(u64 *)(r1 +16)\n     60: .12345.789 (85) call unknown#195896080\n     61: .1.3...789 (0f) r3 += r1\n     62: ...3...789 (bf) r1 = r8\n     63: .1.3...789 (07) r1 += 44\n     64: .1.3...789 (b7) r2 = 4\n     65: .123...789 (85) call bpf_probe_read#4\n     66: ..2.45.789 (b7) r1 = 1\n     67: .12.45.789 (15) if r1 == 0x0 goto pc+8\n     68: .......789 (bf) r1 = r10\n     69: .1.....789 (07) r1 += -80\n     70: .1.....789 (79) r3 = *(u64 *)(r1 +24)\n     71: ...3...789 (b7) r1 = 88\n     72: .1.3...789 (0f) r3 += r1\n     73: ...3...789 (bf) r1 = r8\n     74: .1.3...789 (07) r1 += 48\n     75: .1.3...789 (05) goto pc+7\n     76: ..2.45.789 (bf) r1 = r10\n     77: .12.45.789 (07) r1 += -80\n     78: .12.45.789 (79) r3 = *(u64 *)(r1 +24)\n     79: .12345.789 (85) call unknown#195896080\n     80: .1.3...789 (0f) r3 += r1\n     81: ...3...789 (bf) r1 = r8\n     82: .1.3...789 (07) r1 += 44\n     83: .1.3...789 (b7) r2 = 4\n     84: .123...789 (85) call bpf_probe_read#4\n     85: ....45.789 (b7) r1 = 1\n     86: .1..45.789 (15) if r1 == 0x0 goto pc+40\n     87: .......789 (b7) r6 = 0\n     88: ......6789 (7b) *(u64 *)(r10 -88) = r6\n     89: ......6789 (b7) r1 = 2904\n     90: .1....6789 (bf) r3 = r9\n     91: .1.3..6789 (0f) r3 += r1\n     92: ...3..6789 (bf) r1 = r10\n     93: .1.3..6789 (07) r1 += -88\n     94: .1.3..6789 (b7) r2 = 8\n     95: .123..6789 (85) call bpf_probe_read#4\n     96: ....456789 (79) r3 = *(u64 *)(r10 -88)\n     97: ...3456789 (15) if r3 == 0x0 goto pc+28\n     98: ...3..6789 (63) *(u32 *)(r10 -92) = r6\n     99: ...3...789 (b7) r1 = 4\n    100: .1.3...789 (0f) r3 += r1\n    101: ...3...789 (bf) r1 = r10\n    102: .1.3...789 (07) r1 += -92\n    103: .1.3...789 (b7) r2 = 4\n    104: .123...789 (85) call bpf_probe_read#4\n    105: .......789 (b7) r1 = 128\n    106:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 205
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 208 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 208
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 214 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 214
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 219 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 219
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 225 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 225
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 231 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 231
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 237 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 237
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 244 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 244
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 249 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 249
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 259 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 259
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 262 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 262
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 274 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 274
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 281 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 281
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 288 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 288
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 290 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 290
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 300 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 300
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 301 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 301
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 306 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 306
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 312 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 312
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 318 pass extract failed after 2 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nfunc#1 @3102\nfunc#2 @3218\nfunc#3 @3409\nfunc#4 @3445\nfunc#5 @3514\nLive regs before insn:\n      0: .1........ (bf) r9 = r1\n      1: .........9 (b7) r1 = 0\n      2: .1.......9 (63) *(u32 *)(r10 -172) = r1\n      3: .........9 (bf) r2 = r10\n      4: ..2......9 (07) r2 += -172\n      5: ..2......9 (18) r1 = 0xffff8d2486043600\n      7: .12......9 (85) call bpf_map_lookup_elem#1\n      8: 0........9 (bf) r7 = r0\n      9: .......7.9 (15) if r7 == 0x0 goto pc+489\n     10: .......7.9 (61) r8 = *(u32 *)(r7 +24292)\n     11: .......789 (67) r8 <<= 32\n     12: .......789 (c7) r8 s>>= 32\n     13: .......789 (61) r1 = *(u32 *)(r7 +4)\n     14: .1.....789 (bf) r6 = r1\n     15: .1....6789 (25) if r1 > 0x2327 goto pc+433\n     16: .1.....789 (7b) *(u64 *)(r10 -184) = r1\n     17: .......789 (b7) r1 = 0\n     18: .1.....789 (63) *(u32 *)(r10 -156) = r1\n     19: .......789 (bf) r2 = r10\n     20: ..2....789 (07) r2 += -156\n     21: ..2....789 (18) r1 = 0xffff8d2486043600\n     23: .12....789 (85) call bpf_map_lookup_elem#1\n     24: 0......789 (bf) r6 = r0\n     25: ......6789 (15) if r6 == 0x0 goto pc+59\n     26: ......6789 (bf) r2 = r6\n     27: ..2...6789 (07) r2 += 24288\n     28: ..2...6789 (18) r1 = 0xffff8d28e3415000\n     30: .12...6789 (85) call bpf_map_lookup_elem#1\n     31: 0.....6789 (15) if r0 == 0x0 goto pc+53\n     32: 0.....6789 (7b) *(u64 *)(r10 -208) = r6\n     33: 0......789 (7b) *(u64 *)(r10 -200) = r7\n     34: 0.......89 (bf) r7 = r8\n     35: 0......789 (57) r7 &= 7\n     36: 0......789 (67) r7 <<= 32\n     37: 0......789 (c7) r7 s>>= 32\n     38: 0......789 (bf) r1 = r7\n     39: 01.....789 (67) r1 <<= 2\n     40: 01.....789 (bf) r2 = r0\n     41: 012....789 (0f) r2 += r1\n     42: 0.2....789 (71) r3 = *(u8 *)(r2 +65)\n     43: 0.23...789 (67) r3 <<= 8\n     44: 0.23...789 (71) r1 = *(u8 *)(r2 +64)\n     45: 0123...789 (4f) r3 |= r1\n     46: 0.23...789 (71) r4 = *(u8 *)(r2 +66)\n     47: 0.234..789 (67) r4 <<= 16\n     48: 0.234..789 (71) r1 = *(u8 *)(r2 +67)\n     49: 01234..789 (67) r1 <<= 24\n     50: 01234..789 (4f) r1 |= r4\n     51: 0123...789 (4f) r1 |= r3\n     52: 012....789 (71) r3 = *(u8 *)(r2 +5)\n     53: 0123...789 (67) r3 <<= 8\n     54: 0123...789 (71) r4 = *(u8 *)(r2 +4)\n     55: 01234..789 (4f) r3 |= r4\n     56: 0123...789 (71) r4 = *(u8 *)(r2 +6)\n     57: 01234..789 (67) r4 <<= 16\n     58: 01234..789 (71) r6 = *(u8 *)(r2 +7)\n     59: 01234.6789 (67) r6 <<= 24\n     60: 01234.6789 (4f) r6 |= r4\n     61: 0123..6789 (4f) r6 |= r3\n     62: 012...6789 (71) r5 = *(u8 *)(r2 +27)\n     63: 012..56789 (71) r3 = *(u8 *)(r2 +26)\n     64: 0123.56789 (71) r4 = *(u8 *)(r2 +24)\n     65: 0123456789 (71) r2 = *(u8 *)(r2 +25)\n     66: 0123456789 (57) r1 &= 7\n     67: 0123456789 (67) r2 <<= 8\n     68: 0123456789 (4f) r2 |= r4\n     69: 0123.56789 (67) r3 <<= 16\n     70: 0123.56789 (67) r5 <<= 24\n     71: 0123.56789 (4f) r5 |= r3\n     72: 012..56789 (4f) r5 |= r2\n     73: 01...56789 (7b) *(u64 *)(r10 -216) = r5\n     74: 01...56789 (bf) r2 = r5\n     75: 012...6789 (57) r2 &= 64\n     76: 012...6789 (7b) *(u64 *)(r10 -192) = r8\n     77: 012...67.9 (15) if r2 == 0x0 goto pc+9\n     78: 0.....67.9 (bf) r8 = r9\n     79: 0.....678. (bf) r9 = r0\n     80: ......6789 (85) call bpf_get_current_task#35\n     81: 0.....6789 (bf) r1 = r0\n     82: .1....6789 (bf) r0 = r9\n     83: 01....678. (bf) r9 = r8\n     84: 01....67.9 (05) goto pc+8\n     85: .......789 (79) r6 = *(u64 *)(r10 -184)\n     86: ......6789 (05) goto pc+362\n     87: 01....67.9 (67) r1 <<= 32\n     88: 01....67.9 (c7) r1 s>>= 32\n     89: 01....67.9 (67) r1 <<= 3\n     90: 01....67.9 (79) r2 = *(u64 *)(r10 -208)\n     91: 012...67.9 (0f) r2 += r1\n     92: 0.2...67.9 (79) r1 = *(u64 *)(r2 +24144)\n     93: 01....67.9 (7b) *(u64 *)(r10 -168) = r1\n     94: 0.....67.9 (79) r4 = *(u64 *)(r10 -184)\n     95: 0...4.67.9 (65) if r7 s> 0x4 goto pc+24\n     96: 0...4.67.9 (bf) r1 = r7\n     97: 01..4.67.9 (57) r1 &= 7\n     98: 01..4.67.9 (67) r1 <<= 32\n     99: 01..4.67.9 (c7) r1 s>>= 32\n    100: 01..4.67.9 (27) r1 *= 80\n    101: 01..4.67.9 (0f) r0 += r1\n    102: 0...4.67.9 (71) r1 = *(u8 *)(r0 +119)\n    103: 01..4.67\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 318
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 320 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 320
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 325 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 325
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 328 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 328
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 336 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 336
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 339 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 339
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 345 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 345
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 355 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 355
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 362 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 362
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 368 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 368
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 372 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 372
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 380 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 380
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 388 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 388
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 395 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 395
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 400 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 400
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 410 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 410
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 414 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 414
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 423 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 423
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 430 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 430
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 432 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 432
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 442 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 442
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 448 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 448
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 453 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 453
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 458 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 458
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 238,
          "not_applied": 49,
          "requested": 287
        }
      },
      "runner": "tetragon",
      "selected_workload": "stress_ng_os_io_network",
      "status": "ok"
    },
    {
      "app": "katran",
      "baseline": {
        "bpf": {
          "470": {
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 470,
            "name": "xdp_root",
            "run_cnt_delta": 99438,
            "run_time_ns_delta": 36393401,
            "type": "xdp"
          },
          "476": {
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 476,
            "name": "balancer_ingress",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "478": {
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 478,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 3.000862737000034,
            "ops_per_sec": 5522.745107817909,
            "ops_total": 16573.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "470": {
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 470,
            "name": "xdp_root",
            "run_cnt_delta": 97032,
            "run_time_ns_delta": 36400661,
            "type": "xdp"
          },
          "476": {
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 476,
            "name": "balancer_ingress",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "478": {
            "bytes_jited": 544,
            "bytes_xlated": 1016,
            "id": 478,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0012969900003554,
            "ops_per_sec": 5388.337126875966,
            "ops_total": 16172.0,
            "stderr": "",
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
          "prefetch",
          "map_inline"
        ],
        "error": "prog 476: prog 476 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @2406\nfunc#2 @2554\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 1\n      2: ......67.. (61) r8 = *(u32 *)(r6 +0)\n      3: ......678. (61) r9 = *(u32 *)(r6 +4)\n      4: ......6789 (bf) r1 = r8\n      5: .1....6789 (07) r1 += 14\n      6: .1....6789 (2d) if r1 > r9 goto pc+1581\n      7: ......6789 (b7) r1 = 528\n      8: .1....6789 (63) *(u32 *)(r10 -132) = r1\n      9: ......6789 (bf) r2 = r10\n     10: ..2...6789 (07) r2 += -132\n     11: ..2...6789 (18) r1 = 0xffff8d27a7d98000\n     13: .12...6789 (85) call bpf_map_lookup_elem#1\n     14: 0.....6789 (15) if r0 == 0x0 goto pc+1573\n     15: 0.....6.89 (05) goto pc+0\n     16: 0.....6.89 (05) goto pc+0\n     17: 0.....6.89 (1f) r9 -= r8\n     18: 0.....6.89 (79) r1 = *(u64 *)(r0 +8)\n     19: 01....6.89 (0f) r1 += r9\n     20: 01....6.89 (7b) *(u64 *)(r0 +8) = r1\n     21: 0.....6.89 (79) r1 = *(u64 *)(r0 +0)\n     22: 01....6.89 (07) r1 += 1\n     23: 01....6.89 (7b) *(u64 *)(r0 +0) = r1\n     24: ......6.89 (71) r2 = *(u8 *)(r8 +12)\n     25: ..2...6.89 (71) r1 = *(u8 *)(r8 +13)\n     26: .12...6..9 (67) r1 <<= 8\n     27: .12...6..9 (4f) r1 |= r2\n     28: .1....6..9 (b7) r8 = 1\n     29: .1....6.89 (15) if r1 == 0xdd86 goto pc+129\n     30: .1....6.89 (55) if r1 != 0x8 goto pc+1530\n     31: ......6.89 (61) r2 = *(u32 *)(r6 +4)\n     32: ..2...6.89 (61) r7 = *(u32 *)(r6 +0)\n     33: ..2...6789 (b7) r1 = 0\n     34: .12...6789 (7b) *(u64 *)(r10 -48) = r1\n     35: .12...6789 (7b) *(u64 *)(r10 -56) = r1\n     36: .12...6789 (7b) *(u64 *)(r10 -64) = r1\n     37: .12...6789 (7b) *(u64 *)(r10 -72) = r1\n     38: .12...6789 (7b) *(u64 *)(r10 -80) = r1\n     39: .12...6789 (7b) *(u64 *)(r10 -88) = r1\n     40: .12...6789 (63) *(u32 *)(r10 -96) = r1\n     41: .12...6789 (7b) *(u64 *)(r10 -104) = r1\n     42: .12...6789 (7b) *(u64 *)(r10 -112) = r1\n     43: .12...6789 (63) *(u32 *)(r10 -120) = r1\n     44: ..2...6789 (bf) r3 = r7\n     45: ..23..6789 (07) r3 += 34\n     46: ..23..6789 (7b) *(u64 *)(r10 -144) = r2\n     47: ..23..6789 (2d) if r3 > r2 goto pc+1510\n     48: ...3..6789 (05) goto pc+0\n     49: ...3..6789 (71) r1 = *(u8 *)(r7 +14)\n     50: .1.3..6789 (57) r1 &= 15\n     51: .1.3..6789 (55) if r1 != 0x5 goto pc+1506\n     52: ...3..6789 (05) goto pc+0\n     53: ...3..6789 (71) r1 = *(u8 *)(r7 +15)\n     54: .1.3..6789 (73) *(u8 *)(r10 -43) = r1\n     55: ...3..6789 (71) r1 = *(u8 *)(r7 +23)\n     56: .1.3..6789 (73) *(u8 *)(r10 -52) = r1\n     57: .1.3..6789 (69) r2 = *(u16 *)(r7 +20)\n     58: .123..6789 (bf) r4 = r2\n     59: .1234.6789 (57) r4 &= 65343\n     60: .1234.6789 (55) if r4 != 0x0 goto pc+1497\n     61: .123..6789 (05) goto pc+0\n     62: .123..6789 (69) r0 = *(u16 *)(r7 +16)\n     63: 0123..6789 (15) if r1 == 0x1 goto pc+259\n     64: 01.3..6789 (05) goto pc+0\n     65: 01.3..6789 (61) r2 = *(u32 *)(r7 +26)\n     66: 0123..6789 (63) *(u32 *)(r10 -88) = r2\n     67: 01.3..6789 (61) r2 = *(u32 *)(r7 +30)\n     68: 0123..6789 (63) *(u32 *)(r10 -72) = r2\n     69: 01.3..6789 (b7) r2 = 0\n     70: 0123..6789 (55) if r1 != 0x3a goto pc+640\n     71: 0..3..6789 (bf) r1 = r7\n     72: 01.3..6789 (07) r1 += 42\n     73: 01.3..6789 (79) r2 = *(u64 *)(r10 -144)\n     74: 0123..6789 (2d) if r1 > r2 goto pc+1483\n     75: 0..3..67.9 (05) goto pc+0\n     76: 0..3..67.9 (71) r1 = *(u8 *)(r3 +0)\n     77: 01....67.9 (15) if r1 == 0x1 goto pc+603\n     78: 01....67.9 (15) if r1 == 0x2 goto pc+582\n     79: .1.....7.9 (b7) r8 = 2\n     80: .1.....789 (55) if r1 != 0x80 goto pc+1477\n     81: .......7.9 (b7) r8 = 1\n     82: .......789 (bf) r1 = r7\n     83: .1.....789 (07) r1 += 62\n     84: .1.....789 (79) r2 = *(u64 *)(r10 -144)\n     85: .12....789 (2d) if r1 > r2 goto pc+1472\n     86: .......7.9 (b7) r1 = 129\n     87: .1.....7.9 (73) *(u8 *)(r7 +54) = r1\n     88: .......7.9 (b7) r1 = 64\n     89: .1.....7.9 (73) *(u8 *)(r7 +21) = r1\n     90: .......7.9 (69) r1 = *(u16 *)(r7 +56)\n     91: .1.....7.9 (07) r1 += -1\n     92: .1.....7.9 (6b) *(u16 *)(r7 +56) = r1\n     93: .......7.9 (61) r1 = *(u32 *)(r7 +34)\n     94: .1.....7.9 (67) r1 <<= 32\n     95: .1.....7.9 (61) r2 = *(u32 *)(r7 +30)\n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 476 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @2406\nfunc#2 @2554\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 1\n      2: ......67.. (61) r8 = *(u32 *)(r6 +0)\n      3: ......678. (61) r9 = *(u32 *)(r6 +4)\n      4: ......6789 (bf) r1 = r8\n      5: .1....6789 (07) r1 += 14\n      6: .1....6789 (2d) if r1 > r9 goto pc+1581\n      7: ......6789 (b7) r1 = 528\n      8: .1....6789 (63) *(u32 *)(r10 -132) = r1\n      9: ......6789 (bf) r2 = r10\n     10: ..2...6789 (07) r2 += -132\n     11: ..2...6789 (18) r1 = 0xffff8d27a7d98000\n     13: .12...6789 (85) call bpf_map_lookup_elem#1\n     14: 0.....6789 (15) if r0 == 0x0 goto pc+1573\n     15: 0.....6.89 (05) goto pc+0\n     16: 0.....6.89 (05) goto pc+0\n     17: 0.....6.89 (1f) r9 -= r8\n     18: 0.....6.89 (79) r1 = *(u64 *)(r0 +8)\n     19: 01....6.89 (0f) r1 += r9\n     20: 01....6.89 (7b) *(u64 *)(r0 +8) = r1\n     21: 0.....6.89 (79) r1 = *(u64 *)(r0 +0)\n     22: 01....6.89 (07) r1 += 1\n     23: 01....6.89 (7b) *(u64 *)(r0 +0) = r1\n     24: ......6.89 (71) r2 = *(u8 *)(r8 +12)\n     25: ..2...6.89 (71) r1 = *(u8 *)(r8 +13)\n     26: .12...6..9 (67) r1 <<= 8\n     27: .12...6..9 (4f) r1 |= r2\n     28: .1....6..9 (b7) r8 = 1\n     29: .1....6.89 (15) if r1 == 0xdd86 goto pc+129\n     30: .1....6.89 (55) if r1 != 0x8 goto pc+1530\n     31: ......6.89 (61) r2 = *(u32 *)(r6 +4)\n     32: ..2...6.89 (61) r7 = *(u32 *)(r6 +0)\n     33: ..2...6789 (b7) r1 = 0\n     34: .12...6789 (7b) *(u64 *)(r10 -48) = r1\n     35: .12...6789 (7b) *(u64 *)(r10 -56) = r1\n     36: .12...6789 (7b) *(u64 *)(r10 -64) = r1\n     37: .12...6789 (7b) *(u64 *)(r10 -72) = r1\n     38: .12...6789 (7b) *(u64 *)(r10 -80) = r1\n     39: .12...6789 (7b) *(u64 *)(r10 -88) = r1\n     40: .12...6789 (63) *(u32 *)(r10 -96) = r1\n     41: .12...6789 (7b) *(u64 *)(r10 -104) = r1\n     42: .12...6789 (7b) *(u64 *)(r10 -112) = r1\n     43: .12...6789 (63) *(u32 *)(r10 -120) = r1\n     44: ..2...6789 (bf) r3 = r7\n     45: ..23..6789 (07) r3 += 34\n     46: ..23..6789 (7b) *(u64 *)(r10 -144) = r2\n     47: ..23..6789 (2d) if r3 > r2 goto pc+1510\n     48: ...3..6789 (05) goto pc+0\n     49: ...3..6789 (71) r1 = *(u8 *)(r7 +14)\n     50: .1.3..6789 (57) r1 &= 15\n     51: .1.3..6789 (55) if r1 != 0x5 goto pc+1506\n     52: ...3..6789 (05) goto pc+0\n     53: ...3..6789 (71) r1 = *(u8 *)(r7 +15)\n     54: .1.3..6789 (73) *(u8 *)(r10 -43) = r1\n     55: ...3..6789 (71) r1 = *(u8 *)(r7 +23)\n     56: .1.3..6789 (73) *(u8 *)(r10 -52) = r1\n     57: .1.3..6789 (69) r2 = *(u16 *)(r7 +20)\n     58: .123..6789 (bf) r4 = r2\n     59: .1234.6789 (57) r4 &= 65343\n     60: .1234.6789 (55) if r4 != 0x0 goto pc+1497\n     61: .123..6789 (05) goto pc+0\n     62: .123..6789 (69) r0 = *(u16 *)(r7 +16)\n     63: 0123..6789 (15) if r1 == 0x1 goto pc+259\n     64: 01.3..6789 (05) goto pc+0\n     65: 01.3..6789 (61) r2 = *(u32 *)(r7 +26)\n     66: 0123..6789 (63) *(u32 *)(r10 -88) = r2\n     67: 01.3..6789 (61) r2 = *(u32 *)(r7 +30)\n     68: 0123..6789 (63) *(u32 *)(r10 -72) = r2\n     69: 01.3..6789 (b7) r2 = 0\n     70: 0123..6789 (55) if r1 != 0x3a goto pc+640\n     71: 0..3..6789 (bf) r1 = r7\n     72: 01.3..6789 (07) r1 += 42\n     73: 01.3..6789 (79) r2 = *(u64 *)(r10 -144)\n     74: 0123..6789 (2d) if r1 > r2 goto pc+1483\n     75: 0..3..67.9 (05) goto pc+0\n     76: 0..3..67.9 (71) r1 = *(u8 *)(r3 +0)\n     77: 01....67.9 (15) if r1 == 0x1 goto pc+603\n     78: 01....67.9 (15) if r1 == 0x2 goto pc+582\n     79: .1.....7.9 (b7) r8 = 2\n     80: .1.....789 (55) if r1 != 0x80 goto pc+1477\n     81: .......7.9 (b7) r8 = 1\n     82: .......789 (bf) r1 = r7\n     83: .1.....789 (07) r1 += 62\n     84: .1.....789 (79) r2 = *(u64 *)(r10 -144)\n     85: .12....789 (2d) if r1 > r2 goto pc+1472\n     86: .......7.9 (b7) r1 = 129\n     87: .1.....7.9 (73) *(u8 *)(r7 +54) = r1\n     88: .......7.9 (b7) r1 = 64\n     89: .1.....7.9 (73) *(u8 *)(r7 +21) = r1\n     90: .......7.9 (69) r1 = *(u16 *)(r7 +56)\n     91: .1.....7.9 (07) r1 += -1\n     92: .1.....7.9 (6b) *(u16 *)(r7 +56) = r1\n     93: .......7.9 (61) r1 = *(u32 *)(r7 +34)\n     94: .1.....7.9 (67) r1 <<= 32\n     95: .1.....7.9 (61) r2 = *(u32 *)(r7 +30)\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 476
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
      "selected_workload": "xdp_traffic",
      "status": "ok"
    },
    {
      "app": "tracee/monitor",
      "baseline": {
        "bpf": {
          "493": {
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 493,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 32258088,
            "run_time_ns_delta": 5297726421,
            "type": "raw_tracepoint"
          },
          "494": {
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 494,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "495": {
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 495,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "496": {
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 496,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 32258391,
            "run_time_ns_delta": 10000823725,
            "type": "raw_tracepoint"
          },
          "497": {
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 497,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "498": {
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 498,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "499": {
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 499,
            "name": "trace_sys_enter",
            "run_cnt_delta": 32258088,
            "run_time_ns_delta": 9150196109,
            "type": "raw_tracepoint"
          },
          "500": {
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 500,
            "name": "trace_sys_exit",
            "run_cnt_delta": 32258391,
            "run_time_ns_delta": 9193813449,
            "type": "raw_tracepoint"
          },
          "501": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 501,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "502": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 502,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "503": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 503,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "504": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 504,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "505": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 505,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 865798,
            "run_time_ns_delta": 61878848,
            "type": "kprobe"
          },
          "506": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 506,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 865798,
            "run_time_ns_delta": 237333187,
            "type": "kprobe"
          },
          "507": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 507,
            "name": "trace_dup",
            "run_cnt_delta": 3721,
            "run_time_ns_delta": 1102639,
            "type": "kprobe"
          },
          "508": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 508,
            "name": "trace_ret_dup",
            "run_cnt_delta": 3721,
            "run_time_ns_delta": 4187410,
            "type": "kprobe"
          },
          "509": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 509,
            "name": "trace_dup2",
            "run_cnt_delta": 5024,
            "run_time_ns_delta": 866473,
            "type": "kprobe"
          },
          "510": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 510,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 5024,
            "run_time_ns_delta": 3794713,
            "type": "kprobe"
          },
          "511": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 511,
            "name": "trace_dup3",
            "run_cnt_delta": 5333,
            "run_time_ns_delta": 737254,
            "type": "kprobe"
          },
          "512": {
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 512,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 5333,
            "run_time_ns_delta": 3600359,
            "type": "kprobe"
          },
          "513": {
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 513,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "514": {
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 514,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "515": {
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 515,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "516": {
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 516,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "517": {
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 517,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 518,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 6850,
            "run_time_ns_delta": 19900055,
            "type": "raw_tracepoint"
          },
          "519": {
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 519,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "520": {
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 520,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 521,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 522,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "523": {
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 523,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "524": {
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 524,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 525,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "526": {
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 526,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 18266,
            "type": "raw_tracepoint"
          },
          "527": {
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 527,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "528": {
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 528,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 6562,
            "run_time_ns_delta": 8224817,
            "type": "raw_tracepoint"
          },
          "529": {
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 529,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 6547,
            "run_time_ns_delta": 5680011,
            "type": "raw_tracepoint"
          },
          "530": {
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 530,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "531": {
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 531,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 846793,
            "run_time_ns_delta": 371582669,
            "type": "raw_tracepoint"
          },
          "532": {
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 532,
            "name": "trace_filldir64",
            "run_cnt_delta": 302301,
            "run_time_ns_delta": 5213288,
            "type": "kprobe"
          },
          "533": {
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 533,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "534": {
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 534,
            "name": "trace_do_exit",
            "run_cnt_delta": 6562,
            "run_time_ns_delta": 4894723,
            "type": "kprobe"
          },
          "535": {
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 535,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "536": {
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 536,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "537": {
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 537,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "538": {
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 538,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 5105574,
            "run_time_ns_delta": 500035907,
            "type": "kprobe"
          },
          "539": {
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 539,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "540": {
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 540,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "541": {
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 541,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "542": {
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 542,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "543": {
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 543,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 11249,
            "type": "kprobe"
          },
          "544": {
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 544,
            "name": "trace_security_file_open",
            "run_cnt_delta": 630705,
            "run_time_ns_delta": 371495252,
            "type": "kprobe"
          },
          "545": {
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 545,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "546": {
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 546,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 2682,
            "run_time_ns_delta": 3674788,
            "type": "kprobe"
          },
          "547": {
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 547,
            "name": "trace_commit_creds",
            "run_cnt_delta": 129528,
            "run_time_ns_delta": 37416093,
            "type": "kprobe"
          },
          "548": {
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 548,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 6562,
            "run_time_ns_delta": 4542868,
            "type": "kprobe"
          },
          "549": {
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 549,
            "name": "trace_cap_capable",
            "run_cnt_delta": 2287601,
            "run_time_ns_delta": 292778339,
            "type": "kprobe"
          },
          "550": {
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 550,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 44973,
            "run_time_ns_delta": 18346390,
            "type": "kprobe"
          },
          "551": {
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 551,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "552": {
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 552,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "553": {
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 553,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "554": {
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 554,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "555": {
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 555,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 37637,
            "type": "kprobe"
          },
          "556": {
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 556,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 26956,
            "run_time_ns_delta": 13420052,
            "type": "kprobe"
          },
          "557": {
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 557,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 27528,
            "run_time_ns_delta": 17416616,
            "type": "kprobe"
          },
          "558": {
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 558,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 24,
            "run_time_ns_delta": 32261,
            "type": "kprobe"
          },
          "559": {
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 559,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 26704,
            "run_time_ns_delta": 14229328,
            "type": "kprobe"
          },
          "560": {
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 560,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "561": {
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 561,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "562": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 562,
            "name": "trace_vfs_write",
            "run_cnt_delta": 213633,
            "run_time_ns_delta": 18842347,
            "type": "kprobe"
          },
          "563": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 563,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 213633,
            "run_time_ns_delta": 8822528,
            "type": "kprobe"
          },
          "564": {
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 564,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 213633,
            "run_time_ns_delta": 132056098,
            "type": "kprobe"
          },
          "565": {
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 565,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 213633,
            "run_time_ns_delta": 14624524,
            "type": "kprobe"
          },
          "566": {
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 566,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "567": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 567,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 119,
            "run_time_ns_delta": 33700,
            "type": "kprobe"
          },
          "568": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 568,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 119,
            "run_time_ns_delta": 84228,
            "type": "kprobe"
          },
          "569": {
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 569,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 119,
            "run_time_ns_delta": 296599,
            "type": "kprobe"
          },
          "570": {
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 570,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 119,
            "run_time_ns_delta": 648490,
            "type": "kprobe"
          },
          "571": {
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 571,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "572": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 572,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "573": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 573,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "574": {
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 574,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "575": {
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 575,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "576": {
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 576,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "577": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 577,
            "name": "trace_vfs_read",
            "run_cnt_delta": 1148998,
            "run_time_ns_delta": 93623913,
            "type": "kprobe"
          },
          "578": {
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 578,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 1148998,
            "run_time_ns_delta": 737013231,
            "type": "kprobe"
          },
          "579": {
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 579,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "580": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 580,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 119,
            "run_time_ns_delta": 33875,
            "type": "kprobe"
          },
          "581": {
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 581,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 119,
            "run_time_ns_delta": 294003,
            "type": "kprobe"
          },
          "582": {
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 582,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "583": {
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 583,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 893975,
            "run_time_ns_delta": 129252846,
            "type": "kprobe"
          },
          "584": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 584,
            "name": "trace_do_mmap",
            "run_cnt_delta": 809062,
            "run_time_ns_delta": 68268752,
            "type": "kprobe"
          },
          "585": {
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 585,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 809062,
            "run_time_ns_delta": 298084730,
            "type": "kprobe"
          },
          "586": {
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 586,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 809058,
            "run_time_ns_delta": 95624051,
            "type": "kprobe"
          },
          "587": {
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 587,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 2292159,
            "run_time_ns_delta": 1059390065,
            "type": "kprobe"
          },
          "588": {
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 588,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "589": {
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 589,
            "name": "trace_security_bpf",
            "run_cnt_delta": 7386,
            "run_time_ns_delta": 2109353,
            "type": "kprobe"
          },
          "590": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 590,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "591": {
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 591,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "592": {
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 592,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2608,
            "run_time_ns_delta": 778294,
            "type": "kprobe"
          },
          "593": {
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 593,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 161,
            "run_time_ns_delta": 134570,
            "type": "kprobe"
          },
          "594": {
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 594,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "595": {
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 595,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "596": {
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 596,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "597": {
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 597,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "598": {
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 598,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "599": {
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 599,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 2388,
            "run_time_ns_delta": 3213578,
            "type": "kprobe"
          },
          "600": {
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 600,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "601": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 601,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "602": {
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 602,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "603": {
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 603,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "604": {
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 604,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "605": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 605,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "606": {
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 606,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "607": {
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 607,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 8412,
            "type": "kprobe"
          },
          "608": {
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 608,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 1947804,
            "run_time_ns_delta": 90334319,
            "type": "kprobe"
          },
          "609": {
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 609,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 4242,
            "run_time_ns_delta": 3769467,
            "type": "raw_tracepoint"
          },
          "610": {
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 610,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "611": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 611,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "612": {
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 612,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "613": {
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 613,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 8500,
            "run_time_ns_delta": 7969670,
            "type": "kprobe"
          },
          "614": {
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 614,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "615": {
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 615,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "616": {
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 616,
            "name": "trace_do_truncate",
            "run_cnt_delta": 436,
            "run_time_ns_delta": 944735,
            "type": "kprobe"
          },
          "617": {
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 617,
            "name": "trace_fd_install",
            "run_cnt_delta": 861789,
            "run_time_ns_delta": 244687158,
            "type": "kprobe"
          },
          "618": {
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 618,
            "name": "trace_filp_close",
            "run_cnt_delta": 385137,
            "run_time_ns_delta": 124910119,
            "type": "kprobe"
          },
          "619": {
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 619,
            "name": "trace_file_update_time",
            "run_cnt_delta": 17097,
            "run_time_ns_delta": 4700081,
            "type": "kprobe"
          },
          "620": {
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 620,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 17097,
            "run_time_ns_delta": 16356501,
            "type": "kprobe"
          },
          "621": {
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 621,
            "name": "trace_file_modified",
            "run_cnt_delta": 200839,
            "run_time_ns_delta": 22035150,
            "type": "kprobe"
          },
          "622": {
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 622,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 200839,
            "run_time_ns_delta": 95797630,
            "type": "kprobe"
          },
          "623": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 623,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "624": {
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 624,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "625": {
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 625,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "626": {
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 626,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 295,
            "type": "kprobe"
          },
          "627": {
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 627,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 9441,
            "type": "kprobe"
          },
          "628": {
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 628,
            "name": "trace_execute_finished",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 15952,
            "type": "kprobe"
          },
          "629": {
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 629,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "630": {
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 630,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8368,
            "type": "kprobe"
          },
          "631": {
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 631,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 287832,
            "run_time_ns_delta": 86851859,
            "type": "kprobe"
          },
          "632": {
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 632,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "633": {
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 633,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "634": {
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 634,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 305632,
            "run_time_ns_delta": 104462657,
            "type": "kprobe"
          },
          "635": {
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 635,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "636": {
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 636,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "637": {
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 637,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 72489,
            "run_time_ns_delta": 6818464,
            "type": "kprobe"
          },
          "638": {
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 638,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 72489,
            "run_time_ns_delta": 44004891,
            "type": "kprobe"
          },
          "639": {
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 639,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 26030,
            "run_time_ns_delta": 27001294,
            "type": "kprobe"
          },
          "640": {
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 640,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 581834,
            "run_time_ns_delta": 179450410,
            "type": "kprobe"
          },
          "641": {
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 641,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 1618167,
            "run_time_ns_delta": 497810498,
            "type": "kprobe"
          },
          "642": {
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 642,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 2283143,
            "run_time_ns_delta": 615369083,
            "type": "kprobe"
          },
          "644": {
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 644,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 871716,
            "run_time_ns_delta": 265707964,
            "type": "cgroup_skb"
          },
          "645": {
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 645,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 1397603,
            "run_time_ns_delta": 387155831,
            "type": "cgroup_skb"
          },
          "646": {
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 646,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "647": {
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 647,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "648": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 648,
            "name": "empty_kprobe",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 125,
            "type": "kprobe"
          },
          "649": {
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 649,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2617,
            "type": "raw_tracepoint"
          },
          "650": {
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 650,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 630705,
            "run_time_ns_delta": 174537266,
            "type": "lsm"
          },
          "651": {
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 651,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.3924982379999165,
            "ops_per_sec": 1949537.2155929042,
            "ops_total": 10512876.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [25005] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25005]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25005] cap              286495      5.08      0.14      2.96     56359.95       92581.43\nstress-ng: metrc: [25005] eventfd           67779      5.00      0.12      1.72     13545.06       36933.10\nstress-ng: metrc: [25005] get                3749      5.01      0.10      2.21       748.86        1624.81\nstress-ng: metrc: [25005] prctl              3292      5.00      2.36      0.75       657.83        1058.07\nstress-ng: metrc: [25005] set               12901      5.12      0.10      1.88      2517.38        6532.07\nstress-ng: metrc: [25005] dup                1186      5.03      0.39      0.41       235.99        1485.51\nstress-ng: metrc: [25005] kill              45361      5.08      0.05      3.04      8928.65       14672.77\nstress-ng: metrc: [25005] sigfd            490141      5.14      0.05      3.19     95447.81      151000.93\nstress-ng: metrc: [25005] signal                0      5.04      0.01      0.00         0.00           0.00\nstress-ng: metrc: [25005] pty                  89      5.08      0.15      5.50        17.52          15.75\nstress-ng: metrc: [25005] itimer              258      5.04      0.07      2.26        51.22         110.89\nstress-ng: metrc: [25005] timerfd          222208      5.13      0.02      2.09     43296.38      105479.27\nstress-ng: metrc: [25005] aio               20172      5.03      0.03      0.22      4007.05       78123.67\nstress-ng: metrc: [25005] aiol               5743      5.26      0.12      0.44      1092.22       10232.28\nstress-ng: metrc: [25005] hdd               60416      5.06      1.00      1.00     11938.33       30281.83\nstress-ng: metrc: [25005] io                  125      5.05      0.02      0.02        24.73        2824.35\nstress-ng: metrc: [25005] iomix              4273      5.15      0.10      2.59       828.94        1586.51\nstress-ng: metrc: [25005] io-uring          26828      5.14      0.00      1.55      5216.10       17278.31\nstress-ng: metrc: [25005] sync-file           104      5.02      0.06      1.26        20.73          78.79\nstress-ng: metrc: [25005] epoll               681      5.17      0.05      0.05       131.79        7076.57\nstress-ng: metrc: [25005] netdev           128484      5.08      0.10      4.04     25275.07       31035.61\nstress-ng: metrc: [25005] sctp               6184      5.01      0.04      0.02      1235.56       99048.60\nstress-ng: metrc: [25005] sock                708      5.06      0.10      1.34       139.97         494.17\nstress-ng: metrc: [25005] sockdiag        6783328      5.03      0.01      1.07   1348724.24     6264206.91\nstress-ng: metrc: [25005] sockfd           167039      5.04      0.05      2.03     33172.66       80155.46\nstress-ng: metrc: [25005] sockpair            328      5.12      0.03      0.13        64.03        1983.73\nstress-ng: metrc: [25005] sockmany          26014      5.14      0.07      1.88      5062.05       13300.64\nstress-ng: metrc: [25005] udp              178574      5.01      0.07      4.05     35665.51       43404.01\nstress-ng: metrc: [25005] udp-flood        268582      5.03      0.05      2.00     53417.43      131012.86\nstress-ng: metrc: [25005] mmap                707      5.04      0.06      2.71       140.41         255.55\nstress-ng: metrc: [25005] mprotect        1698228      5.11      0.63     13.51    332078.53      120114.49\nstress-ng: metrc: [25005] mremap             2832      5.03      0.05      2.67       562.83        1039.49\nstress-ng: metrc: [25005] madvise              67      5.02      0.18      4.27        13.35          15.05\nstress-ng: info:  [25005] skipped: 0\nstress-ng: info:  [25005] passed: 132: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp (4) udp-flood (4) mmap (4) mprotect (4) mremap (4) madvise (4)\nstress-ng: info:  [25005] failed: 0\nstress-ng: info:  [25005] metrics untrustworthy: 0\nstress-ng: info:  [25005] successful run completed in 5.36 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "493": {
            "bytes_jited": 237,
            "bytes_xlated": 280,
            "id": 493,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 33066517,
            "run_time_ns_delta": 5508174161,
            "type": "raw_tracepoint"
          },
          "494": {
            "bytes_jited": 2516,
            "bytes_xlated": 4568,
            "id": 494,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "495": {
            "bytes_jited": 17485,
            "bytes_xlated": 30584,
            "id": 495,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "496": {
            "bytes_jited": 266,
            "bytes_xlated": 336,
            "id": 496,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 33066880,
            "run_time_ns_delta": 10123644320,
            "type": "raw_tracepoint"
          },
          "497": {
            "bytes_jited": 2096,
            "bytes_xlated": 3816,
            "id": 497,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "498": {
            "bytes_jited": 11622,
            "bytes_xlated": 20088,
            "id": 498,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "499": {
            "bytes_jited": 8168,
            "bytes_xlated": 13824,
            "id": 499,
            "name": "trace_sys_enter",
            "run_cnt_delta": 33066517,
            "run_time_ns_delta": 9760999903,
            "type": "raw_tracepoint"
          },
          "500": {
            "bytes_jited": 8201,
            "bytes_xlated": 13880,
            "id": 500,
            "name": "trace_sys_exit",
            "run_cnt_delta": 33066880,
            "run_time_ns_delta": 9764561008,
            "type": "raw_tracepoint"
          },
          "501": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 501,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "502": {
            "bytes_jited": 11358,
            "bytes_xlated": 19712,
            "id": 502,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "503": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 503,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "504": {
            "bytes_jited": 11358,
            "bytes_xlated": 19712,
            "id": 504,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "505": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 505,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 924184,
            "run_time_ns_delta": 65468534,
            "type": "kprobe"
          },
          "506": {
            "bytes_jited": 11358,
            "bytes_xlated": 19712,
            "id": 506,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 924184,
            "run_time_ns_delta": 253496293,
            "type": "kprobe"
          },
          "507": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 507,
            "name": "trace_dup",
            "run_cnt_delta": 4096,
            "run_time_ns_delta": 1133685,
            "type": "kprobe"
          },
          "508": {
            "bytes_jited": 11358,
            "bytes_xlated": 19712,
            "id": 508,
            "name": "trace_ret_dup",
            "run_cnt_delta": 4096,
            "run_time_ns_delta": 4399137,
            "type": "kprobe"
          },
          "509": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 509,
            "name": "trace_dup2",
            "run_cnt_delta": 5913,
            "run_time_ns_delta": 830331,
            "type": "kprobe"
          },
          "510": {
            "bytes_jited": 11358,
            "bytes_xlated": 19712,
            "id": 510,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 5913,
            "run_time_ns_delta": 4008611,
            "type": "kprobe"
          },
          "511": {
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 511,
            "name": "trace_dup3",
            "run_cnt_delta": 6314,
            "run_time_ns_delta": 750206,
            "type": "kprobe"
          },
          "512": {
            "bytes_jited": 11358,
            "bytes_xlated": 19712,
            "id": 512,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 6314,
            "run_time_ns_delta": 3961865,
            "type": "kprobe"
          },
          "513": {
            "bytes_jited": 20767,
            "bytes_xlated": 32168,
            "id": 513,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "514": {
            "bytes_jited": 20738,
            "bytes_xlated": 32184,
            "id": 514,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "515": {
            "bytes_jited": 21030,
            "bytes_xlated": 32576,
            "id": 515,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "516": {
            "bytes_jited": 20998,
            "bytes_xlated": 32584,
            "id": 516,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "517": {
            "bytes_jited": 12178,
            "bytes_xlated": 18536,
            "id": 517,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "bytes_jited": 19689,
            "bytes_xlated": 32160,
            "id": 518,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 7439,
            "run_time_ns_delta": 22050191,
            "type": "raw_tracepoint"
          },
          "519": {
            "bytes_jited": 59206,
            "bytes_xlated": 108392,
            "id": 519,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "520": {
            "bytes_jited": 6211,
            "bytes_xlated": 10280,
            "id": 520,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "bytes_jited": 4359,
            "bytes_xlated": 7880,
            "id": 521,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "bytes_jited": 62268,
            "bytes_xlated": 112152,
            "id": 522,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "523": {
            "bytes_jited": 655,
            "bytes_xlated": 1064,
            "id": 523,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "524": {
            "bytes_jited": 57890,
            "bytes_xlated": 102344,
            "id": 524,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "bytes_jited": 3900,
            "bytes_xlated": 6504,
            "id": 525,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "526": {
            "bytes_jited": 20625,
            "bytes_xlated": 35792,
            "id": 526,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 9785,
            "type": "raw_tracepoint"
          },
          "527": {
            "bytes_jited": 24436,
            "bytes_xlated": 38432,
            "id": 527,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "528": {
            "bytes_jited": 8709,
            "bytes_xlated": 14656,
            "id": 528,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 7168,
            "run_time_ns_delta": 9114858,
            "type": "raw_tracepoint"
          },
          "529": {
            "bytes_jited": 251,
            "bytes_xlated": 456,
            "id": 529,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 7168,
            "run_time_ns_delta": 6499318,
            "type": "raw_tracepoint"
          },
          "530": {
            "bytes_jited": 9104,
            "bytes_xlated": 13856,
            "id": 530,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "531": {
            "bytes_jited": 8954,
            "bytes_xlated": 15032,
            "id": 531,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 601910,
            "run_time_ns_delta": 295907735,
            "type": "raw_tracepoint"
          },
          "532": {
            "bytes_jited": 8210,
            "bytes_xlated": 13896,
            "id": 532,
            "name": "trace_filldir64",
            "run_cnt_delta": 400452,
            "run_time_ns_delta": 7008318,
            "type": "kprobe"
          },
          "533": {
            "bytes_jited": 23532,
            "bytes_xlated": 36904,
            "id": 533,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "534": {
            "bytes_jited": 7968,
            "bytes_xlated": 13528,
            "id": 534,
            "name": "trace_do_exit",
            "run_cnt_delta": 7168,
            "run_time_ns_delta": 5395171,
            "type": "kprobe"
          },
          "535": {
            "bytes_jited": 56360,
            "bytes_xlated": 97432,
            "id": 535,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "536": {
            "bytes_jited": 6767,
            "bytes_xlated": 11216,
            "id": 536,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "537": {
            "bytes_jited": 6540,
            "bytes_xlated": 10968,
            "id": 537,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "538": {
            "bytes_jited": 11482,
            "bytes_xlated": 18448,
            "id": 538,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 1654703,
            "run_time_ns_delta": 189659109,
            "type": "kprobe"
          },
          "539": {
            "bytes_jited": 9756,
            "bytes_xlated": 15808,
            "id": 539,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "540": {
            "bytes_jited": 8658,
            "bytes_xlated": 14560,
            "id": 540,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "541": {
            "bytes_jited": 8633,
            "bytes_xlated": 14536,
            "id": 541,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "542": {
            "bytes_jited": 8633,
            "bytes_xlated": 14536,
            "id": 542,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "543": {
            "bytes_jited": 33408,
            "bytes_xlated": 53024,
            "id": 543,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8673,
            "type": "kprobe"
          },
          "544": {
            "bytes_jited": 23006,
            "bytes_xlated": 37344,
            "id": 544,
            "name": "trace_security_file_open",
            "run_cnt_delta": 438670,
            "run_time_ns_delta": 300266131,
            "type": "kprobe"
          },
          "545": {
            "bytes_jited": 18662,
            "bytes_xlated": 30800,
            "id": 545,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "546": {
            "bytes_jited": 10006,
            "bytes_xlated": 16536,
            "id": 546,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 3076,
            "run_time_ns_delta": 4078294,
            "type": "kprobe"
          },
          "547": {
            "bytes_jited": 10751,
            "bytes_xlated": 17080,
            "id": 547,
            "name": "trace_commit_creds",
            "run_cnt_delta": 120524,
            "run_time_ns_delta": 36232526,
            "type": "kprobe"
          },
          "548": {
            "bytes_jited": 10043,
            "bytes_xlated": 16672,
            "id": 548,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 7168,
            "run_time_ns_delta": 4470374,
            "type": "kprobe"
          },
          "549": {
            "bytes_jited": 8208,
            "bytes_xlated": 13880,
            "id": 549,
            "name": "trace_cap_capable",
            "run_cnt_delta": 1886321,
            "run_time_ns_delta": 265287171,
            "type": "kprobe"
          },
          "550": {
            "bytes_jited": 8487,
            "bytes_xlated": 14296,
            "id": 550,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 208924,
            "run_time_ns_delta": 71053745,
            "type": "kprobe"
          },
          "551": {
            "bytes_jited": 9226,
            "bytes_xlated": 15464,
            "id": 551,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "552": {
            "bytes_jited": 8310,
            "bytes_xlated": 14024,
            "id": 552,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "553": {
            "bytes_jited": 9532,
            "bytes_xlated": 15960,
            "id": 553,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "554": {
            "bytes_jited": 9244,
            "bytes_xlated": 15544,
            "id": 554,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "555": {
            "bytes_jited": 10798,
            "bytes_xlated": 16648,
            "id": 555,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 38847,
            "type": "kprobe"
          },
          "556": {
            "bytes_jited": 10099,
            "bytes_xlated": 15592,
            "id": 556,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 18839,
            "run_time_ns_delta": 9871428,
            "type": "kprobe"
          },
          "557": {
            "bytes_jited": 11281,
            "bytes_xlated": 17384,
            "id": 557,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 18745,
            "run_time_ns_delta": 12788209,
            "type": "kprobe"
          },
          "558": {
            "bytes_jited": 10612,
            "bytes_xlated": 16272,
            "id": 558,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 24,
            "run_time_ns_delta": 35381,
            "type": "kprobe"
          },
          "559": {
            "bytes_jited": 11030,
            "bytes_xlated": 17040,
            "id": 559,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 152855,
            "run_time_ns_delta": 54821481,
            "type": "kprobe"
          },
          "560": {
            "bytes_jited": 952,
            "bytes_xlated": 1584,
            "id": 560,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "561": {
            "bytes_jited": 952,
            "bytes_xlated": 1584,
            "id": 561,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "562": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 562,
            "name": "trace_vfs_write",
            "run_cnt_delta": 241923,
            "run_time_ns_delta": 25919468,
            "type": "kprobe"
          },
          "563": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 563,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 241923,
            "run_time_ns_delta": 8827169,
            "type": "kprobe"
          },
          "564": {
            "bytes_jited": 19178,
            "bytes_xlated": 32016,
            "id": 564,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 241923,
            "run_time_ns_delta": 153223485,
            "type": "kprobe"
          },
          "565": {
            "bytes_jited": 23822,
            "bytes_xlated": 36976,
            "id": 565,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 241923,
            "run_time_ns_delta": 16607626,
            "type": "kprobe"
          },
          "566": {
            "bytes_jited": 29990,
            "bytes_xlated": 52040,
            "id": 566,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "567": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 567,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 103,
            "run_time_ns_delta": 45330,
            "type": "kprobe"
          },
          "568": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 568,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 103,
            "run_time_ns_delta": 55095,
            "type": "kprobe"
          },
          "569": {
            "bytes_jited": 19177,
            "bytes_xlated": 32008,
            "id": 569,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 103,
            "run_time_ns_delta": 242864,
            "type": "kprobe"
          },
          "570": {
            "bytes_jited": 24558,
            "bytes_xlated": 37832,
            "id": 570,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 103,
            "run_time_ns_delta": 601428,
            "type": "kprobe"
          },
          "571": {
            "bytes_jited": 29913,
            "bytes_xlated": 52016,
            "id": 571,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "572": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 572,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "573": {
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 573,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "574": {
            "bytes_jited": 19181,
            "bytes_xlated": 32016,
            "id": 574,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "575": {
            "bytes_jited": 23822,
            "bytes_xlated": 36976,
            "id": 575,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "576": {
            "bytes_jited": 29990,
            "bytes_xlated": 52040,
            "id": 576,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "577": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 577,
            "name": "trace_vfs_read",
            "run_cnt_delta": 1277963,
            "run_time_ns_delta": 107219555,
            "type": "kprobe"
          },
          "578": {
            "bytes_jited": 19181,
            "bytes_xlated": 32016,
            "id": 578,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 1277963,
            "run_time_ns_delta": 1064349643,
            "type": "kprobe"
          },
          "579": {
            "bytes_jited": 17198,
            "bytes_xlated": 30008,
            "id": 579,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "580": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 580,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 103,
            "run_time_ns_delta": 38704,
            "type": "kprobe"
          },
          "581": {
            "bytes_jited": 19177,
            "bytes_xlated": 32008,
            "id": 581,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 103,
            "run_time_ns_delta": 250435,
            "type": "kprobe"
          },
          "582": {
            "bytes_jited": 17924,
            "bytes_xlated": 30976,
            "id": 582,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "583": {
            "bytes_jited": 20691,
            "bytes_xlated": 32888,
            "id": 583,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 542815,
            "run_time_ns_delta": 82143970,
            "type": "kprobe"
          },
          "584": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 584,
            "name": "trace_do_mmap",
            "run_cnt_delta": 520721,
            "run_time_ns_delta": 39725274,
            "type": "kprobe"
          },
          "585": {
            "bytes_jited": 19591,
            "bytes_xlated": 32064,
            "id": 585,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 520721,
            "run_time_ns_delta": 192487775,
            "type": "kprobe"
          },
          "586": {
            "bytes_jited": 37038,
            "bytes_xlated": 61248,
            "id": 586,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 520717,
            "run_time_ns_delta": 66304268,
            "type": "kprobe"
          },
          "587": {
            "bytes_jited": 34684,
            "bytes_xlated": 60000,
            "id": 587,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 3040194,
            "run_time_ns_delta": 1359714570,
            "type": "kprobe"
          },
          "588": {
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 588,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "589": {
            "bytes_jited": 15692,
            "bytes_xlated": 27368,
            "id": 589,
            "name": "trace_security_bpf",
            "run_cnt_delta": 7386,
            "run_time_ns_delta": 1757338,
            "type": "kprobe"
          },
          "590": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 590,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "591": {
            "bytes_jited": 8835,
            "bytes_xlated": 14832,
            "id": 591,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "592": {
            "bytes_jited": 8371,
            "bytes_xlated": 14112,
            "id": 592,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2608,
            "run_time_ns_delta": 630997,
            "type": "kprobe"
          },
          "593": {
            "bytes_jited": 9616,
            "bytes_xlated": 15672,
            "id": 593,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 161,
            "run_time_ns_delta": 115746,
            "type": "kprobe"
          },
          "594": {
            "bytes_jited": 6385,
            "bytes_xlated": 10736,
            "id": 594,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "595": {
            "bytes_jited": 6624,
            "bytes_xlated": 11232,
            "id": 595,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "596": {
            "bytes_jited": 6630,
            "bytes_xlated": 11240,
            "id": 596,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "597": {
            "bytes_jited": 18659,
            "bytes_xlated": 30840,
            "id": 597,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "598": {
            "bytes_jited": 17324,
            "bytes_xlated": 30744,
            "id": 598,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "599": {
            "bytes_jited": 9260,
            "bytes_xlated": 15552,
            "id": 599,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 2812,
            "run_time_ns_delta": 3234199,
            "type": "kprobe"
          },
          "600": {
            "bytes_jited": 8694,
            "bytes_xlated": 14560,
            "id": 600,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "601": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 601,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "602": {
            "bytes_jited": 8836,
            "bytes_xlated": 14816,
            "id": 602,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "603": {
            "bytes_jited": 19893,
            "bytes_xlated": 32840,
            "id": 603,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "604": {
            "bytes_jited": 9013,
            "bytes_xlated": 15144,
            "id": 604,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "605": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 605,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "606": {
            "bytes_jited": 14629,
            "bytes_xlated": 24312,
            "id": 606,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "607": {
            "bytes_jited": 18502,
            "bytes_xlated": 30544,
            "id": 607,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5508,
            "type": "kprobe"
          },
          "608": {
            "bytes_jited": 8728,
            "bytes_xlated": 14712,
            "id": 608,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 2099163,
            "run_time_ns_delta": 98989601,
            "type": "kprobe"
          },
          "609": {
            "bytes_jited": 8521,
            "bytes_xlated": 14328,
            "id": 609,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 4464,
            "run_time_ns_delta": 4486936,
            "type": "raw_tracepoint"
          },
          "610": {
            "bytes_jited": 9846,
            "bytes_xlated": 16568,
            "id": 610,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "611": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 611,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "612": {
            "bytes_jited": 8440,
            "bytes_xlated": 14224,
            "id": 612,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "613": {
            "bytes_jited": 10079,
            "bytes_xlated": 16416,
            "id": 613,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 9156,
            "run_time_ns_delta": 8634060,
            "type": "kprobe"
          },
          "614": {
            "bytes_jited": 18586,
            "bytes_xlated": 30720,
            "id": 614,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "615": {
            "bytes_jited": 18586,
            "bytes_xlated": 30720,
            "id": 615,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "616": {
            "bytes_jited": 9559,
            "bytes_xlated": 16016,
            "id": 616,
            "name": "trace_do_truncate",
            "run_cnt_delta": 401,
            "run_time_ns_delta": 963459,
            "type": "kprobe"
          },
          "617": {
            "bytes_jited": 17014,
            "bytes_xlated": 27688,
            "id": 617,
            "name": "trace_fd_install",
            "run_cnt_delta": 793409,
            "run_time_ns_delta": 235762931,
            "type": "kprobe"
          },
          "618": {
            "bytes_jited": 16942,
            "bytes_xlated": 27536,
            "id": 618,
            "name": "trace_filp_close",
            "run_cnt_delta": 418982,
            "run_time_ns_delta": 141947314,
            "type": "kprobe"
          },
          "619": {
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 619,
            "name": "trace_file_update_time",
            "run_cnt_delta": 16345,
            "run_time_ns_delta": 4721302,
            "type": "kprobe"
          },
          "620": {
            "bytes_jited": 20054,
            "bytes_xlated": 31360,
            "id": 620,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 16345,
            "run_time_ns_delta": 17183398,
            "type": "kprobe"
          },
          "621": {
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 621,
            "name": "trace_file_modified",
            "run_cnt_delta": 194013,
            "run_time_ns_delta": 21093941,
            "type": "kprobe"
          },
          "622": {
            "bytes_jited": 20189,
            "bytes_xlated": 31536,
            "id": 622,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 194013,
            "run_time_ns_delta": 95066138,
            "type": "kprobe"
          },
          "623": {
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 623,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "624": {
            "bytes_jited": 18070,
            "bytes_xlated": 30152,
            "id": 624,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "625": {
            "bytes_jited": 12889,
            "bytes_xlated": 20216,
            "id": 625,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "626": {
            "bytes_jited": 16542,
            "bytes_xlated": 29168,
            "id": 626,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 667,
            "type": "kprobe"
          },
          "627": {
            "bytes_jited": 16753,
            "bytes_xlated": 29352,
            "id": 627,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 6509,
            "type": "kprobe"
          },
          "628": {
            "bytes_jited": 24504,
            "bytes_xlated": 38520,
            "id": 628,
            "name": "trace_execute_finished",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 11145,
            "type": "kprobe"
          },
          "629": {
            "bytes_jited": 18417,
            "bytes_xlated": 30392,
            "id": 629,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "630": {
            "bytes_jited": 18276,
            "bytes_xlated": 30168,
            "id": 630,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 5835,
            "type": "kprobe"
          },
          "631": {
            "bytes_jited": 8654,
            "bytes_xlated": 14544,
            "id": 631,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 243844,
            "run_time_ns_delta": 76216853,
            "type": "kprobe"
          },
          "632": {
            "bytes_jited": 8679,
            "bytes_xlated": 14600,
            "id": 632,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "633": {
            "bytes_jited": 17605,
            "bytes_xlated": 29392,
            "id": 633,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "634": {
            "bytes_jited": 47191,
            "bytes_xlated": 76808,
            "id": 634,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 325485,
            "run_time_ns_delta": 116082161,
            "type": "kprobe"
          },
          "635": {
            "bytes_jited": 13789,
            "bytes_xlated": 22336,
            "id": 635,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "636": {
            "bytes_jited": 9530,
            "bytes_xlated": 15976,
            "id": 636,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "637": {
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 637,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 227661,
            "run_time_ns_delta": 10917120,
            "type": "kprobe"
          },
          "638": {
            "bytes_jited": 8563,
            "bytes_xlated": 13368,
            "id": 638,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 227661,
            "run_time_ns_delta": 46821963,
            "type": "kprobe"
          },
          "639": {
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 639,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 16847,
            "run_time_ns_delta": 12843414,
            "type": "kprobe"
          },
          "640": {
            "bytes_jited": 8816,
            "bytes_xlated": 13608,
            "id": 640,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 452732,
            "run_time_ns_delta": 131265137,
            "type": "kprobe"
          },
          "641": {
            "bytes_jited": 8816,
            "bytes_xlated": 13608,
            "id": 641,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 1341566,
            "run_time_ns_delta": 411540783,
            "type": "kprobe"
          },
          "642": {
            "bytes_jited": 5563,
            "bytes_xlated": 8648,
            "id": 642,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 1760003,
            "run_time_ns_delta": 433285672,
            "type": "kprobe"
          },
          "644": {
            "bytes_jited": 19692,
            "bytes_xlated": 31248,
            "id": 644,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 687011,
            "run_time_ns_delta": 182733301,
            "type": "cgroup_skb"
          },
          "645": {
            "bytes_jited": 19692,
            "bytes_xlated": 31248,
            "id": 645,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 1037517,
            "run_time_ns_delta": 332797694,
            "type": "cgroup_skb"
          },
          "646": {
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 646,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "647": {
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 647,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "648": {
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 648,
            "name": "empty_kprobe",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 336,
            "type": "kprobe"
          },
          "649": {
            "bytes_jited": 58993,
            "bytes_xlated": 97720,
            "id": 649,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1782,
            "type": "raw_tracepoint"
          },
          "650": {
            "bytes_jited": 7334,
            "bytes_xlated": 13480,
            "id": 650,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 438670,
            "run_time_ns_delta": 143690522,
            "type": "lsm"
          },
          "651": {
            "bytes_jited": 5363,
            "bytes_xlated": 9120,
            "id": 651,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.26901530799978,
            "ops_per_sec": 3432133.6991645643,
            "ops_total": 18083965.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [7881] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7881]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7881] cap              376930      5.02      0.15      4.21     75119.71       86408.75\nstress-ng: metrc: [7881] eventfd           85512      5.01      0.10      2.41     17083.73       34026.60\nstress-ng: metrc: [7881] get                2736      5.01      0.18      1.63       545.73        1515.55\nstress-ng: metrc: [7881] prctl              3514      5.01      2.53      0.75       701.57        1071.66\nstress-ng: metrc: [7881] set               11785      5.05      0.08      1.66      2334.59        6799.47\nstress-ng: metrc: [7881] dup                1398      5.02      0.44      0.43       278.39        1607.12\nstress-ng: metrc: [7881] kill              28893      5.04      0.02      1.92      5727.20       14847.14\nstress-ng: metrc: [7881] sigfd            363949      5.06      0.24      4.71     71940.13       73473.90\nstress-ng: metrc: [7881] signal                0      5.01      0.01      0.00         0.00           0.00\nstress-ng: metrc: [7881] pty                  37      5.04      0.05      2.68         7.34          13.58\nstress-ng: metrc: [7881] itimer              261      5.02      0.05      2.33        51.97         109.57\nstress-ng: metrc: [7881] timerfd          481280      5.04      0.06      4.20     95549.01      113159.01\nstress-ng: metrc: [7881] aio               21382      5.04      0.00      0.26      4245.18       81994.37\nstress-ng: metrc: [7881] aiol               5741      5.15      0.13      0.44      1114.51       10046.78\nstress-ng: metrc: [7881] hdd               52482      5.02      0.84      0.93     10445.95       29595.25\nstress-ng: metrc: [7881] io                  169      5.04      0.04      0.02        33.55        2993.91\nstress-ng: metrc: [7881] iomix              3633      5.07      0.16      2.82       716.51        1219.84\nstress-ng: metrc: [7881] io-uring          25848      5.07      0.01      1.70      5098.82       15086.94\nstress-ng: metrc: [7881] sync-file            98      5.02      0.05      1.25        19.52          75.39\nstress-ng: metrc: [7881] epoll               933      5.07      0.07      1.10       183.92         798.60\nstress-ng: metrc: [7881] netdev            27560      5.02      0.02      0.88      5486.23       30524.44\nstress-ng: metrc: [7881] sctp              12670      5.03      0.05      1.07      2519.13       11345.84\nstress-ng: metrc: [7881] sock                681      5.03      0.04      1.46       135.46         453.62\nstress-ng: metrc: [7881] sockdiag       13910193      5.02      0.02      1.96   2769886.72     7043931.04\nstress-ng: metrc: [7881] sockfd           132581      5.03      0.05      1.83     26363.92       70568.02\nstress-ng: metrc: [7881] sockpair            680      5.05      0.00      0.18       134.62        3753.51\nstress-ng: metrc: [7881] sockmany          10070      5.05      0.03      0.84      1994.16       11541.14\nstress-ng: metrc: [7881] udp               90216      5.03      0.07      2.55     17938.85       34477.90\nstress-ng: metrc: [7881] udp-flood        180812      5.01      0.01      1.41     36087.62      127679.65\nstress-ng: metrc: [7881] mmap                467      5.03      0.03      1.95        92.85         236.09\nstress-ng: metrc: [7881] mprotect        2250621      5.05      0.74     17.63    445813.94      122532.58\nstress-ng: metrc: [7881] mremap              771      5.02      0.03      0.81       153.53         918.20\nstress-ng: metrc: [7881] madvise              62      5.03      0.11      4.02        12.34          15.03\nstress-ng: info:  [7881] skipped: 0\nstress-ng: info:  [7881] passed: 132: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp (4) udp-flood (4) mmap (4) mprotect (4) mremap (4) madvise (4)\nstress-ng: info:  [7881] failed: 0\nstress-ng: info:  [7881] metrics untrustworthy: 0\nstress-ng: info:  [7881] successful run completed in 5.24 secs"
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
          "prefetch",
          "map_inline"
        ],
        "error": "prog 517: prog 517 pass bulk_memory failed after 4 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nfunc#1 @2303\nLive regs before insn:\n      0: .1........ (bf) r8 = r1\n      1: ........8. (b7) r1 = 0\n      2: .1......8. (63) *(u32 *)(r10 -176) = r1\n      3: ........8. (bf) r2 = r10\n      4: ..2.....8. (07) r2 += -176\n      5: ..2.....8. (18) r1 = 0xffff8d2509162800\n      7: .12.....8. (85) call bpf_map_lookup_elem#1\n      8: 0.......8. (bf) r7 = r0\n      9: .......78. (15) if r7 == 0x0 goto pc+23\n     10: .......78. (bf) r2 = r10\n     11: ..2....78. (07) r2 += -176\n     12: ..2....78. (18) r1 = 0xffff8d24dedc8c00\n     14: .12....78. (85) call bpf_map_lookup_elem#1\n     15: 0......78. (7b) *(u64 *)(r10 -208) = r0\n     16: 0......78. (15) if r0 == 0x0 goto pc+16\n     17: .......78. (bf) r6 = r7\n     18: ......678. (07) r6 += 40\n     19: ......678. (18) r1 = 0xffff8d24927c1800\n     21: .1....678. (bf) r2 = r6\n     22: .12...678. (85) call bpf_map_lookup_elem#1\n     23: 0.....678. (7b) *(u64 *)(r10 -184) = r0\n     24: 0.....678. (15) if r0 == 0x0 goto pc+8\n     25: ......678. (bf) r9 = r7\n     26: ......6789 (07) r9 += 36\n     27: ......6789 (18) r1 = 0xffff8d25383bcc00\n     29: .1....6789 (bf) r2 = r9\n     30: .12...6789 (85) call bpf_map_lookup_elem#1\n     31: 0.....6789 (7b) *(u64 *)(r10 -216) = r0\n     32: 0.....6789 (55) if r0 != 0x0 goto pc+1\n     33: .......... (05) goto pc+38\n     34: ......6789 (7b) *(u64 *)(r10 -192) = r7\n     35: ......6.89 (79) r1 = *(u64 *)(r10 -184)\n     36: .1....6.89 (79) r1 = *(u64 *)(r1 +168)\n     37: .1....6.89 (15) if r1 == 0xffffffff goto pc+34\n     38: ......6.89 (79) r7 = *(u64 *)(r10 -192)\n     39: ......6789 (b7) r1 = 0\n     40: .1....6789 (6b) *(u16 *)(r7 +32146) = r1\n     41: .1....6789 (73) *(u8 *)(r7 +144) = r1\n     42: ......6789 (b7) r1 = -1\n     43: .1....6789 (63) *(u32 *)(r7 +32148) = r1\n     44: .1....6789 (63) *(u32 *)(r7 +32156) = r1\n     45: .1....6789 (63) *(u32 *)(r7 +32164) = r1\n     46: .1....6789 (63) *(u32 *)(r7 +32172) = r1\n     47: .1....6789 (63) *(u32 *)(r7 +32180) = r1\n     48: .1....6789 (63) *(u32 *)(r7 +32188) = r1\n     49: .1....6789 (63) *(u32 *)(r7 +32196) = r1\n     50: .1....6789 (63) *(u32 *)(r7 +32204) = r1\n     51: .1....6789 (7b) *(u64 *)(r7 +32224) = r1\n     52: .1....6789 (77) r1 >>= 32\n     53: .1....6789 (63) *(u32 *)(r7 +32152) = r1\n     54: .1....6789 (63) *(u32 *)(r7 +32160) = r1\n     55: .1....6789 (63) *(u32 *)(r7 +32168) = r1\n     56: .1....6789 (63) *(u32 *)(r7 +32176) = r1\n     57: .1....6789 (63) *(u32 *)(r7 +32184) = r1\n     58: .1....6789 (63) *(u32 *)(r7 +32192) = r1\n     59: .1....6789 (63) *(u32 *)(r7 +32200) = r1\n     60: .1....6789 (63) *(u32 *)(r7 +32208) = r1\n     61: ......6789 (b7) r1 = 749\n     62: .1....6789 (63) *(u32 *)(r7 +112) = r1\n     63: .1....6789 (69) r2 = *(u16 *)(r7 +134)\n     64: .12...6789 (63) *(u32 *)(r10 -176) = r1\n     65: ..2...6789 (6b) *(u16 *)(r10 -64) = r2\n     66: ......6789 (bf) r2 = r10\n     67: ..2...6789 (07) r2 += -64\n     68: ..2...6789 (18) r1 = 0xffff8d291ab72c00\n     70: .12...6789 (85) call bpf_map_lookup_elem#1\n     71: 0.....6789 (55) if r0 != 0x0 goto pc+2\n     72: .......... (b7) r0 = 0\n     73: 0......... (95) exit\n     74: 0.....6789 (bf) r2 = r10\n     75: 0.2...6789 (07) r2 += -176\n     76: 0.2...6789 (bf) r1 = r0\n     77: .12...6789 (85) call bpf_map_lookup_elem#1\n     78: 0....56789 (15) if r0 == 0x0 goto pc-7\n     79: 0....56789 (79) r1 = *(u64 *)(r0 +8)\n     80: 01...56789 (7b) *(u64 *)(r7 +32232) = r1\n     81: 0....56789 (79) r1 = *(u64 *)(r0 +0)\n     82: 01...56789 (7b) *(u64 *)(r7 +136) = r1\n     83: 01...56789 (7b) *(u64 *)(r7 +32224) = r1\n     84: 01...56789 (79) r2 = *(u64 *)(r0 +56)\n     85: 012..56789 (7b) *(u64 *)(r7 +32280) = r2\n     86: 01...56789 (79) r2 = *(u64 *)(r0 +48)\n     87: 012..56789 (7b) *(u64 *)(r7 +32272) = r2\n     88: 01...56789 (79) r2 = *(u64 *)(r0 +40)\n     89: 012..56789 (7b) *(u64 *)(r7 +32264) = r2\n     90: 01...56789 (79) r2 = *(u64 *)(r0 +32)\n     91: 012..56789 (7b) *(u64 *)(r7 +32256) = r2\n     92: 01...56789 (79) r2 = *(u64 *)(r0 +24)\n     93: 012..56789 (7b) *(u64 *)(r7 +32248) = r2\n     94: 01...56789 (79) r2 = *(u64 *)(r0 +16)\n  \n... verifier log truncated ...; prog 518: prog 518 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (7b) *(u64 *)(r10 -208) = r1\n      1: .......... (b7) r1 = 0\n      2: .1........ (63) *(u32 *)(r10 -136) = r1\n      3: .......... (bf) r2 = r10\n      4: ..2....... (07) r2 += -136\n      5: ..2....... (18) r1 = 0xffff8d2509162800\n      7: .12....... (85) call bpf_map_lookup_elem#1\n      8: 0......... (7b) *(u64 *)(r10 -184) = r0\n      9: 0......... (15) if r0 == 0x0 goto pc+3907\n     10: .......... (bf) r2 = r10\n     11: ..2....... (07) r2 += -136\n     12: ..2....... (18) r1 = 0xffff8d24dedc8c00\n     14: .12....... (85) call bpf_map_lookup_elem#1\n     15: 0......... (bf) r7 = r0\n     16: .......7.. (15) if r7 == 0x0 goto pc+3900\n     17: .......7.. (79) r9 = *(u64 *)(r10 -184)\n     18: .......7.9 (b7) r1 = -1\n     19: .1.....7.9 (63) *(u32 *)(r9 +32148) = r1\n     20: .1.....7.9 (63) *(u32 *)(r9 +32156) = r1\n     21: .1.....7.9 (63) *(u32 *)(r9 +32164) = r1\n     22: .1.....7.9 (63) *(u32 *)(r9 +32172) = r1\n     23: .1.....7.9 (63) *(u32 *)(r9 +32180) = r1\n     24: .1.....7.9 (63) *(u32 *)(r9 +32188) = r1\n     25: .1.....7.9 (63) *(u32 *)(r9 +32196) = r1\n     26: .1.....7.9 (63) *(u32 *)(r9 +32204) = r1\n     27: .1.....7.9 (77) r1 >>= 32\n     28: .1.....7.9 (63) *(u32 *)(r9 +32152) = r1\n     29: .1.....7.9 (63) *(u32 *)(r9 +32160) = r1\n     30: .1.....7.9 (63) *(u32 *)(r9 +32168) = r1\n     31: .1.....7.9 (63) *(u32 *)(r9 +32176) = r1\n     32: .1.....7.9 (63) *(u32 *)(r9 +32184) = r1\n     33: .1.....7.9 (63) *(u32 *)(r9 +32192) = r1\n     34: .1.....7.9 (63) *(u32 *)(r9 +32200) = r1\n     35: .1.....7.9 (63) *(u32 *)(r9 +32208) = r1\n     36: .......7.9 (b7) r6 = 0\n     37: ......67.9 (73) *(u8 *)(r9 +144) = r6\n     38: ......67.9 (6b) *(u16 *)(r9 +32146) = r6\n     39: .......7.9 (85) call bpf_get_current_task#35\n     40: 0......7.9 (7b) *(u64 *)(r9 +32216) = r0\n     41: .......7.9 (72) *(u8 *)(r9 +8) = 0\n     42: .......7.9 (72) *(u8 *)(r9 +9) = 0\n     43: .......7.9 (72) *(u8 *)(r9 +10) = 0\n     44: .......7.9 (72) *(u8 *)(r9 +11) = 0\n     45: .......7.9 (72) *(u8 *)(r9 +12) = 0\n     46: .......7.9 (72) *(u8 *)(r9 +13) = 0\n     47: .......7.9 (72) *(u8 *)(r9 +14) = 0\n     48: .......7.9 (72) *(u8 *)(r9 +15) = 0\n     49: .......7.9 (72) *(u8 *)(r9 +16) = 0\n     50: .......7.9 (72) *(u8 *)(r9 +17) = 0\n     51: .......7.9 (72) *(u8 *)(r9 +18) = 0\n     52: .......7.9 (72) *(u8 *)(r9 +19) = 0\n     53: .......7.9 (72) *(u8 *)(r9 +20) = 0\n     54: .......7.9 (72) *(u8 *)(r9 +21) = 0\n     55: .......7.9 (72) *(u8 *)(r9 +22) = 0\n     56: .......7.9 (72) *(u8 *)(r9 +23) = 0\n     57: .......7.9 (72) *(u8 *)(r9 +24) = 0\n     58: .......7.9 (72) *(u8 *)(r9 +25) = 0\n     59: .......7.9 (72) *(u8 *)(r9 +26) = 0\n     60: .......7.9 (72) *(u8 *)(r9 +27) = 0\n     61: .......7.9 (72) *(u8 *)(r9 +28) = 0\n     62: .......7.9 (72) *(u8 *)(r9 +29) = 0\n     63: .......7.9 (72) *(u8 *)(r9 +30) = 0\n     64: .......7.9 (72) *(u8 *)(r9 +31) = 0\n     65: .......7.9 (72) *(u8 *)(r9 +32) = 0\n     66: .......7.9 (72) *(u8 *)(r9 +33) = 0\n     67: .......7.9 (72) *(u8 *)(r9 +34) = 0\n     68: .......7.9 (72) *(u8 *)(r9 +35) = 0\n     69: .......7.9 (72) *(u8 *)(r9 +36) = 0\n     70: .......7.9 (72) *(u8 *)(r9 +37) = 0\n     71: .......7.9 (72) *(u8 *)(r9 +38) = 0\n     72: .......7.9 (72) *(u8 *)(r9 +39) = 0\n     73: .......7.9 (72) *(u8 *)(r9 +40) = 0\n     74: .......7.9 (72) *(u8 *)(r9 +41) = 0\n     75: .......7.9 (72) *(u8 *)(r9 +42) = 0\n     76: .......7.9 (72) *(u8 *)(r9 +43) = 0\n     77: .......7.9 (72) *(u8 *)(r9 +44) = 0\n     78: .......7.9 (72) *(u8 *)(r9 +45) = 0\n     79: .......7.9 (72) *(u8 *)(r9 +46) = 0\n     80: .......7.9 (72) *(u8 *)(r9 +47) = 0\n     81: .......7.9 (72) *(u8 *)(r9 +48) = 0\n     82: .......7.9 (72) *(u8 *)(r9 +49) = 0\n     83: .......7.9 (72) *(u8 *)(r9 +50) = 0\n     84: .......7.9 (72) *(u8 *)(r9 +51) = 0\n     85: .......7.9 (72) *(u8 *)(r9 +52) = 0\n     86: .......7.9 (72) *(u8 *)(r9 +53) = 0\n     87: .......7.9 (72) *(u8 *)(r9 +54) = 0\n     88: .......7.9 (72) *(u8 *)(r9 +55) = 0\n     89: .......7.9 (72) *(u8 *)(r9 +56) = 0\n     90: .......7.9 (72) *(u8 *)(r9 +57) = 0\n     91: \n... verifier log truncated ...; prog 521: prog 521 pass map_inline failed after 6 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 22: Invalid argument (os error 22)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (18) r2 = 0x1\n      2: .12....... (7b) *(u64 *)(r10 -112) = r1\n      3: .12....... (55) if r2 != 0x0 goto pc+68\n      4: .1........ (b7) r6 = 0\n      5: .1....6... (15) if r1 == 0x0 goto pc+1026\n      6: ......6... (63) *(u32 *)(r10 -8) = r6\n      7: ......6... (bf) r2 = r10\n      8: ..2...6... (07) r2 += -8\n      9: ..2...6... (18) r1 = 0xffff8d26f0d10800\n     11: .12...6... (85) call bpf_map_lookup_elem#1\n     12: 0.....6... (bf) r7 = r0\n     13: ......67.. (15) if r7 == 0x0 goto pc+1018\n     14: ......67.. (05) goto pc+0\n     15: ......67.. (b7) r1 = -1\n     16: .1....67.. (7b) *(u64 *)(r7 +16) = r1\n     17: ......67.. (18) r1 = 0x200000000\n     19: .1....67.. (7b) *(u64 *)(r7 +0) = r1\n     20: ......67.. (85) call bpf_get_smp_processor_id#8\n     21: 0.....67.. (b7) r1 = 103\n     22: 01....67.. (73) *(u8 *)(r7 +36) = r1\n     23: 0.....67.. (b7) r1 = 107\n     24: 01....67.. (73) *(u8 *)(r7 +35) = r1\n     25: 0.....67.. (b7) r1 = 97\n     26: 01....67.. (73) *(u8 *)(r7 +47) = r1\n     27: 0.....67.. (b7) r1 = 114\n     28: 01....67.. (73) *(u8 *)(r7 +46) = r1\n     29: 0.....67.. (b7) r1 = 116\n     30: 01....67.. (73) *(u8 *)(r7 +45) = r1\n     31: 0.....67.. (b7) r1 = 47\n     32: 01....67.. (73) *(u8 *)(r7 +37) = r1\n     33: 01....67.. (73) *(u8 *)(r7 +33) = r1\n     34: 01....67.. (73) *(u8 *)(r7 +44) = r1\n     35: 01....67.. (73) *(u8 *)(r7 +42) = r1\n     36: 0.....67.. (b7) r1 = 102\n     37: 01....67.. (73) *(u8 *)(r7 +41) = r1\n     38: 01....67.. (73) *(u8 *)(r7 +54) = r1\n     39: 0.....67.. (b7) r1 = 112\n     40: 01....67.. (73) *(u8 *)(r7 +34) = r1\n     41: 01....67.. (73) *(u8 *)(r7 +40) = r1\n     42: 01....67.. (73) *(u8 *)(r7 +53) = r1\n     43: 0.....67.. (b7) r1 = 98\n     44: 01....67.. (73) *(u8 *)(r7 +39) = r1\n     45: 01....67.. (73) *(u8 *)(r7 +52) = r1\n     46: 0.....67.. (b7) r1 = 46\n     47: 01....67.. (73) *(u8 *)(r7 +32) = r1\n     48: 01....67.. (73) *(u8 *)(r7 +55) = r1\n     49: 01....67.. (73) *(u8 *)(r7 +51) = r1\n     50: 0.....67.. (b7) r1 = 101\n     51: 01....67.. (73) *(u8 *)(r7 +38) = r1\n     52: 01....67.. (73) *(u8 *)(r7 +50) = r1\n     53: 01....67.. (73) *(u8 *)(r7 +49) = r1\n     54: 0.....67.. (b7) r1 = 1193\n     55: 01....67.. (63) *(u32 *)(r7 +28) = r1\n     56: 0.....67.. (63) *(u32 *)(r7 +24) = r0\n     57: ......67.. (b7) r1 = 99\n     58: .1....67.. (73) *(u8 *)(r7 +43) = r1\n     59: .1....67.. (73) *(u8 *)(r7 +48) = r1\n     60: .1....67.. (73) *(u8 *)(r7 +56) = r1\n     61: ......67.. (73) *(u8 *)(r7 +57) = r6\n     62: ......67.. (7b) *(u64 *)(r10 -88) = r6\n     63: ......67.. (b7) r1 = 1\n     64: .1....67.. (63) *(u32 *)(r10 -88) = r1\n     65: ......67.. (bf) r9 = r7\n     66: ......67.9 (07) r9 += 16\n     67: ......67.9 (18) r1 = 0x1\n     69: .1....67.9 (15) if r1 == 0x0 goto pc+158\n     70: ......67.9 (85) call bpf_ktime_get_boot_ns#125\n     71: 0.....67.9 (05) goto pc+157\n     72: .......... (b7) r6 = 0\n     73: ......6... (63) *(u32 *)(r10 -92) = r6\n     74: ......6... (bf) r2 = r10\n     75: ..2...6... (07) r2 += -92\n     76: ..2...6... (18) r1 = 0xffff8d2509162800\n     78: .12...6... (85) call bpf_map_lookup_elem#1\n     79: 0.....6... (bf) r7 = r0\n     80: ......67.. (15) if r7 == 0x0 goto pc+951\n     81: ......67.. (bf) r2 = r10\n     82: ..2...67.. (07) r2 += -92\n     83: ..2...67.. (18) r1 = 0xffff8d24dedc8c00\n     85: .12...67.. (85) call bpf_map_lookup_elem#1\n     86: 0.....67.. (bf) r8 = r0\n     87: ......678. (15) if r8 == 0x0 goto pc+944\n     88: ......678. (b7) r1 = -1\n     89: .1....678. (63) *(u32 *)(r7 +32148) = r1\n     90: .1....678. (63) *(u32 *)(r7 +32156) = r1\n     91: .1....678. (63) *(u32 *)(r7 +32164) = r1\n     92: .1....678. (63) *(u32 *)(r7 +32172) = r1\n     93: .1....678. (63) *(u32 *)(r7 +32180) = r1\n     94: .1....678. (63) *(u32 *)(r7 +32188) = r1\n     95: .1....678. (63) *(u32 *)(r7 +32196) = r1\n     96: .1....678. (63) *(u32 *)(r7 +32204) = r1\n     97: .1....678. (77) r1 >>= 32\n     98: .1....678. (63) *(u32 *)(r7 +32152) = r1\n     99: .1....678. (63) *(u32 *)(r7 +32160) = r1\n    100: .1....678. (63) *(u32 *)(\n... verifier log truncated ...; prog 626: prog 626 pass map_inline failed after 6 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 22: Invalid argument (os error 22)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r7 = r1\n      1: .......7.. (b7) r0 = 0\n      2: 0......7.. (18) r1 = 0xffffd1564031a011\n      4: 0......7.. (b4) w1 = 1\n      5: 01.....7.. (55) if r1 != 0x0 goto pc+3586\n      6: .......7.. (b7) r1 = 0\n      7: .1.....7.. (63) *(u32 *)(r10 -80) = r1\n      8: .......7.. (bf) r2 = r10\n      9: ..2....7.. (07) r2 += -80\n     10: ..2....7.. (18) r1 = 0xffff8d2509162800\n     12: .12....7.. (85) call bpf_map_lookup_elem#1\n     13: 0......7.. (bf) r8 = r0\n     14: .......78. (15) if r8 == 0x0 goto pc+148\n     15: .......78. (bf) r2 = r10\n     16: ..2....78. (07) r2 += -80\n     17: ..2....78. (18) r1 = 0xffff8d24dedc8c00\n     19: .12....78. (85) call bpf_map_lookup_elem#1\n     20: 0......78. (bf) r9 = r0\n     21: .......789 (15) if r9 == 0x0 goto pc+141\n     22: .......789 (b7) r1 = -1\n     23: .1.....789 (63) *(u32 *)(r8 +32148) = r1\n     24: .1.....789 (63) *(u32 *)(r8 +32156) = r1\n     25: .1.....789 (63) *(u32 *)(r8 +32164) = r1\n     26: .1.....789 (63) *(u32 *)(r8 +32172) = r1\n     27: .1.....789 (63) *(u32 *)(r8 +32180) = r1\n     28: .1.....789 (63) *(u32 *)(r8 +32188) = r1\n     29: .1.....789 (63) *(u32 *)(r8 +32196) = r1\n     30: .1.....789 (63) *(u32 *)(r8 +32204) = r1\n     31: .1.....789 (77) r1 >>= 32\n     32: .1.....789 (63) *(u32 *)(r8 +32152) = r1\n     33: .1.....789 (63) *(u32 *)(r8 +32160) = r1\n     34: .1.....789 (63) *(u32 *)(r8 +32168) = r1\n     35: .1.....789 (63) *(u32 *)(r8 +32176) = r1\n     36: .1.....789 (63) *(u32 *)(r8 +32184) = r1\n     37: .1.....789 (63) *(u32 *)(r8 +32192) = r1\n     38: .1.....789 (63) *(u32 *)(r8 +32200) = r1\n     39: .1.....789 (63) *(u32 *)(r8 +32208) = r1\n     40: .......789 (b7) r6 = 0\n     41: ......6789 (73) *(u8 *)(r8 +144) = r6\n     42: ......6789 (6b) *(u16 *)(r8 +32146) = r6\n     43: ......6789 (85) call bpf_get_current_task#35\n     44: 0.....6789 (7b) *(u64 *)(r8 +32216) = r0\n     45: ......6789 (7b) *(u64 *)(r8 +8) = r6\n     46: ......6789 (7b) *(u64 *)(r8 +16) = r6\n     47: ......6789 (7b) *(u64 *)(r8 +24) = r6\n     48: ......6789 (7b) *(u64 *)(r8 +32) = r6\n     49: ......6789 (7b) *(u64 *)(r8 +40) = r6\n     50: ......6789 (7b) *(u64 *)(r8 +48) = r6\n     51: ......6789 (7b) *(u64 *)(r8 +56) = r6\n     52: ......6789 (7b) *(u64 *)(r8 +64) = r6\n     53: ......6789 (7b) *(u64 *)(r8 +72) = r6\n     54: ......6789 (7b) *(u64 *)(r8 +80) = r6\n     55: ......6789 (7b) *(u64 *)(r8 +88) = r6\n     56: ......6789 (7b) *(u64 *)(r8 +96) = r6\n     57: ......6789 (7b) *(u64 *)(r8 +104) = r6\n     58: .......789 (85) call bpf_get_current_pid_tgid#14\n     59: 0......789 (b7) r1 = 788\n     60: 01.....789 (63) *(u32 *)(r8 +112) = r1\n     61: 0......789 (63) *(u32 *)(r8 +40) = r0\n     62: 0......789 (77) r0 >>= 32\n     63: 0......789 (63) *(u32 *)(r8 +36) = r0\n     64: .......789 (18) r1 = 0x1\n     66: .1.....789 (15) if r1 == 0x0 goto pc+2\n     67: .......789 (85) call bpf_ktime_get_boot_ns#125\n     68: 0......789 (05) goto pc+1\n     69: .......789 (85) call bpf_ktime_get_ns#5\n     70: 0......789 (7b) *(u64 *)(r8 +0) = r0\n     71: .......789 (85) call bpf_get_smp_processor_id#8\n     72: 0......789 (6b) *(u16 *)(r8 +132) = r0\n     73: .......789 (85) call bpf_get_current_task#35\n     74: 0......789 (bf) r6 = r0\n     75: ......6789 (b7) r1 = 44\n     76: .1....6789 (bf) r3 = r6\n     77: .1.3..6789 (0f) r3 += r1\n     78: ...3..6789 (bf) r1 = r10\n     79: .1.3..6789 (07) r1 += -72\n     80: .1.3..6789 (b7) r2 = 4\n     81: .123..6789 (85) call bpf_probe_read_kernel#113\n     82: ......6789 (18) r1 = 0xffffffff\n     84: .1....6789 (61) r2 = *(u32 *)(r10 -72)\n     85: .12...6789 (57) r2 &= 2097152\n     86: .12...6789 (55) if r2 != 0x0 goto pc+56\n     87: ......6789 (18) r1 = 0x1\n     89: .1....6789 (15) if r1 == 0x0 goto pc+8\n     90: ......6789 (18) r1 = 0x1\n     92: .1....6789 (15) if r1 == 0x0 goto pc+5\n     93: ......6789 (85) call bpf_get_current_task_btf#158\n     94: 0.....6789 (bf) r1 = r0\n     95: .1....6789 (85) call bpf_task_pt_regs#175\n     96: 0.....6789 (bf) r3 = r0\n     97: ...3..6789 (05) goto pc+15\n     98: ......6789 (85) call\n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 517 pass bulk_memory failed after 4 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nfunc#1 @2303\nLive regs before insn:\n      0: .1........ (bf) r8 = r1\n      1: ........8. (b7) r1 = 0\n      2: .1......8. (63) *(u32 *)(r10 -176) = r1\n      3: ........8. (bf) r2 = r10\n      4: ..2.....8. (07) r2 += -176\n      5: ..2.....8. (18) r1 = 0xffff8d2509162800\n      7: .12.....8. (85) call bpf_map_lookup_elem#1\n      8: 0.......8. (bf) r7 = r0\n      9: .......78. (15) if r7 == 0x0 goto pc+23\n     10: .......78. (bf) r2 = r10\n     11: ..2....78. (07) r2 += -176\n     12: ..2....78. (18) r1 = 0xffff8d24dedc8c00\n     14: .12....78. (85) call bpf_map_lookup_elem#1\n     15: 0......78. (7b) *(u64 *)(r10 -208) = r0\n     16: 0......78. (15) if r0 == 0x0 goto pc+16\n     17: .......78. (bf) r6 = r7\n     18: ......678. (07) r6 += 40\n     19: ......678. (18) r1 = 0xffff8d24927c1800\n     21: .1....678. (bf) r2 = r6\n     22: .12...678. (85) call bpf_map_lookup_elem#1\n     23: 0.....678. (7b) *(u64 *)(r10 -184) = r0\n     24: 0.....678. (15) if r0 == 0x0 goto pc+8\n     25: ......678. (bf) r9 = r7\n     26: ......6789 (07) r9 += 36\n     27: ......6789 (18) r1 = 0xffff8d25383bcc00\n     29: .1....6789 (bf) r2 = r9\n     30: .12...6789 (85) call bpf_map_lookup_elem#1\n     31: 0.....6789 (7b) *(u64 *)(r10 -216) = r0\n     32: 0.....6789 (55) if r0 != 0x0 goto pc+1\n     33: .......... (05) goto pc+38\n     34: ......6789 (7b) *(u64 *)(r10 -192) = r7\n     35: ......6.89 (79) r1 = *(u64 *)(r10 -184)\n     36: .1....6.89 (79) r1 = *(u64 *)(r1 +168)\n     37: .1....6.89 (15) if r1 == 0xffffffff goto pc+34\n     38: ......6.89 (79) r7 = *(u64 *)(r10 -192)\n     39: ......6789 (b7) r1 = 0\n     40: .1....6789 (6b) *(u16 *)(r7 +32146) = r1\n     41: .1....6789 (73) *(u8 *)(r7 +144) = r1\n     42: ......6789 (b7) r1 = -1\n     43: .1....6789 (63) *(u32 *)(r7 +32148) = r1\n     44: .1....6789 (63) *(u32 *)(r7 +32156) = r1\n     45: .1....6789 (63) *(u32 *)(r7 +32164) = r1\n     46: .1....6789 (63) *(u32 *)(r7 +32172) = r1\n     47: .1....6789 (63) *(u32 *)(r7 +32180) = r1\n     48: .1....6789 (63) *(u32 *)(r7 +32188) = r1\n     49: .1....6789 (63) *(u32 *)(r7 +32196) = r1\n     50: .1....6789 (63) *(u32 *)(r7 +32204) = r1\n     51: .1....6789 (7b) *(u64 *)(r7 +32224) = r1\n     52: .1....6789 (77) r1 >>= 32\n     53: .1....6789 (63) *(u32 *)(r7 +32152) = r1\n     54: .1....6789 (63) *(u32 *)(r7 +32160) = r1\n     55: .1....6789 (63) *(u32 *)(r7 +32168) = r1\n     56: .1....6789 (63) *(u32 *)(r7 +32176) = r1\n     57: .1....6789 (63) *(u32 *)(r7 +32184) = r1\n     58: .1....6789 (63) *(u32 *)(r7 +32192) = r1\n     59: .1....6789 (63) *(u32 *)(r7 +32200) = r1\n     60: .1....6789 (63) *(u32 *)(r7 +32208) = r1\n     61: ......6789 (b7) r1 = 749\n     62: .1....6789 (63) *(u32 *)(r7 +112) = r1\n     63: .1....6789 (69) r2 = *(u16 *)(r7 +134)\n     64: .12...6789 (63) *(u32 *)(r10 -176) = r1\n     65: ..2...6789 (6b) *(u16 *)(r10 -64) = r2\n     66: ......6789 (bf) r2 = r10\n     67: ..2...6789 (07) r2 += -64\n     68: ..2...6789 (18) r1 = 0xffff8d291ab72c00\n     70: .12...6789 (85) call bpf_map_lookup_elem#1\n     71: 0.....6789 (55) if r0 != 0x0 goto pc+2\n     72: .......... (b7) r0 = 0\n     73: 0......... (95) exit\n     74: 0.....6789 (bf) r2 = r10\n     75: 0.2...6789 (07) r2 += -176\n     76: 0.2...6789 (bf) r1 = r0\n     77: .12...6789 (85) call bpf_map_lookup_elem#1\n     78: 0....56789 (15) if r0 == 0x0 goto pc-7\n     79: 0....56789 (79) r1 = *(u64 *)(r0 +8)\n     80: 01...56789 (7b) *(u64 *)(r7 +32232) = r1\n     81: 0....56789 (79) r1 = *(u64 *)(r0 +0)\n     82: 01...56789 (7b) *(u64 *)(r7 +136) = r1\n     83: 01...56789 (7b) *(u64 *)(r7 +32224) = r1\n     84: 01...56789 (79) r2 = *(u64 *)(r0 +56)\n     85: 012..56789 (7b) *(u64 *)(r7 +32280) = r2\n     86: 01...56789 (79) r2 = *(u64 *)(r0 +48)\n     87: 012..56789 (7b) *(u64 *)(r7 +32272) = r2\n     88: 01...56789 (79) r2 = *(u64 *)(r0 +40)\n     89: 012..56789 (7b) *(u64 *)(r7 +32264) = r2\n     90: 01...56789 (79) r2 = *(u64 *)(r0 +32)\n     91: 012..56789 (7b) *(u64 *)(r7 +32256) = r2\n     92: 01...56789 (79) r2 = *(u64 *)(r0 +24)\n     93: 012..56789 (7b) *(u64 *)(r7 +32248) = r2\n     94: 01...56789 (79) r2 = *(u64 *)(r0 +16)\n  \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 517
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 518 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (7b) *(u64 *)(r10 -208) = r1\n      1: .......... (b7) r1 = 0\n      2: .1........ (63) *(u32 *)(r10 -136) = r1\n      3: .......... (bf) r2 = r10\n      4: ..2....... (07) r2 += -136\n      5: ..2....... (18) r1 = 0xffff8d2509162800\n      7: .12....... (85) call bpf_map_lookup_elem#1\n      8: 0......... (7b) *(u64 *)(r10 -184) = r0\n      9: 0......... (15) if r0 == 0x0 goto pc+3907\n     10: .......... (bf) r2 = r10\n     11: ..2....... (07) r2 += -136\n     12: ..2....... (18) r1 = 0xffff8d24dedc8c00\n     14: .12....... (85) call bpf_map_lookup_elem#1\n     15: 0......... (bf) r7 = r0\n     16: .......7.. (15) if r7 == 0x0 goto pc+3900\n     17: .......7.. (79) r9 = *(u64 *)(r10 -184)\n     18: .......7.9 (b7) r1 = -1\n     19: .1.....7.9 (63) *(u32 *)(r9 +32148) = r1\n     20: .1.....7.9 (63) *(u32 *)(r9 +32156) = r1\n     21: .1.....7.9 (63) *(u32 *)(r9 +32164) = r1\n     22: .1.....7.9 (63) *(u32 *)(r9 +32172) = r1\n     23: .1.....7.9 (63) *(u32 *)(r9 +32180) = r1\n     24: .1.....7.9 (63) *(u32 *)(r9 +32188) = r1\n     25: .1.....7.9 (63) *(u32 *)(r9 +32196) = r1\n     26: .1.....7.9 (63) *(u32 *)(r9 +32204) = r1\n     27: .1.....7.9 (77) r1 >>= 32\n     28: .1.....7.9 (63) *(u32 *)(r9 +32152) = r1\n     29: .1.....7.9 (63) *(u32 *)(r9 +32160) = r1\n     30: .1.....7.9 (63) *(u32 *)(r9 +32168) = r1\n     31: .1.....7.9 (63) *(u32 *)(r9 +32176) = r1\n     32: .1.....7.9 (63) *(u32 *)(r9 +32184) = r1\n     33: .1.....7.9 (63) *(u32 *)(r9 +32192) = r1\n     34: .1.....7.9 (63) *(u32 *)(r9 +32200) = r1\n     35: .1.....7.9 (63) *(u32 *)(r9 +32208) = r1\n     36: .......7.9 (b7) r6 = 0\n     37: ......67.9 (73) *(u8 *)(r9 +144) = r6\n     38: ......67.9 (6b) *(u16 *)(r9 +32146) = r6\n     39: .......7.9 (85) call bpf_get_current_task#35\n     40: 0......7.9 (7b) *(u64 *)(r9 +32216) = r0\n     41: .......7.9 (72) *(u8 *)(r9 +8) = 0\n     42: .......7.9 (72) *(u8 *)(r9 +9) = 0\n     43: .......7.9 (72) *(u8 *)(r9 +10) = 0\n     44: .......7.9 (72) *(u8 *)(r9 +11) = 0\n     45: .......7.9 (72) *(u8 *)(r9 +12) = 0\n     46: .......7.9 (72) *(u8 *)(r9 +13) = 0\n     47: .......7.9 (72) *(u8 *)(r9 +14) = 0\n     48: .......7.9 (72) *(u8 *)(r9 +15) = 0\n     49: .......7.9 (72) *(u8 *)(r9 +16) = 0\n     50: .......7.9 (72) *(u8 *)(r9 +17) = 0\n     51: .......7.9 (72) *(u8 *)(r9 +18) = 0\n     52: .......7.9 (72) *(u8 *)(r9 +19) = 0\n     53: .......7.9 (72) *(u8 *)(r9 +20) = 0\n     54: .......7.9 (72) *(u8 *)(r9 +21) = 0\n     55: .......7.9 (72) *(u8 *)(r9 +22) = 0\n     56: .......7.9 (72) *(u8 *)(r9 +23) = 0\n     57: .......7.9 (72) *(u8 *)(r9 +24) = 0\n     58: .......7.9 (72) *(u8 *)(r9 +25) = 0\n     59: .......7.9 (72) *(u8 *)(r9 +26) = 0\n     60: .......7.9 (72) *(u8 *)(r9 +27) = 0\n     61: .......7.9 (72) *(u8 *)(r9 +28) = 0\n     62: .......7.9 (72) *(u8 *)(r9 +29) = 0\n     63: .......7.9 (72) *(u8 *)(r9 +30) = 0\n     64: .......7.9 (72) *(u8 *)(r9 +31) = 0\n     65: .......7.9 (72) *(u8 *)(r9 +32) = 0\n     66: .......7.9 (72) *(u8 *)(r9 +33) = 0\n     67: .......7.9 (72) *(u8 *)(r9 +34) = 0\n     68: .......7.9 (72) *(u8 *)(r9 +35) = 0\n     69: .......7.9 (72) *(u8 *)(r9 +36) = 0\n     70: .......7.9 (72) *(u8 *)(r9 +37) = 0\n     71: .......7.9 (72) *(u8 *)(r9 +38) = 0\n     72: .......7.9 (72) *(u8 *)(r9 +39) = 0\n     73: .......7.9 (72) *(u8 *)(r9 +40) = 0\n     74: .......7.9 (72) *(u8 *)(r9 +41) = 0\n     75: .......7.9 (72) *(u8 *)(r9 +42) = 0\n     76: .......7.9 (72) *(u8 *)(r9 +43) = 0\n     77: .......7.9 (72) *(u8 *)(r9 +44) = 0\n     78: .......7.9 (72) *(u8 *)(r9 +45) = 0\n     79: .......7.9 (72) *(u8 *)(r9 +46) = 0\n     80: .......7.9 (72) *(u8 *)(r9 +47) = 0\n     81: .......7.9 (72) *(u8 *)(r9 +48) = 0\n     82: .......7.9 (72) *(u8 *)(r9 +49) = 0\n     83: .......7.9 (72) *(u8 *)(r9 +50) = 0\n     84: .......7.9 (72) *(u8 *)(r9 +51) = 0\n     85: .......7.9 (72) *(u8 *)(r9 +52) = 0\n     86: .......7.9 (72) *(u8 *)(r9 +53) = 0\n     87: .......7.9 (72) *(u8 *)(r9 +54) = 0\n     88: .......7.9 (72) *(u8 *)(r9 +55) = 0\n     89: .......7.9 (72) *(u8 *)(r9 +56) = 0\n     90: .......7.9 (72) *(u8 *)(r9 +57) = 0\n     91: \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 518
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 521 pass map_inline failed after 6 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 22: Invalid argument (os error 22)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (18) r2 = 0x1\n      2: .12....... (7b) *(u64 *)(r10 -112) = r1\n      3: .12....... (55) if r2 != 0x0 goto pc+68\n      4: .1........ (b7) r6 = 0\n      5: .1....6... (15) if r1 == 0x0 goto pc+1026\n      6: ......6... (63) *(u32 *)(r10 -8) = r6\n      7: ......6... (bf) r2 = r10\n      8: ..2...6... (07) r2 += -8\n      9: ..2...6... (18) r1 = 0xffff8d26f0d10800\n     11: .12...6... (85) call bpf_map_lookup_elem#1\n     12: 0.....6... (bf) r7 = r0\n     13: ......67.. (15) if r7 == 0x0 goto pc+1018\n     14: ......67.. (05) goto pc+0\n     15: ......67.. (b7) r1 = -1\n     16: .1....67.. (7b) *(u64 *)(r7 +16) = r1\n     17: ......67.. (18) r1 = 0x200000000\n     19: .1....67.. (7b) *(u64 *)(r7 +0) = r1\n     20: ......67.. (85) call bpf_get_smp_processor_id#8\n     21: 0.....67.. (b7) r1 = 103\n     22: 01....67.. (73) *(u8 *)(r7 +36) = r1\n     23: 0.....67.. (b7) r1 = 107\n     24: 01....67.. (73) *(u8 *)(r7 +35) = r1\n     25: 0.....67.. (b7) r1 = 97\n     26: 01....67.. (73) *(u8 *)(r7 +47) = r1\n     27: 0.....67.. (b7) r1 = 114\n     28: 01....67.. (73) *(u8 *)(r7 +46) = r1\n     29: 0.....67.. (b7) r1 = 116\n     30: 01....67.. (73) *(u8 *)(r7 +45) = r1\n     31: 0.....67.. (b7) r1 = 47\n     32: 01....67.. (73) *(u8 *)(r7 +37) = r1\n     33: 01....67.. (73) *(u8 *)(r7 +33) = r1\n     34: 01....67.. (73) *(u8 *)(r7 +44) = r1\n     35: 01....67.. (73) *(u8 *)(r7 +42) = r1\n     36: 0.....67.. (b7) r1 = 102\n     37: 01....67.. (73) *(u8 *)(r7 +41) = r1\n     38: 01....67.. (73) *(u8 *)(r7 +54) = r1\n     39: 0.....67.. (b7) r1 = 112\n     40: 01....67.. (73) *(u8 *)(r7 +34) = r1\n     41: 01....67.. (73) *(u8 *)(r7 +40) = r1\n     42: 01....67.. (73) *(u8 *)(r7 +53) = r1\n     43: 0.....67.. (b7) r1 = 98\n     44: 01....67.. (73) *(u8 *)(r7 +39) = r1\n     45: 01....67.. (73) *(u8 *)(r7 +52) = r1\n     46: 0.....67.. (b7) r1 = 46\n     47: 01....67.. (73) *(u8 *)(r7 +32) = r1\n     48: 01....67.. (73) *(u8 *)(r7 +55) = r1\n     49: 01....67.. (73) *(u8 *)(r7 +51) = r1\n     50: 0.....67.. (b7) r1 = 101\n     51: 01....67.. (73) *(u8 *)(r7 +38) = r1\n     52: 01....67.. (73) *(u8 *)(r7 +50) = r1\n     53: 01....67.. (73) *(u8 *)(r7 +49) = r1\n     54: 0.....67.. (b7) r1 = 1193\n     55: 01....67.. (63) *(u32 *)(r7 +28) = r1\n     56: 0.....67.. (63) *(u32 *)(r7 +24) = r0\n     57: ......67.. (b7) r1 = 99\n     58: .1....67.. (73) *(u8 *)(r7 +43) = r1\n     59: .1....67.. (73) *(u8 *)(r7 +48) = r1\n     60: .1....67.. (73) *(u8 *)(r7 +56) = r1\n     61: ......67.. (73) *(u8 *)(r7 +57) = r6\n     62: ......67.. (7b) *(u64 *)(r10 -88) = r6\n     63: ......67.. (b7) r1 = 1\n     64: .1....67.. (63) *(u32 *)(r10 -88) = r1\n     65: ......67.. (bf) r9 = r7\n     66: ......67.9 (07) r9 += 16\n     67: ......67.9 (18) r1 = 0x1\n     69: .1....67.9 (15) if r1 == 0x0 goto pc+158\n     70: ......67.9 (85) call bpf_ktime_get_boot_ns#125\n     71: 0.....67.9 (05) goto pc+157\n     72: .......... (b7) r6 = 0\n     73: ......6... (63) *(u32 *)(r10 -92) = r6\n     74: ......6... (bf) r2 = r10\n     75: ..2...6... (07) r2 += -92\n     76: ..2...6... (18) r1 = 0xffff8d2509162800\n     78: .12...6... (85) call bpf_map_lookup_elem#1\n     79: 0.....6... (bf) r7 = r0\n     80: ......67.. (15) if r7 == 0x0 goto pc+951\n     81: ......67.. (bf) r2 = r10\n     82: ..2...67.. (07) r2 += -92\n     83: ..2...67.. (18) r1 = 0xffff8d24dedc8c00\n     85: .12...67.. (85) call bpf_map_lookup_elem#1\n     86: 0.....67.. (bf) r8 = r0\n     87: ......678. (15) if r8 == 0x0 goto pc+944\n     88: ......678. (b7) r1 = -1\n     89: .1....678. (63) *(u32 *)(r7 +32148) = r1\n     90: .1....678. (63) *(u32 *)(r7 +32156) = r1\n     91: .1....678. (63) *(u32 *)(r7 +32164) = r1\n     92: .1....678. (63) *(u32 *)(r7 +32172) = r1\n     93: .1....678. (63) *(u32 *)(r7 +32180) = r1\n     94: .1....678. (63) *(u32 *)(r7 +32188) = r1\n     95: .1....678. (63) *(u32 *)(r7 +32196) = r1\n     96: .1....678. (63) *(u32 *)(r7 +32204) = r1\n     97: .1....678. (77) r1 >>= 32\n     98: .1....678. (63) *(u32 *)(r7 +32152) = r1\n     99: .1....678. (63) *(u32 *)(r7 +32160) = r1\n    100: .1....678. (63) *(u32 *)(\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 521
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 626 pass map_inline failed after 6 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 22: Invalid argument (os error 22)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r7 = r1\n      1: .......7.. (b7) r0 = 0\n      2: 0......7.. (18) r1 = 0xffffd1564031a011\n      4: 0......7.. (b4) w1 = 1\n      5: 01.....7.. (55) if r1 != 0x0 goto pc+3586\n      6: .......7.. (b7) r1 = 0\n      7: .1.....7.. (63) *(u32 *)(r10 -80) = r1\n      8: .......7.. (bf) r2 = r10\n      9: ..2....7.. (07) r2 += -80\n     10: ..2....7.. (18) r1 = 0xffff8d2509162800\n     12: .12....7.. (85) call bpf_map_lookup_elem#1\n     13: 0......7.. (bf) r8 = r0\n     14: .......78. (15) if r8 == 0x0 goto pc+148\n     15: .......78. (bf) r2 = r10\n     16: ..2....78. (07) r2 += -80\n     17: ..2....78. (18) r1 = 0xffff8d24dedc8c00\n     19: .12....78. (85) call bpf_map_lookup_elem#1\n     20: 0......78. (bf) r9 = r0\n     21: .......789 (15) if r9 == 0x0 goto pc+141\n     22: .......789 (b7) r1 = -1\n     23: .1.....789 (63) *(u32 *)(r8 +32148) = r1\n     24: .1.....789 (63) *(u32 *)(r8 +32156) = r1\n     25: .1.....789 (63) *(u32 *)(r8 +32164) = r1\n     26: .1.....789 (63) *(u32 *)(r8 +32172) = r1\n     27: .1.....789 (63) *(u32 *)(r8 +32180) = r1\n     28: .1.....789 (63) *(u32 *)(r8 +32188) = r1\n     29: .1.....789 (63) *(u32 *)(r8 +32196) = r1\n     30: .1.....789 (63) *(u32 *)(r8 +32204) = r1\n     31: .1.....789 (77) r1 >>= 32\n     32: .1.....789 (63) *(u32 *)(r8 +32152) = r1\n     33: .1.....789 (63) *(u32 *)(r8 +32160) = r1\n     34: .1.....789 (63) *(u32 *)(r8 +32168) = r1\n     35: .1.....789 (63) *(u32 *)(r8 +32176) = r1\n     36: .1.....789 (63) *(u32 *)(r8 +32184) = r1\n     37: .1.....789 (63) *(u32 *)(r8 +32192) = r1\n     38: .1.....789 (63) *(u32 *)(r8 +32200) = r1\n     39: .1.....789 (63) *(u32 *)(r8 +32208) = r1\n     40: .......789 (b7) r6 = 0\n     41: ......6789 (73) *(u8 *)(r8 +144) = r6\n     42: ......6789 (6b) *(u16 *)(r8 +32146) = r6\n     43: ......6789 (85) call bpf_get_current_task#35\n     44: 0.....6789 (7b) *(u64 *)(r8 +32216) = r0\n     45: ......6789 (7b) *(u64 *)(r8 +8) = r6\n     46: ......6789 (7b) *(u64 *)(r8 +16) = r6\n     47: ......6789 (7b) *(u64 *)(r8 +24) = r6\n     48: ......6789 (7b) *(u64 *)(r8 +32) = r6\n     49: ......6789 (7b) *(u64 *)(r8 +40) = r6\n     50: ......6789 (7b) *(u64 *)(r8 +48) = r6\n     51: ......6789 (7b) *(u64 *)(r8 +56) = r6\n     52: ......6789 (7b) *(u64 *)(r8 +64) = r6\n     53: ......6789 (7b) *(u64 *)(r8 +72) = r6\n     54: ......6789 (7b) *(u64 *)(r8 +80) = r6\n     55: ......6789 (7b) *(u64 *)(r8 +88) = r6\n     56: ......6789 (7b) *(u64 *)(r8 +96) = r6\n     57: ......6789 (7b) *(u64 *)(r8 +104) = r6\n     58: .......789 (85) call bpf_get_current_pid_tgid#14\n     59: 0......789 (b7) r1 = 788\n     60: 01.....789 (63) *(u32 *)(r8 +112) = r1\n     61: 0......789 (63) *(u32 *)(r8 +40) = r0\n     62: 0......789 (77) r0 >>= 32\n     63: 0......789 (63) *(u32 *)(r8 +36) = r0\n     64: .......789 (18) r1 = 0x1\n     66: .1.....789 (15) if r1 == 0x0 goto pc+2\n     67: .......789 (85) call bpf_ktime_get_boot_ns#125\n     68: 0......789 (05) goto pc+1\n     69: .......789 (85) call bpf_ktime_get_ns#5\n     70: 0......789 (7b) *(u64 *)(r8 +0) = r0\n     71: .......789 (85) call bpf_get_smp_processor_id#8\n     72: 0......789 (6b) *(u16 *)(r8 +132) = r0\n     73: .......789 (85) call bpf_get_current_task#35\n     74: 0......789 (bf) r6 = r0\n     75: ......6789 (b7) r1 = 44\n     76: .1....6789 (bf) r3 = r6\n     77: .1.3..6789 (0f) r3 += r1\n     78: ...3..6789 (bf) r1 = r10\n     79: .1.3..6789 (07) r1 += -72\n     80: .1.3..6789 (b7) r2 = 4\n     81: .123..6789 (85) call bpf_probe_read_kernel#113\n     82: ......6789 (18) r1 = 0xffffffff\n     84: .1....6789 (61) r2 = *(u32 *)(r10 -72)\n     85: .12...6789 (57) r2 &= 2097152\n     86: .12...6789 (55) if r2 != 0x0 goto pc+56\n     87: ......6789 (18) r1 = 0x1\n     89: .1....6789 (15) if r1 == 0x0 goto pc+8\n     90: ......6789 (18) r1 = 0x1\n     92: .1....6789 (15) if r1 == 0x0 goto pc+5\n     93: ......6789 (85) call bpf_get_current_task_btf#158\n     94: 0.....6789 (bf) r1 = r0\n     95: .1....6789 (85) call bpf_task_pt_regs#175\n     96: 0.....6789 (bf) r3 = r0\n     97: ...3..6789 (05) goto pc+15\n     98: ......6789 (85) call\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 626
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 154,
          "not_applied": 4,
          "requested": 158
        }
      },
      "runner": "tracee",
      "selected_workload": "stress_ng_os_io_network",
      "status": "ok"
    },
    {
      "app": "bpftrace/capable",
      "baseline": {
        "bpf": {
          "657": {
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 657,
            "name": "cap_capable",
            "run_cnt_delta": 1750914,
            "run_time_ns_delta": 331051018,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0476330070000586,
            "ops_per_sec": 4942593.470211655,
            "ops_total": 15063211.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [1527] setting to a 3 secs run per stressor\nstress-ng: info:  [1527] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 dup, 4 kill, 4 sigfd, 4 signal, 4 pty, 4 itimer, 4 timerfd\nstress-ng: info:  [1527] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [1527] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1527]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1527] cap             4997356      3.00      1.19      4.37   1663434.89      898783.70\nstress-ng: metrc: [1527] eventfd          990196      3.00      0.91      3.78    329897.25      210948.80\nstress-ng: metrc: [1527] get                5622      3.00      0.07      1.17      1872.91        4526.97\nstress-ng: metrc: [1527] prctl              9542      3.00      2.12      1.76      3178.69        2459.78\nstress-ng: metrc: [1527] set               60017      3.00      0.21      2.54     20001.26       21777.13\nstress-ng: metrc: [1527] dup                4146      3.00      0.97      0.92      1382.01        2197.06\nstress-ng: metrc: [1527] kill              65166      3.00      0.08      3.69     21710.25       17273.50\nstress-ng: metrc: [1527] sigfd           7523404      3.00      0.94      4.34   2507536.74     1425237.22\nstress-ng: metrc: [1527] signal                0      3.00      0.36      1.42         0.00           0.00\nstress-ng: metrc: [1527] pty                 145      3.00      0.11      4.50        48.28          31.47\nstress-ng: metrc: [1527] itimer              641      3.00      1.60      3.93       213.67         115.90\nstress-ng: metrc: [1527] timerfd         1406976      3.00      0.91      4.00    468617.03      286491.42\nstress-ng: info:  [1527] skipped: 0\nstress-ng: info:  [1527] passed: 48: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4)\nstress-ng: info:  [1527] failed: 0\nstress-ng: info:  [1527] metrics untrustworthy: 0\nstress-ng: info:  [1527] successful run completed in 3.04 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "657": {
            "bytes_jited": 772,
            "bytes_xlated": 1376,
            "id": 657,
            "name": "cap_capable",
            "run_cnt_delta": 1791586,
            "run_time_ns_delta": 320226104,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.049097010999958,
            "ops_per_sec": 4993817.167859278,
            "ops_total": 15226633.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [4786] setting to a 3 secs run per stressor\nstress-ng: info:  [4786] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 dup, 4 kill, 4 sigfd, 4 signal, 4 pty, 4 itimer, 4 timerfd\nstress-ng: info:  [4786] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4786] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4786]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4786] cap             6407240      3.00      1.82      5.78   2134711.96      842546.71\nstress-ng: metrc: [4786] eventfd          934149      3.00      0.76      3.36    311294.04      226349.25\nstress-ng: metrc: [4786] get                6716      3.00      0.13      1.08      2237.97        5519.47\nstress-ng: metrc: [4786] prctl              8217      3.00      1.76      1.53      2736.87        2496.85\nstress-ng: metrc: [4786] set               77608      3.00      0.32      2.72     25868.17       25553.45\nstress-ng: metrc: [4786] dup                3489      3.00      0.78      0.81      1162.31        2193.64\nstress-ng: metrc: [4786] kill              64600      3.00      0.11      3.36     21511.28       18646.84\nstress-ng: metrc: [4786] sigfd           6622341      3.01      1.35      5.39   2201300.09      982034.24\nstress-ng: metrc: [4786] signal                0      3.00      0.25      0.73         0.00           0.00\nstress-ng: metrc: [4786] pty               18374      3.01      0.29      4.11      6105.28        4177.68\nstress-ng: metrc: [4786] itimer              507      3.00      1.19      2.96       169.00         122.29\nstress-ng: metrc: [4786] timerfd         1083392      3.00      0.37      5.08    360664.43      198955.27\nstress-ng: info:  [4786] skipped: 0\nstress-ng: info:  [4786] passed: 48: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4)\nstress-ng: info:  [4786] failed: 0\nstress-ng: info:  [4786] metrics untrustworthy: 0\nstress-ng: info:  [4786] successful run completed in 3.04 secs"
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
          "prefetch",
          "map_inline"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bpftrace",
      "selected_workload": "stress_ng_os",
      "status": "ok"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline": {
        "bpf": {
          "664": {
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 664,
            "name": "block_io_start",
            "run_cnt_delta": 1178158,
            "run_time_ns_delta": 548632642,
            "type": "tracepoint"
          },
          "665": {
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 665,
            "name": "block_io_done",
            "run_cnt_delta": 1178173,
            "run_time_ns_delta": 1065527244,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.388851363999947,
            "ops_per_sec": 292801.7296117829,
            "ops_total": 1577865.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.099436,\n        \"1000\" : 4.400878\n      },\n      \"latency_us\" : {\n        \"2\" : 41.965887,\n        \"4\" : 2.840162,\n        \"10\" : 4.417663,\n        \"20\" : 40.799864,\n        \"50\" : 2.522526,\n        \"100\" : 2.142329,\n        \"250\" : 0.744118,\n        \"500\" : 0.062052,\n        \"750\" : 0.010000,\n        \"1000\" : 0.010000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.010000,\n        \"4\" : 0.010000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "664": {
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 664,
            "name": "block_io_start",
            "run_cnt_delta": 1163753,
            "run_time_ns_delta": 536064051,
            "type": "tracepoint"
          },
          "665": {
            "bytes_jited": 943,
            "bytes_xlated": 1640,
            "id": 665,
            "name": "block_io_done",
            "run_cnt_delta": 1163768,
            "run_time_ns_delta": 1065418508,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.364075572999809,
            "ops_per_sec": 291922.0616282797,
            "ops_total": 1565892.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.010000,\n        \"1000\" : 2.911341\n      },\n      \"latency_us\" : {\n        \"2\" : 43.323732,\n        \"4\" : 3.003792,\n        \"10\" : 4.518932,\n        \"20\" : 41.052677,\n        \"50\" : 2.231578,\n        \"100\" : 2.109582,\n        \"250\" : 0.786732,\n        \"500\" : 0.056031,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
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
          "prefetch",
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
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline": {
        "bpf": {
          "672": {
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 672,
            "name": "1",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 5580,
            "type": "perf_event"
          },
          "673": {
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 673,
            "name": "vfs_create",
            "run_cnt_delta": 4632728,
            "run_time_ns_delta": 179031088,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.3158300150003015,
            "ops_per_sec": 1372901.801179813,
            "ops_total": 4552309.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [1357] setting to a 3 secs run per stressor\nstress-ng: info:  [1357] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime, 4 link, 4 symlink, 4 mknod, 4 fcntl\nstress-ng: info:  [1357] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [1457] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [1377] dentry: 281406 dentries allocated\nstress-ng: metrc: [1357] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1357]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1357] access            33280      3.04      0.58      3.53     10943.99        8082.30\nstress-ng: metrc: [1357] chdir               217      3.19      0.70      4.85        67.92          39.06\nstress-ng: metrc: [1357] chmod               281      3.01      0.03      0.10        93.46        2194.59\nstress-ng: metrc: [1357] chown               331      3.07      0.01      0.05       107.83        5425.25\nstress-ng: metrc: [1357] dentry            25164      3.11      0.06      0.80      8086.78       29162.13\nstress-ng: metrc: [1357] dir               32768      3.25      0.20      3.77     10093.89        8248.40\nstress-ng: metrc: [1357] dirmany           36068      3.05      0.04      0.90     11830.99       38389.57\nstress-ng: metrc: [1357] fallocate             2      3.04      0.02      0.01         0.66          68.35\nstress-ng: metrc: [1357] file-ioctl       167274      3.02      0.24      1.92     55471.28       77200.38\nstress-ng: metrc: [1357] filename           9052      3.04      0.16      1.89      2974.23        4410.15\nstress-ng: metrc: [1357] flock           2786437      3.07      0.54      0.80    906187.03     2071982.28\nstress-ng: metrc: [1357] fpunch             1446      3.07      0.00      2.22       471.19         651.12\nstress-ng: metrc: [1357] fstat              8348      3.01      0.68      2.18      2775.35        2916.59\nstress-ng: metrc: [1357] getdent         1051097      3.00      0.44      7.31    349930.58      135629.46\nstress-ng: metrc: [1357] hdd               40697      3.07      0.64      0.73     13266.63       29711.83\nstress-ng: metrc: [1357] inotify               9      3.05      0.01      0.02         2.95         264.05\nstress-ng: metrc: [1357] open              14336      3.07      0.00      0.24      4662.26       59524.25\nstress-ng: metrc: [1357] rename            87202      3.06      0.06      0.61     28470.43      129126.55\nstress-ng: metrc: [1357] touch            117221      3.08      0.10      3.46     38107.87       32973.47\nstress-ng: metrc: [1357] utime            116109      3.04      0.15      2.06     38161.43       52612.38\nstress-ng: metrc: [1357] link                  9      3.07      0.14      1.03         2.93           7.70\nstress-ng: metrc: [1357] symlink               4      3.14      0.09      1.18         1.27           3.15\nstress-ng: metrc: [1357] mknod               108      3.08      0.02      0.02        35.09        2792.65\nstress-ng: metrc: [1357] fcntl             24849      3.04      0.03      0.42      8181.73       55782.79\nstress-ng: info:  [1357] skipped: 0\nstress-ng: info:  [1357] passed: 96: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4) link (4) symlink (4) mknod (4) fcntl (4)\nstress-ng: info:  [1357] failed: 0\nstress-ng: info:  [1357] metrics untrustworthy: 0\nstress-ng: info:  [1357] successful run completed in 3.30 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "672": {
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 672,
            "name": "1",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 7758,
            "type": "perf_event"
          },
          "673": {
            "bytes_jited": 143,
            "bytes_xlated": 240,
            "id": 673,
            "name": "vfs_create",
            "run_cnt_delta": 4443150,
            "run_time_ns_delta": 168463236,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.300835463000112,
            "ops_per_sec": 1388798.397068071,
            "ops_total": 4584195.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [4262] setting to a 3 secs run per stressor\nstress-ng: info:  [4262] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime, 4 link, 4 symlink, 4 mknod, 4 fcntl\nstress-ng: info:  [4262] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [4348] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [4282] dentry: 252392 dentries allocated\nstress-ng: metrc: [4262] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4262]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4262] access            28901      3.04      0.52      3.05      9498.38        8099.96\nstress-ng: metrc: [4262] chdir               237      3.18      0.77      5.21        74.47          39.60\nstress-ng: metrc: [4262] chmod               217      3.06      0.02      0.10        71.01        1965.58\nstress-ng: metrc: [4262] chown               202      3.05      0.01      0.03        66.30        5360.65\nstress-ng: metrc: [4262] dentry            24576      3.14      0.09      0.70      7832.15       30850.19\nstress-ng: metrc: [4262] dir               32769      3.21      0.20      3.66     10214.73        8468.82\nstress-ng: metrc: [4262] dirmany           26143      3.06      0.03      0.66      8549.32       38016.23\nstress-ng: metrc: [4262] fallocate             3      3.06      0.01      0.01         0.98         123.77\nstress-ng: metrc: [4262] file-ioctl       181139      3.03      0.39      2.10     59843.58       72768.42\nstress-ng: metrc: [4262] filename          10581      3.03      0.12      2.36      3491.04        4254.20\nstress-ng: metrc: [4262] flock           2839826      3.03      0.64      0.95    938262.30     1787126.36\nstress-ng: metrc: [4262] fpunch              945      3.05      0.00      2.05       309.40         460.64\nstress-ng: metrc: [4262] fstat              7330      3.00      0.38      1.79      2442.93        3390.32\nstress-ng: metrc: [4262] getdent         1002101      3.00      0.52      6.92    333673.90      134815.34\nstress-ng: metrc: [4262] hdd               42290      3.04      0.74      0.78     13897.12       27745.01\nstress-ng: metrc: [4262] inotify               8      3.10      0.01      0.01         2.58         352.90\nstress-ng: metrc: [4262] open              14336      3.11      0.01      0.28      4608.32       50280.94\nstress-ng: metrc: [4262] rename           128835      3.04      0.04      0.96     42436.92      129044.05\nstress-ng: metrc: [4262] touch            131719      3.10      0.13      3.58     42465.06       35491.33\nstress-ng: metrc: [4262] utime             90237      3.03      0.12      1.67     29750.44       50375.37\nstress-ng: metrc: [4262] link                  9      3.08      0.18      1.08         2.92           7.15\nstress-ng: metrc: [4262] symlink               4      3.15      0.05      1.24         1.27           3.11\nstress-ng: metrc: [4262] mknod                60      3.09      0.01      0.03        19.40        1708.14\nstress-ng: metrc: [4262] fcntl             21727      3.03      0.08      0.27      7169.37       62332.71\nstress-ng: info:  [4262] skipped: 0\nstress-ng: info:  [4262] passed: 96: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4) link (4) symlink (4) mknod (4) fcntl (4)\nstress-ng: info:  [4262] failed: 0\nstress-ng: info:  [4262] metrics untrustworthy: 0\nstress-ng: info:  [4262] successful run completed in 3.29 secs"
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
          "prefetch",
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
      "selected_workload": "stress_ng_filesystem",
      "status": "ok"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline": {
        "bpf": {
          "680": {
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 680,
            "name": "sched_wakeup",
            "run_cnt_delta": 7201993,
            "run_time_ns_delta": 574751766,
            "type": "tracepoint"
          },
          "681": {
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 681,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 24865,
            "type": "tracepoint"
          },
          "682": {
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 682,
            "name": "sched_switch",
            "run_cnt_delta": 31974382,
            "run_time_ns_delta": 4926204218,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0172576979998667,
            "ops_per_sec": 12874256.32412844,
            "ops_total": 38844949.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [2173] setting to a 3 secs run per stressor\nstress-ng: info:  [2173] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [2173] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2173] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2173]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2173] futex           2899806      6.00      1.19     14.16    483219.36      188903.04\nstress-ng: metrc: [2173] sem             5540896      3.00      1.30      4.39   1846783.23      974299.87\nstress-ng: metrc: [2173] sem-sysv        1092208      3.00      0.18      1.41    363980.45      686052.54\nstress-ng: metrc: [2173] switch          2988516      3.00      1.06      7.60    996107.17      345061.91\nstress-ng: metrc: [2173] yield          26323523      3.00      6.36     13.96   8770280.71     1295399.62\nstress-ng: info:  [2173] skipped: 0\nstress-ng: info:  [2173] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [2173] failed: 0\nstress-ng: info:  [2173] metrics untrustworthy: 0\nstress-ng: info:  [2173] successful run completed in 3.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "680": {
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 680,
            "name": "sched_wakeup",
            "run_cnt_delta": 8340340,
            "run_time_ns_delta": 772801937,
            "type": "tracepoint"
          },
          "681": {
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 681,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 24020,
            "type": "tracepoint"
          },
          "682": {
            "bytes_jited": 518,
            "bytes_xlated": 912,
            "id": 682,
            "name": "sched_switch",
            "run_cnt_delta": 32998496,
            "run_time_ns_delta": 4845325097,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 3.0174720280001566,
            "ops_per_sec": 10742613.253480114,
            "ops_total": 32415535.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [2436] setting to a 3 secs run per stressor\nstress-ng: info:  [2436] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [2436] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2436] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2436]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2436] futex           2987406      6.00      0.73     14.25    497873.85      199452.08\nstress-ng: metrc: [2436] sem             6437767      3.00      1.47      4.86   2145714.68     1017139.85\nstress-ng: metrc: [2436] sem-sysv        1287488      3.00      0.69      2.29    429039.42      433090.95\nstress-ng: metrc: [2436] switch          3250379      3.00      0.94      8.49   1083435.54      344578.83\nstress-ng: metrc: [2436] yield          18452495      3.00      5.87     11.92   6148106.46     1037252.57\nstress-ng: info:  [2436] skipped: 0\nstress-ng: info:  [2436] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [2436] failed: 0\nstress-ng: info:  [2436] metrics untrustworthy: 0\nstress-ng: info:  [2436] successful run completed in 3.01 secs"
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
          "prefetch",
          "map_inline"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bpftrace",
      "selected_workload": "stress_ng_scheduler",
      "status": "ok"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline": {
        "bpf": {
          "690": {
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 690,
            "name": "tcp_set_state",
            "run_cnt_delta": 149005,
            "run_time_ns_delta": 72827741,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.103362979999929,
            "ops_per_sec": 5474.061561435649,
            "ops_total": 16988.0,
            "stderr": "",
            "stdout": "Running 3s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     2.53ms   15.06ms 221.38ms   98.70%\n    Req/Sec     2.76k   750.08     4.02k    45.16%\n  16988 requests in 3.10s, 2.51MB read\n  Socket errors: connect 0, read 16988, write 0, timeout 0\nRequests/sec:   5480.64\nTransfer/sec:    829.59KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "690": {
            "bytes_jited": 2023,
            "bytes_xlated": 3416,
            "id": 690,
            "name": "tcp_set_state",
            "run_cnt_delta": 152077,
            "run_time_ns_delta": 71727095,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.1070417150003777,
            "ops_per_sec": 5591.170506701063,
            "ops_total": 17372.0,
            "stderr": "",
            "stdout": "Running 3s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     1.74ms   10.76ms 221.69ms   99.33%\n    Req/Sec     2.82k     1.23k    5.12k    70.97%\n  17372 requests in 3.10s, 2.57MB read\n  Socket errors: connect 0, read 17372, write 0, timeout 0\nRequests/sec:   5603.89\nTransfer/sec:    848.29KB"
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
          "prefetch",
          "map_inline"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bpftrace",
      "selected_workload": "tcp_connect",
      "status": "ok"
    }
  ],
  "samples": 1,
  "status": "ok",
  "suite_name": "macro_apps",
  "workload_seconds": 3.0
}
```
