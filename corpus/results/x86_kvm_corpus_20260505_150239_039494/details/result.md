# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T15:07:37.263068+00:00",
  "kop_modules": {
    "captured_at": "2026-05-05T15:02:39.059184+00:00",
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
      "invoked_at": "2026-05-05T15:02:39.059074+00:00",
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
        "captured_at": "2026-05-05T15:02:39.059057+00:00",
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
      "captured_at": "2026-05-05T15:02:39.047334+00:00",
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
      "app": "tetragon/observer",
      "baseline": {
        "bpf": {
          "18": {
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 18,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 7771,
            "run_time_ns_delta": 10355059,
            "type": "kprobe"
          },
          "20": {
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 20,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 8596,
            "run_time_ns_delta": 17182946,
            "type": "kprobe"
          },
          "21": {
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 21,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "22": {
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 22,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "23": {
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 23,
            "name": "event_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 12327,
            "type": "tracepoint"
          },
          "24": {
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 24,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1055,
            "type": "kprobe"
          },
          "25": {
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 25,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "28": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 28,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "29": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 29,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "30": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 30,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "31": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 31,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "32": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 32,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "33": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 33,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "34": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 34,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "35": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 35,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "36": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 36,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "37": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 37,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "38": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 38,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "39": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 39,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "40": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 40,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "41": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 41,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "42": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 42,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "43": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 43,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "44": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 44,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "45": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 45,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "46": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 46,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "47": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 47,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "48": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 48,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "49": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 49,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "50": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 50,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 57258,
            "run_time_ns_delta": 64465203,
            "type": "kprobe"
          },
          "51": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 51,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "52": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 52,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "53": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 53,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "54": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 54,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "55": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 55,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "56": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 56,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "57": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 57,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 57258,
            "run_time_ns_delta": 61609768,
            "type": "kprobe"
          },
          "58": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 58,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "59": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 59,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "60": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 60,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "61": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 61,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "62": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 62,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 73737,
            "run_time_ns_delta": 102822604,
            "type": "kprobe"
          },
          "63": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 63,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "64": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 64,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "65": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 65,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "66": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 66,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "67": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 67,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "68": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 68,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "69": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 69,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "70": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 70,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "71": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 71,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "72": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 72,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "73": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 73,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "74": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 74,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "75": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 75,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 57258,
            "run_time_ns_delta": 65236350,
            "type": "kprobe"
          },
          "76": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 76,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "77": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 77,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "78": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 78,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "79": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 79,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "80": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 80,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "81": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 81,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "82": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 82,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "83": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 83,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 57258,
            "run_time_ns_delta": 68503146,
            "type": "kprobe"
          },
          "84": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 84,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "85": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 85,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "86": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 86,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "87": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 87,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "88": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 88,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "89": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 89,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "90": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 90,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 73737,
            "run_time_ns_delta": 98578319,
            "type": "kprobe"
          },
          "91": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 91,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "92": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 92,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "93": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 93,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "94": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 94,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "95": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 95,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 915032,
            "run_time_ns_delta": 948415344,
            "type": "kprobe"
          },
          "96": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 96,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "97": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 97,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "98": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 98,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "99": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 99,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "100": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 100,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "101": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 101,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1732854,
            "run_time_ns_delta": 1868576723,
            "type": "kprobe"
          },
          "102": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 102,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "103": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 103,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "104": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 104,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "105": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 105,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "106": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 106,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "107": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 107,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "108": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 108,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "109": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 109,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "110": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 110,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "111": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 111,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "112": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 112,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "113": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 113,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "114": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 114,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "115": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 115,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "116": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 116,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "117": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 117,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "118": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 118,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "119": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 119,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "120": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 120,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 859128,
            "run_time_ns_delta": 180209481,
            "type": "kprobe"
          },
          "121": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 121,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "122": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 122,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "123": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 123,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "124": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 124,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "125": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 125,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "126": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 126,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "127": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 127,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "128": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 128,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2301824,
            "run_time_ns_delta": 1167644702,
            "type": "kprobe"
          },
          "129": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 129,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "130": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 130,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "131": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 131,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "132": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 132,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "133": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 133,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "134": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 134,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2301824,
            "run_time_ns_delta": 86751020,
            "type": "kprobe"
          },
          "135": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 135,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "136": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 136,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "137": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 137,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "138": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 138,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "139": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 139,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "140": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 140,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "141": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 141,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "142": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 142,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "143": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 143,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "144": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 144,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 419079,
            "run_time_ns_delta": 2263269264,
            "type": "kprobe"
          },
          "145": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 145,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "146": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 146,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 419079,
            "run_time_ns_delta": 18279238,
            "type": "kprobe"
          },
          "147": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 147,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "148": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 148,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "149": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 149,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "150": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 150,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "151": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 151,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "152": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 152,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "153": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 153,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "154": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 154,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 62,
            "run_time_ns_delta": 365970,
            "type": "kprobe"
          },
          "155": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 155,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "156": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 156,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "157": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 157,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "158": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 158,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 62,
            "run_time_ns_delta": 29184,
            "type": "kprobe"
          },
          "159": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 159,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "160": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 160,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "161": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 161,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "162": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 162,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "163": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 163,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "164": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 164,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "165": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 165,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "166": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 166,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "167": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 167,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "168": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 168,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "169": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 169,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "170": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 170,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "171": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 171,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "172": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 172,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "173": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 173,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "174": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 174,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "175": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 175,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "176": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 176,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "177": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 177,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "178": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 178,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "179": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 179,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "180": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 180,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "181": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 181,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "182": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 182,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "183": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 183,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "184": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 184,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "185": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 185,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "186": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 186,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "187": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 187,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "188": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 188,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "189": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 189,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "190": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 190,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "191": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 191,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "192": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 192,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 194,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "195": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 195,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "196": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 196,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "197": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 197,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "198": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 198,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "199": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 199,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "200": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 200,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "201": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 201,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8233,
            "type": "kprobe"
          },
          "202": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 202,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "203": {
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 203,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 35502321,
            "run_time_ns_delta": 38561788526,
            "type": "tracepoint"
          },
          "204": {
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 204,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "205": {
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 205,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "206": {
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 206,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "207": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 207,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "208": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 208,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "209": {
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 209,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "210": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 210,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "211": {
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 211,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "212": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 212,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "213": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 213,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "214": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 214,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "215": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 215,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8114,
            "type": "raw_tracepoint"
          },
          "216": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 216,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "217": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 217,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "218": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 218,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "219": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 219,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "220": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 220,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "221": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 221,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 33512,
            "run_time_ns_delta": 56539456,
            "type": "kprobe"
          },
          "222": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 222,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "223": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 223,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "224": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 224,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "225": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 225,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "226": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 226,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "227": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 227,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 53443,
            "run_time_ns_delta": 176023081,
            "type": "kprobe"
          },
          "228": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 228,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "229": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 229,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "230": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 230,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 232,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "233": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 233,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "234": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 234,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "235": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 235,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "236": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 236,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "237": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 237,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 57258,
            "run_time_ns_delta": 68623379,
            "type": "kprobe"
          },
          "238": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 238,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "239": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 239,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "240": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 240,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "241": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 241,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 244,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "245": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 245,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "246": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 246,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "247": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 247,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 57258,
            "run_time_ns_delta": 73238611,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 250,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "251": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 251,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "252": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 252,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 73737,
            "run_time_ns_delta": 100756675,
            "type": "kprobe"
          },
          "253": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 253,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "254": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 254,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "255": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 255,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "256": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 256,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 164844,
            "run_time_ns_delta": 111734767,
            "type": "kprobe"
          },
          "257": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 257,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "258": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 258,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "259": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 259,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "260": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 260,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "261": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 261,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 262,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 263,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "264": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 264,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "265": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 265,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 266,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "267": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 267,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "268": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 268,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 41081,
            "run_time_ns_delta": 63031041,
            "type": "kprobe"
          },
          "269": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 269,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 271,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 272,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 273,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "274": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 274,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 20533,
            "run_time_ns_delta": 34031880,
            "type": "kprobe"
          },
          "275": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 275,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 276,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 20533,
            "run_time_ns_delta": 40328569,
            "type": "kprobe"
          },
          "277": {
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 277,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 278,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "279": {
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 279,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 280,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 281,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "282": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 282,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 283,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 284,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 285,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 20535,
            "run_time_ns_delta": 40241157,
            "type": "kprobe"
          },
          "286": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 286,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 287,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 288,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 289,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "290": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 290,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 291,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 41081,
            "run_time_ns_delta": 63584219,
            "type": "kprobe"
          },
          "292": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 292,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 293,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 294,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 295,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 296,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "297": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 297,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 352679,
            "run_time_ns_delta": 439455947,
            "type": "kprobe"
          },
          "298": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 298,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 299,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 300,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 301,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 302,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "303": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 303,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 304,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 305,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 306,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 307,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.284651726999996,
            "ops_per_sec": 14544225.233860914,
            "ops_total": 76861165.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [10462] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10462]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10462] cap              419109      5.05      0.13      4.35     82920.41       93538.32\nstress-ng: metrc: [10462] eventfd          115797      5.00      0.13      2.25     23141.53       48559.61\nstress-ng: metrc: [10462] get                2498      5.02      0.08      1.16       497.75        2015.94\nstress-ng: metrc: [10462] prctl              4229      5.01      2.40      0.67       844.32        1378.43\nstress-ng: metrc: [10462] set                8880      5.04      0.01      1.13      1760.65        7816.57\nstress-ng: metrc: [10462] dup                1624      5.03      0.38      0.30       322.94        2357.08\nstress-ng: metrc: [10462] kill              35133      5.06      0.04      1.87      6943.29       18444.16\nstress-ng: metrc: [10462] sigfd            399147      5.06      0.03      2.49     78922.88      158248.99\nstress-ng: metrc: [10462] signal                0      5.04      0.01      0.00         0.00           0.00\nstress-ng: metrc: [10462] pty                  92      5.03      0.05      4.24        18.28          21.43\nstress-ng: metrc: [10462] itimer              163      5.04      0.01      1.35        32.33         120.33\nstress-ng: metrc: [10462] timerfd          376832      5.05      0.06      3.07     74596.60      120313.62\nstress-ng: metrc: [10462] aio               26255      5.04      0.02      0.25      5214.25       97294.43\nstress-ng: metrc: [10462] aiol               5953      5.18      0.14      0.69      1149.66        7174.84\nstress-ng: metrc: [10462] hdd               58636      5.05      0.76      0.91     11622.58       35064.99\nstress-ng: metrc: [10462] io                  192      5.02      0.01      0.03        38.26        4951.01\nstress-ng: metrc: [10462] iomix              4390      5.09      0.11      2.43       863.08        1730.46\nstress-ng: metrc: [10462] io-uring          26768      5.08      0.02      1.46      5266.60       18074.82\nstress-ng: metrc: [10462] sync-file           112      5.04      0.03      1.31        22.23          83.11\nstress-ng: metrc: [10462] epoll               895      5.12      0.06      0.05       174.94        8289.80\nstress-ng: metrc: [10462] netdev           562547      5.02      0.08      3.45    112111.94      159321.23\nstress-ng: metrc: [10462] sctp              62215      5.01      0.07      1.68     12422.02       35465.34\nstress-ng: metrc: [10462] sock                650      5.04      0.01      1.40       128.98         462.09\nstress-ng: metrc: [10462] sockdiag       71619249      5.01      0.17      3.94  14292580.66    17421839.66\nstress-ng: metrc: [10462] sockfd           178349      5.02      0.06      1.83     35520.41       94646.19\nstress-ng: metrc: [10462] sockpair            603      5.08      0.03      0.22       118.74        2373.20\nstress-ng: metrc: [10462] sockmany          20533      5.02      0.06      2.03      4090.40        9812.53\nstress-ng: metrc: [10462] udp              122618      5.00      0.07      2.67     24503.76       44699.27\nstress-ng: metrc: [10462] udp-flood        495701      5.03      0.06      2.40     98469.00      200885.08\nstress-ng: metrc: [10462] mmap                365      5.02      0.01      3.05        72.71         119.25\nstress-ng: metrc: [10462] mprotect        2310565      5.04      0.53     14.55    458269.35      153173.46\nstress-ng: metrc: [10462] mremap             1001      5.02      0.02      0.97       199.27        1012.48\nstress-ng: metrc: [10462] madvise              64      5.02      0.14      3.55        12.75          17.36\nstress-ng: info:  [10462] skipped: 0\nstress-ng: info:  [10462] passed: 132: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp (4) udp-flood (4) mmap (4) mprotect (4) mremap (4) madvise (4)\nstress-ng: info:  [10462] failed: 0\nstress-ng: info:  [10462] metrics untrustworthy: 0\nstress-ng: info:  [10462] successful run completed in 5.26 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "18": {
            "bytes_jited": 1029,
            "bytes_xlated": 1872,
            "id": 18,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 6621,
            "run_time_ns_delta": 9718029,
            "type": "kprobe"
          },
          "20": {
            "bytes_jited": 7128,
            "bytes_xlated": 11152,
            "id": 20,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 7432,
            "run_time_ns_delta": 16260278,
            "type": "kprobe"
          },
          "21": {
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 21,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "22": {
            "bytes_jited": 1395,
            "bytes_xlated": 2416,
            "id": 22,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "23": {
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 23,
            "name": "event_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 10967,
            "type": "tracepoint"
          },
          "24": {
            "bytes_jited": 1541,
            "bytes_xlated": 2592,
            "id": 24,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1470,
            "type": "kprobe"
          },
          "25": {
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 25,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "28": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 28,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "29": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 29,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "30": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 30,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "31": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 31,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "32": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 32,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "33": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 33,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "34": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 34,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "35": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 35,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "36": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 36,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "37": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 37,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "38": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 38,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "39": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 39,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "40": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 40,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "41": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 41,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "42": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 42,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "43": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 43,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "44": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 44,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "45": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 45,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "46": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 46,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "47": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 47,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "48": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 48,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "49": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 49,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "50": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 50,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 54037,
            "run_time_ns_delta": 49160924,
            "type": "kprobe"
          },
          "51": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 51,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "52": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 52,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "53": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 53,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "54": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 54,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "55": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 55,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "56": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 56,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "57": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 57,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 54037,
            "run_time_ns_delta": 42059595,
            "type": "kprobe"
          },
          "58": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 58,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "59": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 59,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "60": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 60,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "61": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 61,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "62": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 62,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 62457,
            "run_time_ns_delta": 82047834,
            "type": "kprobe"
          },
          "63": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 63,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "64": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 64,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "65": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 65,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "66": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 66,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "67": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 67,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "68": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 68,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "69": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 69,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "70": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 70,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "71": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 71,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "72": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 72,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "73": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 73,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "74": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 74,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "75": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 75,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 54037,
            "run_time_ns_delta": 50041520,
            "type": "kprobe"
          },
          "76": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 76,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "77": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 77,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "78": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 78,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "79": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 79,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "80": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 80,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "81": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 81,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "82": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 82,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "83": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 83,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 54037,
            "run_time_ns_delta": 52494960,
            "type": "kprobe"
          },
          "84": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 84,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "85": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 85,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "86": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 86,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "87": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 87,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "88": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 88,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "89": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 89,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "90": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 90,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 62457,
            "run_time_ns_delta": 82658137,
            "type": "kprobe"
          },
          "91": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 91,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "92": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 92,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "93": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 93,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "94": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 94,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "95": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 95,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 494481,
            "run_time_ns_delta": 506845516,
            "type": "kprobe"
          },
          "96": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 96,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "97": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 97,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "98": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 98,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "99": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 99,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "100": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 100,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "101": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 101,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1614662,
            "run_time_ns_delta": 1553853836,
            "type": "kprobe"
          },
          "102": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 102,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "103": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 103,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "104": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 104,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "105": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 105,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "106": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 106,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "107": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 107,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "108": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 108,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "109": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 109,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "110": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 110,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "111": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 111,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "112": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 112,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "113": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 113,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "114": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 114,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "115": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 115,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "116": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 116,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "117": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 117,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "118": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 118,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "119": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 119,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "120": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 120,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 699371,
            "run_time_ns_delta": 147481887,
            "type": "kprobe"
          },
          "121": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 121,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "122": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 122,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "123": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 123,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "124": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 124,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "125": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 125,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "126": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 126,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "127": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 127,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "128": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 128,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1913890,
            "run_time_ns_delta": 989104449,
            "type": "kprobe"
          },
          "129": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 129,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "130": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 130,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "131": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 131,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "132": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 132,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "133": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 133,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "134": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 134,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1913890,
            "run_time_ns_delta": 78211789,
            "type": "kprobe"
          },
          "135": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 135,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "136": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 136,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "137": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 137,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "138": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 138,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "139": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 139,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "140": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 140,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "141": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 141,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "142": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 142,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "143": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 143,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "144": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 144,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 283476,
            "run_time_ns_delta": 1400760004,
            "type": "kprobe"
          },
          "145": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 145,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "146": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 146,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 283476,
            "run_time_ns_delta": 12829721,
            "type": "kprobe"
          },
          "147": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 147,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "148": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 148,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "149": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 149,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "150": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 150,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "151": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 151,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "152": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 152,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "153": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 153,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "154": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 154,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 59,
            "run_time_ns_delta": 355306,
            "type": "kprobe"
          },
          "155": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 155,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "156": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 156,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "157": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 157,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "158": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 158,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 59,
            "run_time_ns_delta": 26890,
            "type": "kprobe"
          },
          "159": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 159,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "160": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 160,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "161": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 161,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "162": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 162,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "163": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 163,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "164": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 164,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "165": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 165,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "166": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 166,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "167": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 167,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "168": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 168,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "169": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 169,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "170": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 170,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "171": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 171,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "172": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 172,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "173": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 173,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "174": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 174,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "175": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 175,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "176": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 176,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "177": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 177,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "178": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 178,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "179": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 179,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "180": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 180,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "181": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 181,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "182": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 182,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "183": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 183,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "184": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 184,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "185": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 185,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "186": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 186,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "187": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 187,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "188": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 188,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "189": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 189,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "190": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 190,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "191": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 191,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "192": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 192,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 194,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "195": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 195,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "196": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 196,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "197": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 197,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "198": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 198,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "199": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 199,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "200": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 200,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "201": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 201,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8603,
            "type": "kprobe"
          },
          "202": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 202,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "203": {
            "bytes_jited": 10963,
            "bytes_xlated": 19728,
            "id": 203,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 36012554,
            "run_time_ns_delta": 42470718779,
            "type": "tracepoint"
          },
          "204": {
            "bytes_jited": 11118,
            "bytes_xlated": 18152,
            "id": 204,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "205": {
            "bytes_jited": 4781,
            "bytes_xlated": 8648,
            "id": 205,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "206": {
            "bytes_jited": 14893,
            "bytes_xlated": 25800,
            "id": 206,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "207": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 207,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "208": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 208,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "209": {
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 209,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "210": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 210,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "211": {
            "bytes_jited": 17087,
            "bytes_xlated": 29584,
            "id": 211,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "212": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 212,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "213": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 213,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "214": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 214,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "215": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 215,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 11822,
            "type": "raw_tracepoint"
          },
          "216": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 216,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "217": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 217,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "218": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 218,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "219": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 219,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "220": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 220,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "221": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 221,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 24167,
            "run_time_ns_delta": 37451849,
            "type": "kprobe"
          },
          "222": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 222,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "223": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 223,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "224": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 224,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "225": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 225,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "226": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 226,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "227": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 227,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 46522,
            "run_time_ns_delta": 171103447,
            "type": "kprobe"
          },
          "228": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 228,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "229": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 229,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "230": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 230,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 232,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "233": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 233,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "234": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 234,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "235": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 235,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "236": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 236,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "237": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 237,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 54037,
            "run_time_ns_delta": 51269819,
            "type": "kprobe"
          },
          "238": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 238,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "239": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 239,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "240": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 240,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "241": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 241,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 244,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "245": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 245,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "246": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 246,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "247": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 247,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 54037,
            "run_time_ns_delta": 55178320,
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
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 250,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "251": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 251,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "252": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 252,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 62457,
            "run_time_ns_delta": 85220118,
            "type": "kprobe"
          },
          "253": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 253,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "254": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 254,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "255": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 255,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "256": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 256,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 110667,
            "run_time_ns_delta": 60600667,
            "type": "kprobe"
          },
          "257": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 257,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "258": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 258,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "259": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 259,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "260": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 260,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "261": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 261,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 262,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 263,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "264": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 264,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "265": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 265,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 266,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "267": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 267,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "268": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 268,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 28450,
            "run_time_ns_delta": 39004424,
            "type": "kprobe"
          },
          "269": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 269,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 271,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 272,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 273,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "274": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 274,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 14221,
            "run_time_ns_delta": 20057066,
            "type": "kprobe"
          },
          "275": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 275,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 276,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 14221,
            "run_time_ns_delta": 26297012,
            "type": "kprobe"
          },
          "277": {
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 277,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 278,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "279": {
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 279,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 280,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 281,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "282": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 282,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 283,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 284,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 285,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 14222,
            "run_time_ns_delta": 22967252,
            "type": "kprobe"
          },
          "286": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 286,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 287,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 288,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 289,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "290": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 290,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 291,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 28450,
            "run_time_ns_delta": 36918659,
            "type": "kprobe"
          },
          "292": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 292,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 293,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 294,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 295,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 296,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "297": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 297,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 409219,
            "run_time_ns_delta": 552127367,
            "type": "kprobe"
          },
          "298": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 298,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 299,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 300,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 301,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 302,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "303": {
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 303,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 304,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 305,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 306,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 307,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.248986755999965,
            "ops_per_sec": 5103401.331576951,
            "ops_total": 26787686.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [28115] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [28115]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [28115] cap              175455      5.05      0.05      2.02     34724.54       85017.36\nstress-ng: metrc: [28115] eventfd          102464      5.01      0.07      1.95     20454.21       50661.38\nstress-ng: metrc: [28115] get                3847      5.02      0.06      1.99       765.72        1872.97\nstress-ng: metrc: [28115] prctl              3825      5.00      2.38      0.68       764.92        1251.82\nstress-ng: metrc: [28115] set               25448      5.06      0.07      3.57      5031.73        6979.85\nstress-ng: metrc: [28115] dup                1251      5.07      0.29      0.30       246.98        2143.16\nstress-ng: metrc: [28115] kill              29511      5.03      0.03      2.58      5864.31       11290.95\nstress-ng: metrc: [28115] sigfd            503818      5.08      0.11      3.29     99272.91      148389.42\nstress-ng: metrc: [28115] signal                0      5.03      0.00      0.38         0.00           0.00\nstress-ng: metrc: [28115] pty                  61      5.04      0.08      4.06        12.09          14.72\nstress-ng: metrc: [28115] itimer              243      5.05      0.03      2.07        48.07         115.90\nstress-ng: metrc: [28115] timerfd          152576      5.12      0.03      1.41     29799.14      106494.09\nstress-ng: metrc: [28115] aio               18766      5.08      0.00      0.19      3690.85       98094.15\nstress-ng: metrc: [28115] aiol               4298      5.19      0.05      0.55       827.38        7193.29\nstress-ng: metrc: [28115] hdd               53140      5.11      0.64      0.75     10390.39       38176.63\nstress-ng: metrc: [28115] io                  128      5.06      0.02      0.02        25.28        3569.64\nstress-ng: metrc: [28115] iomix              3889      5.10      0.13      2.41       761.87        1529.66\nstress-ng: metrc: [28115] io-uring          24668      5.11      0.00      1.39      4829.58       17720.60\nstress-ng: metrc: [28115] sync-file            88      5.10      0.01      1.14        17.24          76.32\nstress-ng: metrc: [28115] epoll               982      5.14      0.08      0.04       191.01        8266.20\nstress-ng: metrc: [28115] netdev           426856      5.08      0.07      2.78     84105.29      149729.38\nstress-ng: metrc: [28115] sctp              43045      5.02      0.03      1.30      8569.86       32278.65\nstress-ng: metrc: [28115] sock                773      5.04      0.01      1.72       153.43         446.08\nstress-ng: metrc: [28115] sockdiag       21541749      5.02      0.08      2.26   4288718.63     9228762.18\nstress-ng: metrc: [28115] sockfd           118761      5.06      0.18      1.11     23486.56       91874.34\nstress-ng: metrc: [28115] sockpair           5393      5.09      0.02      0.39      1060.31       12931.77\nstress-ng: metrc: [28115] sockmany          14217      5.10      0.03      1.09      2789.87       12660.54\nstress-ng: metrc: [28115] udp               33063      5.03      0.04      1.25      6573.71       25533.90\nstress-ng: metrc: [28115] udp-flood        586973      5.01      0.03      2.52    117232.00      229441.47\nstress-ng: metrc: [28115] mmap                211      5.02      0.01      1.63        42.01         128.69\nstress-ng: metrc: [28115] mprotect        2909927      5.04      0.74     19.90    577057.16      140990.61\nstress-ng: metrc: [28115] mremap             2197      5.01      0.01      2.14       438.54        1023.11\nstress-ng: metrc: [28115] madvise              63      5.05      0.12      3.81        12.48          16.02\nstress-ng: info:  [28115] skipped: 0\nstress-ng: info:  [28115] passed: 132: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (4) kill (4) sigfd (4) signal (4) pty (4) itimer (4) timerfd (4) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp (4) udp-flood (4) mmap (4) mprotect (4) mremap (4) madvise (4)\nstress-ng: info:  [28115] failed: 0\nstress-ng: info:  [28115] metrics untrustworthy: 0\nstress-ng: info:  [28115] successful run completed in 5.22 secs"
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
        "error": "prog 21: prog 21 pass cond_select failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @820\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 0\n      2: ......67.. (63) *(u32 *)(r10 -88) = r7\n      3: ......67.. (bf) r2 = r10\n      4: ..2...67.. (07) r2 += -88\n      5: ..2...67.. (18) r1 = 0xffff8c2446269600\n      7: .12...67.. (85) call bpf_map_lookup_elem#1\n      8: 0.....67.. (15) if r0 == 0x0 goto pc+809\n      9: 0.....67.. (7b) *(u64 *)(r10 -120) = r6\n     10: 0......7.. (bf) r8 = r0\n     11: 0......78. (bf) r6 = r0\n     12: ......678. (85) call bpf_get_current_task#35\n     13: 0.....678. (b7) r1 = 2680\n     14: 01....678. (0f) r0 += r1\n     15: 0.....678. (bf) r1 = r10\n     16: 01....678. (07) r1 += -72\n     17: 01....678. (b7) r2 = 8\n     18: 012...678. (bf) r3 = r0\n     19: .123..678. (85) call bpf_probe_read#4\n     20: ......678. (b7) r1 = 1448\n     21: .1....678. (79) r3 = *(u64 *)(r10 -72)\n     22: .1.3..678. (0f) r3 += r1\n     23: ...3..678. (bf) r1 = r10\n     24: .1.3..678. (07) r1 += -64\n     25: .1.3..678. (b7) r2 = 8\n     26: .123..678. (85) call bpf_probe_read#4\n     27: ......678. (79) r9 = *(u64 *)(r10 -64)\n     28: ......6789 (63) *(u32 *)(r10 -84) = r7\n     29: ......6.89 (bf) r2 = r10\n     30: ..2...6.89 (07) r2 += -84\n     31: ..2...6.89 (18) r1 = 0xffff8c2447ba4000\n     33: .12...6.89 (85) call bpf_map_lookup_elem#1\n     34: 0.....6.89 (7b) *(u64 *)(r10 -104) = r6\n     35: 0.....6.89 (07) r6 += 5808\n     36: 0.....6.89 (7b) *(u64 *)(r10 -112) = r6\n     37: 0.......89 (bf) r2 = r8\n     38: 0.2.....89 (7b) *(u64 *)(r10 -96) = r8\n     39: 0.2......9 (bf) r8 = r0\n     40: ..2.....89 (55) if r8 != 0x0 goto pc+1\n     41: .......... (05) goto pc+252\n     42: ..2.....89 (b7) r1 = 64\n     43: .12.....89 (0f) r9 += r1\n     44: ..2.....89 (b7) r1 = 4096\n     45: .12.....89 (63) *(u32 *)(r2 +6192) = r1\n     46: ........89 (85) call bpf_get_current_task#35\n     47: 0.......89 (b7) r1 = 3408\n     48: 01......89 (0f) r0 += r1\n     49: 0.......89 (bf) r1 = r10\n     50: 01......89 (07) r1 += -80\n     51: 01......89 (b7) r2 = 8\n     52: 012.....89 (bf) r3 = r0\n     53: .123....89 (85) call bpf_probe_read#4\n     54: ........89 (b7) r1 = 8\n     55: .1......89 (7b) *(u64 *)(r10 -128) = r9\n     56: .1......89 (0f) r9 += r1\n     57: ........89 (79) r7 = *(u64 *)(r10 -80)\n     58: .......789 (bf) r1 = r10\n     59: .1.....789 (07) r1 += -72\n     60: .1.....789 (b7) r2 = 8\n     61: .12....789 (7b) *(u64 *)(r10 -136) = r9\n     62: .12....789 (bf) r3 = r9\n     63: .123...78. (85) call bpf_probe_read#4\n     64: .......78. (b7) r1 = 8\n     65: .1.....78. (79) r6 = *(u64 *)(r10 -72)\n     66: .1....678. (bf) r3 = r6\n     67: .1.3..678. (0f) r3 += r1\n     68: ...3..678. (b7) r1 = 8\n     69: .1.3..678. (0f) r3 += r1\n     70: ...3..678. (bf) r1 = r10\n     71: .1.3..678. (07) r1 += -64\n     72: .1.3..678. (b7) r2 = 8\n     73: .123..678. (85) call bpf_probe_read#4\n     74: ......678. (79) r3 = *(u64 *)(r10 -96)\n     75: ...3..678. (bf) r9 = r8\n     76: ...3..6789 (07) r9 += 4096\n     77: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     78: .1.3..6789 (55) if r1 != 0x0 goto pc+41\n     79: ......6789 (b7) r1 = 24\n     80: .1....6789 (bf) r3 = r6\n     81: .1.3..6789 (0f) r3 += r1\n     82: ...3..6789 (bf) r1 = r10\n     83: .1.3..6789 (07) r1 += -64\n     84: .1.3..6789 (b7) r2 = 8\n     85: .123..6789 (85) call bpf_probe_read#4\n     86: ......6789 (79) r3 = *(u64 *)(r10 -96)\n     87: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     88: .1.3..6789 (1d) if r1 == r6 goto pc+31\n     89: ...3...789 (61) r1 = *(u32 *)(r3 +6192)\n     90: .1.3...789 (bf) r2 = r1\n     91: .123...789 (07) r2 += -10\n     92: .123...789 (63) *(u32 *)(r3 +6192) = r2\n     93: .123...789 (67) r1 <<= 32\n     94: .123...789 (c7) r1 s>>= 32\n     95: .123...789 (65) if r1 s> 0x9 goto pc+5\n     96: ..23.....9 (18) r1 = 0xffffffdc\n     98: .123.....9 (63) *(u32 *)(r3 +6196) = r1\n     99: ..2......9 (bf) r7 = r9\n    100: ..2....7.. (05) goto pc+93\n    101: ...3...78. (b7) r1 = 41\n    102: .1.3...78. (73) *(u8 *)(r8 +4095) = r1\n    103: ...3...78. (b7) r1 = 116\n    104: .1.3...78. (73) *(u8 *)(r8 +4092) = r1\n    105: ...3\n... verifier log truncated ...; prog 23: prog 23 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @1724\nfunc#2 @1840\nfunc#3 @2033\nfunc#4 @2208\nfunc#5 @2277\nfunc#6 @2300\nfunc#7 @2370\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (85) call bpf_get_current_task#35\n      2: 0.....6... (bf) r9 = r0\n      3: ......6..9 (7b) *(u64 *)(r10 -128) = r6\n      4: ......6..9 (61) r6 = *(u32 *)(r6 +8)\n      5: ......6..9 (b7) r1 = 0\n      6: .1....6..9 (63) *(u32 *)(r10 -120) = r1\n      7: ......6..9 (bf) r2 = r10\n      8: ..2...6..9 (07) r2 += -120\n      9: ..2...6..9 (18) r1 = 0xffff8c2446269600\n     11: .12...6..9 (85) call bpf_map_lookup_elem#1\n     12: 0.....6..9 (bf) r7 = r0\n     13: ......67.9 (15) if r7 == 0x0 goto pc+1689\n     14: ......67.9 (7b) *(u64 *)(r10 -144) = r6\n     15: .......7.9 (85) call bpf_get_current_pid_tgid#14\n     16: 0......7.9 (bf) r6 = r0\n     17: ......67.9 (85) call bpf_get_current_task#35\n     18: 0.....67.9 (7b) *(u64 *)(r10 -96) = r0\n     19: 0.....67.9 (b7) r8 = 2816\n     20: 0.....6789 (0f) r0 += r8\n     21: 0.....6789 (bf) r1 = r10\n     22: 01....6789 (07) r1 += -96\n     23: 01....6789 (b7) r2 = 8\n     24: 012...6789 (bf) r3 = r0\n     25: .123..6789 (85) call bpf_probe_read_kernel#113\n     26: ......6789 (7b) *(u64 *)(r10 -160) = r6\n     27: ......6789 (7b) *(u64 *)(r10 -152) = r6\n     28: .......789 (79) r3 = *(u64 *)(r10 -96)\n     29: ...3...789 (7b) *(u64 *)(r10 -136) = r9\n     30: ...3...789 (15) if r3 == 0x0 goto pc+162\n     31: ...3...789 (b7) r1 = 2804\n     32: .1.3...789 (0f) r3 += r1\n     33: ...3...789 (bf) r1 = r10\n     34: .1.3...789 (07) r1 += -8\n     35: .1.3...789 (b7) r2 = 4\n     36: .123...789 (85) call bpf_probe_read_kernel#113\n     37: .......789 (61) r1 = *(u32 *)(r10 -8)\n     38: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     39: .......789 (bf) r2 = r10\n     40: ..2....789 (07) r2 += -112\n     41: ..2....789 (18) r1 = 0xffff8c2446a1a400\n     43: .12....789 (85) call bpf_map_lookup_elem#1\n     44: 0......789 (bf) r6 = r0\n     45: ......6789 (15) if r6 == 0x0 goto pc+3\n     46: ......6789 (05) goto pc+0\n     47: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     48: .1....6789 (55) if r1 != 0x0 goto pc+81\n     49: .......789 (b7) r1 = 2816\n     50: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     51: .1.3...789 (0f) r3 += r1\n     52: ...3...789 (bf) r1 = r10\n     53: .1.3...789 (07) r1 += -96\n     54: .1.3...789 (b7) r2 = 8\n     55: .123...789 (85) call bpf_probe_read_kernel#113\n     56: .......789 (79) r3 = *(u64 *)(r10 -96)\n     57: ...3...789 (15) if r3 == 0x0 goto pc+135\n     58: ...3...789 (b7) r1 = 2804\n     59: .1.3...789 (0f) r3 += r1\n     60: ...3...789 (bf) r1 = r10\n     61: .1.3...789 (07) r1 += -8\n     62: .1.3...789 (b7) r2 = 4\n     63: .123...789 (85) call bpf_probe_read_kernel#113\n     64: .......789 (61) r1 = *(u32 *)(r10 -8)\n     65: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     66: .......789 (bf) r2 = r10\n     67: ..2....789 (07) r2 += -112\n     68: ..2....789 (18) r1 = 0xffff8c2446a1a400\n     70: .12....789 (85) call bpf_map_lookup_elem#1\n     71: 0......789 (bf) r6 = r0\n     72: ......6789 (15) if r6 == 0x0 goto pc+3\n     73: ......6789 (05) goto pc+0\n     74: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     75: .1....6789 (55) if r1 != 0x0 goto pc+54\n     76: .......789 (b7) r1 = 2816\n     77: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     78: .1.3...789 (0f) r3 += r1\n     79: ...3...789 (bf) r1 = r10\n     80: .1.3...789 (07) r1 += -96\n     81: .1.3...789 (b7) r2 = 8\n     82: .123...789 (85) call bpf_probe_read_kernel#113\n     83: .......789 (79) r3 = *(u64 *)(r10 -96)\n     84: ...3...789 (15) if r3 == 0x0 goto pc+108\n     85: ...3...789 (b7) r1 = 2804\n     86: .1.3...789 (0f) r3 += r1\n     87: ...3...789 (bf) r1 = r10\n     88: .1.3...789 (07) r1 += -8\n     89: .1.3...789 (b7) r2 = 4\n     90: .123...789 (85) call bpf_probe_read_kernel#113\n     91: .......789 (61) r1 = *(u32 *)(r10 -8)\n     92: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     93: .......789 (bf) r2 = r10\n     94: ..2....789 (07) r2 += -112\n     95: ..2....789 (18) r1 = 0xffff8c2446a1a400\n     97: .12....789 (85) call bpf_map_lookup_elem#1\n     98: 0......789 (bf) r6 = r0\n\n... verifier log truncated ...; prog 25: prog 25 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 32: prog 32 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 40: prog 40 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 47: prog 47 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 51: prog 51 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 56: prog 56 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...; prog 66: prog 66 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 71: prog 71 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 74: prog 74 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 84: prog 84 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...; prog 86: prog 86 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 98: prog 98 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 103: prog 103 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 107: prog 107 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 115: prog 115 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 117: prog 117 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r1 = 0\n      2: .1....6... (63) *(u32 *)(r10 -116) = r1\n      3: ......6... (bf) r2 = r10\n      4: ..2...6... (07) r2 += -116\n      5: ..2...6... (18) r1 = 0xffff8c250b570800\n      7: .12...6... (85) call bpf_map_lookup_elem#1\n      8: 0.....6... (bf) r7 = r0\n      9: ......67.. (15) if r7 == 0x0 goto pc+370\n     10: ......67.. (05) goto pc+0\n     11: ......67.. (7b) *(u64 *)(r10 -128) = r6\n     12: .......7.. (79) r1 = *(u64 *)(r7 +24272)\n     13: .1.....7.. (15) if r1 == 0x0 goto pc+203\n     14: .......7.. (85) call bpf_get_current_pid_tgid#14\n     15: 0......7.. (bf) r6 = r0\n     16: ......67.. (85) call bpf_get_current_task#35\n     17: 0.....67.. (bf) r9 = r0\n     18: ......67.9 (77) r6 >>= 32\n     19: ......67.9 (63) *(u32 *)(r10 -80) = r6\n     20: .......7.9 (bf) r2 = r10\n     21: ..2....7.9 (07) r2 += -80\n     22: ..2....7.9 (18) r1 = 0xffff8c2446a1a400\n     24: .12....7.9 (85) call bpf_map_lookup_elem#1\n     25: 0......7.9 (bf) r8 = r0\n     26: .......789 (15) if r8 == 0x0 goto pc+190\n     27: .......789 (b7) r1 = 3440\n     28: .1.....789 (bf) r3 = r9\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (bf) r1 = r10\n     31: .1.3...789 (07) r1 += -8\n     32: .1.3...789 (b7) r2 = 8\n     33: .123...789 (85) call bpf_probe_read#4\n     34: .......789 (79) r3 = *(u64 *)(r10 -8)\n     35: ...3...789 (bf) r6 = r10\n     36: ...3..6789 (07) r6 += -80\n     37: ...3..6789 (bf) r1 = r6\n     38: .1.3..6789 (b7) r2 = 72\n     39: .123..6789 (85) call bpf_probe_read#4\n     40: ...3456789 (bf) r1 = r8\n     41: .1.3456789 (07) r1 += 40\n     42: .1.3456789 (b7) r2 = 1\n     43: .123456789 (15) if r2 == 0x0 goto pc+2\n     44: .1....6789 (b7) r2 = 536\n     45: .12...6789 (05) goto pc+1\n     46: .123456789 (85) call unknown#195896080\n     47: .12...6789 (79) r3 = *(u64 *)(r6 +8)\n     48: .123...789 (0f) r3 += r2\n     49: .1.3...789 (b7) r2 = 4\n     50: .123...789 (85) call bpf_probe_read#4\n     51: ..2.45.789 (b7) r1 = 1\n     52: .12.45.789 (15) if r1 == 0x0 goto pc+5\n     53: .......789 (bf) r1 = r10\n     54: .1.....789 (07) r1 += -80\n     55: .1.....789 (79) r3 = *(u64 *)(r1 +16)\n     56: ...3...789 (b7) r1 = 1240\n     57: .1.3...789 (05) goto pc+4\n     58: ..2.45.789 (bf) r1 = r10\n     59: .12.45.789 (07) r1 += -80\n     60: .12.45.789 (79) r3 = *(u64 *)(r1 +16)\n     61: .12345.789 (85) call unknown#195896080\n     62: .1.3...789 (0f) r3 += r1\n     63: ...3...789 (bf) r1 = r8\n     64: .1.3...789 (07) r1 += 44\n     65: .1.3...789 (b7) r2 = 4\n     66: .123...789 (85) call bpf_probe_read#4\n     67: ..2.45.789 (b7) r1 = 1\n     68: .12.45.789 (15) if r1 == 0x0 goto pc+8\n     69: .......789 (bf) r1 = r10\n     70: .1.....789 (07) r1 += -80\n     71: .1.....789 (79) r3 = *(u64 *)(r1 +24)\n     72: ...3...789 (b7) r1 = 88\n     73: .1.3...789 (0f) r3 += r1\n     74: ...3...789 (bf) r1 = r8\n     75: .1.3...789 (07) r1 += 48\n     76: .1.3...789 (05) goto pc+7\n     77: ..2.45.789 (bf) r1 = r10\n     78: .12.45.789 (07) r1 += -80\n     79: .12.45.789 (79) r3 = *(u64 *)(r1 +24)\n     80: .12345.789 (85) call unknown#195896080\n     81: .1.3...789 (0f) r3 += r1\n     82: ...3...789 (bf) r1 = r8\n     83: .1.3...789 (07) r1 += 44\n     84: .1.3...789 (b7) r2 = 4\n     85: .123...789 (85) call bpf_probe_read#4\n     86: ....45.789 (b7) r1 = 1\n     87: .1..45.789 (15) if r1 == 0x0 goto pc+40\n     88: .......789 (b7) r6 = 0\n     89: ......6789 (7b) *(u64 *)(r10 -88) = r6\n     90: ......6789 (b7) r1 = 2904\n     91: .1....6789 (bf) r3 = r9\n     92: .1.3..6789 (0f) r3 += r1\n     93: ...3..6789 (bf) r1 = r10\n     94: .1.3..6789 (07) r1 += -88\n     95: .1.3..6789 (b7) r2 = 8\n     96: .123..6789 (85) call bpf_probe_read#4\n     97: ....456789 (79) r3 = *(u64 *)(r10 -88)\n     98: ...3456789 (15) if r3 == 0x0 goto pc+28\n     99: ...3..6789 (63) *(u32 *)(r10 -92) = r6\n    100: ...3...789 (b7) r1 = 4\n    101: .1.3...789 (0f) r3 += r1\n    102: ...3...789 (bf) r1 = r10\n    103: .1.3...789 (07) r1 += -92\n    104: .1.3...789 (b7) r2 = 4\n    105: .123...789 (85) call bpf_probe_read#4\n    106\n... verifier log truncated ...; prog 124: prog 124 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 131: prog 131 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 135: prog 135 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...; prog 138: prog 138 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 148: prog 148 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...; prog 150: prog 150 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 156: prog 156 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...; prog 165: prog 165 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 167: prog 167 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...; prog 171: prog 171 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 179: prog 179 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...; prog 188: prog 188 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 195: prog 195 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 198: prog 198 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 207: prog 207 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 209: prog 209 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT; prog 212: prog 212 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 217: prog 217 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 223: prog 223 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 231: prog 231 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 241: prog 241 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 245: prog 245 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...; prog 249: prog 249 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 260: prog 260 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 266: prog 266 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 269: prog 269 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 278: prog 278 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...; prog 282: prog 282 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 287: prog 287 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 298: prog 298 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...; prog 303: prog 303 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 21 pass cond_select failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @820\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 0\n      2: ......67.. (63) *(u32 *)(r10 -88) = r7\n      3: ......67.. (bf) r2 = r10\n      4: ..2...67.. (07) r2 += -88\n      5: ..2...67.. (18) r1 = 0xffff8c2446269600\n      7: .12...67.. (85) call bpf_map_lookup_elem#1\n      8: 0.....67.. (15) if r0 == 0x0 goto pc+809\n      9: 0.....67.. (7b) *(u64 *)(r10 -120) = r6\n     10: 0......7.. (bf) r8 = r0\n     11: 0......78. (bf) r6 = r0\n     12: ......678. (85) call bpf_get_current_task#35\n     13: 0.....678. (b7) r1 = 2680\n     14: 01....678. (0f) r0 += r1\n     15: 0.....678. (bf) r1 = r10\n     16: 01....678. (07) r1 += -72\n     17: 01....678. (b7) r2 = 8\n     18: 012...678. (bf) r3 = r0\n     19: .123..678. (85) call bpf_probe_read#4\n     20: ......678. (b7) r1 = 1448\n     21: .1....678. (79) r3 = *(u64 *)(r10 -72)\n     22: .1.3..678. (0f) r3 += r1\n     23: ...3..678. (bf) r1 = r10\n     24: .1.3..678. (07) r1 += -64\n     25: .1.3..678. (b7) r2 = 8\n     26: .123..678. (85) call bpf_probe_read#4\n     27: ......678. (79) r9 = *(u64 *)(r10 -64)\n     28: ......6789 (63) *(u32 *)(r10 -84) = r7\n     29: ......6.89 (bf) r2 = r10\n     30: ..2...6.89 (07) r2 += -84\n     31: ..2...6.89 (18) r1 = 0xffff8c2447ba4000\n     33: .12...6.89 (85) call bpf_map_lookup_elem#1\n     34: 0.....6.89 (7b) *(u64 *)(r10 -104) = r6\n     35: 0.....6.89 (07) r6 += 5808\n     36: 0.....6.89 (7b) *(u64 *)(r10 -112) = r6\n     37: 0.......89 (bf) r2 = r8\n     38: 0.2.....89 (7b) *(u64 *)(r10 -96) = r8\n     39: 0.2......9 (bf) r8 = r0\n     40: ..2.....89 (55) if r8 != 0x0 goto pc+1\n     41: .......... (05) goto pc+252\n     42: ..2.....89 (b7) r1 = 64\n     43: .12.....89 (0f) r9 += r1\n     44: ..2.....89 (b7) r1 = 4096\n     45: .12.....89 (63) *(u32 *)(r2 +6192) = r1\n     46: ........89 (85) call bpf_get_current_task#35\n     47: 0.......89 (b7) r1 = 3408\n     48: 01......89 (0f) r0 += r1\n     49: 0.......89 (bf) r1 = r10\n     50: 01......89 (07) r1 += -80\n     51: 01......89 (b7) r2 = 8\n     52: 012.....89 (bf) r3 = r0\n     53: .123....89 (85) call bpf_probe_read#4\n     54: ........89 (b7) r1 = 8\n     55: .1......89 (7b) *(u64 *)(r10 -128) = r9\n     56: .1......89 (0f) r9 += r1\n     57: ........89 (79) r7 = *(u64 *)(r10 -80)\n     58: .......789 (bf) r1 = r10\n     59: .1.....789 (07) r1 += -72\n     60: .1.....789 (b7) r2 = 8\n     61: .12....789 (7b) *(u64 *)(r10 -136) = r9\n     62: .12....789 (bf) r3 = r9\n     63: .123...78. (85) call bpf_probe_read#4\n     64: .......78. (b7) r1 = 8\n     65: .1.....78. (79) r6 = *(u64 *)(r10 -72)\n     66: .1....678. (bf) r3 = r6\n     67: .1.3..678. (0f) r3 += r1\n     68: ...3..678. (b7) r1 = 8\n     69: .1.3..678. (0f) r3 += r1\n     70: ...3..678. (bf) r1 = r10\n     71: .1.3..678. (07) r1 += -64\n     72: .1.3..678. (b7) r2 = 8\n     73: .123..678. (85) call bpf_probe_read#4\n     74: ......678. (79) r3 = *(u64 *)(r10 -96)\n     75: ...3..678. (bf) r9 = r8\n     76: ...3..6789 (07) r9 += 4096\n     77: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     78: .1.3..6789 (55) if r1 != 0x0 goto pc+41\n     79: ......6789 (b7) r1 = 24\n     80: .1....6789 (bf) r3 = r6\n     81: .1.3..6789 (0f) r3 += r1\n     82: ...3..6789 (bf) r1 = r10\n     83: .1.3..6789 (07) r1 += -64\n     84: .1.3..6789 (b7) r2 = 8\n     85: .123..6789 (85) call bpf_probe_read#4\n     86: ......6789 (79) r3 = *(u64 *)(r10 -96)\n     87: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     88: .1.3..6789 (1d) if r1 == r6 goto pc+31\n     89: ...3...789 (61) r1 = *(u32 *)(r3 +6192)\n     90: .1.3...789 (bf) r2 = r1\n     91: .123...789 (07) r2 += -10\n     92: .123...789 (63) *(u32 *)(r3 +6192) = r2\n     93: .123...789 (67) r1 <<= 32\n     94: .123...789 (c7) r1 s>>= 32\n     95: .123...789 (65) if r1 s> 0x9 goto pc+5\n     96: ..23.....9 (18) r1 = 0xffffffdc\n     98: .123.....9 (63) *(u32 *)(r3 +6196) = r1\n     99: ..2......9 (bf) r7 = r9\n    100: ..2....7.. (05) goto pc+93\n    101: ...3...78. (b7) r1 = 41\n    102: .1.3...78. (73) *(u8 *)(r8 +4095) = r1\n    103: ...3...78. (b7) r1 = 116\n    104: .1.3...78. (73) *(u8 *)(r8 +4092) = r1\n    105: ...3\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 21
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 23 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @1724\nfunc#2 @1840\nfunc#3 @2033\nfunc#4 @2208\nfunc#5 @2277\nfunc#6 @2300\nfunc#7 @2370\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (85) call bpf_get_current_task#35\n      2: 0.....6... (bf) r9 = r0\n      3: ......6..9 (7b) *(u64 *)(r10 -128) = r6\n      4: ......6..9 (61) r6 = *(u32 *)(r6 +8)\n      5: ......6..9 (b7) r1 = 0\n      6: .1....6..9 (63) *(u32 *)(r10 -120) = r1\n      7: ......6..9 (bf) r2 = r10\n      8: ..2...6..9 (07) r2 += -120\n      9: ..2...6..9 (18) r1 = 0xffff8c2446269600\n     11: .12...6..9 (85) call bpf_map_lookup_elem#1\n     12: 0.....6..9 (bf) r7 = r0\n     13: ......67.9 (15) if r7 == 0x0 goto pc+1689\n     14: ......67.9 (7b) *(u64 *)(r10 -144) = r6\n     15: .......7.9 (85) call bpf_get_current_pid_tgid#14\n     16: 0......7.9 (bf) r6 = r0\n     17: ......67.9 (85) call bpf_get_current_task#35\n     18: 0.....67.9 (7b) *(u64 *)(r10 -96) = r0\n     19: 0.....67.9 (b7) r8 = 2816\n     20: 0.....6789 (0f) r0 += r8\n     21: 0.....6789 (bf) r1 = r10\n     22: 01....6789 (07) r1 += -96\n     23: 01....6789 (b7) r2 = 8\n     24: 012...6789 (bf) r3 = r0\n     25: .123..6789 (85) call bpf_probe_read_kernel#113\n     26: ......6789 (7b) *(u64 *)(r10 -160) = r6\n     27: ......6789 (7b) *(u64 *)(r10 -152) = r6\n     28: .......789 (79) r3 = *(u64 *)(r10 -96)\n     29: ...3...789 (7b) *(u64 *)(r10 -136) = r9\n     30: ...3...789 (15) if r3 == 0x0 goto pc+162\n     31: ...3...789 (b7) r1 = 2804\n     32: .1.3...789 (0f) r3 += r1\n     33: ...3...789 (bf) r1 = r10\n     34: .1.3...789 (07) r1 += -8\n     35: .1.3...789 (b7) r2 = 4\n     36: .123...789 (85) call bpf_probe_read_kernel#113\n     37: .......789 (61) r1 = *(u32 *)(r10 -8)\n     38: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     39: .......789 (bf) r2 = r10\n     40: ..2....789 (07) r2 += -112\n     41: ..2....789 (18) r1 = 0xffff8c2446a1a400\n     43: .12....789 (85) call bpf_map_lookup_elem#1\n     44: 0......789 (bf) r6 = r0\n     45: ......6789 (15) if r6 == 0x0 goto pc+3\n     46: ......6789 (05) goto pc+0\n     47: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     48: .1....6789 (55) if r1 != 0x0 goto pc+81\n     49: .......789 (b7) r1 = 2816\n     50: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     51: .1.3...789 (0f) r3 += r1\n     52: ...3...789 (bf) r1 = r10\n     53: .1.3...789 (07) r1 += -96\n     54: .1.3...789 (b7) r2 = 8\n     55: .123...789 (85) call bpf_probe_read_kernel#113\n     56: .......789 (79) r3 = *(u64 *)(r10 -96)\n     57: ...3...789 (15) if r3 == 0x0 goto pc+135\n     58: ...3...789 (b7) r1 = 2804\n     59: .1.3...789 (0f) r3 += r1\n     60: ...3...789 (bf) r1 = r10\n     61: .1.3...789 (07) r1 += -8\n     62: .1.3...789 (b7) r2 = 4\n     63: .123...789 (85) call bpf_probe_read_kernel#113\n     64: .......789 (61) r1 = *(u32 *)(r10 -8)\n     65: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     66: .......789 (bf) r2 = r10\n     67: ..2....789 (07) r2 += -112\n     68: ..2....789 (18) r1 = 0xffff8c2446a1a400\n     70: .12....789 (85) call bpf_map_lookup_elem#1\n     71: 0......789 (bf) r6 = r0\n     72: ......6789 (15) if r6 == 0x0 goto pc+3\n     73: ......6789 (05) goto pc+0\n     74: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     75: .1....6789 (55) if r1 != 0x0 goto pc+54\n     76: .......789 (b7) r1 = 2816\n     77: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     78: .1.3...789 (0f) r3 += r1\n     79: ...3...789 (bf) r1 = r10\n     80: .1.3...789 (07) r1 += -96\n     81: .1.3...789 (b7) r2 = 8\n     82: .123...789 (85) call bpf_probe_read_kernel#113\n     83: .......789 (79) r3 = *(u64 *)(r10 -96)\n     84: ...3...789 (15) if r3 == 0x0 goto pc+108\n     85: ...3...789 (b7) r1 = 2804\n     86: .1.3...789 (0f) r3 += r1\n     87: ...3...789 (bf) r1 = r10\n     88: .1.3...789 (07) r1 += -8\n     89: .1.3...789 (b7) r2 = 4\n     90: .123...789 (85) call bpf_probe_read_kernel#113\n     91: .......789 (61) r1 = *(u32 *)(r10 -8)\n     92: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     93: .......789 (bf) r2 = r10\n     94: ..2....789 (07) r2 += -112\n     95: ..2....789 (18) r1 = 0xffff8c2446a1a400\n     97: .12....789 (85) call bpf_map_lookup_elem#1\n     98: 0......789 (bf) r6 = r0\n\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 23
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 25 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 25
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 32 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 32
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 40 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 40
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 47 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 47
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 51 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 51
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 56 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 56
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 66 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 66
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 71 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 71
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 74 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 74
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 84 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 84
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 86 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 86
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 98 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 98
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 103 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 103
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 107 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 107
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 115 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 115
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 117 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r1 = 0\n      2: .1....6... (63) *(u32 *)(r10 -116) = r1\n      3: ......6... (bf) r2 = r10\n      4: ..2...6... (07) r2 += -116\n      5: ..2...6... (18) r1 = 0xffff8c250b570800\n      7: .12...6... (85) call bpf_map_lookup_elem#1\n      8: 0.....6... (bf) r7 = r0\n      9: ......67.. (15) if r7 == 0x0 goto pc+370\n     10: ......67.. (05) goto pc+0\n     11: ......67.. (7b) *(u64 *)(r10 -128) = r6\n     12: .......7.. (79) r1 = *(u64 *)(r7 +24272)\n     13: .1.....7.. (15) if r1 == 0x0 goto pc+203\n     14: .......7.. (85) call bpf_get_current_pid_tgid#14\n     15: 0......7.. (bf) r6 = r0\n     16: ......67.. (85) call bpf_get_current_task#35\n     17: 0.....67.. (bf) r9 = r0\n     18: ......67.9 (77) r6 >>= 32\n     19: ......67.9 (63) *(u32 *)(r10 -80) = r6\n     20: .......7.9 (bf) r2 = r10\n     21: ..2....7.9 (07) r2 += -80\n     22: ..2....7.9 (18) r1 = 0xffff8c2446a1a400\n     24: .12....7.9 (85) call bpf_map_lookup_elem#1\n     25: 0......7.9 (bf) r8 = r0\n     26: .......789 (15) if r8 == 0x0 goto pc+190\n     27: .......789 (b7) r1 = 3440\n     28: .1.....789 (bf) r3 = r9\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (bf) r1 = r10\n     31: .1.3...789 (07) r1 += -8\n     32: .1.3...789 (b7) r2 = 8\n     33: .123...789 (85) call bpf_probe_read#4\n     34: .......789 (79) r3 = *(u64 *)(r10 -8)\n     35: ...3...789 (bf) r6 = r10\n     36: ...3..6789 (07) r6 += -80\n     37: ...3..6789 (bf) r1 = r6\n     38: .1.3..6789 (b7) r2 = 72\n     39: .123..6789 (85) call bpf_probe_read#4\n     40: ...3456789 (bf) r1 = r8\n     41: .1.3456789 (07) r1 += 40\n     42: .1.3456789 (b7) r2 = 1\n     43: .123456789 (15) if r2 == 0x0 goto pc+2\n     44: .1....6789 (b7) r2 = 536\n     45: .12...6789 (05) goto pc+1\n     46: .123456789 (85) call unknown#195896080\n     47: .12...6789 (79) r3 = *(u64 *)(r6 +8)\n     48: .123...789 (0f) r3 += r2\n     49: .1.3...789 (b7) r2 = 4\n     50: .123...789 (85) call bpf_probe_read#4\n     51: ..2.45.789 (b7) r1 = 1\n     52: .12.45.789 (15) if r1 == 0x0 goto pc+5\n     53: .......789 (bf) r1 = r10\n     54: .1.....789 (07) r1 += -80\n     55: .1.....789 (79) r3 = *(u64 *)(r1 +16)\n     56: ...3...789 (b7) r1 = 1240\n     57: .1.3...789 (05) goto pc+4\n     58: ..2.45.789 (bf) r1 = r10\n     59: .12.45.789 (07) r1 += -80\n     60: .12.45.789 (79) r3 = *(u64 *)(r1 +16)\n     61: .12345.789 (85) call unknown#195896080\n     62: .1.3...789 (0f) r3 += r1\n     63: ...3...789 (bf) r1 = r8\n     64: .1.3...789 (07) r1 += 44\n     65: .1.3...789 (b7) r2 = 4\n     66: .123...789 (85) call bpf_probe_read#4\n     67: ..2.45.789 (b7) r1 = 1\n     68: .12.45.789 (15) if r1 == 0x0 goto pc+8\n     69: .......789 (bf) r1 = r10\n     70: .1.....789 (07) r1 += -80\n     71: .1.....789 (79) r3 = *(u64 *)(r1 +24)\n     72: ...3...789 (b7) r1 = 88\n     73: .1.3...789 (0f) r3 += r1\n     74: ...3...789 (bf) r1 = r8\n     75: .1.3...789 (07) r1 += 48\n     76: .1.3...789 (05) goto pc+7\n     77: ..2.45.789 (bf) r1 = r10\n     78: .12.45.789 (07) r1 += -80\n     79: .12.45.789 (79) r3 = *(u64 *)(r1 +24)\n     80: .12345.789 (85) call unknown#195896080\n     81: .1.3...789 (0f) r3 += r1\n     82: ...3...789 (bf) r1 = r8\n     83: .1.3...789 (07) r1 += 44\n     84: .1.3...789 (b7) r2 = 4\n     85: .123...789 (85) call bpf_probe_read#4\n     86: ....45.789 (b7) r1 = 1\n     87: .1..45.789 (15) if r1 == 0x0 goto pc+40\n     88: .......789 (b7) r6 = 0\n     89: ......6789 (7b) *(u64 *)(r10 -88) = r6\n     90: ......6789 (b7) r1 = 2904\n     91: .1....6789 (bf) r3 = r9\n     92: .1.3..6789 (0f) r3 += r1\n     93: ...3..6789 (bf) r1 = r10\n     94: .1.3..6789 (07) r1 += -88\n     95: .1.3..6789 (b7) r2 = 8\n     96: .123..6789 (85) call bpf_probe_read#4\n     97: ....456789 (79) r3 = *(u64 *)(r10 -88)\n     98: ...3456789 (15) if r3 == 0x0 goto pc+28\n     99: ...3..6789 (63) *(u32 *)(r10 -92) = r6\n    100: ...3...789 (b7) r1 = 4\n    101: .1.3...789 (0f) r3 += r1\n    102: ...3...789 (bf) r1 = r10\n    103: .1.3...789 (07) r1 += -92\n    104: .1.3...789 (b7) r2 = 4\n    105: .123...789 (85) call bpf_probe_read#4\n    106\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 117
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 124 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 124
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 131 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 131
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 135 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 135
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 138 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 138
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 148 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 148
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 150 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 150
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 156 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 156
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 165 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 165
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 167 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 167
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 171 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 171
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 179 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 179
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 188 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 188
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 195 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 195
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 198 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 198
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 207 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 207
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 209 pass map_inline failed after 0 committed passes: pass map_inline requires verifier states from a previous per-pass ReJIT",
            "exit_code": 1,
            "prog_id": 209
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 212 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 212
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 217 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 217
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 223 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 223
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 231 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 231
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 241 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 241
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 245 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 245
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 249 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 249
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 260 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 260
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 266 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 266
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 269 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 269
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 278 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2019: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2018: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2017: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2014: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2012: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2011: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P46 R2=map_value(map=string_postfix_,ks=4,vs=132,off=45) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-42,smax=smax32=84,umax=0xffffffffffffffd6) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2019: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2019: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2020: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2021: (07) r1 += 1                    ; frame2: R1=52\n2022: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2023 first_idx 2022 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2022: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2021: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2020: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2019: (71) r3\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 278
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 282 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 282
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 287 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 287
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 298 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 298
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 303 pass prefetch failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nr_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2044: frame2: R1=51 R2=map_value(map=string_postfix_,ks=4,vs=132,off=51)\n2044: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2045: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=51) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2046: (07) r1 += 1                    ; frame2: R1=52\n2047: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 2048 first_idx 2047 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2047: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2046: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2045: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2044: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2043: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2042: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2041: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2040: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2039: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2038: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2037: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2036: (15) if r1 == 0x83 goto pc+11\nmark_precise:\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 303
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
    }
  ],
  "samples": 1,
  "status": "ok",
  "suite_name": "macro_apps",
  "workload_seconds": 3.0
}
```
